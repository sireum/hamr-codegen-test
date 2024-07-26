#include "isolette_cpp_pkg/user_headers/isolette_single_sensor_Instance_operator_interface_oip_oit_src.hpp"

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_operator_interface_oip_oit::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void isolette_single_sensor_Instance_operator_interface_oip_oit::timeTriggered()
{
    // Port messages
    auto regulator_status_msg = get_regulator_status();
    auto monitor_status_msg = get_monitor_status();
    auto display_temperature_msg = get_display_temperature();
    auto alarm_control_msg = get_alarm_control();

    // Handle communication

}

