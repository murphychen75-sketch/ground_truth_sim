#!/usr/bin/env python3
"""Ground truth generator node with RViz visualization."""

from __future__ import annotations

import math
import uuid
from typing import List, Optional

import numpy as np
import rclpy
from geometry_msgs.msg import Point
from rclpy.node import Node
from rclpy.qos import QoSProfile
from unique_identifier_msgs.msg import UUID as RosUUID
from visualization_msgs.msg import Marker, MarkerArray

from ground_truth_sim.ctrv import (
    TargetState,
    append_history,
    predict_future_path,
    propagate_target,
    sample_annulus_radius,
)

try:
    from usv_msgs.msg import GlobalTrack, GlobalTrackArray  # type: ignore
except ImportError:  # pragma: no cover - fallback for local package name
    from usv_interfaces.msg import GlobalTrack, GlobalTrackArray  # type: ignore


def _fill_ros_uuid_from_int(msg: RosUUID, value: int) -> None:
    msg.uuid = list(uuid.UUID(int=value).bytes)


class GroundTruthNode(Node):
    """ROS 2 node that simulates ground-truth targets and RViz markers."""

    def __init__(self) -> None:
        """加载参数、初始化 RNG 与目标列表，并创建发布器与定时器。"""
        super().__init__("ground_truth_node")
        self._declare_parameters()

        self._dt = self._get_float("update_dt")
        if self._dt <= 0.0:
            self.get_logger().warn("update_dt must be > 0, resetting to 0.02")
            self._dt = 0.02

        seed = self._get_int("rng_seed")
        self._rng = np.random.default_rng(seed if seed >= 0 else None)

        self._frame_id = self._get_string("frame_id")
        self._target_count = self._get_int("target_count")
        self._radius_min = self._get_float("annulus_radius_min")
        self._radius_max = self._get_float("annulus_radius_max")
        if self._radius_min >= self._radius_max:
            self.get_logger().warn("annulus_radius_min >= annulus_radius_max, fixing ordering")
            self._radius_min, self._radius_max = min(self._radius_min, self._radius_max), max(
                self._radius_min, self._radius_max
            )

        self._speed_min = self._get_float("speed_min")
        self._speed_max = self._get_float("speed_max")
        if self._speed_min >= self._speed_max:
            self.get_logger().warn("speed_min >= speed_max, fixing ordering")
            self._speed_min, self._speed_max = min(self._speed_min, self._speed_max), max(
                self._speed_min, self._speed_max
            )

        self._size_w_min = self._get_float("size_width_min")
        self._size_w_max = self._get_float("size_width_max")
        self._size_l_min = self._get_float("size_length_min")
        self._size_l_max = self._get_float("size_length_max")
        self._size_h_min = self._get_float("size_height_min")
        self._size_h_max = self._get_float("size_height_max")

        self._ais_match_probability = self._get_float("ais_match_probability")
        self._omega_noise_std = self._get_float("omega_noise_std")
        self._omega_decay = self._get_float("omega_decay")
        self._omega_limit = self._get_float("omega_limit")

        self._prediction_horizon = self._get_float("prediction_horizon")
        self._prediction_dt = self._get_float("prediction_dt")
        self._history_max_points = self._get_int("history_max_points")
        if self._history_max_points < 1:
            self._history_max_points = 1

        self._targets: List[TargetState] = self._initialize_targets(count=self._target_count)
        self._next_track_id = self._target_count + 1

        qos = QoSProfile(depth=10)
        self._track_pub = self.create_publisher(GlobalTrackArray, "/sim/ground_truth", qos)
        self._marker_pub = self.create_publisher(MarkerArray, "/sim/ground_truth_markers", qos)
        self.create_timer(self._dt, self._timer_callback)
        self.get_logger().info(
            "GroundTruthNode initialized with %d targets" % len(self._targets)
        )

    # ---------------------------------------------------------------------
    # Target initialization
    # ---------------------------------------------------------------------
    def _declare_parameters(self) -> None:
        """声明本节点使用的全部 ROS 2 参数及其默认值。"""
        self.declare_parameter("update_dt", 0.02)
        self.declare_parameter("frame_id", "base_link")
        self.declare_parameter("target_count", 5)
        self.declare_parameter("annulus_radius_min", 50.0)
        self.declare_parameter("annulus_radius_max", 500.0)
        self.declare_parameter("speed_min", 2.0)
        self.declare_parameter("speed_max", 12.0)
        self.declare_parameter("size_width_min", 2.0)
        self.declare_parameter("size_width_max", 10.0)
        self.declare_parameter("size_length_min", 5.0)
        self.declare_parameter("size_length_max", 50.0)
        self.declare_parameter("size_height_min", 2.0)
        self.declare_parameter("size_height_max", 15.0)
        self.declare_parameter("ais_match_probability", 0.4)
        self.declare_parameter("omega_noise_std", 0.005)
        self.declare_parameter("omega_decay", 0.99)
        self.declare_parameter("omega_limit", 0.1)
        self.declare_parameter("prediction_horizon", 5.0)
        self.declare_parameter("prediction_dt", 0.25)
        self.declare_parameter("history_max_points", 500)
        self.declare_parameter("rng_seed", -1)

    def _get_float(self, name: str) -> float:
        """读取参数并转为 float；缺失时为 0.0。"""
        value = self.get_parameter(name).value
        return float(value) if value is not None else 0.0

    def _get_int(self, name: str) -> int:
        """读取参数并转为 int；缺失时为 0。"""
        value = self.get_parameter(name).value
        return int(value) if value is not None else 0

    def _get_string(self, name: str) -> str:
        """读取参数并转为 str；缺失时为空字符串。"""
        value = self.get_parameter(name).value
        return str(value) if value is not None else ""

    # ---------------------------------------------------------------------
    # Target initialization
    # ---------------------------------------------------------------------
    def _initialize_targets(self, count: int) -> List[TargetState]:
        """生成 count 个目标，track_id 从 1 连续编号到 count。"""
        return [self._create_target(track_id) for track_id in range(1, count + 1)]

    def _create_target(self, track_id: int) -> TargetState:
        """在环形区域内随机采样位置与运动、尺寸、AIS 属性，并写入首帧历史点。"""
        radius = sample_annulus_radius(self._rng, self._radius_min, self._radius_max)
        bearing = self._rng.uniform(-math.pi, math.pi)
        x = radius * math.cos(bearing)
        y = radius * math.sin(bearing)
        speed = self._rng.uniform(self._speed_min, self._speed_max)
        theta = self._rng.uniform(-math.pi, math.pi)
        omega = 0.0
        size_w = self._rng.uniform(self._size_w_min, self._size_w_max)
        size_l = self._rng.uniform(self._size_l_min, self._size_l_max)
        size_h = self._rng.uniform(self._size_h_min, self._size_h_max)
        is_ais_matched = bool(self._rng.random() < self._ais_match_probability)
        matched_mmsi = (
            int(self._rng.integers(100_000_000, 999_999_999)) if is_ais_matched else 0
        )
        target = TargetState(
            track_id=track_id,
            x=x,
            y=y,
            speed=speed,
            theta=theta,
            omega=omega,
            size_w=size_w,
            size_l=size_l,
            size_h=size_h,
            is_dark_target=not is_ais_matched,
            is_ais_matched=is_ais_matched,
            matched_mmsi=matched_mmsi,
        )
        target.history.append(Point(x=float(x), y=float(y), z=0.0))
        return target

    # ---------------------------------------------------------------------
    # Timer callback
    # ---------------------------------------------------------------------
    def _timer_callback(self) -> None:
        """按 CTRV 推进各目标；越出外圆则换新 track_id 重生并发 RViz DELETE；否则累积轨迹历史。随后发布航迹与标记。"""
        removed_track_ids: List[int] = []
        for i, target in enumerate(self._targets):
            propagate_target(
                target,
                self._dt,
                self._omega_noise_std,
                self._omega_decay,
                self._omega_limit,
                self._rng,
            )
            if math.hypot(target.x, target.y) > self._radius_max:
                removed_track_ids.append(target.track_id)
                new_id = self._next_track_id
                self._next_track_id += 1
                self._targets[i] = self._create_target(new_id)
            else:
                append_history(target, self._history_max_points)

        array_msg = self._build_track_array()
        self._track_pub.publish(array_msg)
        self._publish_markers(array_msg, removed_track_ids)

    def _build_track_array(self) -> GlobalTrackArray:
        """将当前内存中的目标列表封装为带当前时间与 frame_id 的 GlobalTrackArray。"""
        msg = GlobalTrackArray()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._frame_id

        for target in self._targets:
            track = GlobalTrack()
            _fill_ros_uuid_from_int(track.track_id, target.track_id)
            track.x = target.x
            track.y = target.y
            track.v_x = target.v_x
            track.v_y = target.v_y
            track.size_w = target.size_w
            track.size_l = target.size_l
            track.size_h = target.size_h
            track.covariance = [0.0] * 16
            track.is_dark_target = target.is_dark_target
            track.is_ais_matched = target.is_ais_matched
            track.matched_mmsi = target.matched_mmsi
            track.source_model_name = ""
            msg.tracks.append(track)
        return msg

    # ---------------------------------------------------------------------
    # RViz markers
    # ---------------------------------------------------------------------
    def _publish_markers(
        self,
        track_array: GlobalTrackArray,
        removed_track_ids: Optional[List[int]] = None,
    ) -> None:
        """发布 RViz 标记。

        有目标重生时：先单独发布各命名空间的 DELETEALL（RViz2 对同一条消息内混排 DELETE 支持不稳定），
        再发布当前所有目标的 ADD。无重生时仅发布 ADD，与上一周期同 id 的标记会被覆盖更新。
        """
        stamp = track_array.header.stamp
        if removed_track_ids:
            clear = MarkerArray()
            clear.markers = self._make_deleteall_markers_for_namespaces(stamp)
            self._marker_pub.publish(clear)

        markers = MarkerArray()
        marker_list: List[Marker] = []
        for target in self._targets:
            marker_list.append(self._make_position_marker(target, stamp))
            marker_list.append(self._make_path_marker(target, stamp))
            marker_list.append(self._make_history_marker(target, stamp))
        markers.markers = marker_list
        self._marker_pub.publish(markers)

    def _make_deleteall_markers_for_namespaces(self, stamp) -> List[Marker]:
        """对位姿 / 预测路径 / 历史三个命名空间各发一条 DELETEALL，清空该话题下对应 ns 的全部旧标记。"""
        out: List[Marker] = []
        for ns in ("target_pose", "target_path", "target_history"):
            m = Marker()
            m.header.frame_id = self._frame_id
            m.header.stamp = stamp
            m.ns = ns
            m.id = 0
            m.action = Marker.DELETEALL
            out.append(m)
        return out

    def _make_position_marker(self, target: TargetState, stamp) -> Marker:
        """目标当前位置的球体标记；AIS 匹配与否用颜色区分。"""
        marker = Marker()
        marker.header.frame_id = self._frame_id
        marker.header.stamp = stamp
        marker.ns = "target_pose"
        marker.id = target.track_id
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.pose.position.x = target.x
        marker.pose.position.y = target.y
        marker.pose.position.z = target.size_h * 0.5
        marker.pose.orientation.w = 1.0
        marker.scale.x = max(target.size_l, 2.0)
        marker.scale.y = max(target.size_w, 2.0)
        marker.scale.z = max(target.size_h, 1.5)
        if target.is_ais_matched:
            marker.color.r = 0.1
            marker.color.g = 0.8
            marker.color.b = 0.2
        else:
            marker.color.r = 1.0
            marker.color.g = 0.5
            marker.color.b = 0.0
        marker.color.a = 0.9
        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0
        return marker

    def _make_path_marker(self, target: TargetState, stamp) -> Marker:
        """按当前 CTRV 状态预测的短时未来轨迹（LINE_STRIP）。"""
        marker = Marker()
        marker.header.frame_id = self._frame_id
        marker.header.stamp = stamp
        marker.ns = "target_path"
        marker.id = target.track_id + 1000
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD
        marker.scale.x = 0.8
        marker.color.a = 0.85
        marker.color.r = 0.2
        marker.color.g = 0.6
        marker.color.b = 1.0 if target.is_ais_matched else 0.2
        marker.points = predict_future_path(
            target, self._prediction_horizon, self._prediction_dt
        )
        return marker

    def _make_history_marker(self, target: TargetState, stamp) -> Marker:
        """目标已走过的平面轨迹历史（LINE_STRIP）。"""
        marker = Marker()
        marker.header.frame_id = self._frame_id
        marker.header.stamp = stamp
        marker.ns = "target_history"
        marker.id = target.track_id + 2000
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD
        marker.scale.x = 0.4
        marker.color.a = 0.9
        marker.color.r = 0.7
        marker.color.g = 0.7
        marker.color.b = 0.7
        marker.points = list(target.history)
        return marker


def main(args=None) -> None:
    """节点入口：初始化 rclpy、创建节点并 spin，退出时销毁节点并 shutdown。"""
    rclpy.init(args=args)
    node = GroundTruthNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("GroundTruthNode interrupted, shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
