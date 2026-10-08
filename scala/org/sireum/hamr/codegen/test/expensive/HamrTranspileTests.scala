package org.sireum.hamr.codegen.test.expensive

import org.scalatest.BeforeAndAfterAll
import org.sireum._
import org.sireum.hamr.codegen.common.util.HamrCli
import org.sireum.hamr.codegen.common.util.HamrCli.CodegenHamrPlatform
import org.sireum.hamr.codegen.test.CodegenTest
import org.sireum.hamr.codegen.test.CodegenTest.{TestResources, baseOptions}
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}

class HamrTranspileTests extends CodegenTest with BeforeAndAfterAll {

  override def generateExpected: B = F || super.generateExpected

  val isKekinianCi: B = {
    Os.env("GITHUB_REPOSITORY") match {
      case Some(r) if r == string"sireum/kekinian" =>
        val buildcmd = TestUtil.getCodegenDir / "bin" / "build.cmd"
        val results = proc"$buildcmd install-sbt-mill".at(TestUtil.getCodegenDir).run()
        if (!results.ok) {
          println(results.err)
          assert(F, s"${getClass.getName} attempt to install sbt and mill failed: ${results.exitCode}")
        }
        T
      case _ => F
    }
  }

  override def testModes: ISZ[TestMode.Type] = {
    (super.testModes :+ TestMode.sergen :+ TestMode.slangcheck) ++ (
      // if we're kekinian and on github then also compile proyek projects via sbt and mill
      // so that regressions introduced by changes to sireum's dependencies, e.g. Java,
      // are caught when they are pushed
      if (isKekinianCi) ISZ(TestMode.compile)
      else ISZ())
  }

  val testResources: TestResources = CodegenTest.defaultTestLayout(getClass())

  // also exercise the legacy scheduler build (one process per thread) for the Linux tests
  override def runLegacy(testName: String): B = ops.StringOps(testName).endsWith("--Linux")

  val (linux, sel4, sel4_tb, sel4_only) = (CodegenHamrPlatform.Linux, CodegenHamrPlatform.SeL4, CodegenHamrPlatform.SeL4_TB, CodegenHamrPlatform.SeL4_Only)

  case class TranspileTest(name: String, modelDir: Os.Path, airFile: Os.Path, platforms: ISZ[CodegenHamrPlatform.Type],
                           tweak: HamrCli.CodegenOption => HamrCli.CodegenOption)

  def gen(name: String, dir: Os.Path, json: String, platforms: ISZ[CodegenHamrPlatform.Type]): TranspileTest = {
    return genWith(name, dir, json, platforms, o => o)
  }

  def genWith(name: String, dir: Os.Path, json: String, platforms: ISZ[CodegenHamrPlatform.Type],
              tweak: HamrCli.CodegenOption => HamrCli.CodegenOption): TranspileTest = {
    val modelDir = dir / name
    val testName = name.native.replaceAll("/", "__")
    return TranspileTest(testName, modelDir, modelDir / ".slang" / json, platforms, tweak)
  }

  val tests: ISZ[TranspileTest] = ISZ(
    gen("building_control_gen_mixed", testResources.modelsDir, "BuildingControl_BuildingControlDemo_i_Instance.json", ISZ(linux)),

    gen("attestation-gate", testResources.modelsDir, "SysContext_top_Impl_Instance.json", ISZ(sel4)),

    // https://github.com/sireum/hamr-codegen/issues/13 -- IS[Z,art.Art.PortId] is sized to the largest
    // port partition (1 here) so ART must not concatenate the event and data out port id sequences
    gen("port-partition-capacity", testResources.modelsDir, "HamrIssueRepro_RootSystem_impl_Instance.json", ISZ(linux)),

    // https://github.com/sireum/hamr-codegen/issues/12 -- the reporter's model: a 100 us Period was
    // floored to 0 ms; it must reach ART as Periodic(period = s64"100000")
    gen("period-100us", testResources.modelsDir, "HamrIssueRepro_RootSystem_impl_Instance.json", ISZ(linux)),

    // #12: periods and a Frame_Period over 2^31 ns survive a 32-bit --bit-width build (Art.Time is S64)
    genWith("long-period-32bit", testResources.modelsDir, "LongPeriod_RootSystem_impl_Instance.json", ISZ(linux),
      o => o(bitWidth = 32)),

    // #12: a periodic device and a sporadic thread without Period get the 1 ms default, in ns,
    // including the legacy apps' sleeps
    gen("default-period", testResources.modelsDir, "DefaultPeriod_RootSystem_impl_Instance.json", ISZ(linux)),
  )

  for (proj <- tests) {
    for (platform <- proj.platforms) {
      // append classname so it doesn't use the expected results from the 'normal' tests
      val testName = s"${getClass.getSimpleName}_${proj.name}--${platform}"
      val ops = proj.tweak(baseOptions(
        platform = platform,
        runTranspiler = T))
      test(
        testName = testName,
        modelDir = proj.modelDir,
        airFile = Some(proj.airFile),
        ops = ops,
        description = None(),
        modelUri = None(),
        expectedErrorReasons = ISZ())
    }
  }

  override def afterAll(): Unit = {
    if (Os.isWin && isKekinianCi) {
      val binDir = TestUtil.getCodegenDir / "bin" / "win"
      val resultsDir = TestUtil.getCodegenDir / "jvm" / "src" / "test" / "results"
      if (binDir.exists) {
        binDir.removeAll()
        println(s"Removed ${binDir}")
      }
      if (resultsDir.exists) {
        resultsDir.removeAll()
        println(s"Removed $resultsDir")
      }
    }
  }
}
