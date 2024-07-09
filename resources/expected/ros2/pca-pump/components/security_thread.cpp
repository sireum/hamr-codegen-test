// security_thread is an sporadic AADL Thread

// Ports:
  // Clinician_Name is a data port with payload Base_Types.String
  // Patient_Name is a data port with payload Base_Types.String
  // Prescription is a data port with payload PCA_Types.Prescription_imp
  // Scan_Data is an event data port with payload PCA_Types.Scan_Data_Type
  // Authenticate_Clinician is an event port
  // Authenticate_Patient is an event port
  // Authenticate_Prescription is an event port
  // Authentication_fail is an event port
  // Authentication_pass is an event port
  // Security_Fault is an event port