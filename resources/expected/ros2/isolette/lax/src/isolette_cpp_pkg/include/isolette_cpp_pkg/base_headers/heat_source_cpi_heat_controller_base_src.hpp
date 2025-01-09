#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include "isolette_cpp_pkg_interfaces/msg/heat.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class heat_source_cpi_heat_controller_base : public rclcpp::Node
{
protected:
    heat_source_cpi_heat_controller_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_heat_out(isolette_cpp_pkg_interfaces::msg::Heat msg);

    isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr get_heat_control();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_heat_control(const isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr msg);

    isolette_cpp_pkg_interfaces::msg::OnOff::SharedPtr heat_control_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::OnOff>::SharedPtr heat_source_cpi_heat_controller_heat_control_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Heat>::SharedPtr heat_source_cpi_heat_controller_heat_out_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
