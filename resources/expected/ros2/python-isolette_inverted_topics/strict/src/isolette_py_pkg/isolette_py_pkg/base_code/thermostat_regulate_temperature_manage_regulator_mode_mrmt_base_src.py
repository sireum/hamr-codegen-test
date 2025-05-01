#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from typing import Union
import threading
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

        MsgType = Union[TempWstatusimpl, FailureFlagimpl, RegulatorMode]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "temperature_sensor_cpi_thermostat_current_tempWstatus",
            self.accept_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure",
            self.accept_interface_failure,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_ = self.create_subscription(
            FailureFlagimpl,
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure",
            self.accept_internal_failure,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_ = self.create_publisher(
            RegulatorMode,
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

        self.infrastructureIn_current_tempWstatus = Queue()
        self.applicationIn_current_tempWstatus = Queue()
        self.infrastructureIn_interface_failure = Queue()
        self.applicationIn_interface_failure = Queue()
        self.infrastructureIn_internal_failure = Queue()
        self.applicationIn_internal_failure = Queue()

        self.infrastructureOut_regulator_mode = Queue()
        self.applicationOut_regulator_mode = Queue()

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
            [self.applicationOut_regulator_mode, self.infrastructureOut_regulator_mode, self.sendOut_regulator_mode]
        ]

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_current_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_current_tempWstatus, msg)

    def accept_interface_failure(self, msg):
        typedMsg = FailureFlagimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_interface_failure, msg)

    def accept_internal_failure(self, msg):
        typedMsg = FailureFlagimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_internal_failure, msg)

    def get_current_tempWstatus(self):
        msg = applicationIn_current_tempWstatus.front()
        return get(msg)

    def get_interface_failure(self):
        msg = applicationIn_interface_failure.front()
        return get(msg)

    def get_internal_failure(self):
        msg = applicationIn_internal_failure.front()
        return get(msg)

    def sendOut_regulator_mode(self, msg):
        if type(msg) is RegulatorMode:
            typedMsg = RegulatorMode()
            typedMsg.data = msg
            self.thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port regulator_mode.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_regulator_mode(self, msg):
        typedMsg = RegulatorMode()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_regulator_mode, typedMsg)

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
