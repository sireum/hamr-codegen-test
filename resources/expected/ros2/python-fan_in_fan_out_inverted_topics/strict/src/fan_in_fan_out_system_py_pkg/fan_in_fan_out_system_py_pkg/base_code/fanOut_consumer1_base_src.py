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

class fanOut_consumer1_base(Node):
    def __init__(self):
        super().__init__("fanOut_consumer1")

        self.cb_group_ = ReentrantCallbackGroup()

        MsgType = Union[Integer64]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.fanOut_consumer1_myInteger_subscription_ = self.create_subscription(
            Integer64,
            "fanOut_producer_myInteger",
            self.accept_myInteger,
            1,
            callback_group=self.cb_group_)

        self.infrastructureIn_myInteger = Queue()
        self.applicationIn_myInteger = Queue()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
        ]

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def myInteger_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_myInteger, self.applicationIn_myInteger)
            if self.applicationIn_myInteger.empty(): return
            self.handle_myInteger_base(self.applicationIn_myInteger.front())
            self.applicationIn_myInteger.pop()
            self.sendOutputs()

    def accept_myInteger(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_myInteger, msg)
        thread = threading.Thread(target=myInteger_thread)
        thread.daemon = True
        thread.start()


    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_myInteger(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myInteger_base(self, msg):
        if type(msg) is Integer64:
            typedMsg = Integer64()
            typedMsg.data = msg
            self.handle_myInteger(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")


    def receiveInputs(self, infrastructureQueue, applicationQueue):
        if not(infrastructureQueue.empty()):
            eventMsg = infrastructureQueue.front()
            infrastructureQueue.pop()
            self.enqueue(applicationQueue, eventMsg)

        for port in self.inDataPortTupleVector:
            infrastructureQueue = port[0]
            if not(infrastructureQueue.empty()):
                msg = infrastructureQueue.front()
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
