#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base_src.hpp"

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss : public wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base
{
public:
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_POST_done(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_POST_fail(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Stop_Button_Pressed(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Start_Button_Pressed(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Scan_Done(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Authentication_fail(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Authentication_pass(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Drug_Not_In_Library(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Hard_Limit_Violated(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Reject_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Confirm_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Rx_Okay(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Door_Closed(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);
    void handle_Turn_Off(const pca_system_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
