from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    thermostat_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('isolette_py_pkg_bringup'),
                         'launch/thermostat.launch.py')
        )
    )

    operator_interface_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('isolette_py_pkg_bringup'),
                         'launch/operator_interface.launch.py')
        )
    )

    temperature_sensor_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('isolette_py_pkg_bringup'),
                         'launch/temperature_sensor.launch.py')
        )
    )

    heat_source_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('isolette_py_pkg_bringup'),
                         'launch/heat_source.launch.py')
        )
    )

    ld.add_action(thermostat_node)
    ld.add_action(operator_interface_node)
    ld.add_action(temperature_sensor_node)
    ld.add_action(heat_source_node)

    return ld
