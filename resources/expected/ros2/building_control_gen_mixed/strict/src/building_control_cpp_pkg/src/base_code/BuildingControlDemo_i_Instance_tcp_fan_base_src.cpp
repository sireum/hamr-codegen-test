#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_fan_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

BuildingControlDemo_i_Instance_tcp_fan_base::BuildingControlDemo_i_Instance_tcp_fan_base() : Node("BuildingControlDemo_i_Instance_tcp_fan")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    BuildingControlDemo_i_Instance_tcp_fan_fanCmd_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::FanCmd>(
        "BuildingControlDemo_i_Instance_tcp_fan_fanCmd",
        1,
        [this](building_control_cpp_pkg_interfaces::msg::FanCmd msg) {
            enqueue(infrastructureIn_fanCmd, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_fanCmd, applicationIn_fanCmd);
                if (applicationIn_fanCmd.empty()) return;
                handle_fanCmd_base(applicationIn_fanCmd.front());
                applicationIn_fanCmd.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    BuildingControlDemo_i_Instance_tcp_fan_fanAck_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::FanAck>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_fanAck",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_fanAck, &infrastructureOut_fanAck, &BuildingControlDemo_i_Instance_tcp_fan_base::sendOut_fanAck}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void BuildingControlDemo_i_Instance_tcp_fan_base::handle_fanCmd_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::FanCmd>(&msg)) {
        handle_fanCmd(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port fanCmd.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void BuildingControlDemo_i_Instance_tcp_fan_base::sendOut_fanAck(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::FanAck>(&msg)) {
        BuildingControlDemo_i_Instance_tcp_fan_fanAck_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port fanAck.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void BuildingControlDemo_i_Instance_tcp_fan_base::put_fanAck(building_control_cpp_pkg_interfaces::msg::FanAck msg)
{
    enqueue(applicationOut_fanAck, msg);
}

void BuildingControlDemo_i_Instance_tcp_fan_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void BuildingControlDemo_i_Instance_tcp_fan_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void BuildingControlDemo_i_Instance_tcp_fan_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (BuildingControlDemo_i_Instance_tcp_fan_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (BuildingControlDemo_i_Instance_tcp_fan_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
