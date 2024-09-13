#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_drug_library")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Load_Drug_Library_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Load_Drug_Library",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Load_Drug_Library, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Load_Drug_Library, applicationIn_Load_Drug_Library);
                if (applicationIn_Load_Drug_Library.empty()) return;
                handle_Load_Drug_Library_base(applicationIn_Load_Drug_Library.front());
                applicationIn_Load_Drug_Library.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record_subscription_ = this->create_subscription<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record",
        1,
        [this](example_interfaces::msg::Int32 msg) {
            enqueue(infrastructureIn_Get_Drug_Record, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_Get_Drug_Record, applicationIn_Get_Drug_Record);
                if (applicationIn_Get_Drug_Record.empty()) return;
                handle_Get_Drug_Record_base(applicationIn_Get_Drug_Record.front());
                applicationIn_Get_Drug_Record.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_The_Drug_Record_publisher_ = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_1 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_2 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_3 = this->create_publisher<example_interfaces::msg::Int32>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library",
        1);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_The_Drug_Record, &infrastructureOut_The_Drug_Record, &wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::sendOut_The_Drug_Record},
        {&applicationOut_No_Drug_Found, &infrastructureOut_No_Drug_Found, &wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::sendOut_No_Drug_Found}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::handle_Load_Drug_Library_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Load_Drug_Library(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Load_Drug_Library.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::handle_Get_Drug_Record_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        handle_Get_Drug_Record(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Get_Drug_Record.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::sendOut_The_Drug_Record(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_The_Drug_Record_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port The_Drug_Record.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::sendOut_No_Drug_Found(MsgType msg)
{
    if (auto typedMsg = std::get_if<example_interfaces::msg::Int32>(&msg)) {
        wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_1->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_2->publish(*typedMsg);
        wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_3->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port No_Drug_Found.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::put_The_Drug_Record(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_The_Drug_Record, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::put_No_Drug_Found(example_interfaces::msg::Int32 msg)
{
    enqueue(applicationOut_No_Drug_Found, msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
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

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
