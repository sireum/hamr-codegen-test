#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base() : Node("isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_interface_failure, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_internal_failure, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode",
        1);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_monitor_mode",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_current_tempWstatus(const example_interfaces::msg::Int32::SharedPtr msg)
{
    current_tempWstatus_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_interface_failure(const example_interfaces::msg::Int32::SharedPtr msg)
{
    interface_failure_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_internal_failure(const example_interfaces::msg::Int32::SharedPtr msg)
{
    internal_failure_msg_holder = msg;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::get_current_tempWstatus() {
    return current_tempWstatus_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::get_interface_failure() {
    return interface_failure_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::get_internal_failure() {
    return internal_failure_msg_holder;
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::put_monitor_mode(example_interfaces::msg::Int32 msg)
{
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1->publish(msg);
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2->publish(msg);
}

