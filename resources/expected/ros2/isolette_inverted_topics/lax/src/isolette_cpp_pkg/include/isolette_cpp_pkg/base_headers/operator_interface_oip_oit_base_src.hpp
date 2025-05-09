#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class operator_interface_oip_oit_base : public rclcpp::Node
{
protected:
    operator_interface_oip_oit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) isolette_cpp_pkg_interfaces::msg::to_yaml(*message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_lower_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void put_upper_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void put_lower_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void put_upper_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);

    isolette_cpp_pkg_interfaces::msg::Status::SharedPtr get_regulator_status();
    isolette_cpp_pkg_interfaces::msg::Status::SharedPtr get_monitor_status();
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr get_display_temperature();
    isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr get_alarm_control();

    // Methods to be used to set initial values for data ports
    void init_regulator_status(isolette_cpp_pkg_interfaces::msg::Status val);
    void init_monitor_status(isolette_cpp_pkg_interfaces::msg::Status val);
    void init_display_temperature(isolette_cpp_pkg_interfaces::msg::Tempimpl val);
    void init_alarm_control(isolette_cpp_pkg_interfaces::msg::OnOff val);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_regulator_status(const isolette_cpp_pkg_interfaces::msg::Status::SharedPtr msg);
    void handle_monitor_status(const isolette_cpp_pkg_interfaces::msg::Status::SharedPtr msg);
    void handle_display_temperature(const isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr msg);
    void handle_alarm_control(const isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::Status::SharedPtr regulator_status_msg_holder;
    isolette_cpp_pkg_interfaces::msg::Status::SharedPtr monitor_status_msg_holder;
    isolette_cpp_pkg_interfaces::msg::Tempimpl::SharedPtr display_temperature_msg_holder;
    isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr alarm_control_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr operator_interface_oip_oit_regulator_status_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr operator_interface_oip_oit_monitor_status_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr operator_interface_oip_oit_display_temperature_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::OnOff>::SharedPtr operator_interface_oip_oit_alarm_control_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_lower_desired_tempWstatus_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_upper_desired_tempWstatus_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
