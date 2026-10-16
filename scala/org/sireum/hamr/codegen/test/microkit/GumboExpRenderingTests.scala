package org.sireum.hamr.codegen.test.microkit

// Regression tests for SlangExpUtil's rendering of GUMBO expressions into executable Rust
// (GUMBOX) and Verus. Each GUMBO library function in models/GumboExpRendering exercises a
// shape that used to be rendered with a different meaning, or not compile:
//
//   orOverCondAnd        `(a and b) | c` was emitted as `a && b | c`, which Rust parses as
//                        `a && (b | c)` (Slang's && binds tighter than |, Rust's looser)
//   existsOr/Implies     an `exists` body `A | B` (or `A implies B`) was emitted as
//                        `range && A || B`, letting B hold outside the range
//   forallLeftOf*        a quantifier as a left operand captured the parent op and its right
//                        operand (a Verus quantifier's body extends as far right as possible)
//   twoQuantifiers       only the first quantifier of an expression got a #[trigger]; Verus
//                        rejected the second ("Could not automatically infer triggers")
//
// The tests check the generated Rust and Verus text (whitespace-normalized), and verify the
// generated crates with Verus when cargo-verus is on the PATH (cancelled otherwise).
//
// The model's AIR (sysml/.slang/Top_impl_Instance.json) is checked in; to regenerate it, run
// `sireum hamr sysml codegen` on sysml/GumboExpRendering.sysml with the AADL/HAMR SysML
// libraries on the sourcepath and `--system-name GumboExpRendering::Top_impl`. That records
// source positions as absolute file:/// URIs, which exist only on the machine that ran it and
// fail the Microkit report's position checks elsewhere: rewrite them to the OSATE-style
// `/sysml/GumboExpRendering.sysml` (resolved against workspaceRootDir) before checking it in.

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.hamr.ir.Aadl
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

class GumboExpRenderingTests extends TestSuite {

  val modelDir: Os.Path = MicrokitTestUtil.resourcesDir / "models" / "GumboExpRendering"
  val sysmlDir: Os.Path = modelDir / "sysml"
  val scratch: Os.Path = Os.tempDir() / "hamr-gumbo-exp-rendering-test"

  def loadModel(): Aadl =
    TestUtil.getModel(Some(sysmlDir / ".slang" / "Top_impl_Instance.json"), None(), sysmlDir, ISZ(), "ger", F)

  def runCodegen(model: Aadl, out: Os.Path): Reporter = {
    out.removeAll()
    val opts = MicrokitTests.baseOptions(
      workspaceRootDir = Some(sysmlDir.canon.value),
      packageName = Some("ger"),
      outputDir = Some(out.canon.value),
      slangOutputDir = Some((out / "slang").value),
      slangOutputCDir = Some((out / "c").value),
      sel4OutputDir = Some((out / "microkit").value))
    val reporter = Reporter.create
    val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
      CodegenReporting.emptyToolReport, Map.empty)
    CodeGen.codeGen(model, T, opts, ArsitPlugin.gumboEnhancedPlugins ++ MicrokitPlugins.defaultMicrokitPlugins,
      store, reporter, (_, _) => 0, _ => 0, (_, _) => 0, (_, _) => 0)
    return reporter
  }

  // Generated once and shared by the tests.
  lazy val generated: Os.Path = {
    val out = scratch / "generated"
    val r = runCodegen(loadModel(), out)
    r.printMessages()
    assert(!r.hasError, "codegen of models/GumboExpRendering reported errors")
    out / "microkit"
  }

  // The GUMBO library crate, with runs of whitespace collapsed so that the checks do not
  // depend on how the renderer breaks lines.
  lazy val libText: Predef.String = {
    val lib = generated / "crates" / "ExpLib" / "src" / "lib.rs"
    assert(lib.exists, s"$lib was not generated")
    lib.read.value.replaceAll("\\s+", " ")
  }

  // The library crate holds executable Rust (GUMBOX) before its `verus! {` block, Verus after.
  lazy val verusStart: Int = {
    val i = libText.indexOf("verus! {")
    assert(i >= 0, "no verus! block in the generated ExpLib crate")
    i
  }
  lazy val rustText: Predef.String = libText.substring(0, verusStart)
  lazy val verusText: Predef.String = libText.substring(verusStart)

  def assertRendered(text: Predef.String, kind: Predef.String, fn: Predef.String, expected: Predef.String): Unit = {
    if (!text.contains(expected)) {
      // show only the offending function, not the whole crate
      val start = text.indexOf(s"fn $fn")
      val actual = if (start < 0) "<not generated>" else text.substring(start, scala.math.min(text.length, start + 240))
      fail(s"$kind rendering of $fn:\n  expected: $expected\n  actual:   $actual ...")
    }
  }

  // ------------------------------------------------------------------------------------------
  // executable Rust (GUMBOX)

  "Rust: a short-circuit `and` under a non-short-circuit `|` is parenthesized" in {
    assertRendered(rustText, "Rust", "orOverCondAnd", "(a && b) | c")
  }

  "Rust: quantifiers render as range iterators" in {
    assertRendered(rustText, "Rust", "existsOr", "(0..=3).any(|i| (v[i] == 1u8) | (v[i] == 2u8))")
    assertRendered(rustText, "Rust", "forallLeftOfImplies", "implies!( (0..=3).all(|i| v[i] == 0u8), b)")
    assertRendered(rustText, "Rust", "forallLeftOfOr", "(0..=3).all(|i| v[i] == 0u8) | b")
    assertRendered(rustText, "Rust", "twoQuantifiers", "(0..=3).all(|i| v[i] == 0u8) & (0..=3).any(|j| v[j + 4] == 1u8)")
  }

  // ------------------------------------------------------------------------------------------
  // Verus

  "Verus: an exists body looser than the range guard is parenthesized" in {
    assertRendered(verusText, "Verus", "existsOr",
      "exists|i:int| 0 <= i <= 3 && ((#[trigger] v[i] == 1u8) || (v[i] == 2u8))")
    assertRendered(verusText, "Verus", "existsImplies",
      "exists|i:int| 0 <= i <= 3 && ((#[trigger] v[i] == 1u8) ==> (v[i + 1] == 2u8))")
  }

  "Verus: a quantifier as a left operand is parenthesized" in {
    assertRendered(verusText, "Verus", "forallLeftOfImplies",
      "(forall|i:int| 0 <= i <= 3 ==> #[trigger] v[i] == 0u8) ==> b")
    assertRendered(verusText, "Verus", "forallLeftOfOr",
      "(forall|i:int| 0 <= i <= 3 ==> #[trigger] v[i] == 0u8) || b")
  }

  "Verus: every quantifier of an expression gets a trigger" in {
    assertRendered(verusText, "Verus", "twoQuantifiers",
      "(forall|i:int| 0 <= i <= 3 ==> #[trigger] v[i] == 0u8) && exists|j:int| 0 <= j <= 3 && #[trigger] v[j + 4] == 1u8")
  }

  "Verus: the generated crates verify" in {
    if (!proc"which cargo-verus".run().ok) cancel("cargo-verus is not on the PATH")
    // the producer crate depends on ExpLib, so verifying it also checks ExpLib's spec fns
    val r = proc"make verus".at(generated / "crates" / "producer_producer").run()
    assert(r.ok, s"make verus failed:\n${r.out}\n${r.err}")
  }
}
