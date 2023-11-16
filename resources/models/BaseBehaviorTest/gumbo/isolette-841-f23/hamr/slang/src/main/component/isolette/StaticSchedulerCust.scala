// #Sireum
package isolette

import org.sireum._
import art.scheduling.static.Schedule
import art.scheduling.static.Schedule._


object StaticSchedulerCust {
  val maxExecutionTime: Z = 20

  // staticSchedule represents the component dispatch order
  val staticSchedule: DScheduleSpec = DScheduleSpec(0, 0, DSchedule(ISZ(
    Schedule.Slot(0, maxExecutionTime),
    Schedule.Slot(1, maxExecutionTime),
    Schedule.Slot(2, maxExecutionTime),
    Schedule.Slot(3, maxExecutionTime),
    Schedule.Slot(4, maxExecutionTime),
    Schedule.Slot(5, maxExecutionTime),
    Schedule.Slot(6, maxExecutionTime),
    Schedule.Slot(7, maxExecutionTime),
    Schedule.Slot(8, maxExecutionTime),
    Schedule.Slot(9, maxExecutionTime),
    Schedule.Slot(10, maxExecutionTime)
  )))

  val domainToBridgeIdMap: ISZ[art.Art.BridgeId] = {
    ISZ(
      /* domain 0 */ Arch.isolette_single_sensor_Instance_operator_interface_oip_oit.id,
      /* domain 1 */ Arch.isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat.id,
      /* domain 2 */ Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_detect_regulator_failure.id,
      /* domain 3 */ Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_detect_monitor_failure.id,
      /* domain 4 */ Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface.id,
      /* domain 5 */ Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode.id,
      /* domain 6 */ Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source.id,
      /* domain 7 */ Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface.id,
      /* domain 8 */ Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode.id,
      /* domain 9 */ Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm.id,
      /* domain 10 */ Arch.isolette_single_sensor_Instance_heat_source_cpi_heat_controller.id
    )
  }

  val threadNickNames: Map[String, art.Art.BridgeId] = Map(
    ISZ(
      "OpInterface" ~> Arch.isolette_single_sensor_Instance_operator_interface_oip_oit.id,
      "RegMHS" ~> Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_heat_source.id,
      "RegMRM" ~> Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_mode.id,
      "RegMRI" ~> Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_manage_regulator_interface.id,
      "MonMA" ~> Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm.id,
      "MonMMM" ~> Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_mode.id,
      "MonMMI" ~> Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_monitor_interface.id,
      "HS" ~> Arch.isolette_single_sensor_Instance_heat_source_cpi_heat_controller.id,
      "TS" ~> Arch.isolette_single_sensor_Instance_temperature_sensor_cpi_thermostat.id,
      "DRF" ~> Arch.isolette_single_sensor_Instance_thermostat_regulate_temperature_detect_regulator_failure.id,
      "DMF" ~> Arch.isolette_single_sensor_Instance_thermostat_monitor_temperature_detect_monitor_failure.id)
  )

  val revThreadNickNames: Map[art.Art.BridgeId, String] = Map.empty[art.Art.BridgeId, String] ++ (for(e <- threadNickNames.entries) yield e._2 ~> e._1)
}