#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_tempSensor_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

BuildingControlDemo_i_Instance_tcp_tempSensor_base::BuildingControlDemo_i_Instance_tcp_tempSensor_base() : Node("BuildingControlDemo_i_Instance_tcp_tempSensor")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    BuildingControlDemo_i_Instance_tcp_tempSensor_currentTemp_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_currentTemp",
        1);

    BuildingControlDemo_i_Instance_tcp_tempSensor_tempChanged_publisher_ = this->create_publisher<building_control_cpp_pkg_interfaces::msg::Empty>(
        "BuildingControlDemo_i_Instance_tcp_tempControl_tempChanged",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&BuildingControlDemo_i_Instance_tcp_tempSensor_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_currentTemp, &infrastructureOut_currentTemp, &BuildingControlDemo_i_Instance_tcp_tempSensor_base::sendOut_currentTemp},
        {&applicationOut_tempChanged, &infrastructureOut_tempChanged, &BuildingControlDemo_i_Instance_tcp_tempSensor_base::sendOut_tempChanged}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::sendOut_currentTemp(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>(&msg)) {
        BuildingControlDemo_i_Instance_tcp_tempSensor_currentTemp_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port currentTemp.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::sendOut_tempChanged(MsgType msg)
{
    if (auto typedMsg = std::get_if<building_control_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        BuildingControlDemo_i_Instance_tcp_tempSensor_tempChanged_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port tempChanged.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::put_currentTemp(building_control_cpp_pkg_interfaces::msg::Temperatureimpl msg)
{
    enqueue(applicationOut_currentTemp, msg);
}

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::put_tempChanged(building_control_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_tempChanged, msg);
}

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::receiveInputs() {
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

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void BuildingControlDemo_i_Instance_tcp_tempSensor_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (BuildingControlDemo_i_Instance_tcp_tempSensor_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (BuildingControlDemo_i_Instance_tcp_tempSensor_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
