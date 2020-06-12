// #Sireum

package org.sireum.hamr.codegen.test.util

import org.sireum._

@enum object TestModes {
  'Base // gen source files
  'Base_TranspileNix // gen source files + run transpiler for nix projects
  'Base_Camkes // gen source files + run CAmkES/ninja (will run transpiler for sel4 projects)
  'Base_TranspileNix_Camkes // gen source files + run transpiler for nix projects + run CAmkES/ninja for sel4 projects
}
