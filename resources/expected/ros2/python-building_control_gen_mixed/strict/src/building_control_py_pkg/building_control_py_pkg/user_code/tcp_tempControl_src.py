#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from building_control_py_pkg.base_code.tcp_tempControl_base_src import tcp_tempControl_base
from building_control_py_pkg_interfaces.msg import FanCmd
from building_control_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class tcp_tempControl(tcp_tempControl_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("tcp_tempControl infrastructure set up")

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
    def initialize(node):
        node.get_logger().info("Initialize Entry Point invoked")

        # Initialize the node

        # Initialize the node's incoming data port values here


#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
    def message_to_string(msg):
        yaml_str = message_to_yaml(msg)
        return yaml_str

    def handle_fanAck(self, msg):
        # Handle fanAck msg
        self.get_logger().info("Received fanAck: %s", message_to_string(msg))

        # Example receiving messages on data ports
        currentTemp = get_currentTemp()
        self.get_logger().info("Received currentTemp: %s", message_to_string(currentTemp))
    def handle_setPoint(self, msg):
        # Handle setPoint msg
        self.get_logger().info("Received setPoint: %s", message_to_string(msg))

    def handle_tempChanged(self):
        # Handle tempChanged event
        self.get_logger().info("Received tempChanged")


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
