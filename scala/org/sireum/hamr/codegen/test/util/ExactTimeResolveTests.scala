package org.sireum.hamr.codegen.test.util

import org.sireum._
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.symbols.SymbolTable
import org.sireum.hamr.codegen.common.util.HamrCli.CodegenHamrPlatform
import org.sireum.hamr.codegen.common.util.ModelUtil
import org.sireum.hamr.codegen.test.CodegenTest.baseOptions
import org.sireum.hamr.ir
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

/** Time properties that AADL cannot express, so the ExactTimeTests models cannot hold them: the
  * models' AIR is patched in memory and resolved (SymbolResolver, then the linter) directly.
  * Resolving the AIR, rather than running a CodegenTest, keeps these tests independent of phantom
  * mode, which regenerates the AIR from the AADL. (doc/ExactTime-design.md, D2, D5) */
class ExactTimeResolveTests extends TestSuite {

  val modelsDir: Os.Path = TestUtil.getCodegenDir / "jvm" / "src" / "test" / "resources" / "models" / "ExactTimeTests"

  def load(name: Predef.String): ir.Aadl = {
    val json = modelsDir / name / ".slang" / s"${name.replace('-', '_')}_top_i_Instance.json"
    ir.JSON.toAadl(json.read) match {
      case Either.Left(m) => m
      case Either.Right(e) => halt(s"Could not read $json: ${e.message}")
    }
  }

  def isProp(p: ir.Property, propName: Predef.String): B = p.name.name(p.name.name.size - 1) == String(propName)

  /** Sets property propName of the component at path (e.g. top_i_Instance.ok.worker) to values,
    * adding the property if the component does not have it */
  def patch(m: ir.Aadl, path: Predef.String, propName: Predef.String, values: ISZ[ir.PropertyValue]): ir.Aadl = {
    val target: ISZ[String] = ISZ(path.split('.').toIndexedSeq.map(s => String(s)): _*)

    def visit(c: ir.Component): ir.Component = {
      val c2 = c(subComponents = c.subComponents.map(visit _))
      if (c2.identifier.name == target) {
        val props: ISZ[ir.Property] =
          if (c2.properties.elements.exists(p => isProp(p, propName)))
            c2.properties.map(p => if (isProp(p, propName)) p(propertyValues = values) else p)
          else c2.properties :+ ir.Property(ir.Name(ISZ(String(propName)), None()), values, ISZ())
        c2(properties = props)
      } else c2
    }

    m(components = m.components.map(visit _))
  }

  def resolve(m: ir.Aadl): (Option[SymbolTable], Reporter) = {
    val reporter = Reporter.create
    val store: Store = Map.empty
    val (elements, _) = ModelUtil.resolve(m, None(), "test", baseOptions(platform = CodegenHamrPlatform.JVM), store, reporter)
    (elements.map(e => e.symbolTable), reporter)
  }

  def ps(v: Predef.String): ir.UnitProp = ir.UnitProp(String(v), Some(String("ps")))

  def errorsContaining(r: Reporter, s: Predef.String): Int = r.errors.elements.count(m => ops.StringOps(m.text).contains(String(s)))

  "an inverted Compute_Execution_Time is an error on a non-Microkit platform" in {
    // OSATE rejects 5 ms .. 2 ms itself, but SysML and hand-built AIR can produce it
    val m = patch(load("cet-ranges"), "top_i_Instance.ok.worker", "Timing_Properties::Compute_Execution_Time",
      ISZ(ir.RangeProp(ps("5.0E9"), ps("2.0E9"))))
    val (_, r) = resolve(m)
    assert(errorsContaining(r, "Compute_Execution_Time of top_i_Instance.ok.worker has a low end (5 ms) greater than its high end (2 ms)") == 1,
      r.messages)
  }

  "a Period that does not parse is reported once, not also as missing" in {
    val m = patch(load("cet-ranges"), "top_i_Instance.ok.worker", "Timing_Properties::Period", ISZ(ps("ten")))
    val (st, r) = resolve(m)
    assert(st.isEmpty)
    assert(errorsContaining(r, "top_i_Instance.ok.worker") == 1, r.messages)
    assert(errorsContaining(r, "Must specify") == 0, r.messages)
  }

  "Slot_Time is read with its unit" in {
    val m = patch(load("microkit-exact-frame"), "top_i_Instance.proc", "Timing_Properties::Slot_Time",
      ISZ(ir.UnitProp("5", Some("ms"))))
    val (st, r) = resolve(m)
    assert(!r.hasIssue, r.messages)
    assert(st.get.getAllActualBoundProcessors()(0).slotTimePs == Some(Z(5000000000L)))
  }

  "a unitless Slot_Time is read as picoseconds, with a warning" in {
    val m = patch(load("microkit-exact-frame"), "top_i_Instance.proc", "Timing_Properties::Slot_Time",
      ISZ(ir.UnitProp("7", None())))
    val (st, r) = resolve(m)
    assert(!r.hasError, r.messages)
    assert(r.warnings.elements.count(w => ops.StringOps(w.text).contains("has no time unit")) == 1, r.messages)
    assert(st.get.getAllActualBoundProcessors()(0).slotTimePs == Some(Z(7)))
  }
}
