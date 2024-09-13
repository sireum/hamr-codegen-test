#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base() : Node("isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_lower_alarm_temp, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_upper_alarm_temp, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_monitor_mode_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_monitor_mode",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_monitor_mode, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_operator_interface_oip_oit_alarm_control",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_current_tempWstatus(const example_interfaces::msg::Int32::SharedPtr msg)
{
    current_tempWstatus_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_lower_alarm_temp(const example_interfaces::msg::Int32::SharedPtr msg)
{
    lower_alarm_temp_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_upper_alarm_temp(const example_interfaces::msg::Int32::SharedPtr msg)
{
    upper_alarm_temp_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::handle_monitor_mode(const example_interfaces::msg::Int32::SharedPtr msg)
{
    monitor_mode_msg_holder = msg;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_current_tempWstatus() {
    return current_tempWstatus_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_lower_alarm_temp() {
    return lower_alarm_temp_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_upper_alarm_temp() {
    return upper_alarm_temp_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_monitor_mode() {
    return monitor_mode_msg_holder;
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::put_alarm_control(example_interfaces::msg::Int32 msg)
{
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_->publish(msg);
}

