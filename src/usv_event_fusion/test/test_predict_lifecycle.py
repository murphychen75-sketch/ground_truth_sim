"""航迹预测与生命周期：增量预测、暂态 birth 不预测。"""

from __future__ import annotations

import unittest

import numpy as np

from usv_event_fusion.fusion_engine import FusionEngine
from usv_event_fusion.track_state import InternalTrack, TrackProfile, TrackStatus
from usv_event_fusion.track_uuid import new_track_uuid


def _make_track(vx: float = 1.0, hits: int = 3) -> InternalTrack:
    return InternalTrack(
        track_id=new_track_uuid(),
        mean=np.array([[0.0], [0.0], [vx], [0.0]], dtype=np.float64),
        cov=np.diag([1.0, 1.0, 1.0, 1.0]).astype(np.float64),
        profile=TrackProfile(),
        last_filter_stamp_sec=0.0,
        last_predict_stamp_sec=0.0,
        status=TrackStatus.CONFIRMED if hits >= 3 else TrackStatus.TENTATIVE,
        association_hits=hits,
    )


class TestPredictLifecycle(unittest.TestCase):
    def test_incremental_predict_avoids_double_integration(self) -> None:
        eng = FusionEngine()
        tr = _make_track(vx=1.0, hits=3)
        eng._predict_tracks_to([tr], 0.02)
        x1 = float(tr.mean[0, 0])
        eng._predict_tracks_to([tr], 0.04)
        x2 = float(tr.mean[0, 0])
        self.assertAlmostEqual(x1, 0.02, places=4)
        self.assertAlmostEqual(x2, 0.04, places=4)

    def test_tentative_birth_frozen_until_reassociated(self) -> None:
        eng = FusionEngine()
        tr = _make_track(vx=5.0, hits=1)
        tr.status = TrackStatus.TENTATIVE
        eng._predict_tracks_to([tr], 1.0)
        self.assertAlmostEqual(float(tr.mean[0, 0]), 0.0, places=6)
        self.assertAlmostEqual(tr.last_predict_stamp_sec, 0.0, places=6)


if __name__ == "__main__":
    unittest.main()
