#!/usr/bin/env python3
"""ROS 2 节点：事件驱动的视觉/毫米波融合，使用单一全局航迹表。"""

from __future__ import annotations

import math
import threading
from collections import deque
from typing import Any, Deque, Dict, List, Optional, Tuple
from uuid import UUID

import rclpy
from builtin_interfaces.msg import Time
from geometry_msgs.msg import Point
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.qos import QoSProfile
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

from usv_event_fusion.association_contract import Modality
from usv_event_fusion.fusion_engine import FusionConfig, FusionEngine, RadarObservation, VisionObservation
from usv_event_fusion.fusion_diagnostics import FusionDiagWindow, _fmt_d2_range
from usv_event_fusion.track_state import TrackState
from usv_event_fusion.track_uuid import fill_ros_uuid, ros_uuid_to_bytes, uuid_to_color, uuid_to_marker_id

from usv_event_fusion.sensor_models import mmwave_to_body, profile_width_to_pixel_width, vision_to_body_polar


def stamp_to_sec(stamp: Time) -> float:
    return float(stamp.sec) + float(stamp.nanosec) * 1e-9


def sec_to_stamp(sec: float) -> Time:
    t = Time()
    s = math.floor(sec)
    t.sec = int(s)
    t.nanosec = int(round((sec - s) * 1e9))
    return t


