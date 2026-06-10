#!/usr/bin/env python3
"""ROS 2 node that simulates high-latency AIS broadcasts."""

from __future__ import annotations

import math
from collections import deque
from dataclasses import dataclass
from typing import Deque, List

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.time import Time
from visualization_msgs.msg import Marker, MarkerArray

try:
    from usv_msgs.msg import AISTrack, AISTrackArray, GlobalTrackArray  # type: ignore
except ImportError:  # pragma: no cover
    from usv_interfaces.msg import AISTrack, AISTrackArray, GlobalTrackArray  # type: ignore


@dataclass
class _QueueItem:
    received_time: Time
    message: GlobalTrackArray


class SimAISNode(Node):
    """Simulate AIS link characteristics: low rate, long delay, precise coordinates."""

    def __init__(self) -> None:
        super().__init__("sim_ais_node")
        self.declare_parameter("input_topic", "/sim/ground_truth")
        self.declare_parameter("ais_topic", "/ais/tracks")
        self.declare_parameter("marker_topic", "/ais/markers")
        self.declare_parameter("delay_sec", 3.0)
        self.declare_parameter("timer_period", 0.2)
        self.declare_parameter("ship_name_prefix", "AIS-")
        self.declare_parameter("frame_id", "base_link")
        self.declare_parameter("queue_max", 300)
        self.declare_parameter("text_height", 1.5)

        self._input_topic = self._get_string("input_topic")
        self._ais_topic = self._get_string("ais_topic")
        self._marker_topic = self._get_string("marker_topic")
        self._delay_sec = self._get_float("delay_sec")
        self._timer_period = self._get_float("timer_period")
        self._ship_name_prefix = self._get_string("ship_name_prefix")
        self._frame_id_default = self._get_string("frame_id")
        self._queue_max = max(1, self._get_int("queue_max"))
        self._text_height = max(0.5, self._get_float("text_height"))

        qos = QoSProfile(depth=10)
        self._sub = self.create_subscription(
            GlobalTrackArray, self._input_topic, self._on_ground_truth, qos
        )
        self._ais_pub = self.create_publisher(AISTrackArray, self._ais_topic, qos)
        self._marker_pub = self.create_publisher(MarkerArray, self._marker_topic, qos)

        self._queue: Deque[_QueueItem] = deque()
        self._timer = self.create_timer(self._timer_period, self._process_queue)
        self.get_logger().info(
            "SimAISNode ready (delay=%.1fs, input=%s)" % (self._delay_sec, self._input_topic)
        )

    # ------------------------------------------------------------------
    # Callbacks
    # ------------------------------------------------------------------
    def _on_ground_truth(self, msg: GlobalTrackArray) -> None:
        if len(self._queue) >= self._queue_max:
            dropped = self._queue.popleft()
            dropped_stamp = dropped.received_time.nanoseconds * 1e-9
            self.get_logger().warn(
                "Dropping oldest AIS queue item stamped %.3f due to overflow" % dropped_stamp
            )
        item = _QueueItem(received_time=self.get_clock().now(), message=msg)
        self._queue.append(item)

    def _process_queue(self) -> None:
        if not self._queue:
            return
        now = self.get_clock().now()
        while self._queue:
            head = self._queue[0]
            elapsed = (now.nanoseconds - head.received_time.nanoseconds) * 1e-9
            if elapsed < self._delay_sec:
                break
            self._queue.popleft()
            self._publish_from_snapshot(head.message)

    # ------------------------------------------------------------------
    # Publishing helpers
    # ------------------------------------------------------------------
    def _publish_from_snapshot(self, msg: GlobalTrackArray) -> None:
        frame_id = msg.header.frame_id or self._frame_id_default
        array_msg = AISTrackArray()
        array_msg.header.stamp = msg.header.stamp
        array_msg.header.frame_id = frame_id
        marker_list: List[Marker] = []

        for track in msg.tracks:
            if not track.is_ais_matched:
                continue
            ais_track = AISTrack()
            ais_track.mmsi = track.matched_mmsi
            ais_track.ship_name = f"{self._ship_name_prefix}{track.matched_mmsi}".strip()
            ais_track.relative_x = track.x
            ais_track.relative_y = track.y
            ais_track.relative_v_x = track.v_x
            ais_track.relative_v_y = track.v_y
            ais_track.true_heading = self._compute_heading(track.v_x, track.v_y)
            array_msg.tracks.append(ais_track)
            marker_list.append(self._make_marker(track, frame_id, msg.header.stamp))

        stamp = msg.header.stamp
        # 全量刷新：先清空 ais_labels，避免旧 MMSI/旧 track 重生后 RViz 仍保留旧 TEXT
        clear = MarkerArray()
        clear.markers = [self._make_deleteall_ais_labels(frame_id, stamp)]
        self._marker_pub.publish(clear)
        if marker_list:
            self._marker_pub.publish(MarkerArray(markers=marker_list))

        if not array_msg.tracks:
            return

        self._ais_pub.publish(array_msg)

    def _compute_heading(self, v_x: float, v_y: float) -> float:
        if abs(v_x) < 1e-6 and abs(v_y) < 1e-6:
            return 0.0
        return math.atan2(v_y, v_x)

    def _make_deleteall_ais_labels(self, frame_id: str, stamp) -> Marker:
        m = Marker()
        m.header.frame_id = frame_id
        m.header.stamp = stamp
        m.ns = "ais_labels"
        m.id = 0
        m.action = Marker.DELETEALL
        return m

    def _make_marker(self, track, frame_id: str, stamp) -> Marker:
        marker = Marker()
        marker.header.frame_id = frame_id
        marker.header.stamp = stamp
        marker.ns = "ais_labels"
        marker.id = int(track.matched_mmsi or track.track_id)
        marker.type = Marker.TEXT_VIEW_FACING
        marker.action = Marker.ADD
        marker.pose.position.x = track.x
        marker.pose.position.y = track.y
        marker.pose.position.z = max(track.size_h + 1.0, 1.5)
        marker.pose.orientation.w = 1.0
        marker.scale.z = self._text_height
        marker.color.r = 0.8
        marker.color.g = 0.2
        marker.color.b = 0.8
        marker.color.a = 1.0
        marker.text = f"MMSI: {track.matched_mmsi}"
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

    def _get_int(self, name: str) -> int:
        value = self.get_parameter(name).value
        return int(value) if value is not None else 0


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SimAISNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("SimAISNode interrupted, shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
