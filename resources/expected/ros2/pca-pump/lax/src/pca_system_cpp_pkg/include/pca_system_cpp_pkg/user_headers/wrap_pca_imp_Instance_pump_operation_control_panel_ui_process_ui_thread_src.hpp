#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread : public wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base
{
public:
    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_Touch(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Alarm(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Warning(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_System_Status(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Display_Message(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Sound_Type(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Low_Battery_Warning(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Hard_Limit_Violated(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Soft_Limit_Warning(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Patient_Request_Not_Too_Soon(const example_interfaces::msg::Int32::SharedPtr msg);
    void handle_Patient_Request_Too_Soon(const example_interfaces::msg::Int32::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
