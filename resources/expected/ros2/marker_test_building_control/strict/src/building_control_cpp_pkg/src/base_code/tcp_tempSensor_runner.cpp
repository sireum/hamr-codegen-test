#include "building_control_cpp_pkg/user_headers/tcp_tempSensor_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

tcp_tempSensor::tcp_tempSensor() : tcp_tempSensor_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("tcp_tempSensor infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<tcp_tempSensor>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
