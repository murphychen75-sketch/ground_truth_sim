#!/usr/bin/env python3
"""Publish static range overlays (annulus + sensor sector rings) as MarkerArray for RViz."""

from __future__ import annotations

import math
from typing import List, Sequence, Tuple

import rclpy
from geometry_msgs.msg import Point
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray


def _circle_strip(radius: float, n_seg: int, z: float) -> List[Point]:
    pts: List[Point] = []
    for i in range(n_seg + 1):
        t = 2.0 * math.pi * float(i) / float(n_seg)
        pts.append(Point(x=radius * math.cos(t), y=radius * math.sin(t), z=z))
    return pts


def _sector_annulus_strip(
    center_yaw: float,
    half_fov: float,
    r_in: float,
    r_out: float,
    arc_steps: int,
    z: float,
) -> List[Point]:
    """Closed loop: inner arc, radial out, outer arc back, radial in."""
    a0 = center_yaw - half_fov
    a1 = center_yaw + half_fov
    pts: List[Point] = []
    for i in range(arc_steps):
        t = a0 + (a1 - a0) * float(i) / float(arc_steps - 1)
        pts.append(Point(x=r_in * math.cos(t), y=r_in * math.sin(t), z=z))
    for i in range(1, arc_steps):
        t = a1 + (a0 - a1) * float(i) / float(arc_steps - 1)
        pts.append(Point(x=r_out * math.cos(t), y=r_out * math.sin(t), z=z))
    if pts:
        pts.append(pts[0])
    return pts


def _line_marker(
    ns: str,
    mid: int,
    frame_id: str,
    stamp,
    points: List[Point],
    color: ColorRGBA,
    line_width: float,
) -> Marker:
    m = Marker()
    m.header.frame_id = frame_id
    m.header.stamp = stamp
    m.ns = ns
    m.id = mid
    m.type = Marker.LINE_STRIP
    m.action = Marker.ADD
    m.scale.x = line_width
    m.color = color
    m.points = points
    m.pose.orientation.w = 1.0
    m.lifetime.sec = 0
    m.lifetime.nanosec = 0
    return m


