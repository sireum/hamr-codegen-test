#include "isolette_cpp_pkg/user_headers/isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit::isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit() : isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
