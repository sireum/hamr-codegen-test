#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base() : Node("wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Scan_Data_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Scan_Data",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Scan_Data, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Scan_Data, applicationIn_Scan_Data);
                if (applicationIn_Scan_Data.empty()) return;
                handle_Scan_Data_base(applicationIn_Scan_Data.front());
                applicationIn_Scan_Data.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Authenticate_Clinician, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Authenticate_Clinician, applicationIn_Authenticate_Clinician);
                if (applicationIn_Authenticate_Clinician.empty()) return;
                handle_Authenticate_Clinician_base(applicationIn_Authenticate_Clinician.front());
                applicationIn_Authenticate_Clinician.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Authenticate_Patient, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Authenticate_Patient, applicationIn_Authenticate_Patient);
                if (applicationIn_Authenticate_Patient.empty()) return;
                handle_Authenticate_Patient_base(applicationIn_Authenticate_Patient.front());
                applicationIn_Authenticate_Patient.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Authenticate_Prescription, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Authenticate_Prescription, applicationIn_Authenticate_Prescription);
                if (applicationIn_Authenticate_Prescription.empty()) return;
                handle_Authenticate_Prescription_base(applicationIn_Authenticate_Prescription.front());
                applicationIn_Authenticate_Prescription.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Clinician_Name_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::String>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Patient_Name_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::String>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_fail_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_pass_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass",
        1);

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Security_Fault_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Clinician_Name, &infrastructureOut_Clinician_Name, &wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Clinician_Name},
        {&applicationOut_Patient_Name, &infrastructureOut_Patient_Name, &wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Patient_Name},
        {&applicationOut_Prescription, &infrastructureOut_Prescription, &wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Prescription},
        {&applicationOut_Authentication_fail, &infrastructureOut_Authentication_fail, &wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Authentication_fail},
        {&applicationOut_Authentication_pass, &infrastructureOut_Authentication_pass, &wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Authentication_pass},
        {&applicationOut_Security_Fault, &infrastructureOut_Security_Fault, &wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Security_Fault}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Scan_Data_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Scan_Data(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Scan_Data.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Authenticate_Clinician_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Authenticate_Clinician(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authenticate_Clinician.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Authenticate_Patient_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Authenticate_Patient(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authenticate_Patient.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::handle_Authenticate_Prescription_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Authenticate_Prescription(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authenticate_Prescription.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Clinician_Name(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::String>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Clinician_Name_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Clinician_Name.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Patient_Name(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::String>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Patient_Name_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Name.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Prescription(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Prescription.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Authentication_fail(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_fail_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authentication_fail.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Authentication_pass(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_pass_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authentication_pass.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOut_Security_Fault(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Security_Fault_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Security_Fault.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Clinician_Name(pca_system_cpp_pkg_interfaces::msg::String msg)
{
    enqueue(applicationOut_Clinician_Name, msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Patient_Name(pca_system_cpp_pkg_interfaces::msg::String msg)
{
    enqueue(applicationOut_Patient_Name, msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Prescription(pca_system_cpp_pkg_interfaces::msg::Prescriptionimp msg)
{
    enqueue(applicationOut_Prescription, msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Authentication_fail(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Authentication_fail, msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Authentication_pass(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Authentication_pass, msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::put_Security_Fault(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Security_Fault, msg);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
