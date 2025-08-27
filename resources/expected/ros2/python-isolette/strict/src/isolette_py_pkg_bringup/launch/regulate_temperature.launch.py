from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    thermostat_regulate_temperature_manage_regulator_interface_mrit_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_regulate_temperature_manage_regulator_interface_mrit_exe"
    )

    thermostat_regulate_temperature_manage_heat_source_mhst_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_regulate_temperature_manage_heat_source_mhst_exe"
    )

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe"
    )

    ld.add_action(thermostat_regulate_temperature_manage_regulator_interface_mrit_node)
    ld.add_action(thermostat_regulate_temperature_manage_heat_source_mhst_node)
    ld.add_action(thermostat_regulate_temperature_manage_regulator_mode_mrmt_node)

    return ld
