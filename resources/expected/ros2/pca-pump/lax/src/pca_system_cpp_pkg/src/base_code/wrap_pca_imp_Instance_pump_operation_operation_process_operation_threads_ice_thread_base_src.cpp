#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Start_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Start",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_Start, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Suspend_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Suspend",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_Suspend, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_load_drug_library_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_load_drug_library",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_load_drug_library, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_set_clinican_requested_bolus_duration_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_set_clinican_requested_bolus_duration",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_set_clinican_requested_bolus_duration, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_request_bolus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_request_bolus",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_request_bolus, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_pause_infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_pause_infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_pause_infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_resume_infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_resume_infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_resume_infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_status_AppConnected_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_status_AppConnected",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_status_AppConnected, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Infusion_Flow_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Bolus_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Square_Bolus_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Basal_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_VTBI, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Door_Open_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Door_Open",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Door_Open, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Alarm_Inactivation, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Alarm, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_CP_Bolus_Duration, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Rx_Okay, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Request_Not_Too_Soon, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Request_Too_Soon, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_HW_Detected_Failure_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_HW_Detected_Failure",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_HW_Detected_Failure, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Stop_Pump_Completely_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Stop_Pump_Completely",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Stop_Pump_Completely, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Pump_At_KVO_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_CP_Clinician_Request_Bolus, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Halt_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Begin_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Near_Max_Drug_Per_Hour, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Over_Max_Drug_Per_Hour, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_ICE_Stop_Pump_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_status_AppConnected(const example_interfaces::msg::Int32::SharedPtr msg)
{
    status_AppConnected_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Infusion_Flow_Rate(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Infusion_Flow_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Bolus_Rate(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Patient_Bolus_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Square_Bolus_Rate(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Square_Bolus_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Basal_Rate(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Basal_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_VTBI(const example_interfaces::msg::Int32::SharedPtr msg)
{
    VTBI_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Door_Open(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Door_Open_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Alarm_Inactivation(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Alarm_Inactivation_msg_holder = msg;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_status_AppConnected() {
    return status_AppConnected_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Infusion_Flow_Rate() {
    return Infusion_Flow_Rate_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Patient_Bolus_Rate() {
    return Patient_Bolus_Rate_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Square_Bolus_Rate() {
    return Square_Bolus_Rate_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Basal_Rate() {
    return Basal_Rate_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_VTBI() {
    return VTBI_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Door_Open() {
    return Door_Open_msg_holder;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Alarm_Inactivation() {
    return Alarm_Inactivation_msg_holder;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_ICE_Stop_Pump(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_ICE_Stop_Pump_publisher_->publish(msg);
}

