#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Patient_Request_Not_Too_Soon(example_interfaces::msg::Int32 msg);
    void put_Patient_Request_Too_Soon(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32 get_Minimum_Time_Between_Bolus();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Patient_Button_Request(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Patient_Button_Request_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_Minimum_Time_Between_Bolus;
    std::queue<MsgType> applicationIn_Minimum_Time_Between_Bolus;
    std::queue<MsgType> infrastructureIn_Patient_Button_Request;
    std::queue<MsgType> applicationIn_Patient_Button_Request;

    std::queue<MsgType> infrastructureOut_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> applicationOut_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> infrastructureOut_Patient_Request_Too_Soon;
    std::queue<MsgType> applicationOut_Patient_Request_Too_Soon;

    void sendOut_Patient_Request_Not_Too_Soon(MsgType msg);
    void sendOut_Patient_Request_Too_Soon(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Minimum_Time_Between_Bolus_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Button_Request_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Not_Too_Soon_publisher_3;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_Patient_Request_Too_Soon_publisher_2;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base::*)(MsgType)>> outPortTupleVector;
};
