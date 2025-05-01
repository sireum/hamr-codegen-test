#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from isolette_py_pkg.user_code.thermostat_regulate_temperature_manage_heat_source_mhst_src import initialize
from isolette_py_pkg.base_code.thermostat_regulate_temperature_manage_heat_source_mhst_base_src import thermostat_regulate_temperature_manage_heat_source_mhst_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class thermostat_regulate_temperature_manage_heat_source_mhst(thermostat_regulate_temperature_manage_heat_source_mhst_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("thermostat_regulate_temperature_manage_heat_source_mhst infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = thermostat_regulate_temperature_manage_heat_source_mhst()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
