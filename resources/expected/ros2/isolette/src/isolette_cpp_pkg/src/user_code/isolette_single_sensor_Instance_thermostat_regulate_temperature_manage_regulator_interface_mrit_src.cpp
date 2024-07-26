#include "isolette_cpp_pkg/user_headers/isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_src.hpp"

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit::timeTriggered()
{
    // Port messages
    auto current_tempWstatus_msg = get_current_tempWstatus();
    auto lower_desired_tempWstatus_msg = get_lower_desired_tempWstatus();
    auto upper_desired_tempWstatus_msg = get_upper_desired_tempWstatus();
    auto regulator_mode_msg = get_regulator_mode();

    // Handle communication

}

