from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    fanIn_producer1_node = Node(
        package = "fan_in_fan_out_system_py_pkg",
        executable = "fanIn_producer1_exe"
    )

    fanIn_producer2_node = Node(
        package = "fan_in_fan_out_system_py_pkg",
        executable = "fanIn_producer2_exe"
    )

    fanIn_consumer_node = Node(
        package = "fan_in_fan_out_system_py_pkg",
        executable = "fanIn_consumer_exe"
    )

    fanOut_producer_node = Node(
        package = "fan_in_fan_out_system_py_pkg",
        executable = "fanOut_producer_exe"
    )

    fanOut_consumer1_node = Node(
        package = "fan_in_fan_out_system_py_pkg",
        executable = "fanOut_consumer1_exe"
    )

    fanOut_consumer2_node = Node(
        package = "fan_in_fan_out_system_py_pkg",
        executable = "fanOut_consumer2_exe"
    )

    ld.add_action(fanIn_producer1_node)
    ld.add_action(fanIn_producer2_node)
    ld.add_action(fanIn_consumer_node)
    ld.add_action(fanOut_producer_node)
    ld.add_action(fanOut_consumer1_node)
    ld.add_action(fanOut_consumer2_node)

    return ld
