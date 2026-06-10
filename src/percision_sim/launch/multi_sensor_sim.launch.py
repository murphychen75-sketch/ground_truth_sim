#!/usr/bin/env python3
"""Launch four vision and four mmWave simulators from YAML (ground truth must run separately)."""

from __future__ import annotations

import os
from typing import List

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _build_sensor_nodes(params_file: LaunchConfiguration) -> List[Node]:
    """Return eight sensor nodes; parameter keys must match node names in the params file."""
    nodes: List[Node] = []
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
    """Sensors + optional RViz. Run ``ground_truth_sim.launch.py`` first (or use ``full_stack_sim.launch.py``)."""
    pkg_share = get_package_share_directory("percision_sim")
    ground_truth_share = get_package_share_directory("ground_truth_sim")
    default_params = os.path.join(pkg_share, "config", "multi_sensor_params.yaml")
    default_rviz = os.path.join(ground_truth_share, "rviz", "ground_truth_view.rviz")
    default_parent_frame = "map"
    default_child_frame = "base_link"

    params_file_arg = DeclareLaunchArgument(
        "params_file",
        default_value=default_params,
        description="YAML: sim_vision_* and sim_mmwave_* sections (no ground_truth_node)",
    )
    parent_frame_arg = DeclareLaunchArgument(
        "parent_frame",
        default_value=default_parent_frame,
        description="Deprecated no-op (static TF comes from ground_truth_sim.launch.py)",
    )
    child_frame_arg = DeclareLaunchArgument(
        "child_frame",
        default_value=default_child_frame,
        description="Deprecated no-op",
    )

    use_rviz_arg = DeclareLaunchArgument(
        "use_rviz",
        default_value="true",
        description="Whether to auto-start RViz with the multi-sensor marker config",
    )
    rviz_config_arg = DeclareLaunchArgument(
        "rviz_config",
        default_value=default_rviz,
        description="Absolute path to RViz config (e.g. ground_truth_view.rviz)",
    )

    params_file = LaunchConfiguration("params_file")
    nodes = _build_sensor_nodes(params_file)

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
            *nodes,
            rviz_node,
        ]
    )
