#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_regulator_mode(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32 get_current_tempWstatus();
    example_interfaces::msg::Int32 get_interface_failure();
    example_interfaces::msg::Int32 get_internal_failure();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureIn_current_tempWstatus;
    std::queue<MsgType> applicationIn_current_tempWstatus;
    std::queue<MsgType> infrastructureIn_interface_failure;
    std::queue<MsgType> applicationIn_interface_failure;
    std::queue<MsgType> infrastructureIn_internal_failure;
    std::queue<MsgType> applicationIn_internal_failure;

    std::queue<MsgType> infrastructureOut_regulator_mode;
    std::queue<MsgType> applicationOut_regulator_mode;

    void sendOut_regulator_mode(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_2;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::*)(MsgType)>> outPortTupleVector;
};
