#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from isolette_py_pkg.base_code.thermostat_regulate_temperature_manage_heat_source_mhst_base_src import thermostat_regulate_temperature_manage_heat_source_mhst_base
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import Tempimpl
from isolette_py_pkg_interfaces.msg import RegulatorMode
from isolette_py_pkg_interfaces.msg import OnOff
from isolette_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class thermostat_regulate_temperature_manage_heat_source_mhst(thermostat_regulate_temperature_manage_heat_source_mhst_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("thermostat_regulate_temperature_manage_heat_source_mhst infrastructure set up")

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
    def initialize(self):
        self.get_logger().info("Initialize Entry Point invoked")

        # Initialize the node

        # Initialize the node's incoming data port values here

        # Initialize the node's incoming data port values here
        current_tempWstatus = TempWstatusimpl()
        self.init_current_tempWstatus(current_tempWstatus)

        lower_desired_temp = Tempimpl()
        self.init_lower_desired_temp(lower_desired_temp)

        upper_desired_temp = Tempimpl()
        self.init_upper_desired_temp(upper_desired_temp)

        regulator_mode = RegulatorMode()
        self.init_regulator_mode(regulator_mode)


#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
    def message_to_string(self, msg):
        yaml_str = message_to_yaml(msg)
        return yaml_str

    def timeTriggered(self):
        # Handle communication

        # Example receiving messages on data ports
        current_tempWstatus = self.get_current_tempWstatus()
        self.get_logger().info(f"Received current_tempWstatus: {self.message_to_string(current_tempWstatus)}")

        lower_desired_temp = self.get_lower_desired_temp()
        self.get_logger().info(f"Received lower_desired_temp: {self.message_to_string(lower_desired_temp)}")

        upper_desired_temp = self.get_upper_desired_temp()
        self.get_logger().info(f"Received upper_desired_temp: {self.message_to_string(upper_desired_temp)}")

        regulator_mode = self.get_regulator_mode()
        self.get_logger().info(f"Received regulator_mode: {self.message_to_string(regulator_mode)}")


        # Example publishing messages
        heat_control = OnOff()
        self.put_heat_control(heat_control)


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
