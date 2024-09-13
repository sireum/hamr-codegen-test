#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int32.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<example_interfaces::msg::Int32>;

    wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_Image(example_interfaces::msg::Int32 msg);
    void put_AudioSignal(example_interfaces::msg::Int32 msg);
    void put_Alarm_Inactivation(example_interfaces::msg::Int32 msg);
    void put_Bolus_Duration(example_interfaces::msg::Int32 msg);
    void put_CP_Reset_Alarm(example_interfaces::msg::Int32 msg);
    void put_Confirm_Soft_Limit_Exception(example_interfaces::msg::Int32 msg);
    void put_Reject_Soft_Limit_Exception(example_interfaces::msg::Int32 msg);
    void put_Stop_Button_Pressed(example_interfaces::msg::Int32 msg);
    void put_Start_Button_Pressed(example_interfaces::msg::Int32 msg);
    void put_Clinician_Request_Bolus(example_interfaces::msg::Int32 msg);
    void put_Pause_Infusion(example_interfaces::msg::Int32 msg);
    void put_Resume_Infusion(example_interfaces::msg::Int32 msg);
    void put_Turn_Off(example_interfaces::msg::Int32 msg);

    example_interfaces::msg::Int32 get_Remaining_Battery_Time();
    example_interfaces::msg::Int32 get_Using_Battery_Power();
    example_interfaces::msg::Int32 get_Prescription();
    example_interfaces::msg::Int32 get_Infusion_Flow_Rate();
    example_interfaces::msg::Int32 get_Clinician_Name();
    example_interfaces::msg::Int32 get_Patient_Name();

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_Touch(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Touch_base(MsgType msg);
    virtual void handle_Alarm(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Alarm_base(MsgType msg);
    virtual void handle_Warning(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Warning_base(MsgType msg);
    virtual void handle_System_Status(const example_interfaces::msg::Int32 msg) = 0;
    void handle_System_Status_base(MsgType msg);
    virtual void handle_Display_Message(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Display_Message_base(MsgType msg);
    virtual void handle_Sound_Type(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Sound_Type_base(MsgType msg);
    virtual void handle_Low_Battery_Warning(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Low_Battery_Warning_base(MsgType msg);
    virtual void handle_Hard_Limit_Violated(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Hard_Limit_Violated_base(MsgType msg);
    virtual void handle_Soft_Limit_Warning(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Soft_Limit_Warning_base(MsgType msg);
    virtual void handle_Patient_Request_Not_Too_Soon(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Patient_Request_Not_Too_Soon_base(MsgType msg);
    virtual void handle_Patient_Request_Too_Soon(const example_interfaces::msg::Int32 msg) = 0;
    void handle_Patient_Request_Too_Soon_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_Remaining_Battery_Time;
    std::queue<MsgType> applicationIn_Remaining_Battery_Time;
    std::queue<MsgType> infrastructureIn_Using_Battery_Power;
    std::queue<MsgType> applicationIn_Using_Battery_Power;
    std::queue<MsgType> infrastructureIn_Prescription;
    std::queue<MsgType> applicationIn_Prescription;
    std::queue<MsgType> infrastructureIn_Infusion_Flow_Rate;
    std::queue<MsgType> applicationIn_Infusion_Flow_Rate;
    std::queue<MsgType> infrastructureIn_Clinician_Name;
    std::queue<MsgType> applicationIn_Clinician_Name;
    std::queue<MsgType> infrastructureIn_Patient_Name;
    std::queue<MsgType> applicationIn_Patient_Name;
    std::queue<MsgType> infrastructureIn_Touch;
    std::queue<MsgType> applicationIn_Touch;
    std::queue<MsgType> infrastructureIn_Alarm;
    std::queue<MsgType> applicationIn_Alarm;
    std::queue<MsgType> infrastructureIn_Warning;
    std::queue<MsgType> applicationIn_Warning;
    std::queue<MsgType> infrastructureIn_System_Status;
    std::queue<MsgType> applicationIn_System_Status;
    std::queue<MsgType> infrastructureIn_Display_Message;
    std::queue<MsgType> applicationIn_Display_Message;
    std::queue<MsgType> infrastructureIn_Sound_Type;
    std::queue<MsgType> applicationIn_Sound_Type;
    std::queue<MsgType> infrastructureIn_Low_Battery_Warning;
    std::queue<MsgType> applicationIn_Low_Battery_Warning;
    std::queue<MsgType> infrastructureIn_Hard_Limit_Violated;
    std::queue<MsgType> applicationIn_Hard_Limit_Violated;
    std::queue<MsgType> infrastructureIn_Soft_Limit_Warning;
    std::queue<MsgType> applicationIn_Soft_Limit_Warning;
    std::queue<MsgType> infrastructureIn_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> applicationIn_Patient_Request_Not_Too_Soon;
    std::queue<MsgType> infrastructureIn_Patient_Request_Too_Soon;
    std::queue<MsgType> applicationIn_Patient_Request_Too_Soon;

    std::queue<MsgType> infrastructureOut_Image;
    std::queue<MsgType> applicationOut_Image;
    std::queue<MsgType> infrastructureOut_AudioSignal;
    std::queue<MsgType> applicationOut_AudioSignal;
    std::queue<MsgType> infrastructureOut_Alarm_Inactivation;
    std::queue<MsgType> applicationOut_Alarm_Inactivation;
    std::queue<MsgType> infrastructureOut_Bolus_Duration;
    std::queue<MsgType> applicationOut_Bolus_Duration;
    std::queue<MsgType> infrastructureOut_CP_Reset_Alarm;
    std::queue<MsgType> applicationOut_CP_Reset_Alarm;
    std::queue<MsgType> infrastructureOut_Confirm_Soft_Limit_Exception;
    std::queue<MsgType> applicationOut_Confirm_Soft_Limit_Exception;
    std::queue<MsgType> infrastructureOut_Reject_Soft_Limit_Exception;
    std::queue<MsgType> applicationOut_Reject_Soft_Limit_Exception;
    std::queue<MsgType> infrastructureOut_Stop_Button_Pressed;
    std::queue<MsgType> applicationOut_Stop_Button_Pressed;
    std::queue<MsgType> infrastructureOut_Start_Button_Pressed;
    std::queue<MsgType> applicationOut_Start_Button_Pressed;
    std::queue<MsgType> infrastructureOut_Clinician_Request_Bolus;
    std::queue<MsgType> applicationOut_Clinician_Request_Bolus;
    std::queue<MsgType> infrastructureOut_Pause_Infusion;
    std::queue<MsgType> applicationOut_Pause_Infusion;
    std::queue<MsgType> infrastructureOut_Resume_Infusion;
    std::queue<MsgType> applicationOut_Resume_Infusion;
    std::queue<MsgType> infrastructureOut_Turn_Off;
    std::queue<MsgType> applicationOut_Turn_Off;

    void sendOut_Image(MsgType msg);
    void sendOut_AudioSignal(MsgType msg);
    void sendOut_Alarm_Inactivation(MsgType msg);
    void sendOut_Bolus_Duration(MsgType msg);
    void sendOut_CP_Reset_Alarm(MsgType msg);
    void sendOut_Confirm_Soft_Limit_Exception(MsgType msg);
    void sendOut_Reject_Soft_Limit_Exception(MsgType msg);
    void sendOut_Stop_Button_Pressed(MsgType msg);
    void sendOut_Start_Button_Pressed(MsgType msg);
    void sendOut_Clinician_Request_Bolus(MsgType msg);
    void sendOut_Pause_Infusion(MsgType msg);
    void sendOut_Resume_Infusion(MsgType msg);
    void sendOut_Turn_Off(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Remaining_Battery_Time_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Using_Battery_Power_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Prescription_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Infusion_Flow_Rate_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Name_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Name_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Touch_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Warning_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_System_Status_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Display_Message_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Sound_Type_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Low_Battery_Warning_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Hard_Limit_Violated_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Soft_Limit_Warning_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Not_Too_Soon_subscription_;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Patient_Request_Too_Soon_subscription_;

    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Alarm_Inactivation_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Bolus_Duration_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_CP_Reset_Alarm_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Confirm_Soft_Limit_Exception_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Reject_Soft_Limit_Exception_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Stop_Button_Pressed_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Start_Button_Pressed_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_1;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Clinician_Request_Bolus_publisher_2;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Pause_Infusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Resume_Infusion_publisher_;
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_Turn_Off_publisher_;

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (wrap_pca_imp_Instance_pump_operation_control_panel_ui_process_ui_thread_base::*)(MsgType)>> outPortTupleVector;
};
