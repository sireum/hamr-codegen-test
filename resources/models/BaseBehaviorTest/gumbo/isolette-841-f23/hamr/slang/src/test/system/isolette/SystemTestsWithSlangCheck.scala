package isolette

import art.scheduling.static._
import art.{Art, ArtNative_Ext}
import isolette.Regulate.{Manage_Heat_Source_impl_thermostat_regulate_temperature_manage_heat_source_SystemTestAPI => RegMHS}
import org.sireum.Random.Gen64
import org.sireum.Random.Impl.Xoshiro256
import org.sireum._

import java.io.{OutputStream, PrintStream}
// import isolette.Regulate.{Detect_Regulator_Failure_impl_thermostat_regulate_temperature_detect_regulator_failure_SystemTestAPI => nickname}
// import isolette.Monitor.{Manage_Monitor_Interface_impl_thermostat_monitor_temperature_manage_monitor_interface_SystemTestAPI => nickname}
// import isolette.Monitor.{Manage_Alarm_impl_thermostat_monitor_temperature_manage_alarm_SystemTestAPI => nickname}
// import isolette.Monitor.{Manage_Monitor_Mode_impl_thermostat_monitor_temperature_manage_monitor_mode_SystemTestAPI => nickname}
// import isolette.Monitor.{Detect_Monitor_Failure_impl_thermostat_monitor_temperature_detect_monitor_failure_SystemTestAPI => nickname}
// import isolette.Isolette.{operator_interface_thread_impl_operator_interface_oip_oit_SystemTestAPI => nickname}
// import isolette.Devices.{Temperature_Sensor_impl_temperature_sensor_cpi_thermostat_SystemTestAPI => nickname}
// import isolette.Devices.{Heat_Source_impl_heat_source_cpi_heat_controller_SystemTestAPI => nickname}

class SystemTestsWithSlangCheck extends SystemTestSuite {

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

  override def beforeEach(): Unit = {
    // disable the various guis
    System.setProperty("java.awt.headless", "true")

    // suppress the log stream
    ArtNative_Ext.logStream = new PrintStream(new OutputStream {
      override def write(b: Int): Unit = {}
    })

    super.beforeEach()
  }

  def seedGen: Gen64 = Random.Gen64Impl(Xoshiro256.create)

  def freshRandomLib: RandomLib = RandomLib(Random.Gen64Impl(Xoshiro256.createSeed(seedGen.genU64())))

  for (i <- 0 until 100) {
    registerTest(s"Violate MHS REQ_MHS_2 $i") {
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

      // helper method to customize a random lib's F32 config
      def c32(low: Option[F32], high: Option[F32], ranLib: RandomLib): RandomLib = {
        ranLib.set_Config_F32(ranLib.get_Config_F32(low = low, high = high))
        return ranLib
      }

      // helper method to customize a random lib's Value config
      def cData_ModelValueStatus(filter: Isolette_Data_Model.ValueStatus.Type => B, ranLib: RandomLib): RandomLib = {
        ranLib.set_Config_Isolette_Data_ModelValueStatusType(
          ranLib.get_Config_Isolette_Data_ModelValueStatusType(filter = filter)
        )
        return ranLib
      }

      val low: Isolette_Data_Model.Temp_impl = c32(
        low = Some(InitialValues.LOWER_DESIRED_TEMPERATURE_LOWER_RANGE),
        high = Some(InitialValues.LOWER_DESIRED_TEMPERATURE_UPPER_RANGE),
        ranLib = freshRandomLib
      ).nextIsolette_Data_ModelTemp_impl()

      val high: Isolette_Data_Model.Temp_impl = c32(
        low = Some(
          if (low.value > InitialValues.UPPER_DESIRED_TEMPERATURE_LOWER_RANGE) low.value + f32"0.1"
          else InitialValues.UPPER_DESIRED_TEMPERATURE_LOWER_RANGE),
        high = Some(InitialValues.UPPER_DESIRED_TEMPERATURE_UPPER_RANGE),
        ranLib = freshRandomLib
      ).nextIsolette_Data_ModelTemp_impl()

      val currentTemp: Isolette_Data_Model.TempWstatus_impl =
        cData_ModelValueStatus(
          filter = randomlyGeneratedValue => randomlyGeneratedValue == Isolette_Data_Model.ValueStatus.Valid,
          ranLib = c32(
            low = None(),
            high = Some(low.value - f32"0.1"),
            ranLib = freshRandomLib
          )
        ).nextIsolette_Data_ModelTempWstatus_impl()

      /*
      RegMHS.put_concrete_inputs(
        In_lastCmd = RegMHS.get_lastCmd(),
        api_regulator_mode = Isolette_Data_Model.Regulator_Mode.Normal_Regulator_Mode,
        api_current_tempWstatus = Isolette_Data_Model.TempWstatus_impl(98f, Isolette_Data_Model.ValueStatus.Valid),
        api_lower_desired_temp = Isolette_Data_Model.Temp_impl(99f),
        api_upper_desired_temp = Isolette_Data_Model.Temp_impl(101f))
      */
      RegMHS.put_concrete_inputs(
        In_lastCmd = RegMHS.get_lastCmd(),
        api_regulator_mode = Isolette_Data_Model.Regulator_Mode.Normal_Regulator_Mode,
        api_current_tempWstatus = currentTemp,
        api_lower_desired_temp = low,
        api_upper_desired_temp = high
      )

      print("\u001B[1;32m")
      print(
        st"""cTemp = $currentTemp)
            |low   = $low
            |high  = $high""".render)
      println("\u001B[0m")

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
}
