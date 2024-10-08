#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Minuteimp msg) {
            enqueue(infrastructureIn_Minimum_Time_Between_Bolus, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Button_Request_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Button_Request",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Patient_Button_Request, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Patient_Button_Request, applicationIn_Patient_Button_Request);
                if (applicationIn_Patient_Button_Request.empty()) return;
                handle_Patient_Button_Request_base(applicationIn_Patient_Button_Request.front());
                applicationIn_Patient_Button_Request.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Request_Not_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_Minimum_Time_Between_Bolus, &applicationIn_Minimum_Time_Between_Bolus}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Patient_Request_Not_Too_Soon, &infrastructureOut_Patient_Request_Not_Too_Soon, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::sendOut_Patient_Request_Not_Too_Soon},
        {&applicationOut_Patient_Request_Too_Soon, &infrastructureOut_Patient_Request_Too_Soon, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::sendOut_Patient_Request_Too_Soon}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

pca_system_cpp_pkg_interfaces::msg::Minuteimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::get_Minimum_Time_Between_Bolus() {
    MsgType msg = applicationIn_Minimum_Time_Between_Bolus.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(msg);
}
void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::handle_Patient_Button_Request_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Patient_Button_Request(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Button_Request.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::sendOut_Patient_Request_Not_Too_Soon(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_2->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_3->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Request_Not_Too_Soon.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::sendOut_Patient_Request_Too_Soon(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Request_Too_Soon.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::put_Patient_Request_Not_Too_Soon(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Patient_Request_Not_Too_Soon, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::put_Patient_Request_Too_Soon(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Patient_Request_Too_Soon, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
