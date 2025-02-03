#include "rclcpp/rclcpp.hpp"
#include "fan_in_fan_out_system_cpp_pkg_interfaces/msg/integer64.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class fanIn_producer1_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>;

    fanIn_producer1_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureOut_myInteger;
    std::queue<MsgType> applicationOut_myInteger;

    void sendOut_myInteger(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr fanIn_producer1_myInteger_publisher_;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanIn_producer1_base::*)(MsgType)>> outPortTupleVector;
};
