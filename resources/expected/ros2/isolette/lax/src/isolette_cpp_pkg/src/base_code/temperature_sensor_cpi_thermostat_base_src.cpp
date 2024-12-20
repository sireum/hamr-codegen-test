#include "isolette_cpp_pkg/base_headers/temperature_sensor_cpi_thermostat_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

temperature_sensor_cpi_thermostat_base::temperature_sensor_cpi_thermostat_base() : Node("temperature_sensor_cpi_thermostat")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_air_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl>(
        "isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_air",
        1,
        std::bind(&temperature_sensor_cpi_thermostat_base::handle_air, this, std::placeholders::_1), subscription_options_);

    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_1 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus",
        1);

    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_2 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus",
        1);

    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_3 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus",
        1);

    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_4 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus",
        1);

    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_5 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus",
        1);

    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_6 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus",
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
    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_1->publish(msg);
    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_2->publish(msg);
    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_3->publish(msg);
    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_4->publish(msg);
    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_5->publish(msg);
    isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_6->publish(msg);
}

