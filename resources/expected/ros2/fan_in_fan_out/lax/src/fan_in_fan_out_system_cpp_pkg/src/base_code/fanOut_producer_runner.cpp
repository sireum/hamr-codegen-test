#include "fan_in_fan_out_system_cpp_pkg/user_headers/fanOut_producer_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanOut_producer::fanOut_producer() : fanOut_producer_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("fanOut_producer infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<fanOut_producer>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
