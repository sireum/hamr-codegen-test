#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from fan_in_fan_out_system_py_pkg.user_code.fanIn_producer2_src import fanIn_producer2
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================
def main(args=None):
    rclpy.init(args=args)
    node = fanIn_producer2()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
