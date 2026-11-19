package org.sireum.hamr.codegen.test.microkit

// Regression tests for which GUMBO library functions get an assume_specification, and its
// shape (GumboRustPlugin.libraryFnsWithExecSpecs / LibraryBodyScan / libraryExecSpecs).
//
// models/GumboLibrary/sysml is gumbo-verus/structs_arrays (without its //@ HAMR: lines)
// plus Collision.sysml: library Foreign's f uses arithmetic, and library Local has a
// same-named f that qualifies, a callForeign that calls Foreign's f, a callLocal that calls
// its own f, and a resultNames whose parameters are named res and res_.
//
// .slang/Sys_i_Instance.json was produced from the .sysml files, with the AADL libraries
// of structs_arrays (sysml-aadl-libraries) beside them, by
//   sireum hamr sysml codegen --platform Microkit --package-name sysml --no-proyek-ive \
//     --output-dir <out> --workspace-root-dir <dir> --sourcepath <dir> \
//     --system-name Gubmo_Structs_Arrays::Sys_i
// Regenerate it the same way after changing a .sysml file.

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

class GumboLibraryTests extends TestSuite with TestScratch {

  val sysmlDir: Os.Path = MicrokitTestUtil.resourcesDir / "models" / "GumboLibrary" / "sysml"

  // Generated once and shared by the tests.
  lazy val generated: Os.Path = {
    val out = scratchBase / "gumbo-library"
    out.removeAll()
    val model = TestUtil.getModel(Some(sysmlDir / ".slang" / "Sys_i_Instance.json"), None(), sysmlDir, ISZ(), "lib", F)
    val opts = MicrokitTests.baseOptions(
      workspaceRootDir = Some(sysmlDir.canon.value),
      packageName = Some("lib"),
      outputDir = Some(out.canon.value),
      slangOutputDir = Some((out / "slang").value),
      slangOutputCDir = Some((out / "c").value),
      sel4OutputDir = Some((out / "microkit").value))
    val reporter = Reporter.create
    val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
      CodegenReporting.emptyToolReport, Map.empty)
    CodeGen.codeGen(model, T, opts, ArsitPlugin.gumboEnhancedPlugins ++ MicrokitPlugins.defaultMicrokitPlugins,
      store, reporter, (_, _) => 0, _ => 0, (_, _) => 0, (_, _) => 0)
    reporter.printMessages()
    assert(!reporter.hasError, "codegen of models/GumboLibrary reported errors")
    out / "microkit"
  }

  def libRs(lib: String): ops.StringOps = ops.StringOps((generated / "crates" / lib / "src" / "lib.rs").read)

  "a library function that calls a same-named function of another library gets no assume_specification" in {
    val local = libRs("Local")
    assert(local.contains("pub assume_specification[ f ](x: i32) -> (res: bool)"), "Local's own f should qualify")
    assert(!local.contains("assume_specification[ callForeign ]"), "callForeign calls Foreign's f, which uses arithmetic")
    assert(local.contains("// No assume_specification, so not callable from verified code: callForeign."))
    assert(local.contains("calls something outside this library (such as a conversion\n  // or another library's function)"))
    // Foreign's f itself uses arithmetic
    assert(!libRs("Foreign").contains("assume_specification[ f ]"))
  }

  "a library function that calls its own library's function still gets one" in {
    assert(libRs("Local").contains("pub assume_specification[ callLocal ](x: i32) -> (res: bool)"))
  }

  def cargoToml(lib: String): ops.StringOps = ops.StringOps((generated / "crates" / lib / "Cargo.toml").read)

  "a library crate depends on the crates of the other libraries its functions call" in {
    assert(cargoToml("Local").contains("[dependencies]\ndata = { path=\"../data\" }\nForeign = { path = \"../Foreign\" }\n"),
      cargoToml("Local").s.value)
    // Foreign and GumboLib call no other library: only data, as before
    for (lib <- Seq("Foreign", "GumboLib")) {
      val toml = cargoToml(lib)
      assert(toml.contains("[dependencies]\ndata = { path=\"../data\" }\n\n"), toml.s.value)
      assert(!toml.contains("Local = {") && !toml.contains("Foreign = {") && !toml.contains("GumboLib = {"))
    }
  }

  "libraries that call each other in a cycle are found, and an acyclic set is not" in {
    import org.sireum.hamr.codegen.microkit.plugins.gumbo.GumboRustPlugin
    val libs = ISZ[String]("A", "B", "C", "D")
    val cyclic = Map.empty[String, Set[String]] + "A" ~> Set.empty[String].+("B") +
      "B" ~> Set.empty[String].+("C") + "C" ~> Set.empty[String].+("A")
    assert(GumboRustPlugin.libraryDependencyCycle(libs, cyclic) == Some(ISZ[String]("A", "B", "C", "A")))
    // a diamond is not a cycle
    val diamond = Map.empty[String, Set[String]] + "A" ~> (Set.empty[String] ++ ISZ[String]("B", "C")) +
      "B" ~> Set.empty[String].+("D") + "C" ~> Set.empty[String].+("D")
    assert(GumboRustPlugin.libraryDependencyCycle(libs, diamond) == None[ISZ[String]]())
  }

  "the result name differs from every parameter name" in {
    val local = libRs("Local")
    assert(local.contains("pub assume_specification[ resultNames ](res: i32, res_: i32) -> (res__: bool)"), local.s.value)
    assert(local.contains("ensures res__ == resultNames_spec(res, res_);"))
  }
}
