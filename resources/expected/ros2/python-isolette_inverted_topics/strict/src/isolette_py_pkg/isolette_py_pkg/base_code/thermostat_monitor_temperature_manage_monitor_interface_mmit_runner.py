#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from isolette_py_pkg.user_code.thermostat_monitor_temperature_manage_monitor_interface_mmit_src import thermostat_monitor_temperature_manage_monitor_interface_mmit
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================
def main(args=None):
    rclpy.init(args=args)
    node = thermostat_monitor_temperature_manage_monitor_interface_mmit()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
