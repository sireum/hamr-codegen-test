#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class isolette_single_sensor_Instance_operator_interface_oip_oit_base : public rclcpp::Node
{
protected:
    isolette_single_sensor_Instance_operator_interface_oip_oit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_lower_desired_tempWstatus(example_interfaces::msg::Int32 msg);
    void put_upper_desired_tempWstatus(example_interfaces::msg::Int32 msg);
    void put_upper_alarm_tempWstatus(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_regulator_status();
    example_interfaces::msg::Int32::SharedPtr get_monitor_status();
    example_interfaces::msg::Int32::SharedPtr get_display_temperature();
    example_interfaces::msg::Int32::SharedPtr get_alarm_control();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_regulator_status(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_monitor_status(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_display_temperature(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_alarm_control(const example_interfaces::msg::Int32::SharedPtr msg);

    example_interfaces::msg::Int32::SharedPtr regulator_status_msg_holder;
    example_interfaces::msg::Int32::SharedPtr monitor_status_msg_holder;
    example_interfaces::msg::Int32::SharedPtr display_temperature_msg_holder;
    example_interfaces::msg::Int32::SharedPtr alarm_control_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_regulator_status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_monitor_status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_display_temperature_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_alarm_control_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_lower_desired_tempWstatus_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_upper_desired_tempWstatus_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_2;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
