#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Near_Max_Drug_Per_Hour(example_interfaces::msg::Int32 msg);
    void put_Over_Max_Drug_Per_Hour(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_Infusion_Flow_Rate();
    example_interfaces::msg::Int32::SharedPtr get_Max_Drug_Per_Hour();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Infusion_Flow_Rate(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Max_Drug_Per_Hour(const example_interfaces::msg::Int32::SharedPtr msg);

    example_interfaces::msg::Int32::SharedPtr Infusion_Flow_Rate_msg_holder;
    example_interfaces::msg::Int32::SharedPtr Max_Drug_Per_Hour_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_3;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
