#include "wrap_pca_imp_Instance_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base_src.hpp"

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
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_Start, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Suspend_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Suspend",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_Suspend, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_load_drug_library_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_load_drug_library",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_load_drug_library, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_set_clinican_requested_bolus_duration_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_set_clinican_requested_bolus_duration",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_set_clinican_requested_bolus_duration, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_request_bolus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_request_bolus",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_request_bolus, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_pause_infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_pause_infusion",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_pause_infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_resume_infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_resume_infusion",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_resume_infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_status_AppConnected_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_status_AppConnected",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_status_AppConnected, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Infusion_Flow_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Bolus_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Square_Bolus_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Basal_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_VTBI, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Door_Open_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Door_Open",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Door_Open, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Alarm_Inactivation, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Alarm, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_CP_Bolus_Duration, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_ICE_Stop_Pump_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump",
        10);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Rx_Okay, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Request_Not_Too_Soon, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Request_Too_Soon, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_HW_Detected_Failure_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_HW_Detected_Failure",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_HW_Detected_Failure, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Stop_Pump_Completely_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Stop_Pump_Completely",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Stop_Pump_Completely, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Pump_At_KVO_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_CP_Clinician_Request_Bolus, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Halt_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Begin_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Near_Max_Drug_Per_Hour, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour",
        10,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Over_Max_Drug_Per_Hour, this, std::placeholders::_1), subscription_options_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_ICE_Stop_Pump(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_ICE_Stop_Pump_publisher_->publish(msg);
}

