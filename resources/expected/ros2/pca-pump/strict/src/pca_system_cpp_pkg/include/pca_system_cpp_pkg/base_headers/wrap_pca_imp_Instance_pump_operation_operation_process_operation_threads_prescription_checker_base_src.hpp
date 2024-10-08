#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/prescriptionimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_volumeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/flow_rateimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/minuteimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_codeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_recordimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<pca_system_cpp_pkg_interfaces::msg::Prescriptionimp, pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp, pca_system_cpp_pkg_interfaces::msg::FlowRateimp, pca_system_cpp_pkg_interfaces::msg::Minuteimp, pca_system_cpp_pkg_interfaces::msg::DrugCodeimp, pca_system_cpp_pkg_interfaces::msg::DrugRecordimp, pca_system_cpp_pkg_interfaces::msg::Empty>;

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

    pca_system_cpp_pkg_interfaces::msg::Prescriptionimp get_Prescription();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_The_Drug_Record(const pca_system_cpp_pkg_interfaces::msg::DrugRecordimp msg) = 0;
    void handle_The_Drug_Record_base(MsgType msg);
    virtual void handle_Check_Rx(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Check_Rx_base(MsgType msg);
    virtual void handle_Drug_Not_In_Library(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Drug_Not_In_Library_base(MsgType msg);
    virtual void handle_Confirm_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Confirm_Soft_Limit_Exception_base(MsgType msg);
    virtual void handle_Reject_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Reject_Soft_Limit_Exception_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_Prescription;
    std::queue<MsgType> applicationIn_Prescription;
    std::queue<MsgType> infrastructureIn_The_Drug_Record;
    std::queue<MsgType> applicationIn_The_Drug_Record;
    std::queue<MsgType> infrastructureIn_Check_Rx;
    std::queue<MsgType> applicationIn_Check_Rx;
    std::queue<MsgType> infrastructureIn_Drug_Not_In_Library;
    std::queue<MsgType> applicationIn_Drug_Not_In_Library;
    std::queue<MsgType> infrastructureIn_Confirm_Soft_Limit_Exception;
    std::queue<MsgType> applicationIn_Confirm_Soft_Limit_Exception;
    std::queue<MsgType> infrastructureIn_Reject_Soft_Limit_Exception;
    std::queue<MsgType> applicationIn_Reject_Soft_Limit_Exception;

    std::queue<MsgType> infrastructureOut_VTBI;
    std::queue<MsgType> applicationOut_VTBI;
    std::queue<MsgType> infrastructureOut_Square_Bolus_Rate;
    std::queue<MsgType> applicationOut_Square_Bolus_Rate;
    std::queue<MsgType> infrastructureOut_Patient_Bolus_Rate;
    std::queue<MsgType> applicationOut_Patient_Bolus_Rate;
    std::queue<MsgType> infrastructureOut_Basal_Rate;
    std::queue<MsgType> applicationOut_Basal_Rate;
    std::queue<MsgType> infrastructureOut_Minimum_Time_Between_Bolus;
    std::queue<MsgType> applicationOut_Minimum_Time_Between_Bolus;
    std::queue<MsgType> infrastructureOut_Max_Drug_Per_Hour;
    std::queue<MsgType> applicationOut_Max_Drug_Per_Hour;
    std::queue<MsgType> infrastructureOut_Get_Drug_Record;
    std::queue<MsgType> applicationOut_Get_Drug_Record;
    std::queue<MsgType> infrastructureOut_Rx_Okay;
    std::queue<MsgType> applicationOut_Rx_Okay;
    std::queue<MsgType> infrastructureOut_Soft_Limit_Warning;
    std::queue<MsgType> applicationOut_Soft_Limit_Warning;
    std::queue<MsgType> infrastructureOut_Hard_Limit_Violated;
    std::queue<MsgType> applicationOut_Hard_Limit_Violated;

    void sendOut_VTBI(MsgType msg);
    void sendOut_Square_Bolus_Rate(MsgType msg);
    void sendOut_Patient_Bolus_Rate(MsgType msg);
    void sendOut_Basal_Rate(MsgType msg);
    void sendOut_Minimum_Time_Between_Bolus(MsgType msg);
    void sendOut_Max_Drug_Per_Hour(MsgType msg);
    void sendOut_Get_Drug_Record(MsgType msg);
    void sendOut_Rx_Okay(MsgType msg);
    void sendOut_Soft_Limit_Warning(MsgType msg);
    void sendOut_Hard_Limit_Violated(MsgType msg);

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

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base::*)(MsgType)>> outPortTupleVector;
};
