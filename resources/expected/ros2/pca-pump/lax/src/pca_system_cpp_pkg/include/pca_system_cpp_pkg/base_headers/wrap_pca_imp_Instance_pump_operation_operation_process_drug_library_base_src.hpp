#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_library.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_codeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_recordimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base : public rclcpp::Node
{
protected:
    wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_The_Drug_Record(pca_system_cpp_pkg_interfaces::msg::DrugRecordimp msg);
    void put_No_Drug_Found(pca_system_cpp_pkg_interfaces::msg::Empty msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Load_Drug_Library(const pca_system_cpp_pkg_interfaces::msg::DrugLibrary::SharedPtr msg) = 0;
    virtual void handle_Get_Drug_Record(const pca_system_cpp_pkg_interfaces::msg::DrugCodeimp::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugLibrary>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Load_Drug_Library_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugCodeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::DrugRecordimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_The_Drug_Record_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_3;

};
