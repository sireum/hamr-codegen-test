// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM.GumboXUtil.GumboXResult
import prod_cons__JVM.RandomLib
import org.sireum.Random.Gen64
import org.sireum.Random.Impl.Xoshiro256

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Distribute SlangCheck test runners

@record class Filter_p_p_filterp_GumboX_DSC_TestRunner
  extends Random.Gen.TestRunner[Filter_p_p_filterp_DSC_TestVector]
  with Filter_p_p_filterp_GumboX_TestHarness {

  val verbose: B = F

  val seedGen: Gen64 = Random.Gen64Impl(Xoshiro256.create)
  val ranLibd_event_in: RandomLib = RandomLib(Random.Gen64Impl(Xoshiro256.createSeed(seedGen.genU64())))
  val ranLibb_event_data_in: RandomLib = RandomLib(Random.Gen64Impl(Xoshiro256.createSeed(seedGen.genU64())))
  val ranLibc_event_data_in: RandomLib = RandomLib(Random.Gen64Impl(Xoshiro256.createSeed(seedGen.genU64())))
  val ranLiba_data_in: RandomLib = RandomLib(Random.Gen64Impl(Xoshiro256.createSeed(seedGen.genU64())))

  override def next(): Filter_p_p_filterp_DSC_TestVector = {
    val api_d_event_in = ranLibd_event_in.nextOption_artEmpty()
    val api_b_event_data_in = ranLibb_event_data_in.nextOptionProdConsFlowsContainer_i()
    val api_c_event_data_in = ranLibc_event_data_in.nextOptionProdConsFlowsContainer_i()
    val api_a_data_in = ranLiba_data_in.nextProdConsFlowsContainer_i()
    return Filter_p_p_filterp_DSC_TestVector(
      api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in
    )
  }

  override def toCompactJson(o: Filter_p_p_filterp_DSC_TestVector): String = {
    return prod_cons__JVM.JSON.fromProdConsFlowsFilter_p_p_filterp_DSC_TestVector(o, T)
  }

  override def fromJson(json: String): Filter_p_p_filterp_DSC_TestVector = {
    prod_cons__JVM.JSON.toProdConsFlowsFilter_p_p_filterp_DSC_TestVector(json) match {
      case Either.Left(o) => return o
      case Either.Right(msg) => halt(msg.string)
    }
  }

  override def test(o: Filter_p_p_filterp_DSC_TestVector): B = {
    BeforeEntrypoint()
    val r: B = testComputeCB(o.api_d_event_in, o.api_b_event_data_in, o.api_c_event_data_in, o.api_a_data_in) match {
      case GumboXResult.Pre_Condition_Unsat =>
        prod_cons__JVM.DSC_RecordUnsatPre.report(prod_cons__JVM.JSON.fromProdConsFlowsFilter_p_p_filterp_DSC_TestVector(o, T))
        T
      case GumboXResult.Post_Condition_Fail => F
      case GumboXResult.Post_Condition_Pass => T
    }
    AfterEntrypoint()
    return r
  }
}