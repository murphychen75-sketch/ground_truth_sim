"""内部航迹表示与可发布的快照。"""

from __future__ import annotations

from collections import Counter, deque
from dataclasses import dataclass, field
from enum import Enum
from typing import Deque, Dict, List
from uuid import UUID

import numpy as np
import numpy.typing as npt


class TrackStatus(str, Enum):
    """TENTATIVE 航迹在晋升前不会发布到 FusedSceneSnapshot。"""

    TENTATIVE = "tentative"
    CONFIRMED = "confirmed"


@dataclass
class TrackProfile:
    """缓变目标属性（消息 B）。"""

    size_w: float = 0.0
    size_l: float = 0.0
    size_h: float = 0.0
    class_id: int = 0
    class_name: str = ""
    class_confidence: float = 0.0
    radar_track_id: int = 0
    class_ids_by_name: Dict[str, int] = field(default_factory=dict)
    class_history: Deque[str] = field(default_factory=lambda: deque(maxlen=10))

    def update_sizes_lpf(
        self,
        size_w: float,
        size_l: float,
        size_h: float,
        alpha: float,
    ) -> None:
        """对包围盒尺寸做一阶低通滤波。"""
        a = float(np.clip(alpha, 0.0, 1.0))
        if self.size_w <= 0.0 and self.size_l <= 0.0 and self.size_h <= 0.0:
            self.size_w = size_w
            self.size_l = size_l
            self.size_h = size_h
            return
        self.size_w = a * size_w + (1.0 - a) * self.size_w
        self.size_l = a * size_l + (1.0 - a) * self.size_l
        self.size_h = a * size_h + (1.0 - a) * self.size_h

    def update_class_vote(
        self,
        class_name: str,
        class_id: int,
        history_len: int,
    ) -> None:
        """追加匹配视觉检测的类别并刷新主导类别。"""
        if not class_name:
            return
        if self.class_history.maxlen != history_len:
            self.class_history = deque(self.class_history, maxlen=history_len)
        self.class_history.append(class_name)
        self.class_ids_by_name[class_name] = class_id
        counts = Counter(self.class_history)
        dominant, count = counts.most_common(1)[0]
        self.class_name = dominant
        self.class_confidence = float(count) / float(len(self.class_history))
        self.class_id = self.class_ids_by_name.get(dominant, class_id)


@dataclass
class InternalTrack:
    """全局航迹表中的一行：运动学 (A) + 剖面 (B)。"""

    track_id: UUID
    mean: npt.NDArray[np.float64]
    cov: npt.NDArray[np.float64]
    profile: TrackProfile
    last_filter_stamp_sec: float
    last_predict_stamp_sec: float
    status: TrackStatus
    """晋升：成功关联会使 ``association_hits`` 递增。"""

    association_hits: int


@dataclass
class TrackState:
    """可序列化的融合航迹，供 ROS 发布。"""

    track_id: UUID
    x: float
    y: float
    vx: float
    vy: float
    covariance_row_major: List[float]
    size_w: float
    size_l: float
    size_h: float
    class_id: int
    class_name: str
    class_confidence: float
    last_seen_stamp_sec: float


def cov_to_row_major_16(cov: npt.NDArray[np.float64]) -> List[float]:
    out: List[float] = []
    for r in range(4):
        for c in range(4):
            out.append(float(cov[r, c]))
    return out


def track_state_from_internal(tr: InternalTrack) -> TrackState:
    prof = tr.profile
    return TrackState(
        track_id=tr.track_id,
        x=float(tr.mean[0, 0]),
        y=float(tr.mean[1, 0]),
        vx=float(tr.mean[2, 0]),
        vy=float(tr.mean[3, 0]),
        covariance_row_major=cov_to_row_major_16(tr.cov),
        size_w=prof.size_w,
        size_l=prof.size_l,
        size_h=prof.size_h,
        class_id=prof.class_id,
        class_name=prof.class_name,
        class_confidence=prof.class_confidence,
        last_seen_stamp_sec=tr.last_filter_stamp_sec,
    )
