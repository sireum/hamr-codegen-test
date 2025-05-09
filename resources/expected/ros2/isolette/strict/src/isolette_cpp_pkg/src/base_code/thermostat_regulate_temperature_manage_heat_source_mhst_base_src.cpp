#include "isolette_cpp_pkg/base_headers/thermostat_regulate_temperature_manage_heat_source_mhst_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

thermostat_regulate_temperature_manage_heat_source_mhst_base::thermostat_regulate_temperature_manage_heat_source_mhst_base() : Node("thermostat_regulate_temperature_manage_heat_source_mhst")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "thermostat_regulate_temperature_manage_heat_source_mhst_current_tempWstatus",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_current_tempWstatus, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_regulate_temperature_manage_heat_source_mhst_lower_desired_temp",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_lower_desired_temp, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::Tempimpl>(
        "thermostat_regulate_temperature_manage_heat_source_mhst_upper_desired_temp",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_upper_desired_temp, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(
        "thermostat_regulate_temperature_manage_heat_source_mhst_regulator_mode",
        1,
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_regulator_mode, this, std::placeholders::_1), subscription_options_);

    thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::OnOff>(
        "heat_source_cpi_heat_controller_heat_control",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&thermostat_regulate_temperature_manage_heat_source_mhst_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_lower_desired_temp, &applicationIn_lower_desired_temp},
        {&infrastructureIn_upper_desired_temp, &applicationIn_upper_desired_temp},
        {&infrastructureIn_regulator_mode, &applicationIn_regulator_mode}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_current_tempWstatus, &applicationIn_current_tempWstatus},
        {&infrastructureIn_lower_desired_temp, &applicationIn_lower_desired_temp},
        {&infrastructureIn_upper_desired_temp, &applicationIn_upper_desired_temp},
        {&infrastructureIn_regulator_mode, &applicationIn_regulator_mode}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_heat_control, &infrastructureOut_heat_control, &thermostat_regulate_temperature_manage_heat_source_mhst_base::sendOut_heat_control}
    };

}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::init_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl val) {
    enqueue(infrastructureIn_current_tempWstatus, val);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::init_lower_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl val) {
    enqueue(infrastructureIn_lower_desired_temp, val);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::init_upper_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl val) {
    enqueue(infrastructureIn_upper_desired_temp, val);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::init_regulator_mode(isolette_cpp_pkg_interfaces::msg::RegulatorMode val) {
    enqueue(infrastructureIn_regulator_mode, val);
}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    enqueue(infrastructureIn_current_tempWstatus, msg);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_lower_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(infrastructureIn_lower_desired_temp, msg);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_upper_desired_temp(isolette_cpp_pkg_interfaces::msg::Tempimpl msg)
{
    enqueue(infrastructureIn_upper_desired_temp, msg);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::accept_regulator_mode(isolette_cpp_pkg_interfaces::msg::RegulatorMode msg)
{
    enqueue(infrastructureIn_regulator_mode, msg);
}

isolette_cpp_pkg_interfaces::msg::TempWstatusimpl thermostat_regulate_temperature_manage_heat_source_mhst_base::get_current_tempWstatus() {
    MsgType msg = applicationIn_current_tempWstatus.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::Tempimpl thermostat_regulate_temperature_manage_heat_source_mhst_base::get_lower_desired_temp() {
    MsgType msg = applicationIn_lower_desired_temp.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::Tempimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::Tempimpl thermostat_regulate_temperature_manage_heat_source_mhst_base::get_upper_desired_temp() {
    MsgType msg = applicationIn_upper_desired_temp.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::Tempimpl>(msg);
}

isolette_cpp_pkg_interfaces::msg::RegulatorMode thermostat_regulate_temperature_manage_heat_source_mhst_base::get_regulator_mode() {
    MsgType msg = applicationIn_regulator_mode.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::RegulatorMode>(msg);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::sendOut_heat_control(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::OnOff>(&msg)) {
        thermostat_regulate_temperature_manage_heat_source_mhst_heat_control_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port heat_control.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::put_heat_control(isolette_cpp_pkg_interfaces::msg::OnOff msg)
{
    enqueue(applicationOut_heat_control, msg);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::receiveInputs() {
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

void thermostat_regulate_temperature_manage_heat_source_mhst_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void thermostat_regulate_temperature_manage_heat_source_mhst_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_regulate_temperature_manage_heat_source_mhst_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (thermostat_regulate_temperature_manage_heat_source_mhst_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
