#include "rclcpp/rclcpp.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_cmd.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_ack.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class BuildingControlDemo_i_Instance_tcp_fan_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<building_control_cpp_pkg_interfaces::msg::FanCmd, building_control_cpp_pkg_interfaces::msg::FanAck>;

    BuildingControlDemo_i_Instance_tcp_fan_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_fanAck(building_control_cpp_pkg_interfaces::msg::FanAck msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (BuildingControlDemo_i_Instance_tcp_fan_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_fanCmd(const building_control_cpp_pkg_interfaces::msg::FanCmd msg) = 0;
    void handle_fanCmd_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_fanCmd;
    std::queue<MsgType> applicationIn_fanCmd;

    std::queue<MsgType> infrastructureOut_fanAck;
    std::queue<MsgType> applicationOut_fanAck;

    void sendOut_fanAck(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::FanCmd>::SharedPtr BuildingControlDemo_i_Instance_tcp_fan_fanCmd_subscription_;

    rclcpp::Publisher<building_control_cpp_pkg_interfaces::msg::FanAck>::SharedPtr BuildingControlDemo_i_Instance_tcp_fan_fanAck_publisher_;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (BuildingControlDemo_i_Instance_tcp_fan_base::*)(MsgType)>> outPortTupleVector;
};
