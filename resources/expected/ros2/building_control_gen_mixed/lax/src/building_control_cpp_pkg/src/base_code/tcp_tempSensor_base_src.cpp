#include "building_control_cpp_pkg/base_headers/tcp_tempSensor_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

tcp_tempSensor_base::tcp_tempSensor_base() : Node("tcp_tempSensor")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    tcp_tempSensor_currentTemp_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(
        "tcp_tempControl_currentTemp",
        1);

    tcp_tempSensor_tempChanged_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::Empty>(
        "tcp_tempControl_tempChanged",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&tcp_tempSensor_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void tcp_tempSensor_base::put_currentTemp(building_control_cpp_pkg_interfaces::msg::Temperatureimpl msg)
{
    tcp_tempSensor_currentTemp_publisher_->publish(msg);
}

void tcp_tempSensor_base::put_tempChanged()
{
    building_control_cpp_pkg_interfaces::msg::Empty msg = building_control_cpp_pkg_interfaces::msg::Empty();

    tcp_tempSensor_tempChanged_publisher_->publish(msg);
}

