#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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
            "tcp_tempControl_currentTemp",
            1)

        self.tcp_tempSensor_tempChanged_publisher_ = self.create_publisher(
            Empty,
            "tcp_tempControl_tempChanged",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def put_currentTemp(self, msg):
        typedMsg = Temperatureimpl()
        typedMsg.data = msg
        self.tcp_tempSensor_currentTemp_publisher_.publish(typedMsg)

    def put_tempChanged(self):
        typedMsg = Empty()

        self.tcp_tempSensor_tempChanged_publisher_.publish(typedMsg)

