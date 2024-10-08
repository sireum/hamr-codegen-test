#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_done_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_done",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_POST_done, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_fail_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_fail",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_POST_fail, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Stop_Button_Pressed, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Start_Button_Pressed, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Scan_Done_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Scan_Done",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Scan_Done, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Authentication_fail, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Authentication_pass, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Drug_Not_In_Library, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Hard_Limit_Violated, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Reject_Soft_Limit_Exception, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Confirm_Soft_Limit_Exception, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Rx_Okay, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Door_Closed_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Door_Closed",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Door_Closed, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Turn_Off, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Display_Message_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Message>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Sound_Type_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Sound>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Log_Event_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Log_Event",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Clinician_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Patient_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Prescription_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Check_Rx_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Priming_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Priming",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_End_Priming_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_End_Priming",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Prime_Failure_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Halt_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion",
        1);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Display_Message(pca_system_cpp_pkg_interfaces::msg::Message msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Display_Message_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Sound_Type(pca_system_cpp_pkg_interfaces::msg::Sound msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Sound_Type_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Log_Event(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Log_Event_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Authenticate_Clinician(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Clinician_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Authenticate_Patient(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Patient_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Authenticate_Prescription(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Prescription_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Check_Rx(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Check_Rx_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Begin_Priming(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Priming_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_End_Priming(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_End_Priming_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Prime_Failure(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Prime_Failure_publisher_->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Begin_Infusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Halt_Infusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_2->publish(msg);
}

