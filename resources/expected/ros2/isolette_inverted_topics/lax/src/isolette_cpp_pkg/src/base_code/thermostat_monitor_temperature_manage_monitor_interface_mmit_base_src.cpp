#include "isolette_cpp_pkg/base_headers/thermostat_monitor_temperature_manage_monitor_interface_mmit_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

thermostat_monitor_temperature_manage_monitor_interface_mmit_base::thermostat_monitor_temperature_manage_monitor_interface_mmit_base() : Node("thermostat_monitor_temperature_manage_monitor_interface_mmit")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_upper_alarm_tempWstatus",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_upper_alarm_tempWstatus, this, std::placeholders::_1), subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_upper_alarm_tempWstatus",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_lower_alarm_tempWstatus, this, std::placeholders::_1), subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "temperature_sensor_cpi_thermostat_current_tempWstatus",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::MonitorMode>(
        "thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::handle_monitor_mode, this, std::placeholders::_1), subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp",
        1);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp",
        1);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Status>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status",
        1);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::timeTriggered, this), cb_group_);

}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::init_upper_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val) {
    upper_alarm_tempWstatus_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(val);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::init_lower_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val) {
    lower_alarm_tempWstatus_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(val);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::init_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val) {
    current_tempWstatus_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(val);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::init_monitor_mode(isolette_cpp_pkg_interfaces::msg::MonitorMode val) {
    monitor_mode_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::MonitorMode>(val);
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
    thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_->publish(msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_lower_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_->publish(msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_monitor_status(isolette_cpp_pkg_interfaces::msg::Status msg)
{
    thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_->publish(msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg)
{
    thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_->publish(msg);
}

