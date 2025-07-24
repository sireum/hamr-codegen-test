#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from isolette_py_pkg.base_code.thermostat_monitor_temperature_manage_monitor_mode_mmmt_base_src import thermostat_monitor_temperature_manage_monitor_mode_mmmt_base
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import FailureFlagimpl
from isolette_py_pkg_interfaces.msg import MonitorMode
from isolette_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class thermostat_monitor_temperature_manage_monitor_mode_mmmt(thermostat_monitor_temperature_manage_monitor_mode_mmmt_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("thermostat_monitor_temperature_manage_monitor_mode_mmmt infrastructure set up")

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

        interface_failure = FailureFlagimpl()
        self.init_interface_failure(interface_failure)

        internal_failure = FailureFlagimpl()
        self.init_internal_failure(internal_failure)


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

        interface_failure = self.get_interface_failure()
        self.get_logger().info(f"Received interface_failure: {self.message_to_string(interface_failure)}")

        internal_failure = self.get_internal_failure()
        self.get_logger().info(f"Received internal_failure: {self.message_to_string(internal_failure)}")


        # Example publishing messages
        monitor_mode = MonitorMode()
        self.put_monitor_mode(monitor_mode)


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
