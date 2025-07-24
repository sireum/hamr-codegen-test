#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
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

        self.lock_ = threading.Lock()

        # Setting up connections
        self.temperature_sensor_cpi_thermostat_air_subscription_ = self.create_subscription(
            PhysicalTempimpl,
            "temperature_sensor_cpi_thermostat_air",
            self.accept_air,
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

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureIn_air = deque()
        self.applicationIn_air = deque()

        self.infrastructureOut_current_tempWstatus = deque()
        self.applicationOut_current_tempWstatus = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
            [self.infrastructureIn_air, self.applicationIn_air]
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
            [self.infrastructureIn_air, self.applicationIn_air]
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_current_tempWstatus, self.infrastructureOut_current_tempWstatus, self.sendOut_current_tempWstatus]
        ]

    def init_air(self, val):
        self.enqueue(self.infrastructureIn_air, val)


    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def accept_air(self, msg):
        self.enqueue(self.infrastructureIn_air, msg)

    def get_air(self):
        msg = self.applicationIn_air[0]
        return msg

    def sendOut_current_tempWstatus(self, msg):
        if type(msg) is TempWstatusimpl:
            self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_1.publish(msg)
            self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_2.publish(msg)
            self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_3.publish(msg)
            self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_4.publish(msg)
            self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_5.publish(msg)
            self.temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_6.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port current_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_current_tempWstatus(self, msg):
        self.enqueue(self.applicationOut_current_tempWstatus, msg)

    def timeTriggeredCaller(self):
        self.receiveInputs()
        self.timeTriggered()
        self.sendOutputs()

    def receiveInputs(self):
        for port in self.inDataPortTupleVector:
            infrastructureQueue = port[0]
            if not(len(infrastructureQueue) == 0):
                msg = infrastructureQueue[0]
                self.enqueue(port[1], msg)

        for port in self.inEventPortTupleVector:
            infrastructureQueue = port[0]
            if not(len(infrastructureQueue) == 0):
                msg = infrastructureQueue[0]
                infrastructureQueue.pop()
                self.enqueue(port[1], msg)

    def enqueue(self, queue, val):
        if len(queue) >= 1:
            queue.pop()
        queue.append(val)

    def sendOutputs(self):
        for port in self.outPortTupleVector:
            applicationQueue = port[0]
            if len(applicationQueue) != 0:
                msg = applicationQueue[0]
                applicationQueue.pop()
                self.enqueue(port[1], msg)

        for port in self.outPortTupleVector:
            infrastructureQueue = port[1]
            if len(infrastructureQueue) != 0:
                msg = infrastructureQueue[0]
                infrastructureQueue.pop()
                (port[2])(msg)
