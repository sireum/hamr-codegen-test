#include "isolette_cpp_pkg/user_headers/isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_src.hpp"

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt::timeTriggered()
{
    // Port messages
    auto current_tempWstatus_msg = get_current_tempWstatus();
    auto interface_failure_msg = get_interface_failure();
    auto internal_failure_msg = get_internal_failure();

    // Handle communication

}

