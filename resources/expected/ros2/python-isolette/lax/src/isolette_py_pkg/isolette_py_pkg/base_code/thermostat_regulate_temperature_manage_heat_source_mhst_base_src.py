#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from isolette_py_pkg.user_code.thermostat_regulate_temperature_manage_heat_source_mhst_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import Tempimpl
from isolette_py_pkg_interfaces.msg import RegulatorMode
from isolette_py_pkg_interfaces.msg import OnOff

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class thermostat_regulate_temperature_manage_heat_source_mhst_base(Node):
    def __init__(self):
        super().__init__("thermostat_regulate_temperature_manage_heat_source_mhst")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus",
            self.handle_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp",
            self.handle_lower_desired_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp",
            self.handle_upper_desired_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode_subscription_ = self.create_subscription(
            RegulatorMode,
            "thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode",
            self.handle_regulator_mode,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_ = self.create_publisher(
            OnOff,
            "heat_source_cpi_heat_controller_heat_control",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

        self.current_tempWstatus_msg_holder = None
        self.lower_desired_temp_msg_holder = None
        self.upper_desired_temp_msg_holder = None
        self.regulator_mode_msg_holder = None

    def init_current_tempWstatus(self, val):
        self.current_tempWstatus_msg_holder = val

    def init_lower_desired_temp(self, val):
        self.lower_desired_temp_msg_holder = val

    def init_upper_desired_temp(self, val):
        self.upper_desired_temp_msg_holder = val

    def init_regulator_mode(self, val):
        self.regulator_mode_msg_holder = val

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_current_tempWstatus(self, msg):
        self.current_tempWstatus_msg_holder = msg

    def handle_lower_desired_temp(self, msg):
        self.lower_desired_temp_msg_holder = msg

    def handle_upper_desired_temp(self, msg):
        self.upper_desired_temp_msg_holder = msg

    def handle_regulator_mode(self, msg):
        self.regulator_mode_msg_holder = msg

    def get_current_tempWstatus(self):
        return self.current_tempWstatus_msg_holder

    def get_lower_desired_temp(self):
        return self.lower_desired_temp_msg_holder

    def get_upper_desired_temp(self):
        return self.upper_desired_temp_msg_holder

    def get_regulator_mode(self):
        return self.regulator_mode_msg_holder

    def put_heat_control(self, msg):
        self.thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_.publish(msg)

