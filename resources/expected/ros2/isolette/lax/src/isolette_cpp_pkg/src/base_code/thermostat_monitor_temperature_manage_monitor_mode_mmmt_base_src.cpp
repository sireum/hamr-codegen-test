#include "isolette_cpp_pkg/base_headers/thermostat_monitor_temperature_manage_monitor_mode_mmmt_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::thermostat_monitor_temperature_manage_monitor_mode_mmmt_base() : Node("thermostat_monitor_temperature_manage_monitor_mode_mmmt")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_interface_failure, this, std::placeholders::_1), subscription_options_);

    thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure",
        1,
        std::bind(&thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_internal_failure, this, std::placeholders::_1), subscription_options_);

    thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::MonitorMode>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode",
        1);

    thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::MonitorMode>(
        "thermostat_monitor_temperature_manage_alarm_mat_monitor_mode",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg)
{
    current_tempWstatus_msg_holder = msg;
}

void thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_interface_failure(const isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr msg)
{
    interface_failure_msg_holder = msg;
}

void thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::handle_internal_failure(const isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr msg)
{
    internal_failure_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::get_current_tempWstatus() {
    return current_tempWstatus_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::get_interface_failure() {
    return interface_failure_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::get_internal_failure() {
    return internal_failure_msg_holder;
}

void thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::put_monitor_mode(isolette_cpp_pkg_interfaces::msg::MonitorMode msg)
{
    thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1->publish(msg);
    thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2->publish(msg);
}

