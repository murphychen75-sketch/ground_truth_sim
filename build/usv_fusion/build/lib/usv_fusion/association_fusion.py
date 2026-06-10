"""Multi-target association and CV-EKF fusion (replaceable module, ROS-agnostic)."""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import List, Optional, Sequence, Set, Tuple

import numpy as np
from scipy.optimize import linear_sum_assignment

BIG = 1.0e6


@dataclass
class RadarObservation:
    """Single mmWave target expressed in the common body frame (planar)."""

    x: float
    y: float
    vx: float
    vy: float
    size_w: float
    size_l: float
    size_h: float
    snr: float


@dataclass
class VisionObservation:
    """Single vision detection expressed in the common body frame (planar)."""

    x: float
    y: float
    size_w: float
    size_h: float
    confidence: float
    camera_id: str = ""


@dataclass
class FusedMeasurement:
    """One measurement entering the track-update stage (fused pair or single modality)."""

    x: float
    y: float
    vx: float
    vy: float
    has_velocity: bool
    pos_var: float
    vel_var: float
    size_w: float
    size_l: float
    size_h: float


@dataclass
class TrackState:
    """Serializable fused track snapshot for downstream ROS publishing."""

    track_id: int
    x: float
    y: float
    vx: float
    vy: float
    covariance_row_major: List[float]
    size_w: float
    size_l: float
    size_h: float
    last_seen_stamp_sec: float


@dataclass
class _InternalTrack:
    """EKF track state held inside FusionEngine."""

    track_id: int
    mean: np.ndarray = field(default_factory=lambda: np.zeros((4, 1)))
    cov: np.ndarray = field(default_factory=lambda: np.eye(4) * 10.0)
    size_w: float = 0.0
    size_l: float = 0.0
    size_h: float = 0.0
    last_seen_stamp_sec: float = 0.0


def vision_position_variance(confidence: float, base_std: float, scale: float) -> float:
    """Map vision confidence to planar position variance (sigma^2)."""
    c = float(np.clip(confidence, 1e-3, 1.0))
    sigma = base_std * (1.0 + scale * (1.0 / c - 1.0))
    return float(sigma * sigma)


def radar_position_variance(snr: float, base_std: float, scale: float) -> float:
    """Map radar SNR to planar position variance (sigma^2)."""
    s = max(float(snr), 1.0)
    sigma = base_std * (1.0 + scale / s)
    return float(sigma * sigma)


def radar_velocity_variance(snr: float, base_std: float, scale: float) -> float:
    """Map radar SNR to velocity-component variance (sigma^2)."""
    s = max(float(snr), 1.0)
    sigma = base_std * (1.0 + scale / s)
    return float(sigma * sigma)


def _mahalanobis_gate_sq(
    mx: float,
    my: float,
    zx: float,
    zy: float,
    meas_var: float,
    track_cov_xy: np.ndarray,
    gating_m: float,
) -> Tuple[bool, float]:
    """Return (passes_gate, squared_distance) using diagonal XY gate."""
    dx = zx - mx
    dy = zy - my
    combined_var = float(meas_var + track_cov_xy[0, 0])
    combined_vary = float(meas_var + track_cov_xy[1, 1])
    if combined_var < 1e-9:
        combined_var = 1e-9
    if combined_vary < 1e-9:
        combined_vary = 1e-9
    d2 = (dx * dx) / combined_var + (dy * dy) / combined_vary
    return d2 <= gating_m * gating_m, d2


def _cv_predict(mean: np.ndarray, cov: np.ndarray, dt: float, q_pos: float, q_vel: float) -> Tuple[np.ndarray, np.ndarray]:
    """Constant-velocity predict for state [x,y,vx,vy]."""
    f = np.array(
        [
            [1.0, 0.0, dt, 0.0],
            [0.0, 1.0, 0.0, dt],
            [0.0, 0.0, 1.0, 0.0],
            [0.0, 0.0, 0.0, 1.0],
        ]
    )
    q = np.diag([q_pos, q_pos, q_vel, q_vel]) * max(dt, 1e-3)
    m_new = f @ mean
    p_new = f @ cov @ f.T + q
    return m_new, p_new


