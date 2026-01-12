#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
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

        self.lock_ = threading.Lock()

        # Setting up connections
        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus",
            self.accept_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure",
            self.accept_interface_failure,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure",
            self.accept_internal_failure,
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

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureIn_current_tempWstatus = deque()
        self.applicationIn_current_tempWstatus = deque()
        self.infrastructureIn_interface_failure = deque()
        self.applicationIn_interface_failure = deque()
        self.infrastructureIn_internal_failure = deque()
        self.applicationIn_internal_failure = deque()

        self.infrastructureOut_monitor_mode = deque()
        self.applicationOut_monitor_mode = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_interface_failure, self.applicationIn_interface_failure],
            [self.infrastructureIn_internal_failure, self.applicationIn_internal_failure]
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_interface_failure, self.applicationIn_interface_failure],
            [self.infrastructureIn_internal_failure, self.applicationIn_internal_failure]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_monitor_mode, self.infrastructureOut_monitor_mode, self.sendOut_monitor_mode]
        ]

    def init_current_tempWstatus(self, val):
        self.enqueue(self.infrastructureIn_current_tempWstatus, val)


    def init_interface_failure(self, val):
        self.enqueue(self.infrastructureIn_interface_failure, val)


    def init_internal_failure(self, val):
        self.enqueue(self.infrastructureIn_internal_failure, val)


    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_current_tempWstatus(self, msg):
        self.enqueue(self.infrastructureIn_current_tempWstatus, msg)

    def accept_interface_failure(self, msg):
        self.enqueue(self.infrastructureIn_interface_failure, msg)

    def accept_internal_failure(self, msg):
        self.enqueue(self.infrastructureIn_internal_failure, msg)

    def get_current_tempWstatus(self):
        msg = self.applicationIn_current_tempWstatus[0]
        return msg

    def get_interface_failure(self):
        msg = self.applicationIn_interface_failure[0]
        return msg

    def get_internal_failure(self):
        msg = self.applicationIn_internal_failure[0]
        return msg

    def sendOut_monitor_mode(self, msg):
        if type(msg) is MonitorMode:
            self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1.publish(msg)
            self.thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port monitor_mode.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_monitor_mode(self, msg):
        self.enqueue(self.applicationOut_monitor_mode, msg)

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
