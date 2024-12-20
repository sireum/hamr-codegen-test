#include "isolette_cpp_pkg/user_headers/operator_interface_oip_oit_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

operator_interface_oip_oit::operator_interface_oip_oit() : operator_interface_oip_oit_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("operator_interface_oip_oit infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<operator_interface_oip_oit>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
