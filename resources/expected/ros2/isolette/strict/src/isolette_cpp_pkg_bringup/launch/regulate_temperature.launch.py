# Content between markers will be preserved if codegen is rerun

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

# LAUNCH PREAMBLE - additions within these tags will be preserved when re-running Codegen
# Add imports and helper functions here, e.g.
#     from launch.actions import TimerAction
#
#     def delayed(action, seconds):
#         return TimerAction(period=float(seconds), actions=[action])
# LAUNCH PREAMBLE - additions within these tags will be preserved when re-running Codegen


def generate_launch_description():
    ld = LaunchDescription()

    # LAUNCH ARGUMENTS - additions within these tags will be preserved when re-running Codegen
    # Declare launch arguments here, e.g.
    #     log_file = LaunchConfiguration("log_file")
    #     ld.add_action(DeclareLaunchArgument("log_file", default_value="uros-demo.txt"))
    # then reference them from a node's config block:
    #     parameters=[{"log_file_name": log_file}],
    # LAUNCH ARGUMENTS - additions within these tags will be preserved when re-running Codegen

    thermostat_regulate_temperature_manage_regulator_interface_mrit_node = Node(
        package="isolette_cpp_pkg",
        executable="thermostat_regulate_temperature_manage_regulator_interface_mrit_exe",
        # LAUNCH CONFIG thermostat_regulate_temperature_manage_regulator_interface_mrit - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG thermostat_regulate_temperature_manage_regulator_interface_mrit - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE thermostat_regulate_temperature_manage_regulator_interface_mrit - additions within these tags will be preserved when re-running Codegen
    # Rebind thermostat_regulate_temperature_manage_regulator_interface_mrit_node here to replace the declaration above, e.g.
    #     thermostat_regulate_temperature_manage_regulator_interface_mrit_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE thermostat_regulate_temperature_manage_regulator_interface_mrit - additions within these tags will be preserved when re-running Codegen
    ld.add_action(thermostat_regulate_temperature_manage_regulator_interface_mrit_node)

    thermostat_regulate_temperature_manage_heat_source_mhst_node = Node(
        package="isolette_cpp_pkg",
        executable="thermostat_regulate_temperature_manage_heat_source_mhst_exe",
        # LAUNCH CONFIG thermostat_regulate_temperature_manage_heat_source_mhst - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG thermostat_regulate_temperature_manage_heat_source_mhst - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE thermostat_regulate_temperature_manage_heat_source_mhst - additions within these tags will be preserved when re-running Codegen
    # Rebind thermostat_regulate_temperature_manage_heat_source_mhst_node here to replace the declaration above, e.g.
    #     thermostat_regulate_temperature_manage_heat_source_mhst_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE thermostat_regulate_temperature_manage_heat_source_mhst - additions within these tags will be preserved when re-running Codegen
    ld.add_action(thermostat_regulate_temperature_manage_heat_source_mhst_node)

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_node = Node(
        package="isolette_cpp_pkg",
        executable="thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe",
        # LAUNCH CONFIG thermostat_regulate_temperature_manage_regulator_mode_mrmt - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG thermostat_regulate_temperature_manage_regulator_mode_mrmt - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE thermostat_regulate_temperature_manage_regulator_mode_mrmt - additions within these tags will be preserved when re-running Codegen
    # Rebind thermostat_regulate_temperature_manage_regulator_mode_mrmt_node here to replace the declaration above, e.g.
    #     thermostat_regulate_temperature_manage_regulator_mode_mrmt_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE thermostat_regulate_temperature_manage_regulator_mode_mrmt - additions within these tags will be preserved when re-running Codegen
    ld.add_action(thermostat_regulate_temperature_manage_regulator_mode_mrmt_node)

    return ld
