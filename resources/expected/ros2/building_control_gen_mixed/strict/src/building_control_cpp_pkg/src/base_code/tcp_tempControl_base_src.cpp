#include "building_control_cpp_pkg/base_headers/tcp_tempControl_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

tcp_tempControl_base::tcp_tempControl_base() : Node("tcp_tempControl")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    tcp_tempControl_currentTemp_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(
        "tcp_tempControl_currentTemp",
        1,
        [this](building_control_cpp_pkg_interfaces::msg::Temperatureimpl msg) {
            enqueue(infrastructureIn_currentTemp, msg);
        },
        subscription_options_);

    tcp_tempControl_fanAck_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::FanAck>(
        "tcp_tempControl_fanAck",
        1,
        [this](building_control_cpp_pkg_interfaces::msg::FanAck msg) {
            enqueue(infrastructureIn_fanAck, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_fanAck, applicationIn_fanAck);
                if (applicationIn_fanAck.empty()) return;
                handle_fanAck_base(applicationIn_fanAck.front());
                applicationIn_fanAck.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    tcp_tempControl_setPoint_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::SetPointimpl>(
        "tcp_tempControl_setPoint",
        1,
        [this](building_control_cpp_pkg_interfaces::msg::SetPointimpl msg) {
            enqueue(infrastructureIn_setPoint, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_setPoint, applicationIn_setPoint);
                if (applicationIn_setPoint.empty()) return;
                handle_setPoint_base(applicationIn_setPoint.front());
                applicationIn_setPoint.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    tcp_tempControl_tempChanged_subscription_ = this->create_subscription<building_control_cpp_pkg_interfaces::msg::Empty>(
        "tcp_tempControl_tempChanged",
        1,
        [this](building_control_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_tempChanged, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_tempChanged, applicationIn_tempChanged);
                if (applicationIn_tempChanged.empty()) return;
                handle_tempChanged_base(applicationIn_tempChanged.front());
                applicationIn_tempChanged.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    tcp_tempControl_fanCmd_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::FanCmd>(
        "tcp_fan_fanCmd",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_currentTemp, &applicationIn_currentTemp}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_fanCmd, &infrastructureOut_fanCmd, &tcp_tempControl_base::sendOut_fanCmd}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

building_control_cpp_pkg_interfaces::msg::Temperatureimpl tcp_tempControl_base::get_currentTemp() {
    MsgType msg = applicationIn_currentTemp.front();
    return std::get<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(msg);
}

void tcp_tempControl_base::handle_fanAck_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::FanAck>(&msg)) {
        handle_fanAck(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port fanAck.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void tcp_tempControl_base::handle_setPoint_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::SetPointimpl>(&msg)) {
        handle_setPoint(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port setPoint.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void tcp_tempControl_base::handle_tempChanged_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_tempChanged(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port tempChanged.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void tcp_tempControl_base::sendOut_fanCmd(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::FanCmd>(&msg)) {
        tcp_tempControl_fanCmd_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port fanCmd.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void tcp_tempControl_base::put_fanCmd(building_control_cpp_pkg_interfaces::msg::FanCmd msg)
{
    enqueue(applicationOut_fanCmd, msg);
}

void tcp_tempControl_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void tcp_tempControl_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void tcp_tempControl_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (tcp_tempControl_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (tcp_tempControl_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
