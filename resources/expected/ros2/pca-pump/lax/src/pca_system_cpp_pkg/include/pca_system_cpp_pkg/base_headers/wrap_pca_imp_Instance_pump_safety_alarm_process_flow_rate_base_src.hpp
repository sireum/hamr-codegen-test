#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/status_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/flow_rateimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
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

    void put_Basal_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Bolus_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Square_Bolus_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Basal_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Bolus_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Square_Bolus_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);

    pca_system_cpp_pkg_interfaces::msg::StatusType::SharedPtr get_System_Status();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Infusion_Flow_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Upstream_Flow_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Downstream_Flow_Rate();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_System_Status(const pca_system_cpp_pkg_interfaces::msg::StatusType::SharedPtr msg);
    void handle_Infusion_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Upstream_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Downstream_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);

    pca_system_cpp_pkg_interfaces::msg::StatusType::SharedPtr System_Status_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Infusion_Flow_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Upstream_Flow_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Downstream_Flow_Rate_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::StatusType>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Upstream_Flow_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Downstream_Flow_Rate_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Overinfusion_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Overinfusion_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Overinfusion_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Underinfusion_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Underinfusion_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Underinfusion_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
