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

    tcp_tempSensor_node = Node(
        package="building_control_cpp_pkg",
        executable="tcp_tempSensor_exe",
        # LAUNCH CONFIG tcp_tempSensor - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG tcp_tempSensor - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE tcp_tempSensor - additions within these tags will be preserved when re-running Codegen
    # Rebind tcp_tempSensor_node here to replace the declaration above, e.g.
    #     tcp_tempSensor_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE tcp_tempSensor - additions within these tags will be preserved when re-running Codegen
    ld.add_action(tcp_tempSensor_node)

    tcp_tempControl_node = Node(
        package="building_control_cpp_pkg",
        executable="tcp_tempControl_exe",
        # LAUNCH CONFIG tcp_tempControl - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG tcp_tempControl - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE tcp_tempControl - additions within these tags will be preserved when re-running Codegen
    # Rebind tcp_tempControl_node here to replace the declaration above, e.g.
    #     tcp_tempControl_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE tcp_tempControl - additions within these tags will be preserved when re-running Codegen
    ld.add_action(tcp_tempControl_node)

    tcp_fan_node = Node(
        package="building_control_cpp_pkg",
        executable="tcp_fan_exe",
        # LAUNCH CONFIG tcp_fan - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG tcp_fan - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE tcp_fan - additions within these tags will be preserved when re-running Codegen
    # Rebind tcp_fan_node here to replace the declaration above, e.g.
    #     tcp_fan_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE tcp_fan - additions within these tags will be preserved when re-running Codegen
    ld.add_action(tcp_fan_node)

    return ld
