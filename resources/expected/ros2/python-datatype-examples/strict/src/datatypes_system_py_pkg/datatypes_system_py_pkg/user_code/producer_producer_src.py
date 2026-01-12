#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rosidl_runtime_py.convert import message_to_yaml
from datatypes_system_py_pkg.base_code.producer_producer_base_src import producer_producer_base
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
from datatypes_system_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================
class producer_producer(producer_producer_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        self.initialize()

        self.get_logger().info("producer_producer infrastructure set up")

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

    def timeTriggered(self):
        # Handle communication

        # Example publishing messages
        myBoolean = Boolean()
        self.put_myBoolean(myBoolean)

        myInteger = Integer64()
        self.put_myInteger(myInteger)

        myFloat = Float64()
        self.put_myFloat(myFloat)

        myCharacter = Character()
        self.put_myCharacter(myCharacter)

        myString = String()
        self.put_myString(myString)

        myInt8 = Integer8()
        self.put_myInt8(myInt8)

        myInt16 = Integer16()
        self.put_myInt16(myInt16)

        myInt32 = Integer32()
        self.put_myInt32(myInt32)

        myInt64 = Integer64()
        self.put_myInt64(myInt64)

        myUInt8 = Unsigned8()
        self.put_myUInt8(myUInt8)

        myUInt16 = Unsigned16()
        self.put_myUInt16(myUInt16)

        myUInt32 = Unsigned32()
        self.put_myUInt32(myUInt32)

        myUInt64 = Unsigned64()
        self.put_myUInt64(myUInt64)

        myFloat32 = Float32()
        self.put_myFloat32(myFloat32)

        myFloat64 = Float64()
        self.put_myFloat64(myFloat64)

        myEnum = MyEnum()
        self.put_myEnum(myEnum)

        myStruct = MyStructi()
        self.put_myStruct(myStruct)

        myArray1 = MyArrayOneDim()
        self.put_myArray1(myArray1)

        myArray2 = MyArrayUnbounded()
        self.put_myArray2(myArray2)


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
