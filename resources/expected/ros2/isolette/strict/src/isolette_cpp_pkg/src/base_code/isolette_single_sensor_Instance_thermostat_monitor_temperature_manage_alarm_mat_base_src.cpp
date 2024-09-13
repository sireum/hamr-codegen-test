#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base() : Node("isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_current_tempWstatus",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_current_tempWstatus, msg);
        },
        subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_lower_alarm_temp, msg);
        },
        subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_upper_alarm_temp, msg);
        },
        subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_monitor_mode_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_monitor_mode",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_monitor_mode, msg);
        },
        subscription_options_);

    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "isolette_single_sensor_Instance_operator_interface_oip_oit_alarm_control",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_lower_alarm_temp, &applicationIn_lower_alarm_temp},
        {&infrastructureIn_upper_alarm_temp, &applicationIn_upper_alarm_temp},
        {&infrastructureIn_monitor_mode, &applicationIn_monitor_mode}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_lower_alarm_temp, &applicationIn_lower_alarm_temp},
        {&infrastructureIn_upper_alarm_temp, &applicationIn_upper_alarm_temp},
        {&infrastructureIn_monitor_mode, &applicationIn_monitor_mode}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_alarm_control, &infrastructureOut_alarm_control, &isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::sendOut_alarm_control}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

example_interfaces::msg::Int32 isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_current_tempWstatus() {
    MsgType msg = applicationIn_current_tempWstatus.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_lower_alarm_temp() {
    MsgType msg = applicationIn_lower_alarm_temp.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_upper_alarm_temp() {
    MsgType msg = applicationIn_upper_alarm_temp.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::get_monitor_mode() {
    MsgType msg = applicationIn_monitor_mode.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::sendOut_alarm_control(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_alarm_control_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port alarm_control.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::put_alarm_control(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_alarm_control, msg);
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::receiveInputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*> port : inDataPortTupleVector) {
        auto infrastructureQueue = std::get<0>(port);
        if (!infrastructureQueue->empty()) {
            auto msg = infrastructureQueue->front();
            enqueue(*std::get<1>(port), msg);
        }
    }
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*> port : inEventPortTupleVector) {
        auto infrastructureQueue = std::get<0>(port);
        if (!infrastructureQueue->empty()) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
