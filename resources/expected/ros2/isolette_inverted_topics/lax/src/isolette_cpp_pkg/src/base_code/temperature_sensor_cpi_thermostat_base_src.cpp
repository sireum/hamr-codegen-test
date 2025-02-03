#include "isolette_cpp_pkg/base_headers/temperature_sensor_cpi_thermostat_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

temperature_sensor_cpi_thermostat_base::temperature_sensor_cpi_thermostat_base() : Node("temperature_sensor_cpi_thermostat")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    temperature_sensor_cpi_thermostat_air_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl>(
        "temperature_sensor_cpi_thermostat_air",
        1,
        std::bind(&temperature_sensor_cpi_thermostat_base::handle_air, this, std::placeholders::_1), subscription_options_);

    temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "temperature_sensor_cpi_thermostat_current_tempWstatus",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&temperature_sensor_cpi_thermostat_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void temperature_sensor_cpi_thermostat_base::handle_air(const isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl::SharedPtr msg)
{
    air_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl::SharedPtr temperature_sensor_cpi_thermostat_base::get_air() {
    return air_msg_holder;
}

void temperature_sensor_cpi_thermostat_base::put_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_->publish(msg);
}

