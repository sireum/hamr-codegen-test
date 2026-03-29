#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from building_control_py_pkg_interfaces.msg import FanCmd
from building_control_py_pkg_interfaces.msg import FanAck

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class tcp_fan_base(Node):
    def __init__(self):
        super().__init__("tcp_fan")

        self.cb_group_ = ReentrantCallbackGroup()

        self.lock_ = threading.Lock()

        # Setting up connections
        self.tcp_fan_fanCmd_subscription_ = self.create_subscription(
            FanCmd,
            "tcp_tempControl_fanCmd",
            self.accept_fanCmd,
            1,
            callback_group=self.cb_group_)

        self.tcp_fan_fanAck_publisher_ = self.create_publisher(
            FanAck,
            "tcp_fan_fanAck",
            1)

        self.infrastructureIn_fanCmd = deque()
        self.applicationIn_fanCmd = deque()

        self.infrastructureOut_fanAck = deque()
        self.applicationOut_fanAck = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_fanAck, self.infrastructureOut_fanAck, self.sendOut_fanAck]
        ]

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def fanCmd_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_fanCmd, self.applicationIn_fanCmd)
            if len(self.applicationIn_fanCmd) == 0: return
            self.handle_fanCmd_base(self.applicationIn_fanCmd[0])
            self.applicationIn_fanCmd.pop()
            self.sendOutputs()

    def accept_fanCmd(self, msg):
        self.enqueue(self.infrastructureIn_fanCmd, msg)
        thread = threading.Thread(target=self.fanCmd_thread)
        thread.daemon = True
        thread.start()


    def sendOut_fanAck(self, msg):
        if type(msg) is FanAck:
            self.tcp_fan_fanAck_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port fanAck.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_fanAck(self, msg):
        self.enqueue(self.applicationOut_fanAck, msg)

    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_fanCmd(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_fanCmd_base(self, msg):
        if type(msg) is FanCmd:
            self.handle_fanCmd(msg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port fanCmd.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")


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
