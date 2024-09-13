#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Basal_Overinfusion(example_interfaces::msg::Int32 msg);
    void put_Bolus_Overinfusion(example_interfaces::msg::Int32 msg);
    void put_Square_Bolus_Overinfusion(example_interfaces::msg::Int32 msg);
    void put_Basal_Underinfusion(example_interfaces::msg::Int32 msg);
    void put_Bolus_Underinfusion(example_interfaces::msg::Int32 msg);
    void put_Square_Bolus_Underinfusion(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_System_Status();
    example_interfaces::msg::Int32::SharedPtr get_Infusion_Flow_Rate();
    example_interfaces::msg::Int32::SharedPtr get_Upstream_Flow_Rate();
    example_interfaces::msg::Int32::SharedPtr get_Downstream_Flow_Rate();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_System_Status(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Infusion_Flow_Rate(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Upstream_Flow_Rate(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Downstream_Flow_Rate(const example_interfaces::msg::Int32::SharedPtr msg);

    example_interfaces::msg::Int32::SharedPtr System_Status_msg_holder;
    example_interfaces::msg::Int32::SharedPtr Infusion_Flow_Rate_msg_holder;
    example_interfaces::msg::Int32::SharedPtr Upstream_Flow_Rate_msg_holder;
    example_interfaces::msg::Int32::SharedPtr Downstream_Flow_Rate_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Upstream_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Downstream_Flow_Rate_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Overinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Overinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Overinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Underinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Underinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Underinfusion_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
