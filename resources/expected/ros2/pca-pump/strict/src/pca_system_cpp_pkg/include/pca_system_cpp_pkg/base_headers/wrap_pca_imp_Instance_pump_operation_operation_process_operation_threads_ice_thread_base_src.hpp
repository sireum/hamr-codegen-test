#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_library.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/minuteimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/boolean.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/status_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/flow_rateimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_volumeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/alarm_signal.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/alarm_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/warning_type.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<pca_system_cpp_pkg_interfaces::msg::Empty, pca_system_cpp_pkg_interfaces::msg::DrugLibrary, pca_system_cpp_pkg_interfaces::msg::Minuteimp, pca_system_cpp_pkg_interfaces::msg::Boolean, pca_system_cpp_pkg_interfaces::msg::StatusType, pca_system_cpp_pkg_interfaces::msg::FlowRateimp, pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp, pca_system_cpp_pkg_interfaces::msg::AlarmSignal, pca_system_cpp_pkg_interfaces::msg::AlarmType, pca_system_cpp_pkg_interfaces::msg::WarningType>;

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_parameters_current_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_parameters_basal_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_parameters_bolus_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_parameters_KVO_Flow_Rate(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_parameters_volume_to_be_infused(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_parameters_clinican_requested_bolus_duration(pca_system_cpp_pkg_interfaces::msg::Minuteimp msg);
    void put_parameters_square_flow_rate(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_status_On(pca_system_cpp_pkg_interfaces::msg::Boolean msg);
    void put_status_Okay(pca_system_cpp_pkg_interfaces::msg::Boolean msg);
    void put_status_status(pca_system_cpp_pkg_interfaces::msg::StatusType msg);
    void put_ICE_Stop_Pump(pca_system_cpp_pkg_interfaces::msg::Empty msg);

    pca_system_cpp_pkg_interfaces::msg::Boolean get_status_AppConnected();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp get_Infusion_Flow_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp get_Patient_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp get_Square_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp get_Basal_Rate();
    pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp get_VTBI();
    pca_system_cpp_pkg_interfaces::msg::Boolean get_Door_Open();
    pca_system_cpp_pkg_interfaces::msg::AlarmSignal get_Alarm_Inactivation();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_command_Start(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_command_Start_base(MsgType msg);
    virtual void handle_command_Suspend(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_command_Suspend_base(MsgType msg);
    virtual void handle_command_load_drug_library(const pca_system_cpp_pkg_interfaces::msg::DrugLibrary msg) = 0;
    void handle_command_load_drug_library_base(MsgType msg);
    virtual void handle_command_set_clinican_requested_bolus_duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp msg) = 0;
    void handle_command_set_clinican_requested_bolus_duration_base(MsgType msg);
    virtual void handle_command_request_bolus(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_command_request_bolus_base(MsgType msg);
    virtual void handle_command_pause_infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_command_pause_infusion_base(MsgType msg);
    virtual void handle_command_resume_infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_command_resume_infusion_base(MsgType msg);
    virtual void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType msg) = 0;
    void handle_Alarm_base(MsgType msg);
    virtual void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType msg) = 0;
    void handle_Warning_base(MsgType msg);
    virtual void handle_CP_Bolus_Duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp msg) = 0;
    void handle_CP_Bolus_Duration_base(MsgType msg);
    virtual void handle_Rx_Okay(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Rx_Okay_base(MsgType msg);
    virtual void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Patient_Request_Not_Too_Soon_base(MsgType msg);
    virtual void handle_Patient_Request_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Patient_Request_Too_Soon_base(MsgType msg);
    virtual void handle_HW_Detected_Failure(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_HW_Detected_Failure_base(MsgType msg);
    virtual void handle_Stop_Pump_Completely(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Stop_Pump_Completely_base(MsgType msg);
    virtual void handle_Pump_At_KVO_Rate(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Pump_At_KVO_Rate_base(MsgType msg);
    virtual void handle_CP_Clinician_Request_Bolus(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_CP_Clinician_Request_Bolus_base(MsgType msg);
    virtual void handle_Halt_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Halt_Infusion_base(MsgType msg);
    virtual void handle_Begin_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Begin_Infusion_base(MsgType msg);
    virtual void handle_Near_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Near_Max_Drug_Per_Hour_base(MsgType msg);
    virtual void handle_Over_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Over_Max_Drug_Per_Hour_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_command_Start;
    std::queue<MsgType> applicationIn_command_Start;
    std::queue<MsgType> infrastructureIn_command_Suspend;
    std::queue<MsgType> applicationIn_command_Suspend;
    std::queue<MsgType> infrastructureIn_command_load_drug_library;
    std::queue<MsgType> applicationIn_command_load_drug_library;
    std::queue<MsgType> infrastructureIn_command_set_clinican_requested_bolus_duration;
    std::queue<MsgType> applicationIn_command_set_clinican_requested_bolus_duration;
    std::queue<MsgType> infrastructureIn_command_request_bolus;
    std::queue<MsgType> applicationIn_command_request_bolus;
    std::queue<MsgType> infrastructureIn_command_pause_infusion;
    std::queue<MsgType> applicationIn_command_pause_infusion;
    std::queue<MsgType> infrastructureIn_command_resume_infusion;
    std::queue<MsgType> applicationIn_command_resume_infusion;
    std::queue<MsgType> infrastructureIn_status_AppConnected;
    std::queue<MsgType> applicationIn_status_AppConnected;
    std::queue<MsgType> infrastructureIn_Infusion_Flow_Rate;
    std::queue<MsgType> applicationIn_Infusion_Flow_Rate;
    std::queue<MsgType> infrastructureIn_Patient_Bolus_Rate;
    std::queue<MsgType> applicationIn_Patient_Bolus_Rate;
    std::queue<MsgType> infrastructureIn_Square_Bolus_Rate;
    std::queue<MsgType> applicationIn_Square_Bolus_Rate;
    std::queue<MsgType> infrastructureIn_Basal_Rate;
    std::queue<MsgType> applicationIn_Basal_Rate;
    std::queue<MsgType> infrastructureIn_VTBI;
    std::queue<MsgType> applicationIn_VTBI;
    std::queue<MsgType> infrastructureIn_Door_Open;
    std::queue<MsgType> applicationIn_Door_Open;
    std::queue<MsgType> infrastructureIn_Alarm_Inactivation;
    std::queue<MsgType> applicationIn_Alarm_Inactivation;
    std::queue<MsgType> infrastructureIn_Alarm;
    std::queue<MsgType> applicationIn_Alarm;
    std::queue<MsgType> infrastructureIn_Warning;
    std::queue<MsgType> applicationIn_Warning;
    std::queue<MsgType> infrastructureIn_CP_Bolus_Duration;
    std::queue<MsgType> applicationIn_CP_Bolus_Duration;
    std::queue<MsgType> infrastructureIn_Rx_Okay;
    std::queue<MsgType> applicationIn_Rx_Okay;
    std::queue<MsgType> infrastructureIn_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> applicationIn_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> infrastructureIn_Patient_Request_Too_Soon;
    std::queue<MsgType> applicationIn_Patient_Request_Too_Soon;
    std::queue<MsgType> infrastructureIn_HW_Detected_Failure;
    std::queue<MsgType> applicationIn_HW_Detected_Failure;
    std::queue<MsgType> infrastructureIn_Stop_Pump_Completely;
    std::queue<MsgType> applicationIn_Stop_Pump_Completely;
    std::queue<MsgType> infrastructureIn_Pump_At_KVO_Rate;
    std::queue<MsgType> applicationIn_Pump_At_KVO_Rate;
    std::queue<MsgType> infrastructureIn_CP_Clinician_Request_Bolus;
    std::queue<MsgType> applicationIn_CP_Clinician_Request_Bolus;
    std::queue<MsgType> infrastructureIn_Halt_Infusion;
    std::queue<MsgType> applicationIn_Halt_Infusion;
    std::queue<MsgType> infrastructureIn_Begin_Infusion;
    std::queue<MsgType> applicationIn_Begin_Infusion;
    std::queue<MsgType> infrastructureIn_Near_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationIn_Near_Max_Drug_Per_Hour;
    std::queue<MsgType> infrastructureIn_Over_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationIn_Over_Max_Drug_Per_Hour;

    std::queue<MsgType> infrastructureOut_parameters_current_flow_rate;
    std::queue<MsgType> applicationOut_parameters_current_flow_rate;
    std::queue<MsgType> infrastructureOut_parameters_basal_flow_rate;
    std::queue<MsgType> applicationOut_parameters_basal_flow_rate;
    std::queue<MsgType> infrastructureOut_parameters_bolus_flow_rate;
    std::queue<MsgType> applicationOut_parameters_bolus_flow_rate;
    std::queue<MsgType> infrastructureOut_parameters_KVO_Flow_Rate;
    std::queue<MsgType> applicationOut_parameters_KVO_Flow_Rate;
    std::queue<MsgType> infrastructureOut_parameters_volume_to_be_infused;
    std::queue<MsgType> applicationOut_parameters_volume_to_be_infused;
    std::queue<MsgType> infrastructureOut_parameters_clinican_requested_bolus_duration;
    std::queue<MsgType> applicationOut_parameters_clinican_requested_bolus_duration;
    std::queue<MsgType> infrastructureOut_parameters_square_flow_rate;
    std::queue<MsgType> applicationOut_parameters_square_flow_rate;
    std::queue<MsgType> infrastructureOut_status_On;
    std::queue<MsgType> applicationOut_status_On;
    std::queue<MsgType> infrastructureOut_status_Okay;
    std::queue<MsgType> applicationOut_status_Okay;
    std::queue<MsgType> infrastructureOut_status_status;
    std::queue<MsgType> applicationOut_status_status;
    std::queue<MsgType> infrastructureOut_ICE_Stop_Pump;
    std::queue<MsgType> applicationOut_ICE_Stop_Pump;

    void sendOut_parameters_current_flow_rate(MsgType msg);
    void sendOut_parameters_basal_flow_rate(MsgType msg);
    void sendOut_parameters_bolus_flow_rate(MsgType msg);
    void sendOut_parameters_KVO_Flow_Rate(MsgType msg);
    void sendOut_parameters_volume_to_be_infused(MsgType msg);
    void sendOut_parameters_clinican_requested_bolus_duration(MsgType msg);
    void sendOut_parameters_square_flow_rate(MsgType msg);
    void sendOut_status_On(MsgType msg);
    void sendOut_status_Okay(MsgType msg);
    void sendOut_status_status(MsgType msg);
    void sendOut_ICE_Stop_Pump(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Start_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_Suspend_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugLibrary>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_load_drug_library_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_set_clinican_requested_bolus_duration_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_request_bolus_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_pause_infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_command_resume_infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_status_AppConnected_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Bolus_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Square_Bolus_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Basal_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_VTBI_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Door_Open_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::AlarmSignal>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_Inactivation_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::AlarmType>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Alarm_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::WarningType>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Warning_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Minuteimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Bolus_Duration_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Rx_Okay_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Not_Too_Soon_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Patient_Request_Too_Soon_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_HW_Detected_Failure_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Stop_Pump_Completely_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Pump_At_KVO_Rate_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_CP_Clinician_Request_Bolus_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Halt_Infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Begin_Infusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_ICE_Stop_Pump_publisher_;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base::*)(MsgType)>> outPortTupleVector;
};
