// #Sireum

package tc.TempControlSoftwareSystem

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit

// Test vector containers for Distributed SlangCheck testing

@datatype class TempControlPeriodic_p_tcproc_tempControl_DSC_TestVector (
  val api_currentTemp: TempSensor.Temperature_i,
  val api_fanAck: CoolingFan.FanAck.Type,
  val api_setPoint: TempControlSoftwareSystem.SetPoint_i)

@datatype class TempControlPeriodic_p_tcproc_tempControl_DSC_TestVectorwL (
  val In_latestFanCmd: CoolingFan.FanCmd.Type,
  val api_currentTemp: TempSensor.Temperature_i,
  val api_fanAck: CoolingFan.FanAck.Type,
  val api_setPoint: TempControlSoftwareSystem.SetPoint_i)
