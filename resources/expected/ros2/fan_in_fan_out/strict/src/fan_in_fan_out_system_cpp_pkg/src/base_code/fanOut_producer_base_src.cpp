#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanOut_producer_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanOut_producer_base::fanOut_producer_base() : Node("fanOut_producer")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    fanOut_producer_myInteger_publisher_1 = this->create_publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanOut_consumer1_myInteger",
        1);

    fanOut_producer_myInteger_publisher_2 = this->create_publisher<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanOut_consumer2_myInteger",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&fanOut_producer_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_myInteger, &infrastructureOut_myInteger, &fanOut_producer_base::sendOut_myInteger}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void fanOut_producer_base::sendOut_myInteger(MsgType msg)
{
    if (auto typedMsg = std::get_if<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(&msg)) {
        fanOut_producer_myInteger_publisher_1->publish(*typedMsg);
        fanOut_producer_myInteger_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void fanOut_producer_base::put_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    enqueue(applicationOut_myInteger, msg);
}

void fanOut_producer_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void fanOut_producer_base::receiveInputs() {
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

void fanOut_producer_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void fanOut_producer_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanOut_producer_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanOut_producer_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
