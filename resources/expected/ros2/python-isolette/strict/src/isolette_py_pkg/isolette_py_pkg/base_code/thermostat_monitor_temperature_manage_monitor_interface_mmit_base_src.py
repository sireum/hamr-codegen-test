#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
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

        self.lock_ = threading.Lock()

        # Setting up connections
        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus",
            self.accept_upper_alarm_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus",
            self.accept_lower_alarm_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus",
            self.accept_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_ = self.create_subscription(
            MonitorMode,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode",
            self.accept_monitor_mode,
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

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureIn_upper_alarm_tempWstatus = deque()
        self.applicationIn_upper_alarm_tempWstatus = deque()
        self.infrastructureIn_lower_alarm_tempWstatus = deque()
        self.applicationIn_lower_alarm_tempWstatus = deque()
        self.infrastructureIn_current_tempWstatus = deque()
        self.applicationIn_current_tempWstatus = deque()
        self.infrastructureIn_monitor_mode = deque()
        self.applicationIn_monitor_mode = deque()

        self.infrastructureOut_upper_alarm_temp = deque()
        self.applicationOut_upper_alarm_temp = deque()
        self.infrastructureOut_lower_alarm_temp = deque()
        self.applicationOut_lower_alarm_temp = deque()
        self.infrastructureOut_monitor_status = deque()
        self.applicationOut_monitor_status = deque()
        self.infrastructureOut_interface_failure = deque()
        self.applicationOut_interface_failure = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_upper_alarm_tempWstatus, self.applicationIn_upper_alarm_tempWstatus],
            [self.infrastructureIn_lower_alarm_tempWstatus, self.applicationIn_lower_alarm_tempWstatus],
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_monitor_mode, self.applicationIn_monitor_mode]
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
            [self.infrastructureIn_upper_alarm_tempWstatus, self.applicationIn_upper_alarm_tempWstatus],
            [self.infrastructureIn_lower_alarm_tempWstatus, self.applicationIn_lower_alarm_tempWstatus],
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_monitor_mode, self.applicationIn_monitor_mode]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_upper_alarm_temp, self.infrastructureOut_upper_alarm_temp, self.sendOut_upper_alarm_temp],
            [self.applicationOut_lower_alarm_temp, self.infrastructureOut_lower_alarm_temp, self.sendOut_lower_alarm_temp],
            [self.applicationOut_monitor_status, self.infrastructureOut_monitor_status, self.sendOut_monitor_status],
            [self.applicationOut_interface_failure, self.infrastructureOut_interface_failure, self.sendOut_interface_failure]
        ]

    def init_upper_alarm_tempWstatus(self, val):
        self.enqueue(self.infrastructureIn_upper_alarm_tempWstatus, val)


    def init_lower_alarm_tempWstatus(self, val):
        self.enqueue(self.infrastructureIn_lower_alarm_tempWstatus, val)


    def init_current_tempWstatus(self, val):
        self.enqueue(self.infrastructureIn_current_tempWstatus, val)


    def init_monitor_mode(self, val):
        self.enqueue(self.infrastructureIn_monitor_mode, val)


    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_upper_alarm_tempWstatus(self, msg):
        self.enqueue(self.infrastructureIn_upper_alarm_tempWstatus, msg)

    def accept_lower_alarm_tempWstatus(self, msg):
        self.enqueue(self.infrastructureIn_lower_alarm_tempWstatus, msg)

    def accept_current_tempWstatus(self, msg):
        self.enqueue(self.infrastructureIn_current_tempWstatus, msg)

    def accept_monitor_mode(self, msg):
        self.enqueue(self.infrastructureIn_monitor_mode, msg)

    def get_upper_alarm_tempWstatus(self):
        msg = self.applicationIn_upper_alarm_tempWstatus[0]
        return msg

    def get_lower_alarm_tempWstatus(self):
        msg = self.applicationIn_lower_alarm_tempWstatus[0]
        return msg

    def get_current_tempWstatus(self):
        msg = self.applicationIn_current_tempWstatus[0]
        return msg

    def get_monitor_mode(self):
        msg = self.applicationIn_monitor_mode[0]
        return msg

    def sendOut_upper_alarm_temp(self, msg):
        if type(msg) is Tempimpl:
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port upper_alarm_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_lower_alarm_temp(self, msg):
        if type(msg) is Tempimpl:
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port lower_alarm_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_monitor_status(self, msg):
        if type(msg) is Status:
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port monitor_status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_interface_failure(self, msg):
        if type(msg) is FailureFlagimpl:
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port interface_failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_upper_alarm_temp(self, msg):
        self.enqueue(self.applicationOut_upper_alarm_temp, msg)

    def put_lower_alarm_temp(self, msg):
        self.enqueue(self.applicationOut_lower_alarm_temp, msg)

    def put_monitor_status(self, msg):
        self.enqueue(self.applicationOut_monitor_status, msg)

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
