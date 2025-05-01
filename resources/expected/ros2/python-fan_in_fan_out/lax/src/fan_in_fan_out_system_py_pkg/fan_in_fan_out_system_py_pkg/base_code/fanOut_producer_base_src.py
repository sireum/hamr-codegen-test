#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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
        self.fanOut_producer_myInteger_publisher_1 = self.create_publisher(
            Integer64,
            "fanOut_consumer1_myInteger",
            1)

        self.fanOut_producer_myInteger_publisher_2 = self.create_publisher(
            Integer64,
            "fanOut_consumer2_myInteger",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def put_myInteger(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        fanOut_producer_myInteger_publisher_1.publish(typedMsg)
        fanOut_producer_myInteger_publisher_2.publish(typedMsg)

