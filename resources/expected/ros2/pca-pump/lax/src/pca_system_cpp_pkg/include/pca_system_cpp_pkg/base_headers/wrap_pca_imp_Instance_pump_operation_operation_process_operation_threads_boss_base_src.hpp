#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Display_Message(example_interfaces::msg::Int32 msg);
    void put_Sound_Type(example_interfaces::msg::Int32 msg);
    void put_Log_Event(example_interfaces::msg::Int32 msg);
    void put_Authenticate_Clinician(example_interfaces::msg::Int32 msg);
    void put_Authenticate_Patient(example_interfaces::msg::Int32 msg);
    void put_Authenticate_Prescription(example_interfaces::msg::Int32 msg);
    void put_Check_Rx(example_interfaces::msg::Int32 msg);
    void put_Begin_Priming(example_interfaces::msg::Int32 msg);
    void put_End_Priming(example_interfaces::msg::Int32 msg);
    void put_Prime_Failure(example_interfaces::msg::Int32 msg);
    void put_Begin_Infusion(example_interfaces::msg::Int32 msg);
    void put_Halt_Infusion(example_interfaces::msg::Int32 msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_POST_done(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_POST_fail(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Stop_Button_Pressed(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Start_Button_Pressed(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Scan_Done(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Authentication_fail(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Authentication_pass(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Drug_Not_In_Library(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Hard_Limit_Violated(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Reject_Soft_Limit_Exception(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Confirm_Soft_Limit_Exception(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Rx_Okay(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Door_Closed(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Turn_Off(const example_interfaces::msg::Int32::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_done_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_fail_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Scan_Done_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Door_Closed_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Display_Message_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Sound_Type_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Log_Event_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Clinician_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Patient_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Prescription_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Check_Rx_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Priming_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_End_Priming_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Prime_Failure_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_2;

};
