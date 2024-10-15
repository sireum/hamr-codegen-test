#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_fan_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

BuildingControlDemo_i_Instance_tcp_fan_base::BuildingControlDemo_i_Instance_tcp_fan_base() : Node("BuildingControlDemo_i_Instance_tcp_fan")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    BuildingControlDemo_i_Instance_tcp_fan_fanCmd_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::FanCmd>(
        "BuildingControlDemo_i_Instance_tcp_fan_fanCmd",
        1,
        std::bind(&BuildingControlDemo_i_Instance_tcp_fan_base::handle_fanCmd, this, std::placeholders::_1), subscription_options_);

    BuildingControlDemo_i_Instance_tcp_fan_fanAck_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::FanAck>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_fanAck",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void BuildingControlDemo_i_Instance_tcp_fan_base::put_fanAck(building_control_cpp_pkg_interfaces::msg::FanAck msg)
{
    BuildingControlDemo_i_Instance_tcp_fan_fanAck_publisher_->publish(msg);
}

