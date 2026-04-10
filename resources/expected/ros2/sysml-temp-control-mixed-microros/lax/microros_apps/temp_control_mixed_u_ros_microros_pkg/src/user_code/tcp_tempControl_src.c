#include "temp_control_mixed_u_ros_microros_pkg/user_headers/tcp_tempControl_src.h"
#include "temp_control_mixed_u_ros_microros_pkg/base_headers/enum_converter.h"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void tcp_tempControl_initialize(tcp_tempControl_base_t * self)
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void tcp_tempControl_handle_tempChanged(tcp_tempControl_base_t * self)
{
    // Handle tempChanged event
    PRINT_INFO("Received tempChanged");

    // example receiving messages on data ports
    temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__Temperature * currentTemp = get_currentTemp(self);

    // example publishing messages
    temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__FanCmd fanCmd = {0};
    put_fanCmd(self, &fanCmd);
    PRINT_INFO("Sent fanCmd: %s", MESSAGE_TO_STRING(&fanCmd));
}

void tcp_tempControl_handle_fanAck(tcp_tempControl_base_t * self, const temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__FanAck * msg)
{
    // Handle fanAck msg
    PRINT_INFO("Received fanAck");
}

void tcp_tempControl_handle_setPoint(tcp_tempControl_base_t * self, const temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__SetPoint * msg)
{
    // Handle setPoint msg
    PRINT_INFO("Received setPoint");
}

