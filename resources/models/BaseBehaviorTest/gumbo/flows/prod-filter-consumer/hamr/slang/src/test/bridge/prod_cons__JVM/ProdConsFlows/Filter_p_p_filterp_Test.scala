package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM.ProdConsFlows._

// This file will not be overwritten so is safe to edit
class Filter_p_p_filterp_Test extends Filter_p_p_filterp_TestApi {

  test("Example Unit Test for Initialise Entry Point"){
    // Initialise Entry Point doesn't read input port values, so just proceed with
    // launching the entry point code
    testInitialise()
    // use get_XXX methods and check_concrete_output() from test/util/../YYY_TestApi
    // retrieve values from output ports and check against expected results
  }

  test("Example Unit Test for Compute Entry Point"){
    // use put_XXX methods from test/util/../YYY_TestApi to seed input ports with values
    this.put_concrete_inputs(a_in = ISZ(70f), b_in = ISZ(50f))

    testCompute()
    // use get_XXX methods and check_concrete_output() from test/util/../YYY_TestApi
    // retrieve values from output ports and check against expected results
  }
}
