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
void BuildingControlDemo_i_Instance_tcp_tempControl::handle_fanAck(const building_control_cpp_pkg_interfaces::msg::FanAck msg)
{
    // Handle fanAck msg
}

void BuildingControlDemo_i_Instance_tcp_tempControl::handle_setPoint(const building_control_cpp_pkg_interfaces::msg::SetPointimpl msg)
{
    // Handle setPoint msg
}

void BuildingControlDemo_i_Instance_tcp_tempControl::handle_tempChanged(const building_control_cpp_pkg_interfaces::msg::Empty msg)
{
    // Handle tempChanged msg
}

