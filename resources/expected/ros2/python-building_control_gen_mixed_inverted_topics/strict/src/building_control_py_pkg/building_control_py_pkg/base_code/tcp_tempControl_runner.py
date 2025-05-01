#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from building_control_py_pkg.user_code.tcp_tempControl_src import initialize
from building_control_py_pkg.base_code.tcp_tempControl_base_src import tcp_tempControl_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class tcp_tempControl(tcp_tempControl_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("tcp_tempControl infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = tcp_tempControl()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
