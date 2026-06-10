"""单帧 JPDA：在门控 (航迹, 测量) 对上枚举可行联合假设。

对每个判为杂波的测量使用泊松杂波因子 ``lambda_clutter``（可调标量强度）。
检测概率 ``P_D`` 作用于每条航迹。

若假设枚举超过 ``max_hypotheses``，返回 None 以便回退（匈牙利）。
"""

from __future__ import annotations

from typing import List, Optional, Tuple

import numpy as np
import numpy.typing as npt


def log_mvnormal_pdf(z: npt.NDArray[np.float64], mean_z: npt.NDArray[np.float64], S: npt.NDArray[np.float64]) -> float:
    """log N(z; mean_z, S)。"""
    nu = z - mean_z
    d = int(nu.shape[0])
    sign, logdet = np.linalg.slogdet(S)
    if sign <= 0 or not np.isfinite(logdet):
        return -1e300
    Si = np.linalg.inv(S)
    v = nu.flatten()
    quad = float(v @ Si @ v)
    return float(-0.5 * (quad + logdet + d * np.log(2.0 * np.pi)))


def _count_hypotheses_dfs(gate: npt.NDArray[np.bool_], nt: int, nm: int, max_h: int) -> int:
    """统计可行分配 meas -> track|-1（杂波）；超过 max_h 则中止。"""

    cnt = 0

    def dfs(j: int, used: List[bool]) -> None:
        nonlocal cnt
        if cnt >= max_h:
            return
        if j == nm:
            cnt += 1
            return
        dfs(j + 1, used)
        if cnt >= max_h:
            return
        for i in range(nt):
            if gate[i, j] and not used[i]:
                used[i] = True
                dfs(j + 1, used)
                used[i] = False
                if cnt >= max_h:
                    return

    dfs(0, [False] * nt)
    return cnt


def enumerate_hypotheses_log_weights(
    gate: npt.NDArray[np.bool_],
    nt: int,
    nm: int,
    log_L: npt.NDArray[np.float64],
    P_D: float,
    log_lambda_clutter: float,
    log_one_minus_PD: float,
    max_hypotheses: int,
) -> Optional[Tuple[List[Tuple[int, ...]], npt.NDArray[np.float64]]]:
    """枚举分配元组 ``assign[j]`` ∈ {-1,0..nt-1}；返回对数未归一化权重。"""

    hypotheses: List[Tuple[int, ...]] = []
    log_ws: List[float] = []

    def log_w_for_hypothesis(a: Tuple[int, ...]) -> float:
        lw = 0.0
        used = [False] * nt
        for j in range(nm):
            aj = int(a[j])
            if aj >= 0:
                if used[aj]:
                    return -np.inf
                used[aj] = True
                lw += np.log(P_D) + log_L[aj, j]
            else:
                lw += log_lambda_clutter
        for i in range(nt):
            if not used[i]:
                lw += log_one_minus_PD
        return lw

    def dfs(j: int, used: List[bool], cur: List[int]) -> None:
        if len(hypotheses) >= max_hypotheses:
            return
        if j == nm:
            tup = tuple(cur)
            hypotheses.append(tup)
            log_ws.append(log_w_for_hypothesis(tup))
            return
        cur.append(-1)
        dfs(j + 1, used, cur)
        cur.pop()
        if len(hypotheses) >= max_hypotheses:
            return
        for i in range(nt):
            if gate[i, j] and not used[i]:
                used[i] = True
                cur.append(i)
                dfs(j + 1, used, cur)
                cur.pop()
                used[i] = False
                if len(hypotheses) >= max_hypotheses:
                    return

    dfs(0, [False] * nt, [])
    if not hypotheses:
        return None
    arr = np.array(log_ws, dtype=np.float64)
    return hypotheses, arr


def softmax(log_w: npt.NDArray[np.float64]) -> npt.NDArray[np.float64]:
    m = float(np.max(log_w))
    ex = np.exp(np.clip(log_w - m, -80.0, 80.0))
    s = float(np.sum(ex))
    if s <= 0 or not np.isfinite(s):
        n = len(log_w)
        return np.ones(n, dtype=np.float64) / float(max(n, 1))
    return ex / s


def jpda_track_betas_and_meas_marginals(
    gate: npt.NDArray[np.bool_],
    zs: List[npt.NDArray[np.float64]],
    z_hat_track: List[npt.NDArray[np.float64]],
    S_pair: List[List[npt.NDArray[np.float64]]],
    P_D: float,
    lambda_clutter: float,
    max_hypotheses: int,
) -> Optional[Tuple[npt.NDArray[np.float64], npt.NDArray[np.float64]]]:
    """枚举成功时返回 ``(beta_track, P_meas_track)``。

    ``beta_track`` 形状 ``(nt, nm + 1)``：第 0 列为漏检；第 1..nm 列为测量 0..nm-1。

    ``P_meas_track`` 形状 ``(nt, nm)``：边缘概率 P(测量 j 分配给航迹 i)。

    ``z_hat_track[i]`` 为预测测量 H x_hat_i（对所有 j 相同）；``S_pair[i][j]`` 为 S_ij。
    """
    nt = len(z_hat_track)
    nm = len(zs)
    if nm == 0 or nt == 0:
        return None

    log_L = np.full((nt, nm), -np.inf, dtype=np.float64)
    for i in range(nt):
        for j in range(nm):
            if gate[i, j]:
                log_L[i, j] = log_mvnormal_pdf(zs[j], z_hat_track[i], S_pair[i][j])

    log_lambda_clutter = float(np.log(max(lambda_clutter, 1e-300)))
    log_one_minus_PD = float(np.log(max(1.0 - P_D, 1e-300)))

    hc = _count_hypotheses_dfs(gate, int(nt), int(nm), max_hypotheses + 1)
    if hc > max_hypotheses:
        return None

    enum = enumerate_hypotheses_log_weights(
        gate, int(nt), int(nm), log_L, float(P_D), log_lambda_clutter, log_one_minus_PD, max_hypotheses
    )
    if enum is None:
        return None
    hypotheses, log_ws = enum
    prob_h = softmax(log_ws)

    beta_track = np.zeros((nt, nm + 1), dtype=np.float64)
    P_mt = np.zeros((nt, nm), dtype=np.float64)

    for hi, hprob in enumerate(prob_h):
        a = hypotheses[hi]
        used = [False] * nt
        for j in range(nm):
            aj = int(a[j])
            if aj >= 0:
                used[aj] = True
                beta_track[aj, j + 1] += hprob
                P_mt[aj, j] += hprob
        for i in range(nt):
            if not used[i]:
                beta_track[i, 0] += hprob

    # 对 beta_track 各行归一化（数值稳定性）
    for i in range(nt):
        s = float(np.sum(beta_track[i, :]))
        if s > 1e-15:
            beta_track[i, :] /= s

    return beta_track, P_mt
