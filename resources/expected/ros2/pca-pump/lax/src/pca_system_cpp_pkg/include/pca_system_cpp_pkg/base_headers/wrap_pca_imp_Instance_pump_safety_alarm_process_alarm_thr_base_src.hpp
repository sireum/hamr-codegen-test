#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/alarm_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/warning_type.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/alarm_signal.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/fault_recordimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Alarm(pca_system_cpp_pkg_interfaces::msg::AlarmType msg);
    void put_Warning(pca_system_cpp_pkg_interfaces::msg::WarningType msg);
    void put_Pump_At_KVO_Rate(pca_system_cpp_pkg_interfaces::msg::Empty msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_ICE_Alarm_Signal(const pca_system_cpp_pkg_interfaces::msg::AlarmSignal::SharedPtr msg) = 0;
    virtual void handle_ICE_Reset_Alarm(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Max_Dose_Warning(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Hard_Limit_Violation(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Empty_Res(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Low_Res(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Pump_Hot(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Upstream_Occlusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Downstream_Occlusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Bubble(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Prime_Failure(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_CP_Reset_Alarm(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Drug_Not_In_Library(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Defective_Btty(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Low_Battery_Warning(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Voltage_OOR(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Basal_Overinfusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Bolus_Overinfusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Square_Bolus_Overinfusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Basal_Underinfusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Bolus_Underinfusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Square_Bolus_Underinfusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Security_Fault(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::AlarmSignal>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Alarm_Signal_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_ICE_Reset_Alarm_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Hard_Limit_Violation_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Empty_Res_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Res_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_Hot_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Upstream_Occlusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Downstream_Occlusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bubble_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Prime_Failure_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_CP_Reset_Alarm_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Drug_Not_In_Library_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Defective_Btty_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Low_Battery_Warning_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Voltage_OOR_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Overinfusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Overinfusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Overinfusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Basal_Underinfusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Bolus_Underinfusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Square_Bolus_Underinfusion_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Security_Fault_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::AlarmType>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::AlarmType>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::AlarmType>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Alarm_publisher_3;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::WarningType>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::WarningType>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::WarningType>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Warning_publisher_3;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Pump_At_KVO_Rate_publisher_2;

};