class RangeOverlayNode(Node):
    """Publishes GT annulus circles and vision/mmwave FoV sector rings (LINE_STRIP)."""

    def __init__(self) -> None:
        super().__init__("range_overlay_node")
        self.declare_parameter("marker_topic", "/sim/range_overlay_markers")
        self.declare_parameter("publish_hz", 1.0)
        self.declare_parameter("frame_id", "base_link")
        self.declare_parameter("z_height", 0.08)
        self.declare_parameter("line_width", 0.25)
        self.declare_parameter("circle_segments", 96)
        self.declare_parameter("sector_arc_segments", 48)

        self.declare_parameter("show_gt_annulus", True)
        self.declare_parameter("gt_annulus_radius_min", 50.0)
        self.declare_parameter("gt_annulus_radius_max", 200.0)

        self.declare_parameter("show_vision_sector", True)
        # Legacy single-sector params (used when vision_yaws array is empty).
        self.declare_parameter("vision_yaw", 0.0)
        self.declare_parameter("vision_fov_half_angle", math.pi / 4.0)
        self.declare_parameter("vision_yaws", [0.0])
        self.declare_parameter("vision_fov_half_angles", [math.pi / 4.0])
        self.declare_parameter("vision_range_min", 1.0)
        self.declare_parameter("vision_range_max", 250.0)

        self.declare_parameter("show_mmwave_sector", True)
        self.declare_parameter("mmwave_yaw", 0.0)
        self.declare_parameter("mmwave_fov_half_angle", math.pi / 3.0)
        self.declare_parameter("mmwave_yaws", [0.0])
        self.declare_parameter("mmwave_fov_half_angles", [math.pi / 3.0])
        self.declare_parameter("mmwave_range_min", 1.0)
        self.declare_parameter("mmwave_range_max", 250.0)

        self._topic = self.get_parameter("marker_topic").get_parameter_value().string_value
        self._frame = self.get_parameter("frame_id").get_parameter_value().string_value
        hz = float(self.get_parameter("publish_hz").get_parameter_value().double_value)
        if hz <= 0.0:
            hz = 1.0

        qos = QoSProfile(depth=1)
        self._pub = self.create_publisher(MarkerArray, self._topic, qos)
        period = 1.0 / hz
        self._timer = self.create_timer(period, self._on_timer)

        self.get_logger().info(
            "RangeOverlayNode publishing MarkerArray on %s (frame=%s)" % (self._topic, self._frame)
        )

    def _get_double_array(self, name: str) -> List[float]:
        return list(self.get_parameter(name).get_parameter_value().double_array_value)

    def _resolve_sector_pairs(
        self,
        array_yaw_name: str,
        array_fov_name: str,
        legacy_yaw_name: str,
        legacy_fov_name: str,
    ) -> List[Tuple[float, float]]:
        yaws = self._get_double_array(array_yaw_name)
        fovs = self._get_double_array(array_fov_name)
        if not yaws:
            yaws = [float(self.get_parameter(legacy_yaw_name).get_parameter_value().double_value)]
        if not fovs:
            fovs = [float(self.get_parameter(legacy_fov_name).get_parameter_value().double_value)]
        if len(fovs) == 1 and len(yaws) > 1:
            fovs = fovs * len(yaws)
        elif len(yaws) == 1 and len(fovs) > 1:
            yaws = yaws * len(fovs)
        count = min(len(yaws), len(fovs))
        return [(yaws[i], fovs[i]) for i in range(count)]

    def _append_sector_markers(
        self,
        arr: MarkerArray,
        stamp,
        ns: str,
        start_id: int,
        sectors: Sequence[Tuple[float, float]],
        rin: float,
        rout: float,
        n_arc: int,
        z: float,
        lw: float,
        color: ColorRGBA,
    ) -> int:
        mid = start_id
        for yaw, half_fov in sectors:
            if rout <= rin + 0.5 or half_fov <= 1e-6:
                continue
            arr.markers.append(
                _line_marker(
                    ns,
                    mid,
                    self._frame,
                    stamp,
                    _sector_annulus_strip(yaw, half_fov, rin, rout, n_arc, z),
                    color,
                    lw,
                )
            )
            mid += 1
        return mid

    def _on_timer(self) -> None:
        stamp = self.get_clock().now().to_msg()
        z = float(self.get_parameter("z_height").get_parameter_value().double_value)
        lw = float(self.get_parameter("line_width").get_parameter_value().double_value)
        n_circ = int(self.get_parameter("circle_segments").get_parameter_value().integer_value)
        n_arc = int(self.get_parameter("sector_arc_segments").get_parameter_value().integer_value)
        n_circ = max(12, n_circ)
        n_arc = max(8, n_arc)

        arr = MarkerArray()
        mid = 0

        if self.get_parameter("show_gt_annulus").get_parameter_value().bool_value:
            r0 = float(self.get_parameter("gt_annulus_radius_min").get_parameter_value().double_value)
            r1 = float(self.get_parameter("gt_annulus_radius_max").get_parameter_value().double_value)
            c0 = ColorRGBA(r=0.85, g=0.85, b=0.85, a=0.75)
            c1 = ColorRGBA(r=0.65, g=0.75, b=0.95, a=0.75)
            if r0 > 0.5:
                arr.markers.append(
                    _line_marker(
                        "gt_annulus",
                        mid,
                        self._frame,
                        stamp,
                        _circle_strip(r0, n_circ, z),
                        c0,
                        lw,
                    )
                )
                mid += 1
            if r1 > r0 + 0.5:
                arr.markers.append(
                    _line_marker(
                        "gt_annulus",
                        mid,
                        self._frame,
                        stamp,
                        _circle_strip(r1, n_circ, z + 0.01),
                        c1,
                        lw,
                    )
                )
                mid += 1

        if self.get_parameter("show_vision_sector").get_parameter_value().bool_value:
            vision_sectors = self._resolve_sector_pairs(
                "vision_yaws",
                "vision_fov_half_angles",
                "vision_yaw",
                "vision_fov_half_angle",
            )
            rin = float(self.get_parameter("vision_range_min").get_parameter_value().double_value)
            rout = float(self.get_parameter("vision_range_max").get_parameter_value().double_value)
            cv = ColorRGBA(r=0.25, g=0.55, b=1.0, a=0.55)
            mid = self._append_sector_markers(
                arr,
                stamp,
                "vision_fov_ring",
                0,
                vision_sectors,
                rin,
                rout,
                n_arc,
                z + 0.02,
                lw,
                cv,
            )

        if self.get_parameter("show_mmwave_sector").get_parameter_value().bool_value:
            mmwave_sectors = self._resolve_sector_pairs(
                "mmwave_yaws",
                "mmwave_fov_half_angles",
                "mmwave_yaw",
                "mmwave_fov_half_angle",
            )
            rin = float(self.get_parameter("mmwave_range_min").get_parameter_value().double_value)
            rout = float(self.get_parameter("mmwave_range_max").get_parameter_value().double_value)
            cm = ColorRGBA(r=0.2, g=0.9, b=0.35, a=0.5)
            self._append_sector_markers(
                arr,
                stamp,
                "mmwave_fov_ring",
                0,
                mmwave_sectors,
                rin,
                rout,
                n_arc,
                z + 0.03,
                lw,
                cm,
            )

        self._pub.publish(arr)


def main(args=None) -> None:
    rclpy.init(args=args)
    node = RangeOverlayNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
