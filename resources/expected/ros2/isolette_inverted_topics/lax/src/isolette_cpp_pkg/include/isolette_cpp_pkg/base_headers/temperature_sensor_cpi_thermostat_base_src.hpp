#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/physical_tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class temperature_sensor_cpi_thermostat_base : public rclcpp::Node
{
protected:
    temperature_sensor_cpi_thermostat_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);

    isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl::SharedPtr get_air();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_air(const isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl::SharedPtr air_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl>::SharedPtr temperature_sensor_cpi_thermostat_air_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
