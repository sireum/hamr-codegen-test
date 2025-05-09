#include "isolette_cpp_pkg/user_headers/thermostat_regulate_temperature_manage_regulator_interface_mrit_src.hpp"
#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void thermostat_regulate_temperature_manage_regulator_interface_mrit::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl current_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    init_current_tempWstatus(current_tempWstatus);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl lower_desired_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    init_lower_desired_tempWstatus(lower_desired_tempWstatus);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl upper_desired_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    init_upper_desired_tempWstatus(upper_desired_tempWstatus);

    isolette_cpp_pkg_interfaces::msg::RegulatorMode regulator_mode = isolette_cpp_pkg_interfaces::msg::RegulatorMode();
    init_regulator_mode(regulator_mode);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void thermostat_regulate_temperature_manage_regulator_interface_mrit::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus = get_current_tempWstatus();
    PRINT_INFO("Received current_tempWstatus: %s", MESSAGE_TO_STRING(current_tempWstatus));
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr lower_desired_tempWstatus = get_lower_desired_tempWstatus();
    PRINT_INFO("Received lower_desired_tempWstatus: %s", MESSAGE_TO_STRING(lower_desired_tempWstatus));
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr upper_desired_tempWstatus = get_upper_desired_tempWstatus();
    PRINT_INFO("Received upper_desired_tempWstatus: %s", MESSAGE_TO_STRING(upper_desired_tempWstatus));
    isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr regulator_mode = get_regulator_mode();
    PRINT_INFO("Received regulator_mode: %s", MESSAGE_TO_STRING(regulator_mode));

    // Example publishing messages
    isolette_cpp_pkg_interfaces::msg::Tempimpl upper_desired_temp = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    put_upper_desired_temp(upper_desired_temp);
    isolette_cpp_pkg_interfaces::msg::Tempimpl lower_desired_temp = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    put_lower_desired_temp(lower_desired_temp);
    isolette_cpp_pkg_interfaces::msg::Tempimpl displayed_temp = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    put_displayed_temp(displayed_temp);
    isolette_cpp_pkg_interfaces::msg::Status regulator_status = isolette_cpp_pkg_interfaces::msg::Status();
    put_regulator_status(regulator_status);
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl interface_failure = isolette_cpp_pkg_interfaces::msg::FailureFlagimpl();
    put_interface_failure(interface_failure);
}

