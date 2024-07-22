#include "wrap_pca_imp_Instance_cpp_pkg/user_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_src.hpp"

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher::timeTriggered()
{
    // Port messages
    auto Infusion_Flow_Rate_msg = get_Infusion_Flow_Rate();
    auto Max_Drug_Per_Hour_msg = get_Max_Drug_Per_Hour();

    // Handle communication

}

