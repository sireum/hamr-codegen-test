#include "uros_demo_naming_cpp_pkg/user_headers/proc_logger_src.hpp"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void proc_logger::initialize()
{
    LOG_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void proc_logger::handle_rosout(const rcl_interfaces::msg::Log::SharedPtr msg)
{
    // Handle rosout msg
    // Deliberately does not log.  This node subscribes to /rosout, and a ROS node
    // publishes its own log records there -- so logging here would feed this handler
    // its own output and run away.  Write records to a file, a socket, or stdout;
    // anything routed through the ROS logger comes back.
}

