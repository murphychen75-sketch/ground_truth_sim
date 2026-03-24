#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
USV 局部视角多目标跟踪核心大脑 (Multi-Object Tracking Core)
职责: 维系目标生命周期、计算综合代价矩阵执行数据关联(匈牙利最优指派)、基于扩展卡尔曼滤波(EKF)的状态更新。
约束: 纯粹的纯粹数学推演模块，严禁涉及任何 ROS 2 依赖。完全与接口层解耦。
"""

import numpy as np
from scipy.optimize import linear_sum_assignment
from filterpy.kalman import KalmanFilter
import uuid

class Track:
    """
    单目标状态机与滤波器
    维系独立的卡尔曼滤波实例、目标的形态学尺寸以及生命周期的起落
    """
    def __init__(self, detection: dict, sensor_type: str):
        # -------------------------------------------------------------
        # 1. 生命周期初始化
        # -------------------------------------------------------------
        self.id = str(uuid.uuid4())[:8]  # 分配微型 UUID
        self.state = 'Tentative'         # 初始状态: Tentative (试探), Confirmed (确信), Deleted (消亡)
        self.hits = 1                    # 连续命中的有效观测次数
        self.time_since_update = 0       # 距离上一次成功匹配错过了多少帧 (控制消亡)
        self.age = 1                     # 目标存在总帧数

        # 阈值配置
        self.CONFIRM_HITS_THRESHOLD = 3
        self.DELETE_TIME_THRESHOLD = 5

        # -------------------------------------------------------------
        # 2. 形态学状态 (非卡尔曼管理，采用滑动平均 EMA 计算)
        # -------------------------------------------------------------
        self.width = detection.get('width', 0.0)
        self.length = detection.get('length', 0.0)
        self.ema_alpha = 0.8  # EMA 历史保留权重

        # -------------------------------------------------------------
        # 3. 运动学滤波器初始化 (卡尔曼滤波器)
        # 状态向量 X = [x, y, vx, vy]^T (4维)
        # -------------------------------------------------------------
        self.kf = KalmanFilter(dim_x=4, dim_z=4)
        
        # 初始状态向量赋值
        x0 = detection.get('x', 0.0)
        y0 = detection.get('y', 0.0)
        # 如果初始是视觉只有位置，速度默认给0；如果是雷达则赋上被观测初始速度
        vx0 = detection.get('vx', 0.0) if sensor_type == 'mmwave' else 0.0
        vy0 = detection.get('vy', 0.0) if sensor_type == 'mmwave' else 0.0
        
        self.kf.x = np.array([[x0], [y0], [vx0], [vy0]])

        # 初始协方差矩阵 P：如果你是视觉只有坐标没速度，速度的初始不确定性极大 (100)
        self.kf.P = np.array([
            [10.,  0.,   0.,   0.],
            [ 0., 10.,   0.,   0.],
            [ 0.,  0., 100.,   0.],
            [ 0.,  0.,   0., 100.]
        ])

        # 过程噪声协方差矩阵 Q
        # 代表物理模型本身的不可靠程度/系统扰动 (比如船体的加减速变道)
        self.kf.Q = np.array([
            [1.0, 0., 0., 0.],
            [0., 1.0, 0., 0.],
            [0., 0., 5.0, 0.],
            [0., 0., 0., 5.0]
        ])

    def predict(self, dt: float):
        """
        基于时间差推演系统下一刻的状态预测 (Prediction Step)
        """
        # 动态更新状态转移矩阵 F，融入时间变量 dt 进行匀速运动模型(CV模型)的步进
        # [x_new] = [x + vx*dt]
        self.kf.F = np.array([
            [1., 0., dt, 0.],
            [0., 1., 0., dt],
            [0., 0., 1., 0.],
            [0., 0., 0., 1.]
        ])
        
        # 推进卡尔曼预测
        self.kf.predict()
        
        self.age += 1
        self.time_since_update += 1

    def _update_shape_ema(self, new_width: float, new_length: float):
        """ 使用指数滑动平滑算法 (EMA) 缓冲融合船舶长度和宽度的形变波动 """
        if new_width > 0.0:
            self.width = self.ema_alpha * self.width + (1 - self.ema_alpha) * new_width
        if new_length > 0.0:
            self.length = self.ema_alpha * self.length + (1 - self.ema_alpha) * new_length

    def update_radar(self, detection: dict):
        """
        毫米波雷达测量更新：拥有雷达多普勒速度
        检测量 Z = [x, y, vx, vy]^T
        """
        z = np.array([[detection['x']], [detection['y']], [detection['vx']], [detection['vy']]])
        
        # H 矩阵是 4x4 单位矩阵，表示观测向量结构与状态向量一模一样 
        # 即 Z 此时完全映射了 [x, y, vx, vy]^T
        self.kf.H = np.eye(4)
        
        # 观测噪声 R：雷达通常距离精度尚可，但速度存在多普勒跳变情况
        self.kf.R = np.diag([2.0, 2.0, 4.0, 4.0])
        
        # 卡尔曼修正步
        self.kf.update(z)
        
        # 形态学缓冲更新
        self._update_shape_ema(detection.get('width', 0.0), detection.get('length', 0.0))

    def update_vision(self, detection: dict):
        """
        视觉相机测量更新：由于 Filterpy 初始化了 dim_z=4 而视觉只供给2维，
        需主动声明覆写 dim_z=2 再灌入 z=[x, y]^T ，避免矩阵崩塌。
        """
        z = np.array([[detection['x']], [detection['y']]])
        
        # 🌟 关键降维设计：视觉无法直接测量速度！
        # 动态将滤波器的观测维度覆写为2
        self.kf.dim_z = 2
        
        # 量测矩阵 H 为 2x4 的矩形阵，切断并隔离了对速度列的强行映射。
        self.kf.H = np.array([
            [1., 0., 0., 0.],
            [0., 1., 0., 0.]
        ])
        
        # 观测噪声 R：视觉 3D 包围框投影常常受标定与深度的制约跳动剧烈，需给予较大位置容差
        self.kf.R = np.array([
            [5.0,  0.],
            [ 0., 5.0]
        ])
        
        # 卡尔曼修正步
        self.kf.update(z)
        
        # 为了雷达重新能用4维，更新完立即把通道打开
        self.kf.dim_z = 4
        
        self._update_shape_ema(detection.get('width', 0.0), detection.get('length', 0.0))

    def mark_matched(self):
        """ 航迹被成功关联命中，重置漏检计时器并判定是否升权 (确认航迹) """
        self.time_since_update = 0
        self.hits += 1
        if self.state == 'Tentative' and self.hits >= self.CONFIRM_HITS_THRESHOLD:
            self.state = 'Confirmed'

    def mark_missed(self):
        """ 航迹发生漏检游离，处理降权消亡与摘除 """
        if self.time_since_update > self.DELETE_TIME_THRESHOLD:
            self.state = 'Deleted'


class FusionTracker:
    """
    多目标统筹器 (Multi-Object Tracker Master)
    执行代价矩阵构建、波门剪枝以及指派分发。
    """
    def __init__(self):
        self.tracks = []
        
        # Gating 空域门限：超过该距离误差将绝对禁止匹配 (单位: 米)
        self.MAX_KINEMATIC_DISTANCE = 15.0  
        
        # 综合矩阵惩罚权重
        self.WEIGHT_KINEMATIC = 1.0
        self.WEIGHT_SHAPE = 0.5
        
        self.UNMATCHED_COST = 1e5

    def _associate_detections_to_tracks(self, detections: list):
        """
        核心关联逻辑：构建考虑物理距离与实体尺寸的综合代价矩阵，使用匈牙利算法运算。
        """
        if len(self.tracks) == 0:
            return [], [], list(range(len(detections)))
        if len(detections) == 0:
            return [], list(range(len(self.tracks))), []

        # 尺寸: [所有本周期预测结束的现存轨迹数， 本周期刚收到的观测点数]
        cost_matrix = np.zeros((len(self.tracks), len(detections)))

        for t_idx, trk in enumerate(self.tracks):
            # 取出卡尔曼推演后预估的位置
            pred_x, pred_y = trk.kf.x[0, 0], trk.kf.x[1, 0]
            
            for d_idx, det in enumerate(detections):
                # 1. 计算运动学代价 (Kinematic Cost - 纯欧式空间距离)
                # 注：如果要求严丝合缝可以改写成对协方差矩阵求逆算马氏距离
                dist = np.sqrt((pred_x - det['x'])**2 + (pred_y - det['y'])**2)
                
                # 2. 波门强斩 (Gating Filtering)
                # 预估距离误差大得离谱直接封成死路 (设为无穷)，阻止强行飞线匹配产生幽灵航迹
                if dist > self.MAX_KINEMATIC_DISTANCE:
                    cost_matrix[t_idx, d_idx] = self.UNMATCHED_COST
                    continue
                    
                # 3. 计算形态学代价 (Shape/Morphology Cost)
                # 利用刚体固有的尺寸属性去防止由于多船密集交汇产生的 ID 粘连互换
                shape_dist = 0.0
                if 'width' in det and 'length' in det:
                    shape_dist = abs(trk.width - det['width']) + abs(trk.length - det['length'])
                
                # 4. 综合代价合并 
                total_cost = self.WEIGHT_KINEMATIC * dist + self.WEIGHT_SHAPE * shape_dist
                cost_matrix[t_idx, d_idx] = total_cost

        # 5. 匈牙利非二分图匹配算法：针对这一个大型代价矩阵全局寻优寻找代价最小排列组合
        # 返回结果 row_ind 是轨迹的下标数组，col_ind 是对应该分配下的观测下表数组
        row_ind, col_ind = linear_sum_assignment(cost_matrix)

        matches = []
        unmatched_tracks = set(range(len(self.tracks)))
        unmatched_detections = set(range(len(detections)))

        # 6. 后处理校验过滤无效超限点
        for r, c in zip(row_ind, col_ind):
            # 将在指派过程中被迫承受了 UNMATCHED_COST （被强斩或根本匹配不到好对象）的连接丢弃
            if cost_matrix[r, c] >= self.UNMATCHED_COST:
                continue
            matches.append((r, c))
            unmatched_tracks.discard(r)
            unmatched_detections.discard(c)

        return matches, list(unmatched_tracks), list(unmatched_detections)

    def step(self, sensor_type: str, detections: list, dt: float):
        """
        追踪周期的统筹步进驱动器
        参数：
         - sensor_type: 'vision' 或是 'mmwave'，用于通知量测该触发什么模型的更新阵
         - detections: 字典元素的集合列
         - dt: 流逝的时间增量
        """
        # 步骤 1：推演 (Prediction phase)
        for trk in self.tracks:
            trk.predict(dt)
            
        # 步骤 2：数据关联分配 (Association phase)
        matches, unmatched_tracks, unmatched_detections = self._associate_detections_to_tracks(detections)

        # 步骤 3：状态更新 (Update phase)
        for trk_idx, det_idx in matches:
            track = self.tracks[trk_idx]
            det = detections[det_idx]
            
            # 分流选择对应的贝叶斯观测矩阵
            if sensor_type == 'mmwave':
                track.update_radar(det)
            elif sensor_type == 'vision':
                track.update_vision(det)
                
            track.mark_matched()

        # 步骤 4：航迹新生 (Track Generation)
        # 为那些未能匹配到任何既有轨迹池的新鲜探测点，赋予新的生命周期火种
        for d_idx in unmatched_detections:
            new_track = Track(detections[d_idx], sensor_type)
            self.tracks.append(new_track)

        # 步骤 5：航迹消亡 (Track Deletion)
        # 不存在匹配目标的落单轨迹给予游离惩罚，并清理垃圾收集池
        for t_idx in unmatched_tracks:
            self.tracks[t_idx].mark_missed()

        # 最后清理筛选所有状态转为 'Deleted' 的作废航迹对象
        self.tracks = [trk for trk in self.tracks if trk.state != 'Deleted']
        
        # 这里你可以选择返回全部或者仅 'Confirmed' 稳定态的航迹
        return [trk for trk in self.tracks if trk.state == 'Confirmed']
