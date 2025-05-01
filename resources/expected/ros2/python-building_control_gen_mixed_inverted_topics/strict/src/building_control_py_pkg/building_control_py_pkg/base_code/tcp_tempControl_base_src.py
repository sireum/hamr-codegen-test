#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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

        MsgType = Union[Temperatureimpl, FanAck, SetPointimpl, FanCmd, Empty]
        self.lock_ = threading.Lock()

        # Setting up connections
        self.tcp_tempControl_currentTemp_subscription_ = self.create_subscription(
            Temperatureimpl,
            "tcp_tempSensor_currentTemp",
            self.accept_currentTemp,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_fanAck_subscription_ = self.create_subscription(
            FanAck,
            "tcp_fan_fanAck",
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
            "tcp_tempSensor_tempChanged",
            self.accept_tempChanged,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_fanCmd_publisher_ = self.create_publisher(
            FanCmd,
            "tcp_tempControl_fanCmd",
            1)

        self.infrastructureIn_currentTemp = Queue()
        self.applicationIn_currentTemp = Queue()
        self.infrastructureIn_fanAck = Queue()
        self.applicationIn_fanAck = Queue()
        self.infrastructureIn_setPoint = Queue()
        self.applicationIn_setPoint = Queue()
        self.infrastructureIn_tempChanged = Queue()
        self.applicationIn_tempChanged = Queue()

        self.infrastructureOut_fanCmd = Queue()
        self.applicationOut_fanCmd = Queue()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_currentTemp, self.applicationIn_currentTemp]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_fanCmd, self.infrastructureOut_fanCmd, self.sendOut_fanCmd]
        ]

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_currentTemp(self, msg):
        typedMsg = Temperatureimpl()
        typedMsg.data = msg
        self.enqueue(infrastructureIn_currentTemp, msg)

    def fanAck_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_fanAck, self.applicationIn_fanAck)
            if self.applicationIn_fanAck.empty(): return
            self.handle_fanAck_base(self.applicationIn_fanAck.front())
            self.applicationIn_fanAck.pop()
            self.sendOutputs()

    def accept_fanAck(self, msg):
        typedMsg = FanAck()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_fanAck, msg)
        thread = threading.Thread(target=fanAck_thread)
        thread.daemon = True
        thread.start()


    def setPoint_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_setPoint, self.applicationIn_setPoint)
            if self.applicationIn_setPoint.empty(): return
            self.handle_setPoint_base(self.applicationIn_setPoint.front())
            self.applicationIn_setPoint.pop()
            self.sendOutputs()

    def accept_setPoint(self, msg):
        typedMsg = SetPointimpl()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_setPoint, msg)
        thread = threading.Thread(target=setPoint_thread)
        thread.daemon = True
        thread.start()


    def tempChanged_thread(self):
        with self.lock_:
            self.receiveInputs(self.infrastructureIn_tempChanged, self.applicationIn_tempChanged)
            if self.applicationIn_tempChanged.empty(): return
            self.handle_tempChanged_base(self.applicationIn_tempChanged.front())
            self.applicationIn_tempChanged.pop()
            self.sendOutputs()

    def accept_tempChanged(self, msg):
        typedMsg = Empty()
        typedMsg.data = msg
        self.enqueue(self.infrastructureIn_tempChanged, msg)
        thread = threading.Thread(target=tempChanged_thread)
        thread.daemon = True
        thread.start()


    def get_currentTemp(self):
        msg = applicationIn_currentTemp.front()
        return get(msg)

    def sendOut_fanCmd(self, msg):
        if type(msg) is FanCmd:
            typedMsg = FanCmd()
            typedMsg.data = msg
            self.tcp_tempControl_fanCmd_publisher_.publish(typedMsg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port fanCmd.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_fanCmd(self, msg):
        typedMsg = FanCmd()
        typedMsg.data = msg
        self.enqueue(self.applicationOut_fanCmd, typedMsg)

    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_fanAck(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_fanAck_base(self, msg):
        if type(msg) is FanAck:
            typedMsg = FanAck()
            typedMsg.data = msg
            self.handle_fanAck(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port fanAck.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_setPoint(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_setPoint_base(self, msg):
        if type(msg) is SetPointimpl:
            typedMsg = SetPointimpl()
            typedMsg.data = msg
            self.handle_setPoint(typedMsg)
        else:
            self.get_logger.error("Receiving wrong type of variable on port setPoint.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def handle_tempChanged(self):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_tempChanged_base(self, msg):
        self.handle_tempChanged()


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
