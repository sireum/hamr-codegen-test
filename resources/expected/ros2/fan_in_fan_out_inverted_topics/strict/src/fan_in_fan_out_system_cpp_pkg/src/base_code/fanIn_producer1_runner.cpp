#include "fan_in_fan_out_system_cpp_pkg/user_headers/fanIn_producer1_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanIn_producer1::fanIn_producer1() : fanIn_producer1_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("fanIn_producer1 infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<fanIn_producer1>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
