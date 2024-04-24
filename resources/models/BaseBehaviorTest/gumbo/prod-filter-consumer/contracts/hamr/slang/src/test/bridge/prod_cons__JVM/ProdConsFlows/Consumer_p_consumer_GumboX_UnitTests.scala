package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM.GumboXUtil.GumboXResult
import prod_cons__JVM.util.{Container, UnitTestConfigurationBatch}
import prod_cons__JVM.ProdConsFlows.Consumer_p_consumer_UnitTestConfiguration_Util._

// This file will not be overwritten so is safe to edit

class Consumer_p_consumer_GumboX_UnitTests extends Consumer_p_consumer_GumboX_TestHarness_ScalaTest {

  // set verbose to T to see pre/post state values and generated unit tests
  // that can be copied/pasted to replay a test
  val verbose: B = F

  // set failOnUnsatPreconditions to T if the unit tests should fail when either
  // SlangCheck is never able to satisfy a datatype's filter or the generated
  // test vectors are never able to satisfy an entry point's assume pre-condition
  val failOnUnsatPreconditions: B = F

  def configs: MSZ[UnitTestConfigurationBatch] = {
    return MSZ(
      defaultComputeConfig(verbose = verbose, failOnUnsatPreconditions = failOnUnsatPreconditions)
    )
  }


  for (c <- configs) {
    def next: Option[Container] = {
      try {
        c.profile.next match {
          case (cp: Consumer_p_consumer_PreState_Container) =>
            // only allow one incoming event
            if ((cp.api_f_event_data_in.nonEmpty |^ cp.api_g_event_data_in.nonEmpty |^ cp.api_h_event_in.nonEmpty) &&
              !(cp.api_f_event_data_in.nonEmpty && cp.api_g_event_data_in.nonEmpty && cp.api_h_event_in.nonEmpty))
              return Some(cp)
            else return None()
          case c =>
            return Some(c)
        }
      } catch {
        case e: AssertionError => // SlangCheck was unable to satisfy a datatype's filter
          return None()
      }
    }

    for (i <- 0 until c.numTests) {
      val testName = s"${c.name}_$i"

      this.registerTest(testName) {
        var retry: B = T

        var j: Z = 0
        while (j < c.numTestVectorGenRetries && retry) {
          next match {
            case Some(o) =>

              if (verbose && j > 1) {
                println(s"Retry $j:")
              }

              val results = c.test(o)

              if (verbose) {
                c.genReplay(o, testName, results) match {
                  case Some(s) => println(s)
                  case _ =>
                }
              }

              results match {
                case GumboXResult.Pre_Condition_Unsat =>
                case GumboXResult.Post_Condition_Fail =>
                  fail("Post condition did not hold")
                  retry = F
                case GumboXResult.Post_Condition_Pass =>
                  if (verbose) {
                    println("Success!")
                  }
                  retry = F
              }
            case _ =>

          }
          j = j + 1
        }

        if (retry) {
          if (c.failOnUnsatPreconditions) {
            fail("Unable to satisfy precondition")
          } else if (verbose) {
            cprintln(T, "Unable to satisfy precondition")
          }
        }
      }
    }
  }

  def configsToJson: String = {
    return st"[ ${(for (c <- configs) yield s"\"${c.name}|${c.description}\"", ", ")} ]".render
  }
}
