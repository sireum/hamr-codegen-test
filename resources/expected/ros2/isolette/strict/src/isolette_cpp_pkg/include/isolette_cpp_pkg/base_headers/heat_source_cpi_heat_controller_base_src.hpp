#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include "isolette_cpp_pkg_interfaces/msg/heat.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class heat_source_cpi_heat_controller_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<isolette_cpp_pkg_interfaces::msg::OnOff, isolette_cpp_pkg_interfaces::msg::Heat>;

    heat_source_cpi_heat_controller_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_heat_out(isolette_cpp_pkg_interfaces::msg::Heat msg);

    isolette_cpp_pkg_interfaces::msg::OnOff get_heat_control();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureIn_heat_control;
    std::queue<MsgType> applicationIn_heat_control;

    std::queue<MsgType> infrastructureOut_heat_out;
    std::queue<MsgType> applicationOut_heat_out;

    void sendOut_heat_out(MsgType msg);

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

    void timeTriggeredCaller();

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inEventPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (heat_source_cpi_heat_controller_base::*)(MsgType)>> outPortTupleVector;
};
