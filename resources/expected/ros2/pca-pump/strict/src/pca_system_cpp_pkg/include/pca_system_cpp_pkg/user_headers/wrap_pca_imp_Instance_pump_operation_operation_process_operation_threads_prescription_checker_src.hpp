#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker : public wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker_base
{
public:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_prescription_checker();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_The_Drug_Record(const pca_system_cpp_pkg_interfaces::msg::DrugRecordimp msg);
    void handle_Check_Rx(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Drug_Not_In_Library(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Confirm_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Reject_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
