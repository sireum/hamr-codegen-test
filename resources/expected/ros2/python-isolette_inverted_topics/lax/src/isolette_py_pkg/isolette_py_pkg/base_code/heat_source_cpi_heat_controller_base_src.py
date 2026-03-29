#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from isolette_py_pkg.user_code.heat_source_cpi_heat_controller_src import *
from rclpy.callback_groups import ReentrantCallbackGroup
from isolette_py_pkg_interfaces.msg import OnOff
from isolette_py_pkg_interfaces.msg import Heat

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class heat_source_cpi_heat_controller_base(Node):
    def __init__(self):
        super().__init__("heat_source_cpi_heat_controller")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.heat_source_cpi_heat_controller_heat_control_subscription_ = self.create_subscription(
            OnOff,
            "thermostat_regulate_temperature_manage_heat_source_mhst_heat_control",
            self.handle_heat_control,
            1,
            callback_group=self.cb_group_)

        self.heat_source_cpi_heat_controller_heat_out_publisher_ = self.create_publisher(
            Heat,
            "heat_source_cpi_heat_controller_heat_out",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

        self.heat_control_msg_holder = None

    def init_heat_control(self, val):
        self.heat_control_msg_holder = val

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_heat_control(self, msg):
        self.heat_control_msg_holder = msg

    def get_heat_control(self):
        return self.heat_control_msg_holder

    def put_heat_out(self, msg):
        self.heat_source_cpi_heat_controller_heat_out_publisher_.publish(msg)

