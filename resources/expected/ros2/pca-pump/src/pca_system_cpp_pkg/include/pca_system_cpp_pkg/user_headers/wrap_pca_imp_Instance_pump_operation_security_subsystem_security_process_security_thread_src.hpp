#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread : public wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread_base
{
public:
    wrap_pca_imp_Instance_pump_operation_security_subsystem_security_process_security_thread();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Scan_Data(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Authenticate_Clinician(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Authenticate_Patient(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Authenticate_Prescription(const example_interfaces::msg::Int32::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
