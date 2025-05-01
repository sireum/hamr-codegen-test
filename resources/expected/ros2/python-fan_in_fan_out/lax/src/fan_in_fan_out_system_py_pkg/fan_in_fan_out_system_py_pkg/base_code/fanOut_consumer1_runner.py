#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from fan_in_fan_out_system_py_pkg.user_code.fanOut_consumer1_src import initialize
from fan_in_fan_out_system_py_pkg.base_code.fanOut_consumer1_base_src import fanOut_consumer1_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class fanOut_consumer1(fanOut_consumer1_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("fanOut_consumer1 infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = fanOut_consumer1()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
