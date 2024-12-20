#include "datatypes_system_cpp_pkg/user_headers/producer_producer_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

producer_producer::producer_producer() : producer_producer_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("producer_producer infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<producer_producer>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
