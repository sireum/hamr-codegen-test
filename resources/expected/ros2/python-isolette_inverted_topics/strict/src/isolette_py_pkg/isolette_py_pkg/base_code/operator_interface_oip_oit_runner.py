#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from isolette_py_pkg.user_code.operator_interface_oip_oit_src import operator_interface_oip_oit
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================
def main(args=None):
    rclpy.init(args=args)
    node = operator_interface_oip_oit()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
