#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base() : Node("wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::StatusType>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_System_Status, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_Infusion_Flow_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Upstream_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Upstream_Flow_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_Upstream_Flow_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Downstream_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Downstream_Flow_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_Downstream_Flow_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Overinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Overinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Overinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Underinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Underinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Underinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(5),
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_System_Status(const pca_system_cpp_pkg_interfaces::msg::StatusType::SharedPtr msg)
{
    System_Status_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_Infusion_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg)
{
    Infusion_Flow_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_Upstream_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg)
{
    Upstream_Flow_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::handle_Downstream_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg)
{
    Downstream_Flow_Rate_msg_holder = msg;
}

pca_system_cpp_pkg_interfaces::msg::StatusType::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_System_Status() {
    return System_Status_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_Infusion_Flow_Rate() {
    return Infusion_Flow_Rate_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_Upstream_Flow_Rate() {
    return Upstream_Flow_Rate_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_Downstream_Flow_Rate() {
    return Downstream_Flow_Rate_msg_holder;
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Basal_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Overinfusion_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Bolus_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Overinfusion_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Square_Bolus_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Overinfusion_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Basal_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Underinfusion_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Bolus_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Underinfusion_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Square_Bolus_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Underinfusion_publisher_->publish(msg);
}

