#include "turtle_control_naming_microros_pkg/user_headers/proc_encoder_src.h"
#include "turtle_control_naming_microros_pkg/base_headers/enum_converter.h"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void proc_encoder_initialize(proc_encoder_base_t * self)
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void proc_encoder_timeTriggered(proc_encoder_base_t * self)
{
    // Handle communication

    // example receiving messages on data ports
    turtle_control_naming_cpp_pkg_interfaces__msg__OperatingMode * mode = get_mode(self);

    // example receiving queued arrivals -- at most one per port per dispatch
    if (has_calibrate(self)) {
        PRINT_INFO("Received calibrate");
    }
    turtle_control_naming_cpp_pkg_interfaces__msg__TrimCommand * trim = get_trim(self);
    if (trim != NULL) {
        PRINT_INFO("Received trim");
    }

    // Example publishing messages
    turtle_control_naming_cpp_pkg_interfaces__msg__WheelSpeed speed = example_WheelSpeed();
    put_speed(self, &speed);
    PRINT_INFO("Sent speed: %s", MESSAGE_TO_STRING(&speed));
    put_overspeed(self);
}
