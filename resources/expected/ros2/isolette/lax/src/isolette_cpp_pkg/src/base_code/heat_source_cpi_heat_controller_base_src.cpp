#include "isolette_cpp_pkg/base_headers/heat_source_cpi_heat_controller_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

heat_source_cpi_heat_controller_base::heat_source_cpi_heat_controller_base() : Node("heat_source_cpi_heat_controller")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    heat_source_cpi_heat_controller_heat_control_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::OnOff>(
        "heat_source_cpi_heat_controller_heat_control",
        1,
        std::bind(&heat_source_cpi_heat_controller_base::handle_heat_control, this, std::placeholders::_1), subscription_options_);

    heat_source_cpi_heat_controller_heat_out_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Heat>(
        "heat_source_cpi_heat_controller_heat_out",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&heat_source_cpi_heat_controller_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void heat_source_cpi_heat_controller_base::handle_heat_control(const isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr msg)
{
    heat_control_msg_holder = msg;
}

isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr heat_source_cpi_heat_controller_base::get_heat_control() {
    return heat_control_msg_holder;
}

void heat_source_cpi_heat_controller_base::put_heat_out(isolette_cpp_pkg_interfaces::msg::Heat msg)
{
    heat_source_cpi_heat_controller_heat_out_publisher_->publish(msg);
}

