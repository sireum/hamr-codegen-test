// #Sireum

package org.sireum.hamr.codegen.test.util

import org.sireum._

@enum object TestMode {
  "codegen" // implied so doesn't need to be added

  "transpile" // transpile linux and sel4 projects

  "compile" // compile Slang and Linux projects

  "camkes" // run CAmkES/ninja, also transpiles seL4 projects

  "generated_unit_tests" // run unit tests on generated Slang projects

  // all = generated_unit_tests, compile, camkes
}
