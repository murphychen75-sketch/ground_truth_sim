#!/usr/bin/env python3
"""Launch percision_sim sensor nodes from a params file (requires /sim/ground_truth already publishing)."""

from __future__ import annotations

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    """Start vision / AIS / nav radar / mmWave simulators; enable each with start_* launch args."""
    pkg_share = get_package_share_directory("percision_sim")
    default_params = os.path.join(pkg_share, "config", "percision_sim_params.yaml")
    params_file = LaunchConfiguration("params_file")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "params_file",
                default_value=default_params,
                description="YAML with sim_vision_node, sim_ais_node, sim_nav_radar_node, sim_mmwave_node sections",
            ),
            DeclareLaunchArgument(
                "start_vision_node",
                default_value="true",
                description="Launch sim_vision_node",
            ),
            DeclareLaunchArgument(
                "start_ais_node",
                default_value="false",
                description="Launch sim_ais_node",
            ),
            DeclareLaunchArgument(
                "start_nav_radar_node",
                default_value="true",
                description="Launch sim_nav_radar_node",
            ),
            DeclareLaunchArgument(
                "start_mmwave_node",
                default_value="true",
                description="Launch sim_mmwave_node",
            ),
            Node(
                package="percision_sim",
                executable="sim_vision_node",
                name="sim_vision_node",
                output="screen",
                parameters=[params_file],
                condition=IfCondition(LaunchConfiguration("start_vision_node")),
            ),
            Node(
                package="percision_sim",
                executable="sim_ais_node",
                name="sim_ais_node",
                output="screen",
                parameters=[params_file],
                condition=IfCondition(LaunchConfiguration("start_ais_node")),
            ),
            Node(
                package="percision_sim",
                executable="sim_nav_radar_node",
                name="sim_nav_radar_node",
                output="screen",
                parameters=[params_file],
                condition=IfCondition(LaunchConfiguration("start_nav_radar_node")),
            ),
            Node(
                package="percision_sim",
                executable="sim_mmwave_node",
                name="sim_mmwave_node",
                output="screen",
                parameters=[params_file],
                condition=IfCondition(LaunchConfiguration("start_mmwave_node")),
            ),
        ]
    )
