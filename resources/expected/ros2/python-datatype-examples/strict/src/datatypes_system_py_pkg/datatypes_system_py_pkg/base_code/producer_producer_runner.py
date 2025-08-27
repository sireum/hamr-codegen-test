#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from datatypes_system_py_pkg.user_code.producer_producer_src import producer_producer
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================
def main(args=None):
    rclpy.init(args=args)
    node = producer_producer()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
