#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_tempSensor_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

BuildingControlDemo_i_Instance_tcp_tempSensor_base::BuildingControlDemo_i_Instance_tcp_tempSensor_base() : Node("BuildingControlDemo_i_Instance_tcp_tempSensor")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    BuildingControlDemo_i_Instance_tcp_tempSensor_currentTemp_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_currentTemp",
        1);

    BuildingControlDemo_i_Instance_tcp_tempSensor_tempChanged_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::Empty>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_tempChanged",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&BuildingControlDemo_i_Instance_tcp_tempSensor_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::put_currentTemp(building_control_cpp_pkg_interfaces::msg::Temperatureimpl msg)
{
    BuildingControlDemo_i_Instance_tcp_tempSensor_currentTemp_publisher_->publish(msg);
}

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::put_tempChanged(building_control_cpp_pkg_interfaces::msg::Empty msg)
{
    BuildingControlDemo_i_Instance_tcp_tempSensor_tempChanged_publisher_->publish(msg);
}

