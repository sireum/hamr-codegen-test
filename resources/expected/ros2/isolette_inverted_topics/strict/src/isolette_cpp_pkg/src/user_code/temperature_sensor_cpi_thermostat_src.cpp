#include "isolette_cpp_pkg/user_headers/temperature_sensor_cpi_thermostat_src.hpp"
#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void temperature_sensor_cpi_thermostat::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl air = isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl();
    init_air(air);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void temperature_sensor_cpi_thermostat::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl air = get_air();
    PRINT_INFO("Received air: %s", MESSAGE_TO_STRING(air));

    // Example publishing messages
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl current_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    put_current_tempWstatus(current_tempWstatus);
}

