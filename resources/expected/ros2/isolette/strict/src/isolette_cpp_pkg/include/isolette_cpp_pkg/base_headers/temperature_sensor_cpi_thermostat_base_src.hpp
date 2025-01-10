#include "rclcpp/rclcpp.hpp"
#include "isolette_cpp_pkg_interfaces/msg/physical_tempimpl.hpp"
#include "isolette_cpp_pkg_interfaces/msg/temp_wstatusimpl.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class temperature_sensor_cpi_thermostat_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl, isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>;

    temperature_sensor_cpi_thermostat_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg);

    isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl get_air();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureIn_air;
    std::queue<MsgType> applicationIn_air;

    std::queue<MsgType> infrastructureOut_current_tempWstatus;
    std::queue<MsgType> applicationOut_current_tempWstatus;

    void sendOut_current_tempWstatus(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl>::SharedPtr temperature_sensor_cpi_thermostat_air_subscription_;

    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_1;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_2;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_3;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_4;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_5;
    rclcpp::Publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>::SharedPtr temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_6;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (temperature_sensor_cpi_thermostat_base::*)(MsgType)>> outPortTupleVector;
};
