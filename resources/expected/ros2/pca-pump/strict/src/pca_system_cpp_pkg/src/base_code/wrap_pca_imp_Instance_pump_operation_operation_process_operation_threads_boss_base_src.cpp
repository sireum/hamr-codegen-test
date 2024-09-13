#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_done_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_done",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_POST_done, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_POST_done, applicationIn_POST_done);
                if (applicationIn_POST_done.empty()) return;
                handle_POST_done_base(applicationIn_POST_done.front());
                applicationIn_POST_done.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_fail_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_fail",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_POST_fail, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_POST_fail, applicationIn_POST_fail);
                if (applicationIn_POST_fail.empty()) return;
                handle_POST_fail_base(applicationIn_POST_fail.front());
                applicationIn_POST_fail.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Stop_Button_Pressed, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Stop_Button_Pressed, applicationIn_Stop_Button_Pressed);
                if (applicationIn_Stop_Button_Pressed.empty()) return;
                handle_Stop_Button_Pressed_base(applicationIn_Stop_Button_Pressed.front());
                applicationIn_Stop_Button_Pressed.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Start_Button_Pressed, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Start_Button_Pressed, applicationIn_Start_Button_Pressed);
                if (applicationIn_Start_Button_Pressed.empty()) return;
                handle_Start_Button_Pressed_base(applicationIn_Start_Button_Pressed.front());
                applicationIn_Start_Button_Pressed.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Scan_Done_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Scan_Done",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Scan_Done, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Scan_Done, applicationIn_Scan_Done);
                if (applicationIn_Scan_Done.empty()) return;
                handle_Scan_Done_base(applicationIn_Scan_Done.front());
                applicationIn_Scan_Done.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Authentication_fail, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Authentication_fail, applicationIn_Authentication_fail);
                if (applicationIn_Authentication_fail.empty()) return;
                handle_Authentication_fail_base(applicationIn_Authentication_fail.front());
                applicationIn_Authentication_fail.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Authentication_pass, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Authentication_pass, applicationIn_Authentication_pass);
                if (applicationIn_Authentication_pass.empty()) return;
                handle_Authentication_pass_base(applicationIn_Authentication_pass.front());
                applicationIn_Authentication_pass.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated",
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay",
        1,
        [this](example_interfaces::msg::Int32 msg) {
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

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Door_Closed_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Door_Closed",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Door_Closed, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Door_Closed, applicationIn_Door_Closed);
                if (applicationIn_Door_Closed.empty()) return;
                handle_Door_Closed_base(applicationIn_Door_Closed.front());
                applicationIn_Door_Closed.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Turn_Off, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Turn_Off, applicationIn_Turn_Off);
                if (applicationIn_Turn_Off.empty()) return;
                handle_Turn_Off_base(applicationIn_Turn_Off.front());
                applicationIn_Turn_Off.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Display_Message_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Sound_Type_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Log_Event_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Log_Event",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Clinician_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Patient_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Prescription_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Check_Rx_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Priming_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Priming",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_End_Priming_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_End_Priming",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Prime_Failure_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Halt_Infusion",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Display_Message, &infrastructureOut_Display_Message, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Display_Message},
        {&applicationOut_Sound_Type, &infrastructureOut_Sound_Type, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Sound_Type},
        {&applicationOut_Log_Event, &infrastructureOut_Log_Event, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Log_Event},
        {&applicationOut_Do_Scan, &infrastructureOut_Do_Scan, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Do_Scan},
        {&applicationOut_Authenticate_Clinician, &infrastructureOut_Authenticate_Clinician, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Authenticate_Clinician},
        {&applicationOut_Authenticate_Patient, &infrastructureOut_Authenticate_Patient, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Authenticate_Patient},
        {&applicationOut_Authenticate_Prescription, &infrastructureOut_Authenticate_Prescription, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Authenticate_Prescription},
        {&applicationOut_Check_Rx, &infrastructureOut_Check_Rx, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Check_Rx},
        {&applicationOut_Begin_Priming, &infrastructureOut_Begin_Priming, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Begin_Priming},
        {&applicationOut_End_Priming, &infrastructureOut_End_Priming, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_End_Priming},
        {&applicationOut_Prime_Failure, &infrastructureOut_Prime_Failure, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Prime_Failure},
        {&applicationOut_Begin_Infusion, &infrastructureOut_Begin_Infusion, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Begin_Infusion},
        {&applicationOut_Halt_Infusion, &infrastructureOut_Halt_Infusion, &wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Halt_Infusion}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_POST_done_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_POST_done(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port POST_done.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_POST_fail_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_POST_fail(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port POST_fail.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Stop_Button_Pressed_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Stop_Button_Pressed(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Stop_Button_Pressed.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Start_Button_Pressed_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Start_Button_Pressed(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Start_Button_Pressed.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Scan_Done_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Scan_Done(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Scan_Done.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Authentication_fail_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Authentication_fail(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authentication_fail.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Authentication_pass_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Authentication_pass(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authentication_pass.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Drug_Not_In_Library_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Drug_Not_In_Library(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Drug_Not_In_Library.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Hard_Limit_Violated_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Hard_Limit_Violated(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Hard_Limit_Violated.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Reject_Soft_Limit_Exception_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Reject_Soft_Limit_Exception(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Reject_Soft_Limit_Exception.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Confirm_Soft_Limit_Exception_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Confirm_Soft_Limit_Exception(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Confirm_Soft_Limit_Exception.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Rx_Okay_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Rx_Okay(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Rx_Okay.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Door_Closed_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Door_Closed(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Door_Closed.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::handle_Turn_Off_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Turn_Off(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Turn_Off.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Display_Message(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Display_Message_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Display_Message.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Sound_Type(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Sound_Type_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Sound_Type.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Log_Event(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Log_Event_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Log_Event.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Do_Scan(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Do_Scan.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Authenticate_Clinician(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Clinician_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authenticate_Clinician.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Authenticate_Patient(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Patient_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authenticate_Patient.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Authenticate_Prescription(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Prescription_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Authenticate_Prescription.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Check_Rx(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Check_Rx_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Check_Rx.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Begin_Priming(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Priming_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Begin_Priming.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_End_Priming(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_End_Priming_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port End_Priming.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Prime_Failure(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Prime_Failure_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Prime_Failure.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Begin_Infusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Begin_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOut_Halt_Infusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_2->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Halt_Infusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Display_Message(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Display_Message, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Sound_Type(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Sound_Type, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Log_Event(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Log_Event, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Do_Scan(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Do_Scan, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Authenticate_Clinician(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Authenticate_Clinician, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Authenticate_Patient(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Authenticate_Patient, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Authenticate_Prescription(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Authenticate_Prescription, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Check_Rx(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Check_Rx, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Begin_Priming(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Begin_Priming, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_End_Priming(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_End_Priming, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Prime_Failure(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Prime_Failure, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Begin_Infusion(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Begin_Infusion, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::put_Halt_Infusion(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_Halt_Infusion, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
