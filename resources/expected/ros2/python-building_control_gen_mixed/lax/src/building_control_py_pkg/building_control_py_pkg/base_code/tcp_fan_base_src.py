#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from building_control_py_pkg.user_code.tcp_fan_src import *
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

        # Setting up connections
        self.tcp_fan_fanCmd_subscription_ = self.create_subscription(
            FanCmd,
            "tcp_fan_fanCmd",
            self.handle_fanCmd,
            1,
            callback_group=self.cb_group_)

        self.tcp_fan_fanAck_publisher_ = self.create_publisher(
            FanAck,
            "tcp_tempControl_fanAck",
            1)

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def put_fanAck(self, msg):
        typedMsg = FanAck()
        typedMsg.data = msg
        self.tcp_fan_fanAck_publisher_.publish(typedMsg)


    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_fanCmd(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

