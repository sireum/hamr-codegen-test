package org.sireum.hamr.codegen.test.normal

import org.sireum._
import org.sireum.hamr.codegen.common.util.HamrCli
import org.sireum.hamr.codegen.common.util.HamrCli.CodegenHamrPlatform
import org.sireum.hamr.codegen.common.util.TimeUtil
import org.sireum.hamr.codegen.test.CodegenTest
import org.sireum.hamr.codegen.test.CodegenTest.{ExpectedWarnings, TestResources, baseOptions}

/** Exact time values (hamr-codegen#12, doc/ExactTime-design.md): each model in
  * resources/models/ExactTimeTests exercises one conversion, rounding or validity rule */
class ExactTimeTests extends CodegenTest {

  override def generateExpected: B = F || super.generateExpected

  // the error cases' errors are expected; show them only in verbose mode
  override def suppressExpectedErrors: B = T

  val testResources: TestResources = CodegenTest.defaultTestLayout(getClass())

  val (jvm, sel4, microkit) = (CodegenHamrPlatform.JVM, CodegenHamrPlatform.SeL4, CodegenHamrPlatform.Microkit)

  val rounding: String = TimeUtil.timeRoundingKind

  def rounds(contains: String, count: Z): ExpectedWarnings = ExpectedWarnings(rounding, contains, count)

  case class ExactTimeTest(name: String,
                           platform: CodegenHamrPlatform.Type,
                           tweak: HamrCli.CodegenOption => HamrCli.CodegenOption,
                           expectedErrors: ISZ[String],
                           expectedWarnings: ISZ[ExpectedWarnings],
                           variant: String)

  def t(name: String, platform: CodegenHamrPlatform.Type,
        expectedErrors: ISZ[String], expectedWarnings: ISZ[ExpectedWarnings]): ExactTimeTest =
    ExactTimeTest(name, platform, o => o, expectedErrors, expectedWarnings, "")

  def tw(name: String, platform: CodegenHamrPlatform.Type, variant: String,
         tweak: HamrCli.CodegenOption => HamrCli.CodegenOption,
         expectedErrors: ISZ[String], expectedWarnings: ISZ[ExpectedWarnings]): ExactTimeTest =
    ExactTimeTest(name, platform, tweak, expectedErrors, expectedWarnings, variant)

  // the CAmkES backend's warnings that are not about rounding, e.g. a defaulted Compute_Execution_Time
  val actKind: String = org.sireum.hamr.codegen.act.util.Util.toolName

  def none: ISZ[ExpectedWarnings] = ISZ(rounds("", 0))

