from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()


    Sys_i_Instance_producer_producer_node = Node(
       package = datatypes_system_py_pkg,
       executable = Sys_i_Instance_producer_producer_exe
       )


    Sys_i_Instance_consumer_consumer_node = Node(
       package = datatypes_system_py_pkg,
       executable = Sys_i_Instance_consumer_consumer_exe
       )

    ld.add_action(Sys_i_Instance_producer_producer_node)
    ld.add_action(Sys_i_Instance_consumer_consumer_node)

    return ld
