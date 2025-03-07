from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    producer_producer_node = Node(
        package = "datatypes_system_py_pkg",
        executable = "producer_producer_exe"
       )

    consumer_consumer_node = Node(
        package = "datatypes_system_py_pkg",
        executable = "consumer_consumer_exe"
       )

    ld.add_action(producer_producer_node)
    ld.add_action(consumer_consumer_node)

    return ld
