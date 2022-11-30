package org.sireum.hamr.codegen.test.util

import org.sireum._
import org.sireum.hamr.act.templates.SlangEmbeddedTemplate
import org.sireum.hamr.act.util.CMakeOption
import org.sireum.hamr.codegen.common.util.{CodeGenConfig, CodeGenPlatform}
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.ir.{Aadl, JSON}
import org.sireum.message.Reporter

object TestUtil {

  def getSireum(): Os.Path = {
    return Os.cwd / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")
  }

  def getCodegenDir(): Os.Path = {
    return (
      if (Os.cwd.name.native == "codegen") Os.cwd
      else getSireum().up.up / "hamr" / "codegen")
  }

  def getRootDirectory(cls: Class[_]): Os.Path = {
    def search(p: Os.Path): Option[(Os.Path, Os.Path)] = {
      assert(p.isDir, p)
      for (pp <- p.list) {
        if (pp.isFile && pp.name.native == s"${cls.getSimpleName}.scala") {
          val _package = ops.StringOps(cls.getPackage.getName).split((c: C) => c == C('.'))
          var dir = pp.up
          var ok = T
          var i = _package.size - 1
          while (ok && i >= 0) { // ensure we're in the right package
            ok = _package(i) == dir.name
            i = i - 1
            dir = dir.up
          }
          if (ok) {
            return Some((dir, pp))
          }
        }
        if (pp.isDir) {
          search(pp) match {
            case Some((a, b)) => return Some((a, b))
            case _ =>
          }
        }
      }
      return None()
    }

    search(Os.path(".").canon) match {
      case Some((scalaDir, _)) =>
        if (scalaDir.name.native == "scala")
          return scalaDir.up
        else
          halt(s"Expecting the 'scala' directory but found ${scalaDir.value}")
      case _ => halt(s"Couldn't find directory containing ${cls.getName}")
    }
  }

  def getModel(phantomOptions: Option[String],
               rootAadlDir: Os.Path, testModes: ISZ[TestMode.Type], testName: String, verbose: B): Aadl = {
    val s = rootAadlDir / ".slang"
    val cands = s.list.filter(f => f.name.native.endsWith("json"))
    assert(cands.size == 1, s": Inspect json files in ${s.value}")

    return getModel(Some(cands(0)), phantomOptions, rootAadlDir, testModes, testName, verbose)
  }

  def getModel(airFile: Option[Os.Path],
               phantomOptions: Option[String],
               rootAadlDir: Os.Path,
               testModes: ISZ[TestMode.Type], testName: String, verbose: B): Aadl = {

    val s: String = if (ops.ISZOps(testModes).contains(TestMode.phantom) || airFile.isEmpty) {
      val tempDir = Os.tempDir()
      val outputFile = tempDir / ".slang" / "testAIR.json"
      outputFile.up.mkdir()

      // see https://github.com/sireum/osate-plugin/blob/57785407d84793cf1f8d5926647e4dc75ab197a9/org.sireum.aadl.osate.cli/src/org/sireum/aadl/osate/cli/Phantom.java#L508-L517
      val custEnv = Os.envs.entries :+ (("CHECK_PHANTOM_HAMR_API_COMPATIBILITY", "true"))

      println("Generating AIR via phantom ...")
      var p: OsProto.Proc =
        if(phantomOptions.isEmpty) proc"${getSireum().value} hamr phantom -f ${outputFile.canon.string} ${rootAadlDir.canon.string}".env(custEnv)
        else proc"${getSireum().value} hamr phantom -f ${outputFile.canon.string} ${phantomOptions.get}".at(rootAadlDir).env(custEnv)

      if (verbose) {
        p = p.console
      }
      val results = p.run()

      assert(results.ok,
        st"""AIR generation failed for model at ${rootAadlDir.toUri}:
            |  ${results.out}
            |  ${results.err}""".render)

      // see https://github.com/sireum/osate-plugin/blob/57785407d84793cf1f8d5926647e4dc75ab197a9/org.sireum.aadl.osate.cli/src/org/sireum/aadl/osate/cli/Phantom.java#L515
      assert(ops.StringOps(results.out).contains("HAMR plugin API compatibility check passed!"), "OSATE cli plugin did not emit expected api check message")

      assert(check(testName, results, "Phantom did not complete successfully"), "Check did not return OK")
      outputFile.read
    } else {
      airFile.get.read
    }

    return JSON.toAadl(s) match {
      case Either.Left(m) => m
      case Either.Right(m) =>
        halt(s"Json deserialization error at (${m.line}, ${m.column}): ${m.message}")
    }

  }


