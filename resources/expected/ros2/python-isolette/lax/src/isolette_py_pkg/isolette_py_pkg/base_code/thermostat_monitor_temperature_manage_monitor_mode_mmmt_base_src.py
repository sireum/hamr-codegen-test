#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from isolette_py_pkg.user_code.thermostat_monitor_temperature_manage_monitor_mode_mmmt_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import FailureFlagimpl
from isolette_py_pkg_interfaces.msg import MonitorMode

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class thermostat_monitor_temperature_manage_monitor_mode_mmmt_base(Node):
    def __init__(self):
        super().__init__("thermostat_monitor_temperature_manage_monitor_mode_mmmt")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus",
            self.handle_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure",
            self.handle_interface_failure,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure",
            self.handle_internal_failure,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1 = self.create_publisher(
            MonitorMode,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode",
            1)

        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2 = self.create_publisher(
            MonitorMode,
            "thermostat_monitor_temperature_manage_alarm_mat_monitor_mode",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

        self.current_tempWstatus_msg_holder = None
        self.interface_failure_msg_holder = None
        self.internal_failure_msg_holder = None

    def init_current_tempWstatus(self, val):
        self.current_tempWstatus_msg_holder = val

    def init_interface_failure(self, val):
        self.interface_failure_msg_holder = val

    def init_internal_failure(self, val):
        self.internal_failure_msg_holder = val

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_current_tempWstatus(self, msg):
        self.current_tempWstatus_msg_holder = msg

    def handle_interface_failure(self, msg):
        self.interface_failure_msg_holder = msg

    def handle_internal_failure(self, msg):
        self.internal_failure_msg_holder = msg

    def get_current_tempWstatus(self):
        return self.current_tempWstatus_msg_holder

    def get_interface_failure(self):
        return self.interface_failure_msg_holder

    def get_internal_failure(self):
        return self.internal_failure_msg_holder

    def put_monitor_mode(self, msg):
        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1.publish(msg)
        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2.publish(msg)

