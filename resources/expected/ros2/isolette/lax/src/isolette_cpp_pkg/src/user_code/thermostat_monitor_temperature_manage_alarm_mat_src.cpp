#include "isolette_cpp_pkg/user_headers/thermostat_monitor_temperature_manage_alarm_mat_src.hpp"
#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void thermostat_monitor_temperature_manage_alarm_mat::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl current_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    init_current_tempWstatus(current_tempWstatus);

    isolette_cpp_pkg_interfaces::msg::Tempimpl lower_alarm_temp = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    init_lower_alarm_temp(lower_alarm_temp);

    isolette_cpp_pkg_interfaces::msg::Tempimpl upper_alarm_temp = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    init_upper_alarm_temp(upper_alarm_temp);

    isolette_cpp_pkg_interfaces::msg::MonitorMode monitor_mode = isolette_cpp_pkg_interfaces::msg::MonitorMode();
    init_monitor_mode(monitor_mode);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void thermostat_monitor_temperature_manage_alarm_mat::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus = get_current_tempWstatus();
    PRINT_INFO("Received current_tempWstatus: %s", MESSAGE_TO_STRING(current_tempWstatus));
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr lower_alarm_temp = get_lower_alarm_temp();
    PRINT_INFO("Received lower_alarm_temp: %s", MESSAGE_TO_STRING(lower_alarm_temp));
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr upper_alarm_temp = get_upper_alarm_temp();
    PRINT_INFO("Received upper_alarm_temp: %s", MESSAGE_TO_STRING(upper_alarm_temp));
    isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr monitor_mode = get_monitor_mode();
    PRINT_INFO("Received monitor_mode: %s", MESSAGE_TO_STRING(monitor_mode));

    // Example publishing messages
    isolette_cpp_pkg_interfaces::msg::OnOff alarm_control = isolette_cpp_pkg_interfaces::msg::OnOff();
    put_alarm_control(alarm_control);
}

