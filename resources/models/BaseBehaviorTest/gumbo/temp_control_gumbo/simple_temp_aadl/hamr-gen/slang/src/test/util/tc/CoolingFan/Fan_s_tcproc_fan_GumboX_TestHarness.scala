// #Sireum

package tc.CoolingFan

import org.sireum._
import tc._
import tc.GumboXUtil.GumboXResult

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
@msig trait Fan_s_tcproc_fan_GumboX_TestHarness extends Fan_s_tcproc_fan_TestApi {
  def verbose: B

  def testComputeCBJ(json: String): GumboXResult.Type = {
    tc.JSON.toCoolingFanFan_s_tcproc_fan_PreState_Container(json) match {
      case Either.Left(o) => return testComputeCBV(o)
      case Either.Right(msg) => halt(msg.string)
    }
  }

  def testComputeCBV(o: Fan_s_tcproc_fan_PreState_Container): GumboXResult.Type = {
    return testComputeCB(o.api_fanCmd)
  }

  /** Contract-based test harness for the compute entry point
    * @param api_fanCmd incoming event data port
    */
  def testComputeCB(
      api_fanCmd: Option[CoolingFan.FanCmd.Type]): GumboXResult.Type = {

    // [SaveInLocal]: retrieve and save the current (input) values of GUMBO-declared local state variables as retrieved from the component state
    //   fan does not have incoming ports or state variables

    // [CheckPre]: check/filter based on pre-condition.
    //   fan's compute entry point does not have top level assume clauses

    // [PutInPorts]: put values on the input ports
    if (api_fanCmd.nonEmpty) {
      put_fanCmd(api_fanCmd.get)
    }

    if (verbose) {
      println(st"""Pre State Values:
                  |  api_fanCmd = ${api_fanCmd.string}""".render)
    }

    // [InvokeEntryPoint]: invoke the entry point test method
    testCompute()

    // [RetrieveOutState]: retrieve values of the output ports via get operations and GUMBO declared local state variable
    //   fan does not have outgoing ports or state variables

    // [CheckPost]: invoke the oracle function
    //   fan does not contain guarantee clauses for its compute entrypoint
    val result: GumboXResult.Type = GumboXResult.Post_Condition_Pass

    return result
  }
}