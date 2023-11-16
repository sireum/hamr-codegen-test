package isolette

import art.Art
import art.scheduling.static._
import isolette.Isolette_Data_Model.{Failure_Flag_impl, On_Off, Regulator_Mode, Status, TempWstatus_impl, ValueStatus}
import org.sireum._
import isolette.Regulate.{Manage_Regulator_Interface_impl_thermostat_regulate_temperature_manage_regulator_interface_SystemTestAPI => RegMRI}
import isolette.Regulate.{Manage_Heat_Source_impl_thermostat_regulate_temperature_manage_heat_source_SystemTestAPI => RegMHS}
import isolette.Regulate.{Manage_Regulator_Mode_impl_thermostat_regulate_temperature_manage_regulator_mode_SystemTestAPI => RegMRM}
// import isolette.Regulate.{Detect_Regulator_Failure_impl_thermostat_regulate_temperature_detect_regulator_failure_SystemTestAPI => nickname}
// import isolette.Monitor.{Manage_Monitor_Interface_impl_thermostat_monitor_temperature_manage_monitor_interface_SystemTestAPI => nickname}
// import isolette.Monitor.{Manage_Alarm_impl_thermostat_monitor_temperature_manage_alarm_SystemTestAPI => nickname}
// import isolette.Monitor.{Manage_Monitor_Mode_impl_thermostat_monitor_temperature_manage_monitor_mode_SystemTestAPI => nickname}
// import isolette.Monitor.{Detect_Monitor_Failure_impl_thermostat_monitor_temperature_detect_monitor_failure_SystemTestAPI => nickname}
// import isolette.Isolette.{operator_interface_thread_impl_operator_interface_oip_oit_SystemTestAPI => nickname}
// import isolette.Devices.{Temperature_Sensor_impl_temperature_sensor_cpi_thermostat_SystemTestAPI => nickname}
// import isolette.Devices.{Heat_Source_impl_heat_source_cpi_heat_controller_SystemTestAPI => nickname}

// This file will not be overwritten so is safe to edit

class SystemTestsIllustrations extends SystemTestSuite {

  // note: this is overriding SystemTestSuite's 'def scheduler: Scheduler'
  //       abstract method
  //var scheduler: StaticScheduler = Schedulers.getStaticSchedulerH(MNone())
  var scheduler: StaticScheduler = Schedulers.getStaticScheduler(
    StaticSchedulerCust.staticSchedule,
    StaticSchedulerCust.domainToBridgeIdMap,
    StaticSchedulerCust.threadNickNames,
    ISZCommandProvider(ISZ()))

  def compute(isz: ISZ[Command]): Unit = {
    scheduler = scheduler(commandProvider = ISZCommandProvider(isz :+ Stop()))

    Art.computePhase(scheduler)
  }

  // Suggestion: add the following import renamings of the components' SystemTestAPIs,
  //             replacing nickname with shortened versions that are easier to reference
  // import isolette.Regulate.{Manage_Regulator_Interface_impl_thermostat_regulate_temperature_manage_regulator_interface_SystemTestAPI => nickname}
  // import isolette.Regulate.{Manage_Heat_Source_impl_thermostat_regulate_temperature_manage_heat_source_SystemTestAPI => nickname}
  // import isolette.Regulate.{Manage_Regulator_Mode_impl_thermostat_regulate_temperature_manage_regulator_mode_SystemTestAPI => nickname}
  // import isolette.Regulate.{Detect_Regulator_Failure_impl_thermostat_regulate_temperature_detect_regulator_failure_SystemTestAPI => nickname}
  // import isolette.Monitor.{Manage_Monitor_Interface_impl_thermostat_monitor_temperature_manage_monitor_interface_SystemTestAPI => nickname}
  // import isolette.Monitor.{Manage_Alarm_impl_thermostat_monitor_temperature_manage_alarm_SystemTestAPI => nickname}
  // import isolette.Monitor.{Manage_Monitor_Mode_impl_thermostat_monitor_temperature_manage_monitor_mode_SystemTestAPI => nickname}
  // import isolette.Monitor.{Detect_Monitor_Failure_impl_thermostat_monitor_temperature_detect_monitor_failure_SystemTestAPI => nickname}
  // import isolette.Isolette.{operator_interface_thread_impl_operator_interface_oip_oit_SystemTestAPI => nickname}
  // import isolette.Devices.{Temperature_Sensor_impl_temperature_sensor_cpi_thermostat_SystemTestAPI => nickname}
  // import isolette.Devices.{Heat_Source_impl_heat_source_cpi_heat_controller_SystemTestAPI => nickname}

