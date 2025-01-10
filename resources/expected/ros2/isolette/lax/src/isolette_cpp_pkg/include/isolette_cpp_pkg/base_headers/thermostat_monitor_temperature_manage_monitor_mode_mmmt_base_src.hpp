#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/failure_flagimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/monitor_mode.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class thermostat_monitor_temperature_manage_monitor_mode_mmmt_base : public rclcpp::Node
{
protected:
    thermostat_monitor_temperature_manage_monitor_mode_mmmt_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_monitor_mode(isolette_cpp_pkg_interfaces::msg::MonitorMode msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr get_interface_failure();
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr get_internal_failure();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_interface_failure(const isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr msg);
    void handle_internal_failure(const isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr interface_failure_msg_holder;
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl::SharedPtr internal_failure_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::MonitorMode>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_1;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::MonitorMode>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_2;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
