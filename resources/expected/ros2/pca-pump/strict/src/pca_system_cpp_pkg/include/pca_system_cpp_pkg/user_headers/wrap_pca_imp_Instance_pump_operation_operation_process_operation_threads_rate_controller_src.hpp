#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller : public wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_base
{
public:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType msg);
    void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType msg);
    void handle_CP_Bolus_Duration(const pca_system_cpp_pkg_interfaces::msg::Minuteimp msg);
    void handle_Begin_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Begin_Priming(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_End_Priming(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Halt_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_HW_Detected_Failure(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Stop_Pump_Completely(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Pump_At_KVO_Rate(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Pause_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Resume_Infusion(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_CP_Clinician_Request_Bolus(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Near_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Over_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_ICE_Stop_Pump(const pca_system_cpp_pkg_interfaces::msg::Empty msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
