#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from building_control_py_pkg.user_code.tcp_tempSensor_src import initialize
from building_control_py_pkg.base_code.tcp_tempSensor_base_src import tcp_tempSensor_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class tcp_tempSensor(tcp_tempSensor_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("tcp_tempSensor infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = tcp_tempSensor()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
