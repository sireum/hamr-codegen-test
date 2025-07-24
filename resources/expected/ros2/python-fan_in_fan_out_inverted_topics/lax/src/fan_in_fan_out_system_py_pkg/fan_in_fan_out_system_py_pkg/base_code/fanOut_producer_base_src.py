#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from rclpy.callback_groups import ReentrantCallbackGroup
from fan_in_fan_out_system_py_pkg_interfaces.msg import Integer64

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class fanOut_producer_base(Node):
    def __init__(self):
        super().__init__("fanOut_producer")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.fanOut_producer_myInteger_publisher_ = self.create_publisher(
            Integer64,
            "fanOut_producer_myInteger",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def put_myInteger(self, msg):
        self.fanOut_producer_myInteger_publisher_.publish(msg)

