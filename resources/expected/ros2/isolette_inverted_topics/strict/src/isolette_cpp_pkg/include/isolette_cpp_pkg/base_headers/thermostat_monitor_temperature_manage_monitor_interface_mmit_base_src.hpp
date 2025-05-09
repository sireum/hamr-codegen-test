#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/monitor_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/failure_flagimpl.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class thermostat_monitor_temperature_manage_monitor_interface_mmit_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl, isolette_cpp_pkg_interfaces::msg::MonitorMode, isolette_cpp_pkg_interfaces::msg::Tempimpl, isolette_cpp_pkg_interfaces::msg::Status, isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>;

    thermostat_monitor_temperature_manage_monitor_interface_mmit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) isolette_cpp_pkg_interfaces::msg::to_yaml(message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_upper_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_lower_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_monitor_status(isolette_cpp_pkg_interfaces::msg::Status msg);
    void put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_upper_alarm_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_lower_alarm_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::MonitorMode get_monitor_mode();

    // Methods to be used to set initial values for data ports
    void init_upper_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val);
    void init_lower_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val);
    void init_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val);
    void init_monitor_mode(isolette_cpp_pkg_interfaces::msg::MonitorMode val);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    void accept_upper_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void accept_lower_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void accept_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void accept_monitor_mode(isolette_cpp_pkg_interfaces::msg::MonitorMode msg);

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
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::MonitorMode>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_monitor_temperature_manage_monitor_interface_mmit_base::*)(MsgType)>> outPortTupleVector;
};
