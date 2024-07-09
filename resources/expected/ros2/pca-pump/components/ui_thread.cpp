// ui_thread is an sporadic AADL Thread

// Ports:
  // Image is a data port with payload PCA_Types.Image
  // AudioSignal is a data port with payload PCA_Types.Sound
  // Alarm_Inactivation is a data port with payload ICE_Types.Alarm_Signal
  // Remaining_Battery_Time is a data port with payload BLESS_Types.Time
  // Using_Battery_Power is a data port with payload Base_Types.Boolean
  // Prescription is a data port with payload PCA_Types.Prescription_imp
  // Infusion_Flow_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Clinician_Name is a data port with payload Base_Types.String
  // Patient_Name is a data port with payload Base_Types.String
  // Touch is an event data port with payload PCA_Types.Touch
  // Alarm is an event data port with payload PCA_Types.Alarm_Type
  // Warning is an event data port with payload PCA_Types.Warning_Type
  // System_Status is an event data port with payload PCA_Types.Status_Type
  // Display_Message is an event data port with payload PCA_Types.Message
  // Sound_Type is an event data port with payload PCA_Types.Sound
  // Bolus_Duration is an event data port with payload ICE_Types.Minute_imp
  // CP_Reset_Alarm is an event port
  // Low_Battery_Warning is an event port
  // Hard_Limit_Violated is an event port
  // Soft_Limit_Warning is an event port
  // Confirm_Soft_Limit_Exception is an event port
  // Reject_Soft_Limit_Exception is an event port
  // Stop_Button_Pressed is an event port
  // Start_Button_Pressed is an event port
  // Clinician_Request_Bolus is an event port
  // Pause_Infusion is an event port
  // Resume_Infusion is an event port
  // Turn_Off is an event port
  // Patient_Request_Not_Too_Soon is an event port
  // Patient_Request_Too_Soon is an event port