#include "isolette_cpp_pkg/base_headers/thermostat_monitor_temperature_manage_monitor_interface_mmit_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

thermostat_monitor_temperature_manage_monitor_interface_mmit_base::thermostat_monitor_temperature_manage_monitor_interface_mmit_base() : Node("thermostat_monitor_temperature_manage_monitor_interface_mmit")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_upper_alarm_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_lower_alarm_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::MonitorMode>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_monitor_mode, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp",
        1);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp",
        1);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Status>(
        "isolette_single_sensor_Instance_operator_interface_oip_oit_monitor_status",
        1);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_upper_alarm_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg)
{
    upper_alarm_tempWstatus_msg_holder = msg;
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_lower_alarm_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg)
{
    lower_alarm_tempWstatus_msg_holder = msg;
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg)
{
    current_tempWstatus_msg_holder = msg;
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_monitor_mode(const isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr msg)
{
    monitor_mode_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_upper_alarm_tempWstatus() {
    return upper_alarm_tempWstatus_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_lower_alarm_tempWstatus() {
    return lower_alarm_tempWstatus_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_current_tempWstatus() {
    return current_tempWstatus_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_monitor_mode() {
    return monitor_mode_msg_holder;
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_upper_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_->publish(msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_lower_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_->publish(msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_monitor_status(isolette_cpp_pkg_interfaces::msg::Status msg)
{
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_->publish(msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg)
{
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_->publish(msg);
}

