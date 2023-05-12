// #Sireum

package bc

import org.sireum._
import org.sireum.Random.Gen64

/*
GENERATED FROM

TempUnit.scala

Temperature_impl.scala

SetPoint_impl.scala

FanAck.scala

FanCmd.scala

Base_Types.scala

DataContent.scala

*/

@datatype class Config_Z(filter: Z => B) {}

@datatype class Config_B(filter: B => B) {}

@datatype class Config_C(filter: C => B) {}

@datatype class Config_R(filter: R => B) {}

@datatype class Config_F32(filter: F32 => B) {}

@datatype class Config_F64(filter: F64 => B) {}

@datatype class Config_S8(filter: S8 => B) {}

@datatype class Config_S16(filter: S16 => B) {}

@datatype class Config_S32(filter: S32 => B) {}

@datatype class Config_S64(filter: S64 => B) {}

@datatype class Config_U8(filter: U8 => B) {}

@datatype class Config_U16(filter: U16 => B) {}

@datatype class Config_U32(filter: U32 => B) {}

@datatype class Config_U64(filter: U64 => B) {}

@datatype class Config_Base_TypesBoolean_Payload(filter: Base_Types.Boolean_Payload => B) {}

@datatype class Config_Base_TypesInteger_Payload(filter: Base_Types.Integer_Payload => B) {}

@datatype class Config_Base_TypesInteger_8_Payload(filter: Base_Types.Integer_8_Payload => B) {}

@datatype class Config_Base_TypesInteger_16_Payload(filter: Base_Types.Integer_16_Payload => B) {}

@datatype class Config_Base_TypesInteger_32_Payload(filter: Base_Types.Integer_32_Payload => B) {}

@datatype class Config_Base_TypesInteger_64_Payload(filter: Base_Types.Integer_64_Payload => B) {}

@datatype class Config_Base_TypesUnsigned_8_Payload(filter: Base_Types.Unsigned_8_Payload => B) {}

@datatype class Config_Base_TypesUnsigned_16_Payload(filter: Base_Types.Unsigned_16_Payload => B) {}

@datatype class Config_Base_TypesUnsigned_32_Payload(filter: Base_Types.Unsigned_32_Payload => B) {}

@datatype class Config_Base_TypesUnsigned_64_Payload(filter: Base_Types.Unsigned_64_Payload => B) {}

@datatype class Config_Base_TypesFloat_Payload(filter: Base_Types.Float_Payload => B) {}

@datatype class Config_Base_TypesFloat_32_Payload(filter: Base_Types.Float_32_Payload => B) {}

@datatype class Config_Base_TypesFloat_64_Payload(filter: Base_Types.Float_64_Payload => B) {}

@datatype class Config_Base_TypesCharacter_Payload(filter: Base_Types.Character_Payload => B) {}

@datatype class Config_Base_TypesString_Payload(filter: Base_Types.String_Payload => B) {}

@datatype class Config_Base_TypesBits_Payload(filter: Base_Types.Bits_Payload => B) {}

@datatype class Config_artEmpty(filter: art.Empty => B) {}

@datatype class Config_BuildingControlFanAckType(filter: BuildingControl.FanAck.Type => B) {}

@datatype class Config_BuildingControlFanCmdType(filter: BuildingControl.FanCmd.Type => B) {}

@datatype class Config_BuildingControlFanCmd_Payload(filter: BuildingControl.FanCmd_Payload => B) {}

@datatype class Config_BuildingControlFanAck_Payload(filter: BuildingControl.FanAck_Payload => B) {}

@datatype class Config_BuildingControlTempUnitType(filter: BuildingControl.TempUnit.Type => B) {}

@datatype class Config_BuildingControlTempUnit_Payload(filter: BuildingControl.TempUnit_Payload => B) {}

@datatype class Config_BuildingControlSetPoint_impl(filter: BuildingControl.SetPoint_impl => B) {}

@datatype class Config_BuildingControlSetPoint_impl_Payload(filter: BuildingControl.SetPoint_impl_Payload => B) {}

@datatype class Config_BuildingControlTemperature_impl(filter: BuildingControl.Temperature_impl => B) {}

@datatype class Config_BuildingControlTemperature_impl_Payload(filter: BuildingControl.Temperature_impl_Payload => B) {}


