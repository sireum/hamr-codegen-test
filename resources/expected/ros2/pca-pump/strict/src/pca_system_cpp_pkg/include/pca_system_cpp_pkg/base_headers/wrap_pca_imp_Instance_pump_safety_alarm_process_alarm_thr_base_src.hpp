#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Alarm(example_interfaces::msg::Int32 msg);
    void put_Warning(example_interfaces::msg::Int32 msg);
    void put_Log_Fault(example_interfaces::msg::Int32 msg);
    void put_ICE_Immediate(example_interfaces::msg::Int32 msg);
    void put_ICE_Prompt(example_interfaces::msg::Int32 msg);
    void put_ICE_Delayed(example_interfaces::msg::Int32 msg);
    void put_ICE_Malfunction(example_interfaces::msg::Int32 msg);
    void put_Stop_Pump_Completely(example_interfaces::msg::Int32 msg);
    void put_Pump_At_KVO_Rate(example_interfaces::msg::Int32 msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_ICE_Alarm_Signal(const example_interfaces::msg::Int32 msg) = 0;
    void handle_ICE_Alarm_Signal_base(MsgType msg);
    virtual void handle_ICE_Reset_Alarm(const example_interfaces::msg::Int32 msg) = 0;
    void handle_ICE_Reset_Alarm_base(MsgType msg);
    virtual void handle_Max_Dose_Warning(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Max_Dose_Warning_base(MsgType msg);
    virtual void handle_Hard_Limit_Violation(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Hard_Limit_Violation_base(MsgType msg);
    virtual void handle_Empty_Res(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Empty_Res_base(MsgType msg);
    virtual void handle_Low_Res(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Low_Res_base(MsgType msg);
    virtual void handle_Pump_Hot(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Pump_Hot_base(MsgType msg);
    virtual void handle_Upstream_Occlusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Upstream_Occlusion_base(MsgType msg);
    virtual void handle_Downstream_Occlusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Downstream_Occlusion_base(MsgType msg);
    virtual void handle_Bubble(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Bubble_base(MsgType msg);
    virtual void handle_Prime_Failure(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Prime_Failure_base(MsgType msg);
    virtual void handle_CP_Reset_Alarm(const example_interfaces::msg::Int32 msg) = 0;
    void handle_CP_Reset_Alarm_base(MsgType msg);
    virtual void handle_Drug_Not_In_Library(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Drug_Not_In_Library_base(MsgType msg);
    virtual void handle_Defective_Btty(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Defective_Btty_base(MsgType msg);
    virtual void handle_Low_Battery_Warning(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Low_Battery_Warning_base(MsgType msg);
    virtual void handle_Voltage_OOR(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Voltage_OOR_base(MsgType msg);
    virtual void handle_Basal_Overinfusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Basal_Overinfusion_base(MsgType msg);
    virtual void handle_Bolus_Overinfusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Bolus_Overinfusion_base(MsgType msg);
    virtual void handle_Square_Bolus_Overinfusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Square_Bolus_Overinfusion_base(MsgType msg);
    virtual void handle_Basal_Underinfusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Basal_Underinfusion_base(MsgType msg);
    virtual void handle_Bolus_Underinfusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Bolus_Underinfusion_base(MsgType msg);
    virtual void handle_Square_Bolus_Underinfusion(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Square_Bolus_Underinfusion_base(MsgType msg);
    virtual void handle_Security_Fault(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Security_Fault_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_ICE_Alarm_Signal;
    std::queue<MsgType> applicationIn_ICE_Alarm_Signal;
    std::queue<MsgType> infrastructureIn_ICE_Reset_Alarm;
    std::queue<MsgType> applicationIn_ICE_Reset_Alarm;
    std::queue<MsgType> infrastructureIn_Max_Dose_Warning;
    std::queue<MsgType> applicationIn_Max_Dose_Warning;
    std::queue<MsgType> infrastructureIn_Hard_Limit_Violation;
    std::queue<MsgType> applicationIn_Hard_Limit_Violation;
    std::queue<MsgType> infrastructureIn_Empty_Res;
    std::queue<MsgType> applicationIn_Empty_Res;
    std::queue<MsgType> infrastructureIn_Low_Res;
    std::queue<MsgType> applicationIn_Low_Res;
    std::queue<MsgType> infrastructureIn_Pump_Hot;
    std::queue<MsgType> applicationIn_Pump_Hot;
    std::queue<MsgType> infrastructureIn_Upstream_Occlusion;
    std::queue<MsgType> applicationIn_Upstream_Occlusion;
    std::queue<MsgType> infrastructureIn_Downstream_Occlusion;
    std::queue<MsgType> applicationIn_Downstream_Occlusion;
    std::queue<MsgType> infrastructureIn_Bubble;
    std::queue<MsgType> applicationIn_Bubble;
    std::queue<MsgType> infrastructureIn_Prime_Failure;
    std::queue<MsgType> applicationIn_Prime_Failure;
    std::queue<MsgType> infrastructureIn_CP_Reset_Alarm;
    std::queue<MsgType> applicationIn_CP_Reset_Alarm;
    std::queue<MsgType> infrastructureIn_Drug_Not_In_Library;
    std::queue<MsgType> applicationIn_Drug_Not_In_Library;
    std::queue<MsgType> infrastructureIn_Defective_Btty;
    std::queue<MsgType> applicationIn_Defective_Btty;
    std::queue<MsgType> infrastructureIn_Low_Battery_Warning;
    std::queue<MsgType> applicationIn_Low_Battery_Warning;
    std::queue<MsgType> infrastructureIn_Voltage_OOR;
    std::queue<MsgType> applicationIn_Voltage_OOR;
    std::queue<MsgType> infrastructureIn_Basal_Overinfusion;
    std::queue<MsgType> applicationIn_Basal_Overinfusion;
    std::queue<MsgType> infrastructureIn_Bolus_Overinfusion;
    std::queue<MsgType> applicationIn_Bolus_Overinfusion;
    std::queue<MsgType> infrastructureIn_Square_Bolus_Overinfusion;
    std::queue<MsgType> applicationIn_Square_Bolus_Overinfusion;
    std::queue<MsgType> infrastructureIn_Basal_Underinfusion;
    std::queue<MsgType> applicationIn_Basal_Underinfusion;
    std::queue<MsgType> infrastructureIn_Bolus_Underinfusion;
    std::queue<MsgType> applicationIn_Bolus_Underinfusion;
    std::queue<MsgType> infrastructureIn_Square_Bolus_Underinfusion;
    std::queue<MsgType> applicationIn_Square_Bolus_Underinfusion;
    std::queue<MsgType> infrastructureIn_Security_Fault;
    std::queue<MsgType> applicationIn_Security_Fault;

    std::queue<MsgType> infrastructureOut_Alarm;
    std::queue<MsgType> applicationOut_Alarm;
    std::queue<MsgType> infrastructureOut_Warning;
    std::queue<MsgType> applicationOut_Warning;
    std::queue<MsgType> infrastructureOut_Log_Fault;
    std::queue<MsgType> applicationOut_Log_Fault;
    std::queue<MsgType> infrastructureOut_ICE_Immediate;
    std::queue<MsgType> applicationOut_ICE_Immediate;
    std::queue<MsgType> infrastructureOut_ICE_Prompt;
    std::queue<MsgType> applicationOut_ICE_Prompt;
    std::queue<MsgType> infrastructureOut_ICE_Delayed;
    std::queue<MsgType> applicationOut_ICE_Delayed;
    std::queue<MsgType> infrastructureOut_ICE_Malfunction;
    std::queue<MsgType> applicationOut_ICE_Malfunction;
    std::queue<MsgType> infrastructureOut_Stop_Pump_Completely;
    std::queue<MsgType> applicationOut_Stop_Pump_Completely;
    std::queue<MsgType> infrastructureOut_Pump_At_KVO_Rate;
    std::queue<MsgType> applicationOut_Pump_At_KVO_Rate;

    void sendOut_Alarm(MsgType msg);
    void sendOut_Warning(MsgType msg);
    void sendOut_Log_Fault(MsgType msg);
    void sendOut_ICE_Immediate(MsgType msg);
    void sendOut_ICE_Prompt(MsgType msg);
    void sendOut_ICE_Delayed(MsgType msg);
    void sendOut_ICE_Malfunction(MsgType msg);
    void sendOut_Stop_Pump_Completely(MsgType msg);
    void sendOut_Pump_At_KVO_Rate(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Alarm_Signal_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Reset_Alarm_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Empty_Res_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Res_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_Hot_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Upstream_Occlusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Downstream_Occlusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bubble_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Defective_Btty_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Battery_Warning_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Voltage_OOR_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_3;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_3;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_2;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base::*)(MsgType)>> outPortTupleVector;
};
