#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from isolette_py_pkg.user_code.operator_interface_oip_oit_src import initialize
from isolette_py_pkg.base_code.operator_interface_oip_oit_base_src import operator_interface_oip_oit_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class operator_interface_oip_oit(operator_interface_oip_oit_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("operator_interface_oip_oit infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = operator_interface_oip_oit()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
