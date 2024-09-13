#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Clinician_Name(example_interfaces::msg::Int32 msg);
    void put_Patient_Name(example_interfaces::msg::Int32 msg);
    void put_Prescription(example_interfaces::msg::Int32 msg);
    void put_Authentication_fail(example_interfaces::msg::Int32 msg);
    void put_Authentication_pass(example_interfaces::msg::Int32 msg);
    void put_Security_Fault(example_interfaces::msg::Int32 msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Scan_Data(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Authenticate_Clinician(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Authenticate_Patient(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Authenticate_Prescription(const example_interfaces::msg::Int32::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Scan_Data_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Clinician_Name_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Patient_Name_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_fail_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_pass_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Security_Fault_publisher_;

};
