#include "building_control_cpp_pkg/user_headers/BuildingControlDemo_i_Instance_tcp_tempControl_src.hpp"

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void BuildingControlDemo_i_Instance_tcp_tempControl::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void BuildingControlDemo_i_Instance_tcp_tempControl::handle_fanAck(const example_interfaces::msg::Int32 msg)
{
    // Handle fanAck msg
}

void BuildingControlDemo_i_Instance_tcp_tempControl::handle_setPoint(const example_interfaces::msg::Int32 msg)
{
    // Handle setPoint msg
}

void BuildingControlDemo_i_Instance_tcp_tempControl::handle_tempChanged(const example_interfaces::msg::Int32 msg)
{
    // Handle tempChanged msg
}

