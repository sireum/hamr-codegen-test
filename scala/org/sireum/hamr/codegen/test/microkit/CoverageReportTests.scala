package org.sireum.hamr.codegen.test.microkit

// The coverage report codegen emits for Rust component crates: bin/coverage-report.cmd and
// its page files (bin/coverage-report/), which the crate and top-level Makefiles' `make
// coverage` and the agent context's bin/build.cmd run.  Generates the INSPECTA-models
// system-verification/temp-control model -- two Rust component crates (fp_ft, tcp_tct)
// sharing the data crate, with GUMBO contracts whose generated code has branches -- then
// runs the script as a user would, through `sireum slang run`, so on Windows it exercises
// sireum.bat, the toolchain's llvm-cov.exe and backslash paths.  `sireum slang run` turns
// every non-zero exit into one code, so outcomes are checked through the status.txt the
// script writes.  Each crate's outcome is asserted exactly: fp_ft's skeleton passes its
// generated tests, while tcp_tct's fails its GUMBOX property tests by design -- its empty
// initialize entry point does not establish the model's initialize guarantees
// (defaultSetPoint, defaultFanStates, defaultLatestTemp) -- so its runs end tests-failed,
// with the coverage still written.
// Needs cargo; the crates' rust-toolchain.toml makes rustup fetch the pinned toolchain with
// its llvm-tools-preview component.  Cancelled without cargo.

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

class CoverageReportTests extends TestSuite with TestScratch {

  lazy val sysmlDir: Os.Path =
    MicrokitTestUtil.testResources.modelsDir / "micro-examples" / "microkit" / "system-verification" / "temp-control" / "sysml"
  val scratch: Os.Path = scratchBase / "hamr-coverage-report-test"

  // the sireum launcher: $SIREUM_HOME's when set (CI, IVE), else the one TestUtil finds
  val sireum: Os.Path = Os.env("SIREUM_HOME") match {
    case Some(h) => Os.path(h) / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")
    case _ => TestUtil.getSireum
  }

  lazy val hasCargo: B =
    try Os.proc(ISZ[String]("cargo", "--version")).run().ok
    catch { case _: Throwable => F }

