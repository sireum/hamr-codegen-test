// #Sireum

package TempControlSimpleTemp

import org.sireum._
import org.sireum.Random.Gen64

/*
GENERATED FROM

Temperature_i.scala

FanCmd.scala

FanAck.scala

SetPoint_i.scala

Base_Types.scala

TempSensor_i_tcproc_tempSensor__Containers.scala

Fan_i_tcproc_fan__Containers.scala

TempControl_i_tcproc_tempControl__Containers.scala

OperatorInterface_i_tcproc_operatorInterface__Containers.scala

DataContent.scala

Aux_Types.scala

*/

@enum object _artDataContent_DataTypeId {
   "Base_TypesBits_Payload_Id"
   "Base_TypesBoolean_Payload_Id"
   "Base_TypesCharacter_Payload_Id"
   "Base_TypesFloat_32_Payload_Id"
   "Base_TypesFloat_64_Payload_Id"
   "Base_TypesFloat_Payload_Id"
   "Base_TypesInteger_16_Payload_Id"
   "Base_TypesInteger_32_Payload_Id"
   "Base_TypesInteger_64_Payload_Id"
   "Base_TypesInteger_8_Payload_Id"
   "Base_TypesInteger_Payload_Id"
   "Base_TypesString_Payload_Id"
   "Base_TypesUnsigned_16_Payload_Id"
   "Base_TypesUnsigned_32_Payload_Id"
   "Base_TypesUnsigned_64_Payload_Id"
   "Base_TypesUnsigned_8_Payload_Id"
   "CoolingFanFanAck_Payload_Id"
   "CoolingFanFanCmd_Payload_Id"
   "CoolingFanFan_i_tcproc_fan_PostState_Container_P_Id"
   "CoolingFanFan_i_tcproc_fan_PostState_Container_PS_Id"
   "CoolingFanFan_i_tcproc_fan_PreState_Container_P_Id"
   "CoolingFanFan_i_tcproc_fan_PreState_Container_PS_Id"
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PostState_Container_P_Id"
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PostState_Container_PS_Id"
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PreState_Container_P_Id"
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PreState_Container_PS_Id"
   "TempControlSoftwareSystemSetPoint_i_Payload_Id"
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PostState_Container_P_Id"
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PostState_Container_PS_Id"
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PreState_Container_P_Id"
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PreState_Container_PS_Id"
   "TempSensorTempSensor_i_tcproc_tempSensor_PostState_Container_P_Id"
   "TempSensorTempSensor_i_tcproc_tempSensor_PostState_Container_PS_Id"
   "TempSensorTempSensor_i_tcproc_tempSensor_PreState_Container_P_Id"
   "TempSensorTempSensor_i_tcproc_tempSensor_PreState_Container_PS_Id"
   "TempSensorTemperature_i_Payload_Id"
   "_artEmpty_Id"
}

@enum object CoolingFanFan_i_tcproc_fan_PreState_Container_DataTypeId {
   "CoolingFanFan_i_tcproc_fan_PreState_Container_P_Id"
   "CoolingFanFan_i_tcproc_fan_PreState_Container_PS_Id"
}

@enum object CoolingFanFan_i_tcproc_fan_PostState_Container_DataTypeId {
   "CoolingFanFan_i_tcproc_fan_PostState_Container_P_Id"
   "CoolingFanFan_i_tcproc_fan_PostState_Container_PS_Id"
}

@enum object TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PreState_Container_DataTypeId {
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PreState_Container_P_Id"
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PreState_Container_PS_Id"
}

@enum object TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PostState_Container_DataTypeId {
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PostState_Container_P_Id"
   "TempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PostState_Container_PS_Id"
}

@enum object TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PreState_Container_DataTypeId {
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PreState_Container_P_Id"
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PreState_Container_PS_Id"
}

@enum object TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PostState_Container_DataTypeId {
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PostState_Container_P_Id"
   "TempControlSoftwareSystemTempControl_i_tcproc_tempControl_PostState_Container_PS_Id"
}

@enum object TempSensorTempSensor_i_tcproc_tempSensor_PreState_Container_DataTypeId {
   "TempSensorTempSensor_i_tcproc_tempSensor_PreState_Container_P_Id"
   "TempSensorTempSensor_i_tcproc_tempSensor_PreState_Container_PS_Id"
}

@enum object TempSensorTempSensor_i_tcproc_tempSensor_PostState_Container_DataTypeId {
   "TempSensorTempSensor_i_tcproc_tempSensor_PostState_Container_P_Id"
   "TempSensorTempSensor_i_tcproc_tempSensor_PostState_Container_PS_Id"
}
