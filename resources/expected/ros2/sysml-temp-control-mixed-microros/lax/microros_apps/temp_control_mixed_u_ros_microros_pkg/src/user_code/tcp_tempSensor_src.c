#include "temp_control_mixed_u_ros_microros_pkg/user_headers/tcp_tempSensor_src.h"
#include "temp_control_mixed_u_ros_microros_pkg/base_headers/enum_converter.h"

// This file will not be overwritten if HAMR codegen is rerun

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void tcp_tempSensor_initialize(tcp_tempSensor_base_t * self)
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void tcp_tempSensor_timeTriggered(tcp_tempSensor_base_t * self)
{
    // Handle communication

    // Example publishing messages
    temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__Temperature currentTemp = example_Temperature();
    put_currentTemp(self, &currentTemp);
    PRINT_INFO("Sent currentTemp: %s", MESSAGE_TO_STRING(&currentTemp));
    put_tempChanged(self);
}
