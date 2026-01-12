#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from isolette_py_pkg.user_code.thermostat_monitor_temperature_manage_alarm_mat_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import Tempimpl
from isolette_py_pkg_interfaces.msg import MonitorMode
from isolette_py_pkg_interfaces.msg import OnOff

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class thermostat_monitor_temperature_manage_alarm_mat_base(Node):
    def __init__(self):
        super().__init__("thermostat_monitor_temperature_manage_alarm_mat")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus",
            self.handle_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp",
            self.handle_lower_alarm_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp",
            self.handle_upper_alarm_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_monitor_mode_subscription_ = self.create_subscription(
            MonitorMode,
            "thermostat_monitor_temperature_manage_alarm_mat_monitor_mode",
            self.handle_monitor_mode,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_ = self.create_publisher(
            OnOff,
            "operator_interface_oip_oit_alarm_control",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

        self.current_tempWstatus_msg_holder = None
        self.lower_alarm_temp_msg_holder = None
        self.upper_alarm_temp_msg_holder = None
        self.monitor_mode_msg_holder = None

    def init_current_tempWstatus(self, val):
        self.current_tempWstatus_msg_holder = val

    def init_lower_alarm_temp(self, val):
        self.lower_alarm_temp_msg_holder = val

    def init_upper_alarm_temp(self, val):
        self.upper_alarm_temp_msg_holder = val

    def init_monitor_mode(self, val):
        self.monitor_mode_msg_holder = val

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_current_tempWstatus(self, msg):
        self.current_tempWstatus_msg_holder = msg

    def handle_lower_alarm_temp(self, msg):
        self.lower_alarm_temp_msg_holder = msg

    def handle_upper_alarm_temp(self, msg):
        self.upper_alarm_temp_msg_holder = msg

    def handle_monitor_mode(self, msg):
        self.monitor_mode_msg_holder = msg

    def get_current_tempWstatus(self):
        return self.current_tempWstatus_msg_holder

    def get_lower_alarm_temp(self):
        return self.lower_alarm_temp_msg_holder

    def get_upper_alarm_temp(self):
        return self.upper_alarm_temp_msg_holder

    def get_monitor_mode(self):
        return self.monitor_mode_msg_holder

    def put_alarm_control(self, msg):
        self.thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_.publish(msg)

