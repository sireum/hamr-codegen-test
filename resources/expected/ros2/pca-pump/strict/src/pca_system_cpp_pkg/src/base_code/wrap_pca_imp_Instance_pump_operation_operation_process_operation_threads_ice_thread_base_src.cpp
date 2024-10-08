#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Start_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Start",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_command_Start, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_command_Start, applicationIn_command_Start);
                if (applicationIn_command_Start.empty()) return;
                handle_command_Start_base(applicationIn_command_Start.front());
                applicationIn_command_Start.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Suspend_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Suspend",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_command_Suspend, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_command_Suspend, applicationIn_command_Suspend);
                if (applicationIn_command_Suspend.empty()) return;
                handle_command_Suspend_base(applicationIn_command_Suspend.front());
                applicationIn_command_Suspend.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_load_drug_library_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugLibrary>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_load_drug_library",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::DrugLibrary msg) {
            enqueue(infrastructureIn_command_load_drug_library, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_command_load_drug_library, applicationIn_command_load_drug_library);
                if (applicationIn_command_load_drug_library.empty()) return;
                handle_command_load_drug_library_base(applicationIn_command_load_drug_library.front());
                applicationIn_command_load_drug_library.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_set_clinican_requested_bolus_duration_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_set_clinican_requested_bolus_duration",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Minuteimp msg) {
            enqueue(infrastructureIn_command_set_clinican_requested_bolus_duration, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_command_set_clinican_requested_bolus_duration, applicationIn_command_set_clinican_requested_bolus_duration);
                if (applicationIn_command_set_clinican_requested_bolus_duration.empty()) return;
                handle_command_set_clinican_requested_bolus_duration_base(applicationIn_command_set_clinican_requested_bolus_duration.front());
                applicationIn_command_set_clinican_requested_bolus_duration.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_request_bolus_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_request_bolus",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_command_request_bolus, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_command_request_bolus, applicationIn_command_request_bolus);
                if (applicationIn_command_request_bolus.empty()) return;
                handle_command_request_bolus_base(applicationIn_command_request_bolus.front());
                applicationIn_command_request_bolus.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_pause_infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_pause_infusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_command_pause_infusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_command_pause_infusion, applicationIn_command_pause_infusion);
                if (applicationIn_command_pause_infusion.empty()) return;
                handle_command_pause_infusion_base(applicationIn_command_pause_infusion.front());
                applicationIn_command_pause_infusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_resume_infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_resume_infusion",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_command_resume_infusion, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_command_resume_infusion, applicationIn_command_resume_infusion);
                if (applicationIn_command_resume_infusion.empty()) return;
                handle_command_resume_infusion_base(applicationIn_command_resume_infusion.front());
                applicationIn_command_resume_infusion.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_status_AppConnected_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_status_AppConnected",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Boolean msg) {
            enqueue(infrastructureIn_status_AppConnected, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Infusion_Flow_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Patient_Bolus_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Square_Bolus_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Basal_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg) {
            enqueue(infrastructureIn_VTBI, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Door_Open_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Door_Open",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Boolean msg) {
            enqueue(infrastructureIn_Door_Open, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::AlarmSignal>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::AlarmSignal msg) {
            enqueue(infrastructureIn_Alarm_Inactivation, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::AlarmType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::WarningType>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Rx_Okay, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Rx_Okay, applicationIn_Rx_Okay);
                if (applicationIn_Rx_Okay.empty()) return;
                handle_Rx_Okay_base(applicationIn_Rx_Okay.front());
                applicationIn_Rx_Okay.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::Empty msg) {
            enqueue(infrastructureIn_Patient_Request_Too_Soon, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Patient_Request_Too_Soon, applicationIn_Patient_Request_Too_Soon);
                if (applicationIn_Patient_Request_Too_Soon.empty()) return;
                handle_Patient_Request_Too_Soon_base(applicationIn_Patient_Request_Too_Soon.front());
                applicationIn_Patient_Request_Too_Soon.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_HW_Detected_Failure_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_HW_Detected_Failure",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Stop_Pump_Completely_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Stop_Pump_Completely",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_ICE_Stop_Pump_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_status_AppConnected, &applicationIn_status_AppConnected},
        {&infrastructureIn_Infusion_Flow_Rate, &applicationIn_Infusion_Flow_Rate},
        {&infrastructureIn_Patient_Bolus_Rate, &applicationIn_Patient_Bolus_Rate},
        {&infrastructureIn_Square_Bolus_Rate, &applicationIn_Square_Bolus_Rate},
        {&infrastructureIn_Basal_Rate, &applicationIn_Basal_Rate},
        {&infrastructureIn_VTBI, &applicationIn_VTBI},
        {&infrastructureIn_Door_Open, &applicationIn_Door_Open},
        {&infrastructureIn_Alarm_Inactivation, &applicationIn_Alarm_Inactivation}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_parameters_current_flow_rate, &infrastructureOut_parameters_current_flow_rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_current_flow_rate},
        {&applicationOut_parameters_basal_flow_rate, &infrastructureOut_parameters_basal_flow_rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_basal_flow_rate},
        {&applicationOut_parameters_bolus_flow_rate, &infrastructureOut_parameters_bolus_flow_rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_bolus_flow_rate},
        {&applicationOut_parameters_KVO_Flow_Rate, &infrastructureOut_parameters_KVO_Flow_Rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_KVO_Flow_Rate},
        {&applicationOut_parameters_volume_to_be_infused, &infrastructureOut_parameters_volume_to_be_infused, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_volume_to_be_infused},
        {&applicationOut_parameters_clinican_requested_bolus_duration, &infrastructureOut_parameters_clinican_requested_bolus_duration, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_clinican_requested_bolus_duration},
        {&applicationOut_parameters_square_flow_rate, &infrastructureOut_parameters_square_flow_rate, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_square_flow_rate},
        {&applicationOut_status_On, &infrastructureOut_status_On, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_status_On},
        {&applicationOut_status_Okay, &infrastructureOut_status_Okay, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_status_Okay},
        {&applicationOut_status_status, &infrastructureOut_status_status, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_status_status},
        {&applicationOut_ICE_Stop_Pump, &infrastructureOut_ICE_Stop_Pump, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_ICE_Stop_Pump}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

pca_system_cpp_pkg_interfaces::msg::Boolean wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_status_AppConnected() {
    MsgType msg = applicationIn_status_AppConnected.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::Boolean>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Infusion_Flow_Rate() {
    MsgType msg = applicationIn_Infusion_Flow_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Patient_Bolus_Rate() {
    MsgType msg = applicationIn_Patient_Bolus_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Square_Bolus_Rate() {
    MsgType msg = applicationIn_Square_Bolus_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Basal_Rate() {
    MsgType msg = applicationIn_Basal_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_VTBI() {
    MsgType msg = applicationIn_VTBI.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::Boolean wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Door_Open() {
    MsgType msg = applicationIn_Door_Open.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::Boolean>(msg);
}
pca_system_cpp_pkg_interfaces::msg::AlarmSignal wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::get_Alarm_Inactivation() {
    MsgType msg = applicationIn_Alarm_Inactivation.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::AlarmSignal>(msg);
}
void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_Start_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_command_Start(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port command_Start.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_Suspend_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_command_Suspend(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port command_Suspend.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_load_drug_library_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::DrugLibrary>(&msg)) {
        handle_command_load_drug_library(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port command_load_drug_library.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_set_clinican_requested_bolus_duration_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(&msg)) {
        handle_command_set_clinican_requested_bolus_duration(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port command_set_clinican_requested_bolus_duration.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_request_bolus_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_command_request_bolus(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port command_request_bolus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_pause_infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_command_pause_infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port command_pause_infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_command_resume_infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_command_resume_infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port command_resume_infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Alarm_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::AlarmType>(&msg)) {
        handle_Alarm(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Alarm.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Warning_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::WarningType>(&msg)) {
        handle_Warning(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_CP_Bolus_Duration_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(&msg)) {
        handle_CP_Bolus_Duration(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port CP_Bolus_Duration.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Rx_Okay_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Rx_Okay(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Rx_Okay.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Request_Not_Too_Soon_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Patient_Request_Not_Too_Soon(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Request_Not_Too_Soon.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Patient_Request_Too_Soon_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Patient_Request_Too_Soon(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Request_Too_Soon.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_HW_Detected_Failure_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_HW_Detected_Failure(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port HW_Detected_Failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Stop_Pump_Completely_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Stop_Pump_Completely(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Stop_Pump_Completely.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Pump_At_KVO_Rate_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Pump_At_KVO_Rate(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Pump_At_KVO_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_CP_Clinician_Request_Bolus_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_CP_Clinician_Request_Bolus(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port CP_Clinician_Request_Bolus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Halt_Infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Halt_Infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Halt_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Begin_Infusion_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Begin_Infusion(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Begin_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Near_Max_Drug_Per_Hour_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Near_Max_Drug_Per_Hour(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Near_Max_Drug_Per_Hour.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::handle_Over_Max_Drug_Per_Hour_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        handle_Over_Max_Drug_Per_Hour(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Over_Max_Drug_Per_Hour.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_current_flow_rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port parameters_current_flow_rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_basal_flow_rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port parameters_basal_flow_rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_bolus_flow_rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port parameters_bolus_flow_rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_KVO_Flow_Rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port parameters_KVO_Flow_Rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_volume_to_be_infused(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port parameters_volume_to_be_infused.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_clinican_requested_bolus_duration(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Minuteimp>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port parameters_clinican_requested_bolus_duration.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_parameters_square_flow_rate(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port parameters_square_flow_rate.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_status_On(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Boolean>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port status_On.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_status_Okay(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Boolean>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port status_Okay.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_status_status(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::StatusType>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port status_status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOut_ICE_Stop_Pump(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_ICE_Stop_Pump_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port ICE_Stop_Pump.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_parameters_current_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_parameters_current_flow_rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_parameters_basal_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_parameters_basal_flow_rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_parameters_bolus_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_parameters_bolus_flow_rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_parameters_KVO_Flow_Rate(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_parameters_KVO_Flow_Rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_parameters_volume_to_be_infused(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_parameters_volume_to_be_infused, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_parameters_clinican_requested_bolus_duration(pca_system_cpp_pkg_interfaces::msg::Minuteimp msg)
{
    enqueue(applicationOut_parameters_clinican_requested_bolus_duration, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_parameters_square_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_parameters_square_flow_rate, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_status_On(pca_system_cpp_pkg_interfaces::msg::Boolean msg)
{
    enqueue(applicationOut_status_On, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_status_Okay(pca_system_cpp_pkg_interfaces::msg::Boolean msg)
{
    enqueue(applicationOut_status_Okay, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_status_status(pca_system_cpp_pkg_interfaces::msg::StatusType msg)
{
    enqueue(applicationOut_status_status, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::put_ICE_Stop_Pump(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_ICE_Stop_Pump, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
