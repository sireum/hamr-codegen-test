#include "rclcpp/rclcpp.hpp"
#include "fan_in_fan_out_system_cpp_pkg_interfaces/msg/integer64.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class fanIn_consumer_base : public rclcpp::Node
{
protected:
    fanIn_consumer_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) fan_in_fan_out_system_cpp_pkg_interfaces::msg::to_yaml(*message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)


private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_myInteger(const fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr fanIn_consumer_myInteger_subscription_;


};
