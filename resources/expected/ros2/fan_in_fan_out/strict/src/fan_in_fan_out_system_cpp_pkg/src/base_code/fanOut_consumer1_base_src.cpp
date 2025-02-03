#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanOut_consumer1_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanOut_consumer1_base::fanOut_consumer1_base() : Node("fanOut_consumer1")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    fanOut_consumer1_myInteger_subscription_ = this->create_subscription<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanOut_consumer1_myInteger",
        1,
        std::bind(&fanOut_consumer1_base::accept_myInteger, this, std::placeholders::_1), subscription_options_);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void fanOut_consumer1_base::accept_myInteger(fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    enqueue(infrastructureIn_myInteger, msg);
    std::thread([this]() {
        std::lock_guard<std::mutex> lock(mutex_);
        receiveInputs(infrastructureIn_myInteger, applicationIn_myInteger);
        if (applicationIn_myInteger.empty()) return;
        handle_myInteger_base(applicationIn_myInteger.front());
        applicationIn_myInteger.pop();
        sendOutputs();
    }).detach();
}

void fanOut_consumer1_base::handle_myInteger_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(&msg)) {
        handle_myInteger(*typedMsg);
    } else {
        PRINT_ERROR("Receiving wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void fanOut_consumer1_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
    if (!infrastructureQueue.empty()) {
        MsgType eventMsg = infrastructureQueue.front();
        infrastructureQueue.pop();
        enqueue(applicationQueue, eventMsg);
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*> port : inDataPortTupleVector) {
        auto infrastructureQueue = std::get<0>(port);
        if (!infrastructureQueue->empty()) {
            auto msg = infrastructureQueue->front();
            enqueue(*std::get<1>(port), msg);
        }
    }
}

void fanOut_consumer1_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void fanOut_consumer1_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanOut_consumer1_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (fanOut_consumer1_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
