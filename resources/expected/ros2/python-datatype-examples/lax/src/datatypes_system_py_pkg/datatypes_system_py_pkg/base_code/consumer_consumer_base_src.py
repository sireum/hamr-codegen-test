#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from queue import Queue
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
            handle_myBoolean,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInteger_subscription_ = self.create_subscription(
            Integer64,
            "consumer_consumer_myInteger",
            handle_myInteger,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat_subscription_ = self.create_subscription(
            Float64,
            "consumer_consumer_myFloat",
            handle_myFloat,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myCharacter_subscription_ = self.create_subscription(
            Character,
            "consumer_consumer_myCharacter",
            handle_myCharacter,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myString_subscription_ = self.create_subscription(
            String,
            "consumer_consumer_myString",
            handle_myString,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt8_subscription_ = self.create_subscription(
            Integer8,
            "consumer_consumer_myInt8",
            handle_myInt8,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt16_subscription_ = self.create_subscription(
            Integer16,
            "consumer_consumer_myInt16",
            handle_myInt16,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt32_subscription_ = self.create_subscription(
            Integer32,
            "consumer_consumer_myInt32",
            handle_myInt32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myInt64_subscription_ = self.create_subscription(
            Integer64,
            "consumer_consumer_myInt64",
            handle_myInt64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt8_subscription_ = self.create_subscription(
            Unsigned8,
            "consumer_consumer_myUInt8",
            handle_myUInt8,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt16_subscription_ = self.create_subscription(
            Unsigned16,
            "consumer_consumer_myUInt16",
            handle_myUInt16,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt32_subscription_ = self.create_subscription(
            Unsigned32,
            "consumer_consumer_myUInt32",
            handle_myUInt32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myUInt64_subscription_ = self.create_subscription(
            Unsigned64,
            "consumer_consumer_myUInt64",
            handle_myUInt64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat32_subscription_ = self.create_subscription(
            Float32,
            "consumer_consumer_myFloat32",
            handle_myFloat32,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myFloat64_subscription_ = self.create_subscription(
            Float64,
            "consumer_consumer_myFloat64",
            handle_myFloat64,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myEnum_subscription_ = self.create_subscription(
            MyEnum,
            "consumer_consumer_myEnum",
            handle_myEnum,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myStruct_subscription_ = self.create_subscription(
            MyStructi,
            "consumer_consumer_myStruct",
            handle_myStruct,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray1_subscription_ = self.create_subscription(
            MyArrayOneDim,
            "consumer_consumer_myArray1",
            handle_myArray1,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray2_subscription_ = self.create_subscription(
            MyArrayUnbounded,
            "consumer_consumer_myArray2",
            handle_myArray2,
            1,
            callback_group=self.cb_group_)

        self.consumer_consumer_myArray3_subscription_ = self.create_subscription(
            MyArrayTwoDim,
            "consumer_consumer_myArray3",
            handle_myArray3,
            1,
            callback_group=self.cb_group_)
