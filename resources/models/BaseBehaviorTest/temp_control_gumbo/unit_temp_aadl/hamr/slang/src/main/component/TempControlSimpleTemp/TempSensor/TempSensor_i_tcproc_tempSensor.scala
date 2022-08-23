// #Sireum #Logika

package TempControlSimpleTemp.TempSensor

import org.sireum._
// import TempControlSimpleTemp.TempControlSoftwareSystem._

// This file will not be overwritten so is safe to edit
object TempSensor_i_tcproc_tempSensor {

  // use to illustrate concept of data invariant
  // var savedTemp : Temperature_i = Temperature_i(72.0f)

  //=================================================
  //  I n i t i a l i z e    E n t r y    P o i n t
  //=================================================
  def initialise(api: TempSensor_i_Initialization_Api): Unit = {
    Contract(
      Modifies(api),  // modifies api.currentTemp
      // Robby: cannot get things to work with 'val' definitions in Defs
      // Ensures(api.currentTemp == Defs.defaultTemp)
      Ensures(api.currentTemp == Temperature_i(72.0f))
    )
    // The Initialize Entry Point must initialize all component local state and all output data ports.

    // initialize component local state
    //   (no component local state to initialize)

    // initialize output data ports
    // Robby: cannot get things to work with 'val' definitions in Defs
    // api.put_currentTemp(Defs.defaultTemp)
    // DEMO BUG:
    // api.put_currentTemp(Temperature_i(-72.0f))
    api.put_currentTemp(Temperature_i(72.0f))
    // Deduce( |- (api.currentTemp == Temperature_i(71.0f)))
  }

  //=================================================
  //  C o m p u t e    E n t r y    P o i n t
  //=================================================
  def timeTriggered(api: TempSensor_i_Operational_Api): Unit = {
    Contract(
      Modifies(api)  // modifies api.currentTemp
    )
    // read temperature from HARDWARE temperature sensor,
    // via interface realized via Slang Extension "TempSensorNative"
    var temp = TempSensorDevice.currentTempGet()
    // set the out data port currentTemp to hold the read temperature
    //  BUG - unauthorized mod of temperature data
    // val adjDegrees = temp.degrees + 13.0f // adjust temperature upward
    // temp = Temperature_i(adjDegrees)
    api.put_currentTemp(temp)
    // put an event on tempChanged out event port to
    // notify subscribers (e.g., tempControl thermostat) that the
    // temperature has changed
    api.put_tempChanged()
  }

  //=================================================
  //  D e m o   D a t a    C o n s t r a i n t
  //=================================================
  def demoTempDataConstraint(api: TempSensor_i_Operational_Api, sensor_version: Z): Unit = {
    var tempDegrees: F32 = 0.0f
    if (sensor_version == 1) {
      tempDegrees = 500.0f
    } else if (sensor_version == 2) {
      tempDegrees = -400.0f
    }
    val tempData = Temperature_i(tempDegrees)
  }

  //=================================================
  //  AADL entry points below are unused
  //=================================================
  def activate(api: TempSensor_i_Operational_Api): Unit = { }

  def deactivate(api: TempSensor_i_Operational_Api): Unit = { }

  def finalise(api: TempSensor_i_Operational_Api): Unit = { }

  def recover(api: TempSensor_i_Operational_Api): Unit = { }
}

//=================================================
//
//  Slang extension used to interface with non-Slang
//  code to retreive a temperature value.
//
//  In this case, the extension is abstracting a call
//  to underlying communication/hardware infrastructure
//  to retrieve a sensor value.
//
//  Early in development we may choose to simulate the
//  sensor.  Later we may construct a extension implementation that
//  reads from actual hardware.
//=================================================

@ext("TempSensorDevice_Ext_Sim") object TempSensorDevice {
  def currentTempGet(): Temperature_i = Contract.Only(
    Ensures(Res[Temperature_i].degrees >= -50.0f & Res[Temperature_i].degrees <= 150.0f)
  )
}

