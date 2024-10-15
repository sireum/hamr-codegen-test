#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread : public wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_base
{
public:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_command_Start(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_command_Suspend(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_command_load_drug_library(const pca_system_cpp_pkg_interfaces::msg::DrugLibrary::SharedPtr msg);
    void handle_command_set_clinican_requested_bolus_duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp::SharedPtr msg);
    void handle_command_request_bolus(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_command_pause_infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_command_resume_infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType::SharedPtr msg);
    void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType::SharedPtr msg);
    void handle_CP_Bolus_Duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp::SharedPtr msg);
    void handle_Rx_Okay(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Patient_Request_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_HW_Detected_Failure(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Stop_Pump_Completely(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Pump_At_KVO_Rate(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_CP_Clinician_Request_Bolus(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Halt_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Begin_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Near_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Over_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
