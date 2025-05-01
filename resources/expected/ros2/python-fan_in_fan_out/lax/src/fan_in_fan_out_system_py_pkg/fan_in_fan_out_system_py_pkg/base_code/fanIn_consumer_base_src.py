#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from fan_in_fan_out_system_py_pkg.user_code.fanIn_consumer_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from fan_in_fan_out_system_py_pkg_interfaces.msg import Integer64

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class fanIn_consumer_base(Node):
    def __init__(self):
        super().__init__("fanIn_consumer")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.fanIn_consumer_myInteger_subscription_ = self.create_subscription(
            Integer64,
            "fanIn_consumer_myInteger",
            self.handle_myInteger,
            1,
            callback_group=self.cb_group_)

    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_myInteger(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

