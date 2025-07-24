#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from isolette_py_pkg.base_code.temperature_sensor_cpi_thermostat_base_src import temperature_sensor_cpi_thermostat_base
from isolette_py_pkg_interfaces.msg import PhysicalTempimpl
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class temperature_sensor_cpi_thermostat(temperature_sensor_cpi_thermostat_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("temperature_sensor_cpi_thermostat infrastructure set up")

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
    def initialize(self):
        self.get_logger().info("Initialize Entry Point invoked")

        # Initialize the node

        # Initialize the node's incoming data port values here

        # Initialize the node's incoming data port values here
        air = PhysicalTempimpl()
        self.init_air(air)


#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
    def message_to_string(self, msg):
        yaml_str = message_to_yaml(msg)
        return yaml_str

    def timeTriggered(self):
        # Handle communication

        # Example receiving messages on data ports
        air = self.get_air()
        self.get_logger().info(f"Received air: {self.message_to_string(air)}")


        # Example publishing messages
        current_tempWstatus = TempWstatusimpl()
        self.put_current_tempWstatus(current_tempWstatus)


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
