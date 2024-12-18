// #Sireum

package org.sireum.hamr.codegen.test.util

import org.sireum._

@enum object TestMode {
  "codegen" // implied so doesn't need to be added

  "phantom" // generate AIR model via phantom, otherwise pre-generated version will be used

  "tipe" // run proyek tipe on Slang projects

  "ive" // generate ive project info for Slang projects

  "sergen" // generate serializer/deserializers

  "slangcheck" // generate slangcheck artifacts

  "compile" // compile Slang and Linux projects

  "logika" // run proyek logika on Slang projects

  "generated_unit_tests" // run unit tests on generated Slang projects

  "transpile" // transpile linux and sel4 projects

  "camkes" // run CAmkES/ninja, also transpiles seL4 projects

  "smt2" // run smt2 solver on generated refinement proofs

  "verbose"
}

object TestModeHelper {
  def getEnvTestModes(): ISZ[TestMode.Type] = {
    var ret: ISZ[TestMode.Type] = ISZ()
    Os.env("testmodes") match {
      case Some(list) =>
        for (cand <- ops.StringOps(list).split((c: C) => c == ',')) {
          TestMode.byName(ops.StringOps(cand).trim) match {
            case Some(x) => ret = ret :+ x
            case _ =>
              halt(s"$cand is not a valid test mode.  Found in env var testmodes")
          }
        }
      case _ =>
    }
    return ret
  }
}
