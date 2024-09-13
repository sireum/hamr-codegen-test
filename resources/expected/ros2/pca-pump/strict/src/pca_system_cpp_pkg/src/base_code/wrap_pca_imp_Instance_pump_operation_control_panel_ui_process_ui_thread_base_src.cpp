#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base() : Node("wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Remaining_Battery_Time_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Remaining_Battery_Time",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Remaining_Battery_Time, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Using_Battery_Power_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Using_Battery_Power",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Using_Battery_Power, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Prescription, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Infusion_Flow_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Clinician_Name, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Patient_Name, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Touch_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Touch",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Touch, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Touch, applicationIn_Touch);
                if (applicationIn_Touch.empty()) return;
                handle_Touch_base(applicationIn_Touch.front());
                applicationIn_Touch.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_System_Status, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_System_Status, applicationIn_System_Status);
                if (applicationIn_System_Status.empty()) return;
                handle_System_Status_base(applicationIn_System_Status.front());
                applicationIn_System_Status.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Display_Message, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Display_Message, applicationIn_Display_Message);
                if (applicationIn_Display_Message.empty()) return;
                handle_Display_Message_base(applicationIn_Display_Message.front());
                applicationIn_Display_Message.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Sound_Type, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Sound_Type, applicationIn_Sound_Type);
                if (applicationIn_Sound_Type.empty()) return;
                handle_Sound_Type_base(applicationIn_Sound_Type.front());
                applicationIn_Sound_Type.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Low_Battery_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Low_Battery_Warning",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Hard_Limit_Violated, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Hard_Limit_Violated, applicationIn_Hard_Limit_Violated);
                if (applicationIn_Hard_Limit_Violated.empty()) return;
                handle_Hard_Limit_Violated_base(applicationIn_Hard_Limit_Violated.front());
                applicationIn_Hard_Limit_Violated.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Soft_Limit_Warning, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Soft_Limit_Warning, applicationIn_Soft_Limit_Warning);
                if (applicationIn_Soft_Limit_Warning.empty()) return;
                handle_Soft_Limit_Warning_base(applicationIn_Soft_Limit_Warning.front());
                applicationIn_Soft_Limit_Warning.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_Inactivation_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Bolus_Duration",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_CP_Reset_Alarm_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Stop_Button_Pressed_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Start_Button_Pressed_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Clinician_Request_Bolus",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Pause_Infusion_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pause_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Resume_Infusion_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Resume_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Turn_Off_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_Remaining_Battery_Time, &applicationIn_Remaining_Battery_Time},
        {&infrastructureIn_Using_Battery_Power, &applicationIn_Using_Battery_Power},
        {&infrastructureIn_Prescription, &applicationIn_Prescription},
        {&infrastructureIn_Infusion_Flow_Rate, &applicationIn_Infusion_Flow_Rate},
        {&infrastructureIn_Clinician_Name, &applicationIn_Clinician_Name},
        {&infrastructureIn_Patient_Name, &applicationIn_Patient_Name}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Image, &infrastructureOut_Image, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Image},
        {&applicationOut_AudioSignal, &infrastructureOut_AudioSignal, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_AudioSignal},
        {&applicationOut_Alarm_Inactivation, &infrastructureOut_Alarm_Inactivation, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Alarm_Inactivation},
        {&applicationOut_Bolus_Duration, &infrastructureOut_Bolus_Duration, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Bolus_Duration},
        {&applicationOut_CP_Reset_Alarm, &infrastructureOut_CP_Reset_Alarm, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_CP_Reset_Alarm},
        {&applicationOut_Confirm_Soft_Limit_Exception, &infrastructureOut_Confirm_Soft_Limit_Exception, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Confirm_Soft_Limit_Exception},
        {&applicationOut_Reject_Soft_Limit_Exception, &infrastructureOut_Reject_Soft_Limit_Exception, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Reject_Soft_Limit_Exception},
        {&applicationOut_Stop_Button_Pressed, &infrastructureOut_Stop_Button_Pressed, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Stop_Button_Pressed},
        {&applicationOut_Start_Button_Pressed, &infrastructureOut_Start_Button_Pressed, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Start_Button_Pressed},
        {&applicationOut_Clinician_Request_Bolus, &infrastructureOut_Clinician_Request_Bolus, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Clinician_Request_Bolus},
        {&applicationOut_Pause_Infusion, &infrastructureOut_Pause_Infusion, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Pause_Infusion},
        {&applicationOut_Resume_Infusion, &infrastructureOut_Resume_Infusion, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Resume_Infusion},
        {&applicationOut_Turn_Off, &infrastructureOut_Turn_Off, &wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Turn_Off}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

