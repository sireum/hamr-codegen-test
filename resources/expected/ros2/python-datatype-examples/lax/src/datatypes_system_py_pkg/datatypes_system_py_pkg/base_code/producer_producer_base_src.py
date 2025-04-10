#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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
from datatypes_system_py_pkg_interfaces.msg import MyArrayTwoDim

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class producer_producer_base(Node):
    def __init__(self):
        super().__init__("producer_producer")

        self.cb_group_ = ReentrantCallbackGroup()

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

        self.producer_producer_myArray3_publisher_ = self.create_publisher(
            MyArrayTwoDim,
            "consumer_consumer_myArray3",
            1)

        # timeTriggered callback timer
        self.periodTimer_ = self.create_timer(1000, self.timeTriggered, callback_group=self.cb_group_)

    def timeTriggered(self):
        pass

#=================================================
#  C o m m u n i c a t i o n
#=================================================

    def put_myBoolean(self, msg):
        typedMsg = Boolean()
        typedMsg.data = msg
        self.producer_producer_myBoolean_publisher_.publish(typedMsg)

    def put_myInteger(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.producer_producer_myInteger_publisher_.publish(typedMsg)

    def put_myFloat(self, msg):
        typedMsg = Float64()
        typedMsg.data = msg
        self.producer_producer_myFloat_publisher_.publish(typedMsg)

    def put_myCharacter(self, msg):
        typedMsg = Character()
        typedMsg.data = msg
        self.producer_producer_myCharacter_publisher_.publish(typedMsg)

    def put_myString(self, msg):
        typedMsg = String()
        typedMsg.data = msg
        self.producer_producer_myString_publisher_.publish(typedMsg)

    def put_myInt8(self, msg):
        typedMsg = Integer8()
        typedMsg.data = msg
        self.producer_producer_myInt8_publisher_.publish(typedMsg)

    def put_myInt16(self, msg):
        typedMsg = Integer16()
        typedMsg.data = msg
        self.producer_producer_myInt16_publisher_.publish(typedMsg)

    def put_myInt32(self, msg):
        typedMsg = Integer32()
        typedMsg.data = msg
        self.producer_producer_myInt32_publisher_.publish(typedMsg)

    def put_myInt64(self, msg):
        typedMsg = Integer64()
        typedMsg.data = msg
        self.producer_producer_myInt64_publisher_.publish(typedMsg)

    def put_myUInt8(self, msg):
        typedMsg = Unsigned8()
        typedMsg.data = msg
        self.producer_producer_myUInt8_publisher_.publish(typedMsg)

    def put_myUInt16(self, msg):
        typedMsg = Unsigned16()
        typedMsg.data = msg
        self.producer_producer_myUInt16_publisher_.publish(typedMsg)

    def put_myUInt32(self, msg):
        typedMsg = Unsigned32()
        typedMsg.data = msg
        self.producer_producer_myUInt32_publisher_.publish(typedMsg)

    def put_myUInt64(self, msg):
        typedMsg = Unsigned64()
        typedMsg.data = msg
        self.producer_producer_myUInt64_publisher_.publish(typedMsg)

    def put_myFloat32(self, msg):
        typedMsg = Float32()
        typedMsg.data = msg
        self.producer_producer_myFloat32_publisher_.publish(typedMsg)

    def put_myFloat64(self, msg):
        typedMsg = Float64()
        typedMsg.data = msg
        self.producer_producer_myFloat64_publisher_.publish(typedMsg)

    def put_myEnum(self, msg):
        typedMsg = MyEnum()
        typedMsg.data = msg
        self.producer_producer_myEnum_publisher_.publish(typedMsg)

    def put_myStruct(self, msg):
        typedMsg = MyStructi()
        typedMsg.data = msg
        self.producer_producer_myStruct_publisher_.publish(typedMsg)

    def put_myArray1(self, msg):
        typedMsg = MyArrayOneDim()
        typedMsg.data = msg
        self.producer_producer_myArray1_publisher_.publish(typedMsg)

    def put_myArray2(self, msg):
        typedMsg = MyArrayUnbounded()
        typedMsg.data = msg
        self.producer_producer_myArray2_publisher_.publish(typedMsg)

    def put_myArray3(self, msg):
        typedMsg = MyArrayTwoDim()
        typedMsg.data = msg
        self.producer_producer_myArray3_publisher_.publish(typedMsg)

