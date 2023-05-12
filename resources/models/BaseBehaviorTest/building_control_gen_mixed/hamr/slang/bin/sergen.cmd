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

// create serializers/deserializers for the Slang types used in the project

val files: ISZ[String] = ISZ("../src/main/data/bc/BuildingControl/TempUnit.scala",
                             "../src/main/data/bc/BuildingControl/Temperature_impl.scala",
                             "../src/main/data/bc/BuildingControl/SetPoint_impl.scala",
                             "../src/main/data/bc/BuildingControl/FanAck.scala",
                             "../src/main/data/bc/BuildingControl/FanCmd.scala",
                             "../src/main/data/bc/Base_Types.scala",
                             "../src/main/art/art/DataContent.scala")

val toolargs: String = st"${(files, " ")}".render

proc"$sireum tools sergen -p bc -m json,msgpack -o ${Os.slashDir.up}/src/main/data/bc $toolargs".at(Os.slashDir).console.runCheck()
