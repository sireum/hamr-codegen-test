#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Prescription, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugRecordimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_The_Drug_Record, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Check_Rx, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Drug_Not_In_Library, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Confirm_Soft_Limit_Exception, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Reject_Soft_Limit_Exception, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_VTBI",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Square_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Basal_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Minimum_Time_Between_Bolus_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Max_Drug_Per_Hour_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Get_Drug_Record_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugCodeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Soft_Limit_Warning_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Prescription(const pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr msg)
{
    Prescription_msg_holder = msg;
}

pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::get_Prescription() {
    return Prescription_msg_holder;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_VTBI(pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Square_Bolus_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Patient_Bolus_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Basal_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Minimum_Time_Between_Bolus(pca_system_cpp_pkg_interfaces::msg::Minuteimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Minimum_Time_Between_Bolus_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Max_Drug_Per_Hour(pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Max_Drug_Per_Hour_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Get_Drug_Record(pca_system_cpp_pkg_interfaces::msg::DrugCodeimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Get_Drug_Record_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Rx_Okay(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Soft_Limit_Warning(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Soft_Limit_Warning_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Hard_Limit_Violated(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_2->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_3->publish(msg);
}

