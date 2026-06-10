"""融合航迹 UUID 工具：分配、ROS 序列化与 RViz 映射。"""

from __future__ import annotations

import struct
import uuid
import zlib
from typing import TYPE_CHECKING
from uuid import UUID

from std_msgs.msg import ColorRGBA

if TYPE_CHECKING:
    from unique_identifier_msgs.msg import UUID as RosUUID


def new_track_uuid() -> UUID:
    return uuid.uuid4()


def fill_ros_uuid(msg: RosUUID, track_id: UUID) -> None:
    msg.uuid = list(track_id.bytes)


def ros_uuid_to_bytes(msg: RosUUID) -> bytes:
    return bytes(msg.uuid)


def ros_uuid_to_python(msg: RosUUID) -> UUID:
    return UUID(bytes=ros_uuid_to_bytes(msg))


def uuid_sort_key(track_id: UUID) -> bytes:
    return track_id.bytes


def uuid_to_marker_id(track_id: UUID) -> int:
    return int(zlib.crc32(track_id.bytes) & 0x7FFFFFFF)


def uuid_to_color(track_id: UUID) -> ColorRGBA:
    packed = struct.unpack("BBBB", struct.pack(">I", uuid_to_marker_id(track_id)))
    return ColorRGBA(
        r=float(packed[0]) / 255.0,
        g=float(packed[1]) / 255.0,
        b=float(packed[2]) / 255.0,
        a=0.95,
    )


def int_to_uuid(value: int) -> UUID:
    """仿真真值等场景：由整数确定性映射为 UUID。"""
    return UUID(int=int(value))
