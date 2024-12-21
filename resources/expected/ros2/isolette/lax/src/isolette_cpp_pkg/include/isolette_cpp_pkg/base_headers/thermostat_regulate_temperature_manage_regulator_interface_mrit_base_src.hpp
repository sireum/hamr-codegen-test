#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/regulator_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/failure_flagimpl.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class thermostat_regulate_temperature_manage_regulator_interface_mrit_base : public rclcpp::Node
{
protected:
    thermostat_regulate_temperature_manage_regulator_interface_mrit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_upper_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_lower_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_displayed_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_regulator_status(isolette_cpp_pkg_interfaces::msg::Status msg);
    void put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_lower_desired_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_upper_desired_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr get_regulator_mode();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_lower_desired_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_upper_desired_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_regulator_mode(const isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr lower_desired_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr upper_desired_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr regulator_mode_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::RegulatorMode>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
