#!/usr/bin/env python3
"""ROS 2 node: multi-camera vision + mmWave fusion, FusedSceneSnapshot, catalog, history jsonl, optional legacy GlobalTrackArray."""

from __future__ import annotations

import math
import os
import struct
from collections import deque
from typing import Any, Deque, Dict, List, Optional, Tuple

import rclpy
from builtin_interfaces.msg import Time
from geometry_msgs.msg import Point
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray

try:
    from usv_interfaces.msg import (
        FusedSceneSnapshot,
        FusedTargetCatalog,
        FusedTargetProfile,
        FusedTargetSnapshot,
        FusedTrackSample,
        GlobalTrack,
        GlobalTrackArray,
        MmwaveTargetArray,
        VisionDetectionArray,
    )
    from usv_interfaces.srv import GetTargetHistory
except ImportError:  # pragma: no cover
    from usv_interfaces.msg import (  # type: ignore
        FusedSceneSnapshot,
        FusedTargetCatalog,
        FusedTargetProfile,
        FusedTargetSnapshot,
        FusedTrackSample,
        GlobalTrack,
        GlobalTrackArray,
        MmwaveTargetArray,
        VisionDetectionArray,
    )
    from usv_interfaces.srv import GetTargetHistory  # type: ignore

from usv_fusion.association_fusion import FusionEngine, RadarObservation, TrackState, VisionObservation
from usv_fusion.history_io import append_target_sample_jsonl, read_target_history_jsonl, sec_to_time, time_to_sec


def sec_to_stamp(sec: float) -> Time:
    """Convert floating-point seconds since epoch segment to builtin_interfaces/Time."""
    return sec_to_time(sec)


def stamp_to_sec(stamp) -> float:
    """Convert a ROS 2 stamp to seconds."""
    return float(stamp.sec) + float(stamp.nanosec) * 1e-9


def vision_to_body_xy(
    azimuth_rad: float,
    distance_m: float,
    camera_yaw_rad: float,
    mount_x_m: float,
    mount_y_m: float,
) -> Tuple[float, float]:
    """Map monocular azimuth and range into planar body-frame coordinates."""
    rel_x = distance_m * math.cos(azimuth_rad)
    rel_y = distance_m * math.sin(azimuth_rad)
    cy = camera_yaw_rad
    x_body = mount_x_m + rel_x * math.cos(cy) - rel_y * math.sin(cy)
    y_body = mount_y_m + rel_x * math.sin(cy) + rel_y * math.cos(cy)
    return x_body, y_body


def mmwave_to_body(
    x: float,
    y: float,
    vx: float,
    vy: float,
    mount_yaw_rad: float,
    mount_x_m: float,
    mount_y_m: float,
) -> Tuple[float, float, float, float]:
    """Apply planar mount offset and yaw to mmWave-reported position and velocity."""
    c = math.cos(mount_yaw_rad)
    s = math.sin(mount_yaw_rad)
    xr = x * c - y * s
    yr = x * s + y * c
    vxr = vx * c - vy * s
    vyr = vx * s + vy * c
    return mount_x_m + xr, mount_y_m + yr, vxr, vyr


def track_id_to_color(track_id: int) -> ColorRGBA:
    """Map a track id to a stable RGBA color for RViz markers."""
    packed = struct.unpack("BBBB", struct.pack(">I", int(track_id) * 2654435761 % (2**32)))
    return ColorRGBA(
        r=float(packed[0]) / 255.0,
        g=float(packed[1]) / 255.0,
        b=float(packed[2]) / 255.0,
        a=0.95,
    )


