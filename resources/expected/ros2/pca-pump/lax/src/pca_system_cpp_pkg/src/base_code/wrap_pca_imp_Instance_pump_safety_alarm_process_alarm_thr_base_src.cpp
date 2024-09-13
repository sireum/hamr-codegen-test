#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base() : Node("wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Alarm_Signal_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Alarm_Signal",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_ICE_Alarm_Signal, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Reset_Alarm_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Reset_Alarm",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_ICE_Reset_Alarm, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Max_Dose_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Hard_Limit_Violation, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Empty_Res_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Empty_Res",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Empty_Res, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Res_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Res",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Low_Res, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_Hot_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_Hot",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Pump_Hot, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Upstream_Occlusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Upstream_Occlusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Upstream_Occlusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Downstream_Occlusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Downstream_Occlusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Downstream_Occlusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bubble_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bubble",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Bubble, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Prime_Failure, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_CP_Reset_Alarm, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Drug_Not_In_Library, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Defective_Btty_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Defective_Btty",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Defective_Btty, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Battery_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Battery_Warning",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Low_Battery_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Voltage_OOR_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Voltage_OOR",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Voltage_OOR, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Basal_Overinfusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Bolus_Overinfusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Square_Bolus_Overinfusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Basal_Underinfusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Bolus_Underinfusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Square_Bolus_Underinfusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Security_Fault, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Alarm",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_3 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Warning",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_3 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pump_At_KVO_Rate",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Alarm(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_2->publish(msg);
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_3->publish(msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Warning(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_2->publish(msg);
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_3->publish(msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Pump_At_KVO_Rate(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_2->publish(msg);
}

