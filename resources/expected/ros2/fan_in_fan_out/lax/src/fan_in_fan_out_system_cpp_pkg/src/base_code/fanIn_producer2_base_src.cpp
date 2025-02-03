#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanIn_producer2_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanIn_producer2_base::fanIn_producer2_base() : Node("fanIn_producer2")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    fanIn_producer2_myInteger_publisher_ = this->create_publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanIn_consumer_myInteger",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&fanIn_producer2_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void fanIn_producer2_base::put_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    fanIn_producer2_myInteger_publisher_->publish(msg);
}

