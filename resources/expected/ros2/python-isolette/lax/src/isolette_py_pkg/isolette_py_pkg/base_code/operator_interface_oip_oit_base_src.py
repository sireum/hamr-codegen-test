#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from isolette_py_pkg.user_code.consumer_consumer_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import Status
from isolette_py_pkg_interfaces.msg import Tempimpl
from isolette_py_pkg_interfaces.msg import OnOff
from isolette_py_pkg_interfaces.msg import TempWstatusimpl

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class operator_interface_oip_oit_base(Node):
    def __init__(self):
        super().__init__("operator_interface_oip_oit")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.operator_interface_oip_oit_regulator_status_subscription_ = self.create_subscription(
            Status,
            "operator_interface_oip_oit_regulator_status",
            handle_regulator_status,
            1,
            callback_group=self.cb_group_)

        self.operator_interface_oip_oit_monitor_status_subscription_ = self.create_subscription(
            Status,
            "operator_interface_oip_oit_monitor_status",
            handle_monitor_status,
            1,
            callback_group=self.cb_group_)

        self.operator_interface_oip_oit_display_temperature_subscription_ = self.create_subscription(
            Tempimpl,
            "operator_interface_oip_oit_display_temperature",
            handle_display_temperature,
            1,
            callback_group=self.cb_group_)

        self.operator_interface_oip_oit_alarm_control_subscription_ = self.create_subscription(
            OnOff,
            "operator_interface_oip_oit_alarm_control",
            handle_alarm_control,
            1,
            callback_group=self.cb_group_)

        self.operator_interface_oip_oit_lower_desired_tempWstatus_publisher_ = self.create_publisher(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus",
            1)

        self.operator_interface_oip_oit_upper_desired_tempWstatus_publisher_ = self.create_publisher(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus",
            1)

        self.operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_ = self.create_publisher(
            TempWstatusimpl,
            "operator_interface_oip_oit_lower_alarm_tempWstatus",
            1)

        self.operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_1 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus",
            1)

        self.operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_2 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

#=================================================
#  C o m m u n i c a t i o n
#=================================================

    def handle_regulator_status(self, msg):
        typedMsg = Status()
        typedMsg.data = msg
        self.regulator_status_msg_holder = typedMsg

    def handle_monitor_status(self, msg):
        typedMsg = Status()
        typedMsg.data = msg
        self.monitor_status_msg_holder = typedMsg

    def handle_display_temperature(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.display_temperature_msg_holder = typedMsg

    def handle_alarm_control(self, msg):
        typedMsg = OnOff()
        typedMsg.data = msg
        self.alarm_control_msg_holder = typedMsg

    def get_regulator_status(self):
        return self.regulator_status_msg_holder

    def get_monitor_status(self):
        return self.monitor_status_msg_holder

    def get_display_temperature(self):
        return self.display_temperature_msg_holder

    def get_alarm_control(self):
        return self.alarm_control_msg_holder

    def put_lower_desired_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.operator_interface_oip_oit_lower_desired_tempWstatus_publisher_.publish(typedMsg)

    def put_upper_desired_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.operator_interface_oip_oit_upper_desired_tempWstatus_publisher_.publish(typedMsg)

    def put_lower_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_.publish(typedMsg)

    def put_upper_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_1.publish(typedMsg)
        operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_2.publish(typedMsg)

