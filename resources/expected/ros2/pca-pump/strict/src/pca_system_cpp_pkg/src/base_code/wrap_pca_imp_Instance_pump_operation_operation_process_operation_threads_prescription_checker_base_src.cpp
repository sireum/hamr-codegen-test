#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Prescriptionimp msg) {
            enqueue(infrastructureIn_Prescription, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugRecordimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::DrugRecordimp msg) {
            enqueue(infrastructureIn_The_Drug_Record, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_The_Drug_Record, applicationIn_The_Drug_Record);
                if (applicationIn_The_Drug_Record.empty()) return;
                handle_The_Drug_Record_base(applicationIn_The_Drug_Record.front());
                applicationIn_The_Drug_Record.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Check_Rx, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Check_Rx, applicationIn_Check_Rx);
                if (applicationIn_Check_Rx.empty()) return;
                handle_Check_Rx_base(applicationIn_Check_Rx.front());
                applicationIn_Check_Rx.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Drug_Not_In_Library, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Drug_Not_In_Library, applicationIn_Drug_Not_In_Library);
                if (applicationIn_Drug_Not_In_Library.empty()) return;
                handle_Drug_Not_In_Library_base(applicationIn_Drug_Not_In_Library.front());
                applicationIn_Drug_Not_In_Library.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Confirm_Soft_Limit_Exception, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Confirm_Soft_Limit_Exception, applicationIn_Confirm_Soft_Limit_Exception);
                if (applicationIn_Confirm_Soft_Limit_Exception.empty()) return;
                handle_Confirm_Soft_Limit_Exception_base(applicationIn_Confirm_Soft_Limit_Exception.front());
                applicationIn_Confirm_Soft_Limit_Exception.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Reject_Soft_Limit_Exception, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Reject_Soft_Limit_Exception, applicationIn_Reject_Soft_Limit_Exception);
                if (applicationIn_Reject_Soft_Limit_Exception.empty()) return;
                handle_Reject_Soft_Limit_Exception_base(applicationIn_Reject_Soft_Limit_Exception.front());
                applicationIn_Reject_Soft_Limit_Exception.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_VTBI",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Square_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Basal_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Minimum_Time_Between_Bolus_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Max_Drug_Per_Hour_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Get_Drug_Record_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::DrugCodeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Soft_Limit_Warning_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_Prescription, &applicationIn_Prescription}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_VTBI, &infrastructureOut_VTBI, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_VTBI},
        {&applicationOut_Square_Bolus_Rate, &infrastructureOut_Square_Bolus_Rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Square_Bolus_Rate},
        {&applicationOut_Patient_Bolus_Rate, &infrastructureOut_Patient_Bolus_Rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Patient_Bolus_Rate},
        {&applicationOut_Basal_Rate, &infrastructureOut_Basal_Rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Basal_Rate},
        {&applicationOut_Minimum_Time_Between_Bolus, &infrastructureOut_Minimum_Time_Between_Bolus, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Minimum_Time_Between_Bolus},
        {&applicationOut_Max_Drug_Per_Hour, &infrastructureOut_Max_Drug_Per_Hour, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Max_Drug_Per_Hour},
        {&applicationOut_Get_Drug_Record, &infrastructureOut_Get_Drug_Record, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Get_Drug_Record},
        {&applicationOut_Rx_Okay, &infrastructureOut_Rx_Okay, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Rx_Okay},
        {&applicationOut_Soft_Limit_Warning, &infrastructureOut_Soft_Limit_Warning, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Soft_Limit_Warning},
        {&applicationOut_Hard_Limit_Violated, &infrastructureOut_Hard_Limit_Violated, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Hard_Limit_Violated}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

pca_system_cpp_pkg_interfaces::msg::Prescriptionimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::get_Prescription() {
    MsgType msg = applicationIn_Prescription.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>(msg);
}
void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_The_Drug_Record_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::DrugRecordimp>(&msg)) {
        handle_The_Drug_Record(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port The_Drug_Record.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Check_Rx_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Check_Rx(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Check_Rx.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Drug_Not_In_Library_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Drug_Not_In_Library(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Drug_Not_In_Library.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Confirm_Soft_Limit_Exception_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Confirm_Soft_Limit_Exception(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Confirm_Soft_Limit_Exception.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::handle_Reject_Soft_Limit_Exception_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Reject_Soft_Limit_Exception(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Reject_Soft_Limit_Exception.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_VTBI(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port VTBI.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Square_Bolus_Rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Square_Bolus_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Patient_Bolus_Rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Bolus_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Basal_Rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Basal_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Minimum_Time_Between_Bolus(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Minimum_Time_Between_Bolus_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Minimum_Time_Between_Bolus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Max_Drug_Per_Hour(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Max_Drug_Per_Hour_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Max_Drug_Per_Hour.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Get_Drug_Record(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::DrugCodeimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Get_Drug_Record_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Get_Drug_Record.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Rx_Okay(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Rx_Okay.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Soft_Limit_Warning(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Soft_Limit_Warning_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Soft_Limit_Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOut_Hard_Limit_Violated(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_2->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_3->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Hard_Limit_Violated.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_VTBI(pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg)
{
    enqueue(applicationOut_VTBI, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Square_Bolus_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    enqueue(applicationOut_Square_Bolus_Rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Patient_Bolus_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    enqueue(applicationOut_Patient_Bolus_Rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Basal_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    enqueue(applicationOut_Basal_Rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Minimum_Time_Between_Bolus(pca_system_cpp_pkg_interfaces::msg::Minuteimp msg)
{
    enqueue(applicationOut_Minimum_Time_Between_Bolus, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Max_Drug_Per_Hour(pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg)
{
    enqueue(applicationOut_Max_Drug_Per_Hour, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Get_Drug_Record(pca_system_cpp_pkg_interfaces::msg::DrugCodeimp msg)
{
    enqueue(applicationOut_Get_Drug_Record, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Rx_Okay(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Rx_Okay, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Soft_Limit_Warning(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Soft_Limit_Warning, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::put_Hard_Limit_Violated(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Hard_Limit_Violated, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
