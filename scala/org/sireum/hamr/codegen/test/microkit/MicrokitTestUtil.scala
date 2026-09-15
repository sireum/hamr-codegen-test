package org.sireum.hamr.codegen.test.microkit

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenTest.TestResources

object MicrokitTestUtil {
  val isCI: B = Os.env("GITLAB_CI").nonEmpty || Os.env("GITHUB_ACTIONS").nonEmpty || Os.env("BUILD_ID").nonEmpty

  // A model is discovered here when it carries a .ci directory, which is also INSPECTA-models'
  // own CI entry point. r2u2_monitor is excluded on both counts: R2U2MonitorTests and
  // R2U2MonitorBehaviorTests enumerate those models by hand, and their aadl/ holds one AADL
  // package per component language -- aadl/rust and aadl/c, each with its own .slang AIR --
  // rather than the single AIR the generic suites assume, so discovering them aborts
  // MicrokitTests and MicrokitBehaviorTests while they are being constructed.
  def isDiscoverableModel(p: Os.Path): B = {
    return (p.up / ".ci").exists && !p.value.native.contains(".claude") &&
      !p.value.native.contains("r2u2_monitor")
  }

  def getAadlModels(tr: TestResources): ISZ[Os.Path] = {
    return Os.Path.walk(tr.modelsDir, T, T, p => p.name.native == "aadl" && isDiscoverableModel(p))
  }

  def getSysmlModels(tr: TestResources): ISZ[Os.Path] = {
    return Os.Path.walk(tr.modelsDir, T, T, p => p.name.native == "sysml" && isDiscoverableModel(p))
  }

  lazy val resourcesDir: Os.Path = {
    val base = Os.path(".")
    if ((base / "hamr" / "codegen" / "jvm" / "src" / "test" / "resources" / "expected" / "CodeGenTest_Base").exists) {
      base / "hamr" / "codegen" / "jvm" / "src" / "test" / "resources"
    } else if ((base / "jvm" / "src" / "test" / "resources" / "expected" / "CodeGenTest_Base").exists) {
      base / "jvm" / "src" / "test" / "resources"
    } else {
      halt(s"Couldn't locate resources directory from: ${base.canon}")
    }
  }

  lazy val testResources: TestResources = {
    val modelsDir = resourcesDir / "models" / "INSPECTA-models"
    val expectedDir = resourcesDir / "expected"
    val resultsDir = resourcesDir.up / "results"

    val url = "https://github.com/loonwerks/INSPECTA-models.git"
    if (!modelsDir.exists) {
      println(s"Cloning $url ...")
      proc"git clone $url".at(modelsDir.up).runCheck()

      for (f <- Os.Path.walk(modelsDir.up, T, T, p => p.name.native == "HAMR.aadl")) {
        f.remove()
        println(s"Deleted $f")
      }
    } else if (isCI) {
      val results = Os.proc(ISZ("bash", "-c", "git fetch && git status -uno")).at(modelsDir).runCheck()
      if (ops.StringOps(results.out).contains("Your branch is behind")) {
        println(s"Updating $url")
        proc"git pull".at(modelsDir.up).runCheck()
      }
    }

    TestResources(
      resultsDir = (resultsDir / modelsDir.name).canon,
      expectedDir = (expectedDir / modelsDir.name).canon,
      modelsDir = modelsDir.canon)
  }
}
