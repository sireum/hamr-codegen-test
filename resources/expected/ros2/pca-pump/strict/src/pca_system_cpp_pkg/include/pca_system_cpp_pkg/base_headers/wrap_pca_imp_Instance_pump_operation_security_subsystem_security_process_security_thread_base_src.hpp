#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Clinician_Name(example_interfaces::msg::Int32 msg);
    void put_Patient_Name(example_interfaces::msg::Int32 msg);
    void put_Prescription(example_interfaces::msg::Int32 msg);
    void put_Authentication_fail(example_interfaces::msg::Int32 msg);
    void put_Authentication_pass(example_interfaces::msg::Int32 msg);
    void put_Security_Fault(example_interfaces::msg::Int32 msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Scan_Data(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Scan_Data_base(MsgType msg);
    virtual void handle_Authenticate_Clinician(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Authenticate_Clinician_base(MsgType msg);
    virtual void handle_Authenticate_Patient(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Authenticate_Patient_base(MsgType msg);
    virtual void handle_Authenticate_Prescription(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Authenticate_Prescription_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_Scan_Data;
    std::queue<MsgType> applicationIn_Scan_Data;
    std::queue<MsgType> infrastructureIn_Authenticate_Clinician;
    std::queue<MsgType> applicationIn_Authenticate_Clinician;
    std::queue<MsgType> infrastructureIn_Authenticate_Patient;
    std::queue<MsgType> applicationIn_Authenticate_Patient;
    std::queue<MsgType> infrastructureIn_Authenticate_Prescription;
    std::queue<MsgType> applicationIn_Authenticate_Prescription;

    std::queue<MsgType> infrastructureOut_Clinician_Name;
    std::queue<MsgType> applicationOut_Clinician_Name;
    std::queue<MsgType> infrastructureOut_Patient_Name;
    std::queue<MsgType> applicationOut_Patient_Name;
    std::queue<MsgType> infrastructureOut_Prescription;
    std::queue<MsgType> applicationOut_Prescription;
    std::queue<MsgType> infrastructureOut_Authentication_fail;
    std::queue<MsgType> applicationOut_Authentication_fail;
    std::queue<MsgType> infrastructureOut_Authentication_pass;
    std::queue<MsgType> applicationOut_Authentication_pass;
    std::queue<MsgType> infrastructureOut_Security_Fault;
    std::queue<MsgType> applicationOut_Security_Fault;

    void sendOut_Clinician_Name(MsgType msg);
    void sendOut_Patient_Name(MsgType msg);
    void sendOut_Prescription(MsgType msg);
    void sendOut_Authentication_fail(MsgType msg);
    void sendOut_Authentication_pass(MsgType msg);
    void sendOut_Security_Fault(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Scan_Data_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Clinician_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Patient_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authenticate_Prescription_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Clinician_Name_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Patient_Name_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Prescription_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_fail_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Authentication_pass_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_Security_Fault_publisher_;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base::*)(MsgType)>> outPortTupleVector;
};
