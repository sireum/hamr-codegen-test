#include "building_control_cpp_pkg/user_headers/tcp_fan_src.hpp"
#include "building_control_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

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
void tcp_fan::handle_fanCmd(const building_control_cpp_pkg_interfaces::msg::FanCmd::SharedPtr msg)
{
    // Handle fanCmd msg
    PRINT_INFO("Received fanCmd: %s", MESSAGE_TO_STRING(msg));


}

