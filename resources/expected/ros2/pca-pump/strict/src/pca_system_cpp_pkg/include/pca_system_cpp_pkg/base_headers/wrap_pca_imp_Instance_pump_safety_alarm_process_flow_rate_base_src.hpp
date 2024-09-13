#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Basal_Overinfusion(example_interfaces::msg::Int32 msg);
    void put_Bolus_Overinfusion(example_interfaces::msg::Int32 msg);
    void put_Square_Bolus_Overinfusion(example_interfaces::msg::Int32 msg);
    void put_Basal_Underinfusion(example_interfaces::msg::Int32 msg);
    void put_Bolus_Underinfusion(example_interfaces::msg::Int32 msg);
    void put_Square_Bolus_Underinfusion(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32 get_System_Status();
    example_interfaces::msg::Int32 get_Infusion_Flow_Rate();
    example_interfaces::msg::Int32 get_Upstream_Flow_Rate();
    example_interfaces::msg::Int32 get_Downstream_Flow_Rate();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureIn_System_Status;
    std::queue<MsgType> applicationIn_System_Status;
    std::queue<MsgType> infrastructureIn_Infusion_Flow_Rate;
    std::queue<MsgType> applicationIn_Infusion_Flow_Rate;
    std::queue<MsgType> infrastructureIn_Upstream_Flow_Rate;
    std::queue<MsgType> applicationIn_Upstream_Flow_Rate;
    std::queue<MsgType> infrastructureIn_Downstream_Flow_Rate;
    std::queue<MsgType> applicationIn_Downstream_Flow_Rate;

    std::queue<MsgType> infrastructureOut_Basal_Overinfusion;
    std::queue<MsgType> applicationOut_Basal_Overinfusion;
    std::queue<MsgType> infrastructureOut_Bolus_Overinfusion;
    std::queue<MsgType> applicationOut_Bolus_Overinfusion;
    std::queue<MsgType> infrastructureOut_Square_Bolus_Overinfusion;
    std::queue<MsgType> applicationOut_Square_Bolus_Overinfusion;
    std::queue<MsgType> infrastructureOut_Basal_Underinfusion;
    std::queue<MsgType> applicationOut_Basal_Underinfusion;
    std::queue<MsgType> infrastructureOut_Bolus_Underinfusion;
    std::queue<MsgType> applicationOut_Bolus_Underinfusion;
    std::queue<MsgType> infrastructureOut_Square_Bolus_Underinfusion;
    std::queue<MsgType> applicationOut_Square_Bolus_Underinfusion;

    void sendOut_Basal_Overinfusion(MsgType msg);
    void sendOut_Bolus_Overinfusion(MsgType msg);
    void sendOut_Square_Bolus_Overinfusion(MsgType msg);
    void sendOut_Basal_Underinfusion(MsgType msg);
    void sendOut_Bolus_Underinfusion(MsgType msg);
    void sendOut_Square_Bolus_Underinfusion(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_System_Status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Upstream_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Downstream_Flow_Rate_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Overinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Overinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Overinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Basal_Underinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Bolus_Underinfusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_Square_Bolus_Underinfusion_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

    void timeTriggeredCaller();

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inEventPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_base::*)(MsgType)>> outPortTupleVector;
};
