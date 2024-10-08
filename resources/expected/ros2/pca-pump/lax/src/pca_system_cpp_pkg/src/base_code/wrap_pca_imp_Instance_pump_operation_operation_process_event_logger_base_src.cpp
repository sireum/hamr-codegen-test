#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_event_logger")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Log_Event_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Log_Event",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::handle_Log_Event, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Get_Event_Log_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_Get_Event_Log",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_event_logger_base::handle_Get_Event_Log, this, std::placeholders::_1), subscription_options_);

}
