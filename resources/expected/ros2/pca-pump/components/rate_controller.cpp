// rate_controller is an sporadic AADL Thread

// Ports:
  // Infusion_Flow_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Square_Bolus_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Patient_Bolus_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Basal_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // VTBI is a data port with payload PCA_Types.Drug_Volume_imp
  // Door_Open is a data port with payload Base_Types.Boolean
  // System_Status is an event data port with payload PCA_Types.Status_Type
  // Alarm is an event data port with payload PCA_Types.Alarm_Type
  // Warning is an event data port with payload PCA_Types.Warning_Type
  // CP_Bolus_Duration is an event data port with payload ICE_Types.Minute_imp
  // Begin_Infusion is an event port
  // Begin_Priming is an event port
  // End_Priming is an event port
  // Halt_Infusion is an event port
  // HW_Detected_Failure is an event port
  // Stop_Pump_Completely is an event port
  // Pump_At_KVO_Rate is an event port
  // Patient_Request_Not_Too_Soon is an event port
  // Pause_Infusion is an event port
  // Resume_Infusion is an event port
  // CP_Clinician_Request_Bolus is an event port
  // Near_Max_Drug_Per_Hour is an event port
  // Over_Max_Drug_Per_Hour is an event port
  // ICE_Stop_Pump is an event port