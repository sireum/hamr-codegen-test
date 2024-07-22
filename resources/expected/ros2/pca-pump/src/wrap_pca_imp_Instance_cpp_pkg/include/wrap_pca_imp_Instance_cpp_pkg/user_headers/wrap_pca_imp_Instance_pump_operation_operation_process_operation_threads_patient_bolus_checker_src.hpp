#include "wrap_pca_imp_Instance_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker : public wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker_base
{
public:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_patient_bolus_checker();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Minimum_Time_Between_Bolus(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Patient_Button_Request(const example_interfaces::msg::Int32::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
