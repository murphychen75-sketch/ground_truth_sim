#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Level 1: Local Fusion Node (局部感知层 - 分布式融合节点)
角色: USV 高并发多传感器融合系统 (Multi-Process Distributed Architecture) 骨干组件。
描述: 完全独立的单向局部视图进程。负责时间同步、空间外参降维变换映射、以及驱动外挂的多目标跟踪器 (MOT)。
"""

import math
import rclpy
from rclpy.node import Node
from rclpy.time import Time
from rclpy.duration import Duration
import message_filters
from tf2_ros import Buffer, TransformListener
from tf2_ros import LookupException, ConnectivityException, ExtrapolationException

# =========================================================================
# 实际环境接口消息强类型定义
# =========================================================================
from usv_interfaces.msg import VisionDetectionArray, MmwaveTargetArray
# 因为系统中不存在专用的 LocalTrackArray，复用系统级的 GlobalTrackArray 作为 T2T 数据通道格式
from usv_interfaces.msg import GlobalTrackArray, GlobalTrack

# =========================================================================
# 导入核心算法解耦层
# =========================================================================
from .tracker import FusionTracker

class LocalFusionNode(Node):
    def __init__(self):
        # 节点名称带有随机性并不是必须的，因为在 Launch 文件中会指定 node_name。
        # 默认命名，实际运行时通常由 Launch 系统覆写为 local_fusion_front 等。
        super().__init__('local_fusion_node')
        
        # ----------------------------------------------------
        # 1. 参数化实例化 (Parameterization)
        # ----------------------------------------------------
        # 声明并读取方向参数、同步容忍度参数
        self.declare_parameter('direction', 'front')
        self.declare_parameter('sync_slop', 0.1)
        
        self.direction = self.get_parameter('direction').get_parameter_value().string_value
        self.sync_slop = self.get_parameter('sync_slop').get_parameter_value().double_value
        
        self.get_logger().info(f"🚀 初始化 Level 1: 局部感知层进程启动 [{self.direction.upper()}] ...")
        
        # 实例化完全解耦的内部 Tracker (将复杂数学推导隔离)
        self.tracker = FusionTracker()
        
        # ----------------------------------------------------
        # 2. Topic 动态拼接 (Dynamic Topic Binding)
        # ----------------------------------------------------
        vision_topic = f'/vision/{self.direction}/detections'
        mmwave_topic = f'/mmwave/{self.direction}/targets'
        publish_topic = f'/fusion/local/{self.direction}_tracks'
        
        # ----------------------------------------------------
        # 3. 基础依赖初始化 (TF2 与时间管理)
        # ----------------------------------------------------
        # 缓存时间设为 10 秒
        self.tf_buffer = Buffer(Duration(seconds=10.0))
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.last_sync_time = None
        
        # ----------------------------------------------------
        # 4. 基于 message_filters 的局部同步机制 (Local Sync)
        # ----------------------------------------------------
        # 这里必须使用具有 header.stamp 的消息类型才能完成 approximate time sync
        self.sub_vision = message_filters.Subscriber(self, VisionDetectionArray, vision_topic)
        self.sub_mmwave = message_filters.Subscriber(self, MmwaveTargetArray, mmwave_topic)
        
        # 队列深度设为 20，容差为定义的 sync_slop
        self.ts = message_filters.ApproximateTimeSynchronizer(
            [self.sub_vision, self.sub_mmwave], 
            queue_size=20, 
            slop=self.sync_slop
        )
        self.ts.registerCallback(self.sync_callback)

        # 发布提纯后的局部航迹 (这里通过复用 GlobalTrackArray 类型来承载 Local 级追踪数据)
        self.track_pub = self.create_publisher(GlobalTrackArray, publish_topic, 10)
        self.get_logger().info(f"🔗 同步器已连接: Vision({vision_topic}) + Radar({mmwave_topic}) -> 容错: {self.sync_slop}s")

    def _transform_to_base_link(self, target_msg, target_frame: str):
        """
        利用 TF 树，将目标从所在传感器坐标系强转到船体本体系 (base_link)，
        并且按照需求进行系统级的 Z 轴归零降维 (扁平化)。
        """
        try:
            # 查找从 base_link 到 传感器坐标系 的最新 TF 变换
            trans = self.tf_buffer.lookup_transform(
                'base_link', 
                target_frame, 
                Time() # 获取最新有效的 TF
            )
            
            # 使用四元数速算转换 Yaw 偏航角 (只关注 2D 平面旋转)
            q = trans.transform.rotation
            yaw = math.atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))
            
            # 考虑传感器本身的安装平移 (x, y); Z 忽略
            tx = trans.transform.translation.x
            ty = trans.transform.translation.y
            
            # 在 2D 平面上应用点旋转加上传感器外参平移
            # 假设 target_msg 存在 x, y 属性表示其在局部坐标系的坐标
            base_x = tx + target_msg.x * math.cos(yaw) - target_msg.y * math.sin(yaw)
            base_y = ty + target_msg.x * math.sin(yaw) + target_msg.y * math.cos(yaw)
            
            return base_x, base_y
            
        except (LookupException, ConnectivityException, ExtrapolationException) as e:
            self.get_logger().warn(f"[{self.direction}] TF 转换失败 `{target_frame}` -> `base_link`: {e}", throttle_duration_sec=2.0)
            return None, None

    def sync_callback(self, vision_msg, mmwave_msg):
        """
        局部时间同步触发回调。执行空间坐标对齐并喂给 Tracker。
        """
        current_time = self.get_clock().now()
        
        # 1. 计算极微小的时间差 dt
        if self.last_sync_time is None:
            self.last_sync_time = current_time
            return
            
        dt = (current_time - self.last_sync_time).nanoseconds / 1e9
        self.last_sync_time = current_time
        
        # 保证系统的鲁棒性：极偶尔因系统调度出现负时间跳变的情况
        if dt <= 0.0:
            return

        vision_detections = []
        mmwave_detections = []
        
        # ----------------------------------------------------
        # 2. 解析视觉信息 (空间转换 + 形态学提取)
        # ----------------------------------------------------
        vision_frame = vision_msg.header.frame_id
        for det in vision_msg.detections:
            # 视觉没有 x, y，而是 distance_predict 和 azimuth
            # 需要先将其转化为局部笛卡尔坐标，再扔给外参转换
            # 极坐标向传感器局部笛卡尔系的映射 (沿相机前向为 X，左侧为 Y)：
            local_x = det.distance_predict * math.cos(det.azimuth)
            local_y = det.distance_predict * math.sin(det.azimuth)
            mock_vision = type('MockVision', (), {'x': local_x, 'y': local_y})

            base_x, base_y = self._transform_to_base_link(mock_vision, vision_frame)
            if base_x is not None:
                vision_detections.append({
                    'x': base_x,
                    'y': base_y,
                    'z': 0.0,
                    'width': getattr(det, 'size_w', 0.0),
                    'length': getattr(det, 'size_h', 0.0) # 将高度近似理解为边界长
                })

        # ----------------------------------------------------
        # 3. 解析毫米波雷达信息 (空间转换 + 形态学提取)
        # ----------------------------------------------------
        radar_frame = mmwave_msg.header.frame_id if hasattr(mmwave_msg, 'header') else f"mmwave_{self.direction}_link"
        for target in mmwave_msg.targets:
            # MmwaveTarget 消息定义的字段是 x 和 y，速度是 v_x 和 v_y
            mock_target = type('MockTarget', (), {'x': getattr(target, 'x', 0.0), 'y': getattr(target, 'y', 0.0)})
            base_x, base_y = self._transform_to_base_link(mock_target, radar_frame)
            
            if base_x is not None:
                # v_x 和 v_y 也需要根据坐标系转换（忽略角速度，仅做平面旋转）
                try:
                    trans = self.tf_buffer.lookup_transform('base_link', radar_frame, Time())
                    q = trans.transform.rotation
                    yaw = math.atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))
                    vx_local = getattr(target, 'v_x', 0.0)
                    vy_local = getattr(target, 'v_y', 0.0)
                    base_vx = vx_local * math.cos(yaw) - vy_local * math.sin(yaw)
                    base_vy = vx_local * math.sin(yaw) + vy_local * math.cos(yaw)
                except Exception:
                    base_vx, base_vy = 0.0, 0.0

                mmwave_detections.append({
                    'x': base_x,
                    'y': base_y,
                    'z': 0.0,
                    'vx': base_vx,
                    'vy': base_vy,
                    'width': getattr(target, 'size_w', 0.0),
                    'length': getattr(target, 'size_l', 0.0)
                })

        # ----------------------------------------------------
        # 4. 执行局部的单步时序更新 (驱动状态机)
        # ----------------------------------------------------
        # 级联修正：先用带有时间差(dt)的视觉信息推进行星步长并作位置校准
        self.tracker.step('vision', vision_detections, dt)
        
        # 再用流逝时间(0.0)的雷达信息进行同频率切片内的多普勒速度及距离强迫修正
        active_tracks = self.tracker.step('mmwave', mmwave_detections, 0.0)
        
        # ----------------------------------------------------
        # 5. 发布 Level 1 结构化数据 (给全局 Level 2 进程订阅)
        # ----------------------------------------------------
        # 利用复用的系统级 msg 协议打包装箱
        msg_out = GlobalTrackArray()
        msg_out.header.stamp = current_time.to_msg()
        msg_out.header.frame_id = 'base_link'
        
        for trk in active_tracks:
            out_t = GlobalTrack()
            # 内部追踪器的短 UUID 为 16 进制字符串，强制哈希后截断装入 uint32
            out_t.track_id = int(str(trk.id), 16) % 1000000
            
            # KF 核心状态数组打平： [x, y, v_x, v_y]^T
            kf_state = trk.kf.x.flatten()
            out_t.x = float(kf_state[0])
            out_t.y = float(kf_state[1])
            out_t.v_x = float(kf_state[2])
            out_t.v_y = float(kf_state[3])
            
            msg_out.tracks.append(out_t)
            
        self.track_pub.publish(msg_out)


def main(args=None):
    rclpy.init(args=args)
    node = LocalFusionNode()
    
    # 使用 MultiThreadedExecutor 可在内部激活更高频的 TF 队列消费表现，但鉴于已经是单视野独立进程，默认执行器也可。
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Local fusion node stopped cleanly')
    except Exception as e:
        node.get_logger().error(f'Error in local fusion node: {e}')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
