"""视觉 / 雷达几何与测量噪声辅助函数。"""

from __future__ import annotations

import math
from dataclasses import dataclass
from typing import Tuple

import numpy as np
import numpy.typing as npt


@dataclass
class PixelWidthProjectionParams:
    """针孔模型占位；标定时调节 focal_length_px 与 sigma。"""

    focal_length_px: float = 800.0
    width_meas_std_px: float = 12.0
    width_track_std_px: float = 8.0


def profile_width_to_pixel_width(
    distance_m: float,
    width_m: float,
    focal_length_px: float,
) -> float:
    """将剖面物理宽度按距离投影为期望水平像素宽度。

    占位针孔模型：``pixel ≈ f * width / distance``。
    相机内参与畸变后续补充。
    """
    d = max(float(distance_m), 1e-3)
    return float(focal_length_px) * max(float(width_m), 0.0) / d


def distance_size_update_weight(
    distance_m: float,
    ref_distance_m: float,
    min_weight: float,
) -> float:
    """更远目标对 B 态尺寸低通滤波贡献更小（返回值在 [min_weight, 1]）。"""
    d = max(float(distance_m), 1e-3)
    ref = max(float(ref_distance_m), 1e-3)
    return float(np.clip(ref / d, min_weight, 1.0))


def effective_size_lpf_alpha(
    base_alpha: float,
    distance_m: float,
    ref_distance_m: float,
    min_weight: float,
) -> float:
    """按距离缩放剖面低通 alpha — 近处更新快，远处更新慢。"""
    w = distance_size_update_weight(distance_m, ref_distance_m, min_weight)
    return float(np.clip(base_alpha * w, 0.0, 1.0))


def track_planar_distance(mean: npt.NDArray[np.float64]) -> float:
    return float(math.hypot(float(mean[0, 0]), float(mean[1, 0])))


def vision_to_body_xy(
    azimuth_rad: float,
    distance_m: float,
    camera_yaw_rad: float,
    mount_x_m: float,
    mount_y_m: float,
) -> Tuple[float, float]:
    """单目方位角 + 距离 -> 平面船体坐标。"""
    rel_x = distance_m * math.cos(azimuth_rad)
    rel_y = distance_m * math.sin(azimuth_rad)
    cy = camera_yaw_rad
    x_body = mount_x_m + rel_x * math.cos(cy) - rel_y * math.sin(cy)
    y_body = mount_y_m + rel_x * math.sin(cy) + rel_y * math.cos(cy)
    return x_body, y_body


def vision_to_body_polar(
    azimuth_rad: float,
    distance_m: float,
    camera_yaw_rad: float,
    mount_x_m: float,
    mount_y_m: float,
) -> Tuple[float, float, float, float]:
    """单目方位角 + 距离 -> 船体 (x, y) 与船体 (距离, 方位角)。"""
    x_body, y_body = vision_to_body_xy(
        azimuth_rad, distance_m, camera_yaw_rad, mount_x_m, mount_y_m
    )
    r = math.hypot(x_body, y_body)
    bearing = math.atan2(y_body, x_body)
    return x_body, y_body, r, bearing


def mmwave_to_body(
    x: float,
    y: float,
    vx: float,
    vy: float,
    mount_yaw_rad: float,
    mount_x_m: float,
    mount_y_m: float,
) -> Tuple[float, float, float, float]:
    """雷达簇位姿 + 速度变换到船体坐标系。"""
    c = math.cos(mount_yaw_rad)
    s = math.sin(mount_yaw_rad)
    xr = x * c - y * s
    yr = x * s + y * c
    vxr = vx * c - vy * s
    vyr = vx * s + vy * c
    return mount_x_m + xr, mount_y_m + yr, vxr, vyr


def polar_measurement_from_state(
    mean: npt.NDArray[np.float64],
    eps: float = 1e-6,
) -> Tuple[float, float]:
    """由 CV 状态均值预测极坐标测量 h(x) = [r, theta]。"""
    x = float(mean[0, 0])
    y = float(mean[1, 0])
    r = max(math.hypot(x, y), eps)
    theta = math.atan2(y, x)
    return r, theta


def polar_jacobian(
    mean: npt.NDArray[np.float64],
    eps: float = 1e-6,
) -> npt.NDArray[np.float64]:
    """h(x)=[r, theta] 对 [x, y, vx, vy] 的 2×4 雅可比。"""
    x = float(mean[0, 0])
    y = float(mean[1, 0])
    r2 = x * x + y * y
    r = max(math.sqrt(r2), eps)
    r2 = max(r2, eps * eps)
    return np.array(
        [
            [x / r, y / r, 0.0, 0.0],
            [-y / r2, x / r2, 0.0, 0.0],
        ],
        dtype=np.float64,
    )


def wrap_angle_rad(angle: float) -> float:
    """将角度归一化到 [-pi, pi)。"""
    return float((angle + math.pi) % (2.0 * math.pi) - math.pi)


def vision_polar_variance(
    confidence: float,
    sigma_range_m: float,
    sigma_bearing_rad: float,
    conf_scale: float,
) -> Tuple[float, float]:
    """由检测置信度得到距离与方位的 Sigma^2。"""
    c = float(np.clip(confidence, 1e-3, 1.0))
    scale = 1.0 + conf_scale * (1.0 / c - 1.0)
    sr = sigma_range_m * scale
    st = sigma_bearing_rad * scale
    return float(sr * sr), float(st * st)


def radar_position_variance(base_std: float) -> float:
    return float(base_std * base_std)


def radar_velocity_variance(base_std: float, static_inflate: float, is_static: bool) -> float:
    sigma = base_std * (static_inflate if is_static else 1.0)
    return float(sigma * sigma)
