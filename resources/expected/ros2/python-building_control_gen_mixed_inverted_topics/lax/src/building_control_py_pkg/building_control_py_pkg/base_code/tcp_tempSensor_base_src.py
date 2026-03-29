#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from rclpy.callback_groups import ReentrantCallbackGroup
from building_control_py_pkg_interfaces.msg import Temperatureimpl
from building_control_py_pkg_interfaces.msg import Empty

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class tcp_tempSensor_base(Node):
    def __init__(self):
        super().__init__("tcp_tempSensor")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.tcp_tempSensor_currentTemp_publisher_ = self.create_publisher(
            Temperatureimpl,
            "tcp_tempSensor_currentTemp",
            1)

        self.tcp_tempSensor_tempChanged_publisher_ = self.create_publisher(
            Empty,
            "tcp_tempSensor_tempChanged",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def put_currentTemp(self, msg):
        self.tcp_tempSensor_currentTemp_publisher_.publish(msg)

    def put_tempChanged(self):
        msg = Empty()
        self.tcp_tempSensor_tempChanged_publisher_.publish(msg)

