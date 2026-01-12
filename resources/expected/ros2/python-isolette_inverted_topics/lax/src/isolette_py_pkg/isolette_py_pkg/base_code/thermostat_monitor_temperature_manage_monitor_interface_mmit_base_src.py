#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from isolette_py_pkg.user_code.thermostat_monitor_temperature_manage_monitor_interface_mmit_src import *
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
            "operator_interface_oip_oit_upper_alarm_tempWstatus",
            self.handle_upper_alarm_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "operator_interface_oip_oit_upper_alarm_tempWstatus",
            self.handle_lower_alarm_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "temperature_sensor_cpi_thermostat_current_tempWstatus",
            self.handle_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_ = self.create_subscription(
            MonitorMode,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode",
            self.handle_monitor_mode,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_ = self.create_publisher(
            Tempimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp",
            1)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_ = self.create_publisher(
            Tempimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp",
            1)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_ = self.create_publisher(
            Status,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status",
            1)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_ = self.create_publisher(
            FailureFlagimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

        self.upper_alarm_tempWstatus_msg_holder = None
        self.lower_alarm_tempWstatus_msg_holder = None
        self.current_tempWstatus_msg_holder = None
        self.monitor_mode_msg_holder = None

    def init_upper_alarm_tempWstatus(self, val):
        self.upper_alarm_tempWstatus_msg_holder = val

    def init_lower_alarm_tempWstatus(self, val):
        self.lower_alarm_tempWstatus_msg_holder = val

    def init_current_tempWstatus(self, val):
        self.current_tempWstatus_msg_holder = val

    def init_monitor_mode(self, val):
        self.monitor_mode_msg_holder = val

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_upper_alarm_tempWstatus(self, msg):
        self.upper_alarm_tempWstatus_msg_holder = msg

    def handle_lower_alarm_tempWstatus(self, msg):
        self.lower_alarm_tempWstatus_msg_holder = msg

    def handle_current_tempWstatus(self, msg):
        self.current_tempWstatus_msg_holder = msg

    def handle_monitor_mode(self, msg):
        self.monitor_mode_msg_holder = msg

    def get_upper_alarm_tempWstatus(self):
        return self.upper_alarm_tempWstatus_msg_holder

    def get_lower_alarm_tempWstatus(self):
        return self.lower_alarm_tempWstatus_msg_holder

    def get_current_tempWstatus(self):
        return self.current_tempWstatus_msg_holder

    def get_monitor_mode(self):
        return self.monitor_mode_msg_holder

    def put_upper_alarm_temp(self, msg):
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_.publish(msg)

    def put_lower_alarm_temp(self, msg):
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_.publish(msg)

    def put_monitor_status(self, msg):
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_.publish(msg)

    def put_interface_failure(self, msg):
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_.publish(msg)

