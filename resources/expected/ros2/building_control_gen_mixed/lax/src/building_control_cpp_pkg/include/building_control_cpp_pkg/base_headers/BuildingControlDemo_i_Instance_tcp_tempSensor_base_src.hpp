#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class BuildingControlDemo_i_Instance_tcp_tempSensor_base : public rclcpp::Node
{
protected:
    BuildingControlDemo_i_Instance_tcp_tempSensor_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_currentTemp(example_interfaces::msg::Int32 msg);
    void put_tempChanged(example_interfaces::msg::Int32 msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr BuildingControlDemo_i_Instance_tcp_tempSensor_currentTemp_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr BuildingControlDemo_i_Instance_tcp_tempSensor_tempChanged_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
