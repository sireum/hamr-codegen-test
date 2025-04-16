#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from isolette_py_pkg.user_code.consumer_consumer_src import *
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
            handle_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp",
            handle_lower_alarm_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp",
            handle_upper_alarm_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_monitor_mode_subscription_ = self.create_subscription(
            MonitorMode,
            "thermostat_monitor_temperature_manage_alarm_mat_monitor_mode",
            handle_monitor_mode,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_ = self.create_publisher(
            OnOff,
            "operator_interface_oip_oit_alarm_control",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

#=================================================
#  C o m m u n i c a t i o n
#=================================================

    def handle_current_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.current_tempWstatus_msg_holder = typedMsg

    def handle_lower_alarm_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.lower_alarm_temp_msg_holder = typedMsg

    def handle_upper_alarm_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.upper_alarm_temp_msg_holder = typedMsg

    def handle_monitor_mode(self, msg):
        typedMsg = MonitorMode()
        typedMsg.data = msg
        self.monitor_mode_msg_holder = typedMsg

    def get_current_tempWstatus(self):
        return self.current_tempWstatus_msg_holder

    def get_lower_alarm_temp(self):
        return self.lower_alarm_temp_msg_holder

    def get_upper_alarm_temp(self):
        return self.upper_alarm_temp_msg_holder

    def get_monitor_mode(self):
        return self.monitor_mode_msg_holder

    def put_alarm_control(self, msg):
        typedMsg = OnOff()
        typedMsg.data = msg
        self.thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_.publish(typedMsg)

