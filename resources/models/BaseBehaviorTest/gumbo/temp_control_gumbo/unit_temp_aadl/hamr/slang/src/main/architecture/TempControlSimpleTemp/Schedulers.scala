// #Sireum
package TempControlSimpleTemp

import org.sireum._
import art.Art
import art.scheduling.legacy.Legacy
import art.scheduling.roundrobin.RoundRobin
import art.scheduling.static.Schedule.{DSchedule, DScheduleSpec, Slot}
import art.scheduling.static.StaticScheduler

// This file was auto-generated.  Do not edit

@datatype class ProcessorTimingProperties(val clockPeriod: Option[Z],
                                          val framePeriod: Option[Z],
                                          val maxDomain: Option[Z],
                                          val slotTime: Option[Z])

@datatype class ThreadTimingProperties(val domain: Option[Z],
                                       val computeExecutionTime: Option[(Z, Z)])

object Schedulers {


  val TempControlSoftwareSystem_i_Instance_tcproc_tempSensor_timingProperties: ThreadTimingProperties = ThreadTimingProperties(
    computeExecutionTime = None(),
    domain = None())

  val TempControlSoftwareSystem_i_Instance_tcproc_fan_timingProperties: ThreadTimingProperties = ThreadTimingProperties(
    computeExecutionTime = None(),
    domain = None())

  val TempControlSoftwareSystem_i_Instance_tcproc_tempControl_timingProperties: ThreadTimingProperties = ThreadTimingProperties(
    computeExecutionTime = None(),
    domain = None())

  val TempControlSoftwareSystem_i_Instance_tcproc_operatorInterface_timingProperties: ThreadTimingProperties = ThreadTimingProperties(
    computeExecutionTime = None(),
    domain = None())

  // roundRobinSchedule represents the component dispatch order
  val roundRobinSchedule: ISZ[art.Bridge] = Arch.ad.components

  val framePeriod: Z = 1000
  val numComponents: Z = Arch.ad.components.size
  val maxExecutionTime: Z = numComponents / framePeriod

  // staticSchedule represents the component dispatch order
  val staticSchedule: DScheduleSpec = DScheduleSpec(0, 0, DSchedule(ISZ(
    Slot(Arch.TempControlSoftwareSystem_i_Instance_tcproc_tempSensor.id, maxExecutionTime),
    Slot(Arch.TempControlSoftwareSystem_i_Instance_tcproc_fan.id, maxExecutionTime),
    Slot(Arch.TempControlSoftwareSystem_i_Instance_tcproc_tempControl.id, maxExecutionTime),
    Slot(Arch.TempControlSoftwareSystem_i_Instance_tcproc_operatorInterface.id, maxExecutionTime)
  )))


  def getRoundRobinScheduler(schedule: Option[ISZ[art.Bridge]]): RoundRobin = {
    if(roundRobinSchedule.isEmpty) {} // line needed for transpiler; do not remove
    schedule match {
      case Some(s) => return RoundRobin(s)
      case _ => return RoundRobin(ScheduleProviderI.getRoundRobinOrder())
    }
  }

  def getStaticScheduler(schedule: Option[DScheduleSpec]): StaticScheduler = {
    if(staticSchedule.schedule.slots.isEmpty) {} // line needed for transpiler; do not remove
    schedule match {
      case Some(s) => return StaticScheduler(Arch.ad.components, s)
      case _ => return StaticScheduler(Arch.ad.components, ScheduleProviderI.getStaticSchedule())
    }
  }

  def getLegacyScheduler(): Legacy = {
    return Legacy(Arch.ad.components)
  }
}

@ext(name = "ScheduleProvider") object ScheduleProviderI {
  def getRoundRobinOrder(): ISZ[art.Bridge] = $
  def getStaticSchedule(): DScheduleSpec = $
}