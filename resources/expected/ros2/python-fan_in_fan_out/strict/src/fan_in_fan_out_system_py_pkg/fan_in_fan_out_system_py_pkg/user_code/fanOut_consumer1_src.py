#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from fan_in_fan_out_system_py_pkg.base_code.fanOut_consumer1_base_src import fanOut_consumer1_base
from fan_in_fan_out_system_py_pkg_interfaces.msg import Integer64

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class fanOut_consumer1(fanOut_consumer1_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("fanOut_consumer1 infrastructure set up")

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
    def initialize(self):
        self.get_logger().info("Initialize Entry Point invoked")

        # Initialize the node

        # Initialize the node's incoming data port values here


#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
    def message_to_string(self, msg):
        yaml_str = message_to_yaml(msg)
        return yaml_str

    def handle_myInteger(self, msg):
        # Handle myInteger msg
        self.get_logger().info(f"Received myInteger: {self.message_to_string(msg)}")


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
