"""Tracker-tracker 重叠检测与信息滤波合并。"""

from __future__ import annotations

from dataclasses import dataclass
from typing import List, Tuple
from uuid import UUID

import numpy as np

from usv_event_fusion.association_metrics import class_gate_pass, radar_kin_innovation, width_gate_pass
from usv_event_fusion.track_state import InternalTrack, TrackStatus


@dataclass
class TrackMergeConfig:
    center_distance_m: float = 10.0
    use_kin_gate: bool = True
    kin_chi2_gate: float = 9.488
    width_track_std_m: float = 0.3
    width_gate_sigma: float = 2.0
    class_match_min_confidence: float = 0.6


def track_center_distance(a: InternalTrack, b: InternalTrack) -> float:
    dx = float(a.mean[0, 0] - b.mean[0, 0])
    dy = float(a.mean[1, 0] - b.mean[1, 0])
    return float(np.hypot(dx, dy))


def tracks_overlap(a: InternalTrack, b: InternalTrack, cfg: TrackMergeConfig) -> bool:
    if track_center_distance(a, b) > cfg.center_distance_m:
        return False
    sigma = float(cfg.width_track_std_m)
    if not width_gate_pass(
        a.profile.size_w,
        b.profile.size_w,
        sigma,
        sigma,
        cfg.width_gate_sigma,
    ):
        return False
    if not class_gate_pass(a.profile, b.profile.class_name, cfg.class_match_min_confidence):
        return False
    if not class_gate_pass(b.profile, a.profile.class_name, cfg.class_match_min_confidence):
        return False
    if cfg.use_kin_gate:
        _, _, d2_ab = radar_kin_innovation(a, b.mean.copy(), b.cov.copy())
        _, _, d2_ba = radar_kin_innovation(b, a.mean.copy(), a.cov.copy())
        if d2_ab > cfg.kin_chi2_gate or d2_ba > cfg.kin_chi2_gate:
            return False
    return True


def track_merge_priority_key(tr: InternalTrack) -> Tuple[int, int, float, str]:
    confirmed = 1 if tr.status == TrackStatus.CONFIRMED else 0
    return (confirmed, tr.association_hits, tr.last_filter_stamp_sec, str(tr.track_id))


def pick_keeper_loser(a: InternalTrack, b: InternalTrack) -> Tuple[InternalTrack, InternalTrack]:
    if track_merge_priority_key(a) >= track_merge_priority_key(b):
        return a, b
    return b, a


def information_fusion_merge(
    mean_a: np.ndarray,
    cov_a: np.ndarray,
    mean_b: np.ndarray,
    cov_b: np.ndarray,
) -> Tuple[np.ndarray, np.ndarray]:
    try:
        inv_a = np.linalg.inv(cov_a)
        inv_b = np.linalg.inv(cov_b)
    except np.linalg.LinAlgError:
        return mean_a.copy(), cov_a.copy()
    info_a = inv_a @ mean_a
    info_b = inv_b @ mean_b
    inv_sum = inv_a + inv_b
    try:
        cov_m = np.linalg.inv(inv_sum)
    except np.linalg.LinAlgError:
        return mean_a.copy(), cov_a.copy()
    mean_m = cov_m @ (info_a + info_b)
    return mean_m, cov_m


def merge_profiles(keeper: InternalTrack, loser: InternalTrack, class_history_len: int) -> None:
    kp = keeper.profile
    lp = loser.profile
    w_k = max(keeper.association_hits, 1)
    w_l = max(loser.association_hits, 1)
    wt = float(w_k + w_l)
    for attr in ("size_w", "size_l", "size_h"):
        kv = float(getattr(kp, attr))
        lv = float(getattr(lp, attr))
        if kv <= 0.0 and lv > 0.0:
            setattr(kp, attr, lv)
        elif lv > 0.0:
            setattr(kp, attr, (w_k * kv + w_l * lv) / wt)
    combined = list(kp.class_history) + list(lp.class_history)
    kp.class_history.clear()
    for name in combined:
        cid = kp.class_ids_by_name.get(name, lp.class_ids_by_name.get(name, 0))
        kp.update_class_vote(name, cid, class_history_len)
    if lp.radar_track_id and not kp.radar_track_id:
        kp.radar_track_id = lp.radar_track_id


def merge_tracks(keeper: InternalTrack, loser: InternalTrack, class_history_len: int) -> None:
    keeper.mean, keeper.cov = information_fusion_merge(
        keeper.mean,
        keeper.cov,
        loser.mean,
        loser.cov,
    )
    merge_profiles(keeper, loser, class_history_len)
    keeper.association_hits = max(keeper.association_hits, loser.association_hits)
    if loser.status == TrackStatus.CONFIRMED:
        keeper.status = TrackStatus.CONFIRMED
    keeper.last_filter_stamp_sec = max(keeper.last_filter_stamp_sec, loser.last_filter_stamp_sec)
    keeper.last_predict_stamp_sec = max(keeper.last_predict_stamp_sec, loser.last_predict_stamp_sec)


def find_next_merge_pair(
    tracks: List[InternalTrack],
    cfg: TrackMergeConfig,
) -> Tuple[InternalTrack, InternalTrack] | None:
    for i in range(len(tracks)):
        for j in range(i + 1, len(tracks)):
            if tracks_overlap(tracks[i], tracks[j], cfg):
                return pick_keeper_loser(tracks[i], tracks[j])
    return None


def merge_overlapping_track_ids(
    tracks: dict[UUID, InternalTrack],
    cfg: TrackMergeConfig,
    class_history_len: int,
) -> List[Tuple[UUID, UUID]]:
    merged_pairs: List[Tuple[UUID, UUID]] = []
    while True:
        rows = [tracks[k] for k in sorted(tracks.keys(), key=lambda uid: uid.bytes)]
        pair = find_next_merge_pair(rows, cfg)
        if pair is None:
            break
        keeper, loser = pair
        merge_tracks(keeper, loser, class_history_len)
        del tracks[loser.track_id]
        merged_pairs.append((keeper.track_id, loser.track_id))
    return merged_pairs
