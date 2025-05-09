#include "isolette_cpp_pkg/user_headers/operator_interface_oip_oit_src.hpp"
#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void operator_interface_oip_oit::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    isolette_cpp_pkg_interfaces::msg::Status regulator_status = isolette_cpp_pkg_interfaces::msg::Status();
    init_regulator_status(regulator_status);

    isolette_cpp_pkg_interfaces::msg::Status monitor_status = isolette_cpp_pkg_interfaces::msg::Status();
    init_monitor_status(monitor_status);

    isolette_cpp_pkg_interfaces::msg::Tempimpl display_temperature = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    init_display_temperature(display_temperature);

    isolette_cpp_pkg_interfaces::msg::OnOff alarm_control = isolette_cpp_pkg_interfaces::msg::OnOff();
    init_alarm_control(alarm_control);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void operator_interface_oip_oit::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    isolette_cpp_pkg_interfaces::msg::Status::SharedPtr regulator_status = get_regulator_status();
    PRINT_INFO("Received regulator_status: %s", MESSAGE_TO_STRING(regulator_status));
    isolette_cpp_pkg_interfaces::msg::Status::SharedPtr monitor_status = get_monitor_status();
    PRINT_INFO("Received monitor_status: %s", MESSAGE_TO_STRING(monitor_status));
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr display_temperature = get_display_temperature();
    PRINT_INFO("Received display_temperature: %s", MESSAGE_TO_STRING(display_temperature));
    isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr alarm_control = get_alarm_control();
    PRINT_INFO("Received alarm_control: %s", MESSAGE_TO_STRING(alarm_control));

    // Example publishing messages
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl lower_desired_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    put_lower_desired_tempWstatus(lower_desired_tempWstatus);
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl upper_desired_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    put_upper_desired_tempWstatus(upper_desired_tempWstatus);
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl lower_alarm_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    put_lower_alarm_tempWstatus(lower_alarm_tempWstatus);
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl upper_alarm_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    put_upper_alarm_tempWstatus(upper_alarm_tempWstatus);
}

