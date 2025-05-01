#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

#===========================================================
# This file will not be overwritten when re-running Codegen
#===========================================================

#=================================================
#  I n i t i a l i z e    E n t r y    P o i n t
#=================================================
def initialize(node):
    node.get_logger().info("Initialize Entry Point invoked")

    # Initialize the node
    node.handle_myInteger = handle_myInteger

#=================================================
#  C o m p u t e    E n t r y    P o i n t
#=================================================
def handle_myInteger(msg):
    pass # Handle myInteger msg


#=================================================
#  Include any additional declarations here
#=================================================
# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen
