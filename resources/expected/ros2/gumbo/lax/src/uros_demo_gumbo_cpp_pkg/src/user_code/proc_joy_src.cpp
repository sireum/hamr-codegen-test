#include "uros_demo_gumbo_cpp_pkg/user_headers/proc_joy_src.hpp"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void proc_joy::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void proc_joy::timeTriggered()
{
    // Handle communication

    // Example publishing messages
    sensor_msgs::msg::Joy joy = sensor_msgs::msg::Joy();
    put_joy(joy);
}

