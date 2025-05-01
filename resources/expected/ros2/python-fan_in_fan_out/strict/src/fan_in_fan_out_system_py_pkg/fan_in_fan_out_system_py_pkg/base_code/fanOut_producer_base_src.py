#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from fan_in_fan_out_system_py_pkg_interfaces.msg import Integer64

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class fanOut_producer_base(Node):
    def __init__(self):
        super().__init__("fanOut_producer")

        self.cb_group_ = ReentrantCallbackGroup()

        MsgType = Union[Integer64]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.fanOut_producer_myInteger_publisher_1 = self.create_publisher(
            Integer64,
            "fanOut_consumer1_myInteger",
            1)

        self.fanOut_producer_myInteger_publisher_2 = self.create_publisher(
            Integer64,
            "fanOut_consumer2_myInteger",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggeredCaller, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

        self.infrastructureOut_myInteger = Queue()
        self.applicationOut_myInteger = Queue()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_myInteger, self.infrastructureOut_myInteger, self.sendOut_myInteger]
        ]

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def sendOut_myInteger(self, msg):
        if type(msg) is Integer64:
            typedMsg = Integer64()
            typedMsg.data = msg
            self.fanOut_producer_myInteger_publisher_1.publish(typedMsg)
            self.fanOut_producer_myInteger_publisher_2.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_myInteger(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_myInteger, typedMsg)

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
