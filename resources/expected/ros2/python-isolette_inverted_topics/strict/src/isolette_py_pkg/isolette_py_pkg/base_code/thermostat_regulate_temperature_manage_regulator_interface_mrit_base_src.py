#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import TempWstatusimpl
from isolette_py_pkg_interfaces.msg import RegulatorMode
from isolette_py_pkg_interfaces.msg import Tempimpl
from isolette_py_pkg_interfaces.msg import Status
from isolette_py_pkg_interfaces.msg import FailureFlagimpl

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class thermostat_regulate_temperature_manage_regulator_interface_mrit_base(Node):
    def __init__(self):
        super().__init__("thermostat_regulate_temperature_manage_regulator_interface_mrit")

        self.cb_group_ = ReentrantCallbackGroup()

        self.lock_ = threading.Lock()

        # Setting up connections
        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "temperature_sensor_cpi_thermostat_current_tempWstatus",
            self.accept_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "operator_interface_oip_oit_lower_desired_tempWstatus",
            self.accept_lower_desired_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "operator_interface_oip_oit_upper_desired_tempWstatus",
            self.accept_upper_desired_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode_subscription_ = self.create_subscription(
            RegulatorMode,
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode",
            self.accept_regulator_mode,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_ = self.create_publisher(
            Tempimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp",
            1)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_ = self.create_publisher(
            Tempimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp",
            1)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_ = self.create_publisher(
            Tempimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp",
            1)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_ = self.create_publisher(
            Status,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status",
            1)

        self.thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_ = self.create_publisher(
            FailureFlagimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureIn_current_tempWstatus = deque()
        self.applicationIn_current_tempWstatus = deque()
        self.infrastructureIn_lower_desired_tempWstatus = deque()
        self.applicationIn_lower_desired_tempWstatus = deque()
        self.infrastructureIn_upper_desired_tempWstatus = deque()
        self.applicationIn_upper_desired_tempWstatus = deque()
        self.infrastructureIn_regulator_mode = deque()
        self.applicationIn_regulator_mode = deque()

        self.infrastructureOut_upper_desired_temp = deque()
        self.applicationOut_upper_desired_temp = deque()
        self.infrastructureOut_lower_desired_temp = deque()
        self.applicationOut_lower_desired_temp = deque()
        self.infrastructureOut_displayed_temp = deque()
        self.applicationOut_displayed_temp = deque()
        self.infrastructureOut_regulator_status = deque()
        self.applicationOut_regulator_status = deque()
        self.infrastructureOut_interface_failure = deque()
        self.applicationOut_interface_failure = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_lower_desired_tempWstatus, self.applicationIn_lower_desired_tempWstatus],
            [self.infrastructureIn_upper_desired_tempWstatus, self.applicationIn_upper_desired_tempWstatus],
            [self.infrastructureIn_regulator_mode, self.applicationIn_regulator_mode]
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_lower_desired_tempWstatus, self.applicationIn_lower_desired_tempWstatus],
            [self.infrastructureIn_upper_desired_tempWstatus, self.applicationIn_upper_desired_tempWstatus],
            [self.infrastructureIn_regulator_mode, self.applicationIn_regulator_mode]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_upper_desired_temp, self.infrastructureOut_upper_desired_temp, self.sendOut_upper_desired_temp],
            [self.applicationOut_lower_desired_temp, self.infrastructureOut_lower_desired_temp, self.sendOut_lower_desired_temp],
            [self.applicationOut_displayed_temp, self.infrastructureOut_displayed_temp, self.sendOut_displayed_temp],
            [self.applicationOut_regulator_status, self.infrastructureOut_regulator_status, self.sendOut_regulator_status],
            [self.applicationOut_interface_failure, self.infrastructureOut_interface_failure, self.sendOut_interface_failure]
        ]

    def init_current_tempWstatus(self, val):
        self.enqueue(self.infrastructureIn_current_tempWstatus, val)


    def init_lower_desired_tempWstatus(self, val):
        self.enqueue(self.infrastructureIn_lower_desired_tempWstatus, val)


    def init_upper_desired_tempWstatus(self, val):
        self.enqueue(self.infrastructureIn_upper_desired_tempWstatus, val)


    def init_regulator_mode(self, val):
        self.enqueue(self.infrastructureIn_regulator_mode, val)


    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_current_tempWstatus(self, msg):
        self.enqueue(self.infrastructureIn_current_tempWstatus, msg)

    def accept_lower_desired_tempWstatus(self, msg):
        self.enqueue(self.infrastructureIn_lower_desired_tempWstatus, msg)

    def accept_upper_desired_tempWstatus(self, msg):
        self.enqueue(self.infrastructureIn_upper_desired_tempWstatus, msg)

    def accept_regulator_mode(self, msg):
        self.enqueue(self.infrastructureIn_regulator_mode, msg)

    def get_current_tempWstatus(self):
        msg = self.applicationIn_current_tempWstatus[0]
        return msg

    def get_lower_desired_tempWstatus(self):
        msg = self.applicationIn_lower_desired_tempWstatus[0]
        return msg

    def get_upper_desired_tempWstatus(self):
        msg = self.applicationIn_upper_desired_tempWstatus[0]
        return msg

    def get_regulator_mode(self):
        msg = self.applicationIn_regulator_mode[0]
        return msg

    def sendOut_upper_desired_temp(self, msg):
        if type(msg) is Tempimpl:
            self.thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port upper_desired_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_lower_desired_temp(self, msg):
        if type(msg) is Tempimpl:
            self.thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port lower_desired_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_displayed_temp(self, msg):
        if type(msg) is Tempimpl:
            self.thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port displayed_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_regulator_status(self, msg):
        if type(msg) is Status:
            self.thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port regulator_status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_interface_failure(self, msg):
        if type(msg) is FailureFlagimpl:
            self.thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port interface_failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_upper_desired_temp(self, msg):
        self.enqueue(self.applicationOut_upper_desired_temp, msg)

    def put_lower_desired_temp(self, msg):
        self.enqueue(self.applicationOut_lower_desired_temp, msg)

    def put_displayed_temp(self, msg):
        self.enqueue(self.applicationOut_displayed_temp, msg)

    def put_regulator_status(self, msg):
        self.enqueue(self.applicationOut_regulator_status, msg)

    def put_interface_failure(self, msg):
        self.enqueue(self.applicationOut_interface_failure, msg)

    def timeTriggeredCaller(self):
        self.receiveInputs()
        self.timeTriggered()
        self.sendOutputs()

    def receiveInputs(self):
        for port in self.inDataPortTupleVector:
            infrastructureQueue = port[0]
            if not(len(infrastructureQueue) == 0):
                msg = infrastructureQueue[0]
                self.enqueue(port[1], msg)

        for port in self.inEventPortTupleVector:
            infrastructureQueue = port[0]
            if not(len(infrastructureQueue) == 0):
                msg = infrastructureQueue[0]
                infrastructureQueue.pop()
                self.enqueue(port[1], msg)

    def enqueue(self, queue, val):
        if len(queue) >= 1:
            queue.pop()
        queue.append(val)

    def sendOutputs(self):
        for port in self.outPortTupleVector:
            applicationQueue = port[0]
            if len(applicationQueue) != 0:
                msg = applicationQueue[0]
                applicationQueue.pop()
                self.enqueue(port[1], msg)

        for port in self.outPortTupleVector:
            infrastructureQueue = port[1]
            if len(infrastructureQueue) != 0:
                msg = infrastructureQueue[0]
                infrastructureQueue.pop()
                (port[2])(msg)
