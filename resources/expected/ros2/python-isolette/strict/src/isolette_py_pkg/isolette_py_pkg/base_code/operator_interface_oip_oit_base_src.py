#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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

        MsgType = Union[Status, Tempimpl, OnOff, TempWstatusimpl]
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
        self.periodTimer_ = self.create_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

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

        self.infrastructureIn_regulator_status = Queue()
        self.applicationIn_regulator_status = Queue()
        self.infrastructureIn_monitor_status = Queue()
        self.applicationIn_monitor_status = Queue()
        self.infrastructureIn_display_temperature = Queue()
        self.applicationIn_display_temperature = Queue()
        self.infrastructureIn_alarm_control = Queue()
        self.applicationIn_alarm_control = Queue()

        self.infrastructureOut_lower_desired_tempWstatus = Queue()
        self.applicationOut_lower_desired_tempWstatus = Queue()
        self.infrastructureOut_upper_desired_tempWstatus = Queue()
        self.applicationOut_upper_desired_tempWstatus = Queue()
        self.infrastructureOut_lower_alarm_tempWstatus = Queue()
        self.applicationOut_lower_alarm_tempWstatus = Queue()
        self.infrastructureOut_upper_alarm_tempWstatus = Queue()
        self.applicationOut_upper_alarm_tempWstatus = Queue()

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_lower_desired_tempWstatus, self.infrastructureOut_lower_desired_tempWstatus, self.sendOut_lower_desired_tempWstatus],
            [self.applicationOut_upper_desired_tempWstatus, self.infrastructureOut_upper_desired_tempWstatus, self.sendOut_upper_desired_tempWstatus],
            [self.applicationOut_lower_alarm_tempWstatus, self.infrastructureOut_lower_alarm_tempWstatus, self.sendOut_lower_alarm_tempWstatus],
            [self.applicationOut_upper_alarm_tempWstatus, self.infrastructureOut_upper_alarm_tempWstatus, self.sendOut_upper_alarm_tempWstatus]
         ]

#=================================================
#  C o m m u n i c a t i o n
#=================================================

    def accept_regulator_status(self, msg):
        typedMsg = Status()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_regulator_status, msg)

    def accept_monitor_status(self, msg):
        typedMsg = Status()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_monitor_status, msg)

    def accept_display_temperature(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_display_temperature, msg)

    def accept_alarm_control(self, msg):
        typedMsg = OnOff()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_alarm_control, msg)

    def get_regulator_status(self):
        msg = applicationIn_regulator_status.front()
        return get(msg)

    def get_monitor_status(self):
        msg = applicationIn_monitor_status.front()
        return get(msg)

    def get_display_temperature(self):
        msg = applicationIn_display_temperature.front()
        return get(msg)

    def get_alarm_control(self):
        msg = applicationIn_alarm_control.front()
        return get(msg)

    def sendOut_lower_desired_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            typedMsg = TempWstatusimpl()
            typedMsg.data = msg
            self.operator_interface_oip_oit_lower_desired_tempWstatus_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port lower_desired_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_upper_desired_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            typedMsg = TempWstatusimpl()
            typedMsg.data = msg
            self.operator_interface_oip_oit_upper_desired_tempWstatus_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port upper_desired_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_lower_alarm_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            typedMsg = TempWstatusimpl()
            typedMsg.data = msg
            self.operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port lower_alarm_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_upper_alarm_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            typedMsg = TempWstatusimpl()
            typedMsg.data = msg
            self.operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_1.publish(typedMsg)
            self.operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_2.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port upper_alarm_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_lower_desired_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_lower_desired_tempWstatus, typedMsg)

    def put_upper_desired_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_upper_desired_tempWstatus, typedMsg)

    def put_lower_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_lower_alarm_tempWstatus, typedMsg)

    def put_upper_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_upper_alarm_tempWstatus, typedMsg)

    def timeTriggeredCaller(self):
        self.receiveInputs()
        self.timeTriggered()
        self.sendOutputs()

    def receiveInputs(self):
        for port in self.inDataPortTupleVector:
            infrastructureQueue = port[0]
            if not(infrastructureQueue.empty()):
                msg = infrastructureQueue.front()
                self.enqueue(*port[1], msg)

        for port in self.inEventPortTupleVector:
            infrastructureQueue = port[0]
            if not(infrastructureQueue.empty()):
                msg = infrastructureQueue.front()
                infrastructureQueue.pop()
                self.enqueue(port[1], msg)

    def enqueue(self, queue, val):
        if queue.size() >= 1:
            queue.pop()
        queue.push(val)

    def sendOutputs(self):
        for port in self.outPortTupleVector:
            applicationQueue = port[0]
            if applicationQueue.size() != 0:
                msg = applicationQueue.front()
                applicationQueue.pop()
                self.enqueue(port[1], msg)

        for port in self.outPortTupleVector:
            infrastructureQueue = port[1]
            if infrastructureQueue.size() != 0:
                msg = infrastructureQueue.front()
                infrastructureQueue.pop()
                (port[2])(msg)
