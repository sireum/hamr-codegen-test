#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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

        MsgType = Union[Temperatureimpl, Empty]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.tcp_tempSensor_currentTemp_publisher_ = self.create_publisher(
            Temperatureimpl,
            "tcp_tempControl_currentTemp",
            1)

        self.tcp_tempSensor_tempChanged_publisher_ = self.create_publisher(
            Empty,
            "tcp_tempControl_tempChanged",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

        self.infrastructureOut_currentTemp = Queue()
        self.applicationOut_currentTemp = Queue()
        self.infrastructureOut_tempChanged = Queue()
        self.applicationOut_tempChanged = Queue()

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

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def sendOut_currentTemp(self, msg):
        if type(msg) is Temperatureimpl:
            typedMsg = Temperatureimpl()
            typedMsg.data = msg
            self.tcp_tempSensor_currentTemp_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port currentTemp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_tempChanged(self, msg):
        if type(msg) is Empty:
            typedMsg = Empty()
            typedMsg.data = msg
            self.tcp_tempSensor_tempChanged_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port tempChanged.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_currentTemp(self, msg):
        typedMsg = Temperatureimpl()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_currentTemp, typedMsg)

    def put_tempChanged(self, msg):
        self.enqueue(self.applicationOut_tempChanged, Empty())

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
