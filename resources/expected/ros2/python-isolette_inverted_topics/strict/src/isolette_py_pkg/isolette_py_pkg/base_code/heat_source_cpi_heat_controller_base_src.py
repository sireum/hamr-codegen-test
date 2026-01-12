#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import OnOff
from isolette_py_pkg_interfaces.msg import Heat

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class heat_source_cpi_heat_controller_base(Node):
    def __init__(self):
        super().__init__("heat_source_cpi_heat_controller")

        self.cb_group_ = ReentrantCallbackGroup()

        self.lock_ = threading.Lock()

        # Setting up connections
        self.heat_source_cpi_heat_controller_heat_control_subscription_ = self.create_subscription(
            OnOff,
            "thermostat_regulate_temperature_manage_heat_source_mhst_heat_control",
            self.accept_heat_control,
            1,
            callback_group=self.cb_group_)

        self.heat_source_cpi_heat_controller_heat_out_publisher_ = self.create_publisher(
            Heat,
            "heat_source_cpi_heat_controller_heat_out",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureIn_heat_control = deque()
        self.applicationIn_heat_control = deque()

        self.infrastructureOut_heat_out = deque()
        self.applicationOut_heat_out = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_heat_control, self.applicationIn_heat_control]
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
            [self.infrastructureIn_heat_control, self.applicationIn_heat_control]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_heat_out, self.infrastructureOut_heat_out, self.sendOut_heat_out]
        ]

    def init_heat_control(self, val):
        self.enqueue(self.infrastructureIn_heat_control, val)


    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_heat_control(self, msg):
        self.enqueue(self.infrastructureIn_heat_control, msg)

    def get_heat_control(self):
        msg = self.applicationIn_heat_control[0]
        return msg

    def sendOut_heat_out(self, msg):
        if type(msg) is Heat:
            self.heat_source_cpi_heat_controller_heat_out_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port heat_out.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_heat_out(self, msg):
        self.enqueue(self.applicationOut_heat_out, msg)

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
