"""关联阶段契约：匈牙利算法与 JPDA。

匈牙利算法产生硬分配；JPDA 产生 ``beta[i,j]`` 供 PDAF 混合更新使用
（见 ``jpda.py`` + ``filters.jpda_pdaf_update``）。若 JPDA 假设枚举超出预算则回退到匈牙利。
"""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
from typing import List, Optional, Protocol, Sequence
from uuid import UUID

import numpy as np
import numpy.typing as npt


class Modality(str, Enum):
    """单次融合回调的传感器模态。"""

    VISION = "vision"
    RADAR = "radar"


@dataclass
class GatedAssociationProblem:
    """匈牙利与未来 JPDA 共享的输入（预测 + 椭球门控之后）。"""

    track_ids: List[UUID]
    """行索引 i 对应 track_ids[i]。"""

    z_list: List[npt.NDArray[np.float64]]
    """测量向量 z_j（已在滤波器坐标系中）。"""

    gate_valid: npt.NDArray[np.bool_]
    """形状 (n_tracks, n_meas)；gate_valid[i, j] 为 True 表示 (i,j) 通过门控。"""

    modality: Modality

    log_likelihood: Optional[npt.NDArray[np.float64]] = None
    """可选形状 (n_tracks, n_meas)，在 gate_valid 处为有限值。"""

    # --- 仅 JPDA 使用的参数（匈牙利 v1 未用；记录供后续替换） ---
    P_D: float = 0.95
    lambda_clutter: float = 1e-4


@dataclass
class HungarianAssociationResult:
    """硬分配结果（v1）。"""

    pairs: List[tuple[int, int]]
    """(航迹行索引, 测量索引)。"""

    unmatched_track_rows: List[int]
    unmatched_measurement_indices: List[int]


@dataclass
class JPDABetaResult:
    """JPDA 关联概率（预留）；对每个 i 有 sum_j beta[i,j] == 1。"""

    beta: npt.NDArray[np.float64]
    """形状 (n_tracks, n_meas + 1)；第 0 列为「无检测」/ 杂波吸收。"""


class AssociationSolver(Protocol):
    """可选插件接口（匈牙利实现在 ``association.py``）。"""

    def solve(self, problem: GatedAssociationProblem) -> HungarianAssociationResult: ...


def jpda_future_inputs_note() -> str:
    """文档占位：JPDA 需要 P_D、杂波模型；输出 beta[i,j] 用于加权更新。"""

    return (
        "JPDA replaces solve(); downstream uses beta matrix for mixture Kalman update."
    )
