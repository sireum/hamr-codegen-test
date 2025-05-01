#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from building_control_py_pkg.base_code.enum_converter import *

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
def initialize(node):
    node.get_logger().info("Initialize Entry Point invoked")

    # Initialize the node
    node.handle_fanAck = handle_fanAck
    node.handle_setPoint = handle_setPoint
    node.handle_tempChanged = handle_tempChanged

#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
def handle_fanAck(msg):
    pass # Handle fanAck msg

def handle_setPoint(msg):
    pass # Handle setPoint msg

def handle_tempChanged():
    pass # Handle tempChanged event


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
