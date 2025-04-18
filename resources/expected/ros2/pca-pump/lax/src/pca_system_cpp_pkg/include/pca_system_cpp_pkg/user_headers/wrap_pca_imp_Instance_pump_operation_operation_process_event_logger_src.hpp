#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_operation_process_event_logger : public wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base
{
public:
    wrap_pca_imp_Instance_pump_operation_operation_process_event_logger();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Log_Event(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Get_Event_Log(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
