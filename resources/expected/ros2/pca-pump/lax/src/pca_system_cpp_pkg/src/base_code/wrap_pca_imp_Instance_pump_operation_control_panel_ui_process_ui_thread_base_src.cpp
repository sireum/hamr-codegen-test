#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base() : Node("wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Remaining_Battery_Time_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Remaining_Battery_Time",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Remaining_Battery_Time, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Using_Battery_Power_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Using_Battery_Power",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Using_Battery_Power, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Prescription, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Infusion_Flow_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Clinician_Name, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Patient_Name, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Touch_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Touch",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Touch, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Alarm, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_System_Status, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Display_Message, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Sound_Type, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Low_Battery_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Low_Battery_Warning",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Low_Battery_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Hard_Limit_Violated, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Soft_Limit_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Patient_Request_Not_Too_Soon, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Patient_Request_Too_Soon, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_Inactivation_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Bolus_Duration",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_CP_Reset_Alarm_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Stop_Button_Pressed_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Start_Button_Pressed_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Clinician_Request_Bolus",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Pause_Infusion_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pause_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Resume_Infusion_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Resume_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Turn_Off_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Remaining_Battery_Time(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Remaining_Battery_Time_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Using_Battery_Power(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Using_Battery_Power_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Prescription(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Prescription_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Infusion_Flow_Rate(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Infusion_Flow_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Clinician_Name(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Clinician_Name_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Patient_Name(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Patient_Name_msg_holder = msg;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Remaining_Battery_Time() {
    return Remaining_Battery_Time_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Using_Battery_Power() {
    return Using_Battery_Power_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Prescription() {
    return Prescription_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Infusion_Flow_Rate() {
    return Infusion_Flow_Rate_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Clinician_Name() {
    return Clinician_Name_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Patient_Name() {
    return Patient_Name_msg_holder;
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Alarm_Inactivation(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_Inactivation_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Bolus_Duration(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_CP_Reset_Alarm(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_CP_Reset_Alarm_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Confirm_Soft_Limit_Exception(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Reject_Soft_Limit_Exception(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Stop_Button_Pressed(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Stop_Button_Pressed_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Start_Button_Pressed(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Start_Button_Pressed_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Clinician_Request_Bolus(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Pause_Infusion(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Pause_Infusion_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Resume_Infusion(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Resume_Infusion_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Turn_Off(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Turn_Off_publisher_->publish(msg);
}

