"""UUID 航迹 ID 分配与唯一性。"""

from __future__ import annotations

import unittest
from uuid import UUID

from usv_event_fusion.association_contract import Modality
from usv_event_fusion.fusion_engine import FusionConfig, FusionEngine, RadarObservation, VisionObservation
from usv_event_fusion.track_uuid import new_track_uuid, uuid_to_marker_id


class TestTrackUuid(unittest.TestCase):
    def test_new_track_uuid_unique(self) -> None:
        ids = {new_track_uuid() for _ in range(32)}
        self.assertEqual(len(ids), 32)

    def test_spawn_assigns_uuid(self) -> None:
        eng = FusionEngine(FusionConfig(max_internal_tracks=4))
        obs = [
            VisionObservation(
                x=10.0,
                y=0.0,
                range_m=10.0,
                bearing_rad=0.0,
                size_w=5.0,
                size_h=2.0,
                pixel_width=40.0,
                confidence=0.9,
                class_name="ship",
            )
        ]
        eng.run_at_time(0.0, Modality.VISION, obs, [])
        self.assertEqual(len(eng._tracks), 1)
        tid = next(iter(eng._tracks.keys()))
        self.assertIsInstance(tid, UUID)

    def test_prune_does_not_reuse_uuid(self) -> None:
        eng = FusionEngine(FusionConfig(track_predict_stop_sec=0.5, max_internal_tracks=4))
        obs = [
            RadarObservation(
                x=20.0,
                y=0.0,
                vx=0.0,
                vy=0.0,
                size_w=5.0,
                size_l=10.0,
                size_h=2.0,
                objmotion_status=0,
                radar_track_id=7,
            )
        ]
        eng.run_at_time(0.0, Modality.RADAR, [], obs)
        first_id = next(iter(eng._tracks.keys()))
        eng.run_at_time(2.0, Modality.RADAR, [], [])
        self.assertEqual(len(eng._tracks), 0)
        eng.run_at_time(2.1, Modality.RADAR, [], obs)
        second_id = next(iter(eng._tracks.keys()))
        self.assertNotEqual(first_id, second_id)

    def test_marker_id_stable_for_uuid(self) -> None:
        uid = new_track_uuid()
        self.assertEqual(uuid_to_marker_id(uid), uuid_to_marker_id(uid))


if __name__ == "__main__":
    unittest.main()
