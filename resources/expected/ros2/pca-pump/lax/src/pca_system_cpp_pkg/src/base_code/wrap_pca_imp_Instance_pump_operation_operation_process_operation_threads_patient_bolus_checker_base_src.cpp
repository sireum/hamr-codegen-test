#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::handle_Minimum_Time_Between_Bolus, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Button_Request_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Button_Request",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::handle_Patient_Button_Request, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Request_Not_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_3 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::handle_Minimum_Time_Between_Bolus(const example_interfaces::msg::Int32::SharedPtr msg)
{
    Minimum_Time_Between_Bolus_msg_holder = msg;
}

example_interfaces::msg::Int32::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::get_Minimum_Time_Between_Bolus() {
    return Minimum_Time_Between_Bolus_msg_holder;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::put_Patient_Request_Not_Too_Soon(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_2->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_3->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::put_Patient_Request_Too_Soon(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_2->publish(msg);
}

