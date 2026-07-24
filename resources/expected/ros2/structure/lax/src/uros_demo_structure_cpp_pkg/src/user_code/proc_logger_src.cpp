#include "uros_demo_structure_cpp_pkg/user_headers/proc_logger_src.hpp"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void proc_logger::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void proc_logger::handle_rosout(const rcl_interfaces::msg::Log::SharedPtr msg)
{
    // Handle rosout msg
    PRINT_INFO("Received rosout");
}

