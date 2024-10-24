#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_tempControl_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

BuildingControlDemo_i_Instance_tcp_tempControl_base::BuildingControlDemo_i_Instance_tcp_tempControl_base() : Node("BuildingControlDemo_i_Instance_tcp_tempControl")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    BuildingControlDemo_i_Instance_tcp_tempControl_currentTemp_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_currentTemp",
        1,
        std::bind(&BuildingControlDemo_i_Instance_tcp_tempControl_base::handle_currentTemp, this, std::placeholders::_1), subscription_options_);

    BuildingControlDemo_i_Instance_tcp_tempControl_fanAck_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::FanAck>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_fanAck",
        1,
        std::bind(&BuildingControlDemo_i_Instance_tcp_tempControl_base::handle_fanAck, this, std::placeholders::_1), subscription_options_);

    BuildingControlDemo_i_Instance_tcp_tempControl_setPoint_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::SetPointimpl>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_setPoint",
        1,
        std::bind(&BuildingControlDemo_i_Instance_tcp_tempControl_base::handle_setPoint, this, std::placeholders::_1), subscription_options_);

    BuildingControlDemo_i_Instance_tcp_tempControl_tempChanged_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::Empty>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_tempChanged",
        1,
        std::bind(&BuildingControlDemo_i_Instance_tcp_tempControl_base::handle_tempChanged, this, std::placeholders::_1), subscription_options_);

    BuildingControlDemo_i_Instance_tcp_tempControl_fanCmd_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::FanCmd>(
        "BuildingControlDemo_i_Instance_tcp_fan_fanCmd",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void BuildingControlDemo_i_Instance_tcp_tempControl_base::handle_currentTemp(const building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr msg)
{
    currentTemp_msg_holder = msg;
}

building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr BuildingControlDemo_i_Instance_tcp_tempControl_base::get_currentTemp() {
    return currentTemp_msg_holder;
}

void BuildingControlDemo_i_Instance_tcp_tempControl_base::put_fanCmd(building_control_cpp_pkg_interfaces::msg::FanCmd msg)
{
    BuildingControlDemo_i_Instance_tcp_tempControl_fanCmd_publisher_->publish(msg);
}

