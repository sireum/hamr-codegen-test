#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from fan_in_fan_out_system_py_pkg_interfaces.msg import Integer64

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class fanIn_consumer_base(Node):
    def __init__(self):
        super().__init__("fanIn_consumer")

        self.cb_group_ = ReentrantCallbackGroup()

        self.lock_ = threading.Lock()

        # Setting up connections
        self.fanIn_consumer_myInteger_subscription_1 = self.create_subscription(
            Integer64,
            "fanIn_producer1_myInteger",
            self.accept_myInteger,
            1,
            callback_group=self.cb_group_)

        self.fanIn_consumer_myInteger_subscription_2 = self.create_subscription(
            Integer64,
            "fanIn_producer2_myInteger",
            self.accept_myInteger,
            1,
            callback_group=self.cb_group_)

        self.infrastructureIn_myInteger = deque()
        self.applicationIn_myInteger = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
        ]

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def myInteger_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myInteger, self.applicationIn_myInteger)
            if len(self.applicationIn_myInteger) == 0: return
            self.handle_myInteger_base(self.applicationIn_myInteger[0])
            self.applicationIn_myInteger.pop()
            self.sendOutputs()

    def accept_myInteger(self, msg):
        self.enqueue(self.infrastructureIn_myInteger, msg)
        thread = threading.Thread(target=self.myInteger_thread)
        thread.daemon = True
        thread.start()


    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_myInteger(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myInteger_base(self, msg):
        if type(msg) is Integer64:
            self.handle_myInteger(msg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")


    def receiveInputs(self, infrastructureQueue, applicationQueue):
        if not(len(infrastructureQueue) == 0):
            eventMsg = infrastructureQueue[0]
            infrastructureQueue.pop()
            self.enqueue(applicationQueue, eventMsg)

        for port in self.inDataPortTupleVector:
            infrastructureQueue = port[0]
            if not(len(infrastructureQueue) == 0):
                msg = infrastructureQueue[0]
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
