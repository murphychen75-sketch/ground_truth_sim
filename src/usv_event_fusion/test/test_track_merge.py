"""tracker-tracker 重叠检测与合并。"""

from __future__ import annotations

import unittest
from uuid import UUID

import numpy as np

from usv_event_fusion.fusion_engine import FusionConfig, FusionEngine
from usv_event_fusion.track_overlap import (
    TrackMergeConfig,
    merge_tracks,
    pick_keeper_loser,
    tracks_overlap,
)
from usv_event_fusion.track_state import InternalTrack, TrackProfile, TrackStatus
from usv_event_fusion.track_uuid import new_track_uuid


def _make_track(
    x: float,
    y: float,
    *,
    track_id: UUID | None = None,
    hits: int = 1,
    status: TrackStatus = TrackStatus.TENTATIVE,
    class_name: str = "ship",
    size_w: float = 8.0,
    radar_track_id: int = 0,
) -> InternalTrack:
    return InternalTrack(
        track_id=track_id or new_track_uuid(),
        mean=np.array([[x], [y], [0.0], [0.0]], dtype=np.float64),
        cov=np.diag([1.0, 1.0, 1.0, 1.0]).astype(np.float64),
        profile=TrackProfile(size_w=size_w, size_l=size_w, class_name=class_name, class_confidence=0.8),
        last_filter_stamp_sec=1.0,
        last_predict_stamp_sec=1.0,
        status=status,
        association_hits=hits,
    )


class TestTrackMerge(unittest.TestCase):
    def test_overlap_requires_center_distance(self) -> None:
        cfg = TrackMergeConfig(center_distance_m=5.0)
        a = _make_track(0.0, 0.0)
        b = _make_track(20.0, 0.0)
        self.assertFalse(tracks_overlap(a, b, cfg))

    def test_overlap_rejects_class_mismatch(self) -> None:
        cfg = TrackMergeConfig(center_distance_m=10.0)
        a = _make_track(0.0, 0.0, class_name="ship")
        b = _make_track(1.0, 0.0, class_name="buoy")
        self.assertFalse(tracks_overlap(a, b, cfg))

    def test_confirmed_wins_over_tentative(self) -> None:
        tentative = _make_track(0.0, 0.0, hits=1, status=TrackStatus.TENTATIVE)
        confirmed = _make_track(1.0, 0.0, hits=3, status=TrackStatus.CONFIRMED)
        keeper, loser = pick_keeper_loser(tentative, confirmed)
        self.assertEqual(keeper.status, TrackStatus.CONFIRMED)
        self.assertEqual(loser.status, TrackStatus.TENTATIVE)

    def test_merge_fuses_state_between_tracks(self) -> None:
        keeper = _make_track(0.0, 0.0, hits=3, status=TrackStatus.CONFIRMED)
        loser = _make_track(2.0, 0.0, hits=1, status=TrackStatus.TENTATIVE)
        keeper_id = keeper.track_id
        merge_tracks(keeper, loser, class_history_len=10)
        self.assertEqual(keeper.track_id, keeper_id)
        self.assertGreater(float(keeper.mean[0, 0]), 0.0)
        self.assertLess(float(keeper.mean[0, 0]), 2.0)

    def test_engine_merge_removes_duplicate_track(self) -> None:
        eng = FusionEngine(
            FusionConfig(
                enable_track_merge=True,
                merge_center_distance_m=10.0,
                merge_use_kin_gate=True,
                max_internal_tracks=4,
            )
        )
        a = _make_track(0.0, 0.0, hits=3, status=TrackStatus.CONFIRMED)
        b = _make_track(1.0, 0.0, hits=1, status=TrackStatus.TENTATIVE)
        eng._tracks[a.track_id] = a
        eng._tracks[b.track_id] = b
        removed = eng._merge_overlapping_tracks()
        self.assertEqual(len(eng._tracks), 1)
        self.assertEqual(len(removed), 1)
        self.assertIn(a.track_id, eng._tracks)
        self.assertNotIn(b.track_id, eng._tracks)


if __name__ == "__main__":
    unittest.main()
