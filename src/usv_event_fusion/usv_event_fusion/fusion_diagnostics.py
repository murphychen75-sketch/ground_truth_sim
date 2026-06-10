"""融合关联诊断计数（1 Hz 窗口汇总打印）。"""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import List, Tuple
from uuid import UUID


@dataclass
class ModalityAssocStats:
    """单模态在一个汇总窗口内的关联统计。"""

    callbacks: int = 0
    meas_total: int = 0
    tracks_at_step: int = 0
    pairs_matched: int = 0
    tracks_coast: int = 0
    meas_unmatched: int = 0
    spawned: int = 0
    spawn_suppressed: int = 0
    empty_meas_skips: int = 0
    empty_table_births: int = 0
    gate_cells: int = 0
    gate_pass: int = 0
    fail_chi2: int = 0
    fail_width: int = 0
    fail_class: int = 0
    min_d2_kin_pass: float = field(default_factory=lambda: float("inf"))
    max_d2_kin_pass: float = 0.0

    def record_gate_pass(self, d2_kin: float) -> None:
        self.gate_pass += 1
        if d2_kin < self.min_d2_kin_pass:
            self.min_d2_kin_pass = d2_kin
        if d2_kin > self.max_d2_kin_pass:
            self.max_d2_kin_pass = d2_kin


@dataclass
class FusionDiagWindow:
    """约 1 s 内累积的诊断窗口。"""

    vision: ModalityAssocStats = field(default_factory=ModalityAssocStats)
    radar: ModalityAssocStats = field(default_factory=ModalityAssocStats)
    pruned_total: int = 0
    tracks_merged_total: int = 0
    internal_tracks: int = 0
    tentative_tracks: int = 0
    confirmed_tracks: int = 0
    snapshot_count: int = 0
    marker_count: int = 0
    last_promoted_ids: List[UUID] = field(default_factory=list)
    last_merged_pairs: List[Tuple[UUID, UUID]] = field(default_factory=list)


def _fmt_d2_range(stats: ModalityAssocStats) -> str:
    if stats.gate_pass <= 0:
        return "n/a"
    lo = stats.min_d2_kin_pass
    hi = stats.max_d2_kin_pass
    if lo == float("inf"):
        return "n/a"
    return "%.2f-%.2f" % (lo, hi)
