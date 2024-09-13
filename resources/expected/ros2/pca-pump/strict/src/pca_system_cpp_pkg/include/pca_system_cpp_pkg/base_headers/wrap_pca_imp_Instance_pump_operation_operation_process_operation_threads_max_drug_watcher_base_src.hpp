#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Near_Max_Drug_Per_Hour(example_interfaces::msg::Int32 msg);
    void put_Over_Max_Drug_Per_Hour(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32 get_Infusion_Flow_Rate();
    example_interfaces::msg::Int32 get_Max_Drug_Per_Hour();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureIn_Infusion_Flow_Rate;
    std::queue<MsgType> applicationIn_Infusion_Flow_Rate;
    std::queue<MsgType> infrastructureIn_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationIn_Max_Drug_Per_Hour;

    std::queue<MsgType> infrastructureOut_Near_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationOut_Near_Max_Drug_Per_Hour;
    std::queue<MsgType> infrastructureOut_Over_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationOut_Over_Max_Drug_Per_Hour;

    void sendOut_Near_Max_Drug_Per_Hour(MsgType msg);
    void sendOut_Over_Max_Drug_Per_Hour(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_3;

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
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::*)(MsgType)>> outPortTupleVector;
};
