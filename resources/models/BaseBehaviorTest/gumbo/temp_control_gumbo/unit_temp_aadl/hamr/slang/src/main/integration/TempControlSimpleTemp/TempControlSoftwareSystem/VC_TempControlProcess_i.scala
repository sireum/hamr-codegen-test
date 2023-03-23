// #Sireum #Logika

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp.TempSensor._
import TempControlSimpleTemp.CoolingFan._

// generated from any "Defs" clause in TempSensor package
object VC_TempControlProcess_i {
  /*
    ctTStoTC: port tempSensor.currentTemp -> tempControl.currentTemp;

    ToDo:  Update the contract information below

    source port:
     TempSensor_i_tcproc_tempSensor
        guarantee tempInRange "Sensor Temperature in Range" [DerivedFrom: TempSensorReq06]:
            TempSensorRange(currentTemp);

    target port:
     TempControl_i_tcproc_tempControl
        assume currentTempRange:
           currentTemp.degrees >= -20.0F & currentTemp.degrees <= 120.0F;
 */

  //  tempSensor.currentTemp --> tempControl.currentTemp
  @pure def SensorCurrentTemp_TempControlCurrentTemp(v: Temperature_i): Unit = {
    Deduce(
      // for all values v flowing across the connection from TempSensor.currentTemp to TempControl.currentTemp,
      //  if v satisfies the guarantees specified in TempSensor,
      //  then v satisfies the requirements specified in TempControl
      TempSensor_i_Api.currentTemp_PAPred(v) |- TempControl_i_Api.currentTemp_PAPred(v)
      // TempSensor_i_Api.currentTemp_PAPredINCOMPSPEC(v) |- TempControl_i_Api.currentTemp_PAPred(v)
    )
  }

  //  tempSensor.tempChanged --> tempControl.tempChanged
  //    ??? what to do for this?   Can there be integration constraints for event ports?
  //    I don't think so there is no value to observe



  //  tempControl.fanCmd --> fan.fanCmd
  @pure def TempControlFanCmd_FanFanCmd(v: FanCmd.Type): Unit = {
    Deduce(
      TempControl_i_Api.fanCmd_PAPred(v) |- Fan_i_Api.fanCmd_PAPred(v)
    )
  }


}