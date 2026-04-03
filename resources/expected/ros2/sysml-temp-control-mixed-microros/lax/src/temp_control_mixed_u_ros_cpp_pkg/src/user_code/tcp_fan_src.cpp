#include "temp_control_mixed_u_ros_cpp_pkg/user_headers/tcp_fan_src.hpp"
#include "temp_control_mixed_u_ros_cpp_pkg/base_headers/enum_converter.hpp"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void tcp_fan::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void tcp_fan::timeTriggered()
{
    // Handle communication

    // Example publishing messages
    temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::FanAck fanAck = temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::FanAck();
    put_fanAck(fanAck);
}

