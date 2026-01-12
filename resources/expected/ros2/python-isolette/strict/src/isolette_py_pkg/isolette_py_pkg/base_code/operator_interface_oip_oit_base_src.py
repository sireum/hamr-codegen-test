#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
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

        self.lock_ = threading.Lock()

        # Setting up connections
        self.operator_interface_oip_oit_regulator_status_subscription_ = self.create_subscription(
            Status,
            "operator_interface_oip_oit_regulator_status",
            self.accept_regulator_status,
            1,
            callback_group=self.cb_group_)

        self.operator_interface_oip_oit_monitor_status_subscription_ = self.create_subscription(
            Status,
            "operator_interface_oip_oit_monitor_status",
            self.accept_monitor_status,
            1,
            callback_group=self.cb_group_)

        self.operator_interface_oip_oit_display_temperature_subscription_ = self.create_subscription(
            Tempimpl,
            "operator_interface_oip_oit_display_temperature",
            self.accept_display_temperature,
            1,
            callback_group=self.cb_group_)

        self.operator_interface_oip_oit_alarm_control_subscription_ = self.create_subscription(
            OnOff,
            "operator_interface_oip_oit_alarm_control",
            self.accept_alarm_control,
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

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureIn_regulator_status = deque()
        self.applicationIn_regulator_status = deque()
        self.infrastructureIn_monitor_status = deque()
        self.applicationIn_monitor_status = deque()
        self.infrastructureIn_display_temperature = deque()
        self.applicationIn_display_temperature = deque()
        self.infrastructureIn_alarm_control = deque()
        self.applicationIn_alarm_control = deque()

        self.infrastructureOut_lower_desired_tempWstatus = deque()
        self.applicationOut_lower_desired_tempWstatus = deque()
        self.infrastructureOut_upper_desired_tempWstatus = deque()
        self.applicationOut_upper_desired_tempWstatus = deque()
        self.infrastructureOut_lower_alarm_tempWstatus = deque()
        self.applicationOut_lower_alarm_tempWstatus = deque()
        self.infrastructureOut_upper_alarm_tempWstatus = deque()
        self.applicationOut_upper_alarm_tempWstatus = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_regulator_status, self.applicationIn_regulator_status],
            [self.infrastructureIn_monitor_status, self.applicationIn_monitor_status],
            [self.infrastructureIn_display_temperature, self.applicationIn_display_temperature],
            [self.infrastructureIn_alarm_control, self.applicationIn_alarm_control]
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
            [self.infrastructureIn_regulator_status, self.applicationIn_regulator_status],
            [self.infrastructureIn_monitor_status, self.applicationIn_monitor_status],
            [self.infrastructureIn_display_temperature, self.applicationIn_display_temperature],
            [self.infrastructureIn_alarm_control, self.applicationIn_alarm_control]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_lower_desired_tempWstatus, self.infrastructureOut_lower_desired_tempWstatus, self.sendOut_lower_desired_tempWstatus],
            [self.applicationOut_upper_desired_tempWstatus, self.infrastructureOut_upper_desired_tempWstatus, self.sendOut_upper_desired_tempWstatus],
            [self.applicationOut_lower_alarm_tempWstatus, self.infrastructureOut_lower_alarm_tempWstatus, self.sendOut_lower_alarm_tempWstatus],
            [self.applicationOut_upper_alarm_tempWstatus, self.infrastructureOut_upper_alarm_tempWstatus, self.sendOut_upper_alarm_tempWstatus]
        ]

    def init_regulator_status(self, val):
        self.enqueue(self.infrastructureIn_regulator_status, val)


    def init_monitor_status(self, val):
        self.enqueue(self.infrastructureIn_monitor_status, val)


    def init_display_temperature(self, val):
        self.enqueue(self.infrastructureIn_display_temperature, val)


    def init_alarm_control(self, val):
        self.enqueue(self.infrastructureIn_alarm_control, val)


    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_regulator_status(self, msg):
        self.enqueue(self.infrastructureIn_regulator_status, msg)

    def accept_monitor_status(self, msg):
        self.enqueue(self.infrastructureIn_monitor_status, msg)

    def accept_display_temperature(self, msg):
        self.enqueue(self.infrastructureIn_display_temperature, msg)

    def accept_alarm_control(self, msg):
        self.enqueue(self.infrastructureIn_alarm_control, msg)

    def get_regulator_status(self):
        msg = self.applicationIn_regulator_status[0]
        return msg

    def get_monitor_status(self):
        msg = self.applicationIn_monitor_status[0]
        return msg

    def get_display_temperature(self):
        msg = self.applicationIn_display_temperature[0]
        return msg

    def get_alarm_control(self):
        msg = self.applicationIn_alarm_control[0]
        return msg

    def sendOut_lower_desired_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            self.operator_interface_oip_oit_lower_desired_tempWstatus_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port lower_desired_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_upper_desired_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            self.operator_interface_oip_oit_upper_desired_tempWstatus_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port upper_desired_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_lower_alarm_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            self.operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port lower_alarm_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_upper_alarm_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            self.operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_1.publish(msg)
            self.operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_2.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port upper_alarm_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_lower_desired_tempWstatus(self, msg):
        self.enqueue(self.applicationOut_lower_desired_tempWstatus, msg)

    def put_upper_desired_tempWstatus(self, msg):
        self.enqueue(self.applicationOut_upper_desired_tempWstatus, msg)

    def put_lower_alarm_tempWstatus(self, msg):
        self.enqueue(self.applicationOut_lower_alarm_tempWstatus, msg)

    def put_upper_alarm_tempWstatus(self, msg):
        self.enqueue(self.applicationOut_upper_alarm_tempWstatus, msg)

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
