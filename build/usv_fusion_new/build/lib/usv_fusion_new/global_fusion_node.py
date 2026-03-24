#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Level 2: Global Fusion Node (全局认知层 - 单一汇聚节点)
角色: USV 异构多传感器架构的终极决策层，隶属于纯异步事件驱动架构。
描述: 执行航迹到航迹融合 (Track-to-Track, T2T)，汇总东南西北四方局部航迹及中心雷达，解决全包围盲区穿越、轨迹接力ID维护。
"""

import rclpy
from rclpy.node import Node
import threading
from functools import partial

# =========================================================================
# 接口消息占位 (请根据实际构建的 usv_msgs 等包做对应替换)
# =========================================================================
from usv_interfaces.msg import (
    GlobalTrackArray,   # 全局汇总航出 (同时也复用于 Level 1 的 T2T 收发通道)
    GlobalTrack,        # 单体全局航迹
    MmwaveTargetArray   # 平行占位于 NavRadarTargetArray
)

# 使用假想化类别代表实际业务数据体
class MockNavRadarTargetArray: pass

# =========================================================================
# 内部算法解耦层
# =========================================================================
from .global_tracker import GlobalTracker

class GlobalFusionNode(Node):
    def __init__(self):
        super().__init__('global_fusion_node')
        
        self.get_logger().info("🌐 初始化 Level 2: 全局认知融合中心节点启动 ...")

        # ----------------------------------------------------
        # 1. 实例化核心大脑与并发锁机制 
        # ----------------------------------------------------
        # 内部纯数学演算模块实例化
        self.global_tracker = GlobalTracker()
        
        # 互斥锁 (Threading Lock)
        # 本节点由于是纯异步架构，5个不同的订阅者（由于系统调度排队和底层的中间件机制）
        # 完全可能在毫秒级内产生多线程的回调并发竞争/抢占写入，
        # 因此，时间差(dt)推演与 Tracker 状态阵列修改时，必须采用线程锁严格防护，确立时序。
        self.global_lock = threading.Lock()
        
        # 使用精确时间戳浮点数进行记录
        self.last_time = None
        
        # ----------------------------------------------------
        # 2. 批量订阅四方局面 - 使用 partial 多路归一复用回调 
        # ----------------------------------------------------
        directions = ['front', 'rear', 'left', 'right']
        self.local_subs = []
        
        for dir_name in directions:
            topic_name = f'/fusion/local/{dir_name}_tracks'
            
            # 使用 functools.partial 提前给回调函数预装填一个 'source_dir' 变量
            # 这样四个主题最终都能流入同一个优雅复用的 local_track_callback 处理流，却各自携带着源身份令牌
            bound_callback = partial(self.local_track_callback, source_dir=dir_name)
            
            # 由于没有专门设计的 LocalTrackArray 接口类型，本系统全链路统一复用 GlobalTrackArray 作为内部 T2T 总线接口
            sub = self.create_subscription(
                GlobalTrackArray,
                topic_name,
                bound_callback,
                10
            )
            self.local_subs.append(sub)
            self.get_logger().info(f"   [+] 接入子网分支: {topic_name}")

        # ----------------------------------------------------
        # 3. 独立订阅：360度导引雷达
        # ----------------------------------------------------
        self.nav_radar_sub = self.create_subscription(
            MmwaveTargetArray, # 真实环境替换为 -> NavRadarTargetArray
            '/nav_radar/targets',
            self.nav_radar_callback,
            10
        )
        self.get_logger().info("   [+] 接入主心骨: /nav_radar/targets")

        # ----------------------------------------------------
        # 4. 全局终点站发布器
        # ----------------------------------------------------
        self.global_pub = self.create_publisher(GlobalTrackArray, '/fusion/global_tracks', 10)

    def _get_time_float(self, stamp) -> float:
        """从 std_msgs/Header 中提取高精度时间秒"""
        return stamp.sec + stamp.nanosec * 1e-9

    def local_track_callback(self, msg, source_dir: str):
        """
        全向分布式数据灌入池。接收 4 个不同子进程各自送达的提纯 Track 数据。
        注意：此处采用纯多线程并发，需要极小心应对打架问题。
        """
        current_time = self._get_time_float(msg.header.stamp)
        
        # 1. ROS 强结构转本土字典解耦（将一切复杂类型平铺序列化成原生结构，供高阶追踪器使用）
        local_tracks_list = []
        
        for t in msg.tracks:
            local_tracks_list.append({
                'local_id': t.track_id,
                'x': t.x,
                'y': t.y,
                'vx': t.v_x,
                'vy': t.v_y,
                # 注意：如果原本的 GlobalTrack 没有定义长宽字段，这里默认取 0。
                'width': getattr(t, 'width', 0.0),
                'length': getattr(t, 'length', 0.0)
            })

        # 2. 时序控制与追踪器推进 (互斥排队入口)
        with self.global_lock:
            # 建立系统时间的第一桶金
            if self.last_time is None:
                self.last_time = current_time
                return
                
            dt = current_time - self.last_time
            
            # 强化系统鲁棒性：高并发环境往往会导致旧数据比新数据稍晚 2-3 毫秒抵达队列回调函数
            # 一旦时间倒流 (dt < 0) 会瞬间撕裂协方差阵。强制截零并保护状态机。
            if dt < 0:
                dt = 0.0
            elif dt > 1.0:
                # 若系统卡顿太久，强制规定个封顶限额，避免跳点起飞
                dt = 0.1

            # 调用完全独立计算引擎，更新矩阵 （追加了 current_time 供历史存档用）
            self.global_tracker.step(source=source_dir, tracks=local_tracks_list, dt=dt, current_time=current_time)
            
            # 若不是乱序数据，才向前挺进时间沙漏
            if dt >= 0:
                self.last_time = current_time
                
            # 立刻将这个周期的全球视野发布给下游决策模块
            self.publish_global_tracks(msg.header.stamp)

    def nav_radar_callback(self, msg):
        """
        中央导航雷达独立信息入口（处理方式与前一致，仅是 source 表明其身份）
        """
        current_time = self._get_time_float(msg.header.stamp)
        nav_tracks_list = []
        
        # 假设目标的容器叫 targets
        for t in getattr(msg, 'targets', []):
            nav_tracks_list.append({
                'local_id': getattr(t, 'nav_id', 'unk'),
                'x': getattr(t, 'x', 0.0),
                'y': getattr(t, 'y', 0.0),
                'vx': getattr(t, 'vx', 0.0),
                'vy': getattr(t, 'vy', 0.0),
                'width': getattr(t, 'width', 0.0),
                'length': getattr(t, 'length', 0.0)
            })

        # 抢锁时间步进推演，更新航迹机
        with self.global_lock:
            if self.last_time is None:
                self.last_time = current_time
                return
            
            dt = current_time - self.last_time
            
            if dt < 0: dt = 0.0
            elif dt > 1.0: dt = 0.1

            self.global_tracker.step(source='nav_radar', tracks=nav_tracks_list, dt=dt, current_time=current_time)
            
            if dt >= 0:
                self.last_time = current_time
                
            self.publish_global_tracks(msg.header.stamp)

    def publish_global_tracks(self, stamp):
        """
        构建唯一标识的 GlobalTrackArray 并发出。
        本方法由于已经包裹在以上的 global_lock 中调用，因此是绝对的多线程安全的读取。
        """
        pub_msg = GlobalTrackArray()
        pub_msg.header.stamp = stamp
        pub_msg.header.frame_id = 'base_link'  # 所有内容在这个级别早已归一到本体系下
        
        for g_trk in self.global_tracker.global_tracks:
            # 假设你的 global_tracker 把对象状态记录在实例里
            # 只发布那些存活确认的主体结构 (滤除试探态和消亡态残影)
            if getattr(g_trk, 'state', 'Confirmed') != 'Confirmed':
                continue
                
            trk_msg = GlobalTrack()
            # 兼容类型要求，强制转为整型 ID，去除之前设定的 "G-" 字符前缀
            global_id_str = getattr(g_trk, 'global_id', '0')
            try:
                # 过滤掉非数字的部分，如 G-0001 会变成 1
                trk_msg.track_id = int(''.join(filter(str.isdigit, global_id_str)))
            except ValueError:
                trk_msg.track_id = 9999
            
            # （假设）提取内部卡尔曼滤波的状态
            kf_state = getattr(g_trk, 'x', [0.0, 0.0, 0.0, 0.0])
            if hasattr(kf_state, 'flatten'): # numpy 判断
                kf_state = getattr(kf_state, 'flatten')()
                
            trk_msg.x = float(kf_state[0])
            trk_msg.y = float(kf_state[1])
            trk_msg.v_x = float(kf_state[2])
            trk_msg.v_y = float(kf_state[3])
            
            # ... 其他例如协方差 cov 或者体积的补充可根据 custom message 再加
            
            pub_msg.tracks.append(trk_msg)
            
        self.global_pub.publish(pub_msg)


def main(args=None):
    rclpy.init(args=args)
    # 对于这样一个高并发汇集型事件结构，可以考虑通过 rclpy.executors.MultiThreadedExecutor 
    # 让它的回调并发执行得更顺畅，从而真正发挥互斥锁 threading.Lock() 的护城作用。
    node = GlobalFusionNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Global fusion node stopped cleanly')
    except Exception as e:
        node.get_logger().error(f'Error in global fusion node: {e}')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()