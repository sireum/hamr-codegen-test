#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/regulator_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl, isolette_cpp_pkg_interfaces::msg::Tempimpl, isolette_cpp_pkg_interfaces::msg::RegulatorMode, isolette_cpp_pkg_interfaces::msg::OnOff>;

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_heat_control(isolette_cpp_pkg_interfaces::msg::OnOff msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::Tempimpl get_lower_desired_temp();
    isolette_cpp_pkg_interfaces::msg::Tempimpl get_upper_desired_temp();
    isolette_cpp_pkg_interfaces::msg::RegulatorMode get_regulator_mode();

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
    std::queue<MsgType> infrastructureIn_lower_desired_temp;
    std::queue<MsgType> applicationIn_lower_desired_temp;
    std::queue<MsgType> infrastructureIn_upper_desired_temp;
    std::queue<MsgType> applicationIn_upper_desired_temp;
    std::queue<MsgType> infrastructureIn_regulator_mode;
    std::queue<MsgType> applicationIn_regulator_mode;

    std::queue<MsgType> infrastructureOut_heat_control;
    std::queue<MsgType> applicationOut_heat_control;

    void sendOut_heat_control(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::RegulatorMode>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::OnOff>::SharedPtr isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_base::*)(MsgType)>> outPortTupleVector;
};
