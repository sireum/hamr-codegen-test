#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/monitor_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/failure_flagimpl.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class thermostat_monitor_temperature_manage_monitor_interface_mmit_base : public rclcpp::Node
{
protected:
    thermostat_monitor_temperature_manage_monitor_interface_mmit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_upper_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_lower_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_monitor_status(isolette_cpp_pkg_interfaces::msg::Status msg);
    void put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_upper_alarm_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_lower_alarm_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr get_monitor_mode();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_upper_alarm_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_lower_alarm_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_monitor_mode(const isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr upper_alarm_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr lower_alarm_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::MonitorMode::SharedPtr monitor_mode_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::MonitorMode>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
