#include "isolette_cpp_pkg/user_headers/thermostat_regulate_temperature_manage_heat_source_mhst_src.hpp"
#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void thermostat_regulate_temperature_manage_heat_source_mhst::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl current_tempWstatus = isolette_cpp_pkg_interfaces::msg::TempWstatusimpl();
    init_current_tempWstatus(current_tempWstatus);

    isolette_cpp_pkg_interfaces::msg::Tempimpl lower_desired_temp = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    init_lower_desired_temp(lower_desired_temp);

    isolette_cpp_pkg_interfaces::msg::Tempimpl upper_desired_temp = isolette_cpp_pkg_interfaces::msg::Tempimpl();
    init_upper_desired_temp(upper_desired_temp);

    isolette_cpp_pkg_interfaces::msg::RegulatorMode regulator_mode = isolette_cpp_pkg_interfaces::msg::RegulatorMode();
    init_regulator_mode(regulator_mode);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void thermostat_regulate_temperature_manage_heat_source_mhst::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus = get_current_tempWstatus();
    PRINT_INFO("Received current_tempWstatus: %s", MESSAGE_TO_STRING(current_tempWstatus));
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr lower_desired_temp = get_lower_desired_temp();
    PRINT_INFO("Received lower_desired_temp: %s", MESSAGE_TO_STRING(lower_desired_temp));
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr upper_desired_temp = get_upper_desired_temp();
    PRINT_INFO("Received upper_desired_temp: %s", MESSAGE_TO_STRING(upper_desired_temp));
    isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr regulator_mode = get_regulator_mode();
    PRINT_INFO("Received regulator_mode: %s", MESSAGE_TO_STRING(regulator_mode));

    // Example publishing messages
    isolette_cpp_pkg_interfaces::msg::OnOff heat_control = isolette_cpp_pkg_interfaces::msg::OnOff();
    put_heat_control(heat_control);
}

