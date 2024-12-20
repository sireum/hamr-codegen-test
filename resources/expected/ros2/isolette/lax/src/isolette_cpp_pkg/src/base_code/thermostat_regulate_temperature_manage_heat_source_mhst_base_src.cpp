#include "isolette_cpp_pkg/base_headers/thermostat_regulate_temperature_manage_heat_source_mhst_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

thermostat_regulate_temperature_manage_heat_source_mhst_base::thermostat_regulate_temperature_manage_heat_source_mhst_base() : Node("thermostat_regulate_temperature_manage_heat_source_mhst")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_lower_desired_temp, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_upper_desired_temp, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_regulator_mode, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::OnOff>(
        "isolette_single_sensor_Instance_heat_source_cpi_heat_controller_heat_control",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg)
{
    current_tempWstatus_msg_holder = msg;
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_lower_desired_temp(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg)
{
    lower_desired_temp_msg_holder = msg;
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_upper_desired_temp(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg)
{
    upper_desired_temp_msg_holder = msg;
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::handle_regulator_mode(const isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr msg)
{
    regulator_mode_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_base::get_current_tempWstatus() {
    return current_tempWstatus_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_base::get_lower_desired_temp() {
    return lower_desired_temp_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_base::get_upper_desired_temp() {
    return upper_desired_temp_msg_holder;
}

isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_base::get_regulator_mode() {
    return regulator_mode_msg_holder;
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::put_heat_control(isolette_cpp_pkg_interfaces::msg::OnOff msg)
{
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_->publish(msg);
}

