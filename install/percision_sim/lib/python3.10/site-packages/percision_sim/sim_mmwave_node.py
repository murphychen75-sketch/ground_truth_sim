#!/usr/bin/env python3
"""ROS 2 node that simulates 4D mmWave radar observations."""

from __future__ import annotations

import math
from typing import List, Optional

import numpy as np
import rclpy
from geometry_msgs.msg import Point
from rclpy.node import Node
from rclpy.qos import QoSProfile
from visualization_msgs.msg import Marker, MarkerArray

try:  # pragma: no cover - workspace alias support
    from usv_msgs.msg import GlobalTrackArray, MmwaveTarget, MmwaveTargetArray  # type: ignore
except ImportError:  # pragma: no cover
    from usv_interfaces.msg import GlobalTrackArray, MmwaveTarget, MmwaveTargetArray  # type: ignore


class SimMmwaveNode(Node):
    """Simulates mmWave radar traits: precise range/Doppler, noisy bearings, jittery extents."""

    def __init__(self) -> None:
        super().__init__("sim_mmwave_node")
        self.declare_parameter("input_topic", "/sim/ground_truth")
        self.declare_parameter("target_topic", "/mmwave/targets")
        self.declare_parameter("marker_topic", "/mmwave/markers")
        self.declare_parameter("frame_id", "base_link")
        self.declare_parameter("radar_id", "mmwave_front")
        self.declare_parameter("radar_yaw", 0.0)
        self.declare_parameter("fov_half_angle", math.pi / 3.0)  # 120deg total FoV
        self.declare_parameter("radial_noise_std", 0.5)
        self.declare_parameter("angle_noise_std", 0.08)
        self.declare_parameter("velocity_noise_std", 0.1)
        self.declare_parameter("size_jitter", 0.2)
        self.declare_parameter("snr_min", 10.0)
        self.declare_parameter("snr_max", 30.0)
        self.declare_parameter("cylinder_height", 1.0)
        self.declare_parameter("publish_rate_hz", 0.0)

        self._input_topic = self._get_string("input_topic")
        self._target_topic = self._get_string("target_topic")
        self._marker_topic = self._get_string("marker_topic")
        self._frame_id_default = self._get_string("frame_id")
        self._radar_id = self._get_string("radar_id")
        self._radar_yaw = self._get_float("radar_yaw")
        self._fov_half_angle = max(0.0, self._get_float("fov_half_angle"))
        self._radial_std = max(0.0, self._get_float("radial_noise_std"))
        self._angle_std = max(0.0, self._get_float("angle_noise_std"))
        self._velocity_std = max(0.0, self._get_float("velocity_noise_std"))
        self._size_jitter = max(0.0, self._get_float("size_jitter"))
        self._snr_min = self._get_float("snr_min")
        self._snr_max = max(self._snr_min, self._get_float("snr_max"))
        self._cylinder_height = max(0.1, self._get_float("cylinder_height"))
        publish_rate = self._get_float("publish_rate_hz")
        self._min_publish_period = 1.0 / publish_rate if publish_rate > 0.0 else 0.0
        self._last_publish_time: Optional[float] = None

        qos = QoSProfile(depth=10)
        self._sub = self.create_subscription(
            GlobalTrackArray, self._input_topic, self._on_ground_truth, qos
        )
        self._target_pub = self.create_publisher(MmwaveTargetArray, self._target_topic, qos)
        self._marker_pub = self.create_publisher(MarkerArray, self._marker_topic, qos)

        self._rng = np.random.default_rng()
        yaw_deg = math.degrees(self._radar_yaw)
        total_fov_deg = math.degrees(self._fov_half_angle * 2.0)
        rate_info = f"{publish_rate:.1f} Hz" if publish_rate > 0.0 else "sync"
        self.get_logger().info(
            "SimMmwaveNode ready (radar_id=%s, yaw=%.1f°, FoV≈%.1f°, rate=%s, radial_std=%.2f m, angle_std=%.2f rad)"
            % (self._radar_id, yaw_deg, total_fov_deg, rate_info, self._radial_std, self._angle_std)
        )

    # ------------------------------------------------------------------
    # Subscription callback
    # ------------------------------------------------------------------
    def _on_ground_truth(self, msg: GlobalTrackArray) -> None:
        if self._min_publish_period > 0.0:
            now_sec = self.get_clock().now().nanoseconds * 1e-9
            if self._last_publish_time is not None and (
                now_sec - self._last_publish_time
            ) < self._min_publish_period:
                return
            self._last_publish_time = now_sec

        frame_id = msg.header.frame_id or self._frame_id_default
        targets = MmwaveTargetArray()
        targets.header.stamp = msg.header.stamp
        targets.header.frame_id = frame_id

        markers = MarkerArray()
        marker_list: List[Marker] = []

        cos_yaw = math.cos(-self._radar_yaw)
        sin_yaw = math.sin(-self._radar_yaw)

        for idx, track in enumerate(msg.tracks):
            rel_x = track.x * cos_yaw - track.y * sin_yaw
            rel_y = track.x * sin_yaw + track.y * cos_yaw
            distance = math.hypot(rel_x, rel_y)
            if distance < 1e-3:
                continue
            bearing = math.atan2(rel_y, rel_x)
            if self._fov_half_angle > 0.0 and abs(bearing) > self._fov_half_angle:
                continue

            noisy_x, noisy_y = self._apply_polar_noise(track.x, track.y)
            noisy_vx = self._apply_velocity_noise(track.v_x)
            noisy_vy = self._apply_velocity_noise(track.v_y)
            jittered_w = self._apply_size_jitter(track.size_w)
            jittered_l = self._apply_size_jitter(track.size_l)
            snr = self._rng.uniform(self._snr_min, self._snr_max)

            target = MmwaveTarget()
            target.radar_id = self._radar_id
            target.x = noisy_x
            target.y = noisy_y
            target.v_x = noisy_vx
            target.v_y = noisy_vy
            target.size_w = jittered_w
            target.size_l = jittered_l
            target.size_h = track.size_h
            target.snr = snr
            targets.targets.append(target)

            marker_list.extend(
                self._make_markers(
                    base_id=idx,
                    frame_id=frame_id,
                    stamp=msg.header.stamp,
                    x=noisy_x,
                    y=noisy_y,
                    vx=noisy_vx,
                    vy=noisy_vy,
                    diameter=max(max(jittered_w, jittered_l), 0.5),
                )
            )

        if marker_list:
            markers.markers = marker_list
        else:
            delete_marker = Marker()
            delete_marker.header.frame_id = frame_id
            delete_marker.header.stamp = msg.header.stamp
            delete_marker.action = Marker.DELETEALL
            markers.markers = [delete_marker]

        self._target_pub.publish(targets)
        self._marker_pub.publish(markers)

    # ------------------------------------------------------------------
    # Helper methods
    # ------------------------------------------------------------------
    def _apply_polar_noise(self, x: float, y: float) -> tuple[float, float]:
        r = math.hypot(x, y)
        theta = math.atan2(y, x)
        if self._radial_std > 0.0:
            r = float(self._rng.normal(r, self._radial_std))
        if self._angle_std > 0.0:
            theta = float(self._rng.normal(theta, self._angle_std))
        return r * math.cos(theta), r * math.sin(theta)

    def _apply_velocity_noise(self, value: float) -> float:
        if self._velocity_std <= 0.0:
            return value
        return float(self._rng.normal(value, self._velocity_std))

    def _apply_size_jitter(self, base: float) -> float:
        if base <= 0.0:
            return 0.0
        if self._size_jitter <= 0.0:
            return base
        factor = self._rng.uniform(1.0 - self._size_jitter, 1.0 + self._size_jitter)
        return max(0.0, base * float(factor))

    def _make_markers(
        self,
        base_id: int,
        frame_id: str,
        stamp,
        x: float,
        y: float,
        vx: float,
        vy: float,
        diameter: float,
    ) -> List[Marker]:
        cylinder = Marker()
        cylinder.header.frame_id = frame_id
        cylinder.header.stamp = stamp
        cylinder.ns = "mmwave_targets"
        cylinder.id = base_id
        cylinder.type = Marker.CYLINDER
        cylinder.action = Marker.ADD
        cylinder.pose.position.x = x
        cylinder.pose.position.y = y
        cylinder.pose.position.z = self._cylinder_height * 0.5
        cylinder.pose.orientation.w = 1.0
        cylinder.scale.x = max(diameter, 0.5)
        cylinder.scale.y = max(diameter, 0.5)
        cylinder.scale.z = self._cylinder_height
        cylinder.color.r = 0.0
        cylinder.color.g = 1.0
        cylinder.color.b = 0.0
        cylinder.color.a = 0.8
        cylinder.lifetime.sec = 0
        cylinder.lifetime.nanosec = 0

        arrow = Marker()
        arrow.header.frame_id = frame_id
        arrow.header.stamp = stamp
        arrow.ns = "mmwave_velocity"
        arrow.id = base_id + 10000
        arrow.type = Marker.ARROW
        arrow.action = Marker.ADD
        start = Point(x=x, y=y, z=self._cylinder_height)
        end = Point(x=x + vx, y=y + vy, z=self._cylinder_height)
        arrow.points = [start, end]
        arrow.scale.x = 0.2  # shaft diameter
        arrow.scale.y = 0.4  # head diameter
        arrow.scale.z = 0.4  # head length
        arrow.color.r = 0.0
        arrow.color.g = 1.0
        arrow.color.b = 0.0
        arrow.color.a = 0.8
        arrow.lifetime.sec = 0
        arrow.lifetime.nanosec = 0

        return [cylinder, arrow]

    def _get_string(self, name: str) -> str:
        value = self.get_parameter(name).value
        return str(value) if value is not None else ""

    def _get_float(self, name: str) -> float:
        value = self.get_parameter(name).value
        return float(value) if value is not None else 0.0


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SimMmwaveNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("SimMmwaveNode interrupted, shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
