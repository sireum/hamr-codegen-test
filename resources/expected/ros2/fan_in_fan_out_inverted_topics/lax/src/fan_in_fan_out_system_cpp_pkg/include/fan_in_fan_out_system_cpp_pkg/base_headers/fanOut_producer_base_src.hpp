#include "rclcpp/rclcpp.hpp"
#include "fan_in_fan_out_system_cpp_pkg_interfaces/msg/integer64.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class fanOut_producer_base : public rclcpp::Node
{
protected:
    fanOut_producer_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) fan_in_fan_out_system_cpp_pkg_interfaces::msg::to_yaml(*message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr fanOut_producer_myInteger_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
