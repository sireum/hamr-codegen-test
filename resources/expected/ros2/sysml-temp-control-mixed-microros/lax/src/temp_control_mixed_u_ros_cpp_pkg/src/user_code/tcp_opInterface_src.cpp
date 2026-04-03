#include "temp_control_mixed_u_ros_cpp_pkg/user_headers/tcp_opInterface_src.hpp"
#include "temp_control_mixed_u_ros_cpp_pkg/base_headers/enum_converter.hpp"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void tcp_opInterface::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::Temperature currentTemp = temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::Temperature();
    init_currentTemp(currentTemp);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void tcp_opInterface::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::Temperature::SharedPtr currentTemp = get_currentTemp();
    PRINT_INFO("Received currentTemp: %s", MESSAGE_TO_STRING(currentTemp));

    // Example publishing messages
    temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::SetPoint setPoint = temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::SetPoint();
    put_setPoint(setPoint);
}

