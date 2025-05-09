#include "fan_in_fan_out_system_cpp_pkg/user_headers/fanOut_consumer2_src.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void fanOut_consumer2::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void fanOut_consumer2::handle_myInteger(const fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    // Handle myInteger msg
    PRINT_INFO("Received myInteger: %s", MESSAGE_TO_STRING(msg));
}

