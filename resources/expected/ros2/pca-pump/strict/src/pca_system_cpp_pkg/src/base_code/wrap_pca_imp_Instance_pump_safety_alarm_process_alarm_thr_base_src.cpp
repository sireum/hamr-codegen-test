#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base() : Node("wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Alarm_Signal_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::AlarmSignal>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Alarm_Signal",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::AlarmSignal msg) {
            enqueue(infrastructureIn_ICE_Alarm_Signal, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_ICE_Alarm_Signal, applicationIn_ICE_Alarm_Signal);
                if (applicationIn_ICE_Alarm_Signal.empty()) return;
                handle_ICE_Alarm_Signal_base(applicationIn_ICE_Alarm_Signal.front());
                applicationIn_ICE_Alarm_Signal.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Reset_Alarm_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Reset_Alarm",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_ICE_Reset_Alarm, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_ICE_Reset_Alarm, applicationIn_ICE_Reset_Alarm);
                if (applicationIn_ICE_Reset_Alarm.empty()) return;
                handle_ICE_Reset_Alarm_base(applicationIn_ICE_Reset_Alarm.front());
                applicationIn_ICE_Reset_Alarm.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Max_Dose_Warning, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Max_Dose_Warning, applicationIn_Max_Dose_Warning);
                if (applicationIn_Max_Dose_Warning.empty()) return;
                handle_Max_Dose_Warning_base(applicationIn_Max_Dose_Warning.front());
                applicationIn_Max_Dose_Warning.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Hard_Limit_Violation, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Hard_Limit_Violation, applicationIn_Hard_Limit_Violation);
                if (applicationIn_Hard_Limit_Violation.empty()) return;
                handle_Hard_Limit_Violation_base(applicationIn_Hard_Limit_Violation.front());
                applicationIn_Hard_Limit_Violation.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Empty_Res_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Empty_Res",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Empty_Res, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Empty_Res, applicationIn_Empty_Res);
                if (applicationIn_Empty_Res.empty()) return;
                handle_Empty_Res_base(applicationIn_Empty_Res.front());
                applicationIn_Empty_Res.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Res_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Res",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Low_Res, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Low_Res, applicationIn_Low_Res);
                if (applicationIn_Low_Res.empty()) return;
                handle_Low_Res_base(applicationIn_Low_Res.front());
                applicationIn_Low_Res.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_Hot_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_Hot",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Pump_Hot, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Pump_Hot, applicationIn_Pump_Hot);
                if (applicationIn_Pump_Hot.empty()) return;
                handle_Pump_Hot_base(applicationIn_Pump_Hot.front());
                applicationIn_Pump_Hot.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Upstream_Occlusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Upstream_Occlusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Upstream_Occlusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Upstream_Occlusion, applicationIn_Upstream_Occlusion);
                if (applicationIn_Upstream_Occlusion.empty()) return;
                handle_Upstream_Occlusion_base(applicationIn_Upstream_Occlusion.front());
                applicationIn_Upstream_Occlusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Downstream_Occlusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Downstream_Occlusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Downstream_Occlusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Downstream_Occlusion, applicationIn_Downstream_Occlusion);
                if (applicationIn_Downstream_Occlusion.empty()) return;
                handle_Downstream_Occlusion_base(applicationIn_Downstream_Occlusion.front());
                applicationIn_Downstream_Occlusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bubble_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bubble",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Bubble, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Bubble, applicationIn_Bubble);
                if (applicationIn_Bubble.empty()) return;
                handle_Bubble_base(applicationIn_Bubble.front());
                applicationIn_Bubble.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Prime_Failure, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Prime_Failure, applicationIn_Prime_Failure);
                if (applicationIn_Prime_Failure.empty()) return;
                handle_Prime_Failure_base(applicationIn_Prime_Failure.front());
                applicationIn_Prime_Failure.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_CP_Reset_Alarm, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_CP_Reset_Alarm, applicationIn_CP_Reset_Alarm);
                if (applicationIn_CP_Reset_Alarm.empty()) return;
                handle_CP_Reset_Alarm_base(applicationIn_CP_Reset_Alarm.front());
                applicationIn_CP_Reset_Alarm.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library",
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

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Defective_Btty_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Defective_Btty",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Defective_Btty, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Defective_Btty, applicationIn_Defective_Btty);
                if (applicationIn_Defective_Btty.empty()) return;
                handle_Defective_Btty_base(applicationIn_Defective_Btty.front());
                applicationIn_Defective_Btty.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Battery_Warning_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Battery_Warning",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Low_Battery_Warning, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Low_Battery_Warning, applicationIn_Low_Battery_Warning);
                if (applicationIn_Low_Battery_Warning.empty()) return;
                handle_Low_Battery_Warning_base(applicationIn_Low_Battery_Warning.front());
                applicationIn_Low_Battery_Warning.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Voltage_OOR_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Voltage_OOR",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Voltage_OOR, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Voltage_OOR, applicationIn_Voltage_OOR);
                if (applicationIn_Voltage_OOR.empty()) return;
                handle_Voltage_OOR_base(applicationIn_Voltage_OOR.front());
                applicationIn_Voltage_OOR.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Basal_Overinfusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Basal_Overinfusion, applicationIn_Basal_Overinfusion);
                if (applicationIn_Basal_Overinfusion.empty()) return;
                handle_Basal_Overinfusion_base(applicationIn_Basal_Overinfusion.front());
                applicationIn_Basal_Overinfusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Bolus_Overinfusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Bolus_Overinfusion, applicationIn_Bolus_Overinfusion);
                if (applicationIn_Bolus_Overinfusion.empty()) return;
                handle_Bolus_Overinfusion_base(applicationIn_Bolus_Overinfusion.front());
                applicationIn_Bolus_Overinfusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Square_Bolus_Overinfusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Square_Bolus_Overinfusion, applicationIn_Square_Bolus_Overinfusion);
                if (applicationIn_Square_Bolus_Overinfusion.empty()) return;
                handle_Square_Bolus_Overinfusion_base(applicationIn_Square_Bolus_Overinfusion.front());
                applicationIn_Square_Bolus_Overinfusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Basal_Underinfusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Basal_Underinfusion, applicationIn_Basal_Underinfusion);
                if (applicationIn_Basal_Underinfusion.empty()) return;
                handle_Basal_Underinfusion_base(applicationIn_Basal_Underinfusion.front());
                applicationIn_Basal_Underinfusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Bolus_Underinfusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Bolus_Underinfusion, applicationIn_Bolus_Underinfusion);
                if (applicationIn_Bolus_Underinfusion.empty()) return;
                handle_Bolus_Underinfusion_base(applicationIn_Bolus_Underinfusion.front());
                applicationIn_Bolus_Underinfusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Square_Bolus_Underinfusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Square_Bolus_Underinfusion, applicationIn_Square_Bolus_Underinfusion);
                if (applicationIn_Square_Bolus_Underinfusion.empty()) return;
                handle_Square_Bolus_Underinfusion_base(applicationIn_Square_Bolus_Underinfusion.front());
                applicationIn_Square_Bolus_Underinfusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Security_Fault, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Security_Fault, applicationIn_Security_Fault);
                if (applicationIn_Security_Fault.empty()) return;
                handle_Security_Fault_base(applicationIn_Security_Fault.front());
                applicationIn_Security_Fault.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::AlarmType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Alarm",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::AlarmType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::AlarmType>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::WarningType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Warning",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::WarningType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::WarningType>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pump_At_KVO_Rate",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Alarm, &infrastructureOut_Alarm, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Alarm},
        {&applicationOut_Warning, &infrastructureOut_Warning, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Warning},
        {&applicationOut_Log_Fault, &infrastructureOut_Log_Fault, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Log_Fault},
        {&applicationOut_ICE_Immediate, &infrastructureOut_ICE_Immediate, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Immediate},
        {&applicationOut_ICE_Prompt, &infrastructureOut_ICE_Prompt, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Prompt},
        {&applicationOut_ICE_Delayed, &infrastructureOut_ICE_Delayed, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Delayed},
        {&applicationOut_ICE_Malfunction, &infrastructureOut_ICE_Malfunction, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Malfunction},
        {&applicationOut_Stop_Pump_Completely, &infrastructureOut_Stop_Pump_Completely, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Stop_Pump_Completely},
        {&applicationOut_Pump_At_KVO_Rate, &infrastructureOut_Pump_At_KVO_Rate, &wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Pump_At_KVO_Rate}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_ICE_Alarm_Signal_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::AlarmSignal>(&msg)) {
        handle_ICE_Alarm_Signal(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Alarm_Signal.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_ICE_Reset_Alarm_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_ICE_Reset_Alarm(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Reset_Alarm.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Max_Dose_Warning_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Max_Dose_Warning(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Max_Dose_Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Hard_Limit_Violation_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Hard_Limit_Violation(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Hard_Limit_Violation.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Empty_Res_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Empty_Res(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Empty_Res.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Low_Res_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Low_Res(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Low_Res.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Pump_Hot_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Pump_Hot(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Pump_Hot.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Upstream_Occlusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Upstream_Occlusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Upstream_Occlusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Downstream_Occlusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Downstream_Occlusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Downstream_Occlusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Bubble_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Bubble(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Bubble.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Prime_Failure_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Prime_Failure(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Prime_Failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_CP_Reset_Alarm_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_CP_Reset_Alarm(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port CP_Reset_Alarm.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Drug_Not_In_Library_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Drug_Not_In_Library(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Drug_Not_In_Library.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Defective_Btty_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Defective_Btty(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Defective_Btty.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Low_Battery_Warning_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Low_Battery_Warning(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Low_Battery_Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Voltage_OOR_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Voltage_OOR(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Voltage_OOR.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Basal_Overinfusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Basal_Overinfusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Basal_Overinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Bolus_Overinfusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Bolus_Overinfusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Bolus_Overinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Square_Bolus_Overinfusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Square_Bolus_Overinfusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Square_Bolus_Overinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Basal_Underinfusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Basal_Underinfusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Basal_Underinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Bolus_Underinfusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Bolus_Underinfusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Bolus_Underinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Square_Bolus_Underinfusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Square_Bolus_Underinfusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Square_Bolus_Underinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::handle_Security_Fault_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Security_Fault(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Security_Fault.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Alarm(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::AlarmType>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_2->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_3->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Alarm.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Warning(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::WarningType>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_2->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_3->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Log_Fault(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::FaultRecordimp>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Log_Fault.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Immediate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Immediate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Prompt(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Prompt.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Delayed(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Delayed.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_ICE_Malfunction(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Malfunction.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Stop_Pump_Completely(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Stop_Pump_Completely.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOut_Pump_At_KVO_Rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Pump_At_KVO_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Alarm(pca_system_cpp_pkg_interfaces::msg::AlarmType msg)
{
    enqueue(applicationOut_Alarm, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Warning(pca_system_cpp_pkg_interfaces::msg::WarningType msg)
{
    enqueue(applicationOut_Warning, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Log_Fault(pca_system_cpp_pkg_interfaces::msg::FaultRecordimp msg)
{
    enqueue(applicationOut_Log_Fault, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_ICE_Immediate(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_ICE_Immediate, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_ICE_Prompt(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_ICE_Prompt, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_ICE_Delayed(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_ICE_Delayed, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_ICE_Malfunction(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_ICE_Malfunction, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Stop_Pump_Completely(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Stop_Pump_Completely, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::put_Pump_At_KVO_Rate(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Pump_At_KVO_Rate, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
