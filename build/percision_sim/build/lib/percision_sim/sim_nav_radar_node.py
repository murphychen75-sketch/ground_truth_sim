#!/usr/bin/env python3
"""ROS 2 node that simulates a navigation radar with low-frequency wide-area scans."""

from __future__ import annotations

import math
from typing import List

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from visualization_msgs.msg import Marker, MarkerArray

try:  # pragma: no cover - allow workspace alias
    from usv_msgs.msg import GlobalTrackArray, NavRadarTarget, NavRadarTargetArray  # type: ignore
except ImportError:  # pragma: no cover
    from usv_interfaces.msg import GlobalTrackArray, NavRadarTarget, NavRadarTargetArray  # type: ignore


class SimNavRadarNode(Node):
    """Simulate a slow 1 Hz navigation radar that scans wide areas with coarse resolution."""

    def __init__(self) -> None:
        super().__init__("sim_nav_radar_node")
        self.declare_parameter("input_topic", "/sim/ground_truth")
        self.declare_parameter("target_topic", "/nav_radar/targets")
        self.declare_parameter("marker_topic", "/nav_radar/markers")
        self.declare_parameter("frame_id", "base_link")
        self.declare_parameter("min_period", 1.0)
        self.declare_parameter("noise_std", 5.0)
        self.declare_parameter("area_jitter", 0.1)
        self.declare_parameter("marker_height", 0.1)

        self._input_topic = self._get_string("input_topic")
        self._target_topic = self._get_string("target_topic")
        self._marker_topic = self._get_string("marker_topic")
        self._frame_id_default = self._get_string("frame_id")
        self._min_period = max(0.1, self._get_float("min_period"))
        self._noise_std = max(0.0, self._get_float("noise_std"))
        self._area_jitter = max(0.0, self._get_float("area_jitter"))
        self._marker_height = max(0.01, self._get_float("marker_height"))

        qos = QoSProfile(depth=10)
        self._sub = self.create_subscription(
            GlobalTrackArray, self._input_topic, self._on_ground_truth, qos
        )
        self._target_pub = self.create_publisher(NavRadarTargetArray, self._target_topic, qos)
        self._marker_pub = self.create_publisher(MarkerArray, self._marker_topic, qos)

        self._last_publish_time = None
        self._min_period_ns = int(self._min_period * 1e9)
        self._rng = np.random.default_rng()
        self.get_logger().info(
            "SimNavRadarNode ready (min_period=%.2fs, noise_std=%.1f m)" % (self._min_period, self._noise_std)
        )

    # ------------------------------------------------------------------
    # Subscription callback
    # ------------------------------------------------------------------
    def _on_ground_truth(self, msg: GlobalTrackArray) -> None:
        now = self.get_clock().now()
        if self._last_publish_time is not None:
            elapsed_ns = (now - self._last_publish_time).nanoseconds
            if elapsed_ns < self._min_period_ns:
                return
        self._last_publish_time = now
        self._publish_snapshot(msg)

    # ------------------------------------------------------------------
    # Publishing helpers
    # ------------------------------------------------------------------
    def _publish_snapshot(self, msg: GlobalTrackArray) -> None:
        frame_id = msg.header.frame_id or self._frame_id_default
        array_msg = NavRadarTargetArray()
        array_msg.header.stamp = msg.header.stamp
        array_msg.header.frame_id = frame_id

        markers = MarkerArray()
        marker_list: List[Marker] = []

        for idx, track in enumerate(msg.tracks):
            noisy_x, noisy_y = self._apply_position_noise(track.x, track.y)
            jittered_area = self._apply_area_jitter(track.size_w * track.size_l)

            target = NavRadarTarget()
            target.x = noisy_x
            target.y = noisy_y
            target.v_x = track.v_x
            target.v_y = track.v_y
            target.area = jittered_area
            array_msg.targets.append(target)

            marker_list.append(
                self._make_marker(
                    marker_id=idx,
                    frame_id=frame_id,
                    stamp=msg.header.stamp,
                    x=noisy_x,
                    y=noisy_y,
                    width=max(track.size_l, 1.0),
                    length=max(track.size_w, 1.0),
                )
            )

        if not array_msg.targets:
            return

        markers.markers = marker_list
        self._target_pub.publish(array_msg)
        self._marker_pub.publish(markers)

    def _apply_position_noise(self, x: float, y: float) -> tuple[float, float]:
        if self._noise_std <= 0.0:
            return x, y
        noise = self._rng.normal(0.0, self._noise_std, size=2)
        return float(x + noise[0]), float(y + noise[1])

    def _apply_area_jitter(self, base_area: float) -> float:
        if base_area <= 0.0:
            return 0.0
        if self._area_jitter <= 0.0:
            return base_area
        factor = 1.0 + float(self._rng.uniform(-self._area_jitter, self._area_jitter))
        return max(0.0, base_area * factor)

    def _make_marker(
        self,
        marker_id: int,
        frame_id: str,
        stamp,
        x: float,
        y: float,
        width: float,
        length: float,
    ) -> Marker:
        marker = Marker()
        marker.header.frame_id = frame_id
        marker.header.stamp = stamp
        marker.ns = "nav_radar_targets"
        marker.id = marker_id
        marker.type = Marker.CUBE
        marker.action = Marker.ADD
        marker.pose.position.x = x
        marker.pose.position.y = y
        marker.pose.position.z = self._marker_height * 0.5
        marker.pose.orientation.w = 1.0
        marker.scale.x = max(length, 0.5)
        marker.scale.y = max(width, 0.5)
        marker.scale.z = self._marker_height
        marker.color.r = 1.0
        marker.color.g = 1.0
        marker.color.b = 0.0
        marker.color.a = 0.6
        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0
        return marker

    # ------------------------------------------------------------------
    # Parameter helpers
    # ------------------------------------------------------------------
    def _get_string(self, name: str) -> str:
        value = self.get_parameter(name).value
        return str(value) if value is not None else ""

    def _get_float(self, name: str) -> float:
        value = self.get_parameter(name).value
        return float(value) if value is not None else 0.0


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SimNavRadarNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("SimNavRadarNode interrupted, shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
