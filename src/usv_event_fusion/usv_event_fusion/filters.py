"""EKF 更新辅助（线性与极坐标高斯测量模型）。"""

from __future__ import annotations

from typing import List, Tuple

import numpy as np
import numpy.typing as npt

from usv_event_fusion.sensor_models import (
    polar_jacobian,
    polar_measurement_from_state,
    wrap_angle_rad,
)


def ekf_update_linear(
    mean: npt.NDArray[np.float64],
    cov: npt.NDArray[np.float64],
    z: npt.NDArray[np.float64],
    H: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
) -> tuple[npt.NDArray[np.float64], npt.NDArray[np.float64]]:
    """Joseph 形式协方差更新。"""
    S = H @ cov @ H.T + R
    K = cov @ H.T @ np.linalg.inv(S)
    nu = z - H @ mean
    mean_new = mean + K @ nu
    I = np.eye(mean.shape[0], dtype=np.float64)
    IKH = I - K @ H
    cov_new = IKH @ cov @ IKH.T + K @ R @ K.T
    return mean_new, cov_new


def ekf_update_polar(
    mean: npt.NDArray[np.float64],
    cov: npt.NDArray[np.float64],
    z_polar: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
) -> tuple[npt.NDArray[np.float64], npt.NDArray[np.float64]]:
    """Joseph 形式 EKF 更新，测量模型 h(x)=[r, theta]。"""
    H = polar_jacobian(mean)
    r_hat, theta_hat = polar_measurement_from_state(mean)
    z_pred = np.array([[r_hat], [theta_hat]], dtype=np.float64)
    nu = z_polar - z_pred
    nu[1, 0] = wrap_angle_rad(float(nu[1, 0]))
    return ekf_update_linear(mean, cov, z_polar, H, R)


def innovation_covariance(
    cov: npt.NDArray[np.float64],
    H: npt.NDArray[np.float64],
    R: npt.NDArray[np.float64],
) -> npt.NDArray[np.float64]:
    """S = H P H^T + R。"""
    return H @ cov @ H.T + R


def polar_innovation(
    mean: npt.NDArray[np.float64],
    z_polar: npt.NDArray[np.float64],
) -> Tuple[npt.NDArray[np.float64], npt.NDArray[np.float64]]:
    """极坐标测量的新息 nu 与雅可比 H。"""
    H = polar_jacobian(mean)
    r_hat, theta_hat = polar_measurement_from_state(mean)
    z_pred = np.array([[r_hat], [theta_hat]], dtype=np.float64)
    nu = z_polar - z_pred
    nu[1, 0] = wrap_angle_rad(float(nu[1, 0]))
    return nu, H


def mahalanobis_squared(
    nu: npt.NDArray[np.float64],
    S: npt.NDArray[np.float64],
) -> float:
    """nu^T S^{-1} nu。"""
    Si = np.linalg.inv(S)
    v = nu.flatten()
    return float(v @ Si @ v)


def jpda_pdaf_update(
    mean: npt.NDArray[np.float64],
    P: npt.NDArray[np.float64],
    H: npt.NDArray[np.float64],
    zs: List[npt.NDArray[np.float64]],
    Rs: List[npt.NDArray[np.float64]],
    beta_row: npt.NDArray[np.float64],
) -> tuple[npt.NDArray[np.float64], npt.NDArray[np.float64]]:
    """PDAF 风格混合更新；``beta_row`` 长度 ``m+1``，``beta_row[0]`` 为漏检。"""
    m = len(zs)
    nu_list: List[npt.NDArray[np.float64]] = []
    K_list: List[npt.NDArray[np.float64]] = []
    for j in range(m):
        Rj = Rs[j]
        S = H @ P @ H.T + Rj
        K = P @ H.T @ np.linalg.inv(S)
        nu = zs[j] - H @ mean
        nu_list.append(nu)
        K_list.append(K)

    nu_bar = np.zeros_like(mean)
    for j in range(m):
        nu_bar += float(beta_row[j + 1]) * (K_list[j] @ nu_list[j])
    mean_new = mean + nu_bar

    d = int(mean.shape[0])
    I = np.eye(d, dtype=np.float64)
    P_new = float(beta_row[0]) * P
    for j in range(m):
        Kj = K_list[j]
        Rj = Rs[j]
        IKH = I - Kj @ H
        Pj = IKH @ P @ IKH.T + Kj @ Rj @ Kj.T
        P_new += float(beta_row[j + 1]) * Pj
    P_new -= nu_bar @ nu_bar.T
    return mean_new, P_new


def jpda_pdaf_update_polar(
    mean: npt.NDArray[np.float64],
    P: npt.NDArray[np.float64],
    zs: List[npt.NDArray[np.float64]],
    Rs: List[npt.NDArray[np.float64]],
    beta_row: npt.NDArray[np.float64],
) -> tuple[npt.NDArray[np.float64], npt.NDArray[np.float64]]:
    """按测量分别使用极坐标雅可比的 PDAF 混合更新。"""
    m = len(zs)
    nu_list: List[npt.NDArray[np.float64]] = []
    K_list: List[npt.NDArray[np.float64]] = []
    for j in range(m):
        nu_j, H_j = polar_innovation(mean, zs[j])
        S = H_j @ P @ H_j.T + Rs[j]
        K = P @ H_j.T @ np.linalg.inv(S)
        nu_list.append(nu_j)
        K_list.append(K)

    nu_bar = np.zeros_like(mean)
    for j in range(m):
        nu_bar += float(beta_row[j + 1]) * (K_list[j] @ nu_list[j])
    mean_new = mean + nu_bar

    d = int(mean.shape[0])
    I = np.eye(d, dtype=np.float64)
    P_new = float(beta_row[0]) * P
    for j in range(m):
        _, H_j = polar_innovation(mean, zs[j])
        Kj = K_list[j]
        Rj = Rs[j]
        IKH = I - Kj @ H_j
        Pj = IKH @ P @ IKH.T + Kj @ Rj @ Kj.T
        P_new += float(beta_row[j + 1]) * Pj
    P_new -= nu_bar @ nu_bar.T
    return mean_new, P_new
