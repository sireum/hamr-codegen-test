#include "wrap_pca_imp_Instance_cpp_pkg/user_headers/wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate_src.hpp"

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void wrap_pca_imp_Instance_pump_safety_alarm_process_flow_rate::timeTriggered()
{
    // Port messages
    auto System_Status_msg = get_System_Status();
    auto Infusion_Flow_Rate_msg = get_Infusion_Flow_Rate();
    auto Upstream_Flow_Rate_msg = get_Upstream_Flow_Rate();
    auto Downstream_Flow_Rate_msg = get_Downstream_Flow_Rate();

    // Handle communication

}

