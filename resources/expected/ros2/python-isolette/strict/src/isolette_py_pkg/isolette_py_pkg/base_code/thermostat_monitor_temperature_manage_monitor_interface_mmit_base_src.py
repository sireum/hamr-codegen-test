#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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

        MsgType = Union[TempWstatusimpl, MonitorMode, Tempimpl, Status, FailureFlagimpl]
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
        self.periodTimer_ = self.create_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

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

        self.infrastructureIn_upper_alarm_tempWstatus = Queue()
        self.applicationIn_upper_alarm_tempWstatus = Queue()
        self.infrastructureIn_lower_alarm_tempWstatus = Queue()
        self.applicationIn_lower_alarm_tempWstatus = Queue()
        self.infrastructureIn_current_tempWstatus = Queue()
        self.applicationIn_current_tempWstatus = Queue()
        self.infrastructureIn_monitor_mode = Queue()
        self.applicationIn_monitor_mode = Queue()

        self.infrastructureOut_upper_alarm_temp = Queue()
        self.applicationOut_upper_alarm_temp = Queue()
        self.infrastructureOut_lower_alarm_temp = Queue()
        self.applicationOut_lower_alarm_temp = Queue()
        self.infrastructureOut_monitor_status = Queue()
        self.applicationOut_monitor_status = Queue()
        self.infrastructureOut_interface_failure = Queue()
        self.applicationOut_interface_failure = Queue()

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_upper_alarm_temp, self.infrastructureOut_upper_alarm_temp, self.sendOut_upper_alarm_temp],
            [self.applicationOut_lower_alarm_temp, self.infrastructureOut_lower_alarm_temp, self.sendOut_lower_alarm_temp],
            [self.applicationOut_monitor_status, self.infrastructureOut_monitor_status, self.sendOut_monitor_status],
            [self.applicationOut_interface_failure, self.infrastructureOut_interface_failure, self.sendOut_interface_failure]
         ]

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_upper_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_upper_alarm_tempWstatus, msg)

    def accept_lower_alarm_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_lower_alarm_tempWstatus, msg)

    def accept_current_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_current_tempWstatus, msg)

    def accept_monitor_mode(self, msg):
        typedMsg = MonitorMode()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_monitor_mode, msg)

    def get_upper_alarm_tempWstatus(self):
        msg = applicationIn_upper_alarm_tempWstatus.front()
        return get(msg)

    def get_lower_alarm_tempWstatus(self):
        msg = applicationIn_lower_alarm_tempWstatus.front()
        return get(msg)

    def get_current_tempWstatus(self):
        msg = applicationIn_current_tempWstatus.front()
        return get(msg)

    def get_monitor_mode(self):
        msg = applicationIn_monitor_mode.front()
        return get(msg)

    def sendOut_upper_alarm_temp(self, msg):
        if type(msg) is Tempimpl:
            typedMsg = Tempimpl()
            typedMsg.data = msg
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port upper_alarm_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_lower_alarm_temp(self, msg):
        if type(msg) is Tempimpl:
            typedMsg = Tempimpl()
            typedMsg.data = msg
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port lower_alarm_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_monitor_status(self, msg):
        if type(msg) is Status:
            typedMsg = Status()
            typedMsg.data = msg
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port monitor_status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_interface_failure(self, msg):
        if type(msg) is FailureFlagimpl:
            typedMsg = FailureFlagimpl()
            typedMsg.data = msg
            self.thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port interface_failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_upper_alarm_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_upper_alarm_temp, typedMsg)

    def put_lower_alarm_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_lower_alarm_temp, typedMsg)

    def put_monitor_status(self, msg):
        typedMsg = Status()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_monitor_status, typedMsg)

    def put_interface_failure(self, msg):
        typedMsg = FailureFlagimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_interface_failure, typedMsg)

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
