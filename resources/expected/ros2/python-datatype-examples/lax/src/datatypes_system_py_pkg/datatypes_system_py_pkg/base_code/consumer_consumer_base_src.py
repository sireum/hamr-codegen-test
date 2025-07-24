#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from collections import deque
from datatypes_system_py_pkg.user_code.consumer_consumer_src import *
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

class consumer_consumer_base(Node):
    def __init__(self):
        super().__init__("consumer_consumer")

        self.cb_group_ = ReentrantCallbackGroup()

        # Setting up connections
        self.consumer_consumer_myBoolean_subscription_ = self.create_subscription(
            Boolean,
            "consumer_consumer_myBoolean",
            self.handle_myBoolean,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInteger_subscription_ = self.create_subscription(
            Integer64,
            "consumer_consumer_myInteger",
            self.handle_myInteger,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat_subscription_ = self.create_subscription(
            Float64,
            "consumer_consumer_myFloat",
            self.handle_myFloat,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myCharacter_subscription_ = self.create_subscription(
            Character,
            "consumer_consumer_myCharacter",
            self.handle_myCharacter,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myString_subscription_ = self.create_subscription(
            String,
            "consumer_consumer_myString",
            self.handle_myString,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt8_subscription_ = self.create_subscription(
            Integer8,
            "consumer_consumer_myInt8",
            self.handle_myInt8,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt16_subscription_ = self.create_subscription(
            Integer16,
            "consumer_consumer_myInt16",
            self.handle_myInt16,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt32_subscription_ = self.create_subscription(
            Integer32,
            "consumer_consumer_myInt32",
            self.handle_myInt32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt64_subscription_ = self.create_subscription(
            Integer64,
            "consumer_consumer_myInt64",
            self.handle_myInt64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt8_subscription_ = self.create_subscription(
            Unsigned8,
            "consumer_consumer_myUInt8",
            self.handle_myUInt8,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt16_subscription_ = self.create_subscription(
            Unsigned16,
            "consumer_consumer_myUInt16",
            self.handle_myUInt16,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt32_subscription_ = self.create_subscription(
            Unsigned32,
            "consumer_consumer_myUInt32",
            self.handle_myUInt32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt64_subscription_ = self.create_subscription(
            Unsigned64,
            "consumer_consumer_myUInt64",
            self.handle_myUInt64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat32_subscription_ = self.create_subscription(
            Float32,
            "consumer_consumer_myFloat32",
            self.handle_myFloat32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat64_subscription_ = self.create_subscription(
            Float64,
            "consumer_consumer_myFloat64",
            self.handle_myFloat64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myEnum_subscription_ = self.create_subscription(
            MyEnum,
            "consumer_consumer_myEnum",
            self.handle_myEnum,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myStruct_subscription_ = self.create_subscription(
            MyStructi,
            "consumer_consumer_myStruct",
            self.handle_myStruct,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray1_subscription_ = self.create_subscription(
            MyArrayOneDim,
            "consumer_consumer_myArray1",
            self.handle_myArray1,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray2_subscription_ = self.create_subscription(
            MyArrayUnbounded,
            "consumer_consumer_myArray2",
            self.handle_myArray2,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray3_subscription_ = self.create_subscription(
            MyArrayTwoDim,
            "consumer_consumer_myArray3",
            self.handle_myArray3,
            1,
            callback_group=self.cb_group_)

    def timeTriggered(self):
        raise NotImplementedError("Subclasses must implement this method")

    #=================================================
    #  C o m p u t e    E n t r y    P o i n t
    #=================================================
    def handle_myBoolean(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myInteger(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myFloat(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myCharacter(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myString(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myInt8(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myInt16(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myInt32(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myInt64(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myUInt8(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myUInt16(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myUInt32(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myUInt64(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myFloat32(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myFloat64(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myEnum(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myStruct(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myArray1(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myArray2(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

    def handle_myArray3(self, msg):
        raise NotImplementedError("Subclasses must implement this method")

