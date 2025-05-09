#include "rclcpp/rclcpp.hpp"
#include "building_control_cpp_pkg_interfaces/msg/temperatureimpl.hpp"
#include "building_control_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class tcp_tempSensor_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<building_control_cpp_pkg_interfaces::msg::Temperatureimpl, building_control_cpp_pkg_interfaces::msg::Empty>;

    tcp_tempSensor_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) building_control_cpp_pkg_interfaces::msg::to_yaml(message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_currentTemp(building_control_cpp_pkg_interfaces::msg::Temperatureimpl msg);
    void put_tempChanged();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureOut_currentTemp;
    std::queue<MsgType> applicationOut_currentTemp;
    std::queue<MsgType> infrastructureOut_tempChanged;
    std::queue<MsgType> applicationOut_tempChanged;

    void sendOut_currentTemp(MsgType msg);
    void sendOut_tempChanged(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Publisher<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>::SharedPtr tcp_tempSensor_currentTemp_publisher_;
    rclcpp::Publisher<building_control_cpp_pkg_interfaces::msg::Empty>::SharedPtr tcp_tempSensor_tempChanged_publisher_;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (tcp_tempSensor_base::*)(MsgType)>> outPortTupleVector;
};
