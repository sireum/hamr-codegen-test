#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from datatypes_system_py_pkg.base_code.producer_producer_runner import producer_producer
from datatypes_system_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
def initialize(n):
    node = producer_producer()
    node.data = n
    node.get_logger().info("Initialize Entry Point invoked")

    # Initialize the node

#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
def timeTriggered():
    pass # Handle communication

