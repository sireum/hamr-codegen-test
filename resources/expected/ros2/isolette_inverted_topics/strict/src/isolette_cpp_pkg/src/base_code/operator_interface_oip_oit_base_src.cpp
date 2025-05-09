#include "isolette_cpp_pkg/base_headers/operator_interface_oip_oit_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

operator_interface_oip_oit_base::operator_interface_oip_oit_base() : Node("operator_interface_oip_oit")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    operator_interface_oip_oit_regulator_status_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Status>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status",
        1,
        std::bind(&operator_interface_oip_oit_base::accept_regulator_status, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_monitor_status_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Status>(
        "thermostat_monitor_temperature_manage_monitor_interface_mmit_monitor_status",
        1,
        std::bind(&operator_interface_oip_oit_base::accept_monitor_status, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_display_temperature_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp",
        1,
        std::bind(&operator_interface_oip_oit_base::accept_display_temperature, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_alarm_control_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::OnOff>(
        "thermostat_monitor_temperature_manage_alarm_mat_alarm_control",
        1,
        std::bind(&operator_interface_oip_oit_base::accept_alarm_control, this, std::placeholders::_1), subscription_options_);

    operator_interface_oip_oit_lower_desired_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_lower_desired_tempWstatus",
        1);

    operator_interface_oip_oit_upper_desired_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_upper_desired_tempWstatus",
        1);

    operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_lower_alarm_tempWstatus",
        1);

    operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "operator_interface_oip_oit_upper_alarm_tempWstatus",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&operator_interface_oip_oit_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_regulator_status, &applicationIn_regulator_status},
        {&infrastructureIn_monitor_status, &applicationIn_monitor_status},
        {&infrastructureIn_display_temperature, &applicationIn_display_temperature},
        {&infrastructureIn_alarm_control, &applicationIn_alarm_control}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_regulator_status, &applicationIn_regulator_status},
        {&infrastructureIn_monitor_status, &applicationIn_monitor_status},
        {&infrastructureIn_display_temperature, &applicationIn_display_temperature},
        {&infrastructureIn_alarm_control, &applicationIn_alarm_control}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_lower_desired_tempWstatus, &infrastructureOut_lower_desired_tempWstatus, &operator_interface_oip_oit_base::sendOut_lower_desired_tempWstatus},
        {&applicationOut_upper_desired_tempWstatus, &infrastructureOut_upper_desired_tempWstatus, &operator_interface_oip_oit_base::sendOut_upper_desired_tempWstatus},
        {&applicationOut_lower_alarm_tempWstatus, &infrastructureOut_lower_alarm_tempWstatus, &operator_interface_oip_oit_base::sendOut_lower_alarm_tempWstatus},
        {&applicationOut_upper_alarm_tempWstatus, &infrastructureOut_upper_alarm_tempWstatus, &operator_interface_oip_oit_base::sendOut_upper_alarm_tempWstatus}
    };

}

void operator_interface_oip_oit_base::init_regulator_status(isolette_cpp_pkg_interfaces::msg::Status val) {
    enqueue(infrastructureIn_regulator_status, val);
}

void operator_interface_oip_oit_base::init_monitor_status(isolette_cpp_pkg_interfaces::msg::Status val) {
    enqueue(infrastructureIn_monitor_status, val);
}

void operator_interface_oip_oit_base::init_display_temperature(isolette_cpp_pkg_interfaces::msg::Tempimpl val) {
    enqueue(infrastructureIn_display_temperature, val);
}

void operator_interface_oip_oit_base::init_alarm_control(isolette_cpp_pkg_interfaces::msg::OnOff val) {
    enqueue(infrastructureIn_alarm_control, val);
}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void operator_interface_oip_oit_base::accept_regulator_status(isolette_cpp_pkg_interfaces::msg::Status msg)
{
    enqueue(infrastructureIn_regulator_status, msg);
}

void operator_interface_oip_oit_base::accept_monitor_status(isolette_cpp_pkg_interfaces::msg::Status msg)
{
    enqueue(infrastructureIn_monitor_status, msg);
}

void operator_interface_oip_oit_base::accept_display_temperature(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(infrastructureIn_display_temperature, msg);
}

void operator_interface_oip_oit_base::accept_alarm_control(isolette_cpp_pkg_interfaces::msg::OnOff msg)
{
    enqueue(infrastructureIn_alarm_control, msg);
}

isolette_cpp_pkg_interfaces::msg::Status operator_interface_oip_oit_base::get_regulator_status() {
    MsgType msg = applicationIn_regulator_status.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::Status>(msg);
}

isolette_cpp_pkg_interfaces::msg::Status operator_interface_oip_oit_base::get_monitor_status() {
    MsgType msg = applicationIn_monitor_status.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::Status>(msg);
}

isolette_cpp_pkg_interfaces::msg::Tempimpl operator_interface_oip_oit_base::get_display_temperature() {
    MsgType msg = applicationIn_display_temperature.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::Tempimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::OnOff operator_interface_oip_oit_base::get_alarm_control() {
    MsgType msg = applicationIn_alarm_control.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::OnOff>(msg);
}

void operator_interface_oip_oit_base::sendOut_lower_desired_tempWstatus(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(&msg)) {
        operator_interface_oip_oit_lower_desired_tempWstatus_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port lower_desired_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void operator_interface_oip_oit_base::sendOut_upper_desired_tempWstatus(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(&msg)) {
        operator_interface_oip_oit_upper_desired_tempWstatus_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port upper_desired_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void operator_interface_oip_oit_base::sendOut_lower_alarm_tempWstatus(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(&msg)) {
        operator_interface_oip_oit_lower_alarm_tempWstatus_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port lower_alarm_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void operator_interface_oip_oit_base::sendOut_upper_alarm_tempWstatus(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(&msg)) {
        operator_interface_oip_oit_upper_alarm_tempWstatus_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port upper_alarm_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void operator_interface_oip_oit_base::put_lower_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    enqueue(applicationOut_lower_desired_tempWstatus, msg);
}

void operator_interface_oip_oit_base::put_upper_desired_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    enqueue(applicationOut_upper_desired_tempWstatus, msg);
}

void operator_interface_oip_oit_base::put_lower_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    enqueue(applicationOut_lower_alarm_tempWstatus, msg);
}

void operator_interface_oip_oit_base::put_upper_alarm_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    enqueue(applicationOut_upper_alarm_tempWstatus, msg);
}

void operator_interface_oip_oit_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void operator_interface_oip_oit_base::receiveInputs() {
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

void operator_interface_oip_oit_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void operator_interface_oip_oit_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (operator_interface_oip_oit_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (operator_interface_oip_oit_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
