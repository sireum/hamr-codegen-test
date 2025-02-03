#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanIn_producer1_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanIn_producer1_base::fanIn_producer1_base() : Node("fanIn_producer1")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    fanIn_producer1_myInteger_publisher_ = this->create_publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanIn_producer1_myInteger",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&fanIn_producer1_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void fanIn_producer1_base::put_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    fanIn_producer1_myInteger_publisher_->publish(msg);
}

