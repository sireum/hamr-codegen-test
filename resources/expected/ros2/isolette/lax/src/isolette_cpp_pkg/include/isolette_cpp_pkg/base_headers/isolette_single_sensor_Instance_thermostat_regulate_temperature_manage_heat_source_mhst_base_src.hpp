#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_base : public rclcpp::Node
{
protected:
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_heat_control(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32::SharedPtr get_current_tempWstatus();
    example_interfaces::msg::Int32::SharedPtr get_lower_desired_temp();
    example_interfaces::msg::Int32::SharedPtr get_upper_desired_temp();
    example_interfaces::msg::Int32::SharedPtr get_regulator_mode();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_current_tempWstatus(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_lower_desired_temp(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_upper_desired_temp(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_regulator_mode(const example_interfaces::msg::Int32::SharedPtr msg);

    example_interfaces::msg::Int32::SharedPtr current_tempWstatus_msg_holder;
    example_interfaces::msg::Int32::SharedPtr lower_desired_temp_msg_holder;
    example_interfaces::msg::Int32::SharedPtr upper_desired_temp_msg_holder;
    example_interfaces::msg::Int32::SharedPtr regulator_mode_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
