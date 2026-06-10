"""全局航迹表 + 事件步进 CV-EKF（每次调用仅处理一种模态）。"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Dict, List, Optional, Sequence
from uuid import UUID

import numpy as np

from usv_event_fusion.association import BIG, solve_gated_assignment
from usv_event_fusion.association_contract import Modality
from usv_event_fusion.association_metrics import (
    AssociationMetricConfig,
    VisionWidthMatchConfig,
    _radar_gate_flags,
    _vision_gate_flags,
    build_radar_association_cost,
    build_vision_association_cost,
    record_radar_gate_failure,
    record_vision_gate_failure,
)
from usv_event_fusion.filters import ekf_update_linear, ekf_update_polar
from usv_event_fusion.motion_model import predict_cv
from usv_event_fusion.sensor_models import (
    effective_size_lpf_alpha,
    radar_position_variance,
    radar_velocity_variance,
    track_planar_distance,
    vision_polar_variance,
)
from usv_event_fusion.track_state import (
    InternalTrack,
    TrackProfile,
    TrackState,
    TrackStatus,
    track_state_from_internal,
)
from usv_event_fusion.fusion_diagnostics import FusionDiagWindow, ModalityAssocStats
from usv_event_fusion.track_overlap import TrackMergeConfig, merge_overlapping_track_ids
from usv_event_fusion.track_uuid import new_track_uuid, uuid_sort_key


@dataclass
class VisionObservation:
    """船体坐标系下的平面视觉检测。"""

    x: float
    y: float
    range_m: float
    bearing_rad: float
    size_w: float
    size_h: float
    pixel_width: float
    confidence: float
    class_id: int = 0
    class_name: str = ""
    camera_id: str = ""


@dataclass
class RadarObservation:
    """船体坐标系下的平面毫米波簇。"""

    x: float
    y: float
    vx: float
    vy: float
    size_w: float
    size_l: float
    size_h: float
    objmotion_status: int
    radar_track_id: int
    radar_id: str = ""


@dataclass
class FusionConfig:
    """可调融合参数。"""

    q_pos: float = 0.05
    q_vel: float = 0.5
    pos_std_radar_m: float = 1.5
    vel_std_radar_m_s: float = 0.5
    vision_sigma_range_m: float = 2.0
    vision_sigma_bearing_rad: float = 0.05
    vision_conf_scale: float = 0.5
    chi2_gate_vision: float = 5.991
    chi2_gate_radar: float = 9.488
    max_internal_tracks: int = 12
    track_predict_stop_sec: float = 2.5
    promotion_min_hits: int = 3
    spawn_suppression_radius_m: float = 15.0
    initial_vel_variance: float = 25.0
    profile_size_lpf_alpha: float = 0.35
    size_update_ref_distance_m: float = 50.0
    size_update_min_weight: float = 0.1
    class_history_len: int = 10
    class_match_min_confidence: float = 0.6
    association_width_weight: float = 1.5
    width_meas_std_radar_m: float = 0.5
    width_track_std_m: float = 0.3
    width_gate_sigma: float = 2.0
    vision_focal_length_px: float = 800.0
    width_meas_std_vision_px: float = 12.0
    width_track_std_vision_px: float = 8.0
    radar_static_vel_inflate: float = 3.0
    enable_track_merge: bool = True
    merge_center_distance_m: float = 10.0
    merge_use_kin_gate: bool = True
    merge_kin_chi2_gate: float = 9.488


class FusionEngine:
    """维护一份全局航迹列表；`run_at_time` 处理一批单一模态观测。"""

    def __init__(self, config: Optional[FusionConfig] = None) -> None:
        self.cfg = config or FusionConfig()
        self._tracks: Dict[UUID, InternalTrack] = {}
        self._diag = FusionDiagWindow()

    def drain_diag_window(self) -> FusionDiagWindow:
        snap = self._diag
        self._diag = FusionDiagWindow()
        return snap

    def set_publish_diag(self, snapshot_count: int, marker_count: int) -> None:
        self._diag.snapshot_count = snapshot_count
        self._diag.marker_count = marker_count
        self._refresh_track_inventory_diag()

    def _refresh_track_inventory_diag(self) -> None:
        tentative = 0
        confirmed = 0
        for tr in self._tracks.values():
            if tr.status == TrackStatus.CONFIRMED:
                confirmed += 1
            else:
                tentative += 1
        self._diag.internal_tracks = len(self._tracks)
        self._diag.tentative_tracks = tentative
        self._diag.confirmed_tracks = confirmed

    @staticmethod
    def _record_gate_cell(stats: ModalityAssocStats, fail_reason: str, d2_kin: float) -> None:
        stats.gate_cells += 1
        if fail_reason == "pass":
            stats.record_gate_pass(d2_kin)
        elif fail_reason == "chi2":
            stats.fail_chi2 += 1
        elif fail_reason == "width":
            stats.fail_width += 1
        elif fail_reason == "class":
            stats.fail_class += 1

    def reset(self) -> None:
        self._tracks.clear()

    def _allocate_id(self) -> UUID:
        return new_track_uuid()

    def _sorted_track_rows(self) -> List[InternalTrack]:
        return [self._tracks[k] for k in sorted(self._tracks.keys(), key=uuid_sort_key)]

    def _prune_stale(self, stamp_sec: float) -> List[UUID]:
        removed: List[UUID] = []
        if self.cfg.track_predict_stop_sec <= 0.0:
            return removed
        lim = float(self.cfg.track_predict_stop_sec)
        for tid in list(self._tracks.keys()):
            tr = self._tracks[tid]
            if stamp_sec - tr.last_filter_stamp_sec > lim:
                del self._tracks[tid]
                removed.append(tid)
        return removed

    def _spawn_suppressed(self, x: float, y: float) -> bool:
        """若量测已落在现有航迹邻域内，抑制新生以免重复暂态航迹。"""
        radius = float(self.cfg.spawn_suppression_radius_m)
        if radius <= 0.0:
            return False
        for tr in self._tracks.values():
            dx = float(tr.mean[0, 0]) - x
            dy = float(tr.mean[1, 0]) - y
            if float(np.hypot(dx, dy)) <= radius:
                return True
        return False

    def _vision_metric_cfg(self) -> AssociationMetricConfig:
        return AssociationMetricConfig(
            chi2_gate_kin=float(self.cfg.chi2_gate_vision),
            association_width_weight=float(self.cfg.association_width_weight),
            width_meas_std=0.0,
            width_track_std=0.0,
            width_gate_sigma=float(self.cfg.width_gate_sigma),
            class_match_min_confidence=float(self.cfg.class_match_min_confidence),
        )

    def _vision_width_cfg(self) -> VisionWidthMatchConfig:
        return VisionWidthMatchConfig(
            focal_length_px=float(self.cfg.vision_focal_length_px),
            width_meas_std_px=float(self.cfg.width_meas_std_vision_px),
            width_track_std_px=float(self.cfg.width_track_std_vision_px),
        )

    def _radar_metric_cfg(self) -> AssociationMetricConfig:
        return AssociationMetricConfig(
            chi2_gate_kin=float(self.cfg.chi2_gate_radar),
            association_width_weight=float(self.cfg.association_width_weight),
            width_meas_std=float(self.cfg.width_meas_std_radar_m),
            width_track_std=float(self.cfg.width_track_std_m),
            width_gate_sigma=float(self.cfg.width_gate_sigma),
            class_match_min_confidence=float(self.cfg.class_match_min_confidence),
        )

    def _predict_tracks_to(self, rows: List[InternalTrack], stamp_sec: float) -> None:
        """按 last_predict_stamp_sec 增量 CV 预测；仅 birth 且未再关联的暂态航迹不预测。"""
        for tr in rows:
            if tr.status == TrackStatus.TENTATIVE and tr.association_hits <= 1:
                continue
            dt = float(max(stamp_sec - tr.last_predict_stamp_sec, 1e-6))
            tr.mean, tr.cov = predict_cv(tr.mean, tr.cov, dt, self.cfg.q_pos, self.cfg.q_vel)
            tr.last_predict_stamp_sec = stamp_sec

    def _mark_filter_update(self, tr: InternalTrack, stamp_sec: float) -> None:
        tr.last_filter_stamp_sec = stamp_sec
        tr.last_predict_stamp_sec = stamp_sec

    def _distance_weighted_alpha(self, distance_m: float) -> float:
        return effective_size_lpf_alpha(
            self.cfg.profile_size_lpf_alpha,
            distance_m,
            self.cfg.size_update_ref_distance_m,
            self.cfg.size_update_min_weight,
        )

    def _apply_vision_profile(self, tr: InternalTrack, o: VisionObservation) -> None:
        dist = max(o.range_m, track_planar_distance(tr.mean))
        alpha = self._distance_weighted_alpha(dist)
        tr.profile.update_sizes_lpf(o.size_w, o.size_w, o.size_h, alpha)
        tr.profile.update_class_vote(o.class_name, o.class_id, self.cfg.class_history_len)

    def _apply_radar_profile(self, tr: InternalTrack, o: RadarObservation) -> None:
        dist = max(track_planar_distance(tr.mean), float(np.hypot(o.x, o.y)))
        alpha = self._distance_weighted_alpha(dist)
        tr.profile.update_sizes_lpf(o.size_w, o.size_l, o.size_h, alpha)
        tr.profile.radar_track_id = int(o.radar_track_id)

    def _track_merge_cfg(self) -> TrackMergeConfig:
        return TrackMergeConfig(
            center_distance_m=float(self.cfg.merge_center_distance_m),
            use_kin_gate=bool(self.cfg.merge_use_kin_gate),
            kin_chi2_gate=float(self.cfg.merge_kin_chi2_gate),
            width_track_std_m=float(self.cfg.width_track_std_m),
            width_gate_sigma=float(self.cfg.width_gate_sigma),
            class_match_min_confidence=float(self.cfg.class_match_min_confidence),
        )

    def _merge_overlapping_tracks(self) -> List[UUID]:
        if not self.cfg.enable_track_merge or len(self._tracks) < 2:
            return []
        merged_pairs = merge_overlapping_track_ids(
            self._tracks,
            self._track_merge_cfg(),
            self.cfg.class_history_len,
        )
        if merged_pairs:
            self._diag.tracks_merged_total += len(merged_pairs)
            self._diag.last_merged_pairs.extend(merged_pairs)
        return [loser_id for _, loser_id in merged_pairs]

    def run_at_time(
        self,
        stamp_sec: float,
        modality: Modality,
        vision_obs: Sequence[VisionObservation],
        radar_obs: Sequence[RadarObservation],
    ) -> List[UUID]:
        removed = self._prune_stale(stamp_sec)
        if removed:
            self._diag.pruned_total += len(removed)
        rows = self._sorted_track_rows()

        self._predict_tracks_to(rows, stamp_sec)

        if modality == Modality.VISION:
            removed += self._vision_step(stamp_sec, list(vision_obs))
        elif modality == Modality.RADAR:
            removed += self._radar_step(stamp_sec, list(radar_obs))
        else:
            raise ValueError("Unknown modality")
        removed += self._merge_overlapping_tracks()
        return removed

    def _build_vision_measurements(
        self, obs: List[VisionObservation]
    ) -> tuple[List[np.ndarray], List[np.ndarray]]:
        zs: List[np.ndarray] = []
        Rs: List[np.ndarray] = []
        for o in obs:
            zs.append(np.array([[o.range_m], [o.bearing_rad]], dtype=np.float64))
            vr, vt = vision_polar_variance(
                o.confidence,
                self.cfg.vision_sigma_range_m,
                self.cfg.vision_sigma_bearing_rad,
                self.cfg.vision_conf_scale,
            )
            Rs.append(np.diag([vr, vt]).astype(np.float64))
        return zs, Rs

    def _build_radar_measurements(
        self, obs: List[RadarObservation]
    ) -> tuple[List[np.ndarray], List[np.ndarray]]:
        zs: List[np.ndarray] = []
        Rs: List[np.ndarray] = []
        for o in obs:
            zs.append(np.array([[o.x], [o.y], [o.vx], [o.vy]], dtype=np.float64))
            pv = radar_position_variance(self.cfg.pos_std_radar_m)
            is_static = int(o.objmotion_status) == 0
            vv = radar_velocity_variance(
                self.cfg.vel_std_radar_m_s,
                self.cfg.radar_static_vel_inflate,
                is_static,
            )
            Rs.append(np.diag([pv, pv, vv, vv]).astype(np.float64))
        return zs, Rs

    def _vision_step(self, stamp_sec: float, obs: List[VisionObservation]) -> List[UUID]:
        return self._vision_hungarian(stamp_sec, obs)

    def _vision_hungarian(self, stamp_sec: float, obs: List[VisionObservation]) -> List[UUID]:
        stats = self._diag.vision
        stats.callbacks += 1
        rows = self._sorted_track_rows()
        n_t = len(rows)
        n_m = len(obs)
        if n_m == 0:
            stats.empty_meas_skips += 1
            self._refresh_track_inventory_diag()
            return []

        stats.meas_total += n_m
        stats.tracks_at_step += n_t
        metric_cfg = self._vision_metric_cfg()
        width_cfg = self._vision_width_cfg()
        zs, Rs = self._build_vision_measurements(obs)

        cost = np.full((n_t, n_m), BIG, dtype=np.float64)
        if n_t > 0:
            for i, tr in enumerate(rows):
                for j in range(n_m):
                    chi2_ok, width_ok, class_ok, d2_kin = _vision_gate_flags(
                        tr,
                        obs[j].pixel_width,
                        obs[j].class_name,
                        zs[j],
                        Rs[j],
                        metric_cfg,
                        width_cfg,
                    )
                    self._record_gate_cell(
                        stats,
                        record_vision_gate_failure(chi2_ok, width_ok, class_ok),
                        d2_kin,
                    )
                    cost[i, j] = build_vision_association_cost(
                        tr,
                        obs[j].pixel_width,
                        obs[j].class_name,
                        zs[j],
                        Rs[j],
                        metric_cfg,
                        width_cfg,
                    )

        if n_t == 0:
            spawned = self._spawn_vision_births(stamp_sec, obs, zs, Rs, stats)
            stats.empty_table_births += spawned
            self._refresh_track_inventory_diag()
            return []

        assign = solve_gated_assignment(n_t, n_m, cost, dummy_cost=float(metric_cfg.chi2_gate_kin))
        stats.pairs_matched += len(assign.pairs)
        stats.tracks_coast += len(assign.unmatched_track_rows)
        stats.meas_unmatched += len(assign.unmatched_measurement_indices)
        promoted_before = sum(1 for tr in rows if tr.status == TrackStatus.CONFIRMED)
        for ti, mj in assign.pairs:
            tr = rows[ti]
            tr.mean, tr.cov = ekf_update_polar(tr.mean, tr.cov, zs[mj], Rs[mj])
            self._apply_vision_profile(tr, obs[mj])
            self._mark_filter_update(tr, stamp_sec)
            tr.association_hits += 1
            self._maybe_promote(tr)

        for mj in assign.unmatched_measurement_indices:
            if len(self._tracks) >= self.cfg.max_internal_tracks:
                break
            o = obs[mj]
            if self._spawn_suppressed(o.x, o.y):
                stats.spawn_suppressed += 1
                continue
            self._spawn_vision_track(stamp_sec, o, zs[mj], Rs[mj])
            stats.spawned += 1

        promoted_after = sum(1 for tr in self._tracks.values() if tr.status == TrackStatus.CONFIRMED)
        if promoted_after > promoted_before:
            for tr in self._tracks.values():
                if tr.status == TrackStatus.CONFIRMED and tr.track_id not in self._diag.last_promoted_ids:
                    if tr.association_hits == self.cfg.promotion_min_hits:
                        self._diag.last_promoted_ids.append(tr.track_id)
        self._refresh_track_inventory_diag()
        return []

    def _radar_step(self, stamp_sec: float, obs: List[RadarObservation]) -> List[UUID]:
        return self._radar_hungarian(stamp_sec, obs)

    def _radar_hungarian(self, stamp_sec: float, obs: List[RadarObservation]) -> List[UUID]:
        stats = self._diag.radar
        stats.callbacks += 1
        rows = self._sorted_track_rows()
        n_t = len(rows)
        n_m = len(obs)
        if n_m == 0:
            stats.empty_meas_skips += 1
            self._refresh_track_inventory_diag()
            return []

        stats.meas_total += n_m
        stats.tracks_at_step += n_t
        metric_cfg = self._radar_metric_cfg()
        zs, Rs = self._build_radar_measurements(obs)
        H = np.eye(4, dtype=np.float64)

        cost = np.full((n_t, n_m), BIG, dtype=np.float64)
        if n_t > 0:
            for i, tr in enumerate(rows):
                for j in range(n_m):
                    chi2_ok, width_ok, d2_kin = _radar_gate_flags(tr, obs[j].size_w, zs[j], Rs[j], metric_cfg)
                    self._record_gate_cell(
                        stats,
                        record_radar_gate_failure(chi2_ok, width_ok),
                        d2_kin,
                    )
                    cost[i, j] = build_radar_association_cost(tr, obs[j].size_w, zs[j], Rs[j], metric_cfg)

        if n_t == 0:
            spawned = self._spawn_radar_births(stamp_sec, obs, zs, Rs, stats)
            stats.empty_table_births += spawned
            self._refresh_track_inventory_diag()
            return []

        assign = solve_gated_assignment(n_t, n_m, cost, dummy_cost=float(metric_cfg.chi2_gate_kin))
        stats.pairs_matched += len(assign.pairs)
        stats.tracks_coast += len(assign.unmatched_track_rows)
        stats.meas_unmatched += len(assign.unmatched_measurement_indices)
        promoted_before = sum(1 for tr in rows if tr.status == TrackStatus.CONFIRMED)
        for ti, mj in assign.pairs:
            tr = rows[ti]
            tr.mean, tr.cov = ekf_update_linear(tr.mean, tr.cov, zs[mj], H, Rs[mj])
            self._apply_radar_profile(tr, obs[mj])
            self._mark_filter_update(tr, stamp_sec)
            tr.association_hits += 1
            self._maybe_promote(tr)

        for mj in assign.unmatched_measurement_indices:
            if len(self._tracks) >= self.cfg.max_internal_tracks:
                break
            o = obs[mj]
            if self._spawn_suppressed(o.x, o.y):
                stats.spawn_suppressed += 1
                continue
            self._spawn_radar_track(stamp_sec, o, zs[mj], Rs[mj])
            stats.spawned += 1

        promoted_after = sum(1 for tr in self._tracks.values() if tr.status == TrackStatus.CONFIRMED)
        if promoted_after > promoted_before:
            for tr in self._tracks.values():
                if tr.status == TrackStatus.CONFIRMED and tr.track_id not in self._diag.last_promoted_ids:
                    if tr.association_hits == self.cfg.promotion_min_hits:
                        self._diag.last_promoted_ids.append(tr.track_id)
        self._refresh_track_inventory_diag()
        return []

    def _maybe_promote(self, tr: InternalTrack) -> None:
        if tr.status == TrackStatus.CONFIRMED:
            return
        if tr.association_hits >= self.cfg.promotion_min_hits:
            tr.status = TrackStatus.CONFIRMED

    def _spawn_vision_track(
        self,
        stamp_sec: float,
        o: VisionObservation,
        z: np.ndarray,
        R: np.ndarray,
    ) -> None:
        tid = self._allocate_id()
        mean = np.array([[o.x], [o.y], [0.0], [0.0]], dtype=np.float64)
        iv = float(self.cfg.initial_vel_variance)
        vr = float(R[0, 0])
        vt = float(R[1, 1])
        cov = np.diag([vr, vt, iv, iv]).astype(np.float64)
        profile = TrackProfile(size_w=o.size_w, size_l=o.size_w, size_h=o.size_h)
        profile.update_class_vote(o.class_name, o.class_id, self.cfg.class_history_len)
        self._tracks[tid] = InternalTrack(
            track_id=tid,
            mean=mean,
            cov=cov,
            profile=profile,
            last_filter_stamp_sec=stamp_sec,
            last_predict_stamp_sec=stamp_sec,
            status=TrackStatus.TENTATIVE,
            association_hits=1,
        )

    def _spawn_vision_births(
        self,
        stamp_sec: float,
        obs: List[VisionObservation],
        zs: List[np.ndarray],
        Rs: List[np.ndarray],
        stats: Optional[ModalityAssocStats] = None,
    ) -> int:
        spawned = 0
        for j, o in enumerate(obs):
            if len(self._tracks) >= self.cfg.max_internal_tracks:
                break
            if self._spawn_suppressed(o.x, o.y):
                if stats is not None:
                    stats.spawn_suppressed += 1
                continue
            self._spawn_vision_track(stamp_sec, o, zs[j], Rs[j])
            spawned += 1
            if stats is not None:
                stats.spawned += 1
        return spawned

    def _spawn_radar_track(
        self,
        stamp_sec: float,
        o: RadarObservation,
        z: np.ndarray,
        R: np.ndarray,
    ) -> None:
        tid = self._allocate_id()
        mean = z.copy().astype(np.float64)
        cov = R.copy()
        for d in range(2, 4):
            if cov[d, d] < 1e-3:
                cov[d, d] = 1.0
        profile = TrackProfile(
            size_w=o.size_w,
            size_l=o.size_l,
            size_h=o.size_h,
            radar_track_id=int(o.radar_track_id),
        )
        self._tracks[tid] = InternalTrack(
            track_id=tid,
            mean=mean,
            cov=cov,
            profile=profile,
            last_filter_stamp_sec=stamp_sec,
            last_predict_stamp_sec=stamp_sec,
            status=TrackStatus.TENTATIVE,
            association_hits=1,
        )

    def _spawn_radar_births(
        self,
        stamp_sec: float,
        obs: List[RadarObservation],
        zs: List[np.ndarray],
        Rs: List[np.ndarray],
        stats: Optional[ModalityAssocStats] = None,
    ) -> int:
        spawned = 0
        for j, o in enumerate(obs):
            if len(self._tracks) >= self.cfg.max_internal_tracks:
                break
            if self._spawn_suppressed(o.x, o.y):
                if stats is not None:
                    stats.spawn_suppressed += 1
                continue
            self._spawn_radar_track(stamp_sec, o, zs[j], Rs[j])
            spawned += 1
            if stats is not None:
                stats.spawned += 1
        return spawned

    def snapshot_confirmed(self, stamp_sec: float, coast_timeout_sec: float) -> List[TrackState]:
        out: List[TrackState] = []
        for tid in sorted(self._tracks.keys(), key=uuid_sort_key):
            tr = self._tracks[tid]
            if tr.status != TrackStatus.CONFIRMED:
                continue
            if stamp_sec - tr.last_filter_stamp_sec > coast_timeout_sec:
                continue
            out.append(track_state_from_internal(tr))
        return out

    def all_tracks_internal(self, _stamp_sec: float) -> List[TrackState]:
        return [
            track_state_from_internal(self._tracks[tid])
            for tid in sorted(self._tracks.keys(), key=uuid_sort_key)
        ]