example_interfaces::msg::Int32 wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Remaining_Battery_Time() {
    MsgType msg = applicationIn_Remaining_Battery_Time.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Using_Battery_Power() {
    MsgType msg = applicationIn_Using_Battery_Power.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Prescription() {
    MsgType msg = applicationIn_Prescription.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Infusion_Flow_Rate() {
    MsgType msg = applicationIn_Infusion_Flow_Rate.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Clinician_Name() {
    MsgType msg = applicationIn_Clinician_Name.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
example_interfaces::msg::Int32 wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::get_Patient_Name() {
    MsgType msg = applicationIn_Patient_Name.front();
    return std::get<example_interfaces::msg::Int32>(msg);
}
void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Touch_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Touch(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Touch.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Alarm_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Alarm(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Alarm.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Warning_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Warning(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_System_Status_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_System_Status(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port System_Status.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Display_Message_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Display_Message(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Display_Message.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Sound_Type_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Sound_Type(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Sound_Type.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Low_Battery_Warning_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Low_Battery_Warning(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Low_Battery_Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Hard_Limit_Violated_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Hard_Limit_Violated(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Hard_Limit_Violated.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Soft_Limit_Warning_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Soft_Limit_Warning(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Soft_Limit_Warning.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Patient_Request_Not_Too_Soon_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Patient_Request_Not_Too_Soon(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Request_Not_Too_Soon.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::handle_Patient_Request_Too_Soon_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Patient_Request_Too_Soon(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Patient_Request_Too_Soon.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Image(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Image.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_AudioSignal(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port AudioSignal.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Alarm_Inactivation(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_Inactivation_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Alarm_Inactivation.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Bolus_Duration(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Bolus_Duration.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_CP_Reset_Alarm(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_CP_Reset_Alarm_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port CP_Reset_Alarm.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Confirm_Soft_Limit_Exception(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Confirm_Soft_Limit_Exception.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Reject_Soft_Limit_Exception(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Reject_Soft_Limit_Exception.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Stop_Button_Pressed(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Stop_Button_Pressed_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Stop_Button_Pressed.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Start_Button_Pressed(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Start_Button_Pressed_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Start_Button_Pressed.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Clinician_Request_Bolus(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Clinician_Request_Bolus.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Pause_Infusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Pause_Infusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Pause_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Resume_Infusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Resume_Infusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Resume_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOut_Turn_Off(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Turn_Off_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Turn_Off.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Image(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Image, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_AudioSignal(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_AudioSignal, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Alarm_Inactivation(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Alarm_Inactivation, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Bolus_Duration(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Bolus_Duration, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_CP_Reset_Alarm(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_CP_Reset_Alarm, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Confirm_Soft_Limit_Exception(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Confirm_Soft_Limit_Exception, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Reject_Soft_Limit_Exception(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Reject_Soft_Limit_Exception, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Stop_Button_Pressed(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Stop_Button_Pressed, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Start_Button_Pressed(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Start_Button_Pressed, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Clinician_Request_Bolus(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Clinician_Request_Bolus, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Pause_Infusion(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Pause_Infusion, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Resume_Infusion(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Resume_Infusion, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::put_Turn_Off(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Turn_Off, msg);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
