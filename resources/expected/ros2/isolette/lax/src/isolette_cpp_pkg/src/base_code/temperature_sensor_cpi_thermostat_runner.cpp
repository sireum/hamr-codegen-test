#include "isolette_cpp_pkg/user_headers/temperature_sensor_cpi_thermostat_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

temperature_sensor_cpi_thermostat::temperature_sensor_cpi_thermostat() : temperature_sensor_cpi_thermostat_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("temperature_sensor_cpi_thermostat infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<temperature_sensor_cpi_thermostat>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
