"""匀速平面运动模型。"""

from __future__ import annotations

import numpy as np
import numpy.typing as npt


def cv_F(dt: float) -> npt.NDArray[np.float64]:
    """状态 [x, y, vx, vy]。"""
    dt = float(max(dt, 1e-6))
    return np.array(
        [
            [1.0, 0.0, dt, 0.0],
            [0.0, 1.0, 0.0, dt],
            [0.0, 0.0, 1.0, 0.0],
            [0.0, 0.0, 0.0, 1.0],
        ],
        dtype=np.float64,
    )


def cv_Q(dt: float, q_pos: float, q_vel: float) -> npt.NDArray[np.float64]:
    """过程噪声随 dt 缩放（分段常值白加速度近似）。"""
    dt = float(max(dt, 1e-6))
    q = np.diag(np.asarray([q_pos, q_pos, q_vel, q_vel], dtype=np.float64)) * dt
    return q


def predict_cv(
    mean: npt.NDArray[np.float64],
    cov: npt.NDArray[np.float64],
    dt: float,
    q_pos: float,
    q_vel: float,
) -> tuple[npt.NDArray[np.float64], npt.NDArray[np.float64]]:
    """CV 预测 x_{k|k-1}, P_{k|k-1}。"""
    F = cv_F(dt)
    Q = cv_Q(dt, q_pos, q_vel)
    m = F @ mean
    P = F @ cov @ F.T + Q
    return m, P
