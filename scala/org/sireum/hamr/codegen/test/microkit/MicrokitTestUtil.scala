package org.sireum.hamr.codegen.test.microkit

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenTest.TestResources

object MicrokitTestUtil {
  val isCI: B = Os.env("GITLAB_CI").nonEmpty || Os.env("GITHUB_ACTIONS").nonEmpty || Os.env("BUILD_ID").nonEmpty

  def getAadlModels(tr: TestResources): ISZ[Os.Path] = {
    return Os.Path.walk(tr.modelsDir, T, T, p => p.name.native == "aadl" && (p.up / ".ci").exists)
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
