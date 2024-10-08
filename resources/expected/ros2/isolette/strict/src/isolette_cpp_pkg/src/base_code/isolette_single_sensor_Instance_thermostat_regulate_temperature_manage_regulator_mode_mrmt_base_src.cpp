#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base() : Node("isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_current_tempWstatus",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg) {
            enqueue(infrastructureIn_current_tempWstatus, msg);
        },
        subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_interface_failure",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg) {
            enqueue(infrastructureIn_interface_failure, msg);
        },
        subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_internal_failure",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::FailureFlagimpl msg) {
            enqueue(infrastructureIn_internal_failure, msg);
        },
        subscription_options_);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_1 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface_mrit_regulator_mode",
        1);

    isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_2 = this->create_publisher<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(
        "isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::timeTriggeredCaller, this), cb_group_);

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
        {&applicationOut_regulator_mode, &infrastructureOut_regulator_mode, &isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::sendOut_regulator_mode}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_current_tempWstatus() {
    MsgType msg = applicationIn_current_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}
isolette_cpp_pkg_interfaces::msg::FailureFlagimpl isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_interface_failure() {
    MsgType msg = applicationIn_interface_failure.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(msg);
}
isolette_cpp_pkg_interfaces::msg::FailureFlagimpl isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::get_internal_failure() {
    MsgType msg = applicationIn_internal_failure.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::FailureFlagimpl>(msg);
}
void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::sendOut_regulator_mode(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(&msg)) {
        isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_1->publish(*typedMsg);
        isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_regulator_mode_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port regulator_mode.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::put_regulator_mode(isolette_cpp_pkg_interfaces::msg::RegulatorMode msg)
{
    enqueue(applicationOut_regulator_mode, msg);
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::receiveInputs() {
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

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode_mrmt_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
