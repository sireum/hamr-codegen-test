#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base_src.hpp"

class wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr : public wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_base
{
public:
    wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_ICE_Alarm_Signal(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_ICE_Reset_Alarm(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Max_Dose_Warning(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Hard_Limit_Violation(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Empty_Res(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Low_Res(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Pump_Hot(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Upstream_Occlusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Downstream_Occlusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Bubble(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Prime_Failure(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_CP_Reset_Alarm(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Drug_Not_In_Library(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Defective_Btty(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Low_Battery_Warning(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Voltage_OOR(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Basal_Overinfusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Bolus_Overinfusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Square_Bolus_Overinfusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Basal_Underinfusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Bolus_Underinfusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Square_Bolus_Underinfusion(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Security_Fault(const example_interfaces::msg::Int32::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
