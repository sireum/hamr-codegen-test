#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base() : Node("isolette_single_sensor_Instance_heat_source_cpi_heat_controller")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_heat_source_cpi_heat_controller_heat_control_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::OnOff>(
        "isolette_single_sensor_Instance_heat_source_cpi_heat_controller_heat_control",
        1,
        std::bind(&isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::handle_heat_control, this, std::placeholders::_1), subscription_options_);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::handle_heat_control(const isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr msg)
{
    heat_control_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::get_heat_control() {
    return heat_control_msg_holder;
}