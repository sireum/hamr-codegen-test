#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from typing import Union
import threading
from rclpy.callback_groups import ReentrantCallbackGroup
from datatypes_system_py_pkg_interfaces.msg import Boolean
from datatypes_system_py_pkg_interfaces.msg import Integer64
from datatypes_system_py_pkg_interfaces.msg import Float64
from datatypes_system_py_pkg_interfaces.msg import Character
from datatypes_system_py_pkg_interfaces.msg import String
from datatypes_system_py_pkg_interfaces.msg import Integer8
from datatypes_system_py_pkg_interfaces.msg import Integer16
from datatypes_system_py_pkg_interfaces.msg import Integer32
from datatypes_system_py_pkg_interfaces.msg import Unsigned8
from datatypes_system_py_pkg_interfaces.msg import Unsigned16
from datatypes_system_py_pkg_interfaces.msg import Unsigned32
from datatypes_system_py_pkg_interfaces.msg import Unsigned64
from datatypes_system_py_pkg_interfaces.msg import Float32
from datatypes_system_py_pkg_interfaces.msg import MyEnum
from datatypes_system_py_pkg_interfaces.msg import MyStructi
from datatypes_system_py_pkg_interfaces.msg import MyArrayOneDim
from datatypes_system_py_pkg_interfaces.msg import MyArrayUnbounded

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class producer_producer_base(Node):
    def __init__(self):
        super().__init__("producer_producer")

        self.cb_group_ = ReentrantCallbackGroup()

        self.lock_ = threading.Lock()

        # Setting up connections
        self.producer_producer_myBoolean_publisher_ = self.create_publisher(
            Boolean,
            "consumer_consumer_myBoolean",
            1)

        self.producer_producer_myInteger_publisher_ = self.create_publisher(
            Integer64,
            "consumer_consumer_myInteger",
            1)

        self.producer_producer_myFloat_publisher_ = self.create_publisher(
            Float64,
            "consumer_consumer_myFloat",
            1)

        self.producer_producer_myCharacter_publisher_ = self.create_publisher(
            Character,
            "consumer_consumer_myCharacter",
            1)

        self.producer_producer_myString_publisher_ = self.create_publisher(
            String,
            "consumer_consumer_myString",
            1)

        self.producer_producer_myInt8_publisher_ = self.create_publisher(
            Integer8,
            "consumer_consumer_myInt8",
            1)

        self.producer_producer_myInt16_publisher_ = self.create_publisher(
            Integer16,
            "consumer_consumer_myInt16",
            1)

        self.producer_producer_myInt32_publisher_ = self.create_publisher(
            Integer32,
            "consumer_consumer_myInt32",
            1)

        self.producer_producer_myInt64_publisher_ = self.create_publisher(
            Integer64,
            "consumer_consumer_myInt64",
            1)

        self.producer_producer_myUInt8_publisher_ = self.create_publisher(
            Unsigned8,
            "consumer_consumer_myUInt8",
            1)

        self.producer_producer_myUInt16_publisher_ = self.create_publisher(
            Unsigned16,
            "consumer_consumer_myUInt16",
            1)

        self.producer_producer_myUInt32_publisher_ = self.create_publisher(
            Unsigned32,
            "consumer_consumer_myUInt32",
            1)

        self.producer_producer_myUInt64_publisher_ = self.create_publisher(
            Unsigned64,
            "consumer_consumer_myUInt64",
            1)

        self.producer_producer_myFloat32_publisher_ = self.create_publisher(
            Float32,
            "consumer_consumer_myFloat32",
            1)

        self.producer_producer_myFloat64_publisher_ = self.create_publisher(
            Float64,
            "consumer_consumer_myFloat64",
            1)

        self.producer_producer_myEnum_publisher_ = self.create_publisher(
            MyEnum,
            "consumer_consumer_myEnum",
            1)

        self.producer_producer_myStruct_publisher_ = self.create_publisher(
            MyStructi,
            "consumer_consumer_myStruct",
            1)

        self.producer_producer_myArray1_publisher_ = self.create_publisher(
            MyArrayOneDim,
            "consumer_consumer_myArray1",
            1)

        self.producer_producer_myArray2_publisher_ = self.create_publisher(
            MyArrayUnbounded,
            "consumer_consumer_myArray2",
            1)

        # timeTriggeredCaller callback timer
        self.periodTimer_ = self.create_timer(1, self.timeTriggeredCaller, callback_group=self.cb_group_)

        self.infrastructureOut_myBoolean = deque()
        self.applicationOut_myBoolean = deque()
        self.infrastructureOut_myInteger = deque()
        self.applicationOut_myInteger = deque()
        self.infrastructureOut_myFloat = deque()
        self.applicationOut_myFloat = deque()
        self.infrastructureOut_myCharacter = deque()
        self.applicationOut_myCharacter = deque()
        self.infrastructureOut_myString = deque()
        self.applicationOut_myString = deque()
        self.infrastructureOut_myInt8 = deque()
        self.applicationOut_myInt8 = deque()
        self.infrastructureOut_myInt16 = deque()
        self.applicationOut_myInt16 = deque()
        self.infrastructureOut_myInt32 = deque()
        self.applicationOut_myInt32 = deque()
        self.infrastructureOut_myInt64 = deque()
        self.applicationOut_myInt64 = deque()
        self.infrastructureOut_myUInt8 = deque()
        self.applicationOut_myUInt8 = deque()
        self.infrastructureOut_myUInt16 = deque()
        self.applicationOut_myUInt16 = deque()
        self.infrastructureOut_myUInt32 = deque()
        self.applicationOut_myUInt32 = deque()
        self.infrastructureOut_myUInt64 = deque()
        self.applicationOut_myUInt64 = deque()
        self.infrastructureOut_myFloat32 = deque()
        self.applicationOut_myFloat32 = deque()
        self.infrastructureOut_myFloat64 = deque()
        self.applicationOut_myFloat64 = deque()
        self.infrastructureOut_myEnum = deque()
        self.applicationOut_myEnum = deque()
        self.infrastructureOut_myStruct = deque()
        self.applicationOut_myStruct = deque()
        self.infrastructureOut_myArray1 = deque()
        self.applicationOut_myArray1 = deque()
        self.infrastructureOut_myArray2 = deque()
        self.applicationOut_myArray2 = deque()

        # Used by receiveInputs
        self.inDataPortTupleVector = [
        ]

        # Used by receiveInputs
        self.inEventPortTupleVector = [
        ]

        # Used by sendOutputs
        self.outPortTupleVector = [
            [self.applicationOut_myBoolean, self.infrastructureOut_myBoolean, self.sendOut_myBoolean],
            [self.applicationOut_myInteger, self.infrastructureOut_myInteger, self.sendOut_myInteger],
            [self.applicationOut_myFloat, self.infrastructureOut_myFloat, self.sendOut_myFloat],
            [self.applicationOut_myCharacter, self.infrastructureOut_myCharacter, self.sendOut_myCharacter],
            [self.applicationOut_myString, self.infrastructureOut_myString, self.sendOut_myString],
            [self.applicationOut_myInt8, self.infrastructureOut_myInt8, self.sendOut_myInt8],
            [self.applicationOut_myInt16, self.infrastructureOut_myInt16, self.sendOut_myInt16],
            [self.applicationOut_myInt32, self.infrastructureOut_myInt32, self.sendOut_myInt32],
            [self.applicationOut_myInt64, self.infrastructureOut_myInt64, self.sendOut_myInt64],
            [self.applicationOut_myUInt8, self.infrastructureOut_myUInt8, self.sendOut_myUInt8],
            [self.applicationOut_myUInt16, self.infrastructureOut_myUInt16, self.sendOut_myUInt16],
            [self.applicationOut_myUInt32, self.infrastructureOut_myUInt32, self.sendOut_myUInt32],
            [self.applicationOut_myUInt64, self.infrastructureOut_myUInt64, self.sendOut_myUInt64],
            [self.applicationOut_myFloat32, self.infrastructureOut_myFloat32, self.sendOut_myFloat32],
            [self.applicationOut_myFloat64, self.infrastructureOut_myFloat64, self.sendOut_myFloat64],
            [self.applicationOut_myEnum, self.infrastructureOut_myEnum, self.sendOut_myEnum],
            [self.applicationOut_myStruct, self.infrastructureOut_myStruct, self.sendOut_myStruct],
            [self.applicationOut_myArray1, self.infrastructureOut_myArray1, self.sendOut_myArray1],
            [self.applicationOut_myArray2, self.infrastructureOut_myArray2, self.sendOut_myArray2]
        ]

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m m u n i c a t i o n
    #=================================================

    def sendOut_myBoolean(self, msg):
        if type(msg) is Boolean:
            self.producer_producer_myBoolean_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myBoolean.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInteger(self, msg):
        if type(msg) is Integer64:
            self.producer_producer_myInteger_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myFloat(self, msg):
        if type(msg) is Float64:
            self.producer_producer_myFloat_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myFloat.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myCharacter(self, msg):
        if type(msg) is Character:
            self.producer_producer_myCharacter_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myCharacter.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myString(self, msg):
        if type(msg) is String:
            self.producer_producer_myString_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myString.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt8(self, msg):
        if type(msg) is Integer8:
            self.producer_producer_myInt8_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt16(self, msg):
        if type(msg) is Integer16:
            self.producer_producer_myInt16_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt32(self, msg):
        if type(msg) is Integer32:
            self.producer_producer_myInt32_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myInt64(self, msg):
        if type(msg) is Integer64:
            self.producer_producer_myInt64_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt8(self, msg):
        if type(msg) is Unsigned8:
            self.producer_producer_myUInt8_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt16(self, msg):
        if type(msg) is Unsigned16:
            self.producer_producer_myUInt16_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt32(self, msg):
        if type(msg) is Unsigned32:
            self.producer_producer_myUInt32_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myUInt64(self, msg):
        if type(msg) is Unsigned64:
            self.producer_producer_myUInt64_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myUInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myFloat32(self, msg):
        if type(msg) is Float32:
            self.producer_producer_myFloat32_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myFloat32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myFloat64(self, msg):
        if type(msg) is Float64:
            self.producer_producer_myFloat64_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myFloat64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myEnum(self, msg):
        if type(msg) is MyEnum:
            self.producer_producer_myEnum_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myEnum.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myStruct(self, msg):
        if type(msg) is MyStructi:
            self.producer_producer_myStruct_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myStruct.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myArray1(self, msg):
        if type(msg) is MyArrayOneDim:
            self.producer_producer_myArray1_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myArray1.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def sendOut_myArray2(self, msg):
        if type(msg) is MyArrayUnbounded:
            self.producer_producer_myArray2_publisher_.publish(msg)
        else:
            self.get_logger().error("Sending out wrong type of variable on port myArray2.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.")

    def put_myBoolean(self, msg):
        self.enqueue(self.applicationOut_myBoolean, msg)

    def put_myInteger(self, msg):
        self.enqueue(self.applicationOut_myInteger, msg)

    def put_myFloat(self, msg):
        self.enqueue(self.applicationOut_myFloat, msg)

    def put_myCharacter(self, msg):
        self.enqueue(self.applicationOut_myCharacter, msg)

    def put_myString(self, msg):
        self.enqueue(self.applicationOut_myString, msg)

    def put_myInt8(self, msg):
        self.enqueue(self.applicationOut_myInt8, msg)

    def put_myInt16(self, msg):
        self.enqueue(self.applicationOut_myInt16, msg)

    def put_myInt32(self, msg):
        self.enqueue(self.applicationOut_myInt32, msg)

    def put_myInt64(self, msg):
        self.enqueue(self.applicationOut_myInt64, msg)

    def put_myUInt8(self, msg):
        self.enqueue(self.applicationOut_myUInt8, msg)

    def put_myUInt16(self, msg):
        self.enqueue(self.applicationOut_myUInt16, msg)

    def put_myUInt32(self, msg):
        self.enqueue(self.applicationOut_myUInt32, msg)

    def put_myUInt64(self, msg):
        self.enqueue(self.applicationOut_myUInt64, msg)

    def put_myFloat32(self, msg):
        self.enqueue(self.applicationOut_myFloat32, msg)

    def put_myFloat64(self, msg):
        self.enqueue(self.applicationOut_myFloat64, msg)

    def put_myEnum(self, msg):
        self.enqueue(self.applicationOut_myEnum, msg)

    def put_myStruct(self, msg):
        self.enqueue(self.applicationOut_myStruct, msg)

    def put_myArray1(self, msg):
        self.enqueue(self.applicationOut_myArray1, msg)

    def put_myArray2(self, msg):
        self.enqueue(self.applicationOut_myArray2, msg)

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
