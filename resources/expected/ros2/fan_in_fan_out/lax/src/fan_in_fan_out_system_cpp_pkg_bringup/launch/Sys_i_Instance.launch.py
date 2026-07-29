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

    fanIn_producer1_node = Node(
        package="fan_in_fan_out_system_cpp_pkg",
        executable="fanIn_producer1_exe",
        # LAUNCH CONFIG fanIn_producer1 - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG fanIn_producer1 - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE fanIn_producer1 - additions within these tags will be preserved when re-running Codegen
    # Rebind fanIn_producer1_node here to replace the declaration above, e.g.
    #     fanIn_producer1_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE fanIn_producer1 - additions within these tags will be preserved when re-running Codegen
    ld.add_action(fanIn_producer1_node)

    fanIn_producer2_node = Node(
        package="fan_in_fan_out_system_cpp_pkg",
        executable="fanIn_producer2_exe",
        # LAUNCH CONFIG fanIn_producer2 - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG fanIn_producer2 - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE fanIn_producer2 - additions within these tags will be preserved when re-running Codegen
    # Rebind fanIn_producer2_node here to replace the declaration above, e.g.
    #     fanIn_producer2_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE fanIn_producer2 - additions within these tags will be preserved when re-running Codegen
    ld.add_action(fanIn_producer2_node)

    fanIn_consumer_node = Node(
        package="fan_in_fan_out_system_cpp_pkg",
        executable="fanIn_consumer_exe",
        # LAUNCH CONFIG fanIn_consumer - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG fanIn_consumer - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE fanIn_consumer - additions within these tags will be preserved when re-running Codegen
    # Rebind fanIn_consumer_node here to replace the declaration above, e.g.
    #     fanIn_consumer_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE fanIn_consumer - additions within these tags will be preserved when re-running Codegen
    ld.add_action(fanIn_consumer_node)

    fanOut_producer_node = Node(
        package="fan_in_fan_out_system_cpp_pkg",
        executable="fanOut_producer_exe",
        # LAUNCH CONFIG fanOut_producer - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG fanOut_producer - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE fanOut_producer - additions within these tags will be preserved when re-running Codegen
    # Rebind fanOut_producer_node here to replace the declaration above, e.g.
    #     fanOut_producer_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE fanOut_producer - additions within these tags will be preserved when re-running Codegen
    ld.add_action(fanOut_producer_node)

    fanOut_consumer1_node = Node(
        package="fan_in_fan_out_system_cpp_pkg",
        executable="fanOut_consumer1_exe",
        # LAUNCH CONFIG fanOut_consumer1 - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG fanOut_consumer1 - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE fanOut_consumer1 - additions within these tags will be preserved when re-running Codegen
    # Rebind fanOut_consumer1_node here to replace the declaration above, e.g.
    #     fanOut_consumer1_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE fanOut_consumer1 - additions within these tags will be preserved when re-running Codegen
    ld.add_action(fanOut_consumer1_node)

    fanOut_consumer2_node = Node(
        package="fan_in_fan_out_system_cpp_pkg",
        executable="fanOut_consumer2_exe",
        # LAUNCH CONFIG fanOut_consumer2 - additions within these tags will be preserved when re-running Codegen
        # LAUNCH CONFIG fanOut_consumer2 - additions within these tags will be preserved when re-running Codegen
    )
    # LAUNCH OVERRIDE fanOut_consumer2 - additions within these tags will be preserved when re-running Codegen
    # Rebind fanOut_consumer2_node here to replace the declaration above, e.g.
    #     fanOut_consumer2_node = Node(package="...", executable="...")
    # LAUNCH OVERRIDE fanOut_consumer2 - additions within these tags will be preserved when re-running Codegen
    ld.add_action(fanOut_consumer2_node)

    return ld
