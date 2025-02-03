#include "isolette_cpp_pkg/base_headers/thermostat_regulate_temperature_manage_regulator_mode_mrmt_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::thermostat_regulate_temperature_manage_regulator_mode_mrmt_base() : Node("thermostat_regulate_temperature_manage_regulator_mode_mrmt")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "temperature_sensor_cpi_thermostat_current_tempWstatus",
        1,
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure",
        1,
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::handle_interface_failure, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure",
        1,
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::handle_internal_failure, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(
        "thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg)
{
    current_tempWstatus_msg_holder = msg;
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::handle_interface_failure(const isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr msg)
{
    interface_failure_msg_holder = msg;
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::handle_internal_failure(const isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr msg)
{
    internal_failure_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_current_tempWstatus() {
    return current_tempWstatus_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_interface_failure() {
    return interface_failure_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_internal_failure() {
    return internal_failure_msg_holder;
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::put_regulator_mode(isolette_cpp_pkg_interfaces::msg::RegulatorMode msg)
{
    thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_->publish(msg);
}

