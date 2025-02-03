#include "fan_in_fan_out_system_cpp_pkg/user_headers/fanIn_consumer_src.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void fanIn_consumer::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void fanIn_consumer::handle_myInteger(const fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64::SharedPtr msg)
{
    // Handle myInteger msg
}

