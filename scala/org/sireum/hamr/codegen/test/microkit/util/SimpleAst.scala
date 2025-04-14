// #Sireum
package org.sireum.hamr.codegen.test.microkit.util

import org.sireum._

@sig trait Exp

@datatype class Binary(val left: Exp,
                       val op: String,
                       val right: Exp) extends Exp

@datatype class LitB(val value: String) extends Exp

@datatype class Invoke(val name: String,
                       val args: ISZ[Exp]) extends Exp
