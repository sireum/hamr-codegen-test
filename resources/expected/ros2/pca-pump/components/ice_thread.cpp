// ice_thread is an sporadic AADL Thread

// Ports:
  // command_Start is an event port
  // command_Suspend is an event port
  // command_load_drug_library is an event data port with payload PCA_Types.Drug_Library
  // command_set_clinican_requested_bolus_duration is an event data port with payload ICE_Types.Minute_imp
  // command_request_bolus is an event port
  // command_pause_infusion is an event port
  // command_resume_infusion is an event port
  // parameters_current_flow_rate is a data port with payload ICE_Types.Milliliter_Per_Hour
  // parameters_basal_flow_rate is a data port with payload ICE_Types.Milliliter_Per_Hour
  // parameters_bolus_flow_rate is a data port with payload ICE_Types.Milliliter_Per_Hour
  // parameters_KVO_Flow_Rate is a data port with payload ICE_Types.Milliliter_Per_Hour
  // parameters_volume_to_be_infused is a data port with payload ICE_Types.Milliliter
  // parameters_clinican_requested_bolus_duration is a data port with payload ICE_Types.Minute_imp
  // parameters_square_flow_rate is a data port with payload ICE_Types.Milliliter_Per_Hour
  // status_On is a data port with payload Base_Types.Boolean
  // status_Okay is a data port with payload Base_Types.Boolean
  // status_AppConnected is a data port with payload Base_Types.Boolean
  // status_status is a data port with payload PCA_Types.Status_Type
  // Infusion_Flow_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Patient_Bolus_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Square_Bolus_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Basal_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // VTBI is a data port with payload PCA_Types.Drug_Volume_imp
  // Door_Open is a data port with payload Base_Types.Boolean
  // Alarm_Inactivation is a data port with payload ICE_Types.Alarm_Signal
  // Alarm is an event data port with payload PCA_Types.Alarm_Type
  // Warning is an event data port with payload PCA_Types.Warning_Type
  // CP_Bolus_Duration is an event data port with payload ICE_Types.Minute_imp
  // ICE_Stop_Pump is an event port
  // Rx_Okay is an event port
  // Patient_Request_Not_Too_Soon is an event port
  // Patient_Request_Too_Soon is an event port
  // HW_Detected_Failure is an event port
  // Stop_Pump_Completely is an event port
  // Pump_At_KVO_Rate is an event port
  // CP_Clinician_Request_Bolus is an event port
  // Halt_Infusion is an event port
  // Begin_Infusion is an event port
  // Near_Max_Drug_Per_Hour is an event port
  // Over_Max_Drug_Per_Hour is an event port