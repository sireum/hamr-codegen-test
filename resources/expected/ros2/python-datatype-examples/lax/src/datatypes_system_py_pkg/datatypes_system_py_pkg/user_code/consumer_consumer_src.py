#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from datatypes_system_py_pkg.base_code.consumer_consumer_base_src import consumer_consumer_base
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
from datatypes_system_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class consumer_consumer(consumer_consumer_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("consumer_consumer infrastructure set up")

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
    def initialize(self):
        self.get_logger().info("Initialize Entry Point invoked")

        # Initialize the node

        # Initialize the node's incoming data port values here


#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
    def message_to_string(self, msg):
        yaml_str = message_to_yaml(msg)
        return yaml_str

    def handle_myBoolean(self, msg):
        # Handle myBoolean msg
        self.get_logger().info(f"Received myBoolean: {self.message_to_string(msg)}")

    def handle_myInteger(self, msg):
        # Handle myInteger msg
        self.get_logger().info(f"Received myInteger: {self.message_to_string(msg)}")

    def handle_myFloat(self, msg):
        # Handle myFloat msg
        self.get_logger().info(f"Received myFloat: {self.message_to_string(msg)}")

    def handle_myCharacter(self, msg):
        # Handle myCharacter msg
        self.get_logger().info(f"Received myCharacter: {self.message_to_string(msg)}")

    def handle_myString(self, msg):
        # Handle myString msg
        self.get_logger().info(f"Received myString: {self.message_to_string(msg)}")

    def handle_myInt8(self, msg):
        # Handle myInt8 msg
        self.get_logger().info(f"Received myInt8: {self.message_to_string(msg)}")

    def handle_myInt16(self, msg):
        # Handle myInt16 msg
        self.get_logger().info(f"Received myInt16: {self.message_to_string(msg)}")

    def handle_myInt32(self, msg):
        # Handle myInt32 msg
        self.get_logger().info(f"Received myInt32: {self.message_to_string(msg)}")

    def handle_myInt64(self, msg):
        # Handle myInt64 msg
        self.get_logger().info(f"Received myInt64: {self.message_to_string(msg)}")

    def handle_myUInt8(self, msg):
        # Handle myUInt8 msg
        self.get_logger().info(f"Received myUInt8: {self.message_to_string(msg)}")

    def handle_myUInt16(self, msg):
        # Handle myUInt16 msg
        self.get_logger().info(f"Received myUInt16: {self.message_to_string(msg)}")

    def handle_myUInt32(self, msg):
        # Handle myUInt32 msg
        self.get_logger().info(f"Received myUInt32: {self.message_to_string(msg)}")

    def handle_myUInt64(self, msg):
        # Handle myUInt64 msg
        self.get_logger().info(f"Received myUInt64: {self.message_to_string(msg)}")

    def handle_myFloat32(self, msg):
        # Handle myFloat32 msg
        self.get_logger().info(f"Received myFloat32: {self.message_to_string(msg)}")

    def handle_myFloat64(self, msg):
        # Handle myFloat64 msg
        self.get_logger().info(f"Received myFloat64: {self.message_to_string(msg)}")

    def handle_myEnum(self, msg):
        # Handle myEnum msg
        self.get_logger().info(f"Received myEnum: {self.message_to_string(msg)}")

    def handle_myStruct(self, msg):
        # Handle myStruct msg
        self.get_logger().info(f"Received myStruct: {self.message_to_string(msg)}")

    def handle_myArray1(self, msg):
        # Handle myArray1 msg
        self.get_logger().info(f"Received myArray1: {self.message_to_string(msg)}")

    def handle_myArray2(self, msg):
        # Handle myArray2 msg
        self.get_logger().info(f"Received myArray2: {self.message_to_string(msg)}")

    def handle_myArray3(self, msg):
        # Handle myArray3 msg
        self.get_logger().info(f"Received myArray3: {self.message_to_string(msg)}")


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
