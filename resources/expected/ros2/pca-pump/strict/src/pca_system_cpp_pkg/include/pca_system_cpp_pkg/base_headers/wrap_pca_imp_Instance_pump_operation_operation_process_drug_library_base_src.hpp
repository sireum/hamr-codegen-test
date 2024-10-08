#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_library.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_codeimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/drug_recordimp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<pca_system_cpp_pkg_interfaces::msg::DrugLibrary, pca_system_cpp_pkg_interfaces::msg::DrugCodeimp, pca_system_cpp_pkg_interfaces::msg::DrugRecordimp, pca_system_cpp_pkg_interfaces::msg::Empty>;

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

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Load_Drug_Library(const pca_system_cpp_pkg_interfaces::msg::DrugLibrary msg) = 0;
    void handle_Load_Drug_Library_base(MsgType msg);
    virtual void handle_Get_Drug_Record(const pca_system_cpp_pkg_interfaces::msg::DrugCodeimp msg) = 0;
    void handle_Get_Drug_Record_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_Load_Drug_Library;
    std::queue<MsgType> applicationIn_Load_Drug_Library;
    std::queue<MsgType> infrastructureIn_Get_Drug_Record;
    std::queue<MsgType> applicationIn_Get_Drug_Record;

    std::queue<MsgType> infrastructureOut_The_Drug_Record;
    std::queue<MsgType> applicationOut_The_Drug_Record;
    std::queue<MsgType> infrastructureOut_No_Drug_Found;
    std::queue<MsgType> applicationOut_No_Drug_Found;

    void sendOut_The_Drug_Record(MsgType msg);
    void sendOut_No_Drug_Found(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugLibrary>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Load_Drug_Library_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::DrugCodeimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_Get_Drug_Record_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::DrugRecordimp>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_The_Drug_Record_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_No_Drug_Found_publisher_3;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_drug_library_base::*)(MsgType)>> outPortTupleVector;
};
