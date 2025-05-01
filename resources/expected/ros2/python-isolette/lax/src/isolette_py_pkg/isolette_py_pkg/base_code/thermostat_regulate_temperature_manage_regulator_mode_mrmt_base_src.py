#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from isolette_py_pkg.user_code.thermostat_regulate_temperature_manage_regulator_mode_mrmt_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import FailureFlagimpl
from isolette_py_pkg_interfaces.msg import RegulatorMode

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class thermostat_regulate_temperature_manage_regulator_mode_mrmt_base(Node):
    def __init__(self):
        super().__init__("thermostat_regulate_temperature_manage_regulator_mode_mrmt")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus",
            self.handle_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure",
            self.handle_interface_failure,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure",
            self.handle_internal_failure,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_1 = self.create_publisher(
            RegulatorMode,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode",
            1)

        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_2 = self.create_publisher(
            RegulatorMode,
            "thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode",
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

    def handle_interface_failure(self, msg):
        typedMsg = FailureFlagimpl()
        typedMsg.data = msg
        self.interface_failure_msg_holder = typedMsg

    def handle_internal_failure(self, msg):
        typedMsg = FailureFlagimpl()
        typedMsg.data = msg
        self.internal_failure_msg_holder = typedMsg

    def get_current_tempWstatus(self):
        return self.current_tempWstatus_msg_holder

    def get_interface_failure(self):
        return self.interface_failure_msg_holder

    def get_internal_failure(self):
        return self.internal_failure_msg_holder

    def put_regulator_mode(self, msg):
        typedMsg = RegulatorMode()
        typedMsg.data = msg
        thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_1.publish(typedMsg)
        thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_2.publish(typedMsg)

