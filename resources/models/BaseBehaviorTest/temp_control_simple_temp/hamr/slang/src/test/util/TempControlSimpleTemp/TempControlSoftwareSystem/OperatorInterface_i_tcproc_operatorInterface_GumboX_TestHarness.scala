// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._
import TempControlSimpleTemp.GumboXUtil.GumboXResult

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
@msig trait OperatorInterface_i_tcproc_operatorInterface_GumboX_TestHarness extends OperatorInterface_i_tcproc_operatorInterface_TestApi {
  def verbose: B

  /** Contract-based test harness for the initialise entry point
    */
  def testInitialiseCB(
      ): GumboXResult.Type = {

    if (verbose) {
      println(st"""Pre State Values:
                  """.render)
    }

    // [InvokeEntryPoint]: invoke the entry point test method
    testInitialise()

    // [RetrieveOutState]: retrieve values of the output ports via get operations and GUMBO declared local state variable
    val api_setPoint: Option[TempControlSoftwareSystem.SetPoint_i] = get_setPoint()

    if (verbose) {
      println(st"""Post State Values:
                  |  api_setPoint = ${api_setPoint.string}""".render)
    }

    // [CheckPost]: invoke the oracle function
    val postResult = TempControlSimpleTemp.TempControlSoftwareSystem.OperatorInterface_i_tcproc_operatorInterface_GumboX.inititialize_IEP_Post(api_setPoint)
    val result: GumboXResult.Type =
      if (!postResult) GumboXResult.Post_Condition_Fail
      else GumboXResult.Post_Condition_Pass

    return result
  }

  def testComputeCBJ(json: String): GumboXResult.Type = {
    TempControlSimpleTemp.JSON.toTempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PreState_Container(json) match {
      case Either.Left(o) => return testComputeCBV(o)
      case Either.Right(msg) => halt(msg.string)
    }
  }

  def testComputeCBV(o: OperatorInterface_i_tcproc_operatorInterface_PreState_Container): GumboXResult.Type = {
    return testComputeCB(o.api_tempChanged, o.api_currentTemp)
  }

  /** Contract-based test harness for the compute entry point
    * @param api_tempChanged incoming event port
    * @param api_currentTemp incoming data port
    */
  def testComputeCB(
      api_tempChanged: Option[art.Empty],
      api_currentTemp: TempSensor.Temperature_i): GumboXResult.Type = {

    // [SaveInLocal]: retrieve and save the current (input) values of GUMBO-declared local state variables as retrieved from the component state
    //   operatorInterface does not have incoming ports or state variables

    // [CheckPre]: check/filter based on pre-condition.
    val CEP_Pre_Result: B = TempControlSimpleTemp.TempControlSoftwareSystem.OperatorInterface_i_tcproc_operatorInterface_GumboX.compute_CEP_Pre (api_tempChanged, api_currentTemp)
    if (!CEP_Pre_Result) {
      return GumboXResult.Pre_Condition_Unsat
    }

    // [PutInPorts]: put values on the input ports
    if (api_tempChanged.nonEmpty) {
      put_tempChanged()
    }
    put_currentTemp(api_currentTemp)

    if (verbose) {
      println(st"""Pre State Values:
                  |  api_tempChanged = ${api_tempChanged.string}
                  |  api_currentTemp = ${api_currentTemp.string}""".render)
    }

    // [InvokeEntryPoint]: invoke the entry point test method
    testCompute()

    // [RetrieveOutState]: retrieve values of the output ports via get operations and GUMBO declared local state variable
    val api_setPoint: Option[TempControlSoftwareSystem.SetPoint_i] = get_setPoint()

    if (verbose) {
      println(st"""Post State Values:
                  |  api_setPoint = ${api_setPoint.string}""".render)
    }

    // [CheckPost]: invoke the oracle function
    val postResult = TempControlSimpleTemp.TempControlSoftwareSystem.OperatorInterface_i_tcproc_operatorInterface_GumboX.compute_CEP_Post(api_tempChanged, api_currentTemp, api_setPoint)
    val result: GumboXResult.Type =
      if (!postResult) GumboXResult.Post_Condition_Fail
      else GumboXResult.Post_Condition_Pass

    return result
  }
}
