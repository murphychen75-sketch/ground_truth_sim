#!/usr/bin/env python3
"""Bring up ground truth, default sensor simulators, fusion, and one RViz (full marker config)."""

from __future__ import annotations

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    """Include ground_truth_sim (no RViz), percision_sim sensors, usv_event_fusion, then optional full RViz."""
    gt_share = get_package_share_directory("ground_truth_sim")
    percision_share = get_package_share_directory("percision_sim")
    fusion_share = get_package_share_directory("usv_event_fusion")

    default_full_rviz = os.path.join(gt_share, "rviz", "ground_truth_view.rviz")
    default_gt_params = os.path.join(gt_share, "config", "ground_truth_params.yaml")
    default_sensor_params = os.path.join(percision_share, "config", "percision_sim_params.yaml")
    ground_truth_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gt_share, "launch", "ground_truth_sim.launch.py")
        ),
        launch_arguments={
            "use_rviz": "false",
            "params_file": LaunchConfiguration("ground_truth_params_file"),
        }.items(),
    )

    sensors_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(percision_share, "launch", "sensors_sim.launch.py")
        ),
        launch_arguments={
            "params_file": LaunchConfiguration("sensor_params_file"),
            "start_vision_node": LaunchConfiguration("start_vision_node"),
            "start_ais_node": LaunchConfiguration("start_ais_node"),
            "start_nav_radar_node": LaunchConfiguration("start_nav_radar_node"),
            "start_mmwave_node": LaunchConfiguration("start_mmwave_node"),
        }.items(),
    )

    fusion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(fusion_share, "launch", "event_fusion.launch.py")
        ),
        launch_arguments={
            "params_file": LaunchConfiguration("fusion_params_file"),
        }.items(),
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="full_stack_rviz",
        arguments=["-d", LaunchConfiguration("rviz_config")],
        # Do not reuse ``use_rviz``: the included ground_truth launch declares the same
        # argument and is started with use_rviz:=false, which would suppress this node.
        condition=IfCondition(LaunchConfiguration("enable_rviz")),
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "ground_truth_params_file",
                default_value=default_gt_params,
                description="Parameters for ground_truth_node",
            ),
            DeclareLaunchArgument(
                "sensor_params_file",
                default_value=default_sensor_params,
                description="percision_sim YAML (sim_vision_node, ...)",
            ),
            DeclareLaunchArgument(
                "fusion_params_file",
                default_value="",
                description=(
                    "Optional usv_event_fusion params_file override; empty loads "
                    "event_fusion_io.yaml + event_fusion_algorithm.yaml"
                ),
            ),
            DeclareLaunchArgument(
                "enable_rviz",
                default_value="true",
                description="Start full-stack RViz (ground_truth_view.rviz); independent of nested ground_truth use_rviz",
            ),
            DeclareLaunchArgument(
                "rviz_config",
                default_value=default_full_rviz,
                description="RViz config (ground_truth_view.rviz for single-sensor topics)",
            ),
            DeclareLaunchArgument(
                "start_vision_node",
                default_value="true",
            ),
            DeclareLaunchArgument(
                "start_ais_node",
                default_value="false",
            ),
            DeclareLaunchArgument(
                "start_nav_radar_node",
                default_value="true",
            ),
            DeclareLaunchArgument(
                "start_mmwave_node",
                default_value="true",
            ),
            ground_truth_launch,
            sensors_launch,
            fusion_launch,
            rviz_node,
        ]
    )
