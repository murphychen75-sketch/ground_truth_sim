"""启动事件驱动融合节点。"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _fusion_node_params(context):
    pkg_share = get_package_share_directory("usv_event_fusion")
    config_dir = os.path.join(pkg_share, "config")
    default_io = os.path.join(config_dir, "event_fusion_io.yaml")
    default_algo = os.path.join(config_dir, "event_fusion_algorithm.yaml")

    override = LaunchConfiguration("params_file").perform(context).strip()
    if override:
        param_files = [override]
    else:
        io_file = LaunchConfiguration("io_params_file").perform(context).strip() or default_io
        algo_file = (
            LaunchConfiguration("algorithm_params_file").perform(context).strip() or default_algo
        )
        param_files = [io_file, algo_file]

    return [
        Node(
            package="usv_event_fusion",
            executable="event_fusion_node",
            name="event_fusion_node",
            output="screen",
            parameters=param_files,
        )
    ]


def generate_launch_description() -> LaunchDescription:
    pkg_share = get_package_share_directory("usv_event_fusion")
    config_dir = os.path.join(pkg_share, "config")
    default_io = os.path.join(config_dir, "event_fusion_io.yaml")
    default_algo = os.path.join(config_dir, "event_fusion_algorithm.yaml")
    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "io_params_file",
                default_value=default_io,
                description="外部 I/O 与外参：event_fusion_io.yaml",
            ),
            DeclareLaunchArgument(
                "algorithm_params_file",
                default_value=default_algo,
                description="算法参数：event_fusion_algorithm.yaml",
            ),
            DeclareLaunchArgument(
                "params_file",
                default_value="",
                description=(
                    "可选：单文件覆盖 io/algorithm 默认（如 event_fusion_params.yaml）；"
                    "非空时仅加载此文件"
                ),
            ),
            OpaqueFunction(function=_fusion_node_params),
        ]
    )
