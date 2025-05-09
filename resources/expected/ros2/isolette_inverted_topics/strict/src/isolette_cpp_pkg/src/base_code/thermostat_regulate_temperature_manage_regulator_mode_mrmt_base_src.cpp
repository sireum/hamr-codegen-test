#include "isolette_cpp_pkg/base_headers/thermostat_regulate_temperature_manage_regulator_mode_mrmt_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::thermostat_regulate_temperature_manage_regulator_mode_mrmt_base() : Node("thermostat_regulate_temperature_manage_regulator_mode_mrmt")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "temperature_sensor_cpi_thermostat_current_tempWstatus",
        1,
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::accept_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure",
        1,
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::accept_interface_failure, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure",
        1,
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::accept_internal_failure, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(
        "thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_interface_failure, &applicationIn_interface_failure},
        {&infrastructureIn_internal_failure, &applicationIn_internal_failure}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_interface_failure, &applicationIn_interface_failure},
        {&infrastructureIn_internal_failure, &applicationIn_internal_failure}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_regulator_mode, &infrastructureOut_regulator_mode, &thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::sendOut_regulator_mode}
    };

}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::init_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val) {
    enqueue(infrastructureIn_current_tempWstatus, val);
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::init_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl val) {
    enqueue(infrastructureIn_interface_failure, val);
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::init_internal_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl val) {
    enqueue(infrastructureIn_internal_failure, val);
}


//=================================================
//  C o m m u n i c a t i o n
//=================================================

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::accept_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    enqueue(infrastructureIn_current_tempWstatus, msg);
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::accept_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg)
{
    enqueue(infrastructureIn_interface_failure, msg);
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::accept_internal_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg)
{
    enqueue(infrastructureIn_internal_failure, msg);
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_current_tempWstatus() {
    MsgType msg = applicationIn_current_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::FailureFlagimpl thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_interface_failure() {
    MsgType msg = applicationIn_interface_failure.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::FailureFlagimpl thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_internal_failure() {
    MsgType msg = applicationIn_internal_failure.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(msg);
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::sendOut_regulator_mode(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(&msg)) {
        thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port regulator_mode.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::put_regulator_mode(isolette_cpp_pkg_interfaces::msg::RegulatorMode msg)
{
    enqueue(applicationOut_regulator_mode, msg);
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::receiveInputs() {
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

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
