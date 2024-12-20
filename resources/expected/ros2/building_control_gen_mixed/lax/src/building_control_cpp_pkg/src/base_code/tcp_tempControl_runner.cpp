#include "building_control_cpp_pkg/user_headers/tcp_tempControl_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

tcp_tempControl::tcp_tempControl() : tcp_tempControl_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("tcp_tempControl infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<tcp_tempControl>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
