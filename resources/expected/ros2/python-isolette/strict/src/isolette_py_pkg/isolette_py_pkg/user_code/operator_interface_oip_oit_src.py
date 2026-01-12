#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from isolette_py_pkg.base_code.operator_interface_oip_oit_base_src import operator_interface_oip_oit_base
from isolette_py_pkg_interfaces.msg import Status
from isolette_py_pkg_interfaces.msg import Tempimpl
from isolette_py_pkg_interfaces.msg import OnOff
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class operator_interface_oip_oit(operator_interface_oip_oit_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("operator_interface_oip_oit infrastructure set up")

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
    def initialize(self):
        self.get_logger().info("Initialize Entry Point invoked")

        # Initialize the node

        # Initialize the node's incoming data port values here

        # Initialize the node's incoming data port values here
        regulator_status = Status()
        self.init_regulator_status(regulator_status)

        monitor_status = Status()
        self.init_monitor_status(monitor_status)

        display_temperature = Tempimpl()
        self.init_display_temperature(display_temperature)

        alarm_control = OnOff()
        self.init_alarm_control(alarm_control)


#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
    def message_to_string(self, msg):
        yaml_str = message_to_yaml(msg)
        return yaml_str

    def timeTriggered(self):
        # Handle communication

        # Example receiving messages on data ports
        regulator_status = self.get_regulator_status()
        self.get_logger().info(f"Received regulator_status: {self.message_to_string(regulator_status)}")

        monitor_status = self.get_monitor_status()
        self.get_logger().info(f"Received monitor_status: {self.message_to_string(monitor_status)}")

        display_temperature = self.get_display_temperature()
        self.get_logger().info(f"Received display_temperature: {self.message_to_string(display_temperature)}")

        alarm_control = self.get_alarm_control()
        self.get_logger().info(f"Received alarm_control: {self.message_to_string(alarm_control)}")


        # Example publishing messages
        lower_desired_tempWstatus = TempWstatusimpl()
        self.put_lower_desired_tempWstatus(lower_desired_tempWstatus)

        upper_desired_tempWstatus = TempWstatusimpl()
        self.put_upper_desired_tempWstatus(upper_desired_tempWstatus)

        lower_alarm_tempWstatus = TempWstatusimpl()
        self.put_lower_alarm_tempWstatus(lower_alarm_tempWstatus)

        upper_alarm_tempWstatus = TempWstatusimpl()
        self.put_upper_alarm_tempWstatus(upper_alarm_tempWstatus)


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
