#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Infusion_Flow_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg) {
            enqueue(infrastructureIn_Max_Drug_Per_Hour, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Near_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Over_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_Infusion_Flow_Rate, &applicationIn_Infusion_Flow_Rate},
        {&infrastructureIn_Max_Drug_Per_Hour, &applicationIn_Max_Drug_Per_Hour}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_Infusion_Flow_Rate, &applicationIn_Infusion_Flow_Rate},
        {&infrastructureIn_Max_Drug_Per_Hour, &applicationIn_Max_Drug_Per_Hour}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Near_Max_Drug_Per_Hour, &infrastructureOut_Near_Max_Drug_Per_Hour, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::sendOut_Near_Max_Drug_Per_Hour},
        {&applicationOut_Over_Max_Drug_Per_Hour, &infrastructureOut_Over_Max_Drug_Per_Hour, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::sendOut_Over_Max_Drug_Per_Hour}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::get_Infusion_Flow_Rate() {
    MsgType msg = applicationIn_Infusion_Flow_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::get_Max_Drug_Per_Hour() {
    MsgType msg = applicationIn_Max_Drug_Per_Hour.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(msg);
}
void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::sendOut_Near_Max_Drug_Per_Hour(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Near_Max_Drug_Per_Hour.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::sendOut_Over_Max_Drug_Per_Hour(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_2->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_3->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Over_Max_Drug_Per_Hour.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::put_Near_Max_Drug_Per_Hour(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Near_Max_Drug_Per_Hour, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::put_Over_Max_Drug_Per_Hour(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Over_Max_Drug_Per_Hour, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::receiveInputs() {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
