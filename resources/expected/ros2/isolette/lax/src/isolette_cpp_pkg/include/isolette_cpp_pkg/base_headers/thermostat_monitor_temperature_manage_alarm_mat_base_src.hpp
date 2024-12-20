#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/monitor_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class thermostat_monitor_temperature_manage_alarm_mat_base : public rclcpp::Node
{
protected:
    thermostat_monitor_temperature_manage_alarm_mat_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_alarm_control(isolette_cpp_pkg_interfaces::msg::OnOff msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr get_lower_alarm_temp();
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr get_upper_alarm_temp();
    isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr get_monitor_mode();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_lower_alarm_temp(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg);
    void handle_upper_alarm_temp(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg);
    void handle_monitor_mode(const isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr lower_alarm_temp_msg_holder;
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr upper_alarm_temp_msg_holder;
    isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr monitor_mode_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::MonitorMode>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_monitor_mode_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::OnOff>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
