#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
USV 跨进程分层多传感器融合系统 (Hierarchical Multi-Process Fusion System)
启动调度文件 (Launch File)

架构核心设计理念：
Python 的全局解释器锁 (GIL) 会严重限制高频异构传感器（4x视觉 + 4x毫米波）在单一节点内的并发吞吐极值。
该 Launch 文件通过在操作系统 (OS) 层面直接拉起 5 个完全无交集的独立物理进程，
在彻底绕过 GIL 限制的同时，利用 ROS 2 底层的 DDS 通信完成节点/进程间的无缝数据汇流。
"""

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """
    生成 ROS 2 启动描述符
    """
    # 实例化启动描述集对象
    ld = LaunchDescription()

    # 当前定义的工程功能包名称
    package_name = 'usv_fusion_new'

    # ========================================================================
    # Level 1: 局部感知层 (Local Fusion Nodes) - 完全并行的 4 个独立进程
    # ========================================================================
    # 通过 for 循环优雅映射 4 个方向，复用相同的业务代码逻辑。
    # 每一个 Node 动作在 Linux 底层都会 spawn 出一个独立的 python 进程 PID。
    # 这意味着四个方向的 ApproximateTimeSynchronizer 和 拓展卡尔曼矩阵计算 会并行跑在不同的 CPU 物理核上。
    directions = ['front', 'rear', 'left', 'right']
    
    for dir_name in directions:
        local_fusion_node = Node(
            package=package_name,
            executable='local_fusion_node',  # 对应 setup.py 中声明的 console_scripts 入口
            name=f'local_fusion_{dir_name}', # 指定唯一的节点名，防止相互覆盖
            output='screen',                 # 使该进程的 print/logging 直接冲刷到当前终端，便于联合调测
            emulate_tty=True,                # 确保有色彩输出时格式正确
            parameters=[
                {
                    'direction': dir_name,   # 动态传参：挂载方向令牌 (将决定其监听和发布的 topics 空间)
                    'sync_slop': 0.1         # 可选：如果需要在启动阶段覆写时间同步容忍度
                }
            ]
        )
        # 将局部进程丢入启动栈
        ld.add_action(local_fusion_node)


    # ========================================================================
    # Level 2: 全局认知层 (Global Fusion Node) - 唯一数据汇总决策进程
    # ========================================================================
    # 这是全域系统唯一的 T2T (Track-to-Track) 汇聚点。
    # 它通过 DDS 异步接收上方 4 个进程以及额外的主雷达数据，负责处理跨盲区 ID 握手。
    global_fusion_node = Node(
        package=package_name,
        executable='global_fusion_node',     # 汇总进程程序
        name='global_fusion_node',
        output='screen',
        emulate_tty=True
    )
    
    # 将全局进程丢入启动栈
    ld.add_action(global_fusion_node)


    # ========================================================================
    # Level 3: 全局视觉渲染节点 (Global Visualization Node) - 诊断用
    # ========================================================================
    # 该节点专门为了 RViz 设计，负责将系统枯燥的数字矩阵翻译成人类直观易读的 3D UI 坐标标记。
    global_viz_node = Node(
        package=package_name,
        executable='global_viz_node',
        name='global_viz_node',
        output='screen'
    )
    
    ld.add_action(global_viz_node)

    # ========================================================================
    # Level 4: 可视化界面 (RViz 2)
    # ========================================================================
    from launch_ros.substitutions import FindPackageShare
    from launch.substitutions import PathJoinSubstitution
    import os
    from ament_index_python.packages import get_package_share_directory

    rviz_config_file = os.path.join(
        get_package_share_directory('usv_fusion_new'),
        'rviz',
        'fusion_view.rviz'
    )

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        output='screen'
    )

    ld.add_action(rviz_node)

    return ld
