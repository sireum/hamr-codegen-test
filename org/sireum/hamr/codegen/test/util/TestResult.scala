// #Sireum

package org.sireum.hamr.codegen.test.util

import org.sireum._

@datatype class Resource(content: String)

@datatype class TestResult(map: Map[String, Resource])
