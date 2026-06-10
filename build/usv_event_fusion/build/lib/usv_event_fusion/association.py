"""在带 coast 虚拟列的矩形代价矩阵上做匈牙利分配。"""

from __future__ import annotations

from typing import List, Tuple

import numpy as np
from scipy.optimize import linear_sum_assignment

from usv_event_fusion.association_contract import HungarianAssociationResult

BIG = 1.0e8


def associate_hungarian(cost: np.ndarray) -> Tuple[np.ndarray, np.ndarray]:
    """返回 scipy 的 row_indices、col_indices。"""
    return linear_sum_assignment(cost)


def solve_gated_assignment(
    n_tracks: int,
    n_meas: int,
    cost_track_meas: np.ndarray,
    dummy_cost: float = 0.0,
) -> HungarianAssociationResult:
    """航迹 ×（测量 + 航迹虚拟列）；虚拟列 k 以 dummy_cost 让航迹 k coast。"""
    cols = n_meas + n_tracks
    cost = np.full((n_tracks, cols), BIG, dtype=np.float64)
    cost[:, :n_meas] = cost_track_meas
    for i in range(n_tracks):
        cost[i, n_meas + i] = dummy_cost
    ri, ci = associate_hungarian(cost)
    pairs: List[tuple[int, int]] = []
    used_meas: set[int] = set()
    matched_rows: set[int] = set()
    for ti, cidx in zip(ri, ci):
        if cidx < n_meas and cost[ti, cidx] < BIG * 0.5:
            pairs.append((int(ti), int(cidx)))
            used_meas.add(int(cidx))
            matched_rows.add(int(ti))
    unmatched_tracks = [i for i in range(n_tracks) if i not in matched_rows]
    unmatched_meas = [j for j in range(n_meas) if j not in used_meas]
    return HungarianAssociationResult(
        pairs=pairs,
        unmatched_track_rows=unmatched_tracks,
        unmatched_measurement_indices=unmatched_meas,
    )
