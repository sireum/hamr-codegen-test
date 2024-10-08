#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_event_logger")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Log_Event_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Log_Event",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Log_Event, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Log_Event, applicationIn_Log_Event);
                if (applicationIn_Log_Event.empty()) return;
                handle_Log_Event_base(applicationIn_Log_Event.front());
                applicationIn_Log_Event.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Get_Event_Log_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Get_Event_Log",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Get_Event_Log, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Get_Event_Log, applicationIn_Get_Event_Log);
                if (applicationIn_Get_Event_Log.empty()) return;
                handle_Get_Event_Log_base(applicationIn_Get_Event_Log.front());
                applicationIn_Get_Event_Log.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_The_Event_Log, &infrastructureOut_The_Event_Log, &wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::sendOut_The_Event_Log}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::handle_Log_Event_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Log_Event(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Log_Event.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::handle_Get_Event_Log_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Get_Event_Log(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Get_Event_Log.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::sendOut_The_Event_Log(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port The_Event_Log.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::put_The_Event_Log(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_The_Event_Log, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
