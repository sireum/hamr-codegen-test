#include "building_control_cpp_pkg/user_headers/tcp_tempControl_src.hpp"
#include "building_control_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void tcp_tempControl::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    building_control_cpp_pkg_interfaces::msg::Temperatureimpl currentTemp = building_control_cpp_pkg_interfaces::msg::Temperatureimpl();
    init_currentTemp(currentTemp);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void tcp_tempControl::handle_fanAck(const building_control_cpp_pkg_interfaces::msg::FanAck::SharedPtr msg)
{
    // Handle fanAck msg
    PRINT_INFO("Received fanAck: %s", MESSAGE_TO_STRING(msg));

    // example receiving messages on data ports
    building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr currentTemp = get_currentTemp();
    PRINT_INFO("Received currentTemp: %s", MESSAGE_TO_STRING(currentTemp));
}

void tcp_tempControl::handle_setPoint(const building_control_cpp_pkg_interfaces::msg::SetPointimpl::SharedPtr msg)
{
    // Handle setPoint msg
    PRINT_INFO("Received setPoint: %s", MESSAGE_TO_STRING(msg));
}

void tcp_tempControl::handle_tempChanged()
{
    // Handle tempChanged event
    PRINT_INFO("Received tempChanged");
}

