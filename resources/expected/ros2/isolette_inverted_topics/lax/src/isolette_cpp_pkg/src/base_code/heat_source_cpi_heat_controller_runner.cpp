#include "isolette_cpp_pkg/user_headers/heat_source_cpi_heat_controller_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

heat_source_cpi_heat_controller::heat_source_cpi_heat_controller() : heat_source_cpi_heat_controller_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("heat_source_cpi_heat_controller infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<heat_source_cpi_heat_controller>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
