#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base() : Node("isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_lower_desired_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_upper_desired_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode",
        1,
        std::bind(&isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_regulator_mode, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp",
        1);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp",
        1);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_operator_interface_oip_oit_display_temperature",
        1);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_operator_interface_oip_oit_regulator_status",
        1);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_current_tempWstatus(const example_interfaces::msg::Int32::SharedPtr msg)
{
    current_tempWstatus_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_lower_desired_tempWstatus(const example_interfaces::msg::Int32::SharedPtr msg)
{
    lower_desired_tempWstatus_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_upper_desired_tempWstatus(const example_interfaces::msg::Int32::SharedPtr msg)
{
    upper_desired_tempWstatus_msg_holder = msg;
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::handle_regulator_mode(const example_interfaces::msg::Int32::SharedPtr msg)
{
    regulator_mode_msg_holder = msg;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_current_tempWstatus() {
    return current_tempWstatus_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_lower_desired_tempWstatus() {
    return lower_desired_tempWstatus_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_upper_desired_tempWstatus() {
    return upper_desired_tempWstatus_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_regulator_mode() {
    return regulator_mode_msg_holder;
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_upper_desired_temp(example_interfaces::msg::Int32 msg)
{
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_->publish(msg);
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_lower_desired_temp(example_interfaces::msg::Int32 msg)
{
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_->publish(msg);
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_displayed_temp(example_interfaces::msg::Int32 msg)
{
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_->publish(msg);
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_regulator_status(example_interfaces::msg::Int32 msg)
{
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_->publish(msg);
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_interface_failure(example_interfaces::msg::Int32 msg)
{
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_->publish(msg);
}

