#include "isolette_cpp_pkg/user_headers/isolette_single_sensor_Instance_heat_source_cpi_heat_controller_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_heat_source_cpi_heat_controller::isolette_single_sensor_Instance_heat_source_cpi_heat_controller() : isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("isolette_single_sensor_Instance_heat_source_cpi_heat_controller infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<isolette_single_sensor_Instance_heat_source_cpi_heat_controller>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
