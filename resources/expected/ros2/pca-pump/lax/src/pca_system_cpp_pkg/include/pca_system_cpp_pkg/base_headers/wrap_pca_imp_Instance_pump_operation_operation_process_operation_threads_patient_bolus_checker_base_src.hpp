#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Patient_Request_Not_Too_Soon(example_interfaces::msg::Int32 msg);
    void put_Patient_Request_Too_Soon(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_Minimum_Time_Between_Bolus();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Minimum_Time_Between_Bolus(const example_interfaces::msg::Int32::SharedPtr msg);
    virtual void handle_Patient_Button_Request(const example_interfaces::msg::Int32::SharedPtr msg) = 0;

    example_interfaces::msg::Int32::SharedPtr Minimum_Time_Between_Bolus_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Button_Request_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_3;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_2;

};
