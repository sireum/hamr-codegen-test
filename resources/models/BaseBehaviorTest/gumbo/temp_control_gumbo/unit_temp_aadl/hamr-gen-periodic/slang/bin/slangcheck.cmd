::/*#! 2> /dev/null                                   #
@ 2>/dev/null # 2>nul & echo off & goto BOF           #
if [ -z ${SIREUM_HOME} ]; then                        #
  echo "Please set SIREUM_HOME env var"               #
  exit -1                                             #
fi                                                    #
exec ${SIREUM_HOME}/bin/sireum slang run "$0" "$@"    #
:BOF
setlocal
if not defined SIREUM_HOME (
  echo Please set SIREUM_HOME env var
  exit /B -1
)
%SIREUM_HOME%\\bin\\sireum.bat slang run "%0" %*
exit /B %errorlevel%
::!#*/
// #Sireum

import org.sireum._

val sireum = Os.path(Os.env("SIREUM_HOME").get) / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")

// create SlangCheck generators for the types used in the project

val slangCheckJar: Os.Path = {
  Os.env("SLANG_CHECK_JAR") match {
    case Some(p) =>
      val cand = Os.path(p)
      if (!cand.exists) {
        halt(s"SLANG_CHECK_JAR is not a file: $p")
      } else {
        cand
      }
    case _ => halt(s"SLANG_CHECK_JAR is not defined")
  }
}

val files: ISZ[String] = ISZ("../src/main/data/tc/TempSensor/Unit.scala",
                             "../src/main/data/tc/TempSensor/Temperature_i.scala",
                             "../src/main/data/tc/CoolingFan/FanCmd.scala",
                             "../src/main/data/tc/CoolingFan/FanAck.scala",
                             "../src/main/data/tc/TempControlSoftwareSystem/SetPoint_i.scala",
                             "../src/main/data/tc/Base_Types.scala",
                             "../src/main/component/tc/GUMBO_Definitions/GUMBO__Library.scala",
                             "../src/main/component/tc/TempSensor/GUMBO__Library.scala",
                             "../src/main/data/tc/TempSensor/TempSensorPeriodic_p_tcproc_tempSensor_DSC_TestVectors.scala",
                             "../src/main/data/tc/CoolingFan/FanPeriodic_p_tcproc_fan_DSC_TestVectors.scala",
                             "../src/main/data/tc/TempControlSoftwareSystem/TempControlPeriodic_p_tcproc_tempControl_DSC_TestVectors.scala",
                             "../src/main/data/tc/TempControlSoftwareSystem/OperatorInterfacePeriodic_p_tcproc_operatorInterface_DSC_TestVectors.scala",
                             "../src/main/art/art/DataContent.scala")

val toolargs: String = st"${(files, " ")}".render

proc"java -jar $slangCheckJar tools slangcheck -p tc -o ../src/main/data/tc $toolargs".at(Os.slashDir).console.runCheck()
