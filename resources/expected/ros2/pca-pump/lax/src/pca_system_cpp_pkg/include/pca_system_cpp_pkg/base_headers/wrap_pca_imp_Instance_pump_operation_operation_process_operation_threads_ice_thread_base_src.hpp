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

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_ICE_Stop_Pump(pca_system_cpp_pkg_interfaces::msg::Empty msg);

    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr get_status_AppConnected();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Infusion_Flow_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Patient_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Square_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Basal_Rate();
    pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr get_VTBI();
    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr get_Door_Open();
    pca_system_cpp_pkg_interfaces::msg::AlarmSignal::SharedPtr get_Alarm_Inactivation();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_command_Start(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_command_Suspend(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_command_load_drug_library(const pca_system_cpp_pkg_interfaces::msg::DrugLibrary::SharedPtr msg) = 0;
    virtual void handle_command_set_clinican_requested_bolus_duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp::SharedPtr msg) = 0;
    virtual void handle_command_request_bolus(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_command_pause_infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_command_resume_infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    void handle_status_AppConnected(const pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr msg);
    void handle_Infusion_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Patient_Bolus_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Square_Bolus_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Basal_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_VTBI(const pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr msg);
    void handle_Door_Open(const pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr msg);
    void handle_Alarm_Inactivation(const pca_system_cpp_pkg_interfaces::msg::AlarmSignal::SharedPtr msg);
    virtual void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType::SharedPtr msg) = 0;
    virtual void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType::SharedPtr msg) = 0;
    virtual void handle_CP_Bolus_Duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp::SharedPtr msg) = 0;
    virtual void handle_Rx_Okay(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Patient_Request_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_HW_Detected_Failure(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Stop_Pump_Completely(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Pump_At_KVO_Rate(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_CP_Clinician_Request_Bolus(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Halt_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Begin_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Near_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Over_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;

    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr status_AppConnected_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Infusion_Flow_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Patient_Bolus_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Square_Bolus_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Basal_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr VTBI_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr Door_Open_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::AlarmSignal::SharedPtr Alarm_Inactivation_msg_holder;

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

};
