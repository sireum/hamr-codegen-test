#include "isolette_cpp_pkg/base_headers/operator_interface_oip_oit_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

operator_interface_oip_oit_base::operator_interface_oip_oit_base() : Node("operator_interface_oip_oit")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    operator_interface_oip_oit_regulator_status_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Status>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status",
        1,
        std::bind(&operator_interface_oip_oit_base::handle_regulator_status, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_monitor_status_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Status>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status",
        1,
        std::bind(&operator_interface_oip_oit_base::handle_monitor_status, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_display_temperature_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp",
        1,
        std::bind(&operator_interface_oip_oit_base::handle_display_temperature, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_alarm_control_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::OnOff>(
        "thermostat_monitor_temperature_manage_alarm_mat_alarm_control",
        1,
        std::bind(&operator_interface_oip_oit_base::handle_alarm_control, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_lower_desired_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_lower_desired_tempWstatus",
        1);

    operator_interface_oip_oit_upper_desired_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_upper_desired_tempWstatus",
        1);

    operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_lower_alarm_tempWstatus",
        1);

    operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_upper_alarm_tempWstatus",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&operator_interface_oip_oit_base::timeTriggered, this), cb_group_);

}

void operator_interface_oip_oit_base::init_regulator_status(isolette_cpp_pkg_interfaces::msg::Status val) {
    regulator_status_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::Status>(val);
}

void operator_interface_oip_oit_base::init_monitor_status(isolette_cpp_pkg_interfaces::msg::Status val) {
    monitor_status_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::Status>(val);
}

void operator_interface_oip_oit_base::init_display_temperature(isolette_cpp_pkg_interfaces::msg::Tempimpl val) {
    display_temperature_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::Tempimpl>(val);
}

void operator_interface_oip_oit_base::init_alarm_control(isolette_cpp_pkg_interfaces::msg::OnOff val) {
    alarm_control_msg_holder = std::make_shared<isolette_cpp_pkg_interfaces::msg::OnOff>(val);
}


//=================================================
//  C o m m u n i c a t i o n
//=================================================

void operator_interface_oip_oit_base::handle_regulator_status(const isolette_cpp_pkg_interfaces::msg::Status::SharedPtr msg)
{
    regulator_status_msg_holder = msg;
}

void operator_interface_oip_oit_base::handle_monitor_status(const isolette_cpp_pkg_interfaces::msg::Status::SharedPtr msg)
{
    monitor_status_msg_holder = msg;
}

void operator_interface_oip_oit_base::handle_display_temperature(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg)
{
    display_temperature_msg_holder = msg;
}

void operator_interface_oip_oit_base::handle_alarm_control(const isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr msg)
{
    alarm_control_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::Status::SharedPtr operator_interface_oip_oit_base::get_regulator_status() {
    return regulator_status_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::Status::SharedPtr operator_interface_oip_oit_base::get_monitor_status() {
    return monitor_status_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr operator_interface_oip_oit_base::get_display_temperature() {
    return display_temperature_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr operator_interface_oip_oit_base::get_alarm_control() {
    return alarm_control_msg_holder;
}

void operator_interface_oip_oit_base::put_lower_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    operator_interface_oip_oit_lower_desired_tempWstatus_publisher_->publish(msg);
}

void operator_interface_oip_oit_base::put_upper_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    operator_interface_oip_oit_upper_desired_tempWstatus_publisher_->publish(msg);
}

void operator_interface_oip_oit_base::put_lower_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_->publish(msg);
}

void operator_interface_oip_oit_base::put_upper_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_->publish(msg);
}

