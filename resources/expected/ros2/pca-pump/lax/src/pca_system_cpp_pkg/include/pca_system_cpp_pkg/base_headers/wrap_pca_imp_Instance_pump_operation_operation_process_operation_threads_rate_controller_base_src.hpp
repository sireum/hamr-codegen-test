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

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Infusion_Flow_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg);
    void put_System_Status(pca_system_cpp_pkg_interfaces::msg::StatusType msg);

    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Square_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Patient_Bolus_Rate();
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr get_Basal_Rate();
    pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr get_VTBI();
    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr get_Door_Open();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Square_Bolus_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Patient_Bolus_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_Basal_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg);
    void handle_VTBI(const pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr msg);
    void handle_Door_Open(const pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr msg);
    virtual void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType::SharedPtr msg) = 0;
    virtual void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType::SharedPtr msg) = 0;
    virtual void handle_CP_Bolus_Duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp::SharedPtr msg) = 0;
    virtual void handle_Begin_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Begin_Priming(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_End_Priming(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Halt_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_HW_Detected_Failure(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Stop_Pump_Completely(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Pump_At_KVO_Rate(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Pause_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Resume_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_CP_Clinician_Request_Bolus(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Near_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Over_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_ICE_Stop_Pump(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;

    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Square_Bolus_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Patient_Bolus_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr Basal_Rate_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr VTBI_msg_holder;
    pca_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr Door_Open_msg_holder;

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

};
