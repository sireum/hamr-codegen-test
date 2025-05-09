#include "rclcpp/rclcpp.hpp"
#include "building_control_cpp_pkg_interfaces/msg/temperatureimpl.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_ack.hpp"
#include "building_control_cpp_pkg_interfaces/msg/set_pointimpl.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_cmd.hpp"
#include "building_control_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class tcp_tempControl_base : public rclcpp::Node
{
protected:
    tcp_tempControl_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) building_control_cpp_pkg_interfaces::msg::to_yaml(*message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_fanCmd(building_control_cpp_pkg_interfaces::msg::FanCmd msg);

    building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr get_currentTemp();

    // Methods to be used to set initial values for data ports
    void init_currentTemp(building_control_cpp_pkg_interfaces::msg::Temperatureimpl val);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_currentTemp(const building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr msg);
    virtual void handle_fanAck(const building_control_cpp_pkg_interfaces::msg::FanAck::SharedPtr msg) = 0;
    virtual void handle_setPoint(const building_control_cpp_pkg_interfaces::msg::SetPointimpl::SharedPtr msg) = 0;
    void event_handle_tempChanged(const building_control_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    virtual void handle_tempChanged() = 0;

    building_control_cpp_pkg_interfaces::msg::Temperatureimpl::SharedPtr currentTemp_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>::SharedPtr tcp_tempControl_currentTemp_subscription_;
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::FanAck>::SharedPtr tcp_tempControl_fanAck_subscription_;
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::SetPointimpl>::SharedPtr tcp_tempControl_setPoint_subscription_;
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::Empty>::SharedPtr tcp_tempControl_tempChanged_subscription_;

    rclcpp::Publisher<building_control_cpp_pkg_interfaces::msg::FanCmd>::SharedPtr tcp_tempControl_fanCmd_publisher_;

};
