#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
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

        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_1 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus",
            1)

        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_2 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus",
            1)

        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_3 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus",
            1)

        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_4 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus",
            1)

        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_5 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus",
            1)

        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_6 = self.create_publisher(
            TempWstatusimpl,
            "thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggered, callback_group=self.cb_group_)

        self.air_msg_holder = None

    def init_air(self, val):
        self.air_msg_holder = val

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def handle_air(self, msg):
        self.air_msg_holder = msg

    def get_air(self):
        return self.air_msg_holder

    def put_current_tempWstatus(self, msg):
        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_1.publish(msg)
        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_2.publish(msg)
        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_3.publish(msg)
        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_4.publish(msg)
        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_5.publish(msg)
        self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_6.publish(msg)

