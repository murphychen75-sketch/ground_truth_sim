"""复合关联度量：运动学马氏距离 + 宽度惩罚 + 类别门控。"""

from __future__ import annotations

import math
from dataclasses import dataclass
from typing import Tuple

import numpy as np
import numpy.typing as npt

from usv_event_fusion.association import BIG
from usv_event_fusion.filters import innovation_covariance, mahalanobis_squared, polar_innovation
from usv_event_fusion.sensor_models import profile_width_to_pixel_width, track_planar_distance
from usv_event_fusion.track_state import InternalTrack, TrackProfile


@dataclass
class AssociationMetricConfig:
    chi2_gate_kin: float
    association_width_weight: float
    width_meas_std: float
    width_track_std: float
    width_gate_sigma: float
    class_match_min_confidence: float


@dataclass
class VisionWidthMatchConfig:
    focal_length_px: float
    width_meas_std_px: float
    width_track_std_px: float


def width_penalty_squared(
    meas_w: float,
    track_w: float,
    sigma_meas: float,
    sigma_track: float,
) -> float:
    denom = sigma_meas * sigma_meas + sigma_track * sigma_track
    if denom <= 0.0:
        return 0.0
    diff = meas_w - track_w
    return float((diff * diff) / denom)


def width_gate_pass(
    meas_w: float,
    track_w: float,
    sigma_meas: float,
    sigma_track: float,
    gate_sigma: float,
) -> bool:
    if meas_w <= 0.0 or track_w <= 0.0:
        return True
    sigma = math.sqrt(sigma_meas * sigma_meas + sigma_track * sigma_track)
    if sigma <= 0.0:
        return True
    return abs(meas_w - track_w) <= gate_sigma * sigma


def class_gate_pass(
    profile: TrackProfile,
    meas_class_name: str,
    min_confidence: float,
) -> bool:
    if not meas_class_name:
        return True
    if not profile.class_name:
        return True
    if profile.class_confidence < min_confidence:
        return True
    return profile.class_name == meas_class_name


def composite_association_cost(
    d2_kin: float,
    d2_width: float,
    cfg: AssociationMetricConfig,
    class_ok: bool = True,
    width_ok: bool = True,
) -> float:
    if not class_ok or not width_ok:
        return BIG
    if d2_kin > cfg.chi2_gate_kin:
        return BIG
    return d2_kin + cfg.association_width_weight * d2_width


def radar_kin_innovation(
    tr: InternalTrack,
    z: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
) -> Tuple[npt.NDArray[np.float64], npt.NDArray[np.float64], float]:
    H = np.eye(4, dtype=np.float64)
    nu = z - H @ tr.mean
    S = innovation_covariance(tr.cov, H, R)
    d2 = mahalanobis_squared(nu, S)
    return nu, S, d2


def vision_polar_kin_innovation(
    tr: InternalTrack,
    z_polar: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
) -> Tuple[npt.NDArray[np.float64], npt.NDArray[np.float64], float]:
    nu, H = polar_innovation(tr.mean, z_polar)
    S = innovation_covariance(tr.cov, H, R)
    d2 = mahalanobis_squared(nu, S)
    return nu, S, d2


def build_radar_association_cost(
    tr: InternalTrack,
    meas_w: float,
    z: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
    cfg: AssociationMetricConfig,
) -> float:
    chi2_ok, width_ok, d2_kin = _radar_gate_flags(tr, meas_w, z, R, cfg)
    d2_w = width_penalty_squared(
        meas_w,
        tr.profile.size_w,
        cfg.width_meas_std,
        cfg.width_track_std,
    )
    return composite_association_cost(d2_kin, d2_w, cfg, class_ok=True, width_ok=width_ok)


def build_vision_association_cost(
    tr: InternalTrack,
    meas_pixel_width: float,
    meas_class_name: str,
    z_polar: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
    cfg: AssociationMetricConfig,
    width_cfg: VisionWidthMatchConfig,
) -> float:
    chi2_ok, width_ok, class_ok, d2_kin = _vision_gate_flags(
        tr, meas_pixel_width, meas_class_name, z_polar, R, cfg, width_cfg
    )
    track_dist = track_planar_distance(tr.mean)
    track_pixel_w = profile_width_to_pixel_width(
        track_dist,
        tr.profile.size_w,
        width_cfg.focal_length_px,
    )
    d2_w = width_penalty_squared(
        meas_pixel_width,
        track_pixel_w,
        width_cfg.width_meas_std_px,
        width_cfg.width_track_std_px,
    )
    return composite_association_cost(d2_kin, d2_w, cfg, class_ok=class_ok, width_ok=width_ok)


def _vision_gate_flags(
    tr: InternalTrack,
    meas_pixel_width: float,
    meas_class_name: str,
    z_polar: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
    cfg: AssociationMetricConfig,
    width_cfg: VisionWidthMatchConfig,
) -> Tuple[bool, bool, bool, float]:
    _, _, d2_kin = vision_polar_kin_innovation(tr, z_polar, R)
    track_dist = track_planar_distance(tr.mean)
    track_pixel_w = profile_width_to_pixel_width(
        track_dist,
        tr.profile.size_w,
        width_cfg.focal_length_px,
    )
    width_ok = width_gate_pass(
        meas_pixel_width,
        track_pixel_w,
        width_cfg.width_meas_std_px,
        width_cfg.width_track_std_px,
        cfg.width_gate_sigma,
    )
    class_ok = class_gate_pass(tr.profile, meas_class_name, cfg.class_match_min_confidence)
    chi2_ok = d2_kin <= cfg.chi2_gate_kin
    return chi2_ok, width_ok, class_ok, float(d2_kin)


def _radar_gate_flags(
    tr: InternalTrack,
    meas_w: float,
    z: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
    cfg: AssociationMetricConfig,
) -> Tuple[bool, bool, float]:
    _, _, d2_kin = radar_kin_innovation(tr, z, R)
    width_ok = width_gate_pass(
        meas_w,
        tr.profile.size_w,
        cfg.width_meas_std,
        cfg.width_track_std,
        cfg.width_gate_sigma,
    )
    chi2_ok = d2_kin <= cfg.chi2_gate_kin
    return chi2_ok, width_ok, float(d2_kin)


def record_vision_gate_failure(
    chi2_ok: bool,
    width_ok: bool,
    class_ok: bool,
) -> str:
    if not class_ok:
        return "class"
    if not width_ok:
        return "width"
    if not chi2_ok:
        return "chi2"
    return "pass"


def record_radar_gate_failure(chi2_ok: bool, width_ok: bool) -> str:
    if not width_ok:
        return "width"
    if not chi2_ok:
        return "chi2"
    return "pass"
