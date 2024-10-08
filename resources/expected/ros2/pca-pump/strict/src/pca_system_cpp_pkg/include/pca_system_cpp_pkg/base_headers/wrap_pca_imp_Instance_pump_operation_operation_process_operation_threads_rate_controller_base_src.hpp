#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/flow_rateimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_volumeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/boolean.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/status_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/alarm_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/warning_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/minuteimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<pca_system_cpp_pkg_interfaces::msg::FlowRateimp, pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp, pca_system_cpp_pkg_interfaces::msg::Boolean, pca_system_cpp_pkg_interfaces::msg::StatusType, pca_system_cpp_pkg_interfaces::msg::AlarmType, pca_system_cpp_pkg_interfaces::msg::WarningType, pca_system_cpp_pkg_interfaces::msg::Minuteimp, pca_system_cpp_pkg_interfaces::msg::Empty>;

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Infusion_Flow_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg);
    void put_System_Status(pca_system_cpp_pkg_interfaces::msg::StatusType msg);

    pca_system_cpp_pkg_interfaces::msg::FlowRateimp get_Square_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp get_Patient_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp get_Basal_Rate();
    pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp get_VTBI();
    pca_system_cpp_pkg_interfaces::msg::Boolean get_Door_Open();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType msg) = 0;
    void handle_Alarm_base(MsgType msg);
    virtual void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType msg) = 0;
    void handle_Warning_base(MsgType msg);
    virtual void handle_CP_Bolus_Duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp msg) = 0;
    void handle_CP_Bolus_Duration_base(MsgType msg);
    virtual void handle_Begin_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Begin_Infusion_base(MsgType msg);
    virtual void handle_Begin_Priming(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Begin_Priming_base(MsgType msg);
    virtual void handle_End_Priming(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_End_Priming_base(MsgType msg);
    virtual void handle_Halt_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Halt_Infusion_base(MsgType msg);
    virtual void handle_HW_Detected_Failure(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_HW_Detected_Failure_base(MsgType msg);
    virtual void handle_Stop_Pump_Completely(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Stop_Pump_Completely_base(MsgType msg);
    virtual void handle_Pump_At_KVO_Rate(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Pump_At_KVO_Rate_base(MsgType msg);
    virtual void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Patient_Request_Not_Too_Soon_base(MsgType msg);
    virtual void handle_Pause_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Pause_Infusion_base(MsgType msg);
    virtual void handle_Resume_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Resume_Infusion_base(MsgType msg);
    virtual void handle_CP_Clinician_Request_Bolus(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_CP_Clinician_Request_Bolus_base(MsgType msg);
    virtual void handle_Near_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Near_Max_Drug_Per_Hour_base(MsgType msg);
    virtual void handle_Over_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Over_Max_Drug_Per_Hour_base(MsgType msg);
    virtual void handle_ICE_Stop_Pump(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_ICE_Stop_Pump_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_Square_Bolus_Rate;
    std::queue<MsgType> applicationIn_Square_Bolus_Rate;
    std::queue<MsgType> infrastructureIn_Patient_Bolus_Rate;
    std::queue<MsgType> applicationIn_Patient_Bolus_Rate;
    std::queue<MsgType> infrastructureIn_Basal_Rate;
    std::queue<MsgType> applicationIn_Basal_Rate;
    std::queue<MsgType> infrastructureIn_VTBI;
    std::queue<MsgType> applicationIn_VTBI;
    std::queue<MsgType> infrastructureIn_Door_Open;
    std::queue<MsgType> applicationIn_Door_Open;
    std::queue<MsgType> infrastructureIn_Alarm;
    std::queue<MsgType> applicationIn_Alarm;
    std::queue<MsgType> infrastructureIn_Warning;
    std::queue<MsgType> applicationIn_Warning;
    std::queue<MsgType> infrastructureIn_CP_Bolus_Duration;
    std::queue<MsgType> applicationIn_CP_Bolus_Duration;
    std::queue<MsgType> infrastructureIn_Begin_Infusion;
    std::queue<MsgType> applicationIn_Begin_Infusion;
    std::queue<MsgType> infrastructureIn_Begin_Priming;
    std::queue<MsgType> applicationIn_Begin_Priming;
    std::queue<MsgType> infrastructureIn_End_Priming;
    std::queue<MsgType> applicationIn_End_Priming;
    std::queue<MsgType> infrastructureIn_Halt_Infusion;
    std::queue<MsgType> applicationIn_Halt_Infusion;
    std::queue<MsgType> infrastructureIn_HW_Detected_Failure;
    std::queue<MsgType> applicationIn_HW_Detected_Failure;
    std::queue<MsgType> infrastructureIn_Stop_Pump_Completely;
    std::queue<MsgType> applicationIn_Stop_Pump_Completely;
    std::queue<MsgType> infrastructureIn_Pump_At_KVO_Rate;
    std::queue<MsgType> applicationIn_Pump_At_KVO_Rate;
    std::queue<MsgType> infrastructureIn_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> applicationIn_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> infrastructureIn_Pause_Infusion;
    std::queue<MsgType> applicationIn_Pause_Infusion;
    std::queue<MsgType> infrastructureIn_Resume_Infusion;
    std::queue<MsgType> applicationIn_Resume_Infusion;
    std::queue<MsgType> infrastructureIn_CP_Clinician_Request_Bolus;
    std::queue<MsgType> applicationIn_CP_Clinician_Request_Bolus;
    std::queue<MsgType> infrastructureIn_Near_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationIn_Near_Max_Drug_Per_Hour;
    std::queue<MsgType> infrastructureIn_Over_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationIn_Over_Max_Drug_Per_Hour;
    std::queue<MsgType> infrastructureIn_ICE_Stop_Pump;
    std::queue<MsgType> applicationIn_ICE_Stop_Pump;

    std::queue<MsgType> infrastructureOut_Infusion_Flow_Rate;
    std::queue<MsgType> applicationOut_Infusion_Flow_Rate;
    std::queue<MsgType> infrastructureOut_System_Status;
    std::queue<MsgType> applicationOut_System_Status;

    void sendOut_Infusion_Flow_Rate(MsgType msg);
    void sendOut_System_Status(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Square_Bolus_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Bolus_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Basal_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_VTBI_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Door_Open_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::AlarmType>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Alarm_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::WarningType>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Warning_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Bolus_Duration_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Begin_Priming_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_End_Priming_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Halt_Infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_HW_Detected_Failure_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Stop_Pump_Completely_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pump_At_KVO_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Patient_Request_Not_Too_Soon_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Pause_Infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Resume_Infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_CP_Clinician_Request_Bolus_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Near_Max_Drug_Per_Hour_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Over_Max_Drug_Per_Hour_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_ICE_Stop_Pump_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_3;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Infusion_Flow_Rate_publisher_4;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::StatusType>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::StatusType>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_System_Status_publisher_2;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base::*)(MsgType)>> outPortTupleVector;
};
