#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"

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

    void put_Alarm_Inactivation(example_interfaces::msg::Int32 msg);
    void put_Bolus_Duration(example_interfaces::msg::Int32 msg);
    void put_CP_Reset_Alarm(example_interfaces::msg::Int32 msg);
    void put_Confirm_Soft_Limit_Exception(example_interfaces::msg::Int32 msg);
    void put_Reject_Soft_Limit_Exception(example_interfaces::msg::Int32 msg);
    void put_Stop_Button_Pressed(example_interfaces::msg::Int32 msg);
    void put_Start_Button_Pressed(example_interfaces::msg::Int32 msg);
    void put_Clinician_Request_Bolus(example_interfaces::msg::Int32 msg);
    void put_Pause_Infusion(example_interfaces::msg::Int32 msg);
    void put_Resume_Infusion(example_interfaces::msg::Int32 msg);
    void put_Turn_Off(example_interfaces::msg::Int32 msg);

    rclcpp::CallbackGroup::SharedPtr cb_group_;

private:
    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Remaining_Battery_Time(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Using_Battery_Power(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Prescription(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Infusion_Flow_Rate(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Clinician_Name(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Patient_Name(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Touch(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Alarm(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Warning(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_System_Status(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Display_Message(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Sound_Type(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Low_Battery_Warning(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Hard_Limit_Violated(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Soft_Limit_Warning(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Patient_Request_Not_Too_Soon(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Patient_Request_Too_Soon(const example_interfaces::msg::Int32::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_Inactivation_publisher_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Remaining_Battery_Time_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Using_Battery_Power_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Touch_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type_subscription_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_CP_Reset_Alarm_publisher_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Low_Battery_Warning_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning_subscription_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Stop_Button_Pressed_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Start_Button_Pressed_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Pause_Infusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Resume_Infusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Turn_Off_publisher_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon_subscription_;

};
