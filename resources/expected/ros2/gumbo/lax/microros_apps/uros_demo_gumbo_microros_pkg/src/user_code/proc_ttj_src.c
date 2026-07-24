#include "uros_demo_gumbo_microros_pkg/user_headers/proc_ttj_src.h"


// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void proc_ttj_initialize(proc_ttj_base_t * self)
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void proc_ttj_handle_joy(proc_ttj_base_t * self, const sensor_msgs__msg__Joy * msg)
{
    // Handle joy msg
    PRINT_INFO("Received joy");

    // example publishing messages
    geometry_msgs__msg__Twist cmdVel = {0};
    put_cmdVel(self, &cmdVel);
    PRINT_INFO("Sent cmdVel");
}

