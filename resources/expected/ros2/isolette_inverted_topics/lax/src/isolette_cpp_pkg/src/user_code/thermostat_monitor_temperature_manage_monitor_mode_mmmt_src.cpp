#include "isolette_cpp_pkg/user_headers/thermostat_monitor_temperature_manage_monitor_mode_mmmt_src.hpp"
#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void thermostat_monitor_temperature_manage_monitor_mode_mmmt::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl current_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    init_current_tempWstatus(current_tempWstatus);

    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl interface_failure = isolette_cpp_pkg_interfaces::msg::FailureFlagimpl();
    init_interface_failure(interface_failure);

    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl internal_failure = isolette_cpp_pkg_interfaces::msg::FailureFlagimpl();
    init_internal_failure(internal_failure);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void thermostat_monitor_temperature_manage_monitor_mode_mmmt::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus = get_current_tempWstatus();
    PRINT_INFO("Received current_tempWstatus: %s", MESSAGE_TO_STRING(current_tempWstatus));
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr interface_failure = get_interface_failure();
    PRINT_INFO("Received interface_failure: %s", MESSAGE_TO_STRING(interface_failure));
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr internal_failure = get_internal_failure();
    PRINT_INFO("Received internal_failure: %s", MESSAGE_TO_STRING(internal_failure));

    // Example publishing messages
    isolette_cpp_pkg_interfaces::msg::MonitorMode monitor_mode = isolette_cpp_pkg_interfaces::msg::MonitorMode();
    put_monitor_mode(monitor_mode);
}

