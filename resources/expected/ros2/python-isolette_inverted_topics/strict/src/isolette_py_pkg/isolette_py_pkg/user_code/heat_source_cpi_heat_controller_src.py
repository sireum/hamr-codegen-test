#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from isolette_py_pkg.base_code.heat_source_cpi_heat_controller_base_src import heat_source_cpi_heat_controller_base
from isolette_py_pkg_interfaces.msg import OnOff
from isolette_py_pkg_interfaces.msg import Heat
from isolette_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class heat_source_cpi_heat_controller(heat_source_cpi_heat_controller_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("heat_source_cpi_heat_controller infrastructure set up")

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
    def initialize(self):
        self.get_logger().info("Initialize Entry Point invoked")

        # Initialize the node

        # Initialize the node's incoming data port values here

        # Initialize the node's incoming data port values here
        heat_control = OnOff()
        self.init_heat_control(heat_control)


#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
    def message_to_string(self, msg):
        yaml_str = message_to_yaml(msg)
        return yaml_str

    def timeTriggered(self):
        # Handle communication

        # Example receiving messages on data ports
        heat_control = self.get_heat_control()
        self.get_logger().info(f"Received heat_control: {self.message_to_string(heat_control)}")


        # Example publishing messages
        heat_out = Heat()
        self.put_heat_out(heat_out)


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
