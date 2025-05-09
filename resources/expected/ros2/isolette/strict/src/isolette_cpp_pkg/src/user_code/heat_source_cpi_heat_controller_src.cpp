#include "isolette_cpp_pkg/user_headers/heat_source_cpi_heat_controller_src.hpp"
#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void heat_source_cpi_heat_controller::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    isolette_cpp_pkg_interfaces::msg::OnOff heat_control = isolette_cpp_pkg_interfaces::msg::OnOff();
    init_heat_control(heat_control);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void heat_source_cpi_heat_controller::timeTriggered()
{
    // Handle communication

    // example receiving messages on data ports
    isolette_cpp_pkg_interfaces::msg::OnOff heat_control = get_heat_control();
    PRINT_INFO("Received heat_control: %s", MESSAGE_TO_STRING(heat_control));

    // Example publishing messages
    isolette_cpp_pkg_interfaces::msg::Heat heat_out = isolette_cpp_pkg_interfaces::msg::Heat();
    put_heat_out(heat_out);
}

