#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/regulator_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/failure_flagimpl.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class thermostat_regulate_temperature_manage_regulator_interface_mrit_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl, isolette_cpp_pkg_interfaces::msg::RegulatorMode, isolette_cpp_pkg_interfaces::msg::Tempimpl, isolette_cpp_pkg_interfaces::msg::Status, isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>;

    thermostat_regulate_temperature_manage_regulator_interface_mrit_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_upper_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_lower_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_displayed_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg);
    void put_regulator_status(isolette_cpp_pkg_interfaces::msg::Status msg);
    void put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg);

    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_current_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_lower_desired_tempWstatus();
    isolette_cpp_pkg_interfaces::msg::TempWstatusimpl get_upper_desired_tempWstatus();
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
    std::queue<MsgType> infrastructureIn_lower_desired_tempWstatus;
    std::queue<MsgType> applicationIn_lower_desired_tempWstatus;
    std::queue<MsgType> infrastructureIn_upper_desired_tempWstatus;
    std::queue<MsgType> applicationIn_upper_desired_tempWstatus;
    std::queue<MsgType> infrastructureIn_regulator_mode;
    std::queue<MsgType> applicationIn_regulator_mode;

    std::queue<MsgType> infrastructureOut_upper_desired_temp;
    std::queue<MsgType> applicationOut_upper_desired_temp;
    std::queue<MsgType> infrastructureOut_lower_desired_temp;
    std::queue<MsgType> applicationOut_lower_desired_temp;
    std::queue<MsgType> infrastructureOut_displayed_temp;
    std::queue<MsgType> applicationOut_displayed_temp;
    std::queue<MsgType> infrastructureOut_regulator_status;
    std::queue<MsgType> applicationOut_regulator_status;
    std::queue<MsgType> infrastructureOut_interface_failure;
    std::queue<MsgType> applicationOut_interface_failure;

    void sendOut_upper_desired_temp(MsgType msg);
    void sendOut_lower_desired_temp(MsgType msg);
    void sendOut_displayed_temp(MsgType msg);
    void sendOut_regulator_status(MsgType msg);
    void sendOut_interface_failure(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus_subscription_;
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::RegulatorMode>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::Status>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>::SharedPtr thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_regulate_temperature_manage_regulator_interface_mrit_base::*)(MsgType)>> outPortTupleVector;
};
