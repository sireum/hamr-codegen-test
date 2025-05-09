#include "building_control_cpp_pkg/base_headers/tcp_tempControl_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

tcp_tempControl_base::tcp_tempControl_base() : Node("tcp_tempControl")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    tcp_tempControl_currentTemp_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(
        "tcp_tempSensor_currentTemp",
        1,
        std::bind(&tcp_tempControl_base::handle_currentTemp, this, std::placeholders::_1), subscription_options_);

    tcp_tempControl_fanAck_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::FanAck>(
        "tcp_fan_fanAck",
        1,
        std::bind(&tcp_tempControl_base::handle_fanAck, this, std::placeholders::_1), subscription_options_);

    tcp_tempControl_setPoint_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::SetPointimpl>(
        "tcp_tempControl_setPoint",
        1,
        std::bind(&tcp_tempControl_base::handle_setPoint, this, std::placeholders::_1), subscription_options_);

    tcp_tempControl_tempChanged_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::Empty>(
        "tcp_tempSensor_tempChanged",
        1,
        std::bind(&tcp_tempControl_base::event_handle_tempChanged, this, std::placeholders::_1), subscription_options_);

    tcp_tempControl_fanCmd_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::FanCmd>(
        "tcp_tempControl_fanCmd",
        1);

}

void tcp_tempControl_base::init_currentTemp(building_control_cpp_pkg_interfaces::msg::Temperatureimpl val) {
    currentTemp_msg_holder = std::make_shared<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(val);
}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void tcp_tempControl_base::handle_currentTemp(const building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr msg)
{
    currentTemp_msg_holder = msg;
}

building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr tcp_tempControl_base::get_currentTemp() {
    return currentTemp_msg_holder;
}

void tcp_tempControl_base::event_handle_tempChanged(const building_control_cpp_pkg_interfaces::msg::Empty::SharedPtr msg)
{
    (void)msg;
    handle_tempChanged();
}

void tcp_tempControl_base::put_fanCmd(building_control_cpp_pkg_interfaces::msg::FanCmd msg)
{
    tcp_tempControl_fanCmd_publisher_->publish(msg);
}

