#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from building_control_py_pkg.user_code.tcp_tempControl_src import *
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

        # Setting up connections
        self.tcp_tempControl_currentTemp_subscription_ = self.create_subscription(
            Temperatureimpl,
            "tcp_tempSensor_currentTemp",
            self.handle_currentTemp,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_fanAck_subscription_ = self.create_subscription(
            FanAck,
            "tcp_fan_fanAck",
            self.handle_fanAck,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_setPoint_subscription_ = self.create_subscription(
            SetPointimpl,
            "tcp_tempControl_setPoint",
            self.handle_setPoint,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_tempChanged_subscription_ = self.create_subscription(
            Empty,
            "tcp_tempSensor_tempChanged",
            self.event_handle_tempChanged,
            1,
            callback_group=self.cb_group_)

        self.tcp_tempControl_fanCmd_publisher_ = self.create_publisher(
            FanCmd,
            "tcp_tempControl_fanCmd",
            1)

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_currentTemp(self, msg):
        typedMsg = Temperatureimpl()
        typedMsg.data = msg
        self.currentTemp_msg_holder = typedMsg

    def get_currentTemp(self):
        return self.currentTemp_msg_holder

    def event_handle_tempChanged(self, msg):
         handle_tempChanged()

    def put_fanCmd(self, msg):
        typedMsg = FanCmd()
        typedMsg.data = msg
        self.tcp_tempControl_fanCmd_publisher_.publish(typedMsg)


    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_fanAck(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_setPoint(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_tempChanged(self):
        raise NotImplementedError("Subclasses must implement this method")

