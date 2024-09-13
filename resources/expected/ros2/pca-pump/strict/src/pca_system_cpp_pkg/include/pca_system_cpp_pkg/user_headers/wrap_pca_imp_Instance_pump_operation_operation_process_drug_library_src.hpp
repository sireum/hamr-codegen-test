#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_operation_process_drug_library : public wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base
{
public:
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Load_Drug_Library(const example_interfaces::msg::Int32 msg);
    void handle_Get_Drug_Record(const example_interfaces::msg::Int32 msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
