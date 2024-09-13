#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_upper_alarm_temp(example_interfaces::msg::Int32 msg);
    void put_lower_alarm_temp(example_interfaces::msg::Int32 msg);
    void put_monitor_status(example_interfaces::msg::Int32 msg);
    void put_interface_failure(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32 get_upper_alarm_tempWstatus();
    example_interfaces::msg::Int32 get_lower_alarm_tempWstatus();
    example_interfaces::msg::Int32 get_current_tempWstatus();
    example_interfaces::msg::Int32 get_monitor_mode();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureIn_upper_alarm_tempWstatus;
    std::queue<MsgType> applicationIn_upper_alarm_tempWstatus;
    std::queue<MsgType> infrastructureIn_lower_alarm_tempWstatus;
    std::queue<MsgType> applicationIn_lower_alarm_tempWstatus;
    std::queue<MsgType> infrastructureIn_current_tempWstatus;
    std::queue<MsgType> applicationIn_current_tempWstatus;
    std::queue<MsgType> infrastructureIn_monitor_mode;
    std::queue<MsgType> applicationIn_monitor_mode;

    std::queue<MsgType> infrastructureOut_upper_alarm_temp;
    std::queue<MsgType> applicationOut_upper_alarm_temp;
    std::queue<MsgType> infrastructureOut_lower_alarm_temp;
    std::queue<MsgType> applicationOut_lower_alarm_temp;
    std::queue<MsgType> infrastructureOut_monitor_status;
    std::queue<MsgType> applicationOut_monitor_status;
    std::queue<MsgType> infrastructureOut_interface_failure;
    std::queue<MsgType> applicationOut_interface_failure;

    void sendOut_upper_alarm_temp(MsgType msg);
    void sendOut_lower_alarm_temp(MsgType msg);
    void sendOut_monitor_status(MsgType msg);
    void sendOut_interface_failure(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface_mmit_base::*)(MsgType)>> outPortTupleVector;
};
