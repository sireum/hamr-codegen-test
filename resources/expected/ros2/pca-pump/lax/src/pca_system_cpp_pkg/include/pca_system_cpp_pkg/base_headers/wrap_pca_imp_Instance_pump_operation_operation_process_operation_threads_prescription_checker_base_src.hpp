#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/prescriptionimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_volumeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/flow_rateimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/minuteimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_codeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_recordimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_VTBI(pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg);
    void put_Square_Bolus_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg);
    void put_Patient_Bolus_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg);
    void put_Basal_Rate(pca_system_cpp_pkg_interfaces::msg::FlowRateimp msg);
    void put_Minimum_Time_Between_Bolus(pca_system_cpp_pkg_interfaces::msg::Minuteimp msg);
    void put_Max_Drug_Per_Hour(pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp msg);
    void put_Get_Drug_Record(pca_system_cpp_pkg_interfaces::msg::DrugCodeimp msg);
    void put_Rx_Okay(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Soft_Limit_Warning(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Hard_Limit_Violated(pca_system_cpp_pkg_interfaces::msg::Empty msg);

    pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr get_Prescription();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Prescription(const pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr msg);
    virtual void handle_The_Drug_Record(const pca_system_cpp_pkg_interfaces::msg::DrugRecordimp::SharedPtr msg) = 0;
    virtual void handle_Check_Rx(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Drug_Not_In_Library(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Confirm_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;
    virtual void handle_Reject_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg) = 0;

    pca_system_cpp_pkg_interfaces::msg::Prescriptionimp::SharedPtr Prescription_msg_holder;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Prescription_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugRecordimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_The_Drug_Record_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Check_Rx_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Drug_Not_In_Library_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Confirm_Soft_Limit_Exception_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Reject_Soft_Limit_Exception_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_VTBI_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Square_Bolus_Rate_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Patient_Bolus_Rate_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Basal_Rate_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Minuteimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Minimum_Time_Between_Bolus_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Max_Drug_Per_Hour_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::DrugCodeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Get_Drug_Record_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Rx_Okay_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Soft_Limit_Warning_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_Hard_Limit_Violated_publisher_3;

};
