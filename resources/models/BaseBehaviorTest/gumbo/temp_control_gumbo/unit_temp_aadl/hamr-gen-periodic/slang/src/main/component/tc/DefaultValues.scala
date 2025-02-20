// #Sireum

package tc

import org.sireum._
import tc.TempControlSoftwareSystem.SetPoint_i
import tc.TempSensor.Temperature_i
import tc.TempSensor.Unit

object DefaultValues {
  val defaultLowTemp: Temperature_i = Temperature_i(50f, Unit.Fahrenheit)
  val defaultHighTemp: Temperature_i = Temperature_i(50f, Unit.Fahrenheit)
  val defaultSetPoint: SetPoint_i = SetPoint_i(defaultLowTemp, defaultHighTemp)
}