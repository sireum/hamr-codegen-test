// #Sireum

package org.sireum.hamr.codegen.test.util

import org.sireum._

@enum object TestMode {
  "codegen" // implied so doesn't need to be added

  "phantom" // generate AIR model via phantom, otherwise pre-generated version will be used

  "transpile" // transpile linux and sel4 projects

  "compile" // compile Slang and Linux projects

  "camkes" // run CAmkES/ninja, also transpiles seL4 projects

  "smt2" // run smt2 solver on generated refinement proofs

  "logika" // run proyek logika on Slang projects

  "tipe" // run proyek tipe on Slang projects

  "generated_unit_tests" // run unit tests on generated Slang projects

  "verbose"
  // all = generated_unit_tests, compile, camkes
}

object TestModeHelper {
  def getEnvTestModes(): ISZ[TestMode.Type] = {
    var ret: ISZ[TestMode.Type] = ISZ()
    for(k <- ISZ(
      "HamrTestMode", "HamrTestModes",
      "Hamr_Test_Mode", "HAMR_TEST_MODE",
      "Hamr_Test_Modes", "HAMR_TEST_MODES")) {
      Os.envs.get(k) match {
        case Some(list) =>
          for (cand <- ops.StringOps(list).split((c: C) => c == ',')) {
            TestMode.byName(ops.StringOps(cand).trim) match {
              case Some(x) => ret = ret :+ x
              case _ =>
                cprintln(T, s"$cand is not a valid TestMode.  Found in env var ${k}")
            }
          }
        case _ =>
      }
    }
    return ret
  }
}
