#include "turtle_control_structure_cpp_pkg/user_headers/proc_pilot_src.hpp"
#include "turtle_control_structure_cpp_pkg/base_headers/enum_converter.hpp"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void proc_pilot::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
    // Initialize the node's incoming data port values here
    turtlesim::msg::Pose pose = turtlesim::msg::Pose();
    init_pose(pose);

}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void proc_pilot::handle_speed(const turtle_control_structure_cpp_pkg_interfaces::msg::WheelSpeed::SharedPtr msg)
{
    // Handle speed msg
    PRINT_INFO("Received speed: %s", MESSAGE_TO_STRING(msg));

    // example receiving messages on data ports
    turtlesim::msg::Pose::SharedPtr pose = get_pose();
    PRINT_INFO("Received pose");
}

void proc_pilot::handle_overspeed()
{
    // Handle overspeed event
    PRINT_INFO("Received overspeed");
}