def _ekf_update_full(
    mean: np.ndarray,
    cov: np.ndarray,
    z: np.ndarray,
    r: np.ndarray,
    h: np.ndarray,
) -> Tuple[np.ndarray, np.ndarray]:
    """Generic linear-Gaussian EKF update with measurement z, noise R, Jacobian H."""
    s = h @ cov @ h.T + r
    k = cov @ h.T @ np.linalg.inv(s)
    y = z - h @ mean
    mean_new = mean + k @ y
    ikh = np.eye(4) - k @ h
    cov_new = ikh @ cov @ ikh.T + k @ r @ k.T
    return mean_new, cov_new


def _ekf_update_position_only(
    mean: np.ndarray,
    cov: np.ndarray,
    zx: float,
    zy: float,
    var: float,
) -> Tuple[np.ndarray, np.ndarray]:
    """Update with position measurement (x,y) and isotropic variance var."""
    z = np.array([[zx], [zy]])
    h = np.array([[1.0, 0.0, 0.0, 0.0], [0.0, 1.0, 0.0, 0.0]])
    r = np.eye(2) * var
    return _ekf_update_full(mean, cov, z, r, h)


def _ekf_update_position_velocity(
    mean: np.ndarray,
    cov: np.ndarray,
    zx: float,
    zy: float,
    zvx: float,
    zvy: float,
    pos_var: float,
    vel_var: float,
) -> Tuple[np.ndarray, np.ndarray]:
    """Update with (x,y,vx,vy) diagonal measurement noise."""
    z = np.array([[zx], [zy], [zvx], [zvy]])
    h = np.eye(4)
    r = np.diag([pos_var, pos_var, vel_var, vel_var])
    return _ekf_update_full(mean, cov, z, r, h)


def _cov_to_row_major_16(p: np.ndarray) -> List[float]:
    """Flatten 4x4 covariance to row-major list of 16 floats."""
    out: List[float] = []
    for r in range(4):
        for c in range(4):
            out.append(float(p[r, c]))
    return out