class SensorFusionNode(Node):
    """Fuse N vision topics + mmWave into FusedSceneSnapshot, catalog, disk history, markers."""

    def __init__(self) -> None:
        """Declare parameters, subscriptions, publishers, fusion engine, and services."""
        super().__init__("sensor_fusion_node")
        self.declare_parameter("vision_topics", ["/vision/detections"])
        self.declare_parameter("vision_camera_ids", [""])
        self.declare_parameter("vision_camera_yaws", [0.0])
        self.declare_parameter("vision_camera_mount_x", [0.0])
        self.declare_parameter("vision_camera_mount_y", [0.0])
        self.declare_parameter("mmwave_topic", "/mmwave/targets")
        self.declare_parameter("fusion_snapshot_topic", "/fusion/snapshot")
        self.declare_parameter("fusion_catalog_topic", "/fusion/catalog")
        self.declare_parameter("fusion_tracks_topic", "/fusion/tracks")
        self.declare_parameter("fusion_markers_topic", "/fusion/track_markers")
        self.declare_parameter("publish_legacy_global_track", False)
        self.declare_parameter("catalog_publish_hz", 1.0)
        self.declare_parameter("track_publish_hz", 0.0)
        self.declare_parameter("output_frame_id", "base_link")
        self.declare_parameter("fusion_timer_hz", 30.0)
        self.declare_parameter("max_sync_slop_sec", 0.1)
        self.declare_parameter("sync_buffer_size", 60)
        self.declare_parameter("sync_require_all_vision_topics", False)
        self.declare_parameter("defer_spawn_merge_enabled", True)
        self.declare_parameter("defer_spawn_max_pos_m", 35.0)
        self.declare_parameter("defer_spawn_max_speed_m_s", 6.0)
        self.declare_parameter("coast_timeout_sec", 3.0)
        self.declare_parameter("track_predict_stop_sec", 3.0)
        self.declare_parameter("max_history_points_per_track", 2000)
        self.declare_parameter("history_dir", "")
        self.declare_parameter("gating_m", 4.0)
        self.declare_parameter("gate_distance_m", 25.0)
        self.declare_parameter("cluster_max_distance_m", 8.0)
        self.declare_parameter("cluster_allow_same_camera", False)
        self.declare_parameter("position_std_radar_m", 1.5)
        self.declare_parameter("position_std_vision_m", 2.0)
        self.declare_parameter("velocity_std_radar_m_s", 0.5)
        self.declare_parameter("process_noise_pos", 0.05)
        self.declare_parameter("process_noise_vel", 0.5)
        self.declare_parameter("vision_confidence_sigma_scale", 0.5)
        self.declare_parameter("radar_snr_sigma_scale", 20.0)
        self.declare_parameter("default_camera_yaw_rad", 0.0)
        self.declare_parameter("default_camera_mount_x_m", 0.0)
        self.declare_parameter("default_camera_mount_y_m", 0.0)
        self.declare_parameter("default_radar_mount_yaw_rad", 0.0)
        self.declare_parameter("default_radar_mount_x_m", 0.0)
        self.declare_parameter("default_radar_mount_y_m", 0.0)
        self.declare_parameter("max_internal_tracks", 200)
        self.declare_parameter("initial_dt_sec", 0.05)

        vtopics = list(self.get_parameter("vision_topics").get_parameter_value().string_array_value)
        if not vtopics:
            vtopics = ["/vision/detections"]
        self._vision_topics = vtopics
        n = len(vtopics)

        def _pad_str_list(name: str, fill: str) -> List[str]:
            """Pad string array parameter to length n using fill for missing entries."""
            raw = list(self.get_parameter(name).get_parameter_value().string_array_value)
            out = [(raw[i] if i < len(raw) and raw[i] else fill) for i in range(n)]
            return out

        def _pad_double_list(name: str, fill: float) -> List[float]:
            """Pad double array parameter to length n."""
            raw = list(self.get_parameter(name).get_parameter_value().double_array_value)
            out: List[float] = []
            for i in range(n):
                if i < len(raw):
                    out.append(float(raw[i]))
                else:
                    out.append(fill)
            return out

        ids = _pad_str_list("vision_camera_ids", "")
        for i in range(n):
            if not ids[i]:
                ids[i] = "cam_%d" % i
        self._vision_camera_ids = ids

        def_yaw = self.get_parameter("default_camera_yaw_rad").get_parameter_value().double_value
        def_mx = self.get_parameter("default_camera_mount_x_m").get_parameter_value().double_value
        def_my = self.get_parameter("default_camera_mount_y_m").get_parameter_value().double_value
        self._vision_yaws = _pad_double_list("vision_camera_yaws", def_yaw)
        self._vision_mx = _pad_double_list("vision_camera_mount_x", def_mx)
        self._vision_my = _pad_double_list("vision_camera_mount_y", def_my)

        self._mmwave_topic = self.get_parameter("mmwave_topic").get_parameter_value().string_value
        self._snapshot_topic = self.get_parameter("fusion_snapshot_topic").get_parameter_value().string_value
        self._catalog_topic = self.get_parameter("fusion_catalog_topic").get_parameter_value().string_value
        self._tracks_topic = self.get_parameter("fusion_tracks_topic").get_parameter_value().string_value
        self._markers_topic = self.get_parameter("fusion_markers_topic").get_parameter_value().string_value
        self._publish_legacy = self.get_parameter("publish_legacy_global_track").get_parameter_value().bool_value
        self._catalog_hz = max(0.1, self.get_parameter("catalog_publish_hz").get_parameter_value().double_value)
        self._output_frame = self.get_parameter("output_frame_id").get_parameter_value().string_value
        self._coast_timeout = self.get_parameter("coast_timeout_sec").get_parameter_value().double_value
        self._max_hist = max(
            10, int(self.get_parameter("max_history_points_per_track").get_parameter_value().integer_value)
        )
        self._history_dir = self.get_parameter("history_dir").get_parameter_value().string_value.strip()
        self._rad_yaw = self.get_parameter("default_radar_mount_yaw_rad").get_parameter_value().double_value
        self._rad_mx = self.get_parameter("default_radar_mount_x_m").get_parameter_value().double_value
        self._rad_my = self.get_parameter("default_radar_mount_y_m").get_parameter_value().double_value
        self._initial_dt = self.get_parameter("initial_dt_sec").get_parameter_value().double_value

        self._sync_slop = max(1e-4, self.get_parameter("max_sync_slop_sec").get_parameter_value().double_value)
        buf_sz = max(5, int(self.get_parameter("sync_buffer_size").get_parameter_value().integer_value))
        self._sync_require_all_vision = (
            self.get_parameter("sync_require_all_vision_topics").get_parameter_value().bool_value
        )
        self._vision_buffers: Dict[str, Deque[Tuple[float, VisionDetectionArray]]] = {
            t: deque(maxlen=buf_sz) for t in self._vision_topics
        }
        self._radar_buffer: Deque[Tuple[float, MmwaveTargetArray]] = deque(maxlen=buf_sz)

        self._engine = FusionEngine(
            gating_m=self.get_parameter("gating_m").get_parameter_value().double_value,
            gate_distance_m=self.get_parameter("gate_distance_m").get_parameter_value().double_value,
            position_std_radar_m=self.get_parameter("position_std_radar_m").get_parameter_value().double_value,
            position_std_vision_m=self.get_parameter("position_std_vision_m").get_parameter_value().double_value,
            velocity_std_radar_m_s=self.get_parameter("velocity_std_radar_m_s").get_parameter_value().double_value,
            process_noise_pos=self.get_parameter("process_noise_pos").get_parameter_value().double_value,
            process_noise_vel=self.get_parameter("process_noise_vel").get_parameter_value().double_value,
            vision_confidence_sigma_scale=self.get_parameter("vision_confidence_sigma_scale").get_parameter_value().double_value,
            radar_snr_sigma_scale=self.get_parameter("radar_snr_sigma_scale").get_parameter_value().double_value,
            max_internal_tracks=max(
                1, int(self.get_parameter("max_internal_tracks").get_parameter_value().integer_value)
            ),
            cluster_max_distance_m=self.get_parameter("cluster_max_distance_m").get_parameter_value().double_value,
            cluster_allow_same_camera=self.get_parameter("cluster_allow_same_camera").get_parameter_value().bool_value,
            defer_spawn_merge_enabled=self.get_parameter("defer_spawn_merge_enabled").get_parameter_value().bool_value,
            defer_spawn_max_pos_m=self.get_parameter("defer_spawn_max_pos_m").get_parameter_value().double_value,
            defer_spawn_max_speed_m_s=self.get_parameter("defer_spawn_max_speed_m_s").get_parameter_value().double_value,
            track_predict_stop_sec=self.get_parameter("track_predict_stop_sec").get_parameter_value().double_value,
        )
        self._last_engine_stamp_sec: Optional[float] = None
        self._history: Dict[int, Deque[Tuple[float, float, float]]] = {}
        self._profile_first_seen: Dict[int, float] = {}
        self._catalog_profiles: Dict[int, FusedTargetProfile] = {}

        qos = QoSProfile(depth=20)
        self._pub_snapshot = self.create_publisher(FusedSceneSnapshot, self._snapshot_topic, qos)
        self._pub_catalog = self.create_publisher(FusedTargetCatalog, self._catalog_topic, qos)
        self._pub_markers = self.create_publisher(MarkerArray, self._markers_topic, qos)
        self._pub_legacy: Optional[Any] = None
        if self._publish_legacy:
            self._pub_legacy = self.create_publisher(GlobalTrackArray, self._tracks_topic, qos)

        for topic in self._vision_topics:
            self.create_subscription(
                VisionDetectionArray,
                topic,
                lambda msg, t=topic: self._on_vision_topic(msg, t),
                qos,
            )
        self.create_subscription(MmwaveTargetArray, self._mmwave_topic, self._on_radar, qos)

        self.create_service(GetTargetHistory, "get_target_history", self._handle_get_history)

        hz = max(self.get_parameter("fusion_timer_hz").get_parameter_value().double_value, 1.0)
        self.create_timer(1.0 / hz, self._timer_tick)
        self.create_timer(1.0 / self._catalog_hz, self._publish_catalog_tick)

        self.get_logger().info(
            "SensorFusionNode %.1f Hz vision_topics=%s snapshot=%s sync_slop=%.3fs"
            % (hz, self._vision_topics, self._snapshot_topic, self._sync_slop)
        )

    @staticmethod
    def _pick_closest_synced(
        buf: Deque[Tuple[float, Any]], t_ref: float, slop: float
    ) -> Optional[Tuple[float, Any]]:
        """Pick (stamp_sec, msg) in buffer whose stamp is closest to t_ref within ±slop."""
        best: Optional[Tuple[float, Any]] = None
        best_abs = float("inf")
        for t_sec, m in buf:
            dt = abs(float(t_sec) - t_ref)
            if dt <= slop and dt < best_abs:
                best_abs = dt
                best = (float(t_sec), m)
        return best

    def _on_vision_topic(self, msg: VisionDetectionArray, topic: str) -> None:
        """Append stamped vision message for time-synced fusion."""
        t = stamp_to_sec(msg.header.stamp)
        b = self._vision_buffers.get(topic)
        if b is not None:
            b.append((t, msg))

    def _on_radar(self, msg: MmwaveTargetArray) -> None:
        """Append stamped mmWave message for time-synced fusion."""
        self._radar_buffer.append((stamp_to_sec(msg.header.stamp), msg))

    def _camera_index_for_topic(self, topic: str) -> int:
        """Return parameter index for a vision topic name."""
        try:
            return self._vision_topics.index(topic)
        except ValueError:
            return 0

    def _build_vision_observations_from_msg(
        self, msg: VisionDetectionArray, topic: str
    ) -> List[VisionObservation]:
        """Project each detection to body frame using the camera row matching this topic."""
        idx = self._camera_index_for_topic(topic)
        cy = self._vision_yaws[idx]
        mx = self._vision_mx[idx]
        my = self._vision_my[idx]
        cam_id = self._vision_camera_ids[idx]
        out: List[VisionObservation] = []
        for det in msg.detections:
            xb, yb = vision_to_body_xy(
                float(det.azimuth),
                float(det.distance_predict),
                cy,
                mx,
                my,
            )
            out.append(
                VisionObservation(
                    x=xb,
                    y=yb,
                    size_w=float(det.size_w),
                    size_h=float(det.size_h),
                    confidence=float(det.confidence),
                    camera_id=cam_id,
                )
            )
        return out

    def _build_radar_observations(self, msg: MmwaveTargetArray) -> List[RadarObservation]:
        """Transform each MmwaveTarget into body-frame observations."""
        out: List[RadarObservation] = []
        for t in msg.targets:
            xb, yb, vxb, vyb = mmwave_to_body(
                float(t.x),
                float(t.y),
                float(t.v_x),
                float(t.v_y),
                self._rad_yaw,
                self._rad_mx,
                self._rad_my,
            )
            out.append(
                RadarObservation(
                    x=xb,
                    y=yb,
                    vx=vxb,
                    vy=vyb,
                    size_w=float(t.size_w),
                    size_l=float(t.size_l),
                    size_h=float(t.size_h),
                    snr=float(t.snr),
                )
            )
        return out

    def _collect_fusion_inputs(
        self,
    ) -> Optional[Tuple[float, List[VisionObservation], Optional[MmwaveTargetArray]]]:
        """Time-sync inputs: per-stream pick message closest to mean(latest stamps), within slop."""
        latest_ts: List[float] = []
        for topic in self._vision_topics:
            buf = self._vision_buffers.get(topic)
            if buf:
                latest_ts.append(buf[-1][0])
        if self._radar_buffer:
            latest_ts.append(self._radar_buffer[-1][0])
        if not latest_ts:
            return None
        t_ref = sum(latest_ts) / float(len(latest_ts))

        picked_stamps: List[float] = []
        visions: List[VisionObservation] = []
        for topic in self._vision_topics:
            buf = self._vision_buffers.get(topic)
            if not buf:
                if self._sync_require_all_vision:
                    return None
                continue
            picked = self._pick_closest_synced(buf, t_ref, self._sync_slop)
            if picked is None:
                if self._sync_require_all_vision:
                    return None
                continue
            t_sel, msg = picked
            picked_stamps.append(t_sel)
            visions.extend(self._build_vision_observations_from_msg(msg, topic))

        rmsg: Optional[MmwaveTargetArray] = None
        if self._radar_buffer:
            picked = self._pick_closest_synced(self._radar_buffer, t_ref, self._sync_slop)
            if picked is not None:
                t_sel, rmsg = picked
                picked_stamps.append(t_sel)

        if not picked_stamps:
            return None
        stamp_sec = sum(picked_stamps) / float(len(picked_stamps))
        return stamp_sec, visions, rmsg

    def _append_history(self, stamp_sec: float, tracks: List[TrackState]) -> None:
        """Append positions to in-memory deques for RViz."""
        for st in tracks:
            dq = self._history.setdefault(st.track_id, deque(maxlen=self._max_hist))
            dq.append((stamp_sec, st.x, st.y))

    def _update_profiles_and_disk(self, stamp_sec: float, all_states: List[TrackState]) -> None:
        """Refresh catalog profiles, append jsonl rows when history_dir is set."""
        stamp_msg = sec_to_stamp(stamp_sec)
        for st in all_states:
            tid = int(st.track_id)
            if tid not in self._profile_first_seen:
                self._profile_first_seen[tid] = stamp_sec
            prof = self._catalog_profiles.get(tid)
            if prof is None:
                prof = FusedTargetProfile()
                prof.target_id = tid
                prof.first_seen = stamp_msg
                prof.class_id = 0
                prof.class_name = ""
                prof.is_dark_target = False
                prof.is_ais_matched = False
                prof.matched_mmsi = 0
                self._catalog_profiles[tid] = prof
            prof.size_w = st.size_w
            prof.size_l = st.size_l
            prof.size_h = st.size_h
            prof.last_profile_update = stamp_msg
            if self._history_dir:
                row: Dict[str, Any] = {
                    "t_sec": stamp_sec,
                    "x": st.x,
                    "y": st.y,
                    "v_x": st.vx,
                    "v_y": st.vy,
                    "covariance": list(st.covariance_row_major),
                }
                append_target_sample_jsonl(self._history_dir, tid, row)

    def _track_state_to_sample(self, stamp_sec: float, st: TrackState) -> FusedTrackSample:
        """Build FusedTrackSample from engine TrackState."""
        s = FusedTrackSample()
        s.stamp = sec_to_stamp(stamp_sec)
        s.t_sec = stamp_sec
        s.x = st.x
        s.y = st.y
        s.v_x = st.vx
        s.v_y = st.vy
        s.covariance = st.covariance_row_major
        return s

    def _build_scene_snapshot(
        self, stamp_msg: Time, frame_id: str, tracks: List[TrackState]
    ) -> FusedSceneSnapshot:
        """Assemble FusedSceneSnapshot for publishable tracks."""
        out = FusedSceneSnapshot()
        out.header.stamp = stamp_msg
        out.header.frame_id = frame_id
        tsec = stamp_to_sec(stamp_msg)
        for st in tracks:
            snap = FusedTargetSnapshot()
            snap.target_id = int(st.track_id)
            snap.state = self._track_state_to_sample(tsec, st)
            snap.size_w = st.size_w
            snap.size_l = st.size_l
            snap.size_h = st.size_h
            prof = self._catalog_profiles.get(int(st.track_id))
            if prof is not None:
                snap.is_dark_target = prof.is_dark_target
                snap.is_ais_matched = prof.is_ais_matched
                snap.matched_mmsi = prof.matched_mmsi
            else:
                snap.is_dark_target = False
                snap.is_ais_matched = False
                snap.matched_mmsi = 0
            out.targets.append(snap)
        return out

    def _tracks_to_global_array(self, stamp: Time, frame_id: str, tracks: List[TrackState]) -> GlobalTrackArray:
        """Legacy GlobalTrackArray for backward compatibility."""
        out = GlobalTrackArray()
        out.header.stamp = stamp
        out.header.frame_id = frame_id
        for st in tracks:
            gt = GlobalTrack()
            gt.track_id = int(st.track_id)
            gt.x = st.x
            gt.y = st.y
            gt.v_x = st.vx
            gt.v_y = st.vy
            gt.size_w = st.size_w
            gt.size_l = st.size_l
            gt.size_h = st.size_h
            gt.covariance = st.covariance_row_major
            gt.is_dark_target = False
            gt.is_ais_matched = False
            gt.matched_mmsi = 0
            gt.source_model_name = ""
            out.tracks.append(gt)
        return out

    def _make_line_markers(
        self, stamp: Time, frame_id: str, pruned_track_ids: Optional[List[int]] = None
    ) -> MarkerArray:
        """Build LINE_STRIP markers from in-memory history; DELETE pruned ids for RViz."""
        arr = MarkerArray()
        markers: List[Marker] = []
        if pruned_track_ids:
            for tid in pruned_track_ids:
                dm = Marker()
                dm.header.stamp = stamp
                dm.header.frame_id = frame_id
                dm.ns = "fusion_history"
                dm.id = int(tid)
                dm.action = Marker.DELETE
                markers.append(dm)
        for tid, pts in self._history.items():
            if len(pts) < 2:
                continue
            mk = Marker()
            mk.header.stamp = stamp
            mk.header.frame_id = frame_id
            mk.ns = "fusion_history"
            mk.id = int(tid)
            mk.type = Marker.LINE_STRIP
            mk.action = Marker.ADD
            mk.scale.x = 0.15
            mk.color = track_id_to_color(tid)
            for _ps, px, py in pts:
                p = Point()
                p.x = float(px)
                p.y = float(py)
                p.z = 0.0
                mk.points.append(p)
            markers.append(mk)
        arr.markers = markers
        return arr

    def _timer_tick(self) -> None:
        """Periodic fusion: predict/update engine, publish snapshot, markers, optional legacy."""
        chosen = self._collect_fusion_inputs()
        if chosen is None:
            return
        stamp_sec, visions, rmsg = chosen
        radars: List[RadarObservation] = self._build_radar_observations(rmsg) if rmsg else []
        if self._last_engine_stamp_sec is None:
            dt = self._initial_dt
        else:
            dt = max(stamp_sec - self._last_engine_stamp_sec, 1e-3)
        self._last_engine_stamp_sec = stamp_sec
        pruned_ids = self._engine.run_cycle(dt, stamp_sec, radars, visions)
        for tid in pruned_ids:
            self._history.pop(tid, None)
            self._catalog_profiles.pop(tid, None)
            self._profile_first_seen.pop(tid, None)
        all_states = self._engine.all_tracks_for_history(stamp_sec)
        self._append_history(stamp_sec, all_states)
        self._update_profiles_and_disk(stamp_sec, all_states)
        publishable = self._engine.snapshot_tracks(stamp_sec, self._coast_timeout)
        stamp_msg = sec_to_stamp(stamp_sec)
        self._pub_snapshot.publish(self._build_scene_snapshot(stamp_msg, self._output_frame, publishable))
        self._pub_markers.publish(self._make_line_markers(stamp_msg, self._output_frame, pruned_ids))
        if self._pub_legacy is not None:
            self._pub_legacy.publish(self._tracks_to_global_array(stamp_msg, self._output_frame, publishable))

    def _publish_catalog_tick(self) -> None:
        """Publish full profile catalog at a low rate."""
        msg = FusedTargetCatalog()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._output_frame
        for prof in sorted(self._catalog_profiles.values(), key=lambda p: p.target_id):
            msg.profiles.append(prof)
        self._pub_catalog.publish(msg)

    def _handle_get_history(self, request: Any, response: Any) -> Any:
        """Return on-disk history samples for one target."""
        if not self._history_dir:
            response.status = 2
            response.samples = []
            return response
        ts = request.t_start
        te = request.t_end
        t0 = None if (ts.sec == 0 and ts.nanosec == 0) else time_to_sec(ts)
        t1 = None if (te.sec == 0 and te.nanosec == 0) else time_to_sec(te)
        max_n = int(request.max_samples)
        status, rows = read_target_history_jsonl(
            self._history_dir, int(request.target_id), t0, t1, max_n
        )
        response.status = status
        response.samples = []
        if status != 0:
            return response
        for row in rows:
            s = FusedTrackSample()
            sec = float(row["t_sec"])
            s.stamp = sec_to_stamp(sec)
            s.t_sec = sec
            s.x = float(row["x"])
            s.y = float(row["y"])
            s.v_x = float(row.get("v_x", 0.0))
            s.v_y = float(row.get("v_y", 0.0))
            cov = row.get("covariance", [0.0] * 16)
            s.covariance = [float(cov[i]) if i < len(cov) else 0.0 for i in range(16)]
            response.samples.append(s)
        return response


def main(args: Optional[List[str]] = None) -> None:
    """Initialize rclpy, spin SensorFusionNode, and shut down cleanly."""
    rclpy.init(args=args)
    node = SensorFusionNode()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
