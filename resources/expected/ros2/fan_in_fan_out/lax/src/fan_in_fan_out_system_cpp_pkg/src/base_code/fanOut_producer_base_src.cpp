#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanOut_producer_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanOut_producer_base::fanOut_producer_base() : Node("fanOut_producer")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    fanOut_producer_myInteger_publisher_1 = this->create_publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanOut_consumer1_myInteger",
        1);

    fanOut_producer_myInteger_publisher_2 = this->create_publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanOut_consumer2_myInteger",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&fanOut_producer_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void fanOut_producer_base::put_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    fanOut_producer_myInteger_publisher_1->publish(msg);
    fanOut_producer_myInteger_publisher_2->publish(msg);
}

