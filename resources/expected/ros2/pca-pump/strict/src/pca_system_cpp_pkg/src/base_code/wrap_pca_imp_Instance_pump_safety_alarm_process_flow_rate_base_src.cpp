#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base() : Node("wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::StatusType>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::StatusType msg) {
            enqueue(infrastructureIn_System_Status, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Infusion_Flow_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Upstream_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Upstream_Flow_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Upstream_Flow_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Downstream_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Downstream_Flow_Rate",
        1,
        [this](pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg) {
            enqueue(infrastructureIn_Downstream_Flow_Rate, msg);
        },
        subscription_options_);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Overinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Overinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Overinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Underinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Underinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion",
        1);

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Underinfusion_publisher_ = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion",
        1);

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(5),
        std::bind(&wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
        {&infrastructureIn_System_Status, &applicationIn_System_Status},
        {&infrastructureIn_Infusion_Flow_Rate, &applicationIn_Infusion_Flow_Rate},
        {&infrastructureIn_Upstream_Flow_Rate, &applicationIn_Upstream_Flow_Rate},
        {&infrastructureIn_Downstream_Flow_Rate, &applicationIn_Downstream_Flow_Rate}
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
        {&infrastructureIn_System_Status, &applicationIn_System_Status},
        {&infrastructureIn_Infusion_Flow_Rate, &applicationIn_Infusion_Flow_Rate},
        {&infrastructureIn_Upstream_Flow_Rate, &applicationIn_Upstream_Flow_Rate},
        {&infrastructureIn_Downstream_Flow_Rate, &applicationIn_Downstream_Flow_Rate}
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_Basal_Overinfusion, &infrastructureOut_Basal_Overinfusion, &wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Basal_Overinfusion},
        {&applicationOut_Bolus_Overinfusion, &infrastructureOut_Bolus_Overinfusion, &wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Bolus_Overinfusion},
        {&applicationOut_Square_Bolus_Overinfusion, &infrastructureOut_Square_Bolus_Overinfusion, &wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Square_Bolus_Overinfusion},
        {&applicationOut_Basal_Underinfusion, &infrastructureOut_Basal_Underinfusion, &wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Basal_Underinfusion},
        {&applicationOut_Bolus_Underinfusion, &infrastructureOut_Bolus_Underinfusion, &wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Bolus_Underinfusion},
        {&applicationOut_Square_Bolus_Underinfusion, &infrastructureOut_Square_Bolus_Underinfusion, &wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Square_Bolus_Underinfusion}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

pca_system_cpp_pkg_interfaces::msg::StatusType wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_System_Status() {
    MsgType msg = applicationIn_System_Status.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::StatusType>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_Infusion_Flow_Rate() {
    MsgType msg = applicationIn_Infusion_Flow_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_Upstream_Flow_Rate() {
    MsgType msg = applicationIn_Upstream_Flow_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
pca_system_cpp_pkg_interfaces::msg::FlowRateimp wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::get_Downstream_Flow_Rate() {
    MsgType msg = applicationIn_Downstream_Flow_Rate.front();
    return std::get<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(msg);
}
void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Basal_Overinfusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Overinfusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Basal_Overinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Bolus_Overinfusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Overinfusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Bolus_Overinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Square_Bolus_Overinfusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Overinfusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Square_Bolus_Overinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Basal_Underinfusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Underinfusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Basal_Underinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Bolus_Underinfusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Underinfusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Bolus_Underinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOut_Square_Bolus_Underinfusion(MsgType msg)
{
    if (auto typedMsg = std::get_if<pca_system_cpp_pkg_interfaces::msg::Empty>(&msg)) {
        wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Underinfusion_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port Square_Bolus_Underinfusion.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Basal_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Basal_Overinfusion, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Bolus_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Bolus_Overinfusion, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Square_Bolus_Overinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Square_Bolus_Overinfusion, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Basal_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Basal_Underinfusion, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Bolus_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Bolus_Underinfusion, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::put_Square_Bolus_Underinfusion(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    enqueue(applicationOut_Square_Bolus_Underinfusion, msg);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::receiveInputs() {
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

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
