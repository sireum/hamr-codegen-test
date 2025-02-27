#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from datatypes_system_py_pkg.user_code.Sys_i_Instance_producer_producer_src import Sys_i_Instance_producer_producer
#=================================================
#  D O   N O T   E D I T   T H I S   F I L E
#=================================================

class Sys_i_Instance_producer_producer(Sys_i_Instance_producer_producer_base):
  def __init__(self):
    # invoke initialize entry point
    super().__init__()

    Sys_i_Instance_producer_producer()

    self.get_logger().info("Sys_i_Instance_producer_producer infrastructure set up")

def main(args=None):
  rclpy.init(args=args)
  node =  Sys_i_Instance_producer_producer()
  executor = MultiThreadedExecutor()
  executor.add_node(node)
  executor.spin()
  rclpy.shutdown()

if __name__ == "__main__":
  main()
