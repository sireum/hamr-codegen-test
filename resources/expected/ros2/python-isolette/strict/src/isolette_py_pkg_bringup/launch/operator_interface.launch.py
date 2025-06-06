from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    operator_interface_oip_oit_node = Node(
        package = "isolette_py_pkg",
        executable = "operator_interface_oip_oit_exe"
    )

    ld.add_action(operator_interface_oip_oit_node)

    return ld
