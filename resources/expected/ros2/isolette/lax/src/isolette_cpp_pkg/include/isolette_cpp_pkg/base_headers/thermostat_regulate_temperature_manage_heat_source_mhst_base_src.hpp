#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/regulator_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class thermostat_regulate_temperature_manage_heat_source_mhst_base : public rclcpp::Node
{
protected:
    thermostat_regulate_temperature_manage_heat_source_mhst_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_heat_control(isolette_cpp_pkg_interfaces::msg::OnOff msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr get_lower_desired_temp();
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr get_upper_desired_temp();
    isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr get_regulator_mode();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_current_tempWstatus(const isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr msg);
    void handle_lower_desired_temp(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg);
    void handle_upper_desired_temp(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg);
    void handle_regulator_mode(const isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl::SharedPtr current_tempWstatus_msg_holder;
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr lower_desired_temp_msg_holder;
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr upper_desired_temp_msg_holder;
    isolette_cpp_pkg_interfaces::msg::RegulatorMode::SharedPtr regulator_mode_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::RegulatorMode>::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::OnOff>::SharedPtr thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
