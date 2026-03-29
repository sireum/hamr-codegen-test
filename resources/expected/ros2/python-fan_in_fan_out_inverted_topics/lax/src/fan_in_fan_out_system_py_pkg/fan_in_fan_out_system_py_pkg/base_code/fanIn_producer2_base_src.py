#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from rclpy.callback_groups import ReentrantCallbackGroup
from fan_in_fan_out_system_py_pkg_interfaces.msg import Integer64

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class fanIn_producer2_base(Node):
    def __init__(self):
        super().__init__("fanIn_producer2")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.fanIn_producer2_myInteger_publisher_ = self.create_publisher(
            Integer64,
            "fanIn_producer2_myInteger",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def put_myInteger(self, msg):
        self.fanIn_producer2_myInteger_publisher_.publish(msg)

