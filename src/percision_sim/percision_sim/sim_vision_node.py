#!/usr/bin/env python3
"""Simulated monocular vision node for surface target detection."""

from __future__ import annotations

import math
import zlib
from typing import List, Optional

import numpy as np
import rclpy
from builtin_interfaces.msg import Time as TimeMsg
from rclpy.node import Node
from rclpy.qos import QoSProfile
from visualization_msgs.msg import Marker, MarkerArray

try:
    from usv_msgs.msg import GlobalTrackArray, VisionDetection, VisionDetectionArray  # type: ignore
except ImportError:  # pragma: no cover - fallback for local package name
    from usv_interfaces.msg import GlobalTrackArray, VisionDetection, VisionDetectionArray  # type: ignore


class SimVisionNode(Node):
    """Simulates a monocular camera with configurable yaw detecting USV targets."""

    def __init__(self) -> None:
        super().__init__("sim_vision_node")
        self.declare_parameter("input_topic", "/sim/ground_truth")
        self.declare_parameter("detection_topic", "/vision/detections")
        self.declare_parameter("marker_topic", "/vision/markers")
        self.declare_parameter("frame_id", "base_link")
        self.declare_parameter("camera_id", "front")
        self.declare_parameter("camera_yaw", 0.0)
        self.declare_parameter("class_name", "ship")
        self.declare_parameter("class_id", 1)
        self.declare_parameter("fov_half_angle", math.pi / 4.0)  # 45 degrees
        self.declare_parameter("sigma_angle", 0.02)
        self.declare_parameter("distance_noise_offset", 0.05)
        self.declare_parameter("distance_noise_scale", 0.0005)
        self.declare_parameter("publish_rate_hz", 0.0)
        self.declare_parameter("detection_latency_min_sec", 0.030)
        self.declare_parameter("detection_latency_max_sec", 0.050)
        self.declare_parameter("vision_focal_length_px", 800.0)

        self._frame_id = self._get_string("frame_id")
        self._camera_id = self._get_string("camera_id")
        self._class_name = self._get_string("class_name")
        self._class_id = self._get_int("class_id")
        self._camera_yaw = self._get_float("camera_yaw")
        self._fov = self._get_float("fov_half_angle")
        self._sigma_angle = self._get_float("sigma_angle")
        self._noise_offset = self._get_float("distance_noise_offset")
        self._noise_scale = self._get_float("distance_noise_scale")
        self._input_topic = self._get_string("input_topic")
        self._detection_topic = self._get_string("detection_topic")
        self._marker_topic = self._get_string("marker_topic")
        publish_rate = self._get_float("publish_rate_hz")
        self._min_publish_period = 1.0 / publish_rate if publish_rate > 0.0 else 0.0
        self._last_publish_time: Optional[float] = None
        lo = self._get_float("detection_latency_min_sec")
        hi = self._get_float("detection_latency_max_sec")
        if hi < lo:
            lo, hi = hi, lo
        self._latency_min_sec = lo
        self._latency_max_sec = hi
        self._focal_px = max(1.0, self._get_float("vision_focal_length_px"))

        qos = QoSProfile(depth=10)
        self._detections_pub = self.create_publisher(
            VisionDetectionArray, self._detection_topic, qos
        )
        self._marker_pub = self.create_publisher(
            MarkerArray, self._marker_topic, qos
        )
        self._subscription = self.create_subscription(
            GlobalTrackArray,
            self._input_topic,
            self._on_ground_truth,
            qos,
        )
        self._rng = np.random.default_rng()
        yaw_deg = math.degrees(self._camera_yaw)
        rate_info = f"{publish_rate:.1f} Hz" if publish_rate > 0.0 else "sync"
        self.get_logger().info(
            "SimVisionNode ready (camera_id=%s, yaw=%.1f deg, rate=%s, output_latency=%.0f–%.0f ms) subscribing to %s"
            % (
                self._camera_id,
                yaw_deg,
                rate_info,
                self._latency_min_sec * 1000.0,
                self._latency_max_sec * 1000.0,
                self._subscription.topic_name,
            )
        )

    # ------------------------------------------------------------------
    # Subscription callback
    # ------------------------------------------------------------------
    def _on_ground_truth(self, msg: GlobalTrackArray) -> None:
        publish_time = self.get_clock().now()
        if self._min_publish_period > 0.0:
            now_sec = publish_time.nanoseconds * 1e-9
            if self._last_publish_time is not None and (
                now_sec - self._last_publish_time
            ) < self._min_publish_period:
                return
            self._last_publish_time = now_sec

        detections = VisionDetectionArray()
        detections.header.stamp = msg.header.stamp
        detections.header.frame_id = self._frame_id
        delay_s = float(
            self._rng.uniform(self._latency_min_sec, self._latency_max_sec)
        )
        detections.output_stamp = self._stamp_plus_seconds(
            msg.header.stamp, delay_s
        )

        markers = MarkerArray()
        marker_list: List[Marker] = []

        cos_yaw = math.cos(-self._camera_yaw)
        sin_yaw = math.sin(-self._camera_yaw)

        for track in msg.tracks:
            rel_x = track.x * cos_yaw - track.y * sin_yaw
            rel_y = track.x * sin_yaw + track.y * cos_yaw
            d = math.hypot(rel_x, rel_y)
            if d < 1e-3:
                continue
            alpha = math.atan2(rel_y, rel_x)
            if abs(alpha) > self._fov:
                continue

            sigma_d = self._noise_offset + self._noise_scale * (d ** 2)
            d_noisy = max(0.0, float(self._rng.normal(d, sigma_d)))
            alpha_noisy = float(self._rng.normal(alpha, self._sigma_angle))

            confidence = self._compute_confidence(d_noisy)
            detection = VisionDetection()
            detection.camera_id = self._camera_id
            detection.class_name = self._class_name
            detection.class_id = self._class_id
            detection.azimuth = alpha_noisy
            detection.distance_predict = d_noisy
            detection.size_w = track.size_w
            detection.size_h = track.size_h
            detection.pixel_width = (
                self._focal_px * track.size_w / d_noisy if d_noisy > 1e-3 else 0.0
            )
            detection.confidence = confidence
            detections.detections.append(detection)

            marker_list.append(
                self._make_marker(
                    int(zlib.crc32(bytes(track.track_id.uuid)) & 0x7FFFFFFF),
                    d_noisy,
                    alpha_noisy,
                    track.size_w,
                    track.size_h,
                )
            )

        if marker_list:
            markers.markers = marker_list
        else:
            delete_marker = Marker()
            delete_marker.header.frame_id = self._frame_id
            delete_marker.header.stamp = publish_time.to_msg()
            delete_marker.action = Marker.DELETEALL
            markers.markers = [delete_marker]
        self._detections_pub.publish(detections)
        self._marker_pub.publish(markers)

    # ------------------------------------------------------------------
    # Helper methods
    # ------------------------------------------------------------------
    def _stamp_plus_seconds(self, stamp, delay_sec: float) -> TimeMsg:
        """Return builtin Time = stamp + delay_sec (nanosecond-safe)."""
        total_ns = (
            int(stamp.sec) * 10**9
            + int(stamp.nanosec)
            + int(round(float(delay_sec) * 1e9))
        )
        out = TimeMsg()
        out.sec = total_ns // 10**9
        out.nanosec = total_ns % 10**9
        return out

    def _compute_confidence(self, distance: float) -> float:
        if distance <= 100.0:
            return 1.0
        if distance <= 300.0:
            return max(0.5, 1.0 - (distance - 100.0) * 0.0025)
        return 0.2

    def _make_marker(
        self,
        track_id: int,
        distance: float,
        azimuth: float,
        size_w: float,
        size_h: float,
    ) -> Marker:
        marker = Marker()
        marker.header.frame_id = self._frame_id
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "vision_detections"
        marker.id = track_id
        marker.type = Marker.CUBE
        marker.action = Marker.ADD
        marker.pose.position.x = distance * math.cos(azimuth)
        marker.pose.position.y = distance * math.sin(azimuth)
        marker.pose.position.z = max(size_h * 0.5, 0.5)
        half_yaw = 0.5 * self._camera_yaw
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = math.sin(half_yaw)
        marker.pose.orientation.w = math.cos(half_yaw)
        marker.scale.x = 0.05  # thickness (normal to the plane)
        marker.scale.y = max(size_w, 1.0)
        marker.scale.z = max(size_h, 1.0)
        marker.color.r = 0.0
        marker.color.g = 0.2
        marker.color.b = 1.0
        marker.color.a = 0.8
        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0
        return marker

    def _get_float(self, name: str) -> float:
        value = self.get_parameter(name).value
        return float(value) if value is not None else 0.0

    def _get_int(self, name: str) -> int:
        value = self.get_parameter(name).value
        return int(value) if value is not None else 0

    def _get_string(self, name: str) -> str:
        value = self.get_parameter(name).value
        return str(value) if value is not None else ""


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SimVisionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("SimVisionNode interrupted, shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
