#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/sound.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/alarm_signal.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/boolean.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/prescriptionimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/flow_rateimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/string.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/alarm_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/warning_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/status_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/message.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/minuteimp.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Alarm_Inactivation(pca_system_cpp_pkg_interfaces::msg::AlarmSignal msg);
    void put_Bolus_Duration(pca_system_cpp_pkg_interfaces::msg::Minuteimp msg);
    void put_CP_Reset_Alarm(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Confirm_Soft_Limit_Exception(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Reject_Soft_Limit_Exception(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Stop_Button_Pressed(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Start_Button_Pressed(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Clinician_Request_Bolus(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Pause_Infusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Resume_Infusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Turn_Off(pca_system_cpp_pkg_interfaces::msg::Empty msg);

    pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr get_Remaining_Battery_Time();
    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr get_Using_Battery_Power();
    pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr get_Prescription();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Infusion_Flow_Rate();
    pca_system_cpp_pkg_interfaces::msg::String::SharedPtr get_Clinician_Name();
    pca_system_cpp_pkg_interfaces::msg::String::SharedPtr get_Patient_Name();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Remaining_Battery_Time(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Using_Battery_Power(const pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr msg);
    void handle_Prescription(const pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr msg);
    void handle_Infusion_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Clinician_Name(const pca_system_cpp_pkg_interfaces::msg::String::SharedPtr msg);
    void handle_Patient_Name(const pca_system_cpp_pkg_interfaces::msg::String::SharedPtr msg);
    virtual void handle_Touch(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType::SharedPtr msg) = 0;
    virtual void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType::SharedPtr msg) = 0;
    virtual void handle_System_Status(const pca_system_cpp_pkg_interfaces::msg::StatusType::SharedPtr msg) = 0;
    virtual void handle_Display_Message(const pca_system_cpp_pkg_interfaces::msg::Message::SharedPtr msg) = 0;
    virtual void handle_Sound_Type(const pca_system_cpp_pkg_interfaces::msg::Sound::SharedPtr msg) = 0;
    virtual void handle_Low_Battery_Warning(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Hard_Limit_Violated(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Soft_Limit_Warning(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Patient_Request_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;

    pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr Remaining_Battery_Time_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr Using_Battery_Power_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr Prescription_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Infusion_Flow_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::String::SharedPtr Clinician_Name_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::String::SharedPtr Patient_Name_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Remaining_Battery_Time_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Using_Battery_Power_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::String>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::String>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Touch_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::AlarmType>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::WarningType>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::StatusType>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Message>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Sound>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Low_Battery_Warning_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::AlarmSignal>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_Inactivation_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Minuteimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Minuteimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_CP_Reset_Alarm_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Stop_Button_Pressed_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Start_Button_Pressed_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Pause_Infusion_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Resume_Infusion_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Turn_Off_publisher_;

};
