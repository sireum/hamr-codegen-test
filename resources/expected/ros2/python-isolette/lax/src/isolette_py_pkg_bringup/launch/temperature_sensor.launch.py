from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    temperature_sensor_cpi_thermostat_node = Node(
        package = "isolette_py_pkg",
        executable = "temperature_sensor_cpi_thermostat_exe"
    )

    ld.add_action(temperature_sensor_cpi_thermostat_node)

    return ld
