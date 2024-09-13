#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_VTBI(example_interfaces::msg::Int32 msg);
    void put_Square_Bolus_Rate(example_interfaces::msg::Int32 msg);
    void put_Patient_Bolus_Rate(example_interfaces::msg::Int32 msg);
    void put_Basal_Rate(example_interfaces::msg::Int32 msg);
    void put_Minimum_Time_Between_Bolus(example_interfaces::msg::Int32 msg);
    void put_Max_Drug_Per_Hour(example_interfaces::msg::Int32 msg);
    void put_Get_Drug_Record(example_interfaces::msg::Int32 msg);
    void put_Rx_Okay(example_interfaces::msg::Int32 msg);
    void put_Soft_Limit_Warning(example_interfaces::msg::Int32 msg);
    void put_Hard_Limit_Violated(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_Prescription();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Prescription(const example_interfaces::msg::Int32::SharedPtr msg);
    virtual void handle_The_Drug_Record(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Check_Rx(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Drug_Not_In_Library(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Confirm_Soft_Limit_Exception(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_Reject_Soft_Limit_Exception(const example_interfaces::msg::Int32::SharedPtr msg) = 0;

    example_interfaces::msg::Int32::SharedPtr Prescription_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Minimum_Time_Between_Bolus_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Max_Drug_Per_Hour_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Get_Drug_Record_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Soft_Limit_Warning_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_3;

};
