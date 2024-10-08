#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Square_Bolus_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Square_Bolus_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Square_Bolus_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Bolus_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Bolus_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Patient_Bolus_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Basal_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Basal_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Basal_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_VTBI_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_VTBI",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_VTBI, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Door_Open_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Door_Open",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Door_Open, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Alarm_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::AlarmType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Alarm",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Alarm, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Warning_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::WarningType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Warning",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Warning, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Bolus_Duration_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Bolus_Duration",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_CP_Bolus_Duration, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Begin_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Priming_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Priming",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Begin_Priming, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_End_Priming_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_End_Priming",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_End_Priming, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Halt_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Halt_Infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Halt_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_HW_Detected_Failure_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_HW_Detected_Failure",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_HW_Detected_Failure, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Stop_Pump_Completely_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Stop_Pump_Completely",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Stop_Pump_Completely, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pump_At_KVO_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pump_At_KVO_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Pump_At_KVO_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Request_Not_Too_Soon_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Request_Not_Too_Soon",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Patient_Request_Not_Too_Soon, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pause_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pause_Infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Pause_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Resume_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Resume_Infusion",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Resume_Infusion, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Clinician_Request_Bolus_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Clinician_Request_Bolus",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_CP_Clinician_Request_Bolus, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Near_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Near_Max_Drug_Per_Hour",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Near_Max_Drug_Per_Hour, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Over_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Over_Max_Drug_Per_Hour",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Over_Max_Drug_Per_Hour, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_ICE_Stop_Pump, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_4 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::StatusType>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::StatusType>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Square_Bolus_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg)
{
    Square_Bolus_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Patient_Bolus_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg)
{
    Patient_Bolus_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Basal_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg)
{
    Basal_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_VTBI(const pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr msg)
{
    VTBI_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Door_Open(const pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr msg)
{
    Door_Open_msg_holder = msg;
}

pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Square_Bolus_Rate() {
    return Square_Bolus_Rate_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Patient_Bolus_Rate() {
    return Patient_Bolus_Rate_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Basal_Rate() {
    return Basal_Rate_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_VTBI() {
    return VTBI_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Door_Open() {
    return Door_Open_msg_holder;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::put_Infusion_Flow_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_2->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_3->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_4->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::put_System_Status(pca_system_cpp_pkg_interfaces::msg::StatusType msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_2->publish(msg);
}

