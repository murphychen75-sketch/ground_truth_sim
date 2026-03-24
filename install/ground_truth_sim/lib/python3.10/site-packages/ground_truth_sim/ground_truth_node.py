#!/usr/bin/env python3
"""Ground truth generator node with RViz visualization."""

from __future__ import annotations

import math
from dataclasses import dataclass, field
from typing import List

import numpy as np
import rclpy
from geometry_msgs.msg import Point
from rclpy.node import Node
from rclpy.qos import QoSProfile
from visualization_msgs.msg import Marker, MarkerArray

try:
    from usv_msgs.msg import GlobalTrack, GlobalTrackArray  # type: ignore
except ImportError:  # pragma: no cover - fallback for local package name
    from usv_interfaces.msg import GlobalTrack, GlobalTrackArray  # type: ignore


@dataclass
class TargetState:
    track_id: int
    x: float
    y: float
    speed: float
    theta: float
    omega: float
    size_w: float
    size_l: float
    size_h: float
    is_dark_target: bool
    is_ais_matched: bool
    matched_mmsi: int
    history: List[Point] = field(default_factory=list)

    @property
    def v_x(self) -> float:
        return self.speed * math.cos(self.theta)

    @property
    def v_y(self) -> float:
        return self.speed * math.sin(self.theta)


class GroundTruthNode(Node):
    """ROS 2 node that simulates ground-truth targets and RViz markers."""

    def __init__(self) -> None:
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
        value = self.get_parameter(name).value
        return float(value) if value is not None else 0.0

    def _get_int(self, name: str) -> int:
        value = self.get_parameter(name).value
        return int(value) if value is not None else 0

    def _get_string(self, name: str) -> str:
        value = self.get_parameter(name).value
        return str(value) if value is not None else ""

    # ---------------------------------------------------------------------
    # Target initialization
    # ---------------------------------------------------------------------
    def _initialize_targets(self, count: int) -> List[TargetState]:
        targets: List[TargetState] = []
        for track_id in range(1, count + 1):
            radius = self._sample_annulus_radius(self._radius_min, self._radius_max)
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
            targets.append(target)
        return targets

    def _sample_annulus_radius(self, r_min: float, r_max: float) -> float:
        u = self._rng.random()
        return math.sqrt((r_max**2 - r_min**2) * u + r_min**2)

    # ---------------------------------------------------------------------
    # Timer callback
    # ---------------------------------------------------------------------
    def _timer_callback(self) -> None:
        for target in self._targets:
            self._propagate_target(target)

        array_msg = self._build_track_array()
        self._track_pub.publish(array_msg)
        self._publish_markers(array_msg)

    def _propagate_target(self, target: TargetState) -> None:
        omega_noise = self._rng.normal(0.0, self._omega_noise_std)
        omega = (target.omega + omega_noise) * self._omega_decay
        omega = float(np.clip(omega, -self._omega_limit, self._omega_limit))
        target.omega = omega

        if abs(omega) < 1e-3:
            dx = target.speed * math.cos(target.theta) * self._dt
            dy = target.speed * math.sin(target.theta) * self._dt
        else:
            theta = target.theta
            dx = (target.speed / omega) * (
                math.sin(theta + omega * self._dt) - math.sin(theta)
            )
            dy = (target.speed / omega) * (
                -math.cos(theta + omega * self._dt) + math.cos(theta)
            )
        target.x += dx
        target.y += dy
        target.theta = self._wrap_angle(target.theta + omega * self._dt)
        self._update_history(target)

    def _update_history(self, target: TargetState) -> None:
        target.history.append(Point(x=float(target.x), y=float(target.y), z=0.0))
        if len(target.history) > self._history_max_points:
            del target.history[0 : len(target.history) - self._history_max_points]

    def _build_track_array(self) -> GlobalTrackArray:
        msg = GlobalTrackArray()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._frame_id

        for target in self._targets:
            track = GlobalTrack()
            track.track_id = target.track_id
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
            msg.tracks.append(track)
        return msg

    # ---------------------------------------------------------------------
    # RViz markers
    # ---------------------------------------------------------------------
    def _publish_markers(self, track_array: GlobalTrackArray) -> None:
        markers = MarkerArray()
        stamp = track_array.header.stamp
        marker_list: List[Marker] = []
        for target in self._targets:
            marker_list.append(self._make_position_marker(target, stamp))
            marker_list.append(self._make_path_marker(target, stamp))
            marker_list.append(self._make_history_marker(target, stamp))
        markers.markers = marker_list
        self._marker_pub.publish(markers)

    def _make_position_marker(self, target: TargetState, stamp) -> Marker:
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
        marker.points = self._predict_future_path(target)
        return marker

    def _make_history_marker(self, target: TargetState, stamp) -> Marker:
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

    def _predict_future_path(self, target: TargetState) -> List[Point]:
        points: List[Point] = []
        x, y, theta = target.x, target.y, target.theta
        omega = target.omega
        steps = int(self._prediction_horizon / self._prediction_dt)
        for _ in range(steps):
            x, y, theta = self._ctrv_step(x, y, target.speed, theta, omega, self._prediction_dt)
            points.append(Point(x=float(x), y=float(y), z=0.0))
        return points

    @staticmethod
    def _ctrv_step(
        x: float,
        y: float,
        speed: float,
        theta: float,
        omega: float,
        dt: float,
    ) -> tuple[float, float, float]:
        if abs(omega) < 1e-3:
            x_next = x + speed * math.cos(theta) * dt
            y_next = y + speed * math.sin(theta) * dt
            theta_next = theta
        else:
            x_next = x + (speed / omega) * (math.sin(theta + omega * dt) - math.sin(theta))
            y_next = y + (speed / omega) * (-math.cos(theta + omega * dt) + math.cos(theta))
            theta_next = theta + omega * dt
        return x_next, y_next, GroundTruthNode._wrap_angle(theta_next)

    @staticmethod
    def _wrap_angle(angle: float) -> float:
        wrapped = math.fmod(angle + math.pi, 2.0 * math.pi)
        if wrapped < 0.0:
            wrapped += 2.0 * math.pi
        return wrapped - math.pi


def main(args=None) -> None:
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
