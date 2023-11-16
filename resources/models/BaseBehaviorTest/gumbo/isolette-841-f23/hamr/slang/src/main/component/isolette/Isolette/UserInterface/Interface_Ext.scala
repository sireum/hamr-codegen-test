package isolette.Isolette.UserInterface

import isolette.Isolette_Data_Model.TempWstatus_impl
import isolette._
import org.sireum._

import java.awt.GraphicsEnvironment
import java.util.concurrent.atomic.AtomicReference

object Interface_Ext {

  // Alternatively could implement gui directly here rather than
  // doing pass-throughs

  val form: Option[Gui] =
    if (GraphicsEnvironment.isHeadless) None()
    else Some(new Gui())

  var lowerDesiredTempWstatus: AtomicReference[Isolette_Data_Model.TempWstatus_impl] = new AtomicReference[TempWstatus_impl]()
  var upperDesiredTempWstatus: AtomicReference[Isolette_Data_Model.TempWstatus_impl] = new AtomicReference[TempWstatus_impl]()
  var lowerAlarmTempWstatus: AtomicReference[Isolette_Data_Model.TempWstatus_impl] = new AtomicReference[TempWstatus_impl]()
  var upperAlarmTempWstatus: AtomicReference[Isolette_Data_Model.TempWstatus_impl] = new AtomicReference[TempWstatus_impl]()

  def initialise(_lowerDesiredTempWstatus: Isolette_Data_Model.TempWstatus_impl,
                 _upperDesiredTempWstatus: Isolette_Data_Model.TempWstatus_impl,
                 _lowerAlarmTempWstatus: Isolette_Data_Model.TempWstatus_impl,
                 _upperAlarmTempWstatus: Isolette_Data_Model.TempWstatus_impl): Unit = {
    lowerDesiredTempWstatus.set(_lowerDesiredTempWstatus)
    upperDesiredTempWstatus.set(_upperDesiredTempWstatus)
    lowerAlarmTempWstatus.set(_lowerAlarmTempWstatus)
    upperAlarmTempWstatus.set(_upperAlarmTempWstatus)

    form match {
      case Some(f) =>
        f.init(
          lowerDesiredTempWstatus.get(),
          upperDesiredTempWstatus.get(),
          lowerAlarmTempWstatus.get(),
          upperAlarmTempWstatus.get())
      case _ =>
    }
  }

  def finalise(): Unit = {
    form match {
      case Some(f) => f.frame.dispose()
      case _ =>
    }
  }

  def setRegulatorStatus(v: Option[Isolette_Data_Model.Status.Type]): Unit = {
    form match {
      case Some(f) => f.setRegulatorStatus(v)
      case _ =>
    }
  }

  def setMonitorStatus(v: Option[Isolette_Data_Model.Status.Type]): Unit = {
    form match {
      case Some(f) => f.setMonitorStatus(v)
      case _ =>
    }
  }

  def setDispayTemperature(v: Option[Isolette_Data_Model.Temp_impl]): Unit = {
    form match {
      case Some(f) => f.setDisplayTemperature(v)
      case _ =>
    }
  }

  def setAlarmControl(v: Option[Isolette_Data_Model.On_Off.Type]): Unit = {
    form match {
      case Some(f) => f.setAlarmControl(v)
      case _ =>
    }
  }


  def getLowerDesiredTempWstatus(): Isolette_Data_Model.TempWstatus_impl = {
    return lowerDesiredTempWstatus.get()
  }

  def getUpperDesiredTempWstatus(): Isolette_Data_Model.TempWstatus_impl = {
    return upperDesiredTempWstatus.get()
  }

  def getLowerAlarmTempWstatus(): Isolette_Data_Model.TempWstatus_impl = {
    return lowerAlarmTempWstatus.get()
  }

  def getUpperAlarmTempWstatus(): Isolette_Data_Model.TempWstatus_impl = {
    return upperAlarmTempWstatus.get()
  }
}
