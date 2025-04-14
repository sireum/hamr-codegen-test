// #Sireum

import org.sireum._

val home = Os.slashDir

val SIREUM_HOME = Os.path(Os.env("SIREUM_HOME").get)
val sireum = SIREUM_HOME / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")

val s = home / "SimpleAst.scala"
proc"$sireum tools sergen -p org.sireum.hamr.codegen.test.microkit.util -m json -o $home $s".at(home).echo.console.runCheck()
