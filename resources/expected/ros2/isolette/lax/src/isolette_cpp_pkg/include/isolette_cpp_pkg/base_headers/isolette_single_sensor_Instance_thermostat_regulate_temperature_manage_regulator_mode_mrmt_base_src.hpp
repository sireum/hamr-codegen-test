#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/failure_flagimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/regulator_mode.hpp"
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

    void put_regulator_mode(isolette_cpp_pkg_interfaces::msg::RegulatorMode msg);

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
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::RegulatorMode>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_1;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::RegulatorMode>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_2;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};