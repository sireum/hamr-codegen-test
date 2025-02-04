package org.sireum.hamr.codegen.test.microkit

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenTest.TestResources

object MicrokitTestUtil {
  val isCI: B = Os.env("GITLAB_CI").nonEmpty || Os.env("GITHUB_ACTIONS").nonEmpty || Os.env("BUILD_ID").nonEmpty

  def getAadlModels(tr: TestResources): ISZ[Os.Path] = {
    return Os.Path.walk(tr.modelsDir, T, T, p => p.name.native == "aadl" && (p.up / ".ci").exists)
  }

  val resourcesDir: Os.Path = {
    def r(p: Os.Path): Option[Os.Path] = {
      if (ops.StringOps(p.value).contains("jvm/src/test/resources/expected/CodeGenTest_Base")) {
        return Some(p.up.up)
      } else {
        for (pp <- p.list if pp.isDir) {
          r(pp) match {
            case Some(ppp) => return Some(ppp)
            case _ =>
          }
        }
        return None()
      }
    }
    r(Os.path(".")).get
  }

  val testResources: TestResources = {
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
    } else {
      val results = proc"git fetch && git status -uno".at(modelsDir.up).run()
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
