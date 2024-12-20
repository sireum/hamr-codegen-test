#include "datatypes_system_cpp_pkg/user_headers/consumer_consumer_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

consumer_consumer::consumer_consumer() : consumer_consumer_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("consumer_consumer infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<consumer_consumer>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