class FusionEngine:
    """Owns tracks, performs radar–vision association and CV-EKF updates."""

    def __init__(
        self,
        gating_m: float,
        gate_distance_m: float,
        position_std_radar_m: float,
        position_std_vision_m: float,
        velocity_std_radar_m_s: float,
        process_noise_pos: float,
        process_noise_vel: float,
        vision_confidence_sigma_scale: float,
        radar_snr_sigma_scale: float,
        max_internal_tracks: int = 200,
        cluster_max_distance_m: float = 8.0,
        cluster_allow_same_camera: bool = False,
        defer_spawn_merge_enabled: bool = True,
        defer_spawn_max_pos_m: float = 35.0,
        defer_spawn_max_speed_m_s: float = 6.0,
        track_predict_stop_sec: float = 3.0,
    ) -> None:
        """Store fusion thresholds, noise scales, and internal capacity."""
        self._gating_m = gating_m
        self._gate_d = gate_distance_m
        self._pos_std_r = position_std_radar_m
        self._pos_std_v = position_std_vision_m
        self._vel_std_r = velocity_std_radar_m_s
        self._q_pos = process_noise_pos
        self._q_vel = process_noise_vel
        self._vis_scale = vision_confidence_sigma_scale
        self._snr_scale = radar_snr_sigma_scale
        self._max_tracks = max_internal_tracks
        self._cluster_max_d = cluster_max_distance_m
        self._cluster_same_cam = cluster_allow_same_camera
        self._defer_merge = defer_spawn_merge_enabled
        self._defer_max_pos = max(0.0, float(defer_spawn_max_pos_m))
        self._defer_max_spd = max(0.0, float(defer_spawn_max_speed_m_s))
        self._predict_stop_sec = float(track_predict_stop_sec)
        self._tracks: dict[int, _InternalTrack] = {}
        self._next_id: int = 1

    def reset(self) -> None:
        """Clear all tracks and reset the monotonic ID counter to 1."""
        self._tracks.clear()
        self._next_id = 1

    def _allocate_id(self) -> int:
        """Return the next monotonic track id (never reused within engine lifetime)."""
        tid = self._next_id
        self._next_id += 1
        return tid

    def associate_radar_vision(
        self,
        radars: Sequence[RadarObservation],
        visions: Sequence[VisionObservation],
    ) -> Tuple[List[Tuple[int, int]], List[int], List[int]]:
        """Pair radar and vision indices via Hungarian on gated planar distance."""
        nr = len(radars)
        nv = len(visions)
        if nr == 0 or nv == 0:
            return [], list(range(nr)), list(range(nv))
        n = max(nr, nv)
        cost = np.full((n, n), BIG, dtype=np.float64)
        for i in range(nr):
            for j in range(nv):
                dx = radars[i].x - visions[j].x
                dy = radars[i].y - visions[j].y
                d = float(np.hypot(dx, dy))
                if d <= self._gate_d:
                    cost[i, j] = d * d
        ri, cj = linear_sum_assignment(cost)
        pairs: List[Tuple[int, int]] = []
        used_r = set()
        used_v = set()
        for ridx, vidx in zip(ri, cj):
            if ridx >= nr or vidx >= nv:
                continue
            if cost[ridx, vidx] >= BIG * 0.5:
                continue
            pairs.append((ridx, vidx))
            used_r.add(ridx)
            used_v.add(vidx)
        unmatched_r = [i for i in range(nr) if i not in used_r]
        unmatched_v = [j for j in range(nv) if j not in used_v]
        return pairs, unmatched_r, unmatched_v

    def build_fused_measurements(
        self,
        radars: Sequence[RadarObservation],
        visions: Sequence[VisionObservation],
    ) -> List[FusedMeasurement]:
        """Fuse paired observations and append single-modality leftovers."""
        pairs, ur, uv = self.associate_radar_vision(radars, visions)
        fused: List[FusedMeasurement] = []
        for i, j in pairs:
            r = radars[i]
            v = visions[j]
            vr = radar_position_variance(r.snr, self._pos_std_r, self._snr_scale)
            vv = vision_position_variance(v.confidence, self._pos_std_v, self._vis_scale)
            w_r = 1.0 / max(vr, 1e-6)
            w_v = 1.0 / max(vv, 1e-6)
            den = w_r + w_v
            xf = (w_r * r.x + w_v * v.x) / den
            yf = (w_r * r.y + w_v * v.y) / den
            pos_var = 1.0 / den
            vel_var = radar_velocity_variance(r.snr, self._vel_std_r, self._snr_scale)
            fused.append(
                FusedMeasurement(
                    x=xf,
                    y=yf,
                    vx=r.vx,
                    vy=r.vy,
                    has_velocity=True,
                    pos_var=pos_var,
                    vel_var=vel_var,
                    size_w=max(r.size_w, v.size_w),
                    size_l=r.size_l,
                    size_h=max(r.size_h, v.size_h),
                )
            )
        for i in ur:
            r = radars[i]
            pr = radar_position_variance(r.snr, self._pos_std_r, self._snr_scale)
            vr = radar_velocity_variance(r.snr, self._vel_std_r, self._snr_scale)
            fused.append(
                FusedMeasurement(
                    x=r.x,
                    y=r.y,
                    vx=r.vx,
                    vy=r.vy,
                    has_velocity=True,
                    pos_var=pr,
                    vel_var=vr,
                    size_w=r.size_w,
                    size_l=r.size_l,
                    size_h=r.size_h,
                )
            )
        for j in uv:
            v = visions[j]
            vv = vision_position_variance(v.confidence, self._pos_std_v, self._vis_scale)
            fused.append(
                FusedMeasurement(
                    x=v.x,
                    y=v.y,
                    vx=0.0,
                    vy=0.0,
                    has_velocity=False,
                    pos_var=vv,
                    vel_var=1.0,
                    size_w=v.size_w,
                    size_l=v.size_w,
                    size_h=v.size_h,
                )
            )
        return fused

    def associate_tracks_to_measurements(
        self,
        tracks: Sequence[_InternalTrack],
        measurements: Sequence[FusedMeasurement],
    ) -> Tuple[List[Tuple[int, int]], List[int]]:
        """Assign each track to at most one measurement (Hungarian with per-track coast dummies)."""
        t_count = len(tracks)
        m_count = len(measurements)
        if t_count == 0:
            return [], list(range(m_count))
        cols = m_count + t_count
        cost = np.full((t_count, cols), BIG, dtype=np.float64)
        for ti, tr in enumerate(tracks):
            mx = float(tr.mean[0, 0])
            my = float(tr.mean[1, 0])
            pxy = tr.cov[0:2, 0:2]
            for mj, meas in enumerate(measurements):
                var = meas.pos_var
                ok, d2 = _mahalanobis_gate_sq(mx, my, meas.x, meas.y, var, pxy, self._gating_m)
                if ok:
                    cost[ti, mj] = d2
            cost[ti, m_count + ti] = 0.0
        ri, ci = linear_sum_assignment(cost)
        pairs: List[Tuple[int, int]] = []
        used_meas = set()
        for ti, cidx in zip(ri, ci):
            if cidx < m_count and cost[ti, cidx] < BIG * 0.5:
                pairs.append((ti, cidx))
                used_meas.add(cidx)
        unmatched_m = [mj for mj in range(m_count) if mj not in used_meas]
        return pairs, unmatched_m

    def _apply_fused_measurement_to_track(self, tr: _InternalTrack, m: FusedMeasurement) -> None:
        """EKF update and size fields from one fused measurement."""
        if m.has_velocity:
            tr.mean, tr.cov = _ekf_update_position_velocity(
                tr.mean,
                tr.cov,
                m.x,
                m.y,
                m.vx,
                m.vy,
                m.pos_var,
                m.vel_var,
            )
        else:
            tr.mean, tr.cov = _ekf_update_position_only(tr.mean, tr.cov, m.x, m.y, m.pos_var)
        tr.size_w = m.size_w
        tr.size_l = m.size_l
        tr.size_h = m.size_h

    def run_cycle(
        self,
        dt: float,
        stamp_sec: float,
        radars: Sequence[RadarObservation],
        visions: Sequence[VisionObservation],
    ) -> List[int]:
        """Predict all tracks, fuse sensors, assign measurements, update or spawn tracks.

        Returns internal track ids removed this cycle (no measurement for >= track_predict_stop_sec):
        they are dropped from the engine and must not be predicted further.
        """
        from usv_fusion.vision_cluster import ClusterOptions, cluster_vision_observations

        pruned_ids: List[int] = []
        if self._predict_stop_sec > 0.0:
            for tid in list(self._tracks.keys()):
                tr = self._tracks[tid]
                if stamp_sec - tr.last_seen_stamp_sec > self._predict_stop_sec:
                    del self._tracks[tid]
                    pruned_ids.append(int(tid))

        dt_clamped = float(max(dt, 1e-3))
        for tr in self._tracks.values():
            tr.mean, tr.cov = _cv_predict(tr.mean, tr.cov, dt_clamped, self._q_pos, self._q_vel)
        cluster_opts = ClusterOptions(
            max_distance_m=self._cluster_max_d,
            allow_same_camera_in_cluster=self._cluster_same_cam,
        )
        vision_for_assoc = cluster_vision_observations(visions, cluster_opts)
        meas = self.build_fused_measurements(radars, vision_for_assoc)
        track_list = list(self._tracks.values())
        pairs_tm, unmatched_m = self.associate_tracks_to_measurements(track_list, meas)
        matched_ti: Set[int] = {ti for ti, _ in pairs_tm}
        for ti, mj in pairs_tm:
            tr = track_list[ti]
            m = meas[mj]
            self._apply_fused_measurement_to_track(tr, m)
            tr.last_seen_stamp_sec = stamp_sec

        if self._defer_merge and unmatched_m and track_list:
            coast_tracks = [ti for ti in range(len(track_list)) if ti not in matched_ti]
            still_unmatched: List[int] = []
            for mj in unmatched_m:
                m = meas[mj]
                best_ti: Optional[int] = None
                best_d = float("inf")
                for ti in coast_tracks:
                    tr = track_list[ti]
                    mx = float(tr.mean[0, 0])
                    my = float(tr.mean[1, 0])
                    d = float(np.hypot(m.x - mx, m.y - my))
                    if d > self._defer_max_pos:
                        continue
                    if m.has_velocity:
                        dvs = float(
                            np.hypot(m.vx - float(tr.mean[2, 0]), m.vy - float(tr.mean[3, 0]))
                        )
                        if dvs > self._defer_max_spd:
                            continue
                    if d < best_d:
                        best_d = d
                        best_ti = ti
                if best_ti is not None:
                    tr = track_list[best_ti]
                    self._apply_fused_measurement_to_track(tr, m)
                    tr.last_seen_stamp_sec = stamp_sec
                    coast_tracks.remove(best_ti)
                    matched_ti.add(best_ti)
                else:
                    still_unmatched.append(mj)
            unmatched_m = still_unmatched

        for mj in unmatched_m:
            if len(self._tracks) >= self._max_tracks:
                break
            m = meas[mj]
            tid = self._allocate_id()
            mean = np.array([[m.x], [m.y], [m.vx], [m.vy]], dtype=np.float64)
            p0 = np.eye(4) * 5.0
            p0[0, 0] = max(m.pos_var, 1.0)
            p0[1, 1] = max(m.pos_var, 1.0)
            p0[2, 2] = max(m.vel_var, 1.0) if m.has_velocity else 25.0
            p0[3, 3] = max(m.vel_var, 1.0) if m.has_velocity else 25.0
            self._tracks[tid] = _InternalTrack(
                track_id=tid,
                mean=mean,
                cov=p0,
                size_w=m.size_w,
                size_l=m.size_l,
                size_h=m.size_h,
                last_seen_stamp_sec=stamp_sec,
            )

        return pruned_ids

    def snapshot_tracks(self, stamp_sec: float, coast_timeout_sec: float) -> List[TrackState]:
        """Return track states suitable for publishing (exclude long-coasted tracks)."""
        out: List[TrackState] = []
        for tid, tr in self._tracks.items():
            if stamp_sec - tr.last_seen_stamp_sec > coast_timeout_sec:
                continue
            out.append(
                TrackState(
                    track_id=tid,
                    x=float(tr.mean[0, 0]),
                    y=float(tr.mean[1, 0]),
                    vx=float(tr.mean[2, 0]),
                    vy=float(tr.mean[3, 0]),
                    covariance_row_major=_cov_to_row_major_16(tr.cov),
                    size_w=tr.size_w,
                    size_l=tr.size_l,
                    size_h=tr.size_h,
                    last_seen_stamp_sec=tr.last_seen_stamp_sec,
                )
            )
        out.sort(key=lambda s: s.track_id)
        return out

    def all_tracks_for_history(self, stamp_sec: float) -> List[TrackState]:
        """Return all internal tracks including coasted ones (for trajectory buffers)."""
        out: List[TrackState] = []
        for tid, tr in self._tracks.items():
            out.append(
                TrackState(
                    track_id=tid,
                    x=float(tr.mean[0, 0]),
                    y=float(tr.mean[1, 0]),
                    vx=float(tr.mean[2, 0]),
                    vy=float(tr.mean[3, 0]),
                    covariance_row_major=_cov_to_row_major_16(tr.cov),
                    size_w=tr.size_w,
                    size_l=tr.size_l,
                    size_h=tr.size_h,
                    last_seen_stamp_sec=tr.last_seen_stamp_sec,
                )
            )
        out.sort(key=lambda s: s.track_id)
        return out
