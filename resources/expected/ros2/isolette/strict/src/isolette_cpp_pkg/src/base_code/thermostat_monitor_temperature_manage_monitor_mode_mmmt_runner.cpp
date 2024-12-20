#include "isolette_cpp_pkg/user_headers/thermostat_monitor_temperature_manage_monitor_mode_mmmt_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

thermostat_monitor_temperature_manage_monitor_mode_mmmt::thermostat_monitor_temperature_manage_monitor_mode_mmmt() : thermostat_monitor_temperature_manage_monitor_mode_mmmt_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("thermostat_monitor_temperature_manage_monitor_mode_mmmt infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<thermostat_monitor_temperature_manage_monitor_mode_mmmt>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
