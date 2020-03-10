// #Sireum

package org.sireum.hamr.codegen.test.util

import org.sireum._

@datatype class Resource(content: String,
                         overwrite: B,
                         makeExecutable: B)

@datatype class TestResult(map: Map[String, Resource])
