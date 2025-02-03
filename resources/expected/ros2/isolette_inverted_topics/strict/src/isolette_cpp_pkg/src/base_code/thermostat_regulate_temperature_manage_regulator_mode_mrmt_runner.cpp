#include "isolette_cpp_pkg/user_headers/thermostat_regulate_temperature_manage_regulator_mode_mrmt_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

thermostat_regulate_temperature_manage_regulator_mode_mrmt::thermostat_regulate_temperature_manage_regulator_mode_mrmt() : thermostat_regulate_temperature_manage_regulator_mode_mrmt_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("thermostat_regulate_temperature_manage_regulator_mode_mrmt infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<thermostat_regulate_temperature_manage_regulator_mode_mrmt>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
