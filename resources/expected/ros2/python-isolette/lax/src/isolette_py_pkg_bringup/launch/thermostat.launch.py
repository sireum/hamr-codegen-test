from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    regulate_temperature_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('isolette_py_pkg_bringup'),
                         'launch/regulate_temperature.launch.py')
        )
    )

    monitor_temperature_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('isolette_py_pkg_bringup'),
                         'launch/monitor_temperature.launch.py')
        )
    )

    ld.add_action(regulate_temperature_node)
    ld.add_action(monitor_temperature_node)

    return ld
