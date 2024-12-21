#include "rclcpp/rclcpp.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_cmd.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_ack.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class tcp_fan_base : public rclcpp::Node
{
protected:
    tcp_fan_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_fanAck(building_control_cpp_pkg_interfaces::msg::FanAck msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_fanCmd(const building_control_cpp_pkg_interfaces::msg::FanCmd::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::FanCmd>::SharedPtr tcp_fan_fanCmd_subscription_;

    rclcpp::Publisher<building_control_cpp_pkg_interfaces::msg::FanAck>::SharedPtr tcp_fan_fanAck_publisher_;

};
