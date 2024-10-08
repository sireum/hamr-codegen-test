#include "datatypes_system_cpp_pkg/user_headers/Sys_i_Instance_consumer_consumer_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

Sys_i_Instance_consumer_consumer::Sys_i_Instance_consumer_consumer() : Sys_i_Instance_consumer_consumer_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("Sys_i_Instance_consumer_consumer infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<Sys_i_Instance_consumer_consumer>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
