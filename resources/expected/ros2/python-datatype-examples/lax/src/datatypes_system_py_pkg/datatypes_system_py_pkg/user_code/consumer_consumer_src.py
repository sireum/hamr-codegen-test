#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from datatypes_system_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
def initialize(node):
    node.get_logger().info("Initialize Entry Point invoked")

    # Initialize the node
    node.handle_myBoolean = handle_myBoolean
    node.handle_myInteger = handle_myInteger
    node.handle_myFloat = handle_myFloat
    node.handle_myCharacter = handle_myCharacter
    node.handle_myString = handle_myString
    node.handle_myInt8 = handle_myInt8
    node.handle_myInt16 = handle_myInt16
    node.handle_myInt32 = handle_myInt32
    node.handle_myInt64 = handle_myInt64
    node.handle_myUInt8 = handle_myUInt8
    node.handle_myUInt16 = handle_myUInt16
    node.handle_myUInt32 = handle_myUInt32
    node.handle_myUInt64 = handle_myUInt64
    node.handle_myFloat32 = handle_myFloat32
    node.handle_myFloat64 = handle_myFloat64
    node.handle_myEnum = handle_myEnum
    node.handle_myStruct = handle_myStruct
    node.handle_myArray1 = handle_myArray1
    node.handle_myArray2 = handle_myArray2
    node.handle_myArray3 = handle_myArray3

#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
def handle_myBoolean(msg):
    pass # Handle myBoolean msg

def handle_myInteger(msg):
    pass # Handle myInteger msg

def handle_myFloat(msg):
    pass # Handle myFloat msg

def handle_myCharacter(msg):
    pass # Handle myCharacter msg

def handle_myString(msg):
    pass # Handle myString msg

def handle_myInt8(msg):
    pass # Handle myInt8 msg

def handle_myInt16(msg):
    pass # Handle myInt16 msg

def handle_myInt32(msg):
    pass # Handle myInt32 msg

def handle_myInt64(msg):
    pass # Handle myInt64 msg

def handle_myUInt8(msg):
    pass # Handle myUInt8 msg

def handle_myUInt16(msg):
    pass # Handle myUInt16 msg

def handle_myUInt32(msg):
    pass # Handle myUInt32 msg

def handle_myUInt64(msg):
    pass # Handle myUInt64 msg

def handle_myFloat32(msg):
    pass # Handle myFloat32 msg

def handle_myFloat64(msg):
    pass # Handle myFloat64 msg

def handle_myEnum(msg):
    pass # Handle myEnum msg

def handle_myStruct(msg):
    pass # Handle myStruct msg

def handle_myArray1(msg):
    pass # Handle myArray1 msg

def handle_myArray2(msg):
    pass # Handle myArray2 msg

def handle_myArray3(msg):
    pass # Handle myArray3 msg


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
