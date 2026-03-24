#!/usr/bin/env python3
"""Launch four vision cameras and four mmWave radars with shared parameters."""

from __future__ import annotations

import os
from typing import List

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _build_nodes(params_file: LaunchConfiguration) -> List[Node]:
    nodes: List[Node] = []

    nodes.append(
        Node(
            package="ground_truth_sim",
            executable="ground_truth_node",
            name="ground_truth_node",
            output="screen",
            parameters=[params_file],
        )
    )

    for suffix in ("front", "right", "rear", "left"):
        nodes.append(
            Node(
                package="percision_sim",
                executable="sim_vision_node",
                name=f"sim_vision_{suffix}",
                output="screen",
                parameters=[params_file],
            )
        )

    for suffix in ("front", "right", "rear", "left"):
        nodes.append(
            Node(
                package="percision_sim",
                executable="sim_mmwave_node",
                name=f"sim_mmwave_{suffix}",
                output="screen",
                parameters=[params_file],
            )
        )

    return nodes


def generate_launch_description() -> LaunchDescription:
    pkg_share = get_package_share_directory("percision_sim")
    ground_truth_share = get_package_share_directory("ground_truth_sim")
    default_params = os.path.join(pkg_share, "config", "multi_sensor_params.yaml")
    default_rviz = os.path.join(ground_truth_share, "rviz", "ground_truth_view.rviz")
    default_parent_frame = "map"
    default_child_frame = "base_link"

    params_file_arg = DeclareLaunchArgument(
        "params_file",
        default_value=default_params,
        description="YAML file containing parameters for ground truth and all sensor nodes",
    )
    parent_frame_arg = DeclareLaunchArgument(
        "parent_frame",
        default_value=default_parent_frame,
        description="Parent TF frame for the simulated vessel",
    )
    child_frame_arg = DeclareLaunchArgument(
        "child_frame",
        default_value=default_child_frame,
        description="Child TF frame broadcast by the static transform node",
    )

    use_rviz_arg = DeclareLaunchArgument(
        "use_rviz",
        default_value="true",
        description="Whether to auto-start RViz with the multi-sensor scene",
    )
    rviz_config_arg = DeclareLaunchArgument(
        "rviz_config",
        default_value=default_rviz,
        description="Absolute path to an RViz configuration file",
    )

    params_file = LaunchConfiguration("params_file")
    nodes = _build_nodes(params_file)

    static_tf_node = Node(
        package="ground_truth_sim",
        executable="static_tf_broadcaster",
        name="static_tf_broadcaster",
        parameters=[
            {
                "parent_frame": LaunchConfiguration("parent_frame"),
                "child_frame": LaunchConfiguration("child_frame"),
            }
        ],
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="multi_sensor_rviz",
        arguments=["-d", LaunchConfiguration("rviz_config")],
        condition=IfCondition(LaunchConfiguration("use_rviz")),
    )

    return LaunchDescription(
        [
            params_file_arg,
            parent_frame_arg,
            child_frame_arg,
            use_rviz_arg,
            rviz_config_arg,
            static_tf_node,
            *nodes,
            rviz_node,
        ]
    )
