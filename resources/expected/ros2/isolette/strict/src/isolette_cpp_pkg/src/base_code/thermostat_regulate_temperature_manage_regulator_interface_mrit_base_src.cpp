#include "isolette_cpp_pkg/base_headers/thermostat_regulate_temperature_manage_regulator_interface_mrit_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

thermostat_regulate_temperature_manage_regulator_interface_mrit_base::thermostat_regulate_temperature_manage_regulator_interface_mrit_base() : Node("thermostat_regulate_temperature_manage_regulator_interface_mrit")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_current_tempWstatus",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg) {
            enqueue(infrastructureIn_current_tempWstatus, msg);
        },
        subscription_options_);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_tempWstatus",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg) {
            enqueue(infrastructureIn_lower_desired_tempWstatus, msg);
        },
        subscription_options_);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_tempWstatus",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg) {
            enqueue(infrastructureIn_upper_desired_tempWstatus, msg);
        },
        subscription_options_);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(
        "thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::RegulatorMode msg) {
            enqueue(infrastructureIn_regulator_mode, msg);
        },
        subscription_options_);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp",
        1);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp",
        1);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "operator_interface_oip_oit_display_temperature",
        1);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::Status>(
        "operator_interface_oip_oit_regulator_status",
        1);

    thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_regulate_temperature_manage_regulator_interface_mrit_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_lower_desired_tempWstatus, &applicationIn_lower_desired_tempWstatus},
        {&infrastructureIn_upper_desired_tempWstatus, &applicationIn_upper_desired_tempWstatus},
        {&infrastructureIn_regulator_mode, &applicationIn_regulator_mode}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_lower_desired_tempWstatus, &applicationIn_lower_desired_tempWstatus},
        {&infrastructureIn_upper_desired_tempWstatus, &applicationIn_upper_desired_tempWstatus},
        {&infrastructureIn_regulator_mode, &applicationIn_regulator_mode}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_upper_desired_temp, &infrastructureOut_upper_desired_temp, &thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_upper_desired_temp},
        {&applicationOut_lower_desired_temp, &infrastructureOut_lower_desired_temp, &thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_lower_desired_temp},
        {&applicationOut_displayed_temp, &infrastructureOut_displayed_temp, &thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_displayed_temp},
        {&applicationOut_regulator_status, &infrastructureOut_regulator_status, &thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_regulator_status},
        {&applicationOut_interface_failure, &infrastructureOut_interface_failure, &thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_interface_failure}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_current_tempWstatus() {
    MsgType msg = applicationIn_current_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_lower_desired_tempWstatus() {
    MsgType msg = applicationIn_lower_desired_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_upper_desired_tempWstatus() {
    MsgType msg = applicationIn_upper_desired_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::RegulatorMode thermostat_regulate_temperature_manage_regulator_interface_mrit_base::get_regulator_mode() {
    MsgType msg = applicationIn_regulator_mode.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(msg);
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_upper_desired_temp(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Tempimpl>(&msg)) {
        thermostat_regulate_temperature_manage_regulator_interface_mrit_upper_desired_temp_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port upper_desired_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_lower_desired_temp(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Tempimpl>(&msg)) {
        thermostat_regulate_temperature_manage_regulator_interface_mrit_lower_desired_temp_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port lower_desired_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_displayed_temp(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Tempimpl>(&msg)) {
        thermostat_regulate_temperature_manage_regulator_interface_mrit_displayed_temp_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port displayed_temp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_regulator_status(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Status>(&msg)) {
        thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_status_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port regulator_status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOut_interface_failure(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(&msg)) {
        thermostat_regulate_temperature_manage_regulator_interface_mrit_interface_failure_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port interface_failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_upper_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(applicationOut_upper_desired_temp, msg);
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_lower_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(applicationOut_lower_desired_temp, msg);
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_displayed_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(applicationOut_displayed_temp, msg);
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_regulator_status(isolette_cpp_pkg_interfaces::msg::Status msg)
{
    enqueue(applicationOut_regulator_status, msg);
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::put_interface_failure(isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg)
{
    enqueue(applicationOut_interface_failure, msg);
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::receiveInputs() {
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

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void thermostat_regulate_temperature_manage_regulator_interface_mrit_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_regulate_temperature_manage_regulator_interface_mrit_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_regulate_temperature_manage_regulator_interface_mrit_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
