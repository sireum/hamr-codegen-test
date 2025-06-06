#include "isolette_cpp_pkg/base_headers/temperature_sensor_cpi_thermostat_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

temperature_sensor_cpi_thermostat_base::temperature_sensor_cpi_thermostat_base() : Node("temperature_sensor_cpi_thermostat")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    temperature_sensor_cpi_thermostat_air_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl>(
        "temperature_sensor_cpi_thermostat_air",
        1,
        std::bind(&temperature_sensor_cpi_thermostat_base::accept_air, this, std::placeholders::_1), subscription_options_);

    temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_ = this->create_publisher<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(
        "temperature_sensor_cpi_thermostat_current_tempWstatus",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&temperature_sensor_cpi_thermostat_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_air, &applicationIn_air}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_air, &applicationIn_air}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_current_tempWstatus, &infrastructureOut_current_tempWstatus, &temperature_sensor_cpi_thermostat_base::sendOut_current_tempWstatus}
    };

}

void temperature_sensor_cpi_thermostat_base::init_air(isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl val) {
    enqueue(infrastructureIn_air, val);
}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void temperature_sensor_cpi_thermostat_base::accept_air(isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl msg)
{
    enqueue(infrastructureIn_air, msg);
}

isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl temperature_sensor_cpi_thermostat_base::get_air() {
    MsgType msg = applicationIn_air.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::PhysicalTempimpl>(msg);
}

void temperature_sensor_cpi_thermostat_base::sendOut_current_tempWstatus(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::TempWstatusimpl>(&msg)) {
        temperature_sensor_cpi_thermostat_current_tempWstatus_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port current_tempWstatus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void temperature_sensor_cpi_thermostat_base::put_current_tempWstatus(isolette_cpp_pkg_interfaces::msg::TempWstatusimpl msg)
{
    enqueue(applicationOut_current_tempWstatus, msg);
}

void temperature_sensor_cpi_thermostat_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void temperature_sensor_cpi_thermostat_base::receiveInputs() {
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

void temperature_sensor_cpi_thermostat_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void temperature_sensor_cpi_thermostat_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (temperature_sensor_cpi_thermostat_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (temperature_sensor_cpi_thermostat_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