  test("Regulator Initialization Test") {
    Art.initializePhase(scheduler)
    // After initialization, check output values for all components in Regulator Subsystem
    // ...command to heat source should be off
    RegMHS.check_concrete_outputs(
      lastCmd = Isolette_Data_Model.On_Off.Off,
      api_heat_control = On_Off.Off)

    // regulator status is Init
    must_match(Status.Init_Status, RegMRI.get_api_regulator_status())
    // failure flag is FALSE
    must_match(Failure_Flag_impl(F), RegMRI.get_api_interface_failure())
    // regulator mode is INIT
    must_match(Regulator_Mode.Init_Regulator_Mode, RegMRM.get_api_regulator_mode())
  }

  test("Failed Status on Operator Interface") {

    // run the system's initialization phase
    Art.initializePhase(scheduler)

    // now in the computePhase
    compute(ISZ(Hstep(2)))

    // run two hyper-periods
    //StaticScheduling.staticScheduling_system_test_run(twoHPs)

    // run to Manage Regulator Interface
    compute(ISZ(RunToThread("RegMRI")))
    //StaticScheduling.staticScheduling_system_test_adv(ISZ(RunToThread("RegMRI")))

    // override inputs for MRI
    val upperDesiredTemp: F32 = 101f
    val lowerDesiredTemp: F32 = 99f
    val currentTemp: F32 = 100f

    // ToDo: wrong order for parameters below
    RegMRI.put_concrete_inputs(
      TempWstatus_impl(upperDesiredTemp, ValueStatus.Valid),
      TempWstatus_impl(lowerDesiredTemp, ValueStatus.Invalid), // force INVALID status for a temperature input
      Regulator_Mode.Normal_Regulator_Mode,
      TempWstatus_impl(currentTemp, ValueStatus.Valid))

    // run to end of current hyper-period - and check outputs of selected components
    compute(ISZ(Hstep(1)))
    //StaticScheduling.staticScheduling_system_test_adv(ISZ(Hstep(1)))

    // For RegMRM component, regulator mode output should be FAILED
    RegMRM.check_concrete_outputs(
      lastRegulatorMode = Regulator_Mode.Failed_Regulator_Mode,
      api_regulator_mode = Regulator_Mode.Failed_Regulator_Mode)

    // checked that mode output remains FAILED (it's latched)
    // run three more hyper-periods
    compute(ISZ(Hstep(3)))
    //StaticScheduling.staticScheduling_system_test_adv(ISZ(Hstep(3)))

    // regulator mode should still be failed
    RegMRM.check_concrete_outputs(
      lastRegulatorMode = Regulator_Mode.Failed_Regulator_Mode,
      api_regulator_mode = Regulator_Mode.Failed_Regulator_Mode)

    // gracefully take system down
    Art.finalizePhase(scheduler)
  }

  test("Three Hyper-periods") {
    Art.initializePhase(scheduler)

    // now in the compute phase
    compute(ISZ(Hstep(3)))

    //StaticScheduling.staticScheduling_system_test_run(twoHPs)

    Art.finalizePhase(scheduler)
  }

  test("Violate MHS Gumbo Contract") {
    // first, seed the bug at line 102 in
    // main/component/isolette/Regulate/Manage_Heat_Source_impl_thermostat_regulate_temperature_manage_heat_source.scala
    // before running this test case

    // Note that running the other test cases also uncover the bug most of the time.  This
    // is due to the random values created for current temp. However some runs of the
    // test suite without this test case do not catch the issue so a dedicated test
    // case still make sense

    Art.initializePhase(scheduler)

    // run up to RegMHS
    compute(ISZ(RunToThread("RegMHS")))

    // we'll now use RegMHS's concrete_inputs to perturb the values RegMRI sent.  Here
    // we're forcing MHS to explore the branch that will uncover the seeded bug

    RegMHS.put_concrete_inputs(
      In_lastCmd = RegMHS.get_lastCmd(),
      api_regulator_mode = Isolette_Data_Model.Regulator_Mode.Normal_Regulator_Mode,
      api_current_tempWstatus = Isolette_Data_Model.TempWstatus_impl(98f, Isolette_Data_Model.ValueStatus.Valid),
      api_lower_desired_temp = Isolette_Data_Model.Temp_impl(99f),
      api_upper_desired_temp = Isolette_Data_Model.Temp_impl(101f))

    // now we'll let RegMHS process those inputs

    compute(ISZ(Hstep(1)))

    // NOTE: if the bug is seeded then we shouldn't get here as the GUMBO compute post condition for
    //       MHS should have failed

    RegMHS.check_concrete_outputs(
      lastCmd = Isolette_Data_Model.On_Off.Onn,

      // ie. MHS must send Onn via heat_control when current_tempWstatus < lower_desired_temp
      api_heat_control = Isolette_Data_Model.On_Off.Onn
    )
  }
}
