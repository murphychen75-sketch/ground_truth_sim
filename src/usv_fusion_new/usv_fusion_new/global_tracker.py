#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
USV 全局认知层航迹融合大脑 (Global Track-to-Track Tracker)
职责: 接收局部融合节点 (Local Tracks) 的高纯度航迹，执行全局级的数据关联与卡尔曼平滑更新。
核心特性: 
  1. 通过统一的 base_link 坐标系，纯数学隐式实现【跨盲区目标交接 (ID Handover)】。
  2. "Track as Measurement" - 将局部航迹视作高质量量测，融合入全局状态机。
约束: 纯粹的数学推演模块，严禁任何 ROS 2 依赖。
"""

import numpy as np
from scipy.optimize import linear_sum_assignment
from filterpy.kalman import KalmanFilter

class GlobalTrack:
    """
    单体全局目标状态机
    维系全局唯一的跟踪实体，融合多方局部航迹的观测结果。
    """
    def __init__(self, local_track_data: dict, source: str, global_id: int):
        # -------------------------------------------------------------
        # 1. 生命周期与身份元数据
        # -------------------------------------------------------------
        self.global_id = f"G-{global_id:04d}" # 赋予全集唯一且递增的 ID (e.g., G-0001)
        self.state = 'Tentative'              # 初始状态: Tentative (试探), Confirmed (确信), Coasted (滑行/保留), Deleted (消亡)
        
        self.hits = 1                         # 累计成功关联的次数
        self.time_since_update = 0            # 距离上一次成功更新的流逝步数 (Age for death)
        self.age = 1                          # 航迹存在总寿命
        
        # -------------------------------------------------------------
        # 历史轨迹缓存机制 (History Trajectory Cache)
        # -------------------------------------------------------------
        self.MAX_HISTORY_LENGTH = 50          # 保存的最大历史点数量（可调）
        # 每个元素存储为一个字典: {'x': float, 'y': float, 'vx': float, 'vy': float, 'time': float}
        self.history = []                     

        # 全局航迹的生命周期容忍度需要更高，因为异步调度和视野跨越可能带来短暂中断
        self.CONFIRM_HITS_THRESHOLD = 3
        self.DELETE_TIME_THRESHOLD = 15       # 容忍丢失帧数可适当放大，实现平滑滑行 (Coasting)

        # -------------------------------------------------------------
        # 2. 形态学状态 (滑动平均平滑)
        # -------------------------------------------------------------
        self.width = local_track_data.get('width', 0.0)
        self.length = local_track_data.get('length', 0.0)
        self.ema_alpha = 0.85 # EMA 历史保留权重，全局应更稳健

        # -------------------------------------------------------------
        # 3. 运动学滤波器初始化 (标准卡尔曼滤波)
        # 状态向量 X = [x, y, vx, vy]^T (4维)
        # -------------------------------------------------------------
        self.kf = KalmanFilter(dim_x=4, dim_z=4)
        
        # 将传入的局部航迹数据初始化给全局滤波器
        x0  = local_track_data.get('x', 0.0)
        y0  = local_track_data.get('y', 0.0)
        vx0 = local_track_data.get('vx', 0.0)
        vy0 = local_track_data.get('vy', 0.0)
        self.kf.x = np.array([[x0], [y0], [vx0], [vy0]])

        # 协方差矩阵 P：由于输入已经是提纯过的局部航迹，初始信任度可以给高一点(方差设小)
        self.kf.P = np.diag([2.0, 2.0, 5.0, 5.0])

        # 过程噪声结构 Q：代表由于海浪、船只加减速引起的自身运动不确定度
        self.kf.Q = np.diag([0.5, 0.5, 1.0, 1.0])

        # 【核心理念】：Track as Measurement
        # 对于 Track-to-Track 融合，底层的输入不再是残缺的原始像素或点云
        # 而是包含了完整坐标与速度的优良估计 [x, y, v_x, v_y]
        # 因此，全局量测矩阵 H 为 4x4 标准单位阵，全要素映射！
        self.kf.H = np.eye(4)

    def predict(self, dt: float):
        """
        基于全局流逝的时间差(dt)推演状态 (Prediction Step)
        """
        if dt > 0:
            # 根据真实 dt 构建匀速 (CV) 模型的步进状态转移矩阵 F
            self.kf.F = np.array([
                [1., 0., dt, 0.],
                [0., 1., 0., dt],
                [0., 0., 1., 0.],
                [0., 0., 0., 1.]
            ])
            self.kf.predict()
            
            # 由于推演改变了当前状态机位置，可以将纯推演/滑行的轨迹同样录入历史或等 update
            # 一般来说纯预测点不加入最终发布用的确认缓存，除非需要在画面里画虚线
            
        self.age += 1
        # 推演时自行衰减健康度，必须由后续的 mark_matched 来拯救
        self.time_since_update += 1
        
        # 引入 Coasted (滑行) 状态机制
        if self.state == 'Confirmed' and self.time_since_update > 2:
            self.state = 'Coasted'

    def update(self, local_track_data: dict, source: str):
        """
        全局吸收合并与更新 (Track-to-Track Fusion Update)
        参数 source 决定了我们在这个周期应该采用多大的观测宽容度 (R 阵)。
        """
        # 构建当前量测列向量 Z = [x, y, vx, vy]^T
        z = np.array([
            [local_track_data.get('x', 0.0)], 
            [local_track_data.get('y', 0.0)], 
            [local_track_data.get('vx', 0.0)], 
            [local_track_data.get('vy', 0.0)]
        ])
        
        # 🌟 动态量测噪声 R：根据来源等级实现异构数据置信度的平衡 🌟
        if source == 'nav_radar':
            # 导航雷达 (nav_radar): 扫频慢(1Hz)，距离远，信噪比一般。因此给予其较大的 R (较低置信度)
            # 意味着它的输入主要是用来兜底，卡尔曼会自动给予它较小的更新增益 (Kalman Gain)
            self.kf.R = np.diag([4.0, 4.0, 8.0, 8.0])
        else:
            # 局部融合视野 (front, rear, left, right): 
            # 它们是 4D毫米波雷达+相机高频高速(30Hz)联合输出的精华，拥有极高的精准度。且给较小方差。
            self.kf.R = np.diag([1.0, 1.0, 2.0, 2.0])
            
        self.kf.update(z)
        
        # 尺寸的滑动平均 (EMA) 并击更新
        new_w = local_track_data.get('width', 0.0)
        new_l = local_track_data.get('length', 0.0)
        if new_w > 0: self.width = self.ema_alpha * self.width + (1 - self.ema_alpha) * new_w
        if new_l > 0: self.length = self.ema_alpha * self.length + (1 - self.ema_alpha) * new_l

    def mark_matched(self, current_time: float):
        """目标成功续命，执行历史快照缓存并且重置超时判定"""
        self.time_since_update = 0
        self.hits += 1
        
        # 提取被修正后最新鲜的高纯度状态
        current_state = self.kf.x.flatten()
        self.history.append({
            'time': current_time,
            'x': float(current_state[0]),
            'y': float(current_state[1]),
            'vx': float(current_state[2]),
            'vy': float(current_state[3])
        })
        
        # 维持滑动窗口，裁切掉过于年代久远的历史尾巴避免爆显存
        if len(self.history) > self.MAX_HISTORY_LENGTH:
            self.history.pop(0)

        # 从 Tentative 或 Coasted 状态转为绝对的确信活跃状态
        if self.hits >= self.CONFIRM_HITS_THRESHOLD:
            self.state = 'Confirmed'

    def mark_missed(self):
        """
        （作为外部主动干预漏检的接口保留，但由于 time_since_update 在 predict 已自增，此处主要用于死线判定）
        """
        if self.time_since_update > self.DELETE_TIME_THRESHOLD:
            self.state = 'Deleted'


class GlobalTracker:
    """
    跨盲区数据关联全局统筹器 (Global Tracker Master)
    执行多端聚合寻优，隐式完成跨视野 ID 接手。
    """
    def __init__(self):
        self.global_tracks = []
        self.global_id_counter = 1
        
        # 全局空域的惩罚极大值 (波门范围外)
        self.UNMATCHED_COST = 1e5
        # 允许最大吸纳绑定的欧氏距离波动范围。
        # 由于局部航迹本身就很准，这里的阈值可稍微设紧凑防止飞线。
        self.MAX_KINEMATIC_DISTANCE = 8.0

    def _associate(self, local_tracks: list):
        """
        核心综合代价关联：
        输入是若干 local_tracks (字典)，需要分配到已有的 self.global_tracks 中去
        """
        if len(self.global_tracks) == 0:
            return [], [], list(range(len(local_tracks)))
        if len(local_tracks) == 0:
            return [], list(range(len(self.global_tracks))), []

        cost_matrix = np.zeros((len(self.global_tracks), len(local_tracks)))

        for r, g_trk in enumerate(self.global_tracks):
            g_x, g_y = g_trk.kf.x[0, 0], g_trk.kf.x[1, 0]
            g_vx, g_vy = g_trk.kf.x[2, 0], g_trk.kf.x[3, 0]
            
            for c, l_trk in enumerate(local_tracks):
                l_x = l_trk.get('x', 0.0)
                l_y = l_trk.get('y', 0.0)
                l_vx = l_trk.get('vx', 0.0)
                l_vy = l_trk.get('vy', 0.0)
                
                # 1. 运动学代价: 位置欧氏距离为主，速度差异轻微辅助 (减少速度噪音导致的矩阵震荡)
                dist_pos = np.hypot(g_x - l_x, g_y - l_y)
                dist_vel = np.hypot(g_vx - l_vx, g_vy - l_vy)
                c_kinematic = dist_pos + 0.2 * dist_vel
                
                # 波门强斩 Gating
                if dist_pos > self.MAX_KINEMATIC_DISTANCE:
                    cost_matrix[r, c] = self.UNMATCHED_COST
                    continue
                    
                # 2. 形态学代价: 目标体积/尺寸差值
                # (这里如果缺乏尺寸，默认为0即可，不会产生过大惩罚)
                c_shape = abs(g_trk.width - l_trk.get('width', 0.0)) + abs(g_trk.length - l_trk.get('length', 0.0))
                
                # 3. 融合总代价计算矩阵
                cost_matrix[r, c] = c_kinematic + 0.5 * c_shape

        # 执行匈牙利最优解指派
        row_ind, col_ind = linear_sum_assignment(cost_matrix)

        matches = []
        unmatched_globals = set(range(len(self.global_tracks)))
        unmatched_locals = set(range(len(local_tracks)))

        for r, c in zip(row_ind, col_ind):
            # 将在指派组合中不得不吃下极大惩罚(无法满足波门)的匹配拆散
            if cost_matrix[r, c] >= self.UNMATCHED_COST:
                continue
            matches.append((r, c))
            unmatched_globals.discard(r)
            unmatched_locals.discard(c)

        return matches, list(unmatched_globals), list(unmatched_locals)

    def step(self, source: str, tracks: list, dt: float, current_time: float):
        """
        全局 T2T 事件的驱动枢纽
        :param source: 'front', 'rear', 'left', 'right', 或 'nav_radar'
        :param tracks: 来自该源的包含目标要素的字典数组
        :param dt: 距离全局系统上一次调用的流逝时间
        :param current_time: 用标定历史航迹序列的系统秒
        """
        
        # 步骤 1：时间推演 (不管谁发的数据，只要时间往前走了，所有池子里的航迹必须往前预测物理步)
        if dt > 0.0:
            for g_trk in self.global_tracks:
                g_trk.predict(dt)
                
        # 步骤 2 & 3：执行代价构建与匈牙利统筹分配
        # 💥【跨盲区目标交接 (ID Handover) 生效区】💥
        # 在此步由于所有的输入源（不论前后左右）事先都投射在同一个 base_link 大地毯上。
        # 它的空间重叠导致同个物理船会在极小的运动学代价下，被自动接管进本该是本目标对象的池子里，
        # 原本地理区域的源丢失了并无大碍，因为来自新盲区的观测接替了 update，并重新执行了 mark_matched!
        matches, unmatched_globals, unmatched_locals = self._associate(tracks)

        # 步骤 4：分配后状态翻新流转
        for g_idx, l_idx in matches:
            # 命中的航迹被对应的源结构注入刷新
            self.global_tracks[g_idx].update(tracks[l_idx], source)
            self.global_tracks[g_idx].mark_matched(current_time)

        # 对于全局来说，只有彻底未被任何盲区观测囊括的“全新点”才配得上获得全局新 ID
        for l_idx in unmatched_locals:
            new_g_track = GlobalTrack(
                local_track_data=tracks[l_idx], 
                source=source, 
                global_id=self.global_id_counter
            )
            # 首次创立也执行一次强制命中留底
            new_g_track.mark_matched(current_time)
            self.global_tracks.append(new_g_track)
            self.global_id_counter += 1

        # 步骤 5：死线管理 (消亡判决)
        # 注意：在此设计下由于 time_since_update 已经在 predict 阶段自增过了。
        # 这里只做阈值剔除判定。不采用主动递增惩罚，避免左侧相机进入数据时强行惩罚了右侧还存活的船。
        for g_trk in self.global_tracks:
            g_trk.mark_missed()
            
        # GC回收无用队列
        self.global_tracks = [t for t in self.global_tracks if t.state != 'Deleted']
