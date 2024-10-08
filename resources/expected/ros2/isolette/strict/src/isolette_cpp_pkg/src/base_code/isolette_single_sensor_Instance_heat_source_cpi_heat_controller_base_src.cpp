#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base() : Node("isolette_single_sensor_Instance_heat_source_cpi_heat_controller")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    isolette_single_sensor_Instance_heat_source_cpi_heat_controller_heat_control_subscription_ = this->create_subscription<isolette_cpp_pkg_interfaces::msg::OnOff>(
        "isolette_single_sensor_Instance_heat_source_cpi_heat_controller_heat_control",
        1,
        [this](isolette_cpp_pkg_interfaces::msg::OnOff msg) {
            enqueue(infrastructureIn_heat_control, msg);
        },
        subscription_options_);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_heat_control, &applicationIn_heat_control}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_heat_control, &applicationIn_heat_control}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_heat_out, &infrastructureOut_heat_out, &isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::sendOut_heat_out}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

isolette_cpp_pkg_interfaces::msg::OnOff isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::get_heat_control() {
    MsgType msg = applicationIn_heat_control.front();
    return std::get<isolette_cpp_pkg_interfaces::msg::OnOff>(msg);
}
void isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::sendOut_heat_out(MsgType msg)
{
    if (auto typedMsg = std::get_if<isolette_cpp_pkg_interfaces::msg::Heat>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port heat_out.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::put_heat_out(isolette_cpp_pkg_interfaces::msg::Heat msg)
{
    enqueue(applicationOut_heat_out, msg);
}

void isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::receiveInputs() {
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

void isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (isolette_single_sensor_Instance_heat_source_cpi_heat_controller_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
