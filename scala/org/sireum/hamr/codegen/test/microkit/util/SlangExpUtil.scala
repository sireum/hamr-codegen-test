// #Sireum
package org.sireum.hamr.codegen.test.microkit.util

import org.sireum._

object Util {
  val testDir: Os.Path = {
    val base = Os.path(".")
    if ((base / "hamr" / "codegen" / "jvm" / "src" / "test" / "resources" / "expected" / "CodeGenTest_Base").exists) {
      base / "hamr" / "codegen" / "jvm" / "src" / "test"
    } else if ((base / "jvm" / "src" / "test" / "resources" / "expected" / "CodeGenTest_Base").exists) {
      base / "jvm" / "src" / "test"
    } else {
      halt(s"Couldn't locate test directory from: ${base.canon}")
    }
  }
}