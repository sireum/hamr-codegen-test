#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from typing import Union
import threading
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

        MsgType = Union[TempWstatusimpl, Tempimpl, RegulatorMode, OnOff]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus_subscription_ = self.create_subscription(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus",
            self.accept_current_tempWstatus,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp",
            self.accept_lower_desired_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp_subscription_ = self.create_subscription(
            Tempimpl,
            "thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp",
            self.accept_upper_desired_temp,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode_subscription_ = self.create_subscription(
            RegulatorMode,
            "thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode",
            self.accept_regulator_mode,
            1,
            callback_group=self.cb_group_)

        self.thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_ = self.create_publisher(
            OnOff,
            "heat_source_cpi_heat_controller_heat_control",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_lower_desired_temp, self.applicationIn_lower_desired_temp],
            [self.infrastructureIn_upper_desired_temp, self.applicationIn_upper_desired_temp],
            [self.infrastructureIn_regulator_mode, self.applicationIn_regulator_mode]
         ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
            [self.infrastructureIn_current_tempWstatus, self.applicationIn_current_tempWstatus],
            [self.infrastructureIn_lower_desired_temp, self.applicationIn_lower_desired_temp],
            [self.infrastructureIn_upper_desired_temp, self.applicationIn_upper_desired_temp],
            [self.infrastructureIn_regulator_mode, self.applicationIn_regulator_mode]
          ]

        self.infrastructureIn_current_tempWstatus = Queue()
        self.applicationIn_current_tempWstatus = Queue()
        self.infrastructureIn_lower_desired_temp = Queue()
        self.applicationIn_lower_desired_temp = Queue()
        self.infrastructureIn_upper_desired_temp = Queue()
        self.applicationIn_upper_desired_temp = Queue()
        self.infrastructureIn_regulator_mode = Queue()
        self.applicationIn_regulator_mode = Queue()

        self.infrastructureOut_heat_control = Queue()
        self.applicationOut_heat_control = Queue()

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_heat_control, self.infrastructureOut_heat_control, self.sendOut_heat_control]
         ]

#=================================================
#  C o m m u n i c a t i o n
#=================================================

    def accept_current_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_current_tempWstatus, msg)

    def accept_lower_desired_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_lower_desired_temp, msg)

    def accept_upper_desired_temp(self, msg):
        typedMsg = Tempimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_upper_desired_temp, msg)

    def accept_regulator_mode(self, msg):
        typedMsg = RegulatorMode()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_regulator_mode, msg)

    def get_current_tempWstatus(self):
        msg = applicationIn_current_tempWstatus.front()
        return get(msg)

    def get_lower_desired_temp(self):
        msg = applicationIn_lower_desired_temp.front()
        return get(msg)

    def get_upper_desired_temp(self):
        msg = applicationIn_upper_desired_temp.front()
        return get(msg)

    def get_regulator_mode(self):
        msg = applicationIn_regulator_mode.front()
        return get(msg)

    def sendOut_heat_control(self, msg):
        if type(msg) is OnOff:
            typedMsg = OnOff()
            typedMsg.data = msg
            self.thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port heat_control.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_heat_control(self, msg):
        typedMsg = OnOff()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_heat_control, typedMsg)

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
