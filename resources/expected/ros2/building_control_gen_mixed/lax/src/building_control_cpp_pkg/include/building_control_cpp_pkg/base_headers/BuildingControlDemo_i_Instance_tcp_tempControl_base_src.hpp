#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class BuildingControlDemo_i_Instance_tcp_tempControl_base : public rclcpp::Node
{
protected:
    BuildingControlDemo_i_Instance_tcp_tempControl_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_fanCmd(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_currentTemp();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_currentTemp(const example_interfaces::msg::Int32::SharedPtr msg);
    virtual void handle_fanAck(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_setPoint(const example_interfaces::msg::Int32::SharedPtr msg) = 0;
    virtual void handle_tempChanged(const example_interfaces::msg::Int32::SharedPtr msg) = 0;

    example_interfaces::msg::Int32::SharedPtr currentTemp_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr BuildingControlDemo_i_Instance_tcp_tempControl_currentTemp_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr BuildingControlDemo_i_Instance_tcp_tempControl_fanAck_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr BuildingControlDemo_i_Instance_tcp_tempControl_setPoint_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr BuildingControlDemo_i_Instance_tcp_tempControl_tempChanged_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr BuildingControlDemo_i_Instance_tcp_tempControl_fanCmd_publisher_;

};
