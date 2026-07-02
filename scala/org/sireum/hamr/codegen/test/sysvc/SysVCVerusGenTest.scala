package org.sireum.hamr.codegen.test.sysvc

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.containers.{SireumProyekIveOption, SireumSlangTranspilersCOption, SireumToolsSergenOption, SireumToolsSlangcheckGeneratorOption}
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.common.util.HamrCli
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.microkit.MicrokitTests
import org.sireum.hamr.ir
import org.sireum.hamr.ir.JSON
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

// Standalone driver for system-VC serialization: runs full Microkit codegen on the
// Isolette (the AADL model with a GUMBO system schedule) into a scratch directory,
// separate from the golden-file MicrokitTests, so the generated crates/sys_proof
// can be post-processed (e.g. `cargo verus verify`). Set SYSVC_OUT to control the
// output directory; otherwise a temp directory is used (its path is printed).
class SysVCVerusGenTest extends TestSuite {

  val resourcesDir: Os.Path = {
    val base = Os.path(".")
    if ((base / "hamr" / "codegen" / "jvm" / "src" / "test" / "resources").exists) {
      base / "hamr" / "codegen" / "jvm" / "src" / "test" / "resources"
    } else if ((base / "jvm" / "src" / "test" / "resources").exists) {
      base / "jvm" / "src" / "test" / "resources"
    } else {
      halt(s"Couldn't locate resources directory from: ${base.canon}")
    }
  }

  val isoletteAadlDir: Os.Path = resourcesDir / "models" / "INSPECTA-models" / "isolette" / "aadl"

  def loadModel(modelDir: Os.Path): ir.Aadl = {
    val cands = Os.Path.walk(modelDir, T, F, p => p.isFile && p.up.name.native == ".slang" && p.ext.native == "json")
    assert(cands.size == 1, s"Expected exactly one JSON file under ${modelDir.toUri}: $cands")
    JSON.toAadl(cands(0).read) match {
      case Either.Left(m) => m
      case Either.Right(m) =>
        halt(s"Json deserialization error at (${m.line}, ${m.column}): ${m.message}")
    }
  }

  val tests = Tests {

    * - {
      val outDir: Os.Path = Os.env("SYSVC_OUT") match {
        case Some(p) => Os.path(p)
        case _ => Os.tempDir()
      }
      outDir.removeAll()
      outDir.mkdirAll()

      // mirror MicrokitTests' sys_assert isolette configuration (UserLand scheduling
      // activates the system schedule plugins)
      val options = MicrokitTests.baseOptions(
        runtimeMonitoring = T,
        scheduling = HamrCli.CodegenScheduling.UserLand,
        packageName = Some("isolette"),
        outputDir = Some(outDir.value),
        slangOutputDir = Some((outDir / "slang").value),
        slangOutputCDir = Some((outDir / "c").value),
        sel4OutputDir = Some((outDir / "microkit").value),
        workspaceRootDir = Some(isoletteAadlDir.canon.value))

      val reporter = Reporter.create
      val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
        CodegenReporting.emptyToolReport, Map.empty)
      val model = loadModel(isoletteAadlDir)
      val plugins = ArsitPlugin.gumboEnhancedPlugins ++ MicrokitPlugins.defaultMicrokitPlugins

      CodeGen.codeGen(model, T, options, plugins, store, reporter,
        (_: SireumSlangTranspilersCOption, _: Reporter) => 0,
        (_: SireumProyekIveOption) => 0,
        (_: SireumToolsSergenOption, _: Reporter) => 0,
        (_: SireumToolsSlangcheckGeneratorOption, _: Reporter) => 0)

      reporter.printMessages()
      assert(!reporter.hasError, "Expecting no errors but codegen did not complete successfully")

      // one proof crate per composition: crates/sys_<composition id>_proof
      val cratesDir = outDir / "microkit" / "crates"
      val sysProofDirs = cratesDir.list.filter(p => p.isDir &&
        ops.StringOps(p.name).startsWith("sys_") && ops.StringOps(p.name).endsWith("_proof"))
      assert(sysProofDirs.nonEmpty, s"Expected at least one sys_<id>_proof crate under ${cratesDir.toUri}")

      for (sysProofDir <- sysProofDirs) {
        val sharedFiles = ISZ[String](
          "Cargo.toml", "rust-toolchain.toml",
          "src/lib.rs", "src/system_state.rs", "src/contracts.rs", "src/assertions.rs",
          "src/write_frames.rs", "src/actions.rs", "src/vc_commutativity.rs", "src/vc_integration.rs")
        for (f <- sharedFiles) {
          assert(Os.path(s"${sysProofDir.value}/$f").exists, s"Missing generated file: ${sysProofDir.name}/$f")
        }
        // per-property module groups: one folder per property under src/, each
        // containing mod.rs + assertions.rs + the four vc_*.rs modules (shared
        // modules are files, so property groups are exactly the subdirectories)
        val propDirs = (sysProofDir / "src").list.filter((p: Os.Path) => p.isDir)
        assert(propDirs.nonEmpty,
          s"${sysProofDir.name}: expected at least one per-property folder src/<p>")
        for (propDir <- propDirs) {
          val propFiles = ISZ[String](
            "mod.rs", "assertions.rs",
            "vc_init.rs", "vc_sequential.rs", "vc_post_pre.rs", "vc_non_disabling.rs")
          for (f <- propFiles) {
            assert((propDir / f).exists, s"Missing generated file: src/${propDir.name}/$f")
          }
        }

        println(s"SYS_PROOF_DIR: ${sysProofDir.canon.value}")
      }
    }
  }
}
