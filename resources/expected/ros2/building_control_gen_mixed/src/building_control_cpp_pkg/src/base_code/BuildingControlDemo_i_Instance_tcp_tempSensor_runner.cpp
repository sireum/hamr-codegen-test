#include "building_control_cpp_pkg/user_headers/BuildingControlDemo_i_Instance_tcp_tempSensor_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

BuildingControlDemo_i_Instance_tcp_tempSensor::BuildingControlDemo_i_Instance_tcp_tempSensor() : BuildingControlDemo_i_Instance_tcp_tempSensor_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("BuildingControlDemo_i_Instance_tcp_tempSensor infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<BuildingControlDemo_i_Instance_tcp_tempSensor>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
