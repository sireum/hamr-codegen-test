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

    producer_producer_node = Node(
        package="datatypes_system_cpp_pkg",
        executable="producer_producer_exe",
        # LAUNCH CONFIG producer_producer - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG producer_producer - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE producer_producer - additions within these tags will be preserved when re-running Codegen
    # Rebind producer_producer_node here to replace the declaration above, e.g.
    #     producer_producer_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE producer_producer - additions within these tags will be preserved when re-running Codegen
    ld.add_action(producer_producer_node)

    consumer_consumer_node = Node(
        package="datatypes_system_cpp_pkg",
        executable="consumer_consumer_exe",
        # LAUNCH CONFIG consumer_consumer - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG consumer_consumer - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE consumer_consumer - additions within these tags will be preserved when re-running Codegen
    # Rebind consumer_consumer_node here to replace the declaration above, e.g.
    #     consumer_consumer_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE consumer_consumer - additions within these tags will be preserved when re-running Codegen
    ld.add_action(consumer_consumer_node)

    return ld
