#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from building_control_py_pkg_interfaces.msg import Temperatureimpl
from building_control_py_pkg_interfaces.msg import Empty

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class tcp_tempSensor_base(Node):
    def __init__(self):
        super().__init__("tcp_tempSensor")

        self.cb_group_ = ReentrantCallbackGroup()

        self.lock_ = threading.Lock()

        # Setting up connections
        self.tcp_tempSensor_currentTemp_publisher_ = self.create_publisher(
            Temperatureimpl,
            "tcp_tempSensor_currentTemp",
            1)

        self.tcp_tempSensor_tempChanged_publisher_ = self.create_publisher(
            Empty,
            "tcp_tempSensor_tempChanged",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureOut_currentTemp = deque()
        self.applicationOut_currentTemp = deque()
        self.infrastructureOut_tempChanged = deque()
        self.applicationOut_tempChanged = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_currentTemp, self.infrastructureOut_currentTemp, self.sendOut_currentTemp],
            [self.applicationOut_tempChanged, self.infrastructureOut_tempChanged, self.sendOut_tempChanged]
        ]

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def sendOut_currentTemp(self, msg):
        if type(msg) is Temperatureimpl:
            self.tcp_tempSensor_currentTemp_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port currentTemp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_tempChanged(self, msg):
        if type(msg) is Empty:
            self.tcp_tempSensor_tempChanged_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port tempChanged.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_currentTemp(self, msg):
        self.enqueue(self.applicationOut_currentTemp, msg)

    def put_tempChanged(self):
        self.enqueue(self.applicationOut_tempChanged, Empty())

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
