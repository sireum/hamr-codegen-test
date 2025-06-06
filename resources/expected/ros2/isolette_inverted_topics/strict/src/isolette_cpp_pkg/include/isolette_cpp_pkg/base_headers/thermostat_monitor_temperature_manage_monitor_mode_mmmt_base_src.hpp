#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/failure_flagimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/monitor_mode.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class thermostat_monitor_temperature_manage_monitor_mode_mmmt_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl, isolette_cpp_pkg_interfaces::msg::FailureFlagimpl, isolette_cpp_pkg_interfaces::msg::MonitorMode>;

    thermostat_monitor_temperature_manage_monitor_mode_mmmt_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) isolette_cpp_pkg_interfaces::msg::to_yaml(message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_monitor_mode(isolette_cpp_pkg_interfaces::msg::MonitorMode msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl get_interface_failure();
    isolette_cpp_pkg_interfaces::msg::FailureFlagimpl get_internal_failure();

    // Methods to be used to set initial values for data ports
    void init_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val);
    void init_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl val);
    void init_internal_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl val);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    void accept_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void accept_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg);
    void accept_internal_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg);

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

    std::queue<MsgType> infrastructureOut_monitor_mode;
    std::queue<MsgType> applicationOut_monitor_mode;

    void sendOut_monitor_mode(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_internal_failure_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::MonitorMode>::SharedPtr thermostat_monitor_temperature_manage_monitor_mode_mmmt_monitor_mode_publisher_;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_monitor_temperature_manage_monitor_mode_mmmt_base::*)(MsgType)>> outPortTupleVector;
};
