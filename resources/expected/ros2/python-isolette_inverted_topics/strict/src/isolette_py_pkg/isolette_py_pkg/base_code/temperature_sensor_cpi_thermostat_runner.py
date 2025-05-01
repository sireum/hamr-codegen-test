#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from isolette_py_pkg.user_code.temperature_sensor_cpi_thermostat_src import initialize
from isolette_py_pkg.base_code.temperature_sensor_cpi_thermostat_base_src import temperature_sensor_cpi_thermostat_base
#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

class temperature_sensor_cpi_thermostat(temperature_sensor_cpi_thermostat_base):
    def __init__(self):
        super().__init__()
        # invoke initialize entry point
        initialize(self)

        self.get_logger().info("temperature_sensor_cpi_thermostat infrastructure set up")

def main(args=None):
    rclpy.init(args=args)
    node = temperature_sensor_cpi_thermostat()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
