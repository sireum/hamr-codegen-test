#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from building_control_py_pkg_interfaces.msg import Temperatureimpl
from building_control_py_pkg_interfaces.msg import FanAck
from building_control_py_pkg_interfaces.msg import SetPointimpl
from building_control_py_pkg_interfaces.msg import FanCmd
from building_control_py_pkg_interfaces.msg import Empty

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class tcp_tempControl_base(Node):
    def __init__(self):
        super().__init__("tcp_tempControl")

        self.cb_group_ = ReentrantCallbackGroup()

        self.lock_ = threading.Lock()

        # Setting up connections
        self.tcp_tempControl_currentTemp_subscription_ = self.create_subscription(
            Temperatureimpl,
            "tcp_tempControl_currentTemp",
            self.accept_currentTemp,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_fanAck_subscription_ = self.create_subscription(
            FanAck,
            "tcp_tempControl_fanAck",
            self.accept_fanAck,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_setPoint_subscription_ = self.create_subscription(
            SetPointimpl,
            "tcp_tempControl_setPoint",
            self.accept_setPoint,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_tempChanged_subscription_ = self.create_subscription(
            Empty,
            "tcp_tempControl_tempChanged",
            self.accept_tempChanged,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_fanCmd_publisher_ = self.create_publisher(
            FanCmd,
            "tcp_fan_fanCmd",
            1)

        self.infrastructureIn_currentTemp = deque()
        self.applicationIn_currentTemp = deque()
        self.infrastructureIn_fanAck = deque()
        self.applicationIn_fanAck = deque()
        self.infrastructureIn_setPoint = deque()
        self.applicationIn_setPoint = deque()
        self.infrastructureIn_tempChanged = deque()
        self.applicationIn_tempChanged = deque()

        self.infrastructureOut_fanCmd = deque()
        self.applicationOut_fanCmd = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_currentTemp, self.applicationIn_currentTemp]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_fanCmd, self.infrastructureOut_fanCmd, self.sendOut_fanCmd]
        ]

    def init_currentTemp(self, val):
        self.enqueue(self.infrastructureIn_currentTemp, val)


    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_currentTemp(self, msg):
        self.enqueue(self.infrastructureIn_currentTemp, msg)

    def fanAck_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_fanAck, self.applicationIn_fanAck)
            if len(self.applicationIn_fanAck) == 0: return
            self.handle_fanAck_base(self.applicationIn_fanAck[0])
            self.applicationIn_fanAck.pop()
            self.sendOutputs()

    def accept_fanAck(self, msg):
        self.enqueue(self.infrastructureIn_fanAck, msg)
        thread = threading.Thread(target=self.fanAck_thread)
        thread.daemon = True
        thread.start()


    def setPoint_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_setPoint, self.applicationIn_setPoint)
            if len(self.applicationIn_setPoint) == 0: return
            self.handle_setPoint_base(self.applicationIn_setPoint[0])
            self.applicationIn_setPoint.pop()
            self.sendOutputs()

    def accept_setPoint(self, msg):
        self.enqueue(self.infrastructureIn_setPoint, msg)
        thread = threading.Thread(target=self.setPoint_thread)
        thread.daemon = True
        thread.start()


    def tempChanged_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_tempChanged, self.applicationIn_tempChanged)
            if len(self.applicationIn_tempChanged) == 0: return
            self.handle_tempChanged_base(self.applicationIn_tempChanged[0])
            self.applicationIn_tempChanged.pop()
            self.sendOutputs()

    def accept_tempChanged(self, msg):
        self.enqueue(self.infrastructureIn_tempChanged, msg)
        thread = threading.Thread(target=self.tempChanged_thread)
        thread.daemon = True
        thread.start()


    def get_currentTemp(self):
        msg = self.applicationIn_currentTemp[0]
        return msg

    def sendOut_fanCmd(self, msg):
        if type(msg) is FanCmd:
            self.tcp_tempControl_fanCmd_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port fanCmd.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_fanCmd(self, msg):
        self.enqueue(self.applicationOut_fanCmd, msg)

    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_fanAck(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_fanAck_base(self, msg):
        if type(msg) is FanAck:
            self.handle_fanAck(msg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port fanAck.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_setPoint(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_setPoint_base(self, msg):
        if type(msg) is SetPointimpl:
            self.handle_setPoint(msg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port setPoint.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_tempChanged(self):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_tempChanged_base(self, msg):
        self.handle_tempChanged()


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