  def check(testName: String, results: OsProto.Proc.Result, failMsg: String): B = {
    if (!results.ok) {
      println(s"${testName}: ${failMsg}")
      println("out:")
      println(results.out)
      println("err:")
      println(results.err)
    }
    return results.ok
  }


  def runAdditionalTasks(testName: String,
                         testResultsDir: Os.Path,
                         testOps: CodeGenConfig,
                         testModes: ISZ[TestMode.Type],
                         logikaOptions: Option[String],
                         verbose: B,
                         reporter: Reporter): B = {

    def vproc(commands: String, runInDir: Os.Path, env: ISZ[(String, String)], timeout: Option[Z]): OsProto.Proc.Result = {
      var p = proc"$commands".env(env).at(runInDir)
      if (timeout.nonEmpty) {
        p = p.timeout(timeout.get)
      }
      if (verbose) {
        p = p.console.redirectErr
      }
      return p.run()
    }

    val sireum: Os.Path = getSireum()
    val sireumHome: Os.Path = sireum.up.up
    val os: String = Os.kind match {
      case Os.Kind.Win => "win"
      case Os.Kind.Linux => "linux"
      case Os.Kind.LinuxArm => "linux/arm"
      case Os.Kind.Mac => "mac"
      case _ => halt("Unsupported OS")
    }

    var slangDir: Os.Path = testResultsDir //Os.path(testOps.slangOutputDir.get)

    var optSubstDrive: String = ""
    if (Os.isWin) {
      // scalac.bat fails for long paths even when enabled (e.g. on github action windows 2019 nodes)
      // so create a virtual drive to shorten the path
      optSubstDrive = {
        var i = 90
        var cand: String = ""
        while (i > 65) {
          val d = Os.path(s"${C(i)}:")
          if (!d.exists) {
            cand = d.string;
            i = 65
          }
          i = i - 1
        }
        cand
      }
      println(s"Attempting subst of ${optSubstDrive} for '${slangDir.string}'")
      proc"subst ${optSubstDrive} ${slangDir.string}".runCheck()

      slangDir = Os.path(optSubstDrive)
      assert(slangDir.exists, s"Virtual drive ${slangDir.string} doesn't exist")
    }

    def fetch(filename: String): Os.Path = {
      var loc: ISZ[Os.Path] = ISZ()

      def r(p: Os.Path): Unit = {
        if (p.isDir) {
          for (pp <- p.list if loc.isEmpty) {
            r(pp)
          }
        }
        else {
          if (p.name == filename) {
            loc = loc :+ p
          }
        }
      }

      r(slangDir)
      assert(loc.size == 1, s"Fetch failed for ${filename}. Found ${loc.size} matches. ${loc}")
      return loc(0).canon
    }

    var keepGoing: B = T

    def _check(results: OsProto.Proc.Result, failMsg: String): Unit = {
      keepGoing = check(testName, results, failMsg)
    }

    if (shouldTipe(testOps, testModes) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Running Tipe on Slang project ...")
      val proyekResults = vproc(s"${sireum.string} proyek tipe --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      _check(proyekResults, "Proyek tipe failed")
    }

    if (shouldProyekIve(testOps, testModes) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Generating IVE project via proyek ive ...")
      val proyekResults = vproc(s"${sireum.string} proyek ive ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      _check(proyekResults, "Proyek ive failed")
    }

    if (shouldTranspile(testOps, testModes) && keepGoing) {
      if (isLinux(testOps.platform)) {
        val transpileScript = fetch("transpile.cmd")

        println(s"Transpiling ${testOps.platform} via script ...")
        val cTranspileResults = vproc(s"${transpileScript.string}", transpileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string)), None())
        _check(cTranspileResults, "C transpiling failed")

      } else {
        assert(testOps.platform == CodeGenPlatform.SeL4, s"Hmm, ${testOps.platform}")
        val transpileScript = fetch("transpile-sel4.cmd")

        println(s"Transpiling ${testOps.platform} via script ...")
        val cTranspileResults = vproc(s"${transpileScript.string}", transpileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string)), None())
        _check(cTranspileResults, "seL4 transpiling failed")
      }
    }

    if (shouldCompile(testOps.platform, testModes) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Compiling Slang project via proyek compile ...")
      val proyekResults = vproc(s"${sireum.string} proyek compile --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      _check(proyekResults, "Proyek compilation failed")

      if (testOps.genSbtMill && keepGoing) {
        val sbt = getCodegenDir() / "bin" / "sbt" / "bin" / (if (Os.isWin) "sbt.bat" else "sbt")
        if (sbt.exists) {
          println("Compiling Slang project via sbt ...")
          val sbtResults = vproc(s"$sbt compile", projectCmd.up.up, ISZ(), None())
          _check(sbtResults, "sbt compilation failed")
        } else {
          eprintln(s"sbt not found at $sbt.")
          eprintln(s"Run the following to install it: '$$SIREUM_HOME/hamr/codegen/bin/build.cmd --help'")
        }
      }

      if (isLinux(testOps.platform) && keepGoing) {
        println("Compiling C project via script ...")
        val compileScript = fetch("compile.cmd")

        val cCompileResults = vproc(s"${compileScript.string} -b -r -l", compileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string), ("MAKE_ARGS", "-j4")), None())
        _check(cCompileResults, "C Compilation failed")
      }
    }

    if (shouldRunLogika(testOps, testModes) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Checking Slang project contracts via proyek logika ...")
      val proyekResults = vproc(st"${sireum.string} proyek logika --all --par ${logikaOptions} ${projectCmd.up.up.string}".render, projectCmd.up.up, ISZ(), None())
      _check(proyekResults, "Proyek logika failed")

      // Delete the 'out' directory so that it doesn't pollute directory diffs
      val outDir = projectCmd.up.up / "out"
      if (outDir.exists) outDir.removeAll()
    }

    if (shouldRunGeneratedUnitTests(testOps.platform, testModes) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Running generated unit tests ...")
      val proyekResults = vproc(s"${sireum.string} proyek test --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      _check(proyekResults, "Proyek test failed")
    }

    if (shouldProve(testOps, testModes)) {
      val proof = Os.path(testOps.camkesOutputDir.get) / "proof" / "smt2_case.smt2"
      val cvc = sireumHome / "bin" / os / (if (Os.isWin) "cvc.exe" else "cvc")
      val z3 = sireumHome / "bin" / os / "z3" / "bin" / (if (Os.isWin) "z3.exe" else "z3")

      def err(out: String, exitCode: Z): Unit = {
        halt(
          st"""Error encountered when running ${cvc.value} query:
              |${proof.read}
              |
              |${cvc.value} output (exit code $exitCode):
              |$out""".render)
      }

      assert(proof.exists, s"${proof} does not exist")
      assert(cvc.exists, s"${cvc} doesn't exist")
      assert(z3.exists, s"${z3} doesn't exist")

      println("Checking refinement proof ...")

      val startTime = extension.Time.currentMillis
      val pr = vproc(st"${cvc.value} -i --finite-model-find ${proof.value}".render, proof.up, ISZ(), None())
      val pout: String = pr.out
      val isTimeout: B = pr.exitCode === 6 || pr.exitCode === -101 || pr.exitCode === -100
      if (pout.size == 0 && pr.exitCode != 0 && !isTimeout) {
        err(pout, pr.exitCode)
      }

      val duration = extension.Time.currentMillis - startTime

      if (verbose) {
        println(s"Refinement proof duration: $duration ms")
      }

      val out = ops.StringOps(ops.StringOps(pout).replaceAllLiterally("\r\n", "\n")).split((c: C) => c == C('\n'))
      if (isTimeout || out.size != 10) {
        cprintln(T, s"${if (isTimeout) s"Timed-out after ${duration} ms. " else ""}Expecting 10 lines but got ${out.size}")
        cprintln(T, pr.out)
        keepGoing = F
      } else {
        var accum: B = T

        def scheck(b: B, errorMsg: String): Unit = {
          if (!b) cprintln(T, errorMsg);
          accum = accum & b
        }

        def scheckH(a: String, b: String): Unit = {
          if (a != b) cprintln(T, s"Expecting '${a} but received ${b}'");
          accum = accum & (a == b)
        }

        scheckH(out(0), st""""RefinementProof: Shows that there is a model satisfying all the constraints (should be sat):"""".render)
        scheckH(out(2), st""""AADLWellFormedness: Proves that the generated AADL evidence is well-formed (should be unsat):"""".render)
        scheckH(out(4), st""""CAmkESWellFormedness: Proves that the generated CAmkES evidence is well-formed (should be unsat):"""".render)
        scheckH(out(6), st""""ConnectionPreservation: Proves that the generated CAmkES connections preserve AADL's (should be unsat):"""".render)
        scheckH(out(8), st""""NoNewConnections: Proves that the generated CAmkES connections does not contain more than AADL's (should be unsat):"""".render)

        scheck(out(1) == string"sat", s"RefinementProof is ${out(1)}")
        scheck(out(3) == string"unsat", s"AADLWellFormedness is ${out(3)}")
        scheck(out(5) == string"unsat", s"CAmkESWellFormedness is ${out(5)}")
        scheck(out(7) == string"unsat", s"ConnectionPreservation is ${out(7)}")
        scheck(out(9) == string"unsat", s"NoNewConnections is ${out(9)}")

        keepGoing = accum
      }
    }

    if (shouldCamkes(testOps.platform, testModes) && keepGoing) {
      val hasVMs: B = reporter.messages.filter(m => org.sireum.ops.StringOps(m.text)
        .contains("Your project contains VMs")).nonEmpty

      val rootCamkesDir: Option[Os.Path] =
        if (hasVMs) camkesVmExamplesDir()
        else camkesDir()

      rootCamkesDir match {
        case Some(camkesDir) => {
          val runCamkes = Os.path(testOps.camkesOutputDir.get) / "bin" / "run-camkes.sh"
          assert(runCamkes.exists, s"${runCamkes} doesn't exist")

          val camkesBuildDir = camkesDir / s"build_${testName}"
          camkesBuildDir.removeAll()

          def onOptions(options: ISZ[CMakeOption]): ISZ[(String, String)] = {
            return options.map(o => (o.name, "ON"))
          }

          var camkesEnv: ISZ[(String, String)] = ISZ()

          if (testOps.platform == CodeGenPlatform.SeL4) {
            val toptions = SlangEmbeddedTemplate.TRANSPILER_OPTIONS.filter(c => c.name != string"NO_PRINT")
            camkesEnv = camkesEnv ++ onOptions(toptions)
          }

          // would only want to enable cakeml assemblies if they are built ahead of time
          // which would mean the CI would need to do that as too expensive/large to
          // check the binaries into git
          //camkesArgs = camkesArgs ++ onOptions(CakeMLTemplate.CAKEML_OPTIONS)


          //camkesArgs = camkesArgs :+ s"-DCAMKES_APP=${name}"

          //if(hasVMs) {
          //  camkesEnv = camkesEnv ++ onOptions(VM_Template.VM_CMAKE_OPTIONS)
          //}

          println("Running CAmkES build ...")
          val camkesResults = vproc(s"${runCamkes.value} -n", runCamkes.up, camkesEnv, None())
          _check(camkesResults, "CAmkES build failed")

          //val results = Proc(ISZ("simulate"), Os.cwd, Map.empty, T, None(), F, F, F, F, F, timeout, F).at(camkesBuildDir).run()
        }
        case _ =>
          assert(F, "CAmkES directory not found")
      }
    }

    if (Os.isWin) {
      println(s"Attempting to unsubst ${optSubstDrive}")
      proc"subst ${optSubstDrive} /D".run()
    }

    return keepGoing // ie. no failure occurred
  }

  def isLinux(platform: CodeGenPlatform.Type): Boolean = {
    return platform match {
      case CodeGenPlatform.Linux => T
      case CodeGenPlatform.MacOS => T
      case CodeGenPlatform.Cygwin => T
      case _ => F
    }
  }

  def isSeL4(platform: CodeGenPlatform.Type): Boolean = {
    return platform match {
      case CodeGenPlatform.SeL4 => T
      case CodeGenPlatform.SeL4_TB => T
      case CodeGenPlatform.SeL4_Only => T
      case _ => F
    }
  }

  def isSlang(platform: CodeGenPlatform.Type): B = {
    return isLinux(platform) || platform == CodeGenPlatform.JVM || platform == CodeGenPlatform.SeL4
  }

  def shouldCamkes(platform: CodeGenPlatform.Type, testModes: ISZ[TestMode.Type]): B = {
    return isSeL4(platform) && ops.ISZOps(testModes).contains(TestMode.camkes)
  }

  def shouldProve(config: CodeGenConfig, testModes: ISZ[TestMode.Type]): B = {
    val platform = config.platform
    return { //
      (platform == CodeGenPlatform.SeL4 || platform == CodeGenPlatform.SeL4_Only) &&
        ops.ISZOps(testModes).contains(TestMode.smt2)
    }
  }

  def shouldCompile(platform: CodeGenPlatform.Type, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(platform) && ops.ISZOps(testModes).contains(TestMode.compile)
  }

  def shouldRunGeneratedUnitTests(platform: CodeGenPlatform.Type, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(platform) && ops.ISZOps(testModes).contains(TestMode.generated_unit_tests)
  }

  def shouldRunLogika(config: CodeGenConfig, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(config.platform) && ops.ISZOps(testModes).contains(TestMode.logika)
  }

  def shouldTipe(testOps: CodeGenConfig, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(testOps.platform) && ops.ISZOps(testModes).contains(TestMode.tipe) && !testOps.noEmbedArt
  }

  def shouldTranspile(testOps: CodeGenConfig, testModes: ISZ[TestMode.Type]): B = {
    val platform = testOps.platform
    val _ops = ops.ISZOps(testModes)
    return (testOps.runTranspiler && (isLinux(platform) || platform == CodeGenPlatform.SeL4)) ||
      (_ops.contains(TestMode.transpile) && (isLinux(platform) || platform == CodeGenPlatform.SeL4)) ||
      (_ops.contains(TestMode.compile) && isLinux(platform)) ||
      (_ops.contains(TestMode.camkes) && platform == CodeGenPlatform.SeL4)
  }

  def shouldProyekIve(config: CodeGenConfig, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(config.platform) && (!config.noProyekIve || ops.ISZOps(testModes).contains(TestMode.ive))
  }

  def onOptions(options: ISZ[CMakeOption]): ISZ[String] = {
    return options.map(o => s"-D${o.name}=ON")
  }

  def camkesDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        val candidate = Os.home / "CASE" / "camkes"
        if (candidate.exists) Some(candidate)
        else None()
    }
  }

  def camkesVmExamplesDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_VM_EXAMPLES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        val candidate = Os.home / "CASE" / "camkes-vm-examples"
        if (candidate.exists) Some(candidate)
        else None()
    }
  }
}
