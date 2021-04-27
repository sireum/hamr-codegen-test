// #Sireum

package org.sireum.hamr.codegen.test.util

import org.sireum._

@enum object TestMode {
  "Codegen" // gen source files

  "Transpile"    // gen source files + run transpiler for nix and sel4 projects
  "TranspileNix" // gen source files + run transpiler only for nix projects

  "Camkes" // gen source files + run CAmkES/ninja (will run transpiler for sel4 projects)
  "Camkes_TranspileNix" // gen source files + run transpiler for nix projects + run CAmkES/ninja for sel4 projects
}
