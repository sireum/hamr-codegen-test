#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Square_Bolus_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Square_Bolus_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Square_Bolus_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Bolus_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Bolus_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Patient_Bolus_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Basal_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Basal_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Basal_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_VTBI_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_VTBI",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg) {
            enqueue(infrastructureIn_VTBI, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Door_Open_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Door_Open",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Boolean msg) {
            enqueue(infrastructureIn_Door_Open, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Alarm_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::AlarmType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Alarm",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::AlarmType msg) {
            enqueue(infrastructureIn_Alarm, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Alarm, applicationIn_Alarm);
                if (applicationIn_Alarm.empty()) return;
                handle_Alarm_base(applicationIn_Alarm.front());
                applicationIn_Alarm.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Warning_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::WarningType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Warning",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::WarningType msg) {
            enqueue(infrastructureIn_Warning, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Warning, applicationIn_Warning);
                if (applicationIn_Warning.empty()) return;
                handle_Warning_base(applicationIn_Warning.front());
                applicationIn_Warning.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Bolus_Duration_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Bolus_Duration",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Minuteimp msg) {
            enqueue(infrastructureIn_CP_Bolus_Duration, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_CP_Bolus_Duration, applicationIn_CP_Bolus_Duration);
                if (applicationIn_CP_Bolus_Duration.empty()) return;
                handle_CP_Bolus_Duration_base(applicationIn_CP_Bolus_Duration.front());
                applicationIn_CP_Bolus_Duration.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Infusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Begin_Infusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Begin_Infusion, applicationIn_Begin_Infusion);
                if (applicationIn_Begin_Infusion.empty()) return;
                handle_Begin_Infusion_base(applicationIn_Begin_Infusion.front());
                applicationIn_Begin_Infusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Priming_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Priming",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Begin_Priming, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Begin_Priming, applicationIn_Begin_Priming);
                if (applicationIn_Begin_Priming.empty()) return;
                handle_Begin_Priming_base(applicationIn_Begin_Priming.front());
                applicationIn_Begin_Priming.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_End_Priming_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_End_Priming",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_End_Priming, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_End_Priming, applicationIn_End_Priming);
                if (applicationIn_End_Priming.empty()) return;
                handle_End_Priming_base(applicationIn_End_Priming.front());
                applicationIn_End_Priming.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Halt_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Halt_Infusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Halt_Infusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Halt_Infusion, applicationIn_Halt_Infusion);
                if (applicationIn_Halt_Infusion.empty()) return;
                handle_Halt_Infusion_base(applicationIn_Halt_Infusion.front());
                applicationIn_Halt_Infusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_HW_Detected_Failure_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_HW_Detected_Failure",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_HW_Detected_Failure, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_HW_Detected_Failure, applicationIn_HW_Detected_Failure);
                if (applicationIn_HW_Detected_Failure.empty()) return;
                handle_HW_Detected_Failure_base(applicationIn_HW_Detected_Failure.front());
                applicationIn_HW_Detected_Failure.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Stop_Pump_Completely_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Stop_Pump_Completely",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Stop_Pump_Completely, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Stop_Pump_Completely, applicationIn_Stop_Pump_Completely);
                if (applicationIn_Stop_Pump_Completely.empty()) return;
                handle_Stop_Pump_Completely_base(applicationIn_Stop_Pump_Completely.front());
                applicationIn_Stop_Pump_Completely.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pump_At_KVO_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pump_At_KVO_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Pump_At_KVO_Rate, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Pump_At_KVO_Rate, applicationIn_Pump_At_KVO_Rate);
                if (applicationIn_Pump_At_KVO_Rate.empty()) return;
                handle_Pump_At_KVO_Rate_base(applicationIn_Pump_At_KVO_Rate.front());
                applicationIn_Pump_At_KVO_Rate.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Request_Not_Too_Soon_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Request_Not_Too_Soon",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Patient_Request_Not_Too_Soon, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Patient_Request_Not_Too_Soon, applicationIn_Patient_Request_Not_Too_Soon);
                if (applicationIn_Patient_Request_Not_Too_Soon.empty()) return;
                handle_Patient_Request_Not_Too_Soon_base(applicationIn_Patient_Request_Not_Too_Soon.front());
                applicationIn_Patient_Request_Not_Too_Soon.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pause_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pause_Infusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Pause_Infusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Pause_Infusion, applicationIn_Pause_Infusion);
                if (applicationIn_Pause_Infusion.empty()) return;
                handle_Pause_Infusion_base(applicationIn_Pause_Infusion.front());
                applicationIn_Pause_Infusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Resume_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Resume_Infusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Resume_Infusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Resume_Infusion, applicationIn_Resume_Infusion);
                if (applicationIn_Resume_Infusion.empty()) return;
                handle_Resume_Infusion_base(applicationIn_Resume_Infusion.front());
                applicationIn_Resume_Infusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Clinician_Request_Bolus_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Clinician_Request_Bolus",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_CP_Clinician_Request_Bolus, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_CP_Clinician_Request_Bolus, applicationIn_CP_Clinician_Request_Bolus);
                if (applicationIn_CP_Clinician_Request_Bolus.empty()) return;
                handle_CP_Clinician_Request_Bolus_base(applicationIn_CP_Clinician_Request_Bolus.front());
                applicationIn_CP_Clinician_Request_Bolus.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Near_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Near_Max_Drug_Per_Hour",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Near_Max_Drug_Per_Hour, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Near_Max_Drug_Per_Hour, applicationIn_Near_Max_Drug_Per_Hour);
                if (applicationIn_Near_Max_Drug_Per_Hour.empty()) return;
                handle_Near_Max_Drug_Per_Hour_base(applicationIn_Near_Max_Drug_Per_Hour.front());
                applicationIn_Near_Max_Drug_Per_Hour.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Over_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Over_Max_Drug_Per_Hour",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Over_Max_Drug_Per_Hour, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Over_Max_Drug_Per_Hour, applicationIn_Over_Max_Drug_Per_Hour);
                if (applicationIn_Over_Max_Drug_Per_Hour.empty()) return;
                handle_Over_Max_Drug_Per_Hour_base(applicationIn_Over_Max_Drug_Per_Hour.front());
                applicationIn_Over_Max_Drug_Per_Hour.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_ICE_Stop_Pump, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_ICE_Stop_Pump, applicationIn_ICE_Stop_Pump);
                if (applicationIn_ICE_Stop_Pump.empty()) return;
                handle_ICE_Stop_Pump_base(applicationIn_ICE_Stop_Pump.front());
                applicationIn_ICE_Stop_Pump.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_4 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::StatusType>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::StatusType>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_Square_Bolus_Rate, &applicationIn_Square_Bolus_Rate},
        {&infrastructureIn_Patient_Bolus_Rate, &applicationIn_Patient_Bolus_Rate},
        {&infrastructureIn_Basal_Rate, &applicationIn_Basal_Rate},
        {&infrastructureIn_VTBI, &applicationIn_VTBI},
        {&infrastructureIn_Door_Open, &applicationIn_Door_Open}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Infusion_Flow_Rate, &infrastructureOut_Infusion_Flow_Rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::sendOut_Infusion_Flow_Rate},
        {&applicationOut_System_Status, &infrastructureOut_System_Status, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::sendOut_System_Status}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Square_Bolus_Rate() {
    MsgType msg = applicationIn_Square_Bolus_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Patient_Bolus_Rate() {
    MsgType msg = applicationIn_Patient_Bolus_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Basal_Rate() {
    MsgType msg = applicationIn_Basal_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_VTBI() {
    MsgType msg = applicationIn_VTBI.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::Boolean wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::get_Door_Open() {
    MsgType msg = applicationIn_Door_Open.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::Boolean>(msg);
}
void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Alarm_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::AlarmType>(&msg)) {
        handle_Alarm(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Alarm.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Warning_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::WarningType>(&msg)) {
        handle_Warning(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_CP_Bolus_Duration_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(&msg)) {
        handle_CP_Bolus_Duration(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port CP_Bolus_Duration.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Begin_Infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Begin_Infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Begin_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Begin_Priming_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Begin_Priming(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Begin_Priming.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_End_Priming_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_End_Priming(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port End_Priming.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Halt_Infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Halt_Infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Halt_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_HW_Detected_Failure_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_HW_Detected_Failure(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port HW_Detected_Failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Stop_Pump_Completely_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Stop_Pump_Completely(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Stop_Pump_Completely.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Pump_At_KVO_Rate_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Pump_At_KVO_Rate(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Pump_At_KVO_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Patient_Request_Not_Too_Soon_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Patient_Request_Not_Too_Soon(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Request_Not_Too_Soon.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Pause_Infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Pause_Infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Pause_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Resume_Infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Resume_Infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Resume_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_CP_Clinician_Request_Bolus_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_CP_Clinician_Request_Bolus(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port CP_Clinician_Request_Bolus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Near_Max_Drug_Per_Hour_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Near_Max_Drug_Per_Hour(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Near_Max_Drug_Per_Hour.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_Over_Max_Drug_Per_Hour_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Over_Max_Drug_Per_Hour(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Over_Max_Drug_Per_Hour.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::handle_ICE_Stop_Pump_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_ICE_Stop_Pump(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Stop_Pump.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::sendOut_Infusion_Flow_Rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_2->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_3->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_4->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Infusion_Flow_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::sendOut_System_Status(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::StatusType>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port System_Status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::put_Infusion_Flow_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg)
{
    enqueue(applicationOut_Infusion_Flow_Rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::put_System_Status(pca_system_cpp_pkg_interfaces::msg::StatusType msg)
{
    enqueue(applicationOut_System_Status, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
