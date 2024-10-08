#include "rclcpp/rclcpp.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/message.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/sound.hpp"
#include "pca_system_cpp_pkg_interfaces/msg/empty.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<pca_system_cpp_pkg_interfaces::msg::Message, pca_system_cpp_pkg_interfaces::msg::Sound, pca_system_cpp_pkg_interfaces::msg::Empty>;

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Display_Message(pca_system_cpp_pkg_interfaces::msg::Message msg);
    void put_Sound_Type(pca_system_cpp_pkg_interfaces::msg::Sound msg);
    void put_Log_Event(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Do_Scan(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Authenticate_Clinician(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Authenticate_Patient(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Authenticate_Prescription(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Check_Rx(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Begin_Priming(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_End_Priming(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Prime_Failure(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Begin_Infusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);
    void put_Halt_Infusion(pca_system_cpp_pkg_interfaces::msg::Empty msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_POST_done(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_POST_done_base(MsgType msg);
    virtual void handle_POST_fail(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_POST_fail_base(MsgType msg);
    virtual void handle_Stop_Button_Pressed(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Stop_Button_Pressed_base(MsgType msg);
    virtual void handle_Start_Button_Pressed(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Start_Button_Pressed_base(MsgType msg);
    virtual void handle_Scan_Done(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Scan_Done_base(MsgType msg);
    virtual void handle_Authentication_fail(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Authentication_fail_base(MsgType msg);
    virtual void handle_Authentication_pass(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Authentication_pass_base(MsgType msg);
    virtual void handle_Drug_Not_In_Library(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Drug_Not_In_Library_base(MsgType msg);
    virtual void handle_Hard_Limit_Violated(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Hard_Limit_Violated_base(MsgType msg);
    virtual void handle_Reject_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Reject_Soft_Limit_Exception_base(MsgType msg);
    virtual void handle_Confirm_Soft_Limit_Exception(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Confirm_Soft_Limit_Exception_base(MsgType msg);
    virtual void handle_Rx_Okay(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Rx_Okay_base(MsgType msg);
    virtual void handle_Door_Closed(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Door_Closed_base(MsgType msg);
    virtual void handle_Turn_Off(const pca_system_cpp_pkg_interfaces::msg::Empty msg) = 0;
    void handle_Turn_Off_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_POST_done;
    std::queue<MsgType> applicationIn_POST_done;
    std::queue<MsgType> infrastructureIn_POST_fail;
    std::queue<MsgType> applicationIn_POST_fail;
    std::queue<MsgType> infrastructureIn_Stop_Button_Pressed;
    std::queue<MsgType> applicationIn_Stop_Button_Pressed;
    std::queue<MsgType> infrastructureIn_Start_Button_Pressed;
    std::queue<MsgType> applicationIn_Start_Button_Pressed;
    std::queue<MsgType> infrastructureIn_Scan_Done;
    std::queue<MsgType> applicationIn_Scan_Done;
    std::queue<MsgType> infrastructureIn_Authentication_fail;
    std::queue<MsgType> applicationIn_Authentication_fail;
    std::queue<MsgType> infrastructureIn_Authentication_pass;
    std::queue<MsgType> applicationIn_Authentication_pass;
    std::queue<MsgType> infrastructureIn_Drug_Not_In_Library;
    std::queue<MsgType> applicationIn_Drug_Not_In_Library;
    std::queue<MsgType> infrastructureIn_Hard_Limit_Violated;
    std::queue<MsgType> applicationIn_Hard_Limit_Violated;
    std::queue<MsgType> infrastructureIn_Reject_Soft_Limit_Exception;
    std::queue<MsgType> applicationIn_Reject_Soft_Limit_Exception;
    std::queue<MsgType> infrastructureIn_Confirm_Soft_Limit_Exception;
    std::queue<MsgType> applicationIn_Confirm_Soft_Limit_Exception;
    std::queue<MsgType> infrastructureIn_Rx_Okay;
    std::queue<MsgType> applicationIn_Rx_Okay;
    std::queue<MsgType> infrastructureIn_Door_Closed;
    std::queue<MsgType> applicationIn_Door_Closed;
    std::queue<MsgType> infrastructureIn_Turn_Off;
    std::queue<MsgType> applicationIn_Turn_Off;

    std::queue<MsgType> infrastructureOut_Display_Message;
    std::queue<MsgType> applicationOut_Display_Message;
    std::queue<MsgType> infrastructureOut_Sound_Type;
    std::queue<MsgType> applicationOut_Sound_Type;
    std::queue<MsgType> infrastructureOut_Log_Event;
    std::queue<MsgType> applicationOut_Log_Event;
    std::queue<MsgType> infrastructureOut_Do_Scan;
    std::queue<MsgType> applicationOut_Do_Scan;
    std::queue<MsgType> infrastructureOut_Authenticate_Clinician;
    std::queue<MsgType> applicationOut_Authenticate_Clinician;
    std::queue<MsgType> infrastructureOut_Authenticate_Patient;
    std::queue<MsgType> applicationOut_Authenticate_Patient;
    std::queue<MsgType> infrastructureOut_Authenticate_Prescription;
    std::queue<MsgType> applicationOut_Authenticate_Prescription;
    std::queue<MsgType> infrastructureOut_Check_Rx;
    std::queue<MsgType> applicationOut_Check_Rx;
    std::queue<MsgType> infrastructureOut_Begin_Priming;
    std::queue<MsgType> applicationOut_Begin_Priming;
    std::queue<MsgType> infrastructureOut_End_Priming;
    std::queue<MsgType> applicationOut_End_Priming;
    std::queue<MsgType> infrastructureOut_Prime_Failure;
    std::queue<MsgType> applicationOut_Prime_Failure;
    std::queue<MsgType> infrastructureOut_Begin_Infusion;
    std::queue<MsgType> applicationOut_Begin_Infusion;
    std::queue<MsgType> infrastructureOut_Halt_Infusion;
    std::queue<MsgType> applicationOut_Halt_Infusion;

    void sendOut_Display_Message(MsgType msg);
    void sendOut_Sound_Type(MsgType msg);
    void sendOut_Log_Event(MsgType msg);
    void sendOut_Do_Scan(MsgType msg);
    void sendOut_Authenticate_Clinician(MsgType msg);
    void sendOut_Authenticate_Patient(MsgType msg);
    void sendOut_Authenticate_Prescription(MsgType msg);
    void sendOut_Check_Rx(MsgType msg);
    void sendOut_Begin_Priming(MsgType msg);
    void sendOut_End_Priming(MsgType msg);
    void sendOut_Prime_Failure(MsgType msg);
    void sendOut_Begin_Infusion(MsgType msg);
    void sendOut_Halt_Infusion(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_done_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_POST_fail_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Stop_Button_Pressed_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Start_Button_Pressed_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Scan_Done_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_fail_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authentication_pass_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Drug_Not_In_Library_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Hard_Limit_Violated_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Reject_Soft_Limit_Exception_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Confirm_Soft_Limit_Exception_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Rx_Okay_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Door_Closed_subscription_;
    rclcpp::Subscription<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Turn_Off_subscription_;

    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Message>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Display_Message_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Sound>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Sound_Type_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Log_Event_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Clinician_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Patient_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Authenticate_Prescription_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Check_Rx_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Priming_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_End_Priming_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Prime_Failure_publisher_;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Begin_Infusion_publisher_2;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_1;
    rclcpp::Publisher<pca_system_cpp_pkg_interfaces::msg::Empty>::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_Halt_Infusion_publisher_2;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_boss_base::*)(MsgType)>> outPortTupleVector;
};
