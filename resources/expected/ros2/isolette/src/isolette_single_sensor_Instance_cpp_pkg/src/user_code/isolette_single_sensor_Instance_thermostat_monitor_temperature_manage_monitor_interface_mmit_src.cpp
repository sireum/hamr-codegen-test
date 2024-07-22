#include "isolette_single_sensor_Instance_cpp_pkg/user_headers/isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_src.hpp"

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit::timeTriggered()
{
    // Port messages
    auto upper_alarm_tempWstatus_msg = get_upper_alarm_tempWstatus();
    auto lower_alarm_tempWstatus_msg = get_lower_alarm_tempWstatus();
    auto current_tempWstatus_msg = get_current_tempWstatus();
    auto monitor_mode_msg = get_monitor_mode();

    // Handle communication

}

