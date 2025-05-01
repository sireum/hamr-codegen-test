#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from fan_in_fan_out_system_py_pkg.user_code.fanOut_consumer1_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from fan_in_fan_out_system_py_pkg_interfaces.msg import Integer64

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class fanOut_consumer1_base(Node):
    def __init__(self):
        super().__init__("fanOut_consumer1")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.fanOut_consumer1_myInteger_subscription_ = self.create_subscription(
            Integer64,
            "fanOut_consumer1_myInteger",
            self.handle_myInteger,
            1,
            callback_group=self.cb_group_)

    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_myInteger(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

