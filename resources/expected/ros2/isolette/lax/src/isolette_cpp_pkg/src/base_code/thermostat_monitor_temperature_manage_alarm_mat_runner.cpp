#include "isolette_cpp_pkg/user_headers/thermostat_monitor_temperature_manage_alarm_mat_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

thermostat_monitor_temperature_manage_alarm_mat::thermostat_monitor_temperature_manage_alarm_mat() : thermostat_monitor_temperature_manage_alarm_mat_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("thermostat_monitor_temperature_manage_alarm_mat infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<thermostat_monitor_temperature_manage_alarm_mat>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}