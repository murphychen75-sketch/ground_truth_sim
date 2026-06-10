#!/usr/bin/env python3
"""Launch 3× vision + 1× mmwave simulators (requires /sim/ground_truth already publishing)."""

from __future__ import annotations

import os
from typing import List

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _build_sensor_nodes(params_file: LaunchConfiguration) -> List[Node]:
    nodes: List[Node] = []
    for suffix in ("front", "left", "right"):
        nodes.append(
            Node(
                package="percision_sim",
                executable="sim_vision_node",
                name=f"sim_vision_{suffix}",
                output="screen",
                parameters=[params_file],
            )
        )
    nodes.append(
        Node(
            package="percision_sim",
            executable="sim_mmwave_node",
            name="sim_mmwave_front",
            output="screen",
            parameters=[params_file],
        )
    )
    return nodes


def generate_launch_description() -> LaunchDescription:
    pkg_share = get_package_share_directory("percision_sim")
    default_params = os.path.join(pkg_share, "config", "three_vision_one_mmwave_params.yaml")

    params_file_arg = DeclareLaunchArgument(
        "params_file",
        default_value=default_params,
        description="YAML with sim_vision_{front,left,right} and sim_mmwave_front sections",
    )

    params_file = LaunchConfiguration("params_file")
    return LaunchDescription([params_file_arg, *_build_sensor_nodes(params_file)])
