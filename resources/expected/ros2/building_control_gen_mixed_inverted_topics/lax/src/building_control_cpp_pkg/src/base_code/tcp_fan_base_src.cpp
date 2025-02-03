#include "building_control_cpp_pkg/base_headers/tcp_fan_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

tcp_fan_base::tcp_fan_base() : Node("tcp_fan")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    tcp_fan_fanCmd_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::FanCmd>(
        "tcp_tempControl_fanCmd",
        1,
        std::bind(&tcp_fan_base::handle_fanCmd, this, std::placeholders::_1), subscription_options_);

    tcp_fan_fanAck_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::FanAck>(
        "tcp_fan_fanAck",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void tcp_fan_base::put_fanAck(building_control_cpp_pkg_interfaces::msg::FanAck msg)
{
    tcp_fan_fanAck_publisher_->publish(msg);
}

