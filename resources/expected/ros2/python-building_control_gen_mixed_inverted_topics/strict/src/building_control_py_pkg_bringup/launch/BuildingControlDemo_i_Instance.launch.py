from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    tcp_tempSensor_node = Node(
        package = "building_control_py_pkg",
        executable = "tcp_tempSensor_exe"
    )

    tcp_tempControl_node = Node(
        package = "building_control_py_pkg",
        executable = "tcp_tempControl_exe"
    )

    tcp_fan_node = Node(
        package = "building_control_py_pkg",
        executable = "tcp_fan_exe"
    )

    ld.add_action(tcp_tempSensor_node)
    ld.add_action(tcp_tempControl_node)
    ld.add_action(tcp_fan_node)

    return ld