  val tests: ISZ[ExactTimeTest] = ISZ(
    // D5: zero time values are errors on every platform
    t("zero-times", jvm, ISZ(
      "Period of top_i_Instance.a.worker is 0, but must be greater than 0",
      "Frame_Period of top_i_Instance.proc is 0, but must be greater than 0",
      "Clock_Period of top_i_Instance.proc is 0, but must be greater than 0",
      "Slot_Time of top_i_Instance.proc is 0, but must be greater than 0"), none),

    // D5: a Compute_Execution_Time low end of 0 is valid, a high end of 0 is not
    t("cet-ranges", jvm, ISZ(
      "Compute_Execution_Time of top_i_Instance.zero.worker has a high end of 0, but it must be greater than 0"), none),

    // D4: two instances of one declaration (one position) each get a warning naming their path
    t("two-instances", sel4, ISZ(), ISZ(
      rounds("Period of top_i_Instance.p1.worker", 1), rounds("Period of top_i_Instance.p2.worker", 1), rounds("", 2))),

    // D7: a sub-ms Period is an error under the CAmkES 1 ms dispatcher calendar, not a modulo by zero
    t("dispatcher-sub-ms", sel4, ISZ(
      "Period of top_i_Instance.a.worker (Timing_Properties::Period) is 100 us, which is 0 at the 1 ms resolution of the CAmkES periodic dispatcher's 1 ms calendar"), none),

    // D7/D8: with a 3 ms Clock_Period, entries, the frame and the pacer's own slots round to ticks with
    // warnings; a thread without Compute_Execution_Time gets the 50 ms default with a warning
    t("pacer-rounding", sel4, ISZ(), ISZ(
      rounds("Compute_Execution_Time of top_i_Instance.a.worker", 1),
      rounds("Compute_Execution_Time of top_i_Instance.b.worker", 1),
      rounds("Frame_Period of top_i_Instance.proc", 1),
      rounds("The pacer's own slot for all other seL4 threads and init", 1),
      rounds("The pacer's own slot for domain 0 between components", 1),
      rounds("", 5),
      ExpectedWarnings(actKind, "top_i_Instance.b.worker has no Timing_Properties::Compute_Execution_Time", 1))),

    // D7: the CAmkES pacer needs a Clock_Period that is a whole number of ms, reported once at the
    // bound processor; the same model is fine on the JVM
    t("clock-not-whole-ms", sel4, ISZ(
      "Clock_Period of top_i_Instance.proc (Timing_Properties::Clock_Period) is 1.5 ms, but the CAmkES pacer needs a whole number of milliseconds, as seL4 ticks are TIMER_TICK_MS"),
      ISZ()),
    t("clock-not-whole-ms", jvm, ISZ(), none),

    // D7: a Compute_Execution_Time below half a Clock_Period rounds to 0 ticks, an error
    t("cet-below-half-tick", sel4, ISZ(
      "Compute_Execution_Time of top_i_Instance.a.worker (Timing_Properties::Compute_Execution_Time) is 1 ms, which is 0 at the 4 ms resolution of the CAmkES pacer's domain schedule"), none),

    // D7: with a 25 ms Clock_Period the 10 ms domain 0 slot is clamped to one tick, with a warning
    t("big-clock", sel4, ISZ(), ISZ(rounds("The pacer's own slot for domain 0 between components is 10 ms, which is 0 at the 25 ms resolution", 1), rounds("", 1))),

    // D7: entries that do not fit the Frame_Period are an error (VPM_ben used to generate a negative pad)
    t("frame-overflow", sel4, ISZ(
      "The CAmkES pacer's domain schedule needs 125 ticks (250 ms), which does not fit in Frame_Period of top_i_Instance.proc (Timing_Properties::Frame_Period) (50 ticks, 100 ms)"), none),

    // D7: entries that fill the Frame_Period exactly: the schedule has no pad entry
    t("exact-frame", sel4, ISZ(), none),

    // D7: a sub-ms Compute_Execution_Time: us domain entries, where 1500 ns rounds to 2 us with a
    // warning, and ns MCS (user-land) timeslices, where it is exact
    t("microkit-sub-ms", microkit, ISZ(), ISZ(rounds("Compute_Execution_Time of top_i_Instance.b.worker", 1), rounds("", 1))),
    tw("microkit-sub-ms", microkit, "-UserLand", o => o(scheduling = HamrCli.CodegenScheduling.UserLand), ISZ(), none),

    // D7: a Compute_Execution_Time that is 0 us in the domain schedule is an error
    t("microkit-round-zero", microkit, ISZ(
      "Compute_Execution_Time of top_i_Instance.a.worker (Timing_Properties::Compute_Execution_Time) is 400 ns, which is 0 at the 1 us resolution of the Microkit domain schedule"), none),

    // D3/D4: a Frame_Period that is not a whole us, which the monitor plugin converts again after
    // re-resolving the model, is reported once
    tw("microkit-frame-inexact", microkit, "-monitor", o => o(runtimeMonitoring = T), ISZ(),
      ISZ(rounds("Frame_Period of top_i_Instance.proc", 1), rounds("", 1))),

    // D7: domain entries that fill the Frame_Period exactly: the schedule has no padding entry
    t("microkit-exact-frame", microkit, ISZ(), none),
  )

  for (et <- tests) {
    val modelDir = testResources.modelsDir / et.name
    test(
      testName = s"${et.name}--${et.platform}${et.variant}",
      modelDir = modelDir,
      airFile = Some(modelDir / ".slang" / s"${ops.StringOps(et.name).replaceAllChars('-', '_')}_top_i_Instance.json"),
      ops = et.tweak(baseOptions(platform = et.platform)),
      description = None(),
      modelUri = None(),
      expectedErrorReasons = et.expectedErrors,
      expectedWarnings = et.expectedWarnings)
  }
}
