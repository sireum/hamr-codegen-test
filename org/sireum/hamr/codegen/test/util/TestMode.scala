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

  "generated_unit_tests" // run unit tests on generated Slang projects

  "verbose"
  // all = generated_unit_tests, compile, camkes
}
