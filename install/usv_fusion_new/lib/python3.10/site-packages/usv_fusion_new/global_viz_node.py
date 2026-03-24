#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Level 3: Global Visualization Node (全局可视化节点)
角色: USV 系统的展示与诊断层。
描述: 订阅全局融合出来的 GlobalTrackArray，将其转译为丰富的 RViz Marker (位置球体、速度矢量箭头、属性浮空字)。
提供极其直观的 3D 可视化，便于人类评估 Track-to-Track 的质量、盲区交接的平滑度以及系统延迟。
"""

import math
import rclpy
from rclpy.node import Node
from rclpy.duration import Duration

from usv_interfaces.msg import GlobalTrackArray
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point

class GlobalVizNode(Node):
    def __init__(self):
        super().__init__('global_viz_node')
        
        self.get_logger().info("🎨 启动 Level 3: 全局视觉渲染节点 (RViz 诊断辅助) ...")
        
        # 订阅由 GlobalFusionNode 吐出的最终提纯数据
        self.sub = self.create_subscription(
            GlobalTrackArray,
            '/fusion/global_tracks',
            self.track_callback,
            10
        )
        
        # 专门发布给 RViz 解析的 Markers 
        self.pub = self.create_publisher(MarkerArray, '/fusion/global_markers', 10)

    def track_callback(self, msg):
        marker_array = MarkerArray()

        # -----------------------------------------------------------------
        # 如果当前没有任何目标，发布一次全局清屏指令，防止画面残留幽灵点
        # -----------------------------------------------------------------
        if not msg.tracks:
            m_clear = Marker()
            m_clear.header.frame_id = 'base_link'
            m_clear.action = Marker.DELETEALL
            marker_array.markers = [m_clear]
            self.pub.publish(marker_array)
            return

        # 给予每一个 Marker 一定的寿命 (Lifetime)。
        # 这样如果目标因为驶出视野而彻底消亡，它的标记会在 0.3 秒后自动在 RViz 蒸发，免去我们手动管理 DELETE 队列。
        life_time = Duration(seconds=0, nanoseconds=300000000).to_msg()
        current_stamp = msg.header.stamp

        markers_list = []

        for i, trk in enumerate(msg.tracks):
            # 将字符型的 track_id 转换为整数 ID 供 RViz 使用 (使用 hash 截断)
            numeric_id = abs(hash(trk.track_id)) % 10000

            # ============================================================
            # 1. 位置本体 Marker (紫色发光球体, 代表高权重的 Global 状态)
            # ============================================================
            m_sphere = Marker()
            m_sphere.header.frame_id = 'base_link'
            m_sphere.header.stamp = current_stamp
            m_sphere.ns = 'global_position'
            m_sphere.id = numeric_id
            m_sphere.type = Marker.SPHERE
            m_sphere.action = Marker.ADD
            m_sphere.lifetime = life_time
            
            m_sphere.pose.position.x = trk.x
            m_sphere.pose.position.y = trk.y
            m_sphere.pose.position.z = 1.0  # 稍微抬高防止与海平面穿模
            
            # 使用稍大的体积突显它是全局节点
            m_sphere.scale.x = 2.5
            m_sphere.scale.y = 2.5
            m_sphere.scale.z = 2.5
            
            # 亮紫色 (R:0.8, G:0.2, B:0.8)
            m_sphere.color.r = 0.8
            m_sphere.color.g = 0.2
            m_sphere.color.b = 0.8
            m_sphere.color.a = 0.9
            
            markers_list.append(m_sphere)

            # ============================================================
            # 2. 速度向量箭头 Marker (指示系统的运动推演方向)
            # ============================================================
            m_arrow = Marker()
            m_arrow.header = m_sphere.header
            m_arrow.ns = 'global_velocity'
            m_arrow.id = numeric_id
            m_arrow.type = Marker.ARROW
            m_arrow.action = Marker.ADD
            m_arrow.lifetime = life_time
            
            # 箭头的起点 (目标中心)
            p_start = Point()
            p_start.x = trk.x
            p_start.y = trk.y
            p_start.z = 1.0
            
            # 箭头的终点 (延长 1.5 秒的运动向量用于夸张显示)
            p_end = Point()
            p_end.x = trk.x + trk.v_x * 1.5
            p_end.y = trk.y + trk.v_y * 1.5
            p_end.z = 1.0
            
            m_arrow.points = [p_start, p_end]
            
            m_arrow.scale.x = 0.4  # 柱子粗细
            m_arrow.scale.y = 0.8  # 箭头头部宽度
            m_arrow.scale.z = 0.0
            
            # 箭头给成亮青色 (Cyan)
            m_arrow.color.r = 0.0
            m_arrow.color.g = 1.0
            m_arrow.color.b = 1.0
            m_arrow.color.a = 0.8
            
            markers_list.append(m_arrow)

            # ============================================================
            # 3. 信息面板文本 Marker (浮空显示 ID 与 绝对速度 |V|)
            # ============================================================
            speed = math.hypot(trk.v_x, trk.v_y)
            
            m_text = Marker()
            m_text.header = m_sphere.header
            m_text.ns = 'global_info'
            m_text.id = numeric_id
            m_text.type = Marker.TEXT_VIEW_FACING
            m_text.action = Marker.ADD
            m_text.lifetime = life_time
            
            m_text.pose.position.x = trk.x
            m_text.pose.position.y = trk.y
            m_text.pose.position.z = 4.0 # 顶置于目标上方 4 米
            
            m_text.text = f"{trk.track_id}\n{speed:.1f} m/s"
            
            m_text.scale.z = 1.5 # 字体大小
            m_text.color.r = 1.0
            m_text.color.g = 1.0
            m_text.color.b = 1.0
            m_text.color.a = 1.0
            
            markers_list.append(m_text)

        marker_array.markers = markers_list
        self.pub.publish(marker_array)

def main(args=None):
    rclpy.init(args=args)
    node = GlobalVizNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
