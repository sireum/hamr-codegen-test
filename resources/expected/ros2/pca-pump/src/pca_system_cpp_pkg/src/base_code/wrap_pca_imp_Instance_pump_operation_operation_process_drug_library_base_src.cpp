#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_drug_library")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Load_Drug_Library_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Load_Drug_Library",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::handle_Load_Drug_Library, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::handle_Get_Drug_Record, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_The_Drug_Record_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_3 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::put_The_Drug_Record(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_The_Drug_Record_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::put_No_Drug_Found(example_interfaces::msg::Int32 msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_2->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_3->publish(msg);
}

