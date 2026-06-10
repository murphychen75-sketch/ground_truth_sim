#!/usr/bin/env python3
"""Bring up ground truth, 3× vision + 1× mmwave sim, fusion, and RViz."""

from __future__ import annotations

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    gt_share = get_package_share_directory("ground_truth_sim")
    percision_share = get_package_share_directory("percision_sim")
    fusion_share = get_package_share_directory("usv_event_fusion")

    default_rviz = os.path.join(gt_share, "rviz", "three_sensor_fusion_view.rviz")
    default_gt_params = os.path.join(gt_share, "config", "ground_truth_params.yaml")
    default_overlay_params = os.path.join(gt_share, "config", "three_sensor_overlay_params.yaml")
    default_sensor_params = os.path.join(
        percision_share, "config", "three_vision_one_mmwave_params.yaml"
    )
    default_fusion_io = os.path.join(
        fusion_share, "config", "event_fusion_three_sensor_io.yaml"
    )

    ground_truth_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gt_share, "launch", "ground_truth_sim.launch.py")
        ),
        launch_arguments={
            "use_rviz": "false",
            "params_file": LaunchConfiguration("ground_truth_params_file"),
            "range_overlay_params_file": LaunchConfiguration("range_overlay_params_file"),
        }.items(),
    )

    sensors_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(percision_share, "launch", "three_sensor_sim.launch.py")
        ),
        launch_arguments={
            "params_file": LaunchConfiguration("sensor_params_file"),
        }.items(),
    )

    fusion_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(fusion_share, "launch", "event_fusion.launch.py")
        ),
        launch_arguments={
            "io_params_file": LaunchConfiguration("fusion_io_params_file"),
            "algorithm_params_file": LaunchConfiguration("fusion_algorithm_params_file"),
            "params_file": LaunchConfiguration("fusion_params_file"),
        }.items(),
    )

    default_algo = os.path.join(fusion_share, "config", "event_fusion_algorithm.yaml")

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="three_sensor_fusion_rviz",
        arguments=["-d", LaunchConfiguration("rviz_config")],
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
                "range_overlay_params_file",
                default_value=default_overlay_params,
                description="FoV overlay markers for 3× vision + 1× mmwave",
            ),
            DeclareLaunchArgument(
                "sensor_params_file",
                default_value=default_sensor_params,
                description="percision_sim YAML for three_vision_one_mmwave stack",
            ),
            DeclareLaunchArgument(
                "fusion_io_params_file",
                default_value=default_fusion_io,
                description="usv_event_fusion I/O and extrinsics for 3V+1R",
            ),
            DeclareLaunchArgument(
                "fusion_algorithm_params_file",
                default_value=default_algo,
                description="usv_event_fusion algorithm parameters",
            ),
            DeclareLaunchArgument(
                "fusion_params_file",
                default_value="",
                description="Optional single-file fusion override; empty uses io + algorithm",
            ),
            DeclareLaunchArgument(
                "enable_rviz",
                default_value="true",
                description="Start RViz with three_sensor_fusion_view.rviz",
            ),
            DeclareLaunchArgument(
                "rviz_config",
                default_value=default_rviz,
                description="RViz config for 3V+1R fusion stack",
            ),
            ground_truth_launch,
            sensors_launch,
            fusion_launch,
            rviz_node,
        ]
    )
