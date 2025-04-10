#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from datatypes_system_py_pkg.user_code.producer_producer_src import initialize
from datatypes_system_py_pkg.base_code.producer_producer_base_src import producer_producer_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class producer_producer(producer_producer_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("producer_producer infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = producer_producer()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