class EventFusionNode(Node):
    """订阅回调触发融合；互斥锁保护融合引擎临界区。"""

    def __init__(self) -> None:
        super().__init__("event_fusion_node")
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
        self.declare_parameter("coast_timeout_sec", 3.0)
        self.declare_parameter("max_history_points_per_track", 2000)
        self.declare_parameter("track_predict_stop_sec", 2.5)
        self.declare_parameter("promotion_min_hits", 3)
        self.declare_parameter("max_internal_tracks", 12)
        self.declare_parameter("chi2_gate_vision", 5.991)
        self.declare_parameter("chi2_gate_radar", 9.488)
        self.declare_parameter("position_std_radar_m", 1.5)
        self.declare_parameter("velocity_std_radar_m_s", 0.5)
        self.declare_parameter("vision_sigma_range_m", 2.0)
        self.declare_parameter("vision_sigma_bearing_rad", 0.05)
        self.declare_parameter("process_noise_pos", 0.05)
        self.declare_parameter("process_noise_vel", 0.5)
        self.declare_parameter("vision_confidence_sigma_scale", 0.5)
        self.declare_parameter("profile_size_lpf_alpha", 0.35)
        self.declare_parameter("size_update_ref_distance_m", 50.0)
        self.declare_parameter("size_update_min_weight", 0.1)
        self.declare_parameter("class_history_len", 10)
        self.declare_parameter("class_match_min_confidence", 0.6)
        self.declare_parameter("association_width_weight", 1.5)
        self.declare_parameter("width_meas_std_radar_m", 0.5)
        self.declare_parameter("width_track_std_m", 0.3)
        self.declare_parameter("width_gate_sigma", 2.0)
        self.declare_parameter("vision_focal_length_px", 800.0)
        self.declare_parameter("width_meas_std_vision_px", 12.0)
        self.declare_parameter("width_track_std_vision_px", 8.0)
        self.declare_parameter("radar_static_vel_inflate", 3.0)
        self.declare_parameter("default_camera_yaw_rad", 0.0)
        self.declare_parameter("default_camera_mount_x_m", 0.0)
        self.declare_parameter("default_camera_mount_y_m", 0.0)
        self.declare_parameter("default_radar_mount_yaw_rad", 0.0)
        self.declare_parameter("default_radar_mount_x_m", 0.0)
        self.declare_parameter("default_radar_mount_y_m", 0.0)
        self.declare_parameter("spawn_suppression_radius_m", 15.0)
        self.declare_parameter("association_diag_hz", 1.0)
        self.declare_parameter("enable_track_merge", True)
        self.declare_parameter("merge_center_distance_m", 10.0)
        self.declare_parameter("merge_use_kin_gate", True)
        self.declare_parameter("merge_kin_chi2_gate", 9.488)

        vtopics = list(self.get_parameter("vision_topics").get_parameter_value().string_array_value)
        if not vtopics:
            vtopics = ["/vision/detections"]
        self._vision_topics = vtopics
        n = len(vtopics)

        def _pad_str(name: str, fill: str) -> List[str]:
            raw = list(self.get_parameter(name).get_parameter_value().string_array_value)
            return [(raw[i] if i < len(raw) and raw[i] else fill) for i in range(n)]

        def _pad_double(name: str, fill: float) -> List[float]:
            raw = list(self.get_parameter(name).get_parameter_value().double_array_value)
            out: List[float] = []
            for i in range(n):
                out.append(float(raw[i]) if i < len(raw) else fill)
            return out

        ids = _pad_str("vision_camera_ids", "")
        for i in range(n):
            if not ids[i]:
                ids[i] = "cam_%d" % i
        self._vision_camera_ids = ids
        def_yaw = self.get_parameter("default_camera_yaw_rad").get_parameter_value().double_value
        def_mx = self.get_parameter("default_camera_mount_x_m").get_parameter_value().double_value
        def_my = self.get_parameter("default_camera_mount_y_m").get_parameter_value().double_value
        self._vision_yaws = _pad_double("vision_camera_yaws", def_yaw)
        self._vision_mx = _pad_double("vision_camera_mount_x", def_mx)
        self._vision_my = _pad_double("vision_camera_mount_y", def_my)

        self._mmwave_topic = self.get_parameter("mmwave_topic").get_parameter_value().string_value
        self._snapshot_topic = self.get_parameter("fusion_snapshot_topic").get_parameter_value().string_value
        self._catalog_topic = self.get_parameter("fusion_catalog_topic").get_parameter_value().string_value
        self._tracks_topic = self.get_parameter("fusion_tracks_topic").get_parameter_value().string_value
        self._markers_topic = self.get_parameter("fusion_markers_topic").get_parameter_value().string_value
        self._publish_legacy = self.get_parameter("publish_legacy_global_track").get_parameter_value().bool_value
        self._catalog_hz = max(0.1, self.get_parameter("catalog_publish_hz").get_parameter_value().double_value)
        self._track_publish_hz = max(
            0.0, float(self.get_parameter("track_publish_hz").get_parameter_value().double_value)
        )
        self._output_frame = self.get_parameter("output_frame_id").get_parameter_value().string_value
        self._coast_timeout = self.get_parameter("coast_timeout_sec").get_parameter_value().double_value
        self._max_hist = max(10, int(self.get_parameter("max_history_points_per_track").get_parameter_value().integer_value))

        self._rad_yaw = self.get_parameter("default_radar_mount_yaw_rad").get_parameter_value().double_value
        self._rad_mx = self.get_parameter("default_radar_mount_x_m").get_parameter_value().double_value
        self._rad_my = self.get_parameter("default_radar_mount_y_m").get_parameter_value().double_value
        self._vision_focal_px = self.get_parameter("vision_focal_length_px").get_parameter_value().double_value

        cfg = FusionConfig(
            q_pos=self.get_parameter("process_noise_pos").get_parameter_value().double_value,
            q_vel=self.get_parameter("process_noise_vel").get_parameter_value().double_value,
            pos_std_radar_m=self.get_parameter("position_std_radar_m").get_parameter_value().double_value,
            vel_std_radar_m_s=self.get_parameter("velocity_std_radar_m_s").get_parameter_value().double_value,
            vision_sigma_range_m=self.get_parameter("vision_sigma_range_m").get_parameter_value().double_value,
            vision_sigma_bearing_rad=self.get_parameter("vision_sigma_bearing_rad").get_parameter_value().double_value,
            vision_conf_scale=self.get_parameter("vision_confidence_sigma_scale").get_parameter_value().double_value,
            chi2_gate_vision=self.get_parameter("chi2_gate_vision").get_parameter_value().double_value,
            chi2_gate_radar=self.get_parameter("chi2_gate_radar").get_parameter_value().double_value,
            max_internal_tracks=max(1, int(self.get_parameter("max_internal_tracks").get_parameter_value().integer_value)),
            track_predict_stop_sec=float(self.get_parameter("track_predict_stop_sec").get_parameter_value().double_value),
            promotion_min_hits=max(1, int(self.get_parameter("promotion_min_hits").get_parameter_value().integer_value)),
            profile_size_lpf_alpha=float(self.get_parameter("profile_size_lpf_alpha").get_parameter_value().double_value),
            size_update_ref_distance_m=float(
                self.get_parameter("size_update_ref_distance_m").get_parameter_value().double_value
            ),
            size_update_min_weight=float(
                self.get_parameter("size_update_min_weight").get_parameter_value().double_value
            ),
            class_history_len=max(1, int(self.get_parameter("class_history_len").get_parameter_value().integer_value)),
            class_match_min_confidence=float(
                self.get_parameter("class_match_min_confidence").get_parameter_value().double_value
            ),
            association_width_weight=float(
                self.get_parameter("association_width_weight").get_parameter_value().double_value
            ),
            width_meas_std_radar_m=float(
                self.get_parameter("width_meas_std_radar_m").get_parameter_value().double_value
            ),
            width_track_std_m=float(self.get_parameter("width_track_std_m").get_parameter_value().double_value),
            width_gate_sigma=float(self.get_parameter("width_gate_sigma").get_parameter_value().double_value),
            vision_focal_length_px=float(
                self.get_parameter("vision_focal_length_px").get_parameter_value().double_value
            ),
            width_meas_std_vision_px=float(
                self.get_parameter("width_meas_std_vision_px").get_parameter_value().double_value
            ),
            width_track_std_vision_px=float(
                self.get_parameter("width_track_std_vision_px").get_parameter_value().double_value
            ),
            radar_static_vel_inflate=float(
                self.get_parameter("radar_static_vel_inflate").get_parameter_value().double_value
            ),
            spawn_suppression_radius_m=float(
                self.get_parameter("spawn_suppression_radius_m").get_parameter_value().double_value
            ),
            enable_track_merge=self.get_parameter("enable_track_merge").get_parameter_value().bool_value,
            merge_center_distance_m=float(
                self.get_parameter("merge_center_distance_m").get_parameter_value().double_value
            ),
            merge_use_kin_gate=self.get_parameter("merge_use_kin_gate").get_parameter_value().bool_value,
            merge_kin_chi2_gate=float(
                self.get_parameter("merge_kin_chi2_gate").get_parameter_value().double_value
            ),
        )
        self._engine = FusionEngine(cfg)
        self._fusion_lock = threading.Lock()

        self._history: Dict[UUID, Deque[Tuple[float, float, float]]] = {}
        self._profile_first_seen: Dict[UUID, float] = {}
        self._catalog_profiles: Dict[UUID, FusedTargetProfile] = {}

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
                lambda msg, t=topic: self._on_vision(msg, t),
                qos,
            )
        self.create_subscription(MmwaveTargetArray, self._mmwave_topic, self._on_radar, qos)

        self.create_timer(1.0 / self._catalog_hz, self._publish_catalog_tick)
        if self._track_publish_hz > 0.0:
            self.create_timer(1.0 / self._track_publish_hz, self._track_publish_tick)
        diag_hz = max(0.0, float(self.get_parameter("association_diag_hz").get_parameter_value().double_value))
        if diag_hz > 0.0:
            self.create_timer(1.0 / diag_hz, self._association_diag_tick)

        self._clear_fusion_markers_once()

        track_pub_info = (
            "track_markers=%.1f Hz (decoupled)" % self._track_publish_hz
            if self._track_publish_hz > 0.0
            else "track_markers=event-driven"
        )
        self.get_logger().info(
            "EventFusionNode vision_topics=%s snapshot=%s %s (mutex-protected fusion)"
            % (self._vision_topics, self._snapshot_topic, track_pub_info)
        )

    def _clear_fusion_markers_once(self) -> None:
        """节点启动时清空 RViz 中 fusion_history 命名空间的残留 marker。"""
        stamp = self.get_clock().now().to_msg()
        clear = MarkerArray()
        dm = Marker()
        dm.header.stamp = stamp
        dm.header.frame_id = self._output_frame
        dm.ns = "fusion_history"
        dm.id = 0
        dm.action = Marker.DELETEALL
        clear.markers = [dm]
        self._pub_markers.publish(clear)

    def _camera_index_for_topic(self, topic: str) -> int:
        try:
            return self._vision_topics.index(topic)
        except ValueError:
            return 0

    def _build_vision_observations(self, msg: VisionDetectionArray, topic: str) -> List[VisionObservation]:
        idx = self._camera_index_for_topic(topic)
        cy = self._vision_yaws[idx]
        mx = self._vision_mx[idx]
        my = self._vision_my[idx]
        cam_id = self._vision_camera_ids[idx]
        out: List[VisionObservation] = []
        for det in msg.detections:
            xb, yb, rng, bearing = vision_to_body_polar(
                float(det.azimuth),
                float(det.distance_predict),
                cy,
                mx,
                my,
            )
            px_w = float(det.pixel_width)
            if px_w <= 0.0 and float(det.size_w) > 0.0 and float(det.distance_predict) > 0.0:
                px_w = profile_width_to_pixel_width(
                    float(det.distance_predict),
                    float(det.size_w),
                    self._vision_focal_px,
                )
            out.append(
                VisionObservation(
                    x=xb,
                    y=yb,
                    range_m=rng,
                    bearing_rad=bearing,
                    size_w=float(det.size_w),
                    size_h=float(det.size_h),
                    pixel_width=px_w,
                    confidence=float(det.confidence),
                    class_id=int(det.class_id),
                    class_name=str(det.class_name),
                    camera_id=cam_id,
                )
            )
        return out

    def _build_radar_observations(self, msg: MmwaveTargetArray) -> List[RadarObservation]:
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
                    objmotion_status=int(t.objmotion_status),
                    radar_track_id=int(t.track_id),
                    radar_id=str(t.radar_id),
                )
            )
        return out

    def _append_history(self, stamp_sec: float, tracks: List[TrackState]) -> None:
        """仅在本周期有滤波量测更新时追加历史点（纯预测/coast 不画线）。"""
        for st in tracks:
            if abs(st.last_seen_stamp_sec - stamp_sec) > 1e-3:
                continue
            self._append_history_point(st.track_id, stamp_sec, st.x, st.y)

    def _append_history_point(self, track_id: UUID, stamp_sec: float, x: float, y: float) -> None:
        dq = self._history.setdefault(track_id, deque(maxlen=self._max_hist))
        dq.append((stamp_sec, x, y))

    def _append_history_sample(self, stamp_sec: float, tracks: List[TrackState]) -> None:
        """固定频率采样当前滤波位置写入历史（不要求本周期有新量测）。"""
        for st in tracks:
            self._append_history_point(st.track_id, stamp_sec, st.x, st.y)

    def _update_profiles(self, stamp_sec: float, tracks: List[TrackState]) -> None:
        stamp_msg = sec_to_stamp(stamp_sec)
        for st in tracks:
            tid = st.track_id
            if tid not in self._profile_first_seen:
                self._profile_first_seen[tid] = stamp_sec
            prof = self._catalog_profiles.get(tid)
            if prof is None:
                prof = FusedTargetProfile()
                fill_ros_uuid(prof.target_id, tid)
                prof.first_seen = stamp_msg
                prof.class_id = 0
                prof.class_name = ""
                prof.class_confidence = 0.0
                prof.is_dark_target = False
                prof.is_ais_matched = False
                prof.matched_mmsi = 0
                self._catalog_profiles[tid] = prof
            prof.size_w = st.size_w
            prof.size_l = st.size_l
            prof.size_h = st.size_h
            prof.class_id = st.class_id
            prof.class_name = st.class_name
            prof.class_confidence = st.class_confidence
            prof.last_profile_update = stamp_msg

    def _track_state_to_sample(self, stamp_sec: float, st: TrackState) -> FusedTrackSample:
        s = FusedTrackSample()
        s.stamp = sec_to_stamp(stamp_sec)
        s.t_sec = stamp_sec
        s.x = st.x
        s.y = st.y
        s.v_x = st.vx
        s.v_y = st.vy
        s.covariance = st.covariance_row_major
        return s

    def _build_scene_snapshot(self, stamp_msg: Time, frame_id: str, tracks: List[TrackState]) -> FusedSceneSnapshot:
        out = FusedSceneSnapshot()
        out.header.stamp = stamp_msg
        out.header.frame_id = frame_id
        tsec = stamp_to_sec(stamp_msg)
        for st in tracks:
            snap = FusedTargetSnapshot()
            fill_ros_uuid(snap.target_id, st.track_id)
            snap.state = self._track_state_to_sample(tsec, st)
            snap.size_w = st.size_w
            snap.size_l = st.size_l
            snap.size_h = st.size_h
            prof = self._catalog_profiles.get(st.track_id)
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
        out = GlobalTrackArray()
        out.header.stamp = stamp
        out.header.frame_id = frame_id
        for st in tracks:
            gt = GlobalTrack()
            fill_ros_uuid(gt.track_id, st.track_id)
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

    def _make_line_markers(self, stamp: Time, frame_id: str) -> MarkerArray:
        """仅绘制已确认航迹的历史折线（与 snapshot 一致）。"""
        arr = MarkerArray()
        markers: List[Marker] = []
        for tid, pts in self._history.items():
            if len(pts) < 2:
                continue
            mk = Marker()
            mk.header.stamp = stamp
            mk.header.frame_id = frame_id
            mk.ns = "fusion_history"
            mk.id = uuid_to_marker_id(tid)
            mk.type = Marker.LINE_STRIP
            mk.action = Marker.ADD
            mk.scale.x = 0.15
            mk.color = uuid_to_color(tid)
            for _ps, px, py in pts:
                p = Point()
                p.x = float(px)
                p.y = float(py)
                p.z = 0.0
                mk.points.append(p)
            markers.append(mk)
        arr.markers = markers
        return arr

    def _publish_marker_clear(self, stamp: Time) -> None:
        clear = MarkerArray()
        dm = Marker()
        dm.header.stamp = stamp
        dm.header.frame_id = self._output_frame
        dm.ns = "fusion_history"
        dm.id = 0
        dm.action = Marker.DELETEALL
        clear.markers = [dm]
        self._pub_markers.publish(clear)

    def _publish_fusion_markers(self, stamp: Time, pruned_ids: List[UUID]) -> None:
        """有航迹删除时先发 DELETEALL 清 RViz 残留，再发布当前已确认轨迹。"""
        if pruned_ids:
            self._publish_marker_clear(stamp)
        self._pub_markers.publish(self._make_line_markers(stamp, self._output_frame))

    def _sync_history_to_confirmed(self, confirmed_ids: set[UUID]) -> None:
        for tid in list(self._history.keys()):
            if tid not in confirmed_ids:
                self._history.pop(tid, None)

    def _after_cycle(self, stamp_sec: float, pruned_ids: List[UUID]) -> None:
        for tid in pruned_ids:
            self._history.pop(tid, None)
            self._catalog_profiles.pop(tid, None)
            self._profile_first_seen.pop(tid, None)

        publishable = self._engine.snapshot_confirmed(stamp_sec, self._coast_timeout)
        confirmed_ids = {st.track_id for st in publishable}
        self._sync_history_to_confirmed(confirmed_ids)
        self._update_profiles(stamp_sec, publishable)

        stamp_msg = sec_to_stamp(stamp_sec)
        decoupled_tracks = self._track_publish_hz > 0.0
        if not decoupled_tracks:
            self._append_history(stamp_sec, publishable)
            marker_count = sum(1 for tid in self._history if len(self._history[tid]) >= 2)
            self._engine.set_publish_diag(len(publishable), marker_count)
        self._pub_snapshot.publish(self._build_scene_snapshot(stamp_msg, self._output_frame, publishable))
        if decoupled_tracks:
            if pruned_ids:
                self._publish_marker_clear(stamp_msg)
        else:
            self._publish_fusion_markers(stamp_msg, pruned_ids)
        if self._pub_legacy is not None:
            self._pub_legacy.publish(self._tracks_to_global_array(stamp_msg, self._output_frame, publishable))

    def _track_publish_tick(self) -> None:
        """固定频率采样滤波状态，更新 RViz 轨迹折线（融合计算仍在传感器回调中高频进行）。"""
        stamp_msg = self.get_clock().now().to_msg()
        stamp_sec = stamp_to_sec(stamp_msg)
        with self._fusion_lock:
            publishable = self._engine.snapshot_confirmed(stamp_sec, self._coast_timeout)
            confirmed_ids = {st.track_id for st in publishable}
            self._sync_history_to_confirmed(confirmed_ids)
            self._append_history_sample(stamp_sec, publishable)
            marker_count = sum(1 for tid in self._history if len(self._history[tid]) >= 2)
            self._engine.set_publish_diag(len(publishable), marker_count)
        self._pub_markers.publish(self._make_line_markers(stamp_msg, self._output_frame))

    def _on_vision(self, msg: VisionDetectionArray, topic: str) -> None:
        stamp_sec = stamp_to_sec(msg.header.stamp)
        obs = self._build_vision_observations(msg, topic)
        with self._fusion_lock:
            pruned = self._engine.run_at_time(stamp_sec, Modality.VISION, obs, [])
        self._after_cycle(stamp_sec, pruned)

    def _on_radar(self, msg: MmwaveTargetArray) -> None:
        stamp_sec = stamp_to_sec(msg.header.stamp)
        obs = self._build_radar_observations(msg)
        with self._fusion_lock:
            pruned = self._engine.run_at_time(stamp_sec, Modality.RADAR, [], obs)
        self._after_cycle(stamp_sec, pruned)

    def _association_diag_tick(self) -> None:
        with self._fusion_lock:
            win = self._engine.drain_diag_window()
            cfg = self._engine.cfg
        self._log_association_diag(win, cfg)

    def _log_association_diag(self, win: FusionDiagWindow, cfg: FusionConfig) -> None:
        log = self.get_logger().info
        log(
            "[fusion_diag] gate_params vision: chi2=%.3f width_sigma=%.2f width_w=%.2f "
            "sigma_range=%.2f sigma_bearing=%.3f conf_scale=%.2f class_min_conf=%.2f focal_px=%.0f"
            % (
                cfg.chi2_gate_vision,
                cfg.width_gate_sigma,
                cfg.association_width_weight,
                cfg.vision_sigma_range_m,
                cfg.vision_sigma_bearing_rad,
                cfg.vision_conf_scale,
                cfg.class_match_min_confidence,
                cfg.vision_focal_length_px,
            )
        )
        log(
            "[fusion_diag] gate_params radar: chi2=%.3f width_sigma=%.2f width_w=%.2f "
            "pos_std=%.2f vel_std=%.2f static_vel_inflate=%.2f"
            % (
                cfg.chi2_gate_radar,
                cfg.width_gate_sigma,
                cfg.association_width_weight,
                cfg.pos_std_radar_m,
                cfg.vel_std_radar_m_s,
                cfg.radar_static_vel_inflate,
            )
        )
        log(
            "[fusion_diag] lifecycle: promotion_min_hits=%d track_predict_stop=%.1fs "
            "coast_timeout=%.1fs max_internal=%d spawn_suppress=%.1fm "
            "merge=%s center=%.1fm kin_gate=%s"
            % (
                cfg.promotion_min_hits,
                cfg.track_predict_stop_sec,
                self._coast_timeout,
                cfg.max_internal_tracks,
                cfg.spawn_suppression_radius_m,
                cfg.enable_track_merge,
                cfg.merge_center_distance_m,
                cfg.merge_use_kin_gate,
            )
        )
        self._log_modality_assoc("vision", win.vision)
        self._log_modality_assoc("radar", win.radar)
        promoted = win.last_promoted_ids[-5:] if win.last_promoted_ids else []
        log(
            "[fusion_diag] tracks: internal=%d tentative=%d confirmed=%d | snapshot=%d markers=%d "
            "pruned=%d merged=%d promoted_ids=%s merged_pairs=%s"
            % (
                win.internal_tracks,
                win.tentative_tracks,
                win.confirmed_tracks,
                win.snapshot_count,
                win.marker_count,
                win.pruned_total,
                win.tracks_merged_total,
                promoted,
                win.last_merged_pairs[-3:] if win.last_merged_pairs else [],
            )
        )

    def _log_modality_assoc(self, label: str, stats) -> None:
        self.get_logger().info(
            "[fusion_diag] %s 1s: cb=%d meas=%d track_steps=%d | "
            "matched=%d coast=%d unmatched_meas=%d spawned=%d spawn_suppressed=%d "
            "empty_meas=%d empty_table_births=%d | gate_cells=%d pass=%d fail(chi2=%d width=%d class=%d) d2_pass=%s"
            % (
                label,
                stats.callbacks,
                stats.meas_total,
                stats.tracks_at_step,
                stats.pairs_matched,
                stats.tracks_coast,
                stats.meas_unmatched,
                stats.spawned,
                stats.spawn_suppressed,
                stats.empty_meas_skips,
                stats.empty_table_births,
                stats.gate_cells,
                stats.gate_pass,
                stats.fail_chi2,
                stats.fail_width,
                stats.fail_class,
                _fmt_d2_range(stats),
            )
        )

    def _publish_catalog_tick(self) -> None:
        msg = FusedTargetCatalog()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._output_frame
        for prof in sorted(self._catalog_profiles.values(), key=lambda p: ros_uuid_to_bytes(p.target_id)):
            msg.profiles.append(prof)
        self._pub_catalog.publish(msg)


def main(args: Optional[List[str]] = None) -> None:
    rclpy.init(args=args)
    node = EventFusionNode()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
