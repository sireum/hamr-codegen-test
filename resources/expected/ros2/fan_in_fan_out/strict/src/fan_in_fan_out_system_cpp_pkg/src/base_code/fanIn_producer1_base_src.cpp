#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanIn_producer1_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanIn_producer1_base::fanIn_producer1_base() : Node("fanIn_producer1")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    fanIn_producer1_myInteger_publisher_ = this->create_publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanIn_consumer_myInteger",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&fanIn_producer1_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_myInteger, &infrastructureOut_myInteger, &fanIn_producer1_base::sendOut_myInteger}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void fanIn_producer1_base::sendOut_myInteger(MsgType msg)
{
    if (auto typedMsg = std::get_if<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(&msg)) {
        fanIn_producer1_myInteger_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void fanIn_producer1_base::put_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    enqueue(applicationOut_myInteger, msg);
}

void fanIn_producer1_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void fanIn_producer1_base::receiveInputs() {
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

void fanIn_producer1_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void fanIn_producer1_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanIn_producer1_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanIn_producer1_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
