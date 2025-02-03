#include "fan_in_fan_out_system_cpp_pkg/user_headers/fanOut_consumer2_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanOut_consumer2::fanOut_consumer2() : fanOut_consumer2_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("fanOut_consumer2 infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<fanOut_consumer2>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
