from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    heat_source_cpi_heat_controller_node = Node(
        package = "isolette_py_pkg",
        executable = "heat_source_cpi_heat_controller_exe"
    )

    ld.add_action(heat_source_cpi_heat_controller_node)

    return ld
