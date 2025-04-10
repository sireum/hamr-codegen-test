#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from datatypes_system_py_pkg.user_code.consumer_consumer_src import initialize
from datatypes_system_py_pkg.base_code.consumer_consumer_base_src import consumer_consumer_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class consumer_consumer(consumer_consumer_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("consumer_consumer infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = consumer_consumer()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
