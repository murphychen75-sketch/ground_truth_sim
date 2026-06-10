#!/usr/bin/env python3
"""Launch static TF, ground truth publisher, and optional RViz (truth-only display)."""

from __future__ import annotations

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

_PACKAGE_SHARE = get_package_share_directory("ground_truth_sim")
_DEFAULT_RVIZ_CONFIG = os.path.join(_PACKAGE_SHARE, "rviz", "ground_truth_only.rviz")
_DEFAULT_PARAMS_FILE = os.path.join(_PACKAGE_SHARE, "config", "ground_truth_params.yaml")
_DEFAULT_RANGE_OVERLAY_PARAMS = os.path.join(_PACKAGE_SHARE, "config", "range_overlay_params.yaml")


def generate_launch_description() -> LaunchDescription:
    """Start static TF, ground_truth_node, range overlays for RViz, and optional RViz."""
    parent_frame_arg = DeclareLaunchArgument(
        "parent_frame", default_value="map", description="Parent TF frame name"
    )
    child_frame_arg = DeclareLaunchArgument(
        "child_frame", default_value="base_link", description="Child TF frame name"
    )
    use_rviz_arg = DeclareLaunchArgument(
        "use_rviz",
        default_value="true",
        description="Whether to auto-start RViz with the truth-only config",
    )
    rviz_config_arg = DeclareLaunchArgument(
        "rviz_config",
        default_value=_DEFAULT_RVIZ_CONFIG,
        description="Absolute path to an RViz configuration file",
    )
    params_file_arg = DeclareLaunchArgument(
        "params_file",
        default_value=_DEFAULT_PARAMS_FILE,
        description="YAML file for ground_truth_node parameters",
    )
    range_overlay_params_arg = DeclareLaunchArgument(
        "range_overlay_params_file",
        default_value=_DEFAULT_RANGE_OVERLAY_PARAMS,
        description="YAML for range_overlay_node (/sim/range_overlay_markers)",
    )

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

    ground_truth_node = Node(
        package="ground_truth_sim",
        executable="ground_truth_node",
        name="ground_truth_node",
        output="screen",
        parameters=[LaunchConfiguration("params_file")],
    )

    range_overlay_node = Node(
        package="ground_truth_sim",
        executable="range_overlay_node",
        name="range_overlay_node",
        output="screen",
        parameters=[LaunchConfiguration("range_overlay_params_file")],
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="ground_truth_rviz",
        arguments=["-d", LaunchConfiguration("rviz_config")],
        condition=IfCondition(LaunchConfiguration("use_rviz")),
    )

    return LaunchDescription(
        [
            parent_frame_arg,
            child_frame_arg,
            use_rviz_arg,
            rviz_config_arg,
            params_file_arg,
            range_overlay_params_arg,
            static_tf_node,
            ground_truth_node,
            range_overlay_node,
            rviz_node,
        ]
    )
