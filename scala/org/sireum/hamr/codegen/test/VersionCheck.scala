package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.test.TestSuite

class VersionCheck extends TestSuite {
  val sireum = Os.path(Os.envs.get("SIREUM_HOME").get) / "bin" / s"sireum${if(Os.isWin) ".exe" else ""}"

  val versionChangesDetected: B = TestUtil.inIVE && !proc"$sireum slang run ${TestUtil.getCodegenDir / "bin" / "checkVersions.sc"} no-update".console.run().ok

  def ignoreVersionChanges: B = F

  registerTest("Version check")(
    if (versionChangesDetected) {
      val codegenVersions = TestUtil.getCodegenDir / "jvm" / "src" / "main" / "resources" / "codegen_versions.properties"
      if (ignoreVersionChanges) {
        eprintln(s"Warning: you've chosen to ignore changes in ${codegenVersions.toUri}")
      } else {
        assert(F, s": Resolve version changes in ${codegenVersions.toUri}")
      }
    }
  )
}