  // Generated once and shared by the tests.
  lazy val generated: Os.Path = {
    val out = scratch / "generated"
    out.removeAll()
    val model = TestUtil.getModel(Some(sysmlDir / ".slang" / "TempControlSystem_Instance.json"), None(), sysmlDir, ISZ(), "tc", F)
    val opts = MicrokitTests.baseOptions(
      workspaceRootDir = Some(sysmlDir.canon.value),
      packageName = Some("tc"),
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
    assert(!reporter.hasError, "codegen of system-verification/temp-control reported errors")
    out / "microkit"
  }

  // the Rust thread components' crates (each has src/component/<crate>_app.rs)
  lazy val components: ISZ[Os.Path] = {
    val cs = (generated / "crates").list.filter(c => (c / "src" / "component" / s"${c.name}_app.rs").exists)
    assert(cs.size == 2, s"expected two Rust component crates, found ${cs.size}")
    cs
  }

  def crate(name: String): Os.Path = {
    for (c <- components if c.name == name) {
      return c
    }
    halt(s"no component crate $name")
  }

  def crateCov(c: Os.Path): Os.Path = c / "target" / "coverage"

  def status(covDir: Os.Path): String = {
    val f = covDir / "status.txt"
    return if (f.exists) ops.StringOps(f.read).trim else "(none)"
  }


  def coverageReport(crates: ISZ[Os.Path], extra: ISZ[String]): OsProto.Proc.Result =
    Os.proc(ISZ[String](sireum.string, "slang", "run", (generated / "bin" / "coverage-report.cmd").string) ++
      (for (c <- crates) yield c.string) ++ extra).redirectErr.timeout(30 * 60 * 1000).run()

  // the TOTAL row of a summary.txt: name, regions, missed, %, functions, missed, %, lines,
  // missed, %, branches, missed, %
  def totalBranches(covDir: Os.Path): Z = {
    for (l <- (covDir / "summary.txt").readLines if ops.StringOps(l).startsWith("TOTAL")) {
      val t = for (w <- ops.StringOps(l).split(c => c == C(' ')) if w != String("")) yield w
      return Z(t(10)).get
    }
    return -1
  }

  "codegen emits the coverage report script, its page files, and Makefile targets that run it" in {
    assert((generated / "bin" / "coverage-report.cmd").exists, "no bin/coverage-report.cmd")
    for (f <- ISZ[String]("index.html", "report.js", "report.css")) {
      assert((generated / "bin" / "coverage-report" / f).exists, s"no bin/coverage-report/$f")
    }
    for (c <- components) {
      val makefile = ops.StringOps((c / "Makefile").read)
      assert(makefile.contains("COVERAGE_REPORT = ../../bin/coverage-report.cmd"), s"${c.name}'s Makefile does not use the script")
      assert(makefile.contains("coverage-report:"), s"${c.name}'s Makefile has no coverage-report target")
    }
    // the top level: coverage targets over every component crate, and clobber removes the report
    val top = ops.StringOps((generated / "Makefile").read)
    assert(top.contains("coverage: ${TOP_BUILD_DIR}/Makefile") && top.contains("coverage-report: ${TOP_BUILD_DIR}/Makefile"),
      "the top-level Makefile has no coverage targets")
    assert(top.contains("rm -rf $(TOP_DIR)/target/coverage"), "the top-level clobber does not remove the coverage report")
    val system = ops.StringOps((generated / "system.mk").read)
    assert(system.contains("$(TOP_DIR)/bin/coverage-report.cmd"), "system.mk has no coverage target")
    for (c <- components) {
      assert(system.contains(s"$${CRATES_DIR}/${c.name}"), s"system.mk's coverage target does not include ${c.name}")
    }
  }

  "coverage-report.cmd runs a crate's tests and writes the report" in {
    if (!hasCargo) cancel("cargo is not installed")
    val c = crate("fp_ft")
    val cov = crateCov(c)
    val r = coverageReport(ISZ(c), ISZ())
    assert(status(cov) == String("ok"), s"coverage-report.cmd on fp_ft: status ${status(cov)}, expected ok:\n${r.out}")
    assert(ops.StringOps(r.out).contains("test result:"), s"the tests did not run:\n${r.out}")
    val lcov = ops.StringOps((cov / "lcov.info").read)
    assert(lcov.contains("SF:") && lcov.contains(s"${c.name}_app.rs"), "lcov.info does not cover the app file")
    assert((cov / "binaries.txt").exists, "the run's test executables were not recorded")
    for (f <- ISZ[String]("index.html", "report.js", "report.css", "data.js")) {
      assert((cov / "report" / f).exists, s"no report/$f")
    }
    val data = ops.StringOps((cov / "report" / "data.js").read)
    assert(data.startsWith("window.HAMR_COVERAGE = {"), "data.js does not define HAMR_COVERAGE")
    assert(data.contains(s"pub struct ${c.name}"), "data.js does not carry the app file's source")
  }

  "coverage-report.cmd merges two component crates that share the data crate into one report" in {
    if (!hasCargo) cancel("cargo is not installed")
    val out = scratch / "combined"
    val r = coverageReport(components, ISZ(s"out=${out.string}"))
    // tcp_tct's tests fail, so the merged outcome is tests-failed, with the report written
    assert(status(out) == String("tests-failed"), s"coverage-report.cmd on two crates: status ${status(out)}, expected tests-failed:\n${r.out}")
    // without -Zcoverage-options=branch there would be no branch records at all
    assert(ops.StringOps((out / "lcov.info").read).contains("BRDA:"), "lcov.info has no branch records (BRDA)")
    assert(totalBranches(out) > 0, "summary.txt reports no branches")
    val summary = ops.StringOps((out / "summary.txt").read)
    for (c <- components) {
      assert(summary.contains(s"${c.name}_app.rs"), s"the combined summary does not cover ${c.name}")
    }
    // a data crate source compiled into both crates' tests is reported once
    val dataFiles = for (l <- (out / "lcov.info").readLines if ops.StringOps(l).startsWith("SF:") &&
      ops.StringOps(ops.StringOps(l).replaceAllChars('\\', '/')).contains("/crates/data/")) yield l
    assert(dataFiles.nonEmpty, "the combined report does not cover the data crate")
    assert(dataFiles.size == (HashSSet.empty[String] ++ dataFiles).size, "a data crate source is reported more than once")
    val data = ops.StringOps((out / "report" / "data.js").read)
    assert(data.contains(st"${(for (c <- components) yield c.name, ", ")}".render), "the combined report does not name both crates")
  }

  "no-run reports on a crate's last run, and refuses when its or the data crate's sources changed or the run was filtered; reuse re-tests it" in {
    if (!hasCargo) cancel("cargo is not installed")
    val c = crate("tcp_tct")
    val cov = crateCov(c)
    val run = coverageReport(ISZ(c), ISZ())
    assert(status(cov) == String("tests-failed"), s"the coverage run on tcp_tct: status ${status(cov)}, expected tests-failed:\n${run.out}")

    // no-run carries the last run's failure forward
    (cov / "report").removeAll()
    val noRun = coverageReport(ISZ(c), ISZ("no-run"))
    assert(status(cov) == String("tests-failed"), s"no-run did not carry the run's failure forward (status ${status(cov)}):\n${noRun.out}")
    assert(!ops.StringOps(noRun.out).contains("test result:"), "no-run ran the tests")
    assert((cov / "report" / "data.js").exists, "no-run did not rebuild the report")

    // a source changed after the run: its test executables no longer match the profiles
    val app = c / "src" / "component" / s"${c.name}_app.rs"
    app.setLastModified((cov / "binaries.txt").lastModified + 5000)
    val stale = coverageReport(ISZ(c), ISZ("no-run"))
    assert(!stale.ok && status(cov) == String("stale"), s"no-run accepted out-of-date data (status ${status(cov)}):\n${stale.out}")

    val reuse = coverageReport(ISZ(c), ISZ("reuse"))
    assert(status(cov) == String("tests-failed"), s"reuse on tcp_tct: status ${status(cov)}, expected tests-failed:\n${reuse.out}")
    assert(ops.StringOps(reuse.out).contains("test result:"), "reuse did not re-test the changed crate")
    assert((cov / "run.txt").exists, "the run's exit code and filters were not recorded")

    // a source of a path dependency (the data crate) changed after the run
    val dataSrc = generated / "crates" / "data" / "src" / "lib.rs"
    dataSrc.setLastModified((cov / "binaries.txt").lastModified + 5000)
    val staleData = coverageReport(ISZ(c), ISZ("no-run"))
    assert(status(cov) == String("stale") && ops.StringOps(staleData.out).contains("lib.rs changed"),
      s"no-run missed a change to the data crate (status ${status(cov)}):\n${staleData.out}")

    // a filtered run does not pass for a full one
    // (test_initialization is a unit test that passes on the skeleton)
    val filtered = coverageReport(ISZ(c), ISZ("test_initialization"))
    assert(status(cov) == String("ok"), s"the filtered run: status ${status(cov)}, expected ok:\n${filtered.out}")
    val unfiltered = coverageReport(ISZ(c), ISZ("no-run"))
    assert(status(cov) == String("stale") && ops.StringOps(unfiltered.out).contains("filtered"),
      s"no-run reported a filtered run as a full one (status ${status(cov)}):\n${unfiltered.out}")
  }
}
