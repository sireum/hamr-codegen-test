#include "building_control_cpp_pkg/base_headers/tcp_fan_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

tcp_fan_base::tcp_fan_base() : Node("tcp_fan")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    tcp_fan_fanCmd_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::FanCmd>(
        "tcp_tempControl_fanCmd",
        1,
        std::bind(&tcp_fan_base::accept_fanCmd, this, std::placeholders::_1), subscription_options_);

    tcp_fan_fanAck_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::FanAck>(
        "tcp_fan_fanAck",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_fanAck, &infrastructureOut_fanAck, &tcp_fan_base::sendOut_fanAck}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void tcp_fan_base::accept_fanCmd(building_control_cpp_pkg_interfaces::msg::FanCmd msg)
{
    enqueue(infrastructureIn_fanCmd, msg);
    std::thread([this]() {
        std::lock_guard<std::mutex> lock(mutex_);
        receiveInputs(infrastructureIn_fanCmd, applicationIn_fanCmd);
        if (applicationIn_fanCmd.empty()) return;
        handle_fanCmd_base(applicationIn_fanCmd.front());
        applicationIn_fanCmd.pop();
        sendOutputs();
    }).detach();
}

void tcp_fan_base::handle_fanCmd_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::FanCmd>(&msg)) {
        handle_fanCmd(*typedMsg);
    } else {
        PRINT_ERROR("Receiving wrong type of variable on port fanCmd.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void tcp_fan_base::sendOut_fanAck(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::FanAck>(&msg)) {
        tcp_fan_fanAck_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port fanAck.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void tcp_fan_base::put_fanAck(building_control_cpp_pkg_interfaces::msg::FanAck msg)
{
    enqueue(applicationOut_fanAck, msg);
}

void tcp_fan_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void tcp_fan_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void tcp_fan_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (tcp_fan_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (tcp_fan_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
