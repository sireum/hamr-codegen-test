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

    proc_logger_node = Node(
        package="uros_demo_structure_cpp_pkg",
        executable="proc_logger_exe",
        # LAUNCH CONFIG proc_logger - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG proc_logger - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE proc_logger - additions within these tags will be preserved when re-running Codegen
    # Rebind proc_logger_node here to replace the declaration above, e.g.
    #     proc_logger_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE proc_logger - additions within these tags will be preserved when re-running Codegen
    ld.add_action(proc_logger_node)

    return ld
