#include "rclcpp/rclcpp.hpp"
#include "fan_in_fan_out_system_cpp_pkg_interfaces/msg/integer64.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class fanIn_consumer_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>;

    fanIn_consumer_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)


private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    void accept_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg);

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (fanIn_consumer_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_myInteger(const fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg) = 0;
    void handle_myInteger_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_myInteger;
    std::queue<MsgType> applicationIn_myInteger;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr fanIn_consumer_myInteger_subscription_;


    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanIn_consumer_base::*)(MsgType)>> outPortTupleVector;
};
