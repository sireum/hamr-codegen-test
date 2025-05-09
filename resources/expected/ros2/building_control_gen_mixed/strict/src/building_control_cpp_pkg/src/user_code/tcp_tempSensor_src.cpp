#include "building_control_cpp_pkg/user_headers/tcp_tempSensor_src.hpp"
#include "building_control_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void tcp_tempSensor::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void tcp_tempSensor::timeTriggered()
{
    // Handle communication



    // Example publishing messages
    building_control_cpp_pkg_interfaces::msg::Temperatureimpl currentTemp = building_control_cpp_pkg_interfaces::msg::Temperatureimpl();
    put_currentTemp(currentTemp);
    put_tempChanged();
}

