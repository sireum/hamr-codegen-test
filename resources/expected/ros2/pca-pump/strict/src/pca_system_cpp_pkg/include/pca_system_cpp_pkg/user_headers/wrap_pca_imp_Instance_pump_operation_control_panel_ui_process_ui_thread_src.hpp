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
    void handle_Touch(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Alarm(const pca_system_cpp_pkg_interfaces::msg::AlarmType msg);
    void handle_Warning(const pca_system_cpp_pkg_interfaces::msg::WarningType msg);
    void handle_System_Status(const pca_system_cpp_pkg_interfaces::msg::StatusType msg);
    void handle_Display_Message(const pca_system_cpp_pkg_interfaces::msg::Message msg);
    void handle_Sound_Type(const pca_system_cpp_pkg_interfaces::msg::Sound msg);
    void handle_Low_Battery_Warning(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Hard_Limit_Violated(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Soft_Limit_Warning(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Patient_Request_Not_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void handle_Patient_Request_Too_Soon(const pca_system_cpp_pkg_interfaces::msg::Empty msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};