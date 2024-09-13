#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base() : Node("wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Scan_Data_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Scan_Data",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Scan_Data, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Authenticate_Clinician, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Authenticate_Patient, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Authenticate_Prescription, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Clinician_Name_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Patient_Name_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_fail_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_pass_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Security_Fault_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Clinician_Name(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Clinician_Name_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Patient_Name(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Patient_Name_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Prescription(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Authentication_fail(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_fail_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Authentication_pass(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_pass_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Security_Fault(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Security_Fault_publisher_->publish(msg);
}

