#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
from isolette_py_pkg.user_code.temperature_sensor_cpi_thermostat_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import PhysicalTempimpl
from isolette_py_pkg_interfaces.msg import TempWstatusimpl

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class temperature_sensor_cpi_thermostat_base(Node):
    def __init__(self):
        super().__init__("temperature_sensor_cpi_thermostat")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.temperature_sensor_cpi_thermostat_air_subscription_ = self.create_subscription(
            PhysicalTempimpl,
            "temperature_sensor_cpi_thermostat_air",
            self.handle_air,
            1,
            callback_group=self.cb_group_)

        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_ = self.create_publisher(
            TempWstatusimpl,
            "temperature_sensor_cpi_thermostat_current_tempWstatus",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_air(self, msg):
        typedMsg = PhysicalTempimpl()
        typedMsg.data = msg
        self.air_msg_holder = typedMsg

    def get_air(self):
        return self.air_msg_holder

    def put_current_tempWstatus(self, msg):
        typedMsg = TempWstatusimpl()
        typedMsg.data = msg
        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_.publish(typedMsg)

