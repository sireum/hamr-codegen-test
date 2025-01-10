#include "building_control_cpp_pkg/user_headers/tcp_fan_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

tcp_fan::tcp_fan() : tcp_fan_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("tcp_fan infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<tcp_fan>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
