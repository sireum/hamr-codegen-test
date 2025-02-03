#include "fan_in_fan_out_system_cpp_pkg/user_headers/fanIn_producer2_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanIn_producer2::fanIn_producer2() : fanIn_producer2_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("fanIn_producer2 infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<fanIn_producer2>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
