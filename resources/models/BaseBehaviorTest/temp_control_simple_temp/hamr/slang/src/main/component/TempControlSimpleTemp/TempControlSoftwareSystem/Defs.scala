// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp.TempSensor._
import TempControlSimpleTemp.CoolingFan._

//==========================================================
//  D e f s
//
//  Defines values and predicates that are derived from
//  requirements and other external stakeholder artifacts
//
//==========================================================
object Defs {

  //==================================
  // S y s t e m    C o n s t a n t s
  //==================================
  val alarmThreshold: F32 = 1.0f

  //==================================
  // I n i t i a l    V a l u e s
  //==================================
  val initialTemp: Temperature_i = Temperature_i(85f)
  @spec def initialTemp_Inv = Invariant(
    initialTemp.degrees == 85.0F
  )

  val initialSetPoint: SetPoint_i = SetPoint_i(
    Temperature_i(55f),
    Temperature_i(100f))
  @spec def initialSetPoint_Inv = Invariant(
    // initialSetPoint == Temperature_i(55f) & initialSetPoint.high == Temperature_i(100f)
    initialSetPoint == SetPoint_i(Temperature_i(55f), Temperature_i(100f))
  )

  val initialFanState: FanCmd.Type = FanCmd.Off
  @spec def initialFanState_Inv = Invariant(
    initialFanState == FanCmd.Off
  )
}
