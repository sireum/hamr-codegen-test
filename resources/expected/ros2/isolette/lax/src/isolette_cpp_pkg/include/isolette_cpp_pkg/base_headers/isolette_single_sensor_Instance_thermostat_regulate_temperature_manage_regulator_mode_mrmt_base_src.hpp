#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base : public rclcpp::Node
{
protected:
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_regulator_mode(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_current_tempWstatus();
    example_interfaces::msg::Int32::SharedPtr get_interface_failure();
    example_interfaces::msg::Int32::SharedPtr get_internal_failure();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_current_tempWstatus(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_interface_failure(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_internal_failure(const example_interfaces::msg::Int32::SharedPtr msg);

    example_interfaces::msg::Int32::SharedPtr current_tempWstatus_msg_holder;
    example_interfaces::msg::Int32::SharedPtr interface_failure_msg_holder;
    example_interfaces::msg::Int32::SharedPtr internal_failure_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_2;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
