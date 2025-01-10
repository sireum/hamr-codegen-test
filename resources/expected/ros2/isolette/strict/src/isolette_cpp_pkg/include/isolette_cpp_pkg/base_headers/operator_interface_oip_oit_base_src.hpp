#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class operator_interface_oip_oit_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<isolette_cpp_pkg_interfaces::msg::Status, isolette_cpp_pkg_interfaces::msg::Tempimpl, isolette_cpp_pkg_interfaces::msg::OnOff, isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>;

    operator_interface_oip_oit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_lower_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void put_upper_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void put_lower_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);
    void put_upper_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);

    isolette_cpp_pkg_interfaces::msg::Status get_regulator_status();
    isolette_cpp_pkg_interfaces::msg::Status get_monitor_status();
    isolette_cpp_pkg_interfaces::msg::Tempimpl get_display_temperature();
    isolette_cpp_pkg_interfaces::msg::OnOff get_alarm_control();

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
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr operator_interface_oip_oit_regulator_status_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr operator_interface_oip_oit_monitor_status_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr operator_interface_oip_oit_display_temperature_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::OnOff>::SharedPtr operator_interface_oip_oit_alarm_control_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_lower_desired_tempWstatus_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_upper_desired_tempWstatus_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_1;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_2;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (operator_interface_oip_oit_base::*)(MsgType)>> outPortTupleVector;
};
