#include "isolette_cpp_pkg/base_headers/thermostat_monitor_temperature_manage_monitor_interface_mmit_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

thermostat_monitor_temperature_manage_monitor_interface_mmit_base::thermostat_monitor_temperature_manage_monitor_interface_mmit_base() : Node("thermostat_monitor_temperature_manage_monitor_interface_mmit")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_tempWstatus",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg) {
            enqueue(infrastructureIn_upper_alarm_tempWstatus, msg);
        },
        subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_tempWstatus",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg) {
            enqueue(infrastructureIn_lower_alarm_tempWstatus, msg);
        },
        subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_current_tempWstatus",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg) {
            enqueue(infrastructureIn_current_tempWstatus, msg);
        },
        subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::MonitorMode>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_mode",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::MonitorMode msg) {
            enqueue(infrastructureIn_monitor_mode, msg);
        },
        subscription_options_);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_monitor_temperature_manage_alarm_mat_upper_alarm_temp",
        1);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_monitor_temperature_manage_alarm_mat_lower_alarm_temp",
        1);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Status>(
        "operator_interface_oip_oit_monitor_status",
        1);

    thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_monitor_temperature_manage_monitor_mode_mmmt_interface_failure",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_monitor_temperature_manage_monitor_interface_mmit_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_upper_alarm_tempWstatus, &applicationIn_upper_alarm_tempWstatus},
        {&infrastructureIn_lower_alarm_tempWstatus, &applicationIn_lower_alarm_tempWstatus},
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_monitor_mode, &applicationIn_monitor_mode}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_upper_alarm_tempWstatus, &applicationIn_upper_alarm_tempWstatus},
        {&infrastructureIn_lower_alarm_tempWstatus, &applicationIn_lower_alarm_tempWstatus},
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_monitor_mode, &applicationIn_monitor_mode}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_upper_alarm_temp, &infrastructureOut_upper_alarm_temp, &thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_upper_alarm_temp},
        {&applicationOut_lower_alarm_temp, &infrastructureOut_lower_alarm_temp, &thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_lower_alarm_temp},
        {&applicationOut_monitor_status, &infrastructureOut_monitor_status, &thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_monitor_status},
        {&applicationOut_interface_failure, &infrastructureOut_interface_failure, &thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_interface_failure}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_upper_alarm_tempWstatus() {
    MsgType msg = applicationIn_upper_alarm_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_lower_alarm_tempWstatus() {
    MsgType msg = applicationIn_lower_alarm_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_current_tempWstatus() {
    MsgType msg = applicationIn_current_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::MonitorMode thermostat_monitor_temperature_manage_monitor_interface_mmit_base::get_monitor_mode() {
    MsgType msg = applicationIn_monitor_mode.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::MonitorMode>(msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_upper_alarm_temp(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Tempimpl>(&msg)) {
        thermostat_monitor_temperature_manage_monitor_interface_mmit_upper_alarm_temp_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port upper_alarm_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_lower_alarm_temp(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Tempimpl>(&msg)) {
        thermostat_monitor_temperature_manage_monitor_interface_mmit_lower_alarm_temp_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port lower_alarm_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_monitor_status(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Status>(&msg)) {
        thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port monitor_status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOut_interface_failure(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(&msg)) {
        thermostat_monitor_temperature_manage_monitor_interface_mmit_interface_failure_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port interface_failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_upper_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(applicationOut_upper_alarm_temp, msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_lower_alarm_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(applicationOut_lower_alarm_temp, msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_monitor_status(isolette_cpp_pkg_interfaces::msg::Status msg)
{
    enqueue(applicationOut_monitor_status, msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg)
{
    enqueue(applicationOut_interface_failure, msg);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::receiveInputs() {
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

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void thermostat_monitor_temperature_manage_monitor_interface_mmit_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_monitor_temperature_manage_monitor_interface_mmit_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_monitor_temperature_manage_monitor_interface_mmit_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
