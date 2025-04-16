#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from isolette_py_pkg.user_code.consumer_consumer_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import MonitorMode
from isolette_py_pkg_interfaces.msg import Tempimpl
from isolette_py_pkg_interfaces.msg import Status
from isolette_py_pkg_interfaces.msg import FailureFlagimpl

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class thermostat_monitor_temperature_manage_monitor_interface_mmit_base(Node):
    def __init__(self):
        super().__init__("thermostat_monitor_temperature_manage_monitor_interface_mmit")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus",
            handle_upper_alarm_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus",
            handle_lower_alarm_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus",
            handle_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_ = self.create_subscription(
            MonitorMode,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode",
            handle_monitor_mode,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_ = self.create_publisher(
            Tempimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp",
            1)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_ = self.create_publisher(
            Tempimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp",
            1)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_ = self.create_publisher(
            Status,
            "operator_interface_oip_oit_monitor_status",
            1)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_ = self.create_publisher(
            FailureFlagimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

#=================================================
#  C o m m u n i c a t i o n
#=================================================

    def handle_upper_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.upper_alarm_tempWstatus_msg_holder = typedMsg

    def handle_lower_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.lower_alarm_tempWstatus_msg_holder = typedMsg

    def handle_current_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.current_tempWstatus_msg_holder = typedMsg

    def handle_monitor_mode(self, msg):
        typedMsg = MonitorMode()
        typedMsg.data = msg
        self.monitor_mode_msg_holder = typedMsg

    def get_upper_alarm_tempWstatus(self):
        return self.upper_alarm_tempWstatus_msg_holder

    def get_lower_alarm_tempWstatus(self):
        return self.lower_alarm_tempWstatus_msg_holder

    def get_current_tempWstatus(self):
        return self.current_tempWstatus_msg_holder

    def get_monitor_mode(self):
        return self.monitor_mode_msg_holder

    def put_upper_alarm_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_.publish(typedMsg)

    def put_lower_alarm_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_.publish(typedMsg)

    def put_monitor_status(self, msg):
        typedMsg = Status()
        typedMsg.data = msg
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_.publish(typedMsg)

    def put_interface_failure(self, msg):
        typedMsg = FailureFlagimpl()
        typedMsg.data = msg
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_.publish(typedMsg)

