#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class isolette_single_sensor_Instance_operator_interface_oip_oit_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    isolette_single_sensor_Instance_operator_interface_oip_oit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_lower_desired_tempWstatus(example_interfaces::msg::Int32 msg);
    void put_upper_desired_tempWstatus(example_interfaces::msg::Int32 msg);
    void put_lower_alarm_tempWstatus(example_interfaces::msg::Int32 msg);
    void put_upper_alarm_tempWstatus(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32 get_regulator_status();
    example_interfaces::msg::Int32 get_monitor_status();
    example_interfaces::msg::Int32 get_display_temperature();
    example_interfaces::msg::Int32 get_alarm_control();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureIn_regulator_status;
    std::queue<MsgType> applicationIn_regulator_status;
    std::queue<MsgType> infrastructureIn_monitor_status;
    std::queue<MsgType> applicationIn_monitor_status;
    std::queue<MsgType> infrastructureIn_display_temperature;
    std::queue<MsgType> applicationIn_display_temperature;
    std::queue<MsgType> infrastructureIn_alarm_control;
    std::queue<MsgType> applicationIn_alarm_control;

    std::queue<MsgType> infrastructureOut_lower_desired_tempWstatus;
    std::queue<MsgType> applicationOut_lower_desired_tempWstatus;
    std::queue<MsgType> infrastructureOut_upper_desired_tempWstatus;
    std::queue<MsgType> applicationOut_upper_desired_tempWstatus;
    std::queue<MsgType> infrastructureOut_lower_alarm_tempWstatus;
    std::queue<MsgType> applicationOut_lower_alarm_tempWstatus;
    std::queue<MsgType> infrastructureOut_upper_alarm_tempWstatus;
    std::queue<MsgType> applicationOut_upper_alarm_tempWstatus;

    void sendOut_lower_desired_tempWstatus(MsgType msg);
    void sendOut_upper_desired_tempWstatus(MsgType msg);
    void sendOut_lower_alarm_tempWstatus(MsgType msg);
    void sendOut_upper_alarm_tempWstatus(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_regulator_status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_monitor_status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_display_temperature_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_alarm_control_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_lower_desired_tempWstatus_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_upper_desired_tempWstatus_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_2;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_operator_interface_oip_oit_base::*)(MsgType)>> outPortTupleVector;
};
