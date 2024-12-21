#include "rclcpp/rclcpp.hpp"
#include "building_control_cpp_pkg_interfaces/msg/temperatureimpl.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_ack.hpp"
#include "building_control_cpp_pkg_interfaces/msg/set_pointimpl.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_cmd.hpp"
#include "building_control_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class tcp_tempControl_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<building_control_cpp_pkg_interfaces::msg::Temperatureimpl, building_control_cpp_pkg_interfaces::msg::FanAck, building_control_cpp_pkg_interfaces::msg::SetPointimpl, building_control_cpp_pkg_interfaces::msg::FanCmd, building_control_cpp_pkg_interfaces::msg::Empty>;

    tcp_tempControl_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_fanCmd(building_control_cpp_pkg_interfaces::msg::FanCmd msg);

    building_control_cpp_pkg_interfaces::msg::Temperatureimpl get_currentTemp();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (tcp_tempControl_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_fanAck(const building_control_cpp_pkg_interfaces::msg::FanAck msg) = 0;
    void handle_fanAck_base(MsgType msg);
    virtual void handle_setPoint(const building_control_cpp_pkg_interfaces::msg::SetPointimpl msg) = 0;
    void handle_setPoint_base(MsgType msg);
    virtual void handle_tempChanged(const building_control_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_tempChanged_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_currentTemp;
    std::queue<MsgType> applicationIn_currentTemp;
    std::queue<MsgType> infrastructureIn_fanAck;
    std::queue<MsgType> applicationIn_fanAck;
    std::queue<MsgType> infrastructureIn_setPoint;
    std::queue<MsgType> applicationIn_setPoint;
    std::queue<MsgType> infrastructureIn_tempChanged;
    std::queue<MsgType> applicationIn_tempChanged;

    std::queue<MsgType> infrastructureOut_fanCmd;
    std::queue<MsgType> applicationOut_fanCmd;

    void sendOut_fanCmd(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>::SharedPtr tcp_tempControl_currentTemp_subscription_;
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::FanAck>::SharedPtr tcp_tempControl_fanAck_subscription_;
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::SetPointimpl>::SharedPtr tcp_tempControl_setPoint_subscription_;
    rclcpp::Subscription<building_control_cpp_pkg_interfaces::msg::Empty>::SharedPtr tcp_tempControl_tempChanged_subscription_;

    rclcpp::Publisher<building_control_cpp_pkg_interfaces::msg::FanCmd>::SharedPtr tcp_tempControl_fanCmd_publisher_;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (tcp_tempControl_base::*)(MsgType)>> outPortTupleVector;
};
