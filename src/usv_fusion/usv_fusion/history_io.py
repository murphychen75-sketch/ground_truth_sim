"""Append and read per-target trajectory jsonl files (same schema as FusedTrackSample)."""

from __future__ import annotations

import json
import os
from typing import Any, Dict, List, Optional, Tuple

from builtin_interfaces.msg import Time


def append_target_sample_jsonl(history_dir: str, target_id: int, row: Dict[str, Any]) -> None:
    """Append one JSON line to ``history_dir/target_<id>.jsonl`` (creates directory if needed)."""
    os.makedirs(history_dir, exist_ok=True)
    path = os.path.join(history_dir, "target_%d.jsonl" % int(target_id))
    with open(path, "a", encoding="utf-8") as f:
        f.write(json.dumps(row, ensure_ascii=False) + "\n")


def time_to_sec(t: Time) -> float:
    """Return ``Time`` as floating-point seconds."""
    return float(t.sec) + float(t.nanosec) * 1e-9


def sec_to_time(sec: float) -> Time:
    """Build ``builtin_interfaces/Time`` from floating-point seconds (non-negative)."""
    t = Time()
    sec = max(0.0, float(sec))
    t.sec = int(sec)
    t.nanosec = int(round((sec - t.sec) * 1e9))
    return t


def read_target_history_jsonl(
    history_dir: str,
    target_id: int,
    t_start_sec: Optional[float],
    t_end_sec: Optional[float],
    max_samples: int,
) -> Tuple[int, List[Dict[str, Any]]]:
    """Read jsonl rows for ``target_id``; filter by ``t_start_sec``/``t_end_sec`` (inclusive); cap count.

    Returns ``(status, rows)`` where status is 0=ok, 1=no file, 2=read/parse error.
    """
    path = os.path.join(history_dir, "target_%d.jsonl" % int(target_id))
    if not os.path.isfile(path):
        return 1, []
    rows: List[Dict[str, Any]] = []
    try:
        with open(path, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                row = json.loads(line)
                ts = float(row.get("t_sec", 0.0))
                if t_start_sec is not None and ts < t_start_sec:
                    continue
                if t_end_sec is not None and ts > t_end_sec:
                    continue
                rows.append(row)
                if max_samples > 0 and len(rows) >= max_samples:
                    break
    except (OSError, json.JSONDecodeError):
        return 2, []
    return 0, rows
