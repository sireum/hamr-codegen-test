// prescription_checker is an sporadic AADL Thread

// Ports:
  // Prescription is a data port with payload PCA_Types.Prescription_imp
  // VTBI is a data port with payload PCA_Types.Drug_Volume_imp
  // Square_Bolus_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Patient_Bolus_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Basal_Rate is a data port with payload PCA_Types.Flow_Rate_imp
  // Minimum_Time_Between_Bolus is a data port with payload ICE_Types.Minute_imp
  // Max_Drug_Per_Hour is a data port with payload PCA_Types.Drug_Volume_imp
  // Get_Drug_Record is an event data port with payload PCA_Types.Drug_Code_imp
  // The_Drug_Record is an event data port with payload PCA_Types.Drug_Record_imp
  // Check_Rx is an event port
  // Rx_Okay is an event port
  // Drug_Not_In_Library is an event port
  // Confirm_Soft_Limit_Exception is an event port
  // Reject_Soft_Limit_Exception is an event port
  // Soft_Limit_Warning is an event port
  // Hard_Limit_Violated is an event port