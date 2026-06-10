"""极坐标 EKF、像素宽度投影与关联度量的单元测试。"""

from __future__ import annotations

import math
import unittest

import numpy as np

from usv_event_fusion.association import BIG, solve_gated_assignment
from usv_event_fusion.association_metrics import (
    AssociationMetricConfig,
    VisionWidthMatchConfig,
    build_vision_association_cost,
    class_gate_pass,
    width_penalty_squared,
)
from usv_event_fusion.filters import ekf_update_polar, polar_innovation
from usv_event_fusion.sensor_models import (
    effective_size_lpf_alpha,
    profile_width_to_pixel_width,
)
from usv_event_fusion.track_state import InternalTrack, TrackProfile, TrackStatus
from usv_event_fusion.track_uuid import new_track_uuid


class TestPolarEkf(unittest.TestCase):
    def test_polar_update_moves_toward_measurement(self) -> None:
        mean = np.array([[10.0], [0.0], [0.0], [0.0]], dtype=np.float64)
        cov = np.diag([4.0, 4.0, 1.0, 1.0]).astype(np.float64)
        z = np.array([[12.0], [0.1]], dtype=np.float64)
        R = np.diag([1.0, 0.01]).astype(np.float64)
        mean_new, _ = ekf_update_polar(mean, cov, z, R)
        self.assertGreater(float(mean_new[0, 0]), 10.0)

    def test_innovation_bearing_wrap(self) -> None:
        mean = np.array([[-10.0], [0.0], [0.0], [0.0]], dtype=np.float64)
        z = np.array([[10.0], [-math.pi + 0.05]], dtype=np.float64)
        nu, _ = polar_innovation(mean, z)
        self.assertLess(abs(float(nu[1, 0])), 0.1)


class TestPixelWidth(unittest.TestCase):
    def test_profile_width_to_pixel(self) -> None:
        px = profile_width_to_pixel_width(100.0, 10.0, 800.0)
        self.assertAlmostEqual(px, 80.0)

    def test_distance_weighted_alpha(self) -> None:
        near = effective_size_lpf_alpha(0.35, 50.0, 50.0, 0.1)
        far = effective_size_lpf_alpha(0.35, 200.0, 50.0, 0.1)
        self.assertGreater(near, far)


class TestAssociationMetrics(unittest.TestCase):
    def test_class_gate_rejects_mismatch(self) -> None:
        prof = TrackProfile(class_name="ship", class_confidence=0.8)
        self.assertFalse(class_gate_pass(prof, "buoy", 0.6))

    def test_vision_cost_uses_pixel_width(self) -> None:
        prof = TrackProfile(size_w=10.0)
        tr = InternalTrack(
            track_id=new_track_uuid(),
            mean=np.array([[100.0], [0.0], [0.0], [0.0]], dtype=np.float64),
            cov=np.diag([1.0, 1.0, 1.0, 1.0]).astype(np.float64),
            profile=prof,
            last_filter_stamp_sec=0.0,
            last_predict_stamp_sec=0.0,
            status=TrackStatus.CONFIRMED,
            association_hits=3,
        )
        z = np.array([[100.0], [0.0]], dtype=np.float64)
        R = np.diag([1.0, 0.01]).astype(np.float64)
        track_px = profile_width_to_pixel_width(100.0, 10.0, 800.0)
        cfg = AssociationMetricConfig(
            chi2_gate_kin=5.991,
            association_width_weight=1.0,
            width_meas_std=0.0,
            width_track_std=0.0,
            width_gate_sigma=3.0,
            class_match_min_confidence=0.6,
        )
        wcfg = VisionWidthMatchConfig(800.0, 12.0, 8.0)
        c_match = build_vision_association_cost(tr, track_px, "ship", z, R, cfg, wcfg)
        c_far = build_vision_association_cost(tr, track_px * 0.2, "ship", z, R, cfg, wcfg)
        self.assertLess(c_match, c_far)


class TestHungarianCoastCost(unittest.TestCase):
    def test_zero_coast_cost_skips_gated_pairs(self) -> None:
        """coast 虚列代价为 0 时，匈牙利会优先滑行而不关联。"""
        cost = np.array([[3.0]], dtype=np.float64)
        assign = solve_gated_assignment(1, 1, cost, dummy_cost=0.0)
        self.assertEqual(len(assign.pairs), 0)
        self.assertEqual(assign.unmatched_measurement_indices, [0])

    def test_chi2_coast_cost_allows_gated_pairs(self) -> None:
        cost = np.array([[3.0]], dtype=np.float64)
        assign = solve_gated_assignment(1, 1, cost, dummy_cost=5.991)
        self.assertEqual(assign.pairs, [(0, 0)])


if __name__ == "__main__":
    unittest.main()
