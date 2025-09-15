package org.sireum.hamr.codegen.test.util

import org.scalatest.BeforeAndAfterAll
import org.sireum._
import org.sireum.hamr.codegen.act.templates.SlangEmbeddedTemplate
import org.sireum.hamr.codegen.act.util.CMakeOption
import org.sireum.hamr.codegen.common.containers.{ExternalResource, FileResource, InternalResource, Marker, Resource, SireumProyekIveOption, SireumSlangTranspilersCOption, SireumToolsSergenOption, SireumToolsSlangcheckGeneratorOption}
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenOption}
import org.sireum.hamr.codegen.common.util.test.{ETestResource, ITestResource, TestJSON, TestMarker, TestResource, TestResult}
import org.sireum.hamr.codegen.test.CodegenTest
import org.sireum.hamr.ir.{Aadl, JSON}
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

import java.util.Date
import scala.util.Random

object TestUtil {

  val os: String = Os.kind match {
    case Os.Kind.Win => "win"
    case Os.Kind.Linux => "linux"
    case Os.Kind.LinuxArm => "linux/arm"
    case Os.Kind.Mac => "mac"
    case _ => halt("Unsupported OS")
  }

  def getSireum: Os.Path = {
    return Os.cwd / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")
  }

  def getCodegenDir: Os.Path = {
    return (
      if (Os.cwd.name.native endsWith "codegen") Os.cwd
      else getSireum.up.up / "hamr" / "codegen")
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
        if (pp.isDir && pp.name.native != "bin") {
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
    assert(cands.size == 1, s": Inspect json files in ${s.toUri}")

    return getModel(Some(cands(0)), phantomOptions, rootAadlDir, testModes, testName, verbose)
  }

  val osateDir: Option[Os.Path] = {
    Os.env("OSATE_HOME") match {
      case Some(s) => Some(Os.path(s))
      case _ =>
        val d = getCodegenDir / "bin" / os / s"osate${if (Os.isMac) ".app" else ""}"
        if (d.exists) Some(d)
        else None()
      }
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

      val osateOpt: String = if (osateDir.isEmpty) "" else s"-o ${osateDir.get.value}"

      println(s"Generating AIR via phantom ${if (osateDir.isEmpty) "" else s"using ${osateDir.get} "}...")
      var p: OsProto.Proc =
        if (phantomOptions.isEmpty) proc"${getSireum.value} hamr phantom ${osateOpt} -f ${outputFile.canon.string} ${rootAadlDir.canon.string}".env(custEnv)
        else proc"${getSireum.value} hamr phantom ${osateOpt} -f ${outputFile.canon.string} ${phantomOptions.get}".at(rootAadlDir).env(custEnv)

      if (verbose) {
        p = p.console
      }
      var results = p.run()

      if (Os.isMac && isCI && !results.ok) {
        var retries = 1
        while (!results.ok && retries <= 3) {
          println(s"Previous attempt failed, retry attempt $retries. AIR gen via phantom ${if (osateDir.isEmpty) "" else s"using ${osateDir.get} "}...")
          var p: OsProto.Proc =
            if (phantomOptions.isEmpty) proc"${getSireum.value} hamr phantom ${osateOpt} -f ${outputFile.canon.string} ${rootAadlDir.canon.string}".env(custEnv)
            else proc"${getSireum.value} hamr phantom ${osateOpt} -f ${outputFile.canon.string} ${phantomOptions.get}".at(rootAadlDir).env(custEnv)

          if (verbose) {
            p = p.console
          }
          results = p.run()

          retries = retries + 1
        }
      }

      assert(results.ok,
        st"""AIR generation failed for model at ${rootAadlDir.toUri}:
            |  ${results.out}
            |  ${results.err}""".render)

      // see https://github.com/sireum/osate-plugin/blob/57785407d84793cf1f8d5926647e4dc75ab197a9/org.sireum.aadl.osate.cli/src/org/sireum/aadl/osate/cli/Phantom.java#L515
      assert(ops.StringOps(results.out).contains("HAMR plugin API compatibility check passed!"), "OSATE cli plugin did not emit expected api check message")

      assert(check(testName, results, "Phantom did not complete successfully"), "Check did not return OK")
      val ret = outputFile.read

      if (Os.env("GITHUB_ACTIONS").nonEmpty ) {
        // 2024.02.16 -- running out of space in camkes docker container on github
        tempDir.removeAll()
      }

      ret
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
                         testOps: CodegenOption,
                         testModes: ISZ[TestMode.Type],
                         logikaOptions: Option[String],
                         verbose: B,
                         testSuite: CodegenTestSuite,
                         reporter: Reporter): B = {

    val onGithub = Os.env("GITHUB_ACTIONS").nonEmpty
    val rand = new Random(new Date().hashCode())

    def performAction(msg: String): B = {
      val ret = T // !onGithub || rand.nextInt() % 2 == 0
      if (!ret) {
        println(s"Skipping: $msg")
      }
      return ret
    }

    def vproc(commands: String, runInDir: Os.Path, env: ISZ[(String, String)], timeout: Option[Z], key: String): OsProto.Proc.Result = {
      var p = proc"$commands".env(env).at(runInDir)
      if (timeout.nonEmpty) {
        p = p.timeout(timeout.get)
      }
      if (verbose) {
        p = p.console.redirectErr
      }

      val start = System.currentTimeMillis()
      val results = p.run()
      testSuite.add(key, System.currentTimeMillis() - start)

      return results
    }

    val sireum: Os.Path = getSireum
    val sireumHome: Os.Path = sireum.up.up

    var optSubstDrive: Option[Os.Path] = None()

    val (slangOutDir, cOutDir, camkesOutDir): ((Option[Os.Path], Option[Os.Path], Option[Os.Path])) = {
      if (!Os.isWin) {
        def c(t: Option[String]): Option[Os.Path] = if (t.isEmpty) None() else Some(Os.path(t.get))
        ((c(testOps.slangOutputDir), c(testOps.slangOutputCDir), c(testOps.sel4OutputDir)))
      } else {
        def commonPath(paths: scala.List[String]): String = {
          def common(al: scala.List[String], bl: scala.List[String]): scala.List[String] = (al, bl) match {
            case (a :: as, b :: bs) if a == b => a :: common(as, bs)
            case _ => Nil
          }
          if (paths.length < 2) paths.headOption.getOrElse("")
          else paths.map(m => ops.StringOps(m).split(c => c == C('/')).elements.toList).reduceLeft(common).mkString("/")
        }

        val l = scala.List(testOps.slangOutputDir, testOps.slangOutputCDir, testOps.sel4OutputDir).flatten(a => if (a.isEmpty) scala.List() else scala.List(Os.path(a.get).toUri))
        if (l.isEmpty) {
          (None(), None(), None())
        } else {
          val rootDir: Os.Path = Os.uriToPath(commonPath(l))

          // scalac.bat fails for long paths even when enabled (e.g. on github action windows 2019 nodes)
          // so create a virtual drive to shorten the path
          val _optSubstDrive: String = {
            var i = 90
            var cand: String = ""
            while (i > 65) {
              val d = Os.path(s"${C(i)}:")
              if (!d.exists) {
                cand = d.string
                i = 65
              }
              i = i - 1
            }
            cand
          }
          println(s"Attempting subst of ${_optSubstDrive} for '${rootDir.string}'")
          proc"subst ${_optSubstDrive} ${rootDir.string}".console.runCheck()

          optSubstDrive = Some(Os.path(_optSubstDrive))
          assert(optSubstDrive.get.exists, s"Virtual drive ${optSubstDrive.get.string} doesn't exist")

          def c(t: Option[String]): Option[Os.Path] = t match {
            case Some(path) => Some(optSubstDrive.get / rootDir.relativize(Os.path(path)).value)
            case _ => None()
          }

          ((c(testOps.slangOutputDir), c(testOps.slangOutputCDir), c(testOps.sel4OutputDir)))
        }
      }
    }

    def fetch(filename: String, root: Os.Path): Os.Path = {
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

      r(root)
      assert(loc.size == 1, s"Could not find $filename in $root. Found ${loc.size} matches. $loc")
      return loc(0).canon
    }

    var keepGoing: B = T

    def _check(results: OsProto.Proc.Result, failMsg: String): Unit = {
      keepGoing = check(testName, results, failMsg)
    }

    if (shouldTipe(testOps, testModes) && keepGoing && performAction("Tipe")) {
      val projectCmd = fetch("project.cmd", slangOutDir.get)

      println("Running Tipe on Slang project ...")
      val proyekResults = vproc(s"${sireum.string} proyek tipe --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None(), "tipe")
      _check(proyekResults, "Proyek tipe failed")
    }

    if (shouldProyekIve(testOps, testModes) && keepGoing && performAction("Proyek IVE")) {
      val projectCmd = fetch("project.cmd", slangOutDir.get)

      println("Generating IVE project via proyek ive ...")
      val proyekResults = vproc(s"${sireum.string} proyek ive ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None(), "ive")
      _check(proyekResults, "Proyek ive failed")
    }

    // always transpile if required
    if (shouldTranspile(testOps, testModes) && keepGoing) {
      if (isLinux(testOps.platform)) {
        val transpileScript = fetch("transpile.cmd", slangOutDir.get)

        println(s"Transpiling ${testOps.platform} via script ...")
        val cTranspileResults = vproc(s"${transpileScript.string}", transpileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string)), None(), "trans-linux")
        _check(cTranspileResults, "C transpiling failed")

      } else {
        assert(testOps.platform == CodegenHamrPlatform.SeL4, s"Hmm, ${testOps.platform}")
        val transpileScript = fetch("transpile-sel4.cmd", slangOutDir.get)

        println(s"Transpiling ${testOps.platform} via script ...")
        val cTranspileResults = vproc(s"${transpileScript.string}", transpileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string)), None(), "trans-camkes")
        _check(cTranspileResults, "seL4 transpiling failed")
      }
    }

    if (shouldCompile(testOps.platform, testModes) && keepGoing) {
      val projectCmd = fetch("project.cmd", slangOutDir.get)

      if (performAction("Proyek compile")) {
        println("Compiling Slang project via proyek compile ...")
        val proyekResults = vproc(s"${sireum.string} proyek compile --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None(), "proyek-compile")
        _check(proyekResults, "Proyek compilation failed")
      }

      if (testOps.genSbtMill && keepGoing) {

        if (performAction("sbt compile") && !(Os.isWin && isCI)) {
          val sbt = getCodegenDir / "bin" / os / "sbt" / "bin" / (if (Os.isWin) "sbt.bat" else "sbt")
          if (sbt.exists) {
            println("Compiling Slang project via sbt ...")
            val sbtResults: OsProto.Proc.Result = Os.javaHomeOpt(Os.kind, Os.sireumHomeOpt) match {
              case Some(j) =>
                if (Os.isWin) {
                  val s = st"""set JAVA_HOME=$j
                              |set PATH=%JAVA_HOME\\bin;%PATH
                              |$sbt compile --batch"""
                  val bat = projectCmd.up.up / "w.bat"
                  bat.writeOver(s.render)
                  val r = vproc(s"$bat", projectCmd.up.up, for(e <- Os.envs.entries) yield (e._1, e._2), None(), "sbt-compile")
                  bat.remove()
                  r
                }
                else {
                  val s = st"""#!/usr/bin/env bash
                              |export JAVA_HOME=$j
                              |export PATH=$$JAVA_HOME/bin:$$PATH
                              |$sbt compile --batch"""
                  val bash = projectCmd.up.up / "w.sh"
                  bash.writeOver(s.render)
                  val r = vproc(s"bash $bash", projectCmd.up.up, for(e <- Os.envs.entries) yield (e._1, e._2), None(), "sbt-compile")
                  bash.remove()
                  r
                }
              case _ =>
                vproc(s"$sbt compile --batch", projectCmd.up.up, for(e <- Os.envs.entries) yield (e._1, e._2), None(), "sbt-compile")
            }
            _check(sbtResults, "sbt compilation failed")
          } else {
            eprintln(s"sbt not found at $sbt.")
            eprintln(s"Run the following to install it: '$$SIREUM_HOME/hamr/codegen/bin/build.cmd --help'")
          }
        }
      }

      //noinspection DfaConstantConditions
      if (isLinux(testOps.platform) && keepGoing && performAction("C compile")) {
        if (Os.isWin && !cygwinInstalled()) {
          println("Cygwin not detected, skipping C compilation")
        } else {
          println("Compiling C project via script ...")
          val compileScript = fetch("compile.cmd", cOutDir.get)

          val cCompileResults = vproc(s"${compileScript.string} -b -r -l", compileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string), ("MAKE_ARGS", "-j4")), None(), "c-compile")
          _check(cCompileResults, "C Compilation failed")
        }
      }
    }

    if (shouldRunLogika(testOps, testModes) && keepGoing && performAction("Logika")) {
      val projectCmd = fetch("project.cmd", slangOutDir.get)

      println("Checking Slang project contracts via proyek logika ...")
      val proyekResults = vproc(st"${sireum.string} proyek logika --all --par ${logikaOptions} ${projectCmd.up.up.string}".render, projectCmd.up.up, ISZ(), None(), "logika")
      _check(proyekResults, "Proyek logika failed")

      // Delete the 'out' directory so that it doesn't pollute directory diffs
      val outDir = projectCmd.up.up / "out"
      if (outDir.exists) outDir.removeAll()
    }

    if (shouldRunGeneratedUnitTests(testOps.platform, testModes) && keepGoing && performAction("Generated unit tests")) {
      val projectCmd = fetch("project.cmd", slangOutDir.get)

      println("Running generated unit tests ...")
      val proyekResults = vproc(s"${sireum.string} proyek test --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None(), "gen-unit-test")
      _check(proyekResults, "Proyek test failed")
    }

    if (shouldProve(testOps, testModes) && performAction("Refinement proof")) {
      val proof = camkesOutDir.get / "proof" / "smt2_case.smt2"
      val cvc4 = sireumHome / "bin" / os / (if (Os.isWin) "cvc.exe" else "cvc")

      def err(out: String, exitCode: Z): Unit = {
        halt(
          st"""Error encountered when running ${cvc4.value} query:
              |${proof.read}
              |
              |${cvc4.value} output (exit code $exitCode):
              |$out""".render)
      }

      assert(proof.exists, s"${proof} does not exist")
      assert(cvc4.exists, s"${cvc4} doesn't exist")

      println("Checking refinement proof ...")

      val startTime = extension.Time.currentMillis
      val pr = vproc(st"${cvc4.value} -i --finite-model-find ${proof.value}".render, proof.up, ISZ(), None(), "refinement-proof")
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
          if (!b) cprintln(T, errorMsg)
          accum = accum & b
        }

        def scheckH(a: String, b: String): Unit = {
          if (a != b) cprintln(T, s"Expecting '${a} but received ${b}'")
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

    if (shouldCamkes(testOps.platform, testModes) && keepGoing && performAction("Camkes")) {
      val hasVMs: B = reporter.messages.filter(m => org.sireum.ops.StringOps(m.text)
        .contains("Your project contains VMs")).nonEmpty

      val rootCamkesInstallationDir: Option[Os.Path] =
        if (hasVMs) camkesVmExamplesDir()
        else camkesDir()

      rootCamkesInstallationDir match {
        case Some(camkesInstallDir) => {
          val runCamkes = camkesOutDir.get / "bin" / "run-camkes.sh"
          assert(runCamkes.exists, s"${runCamkes} doesn't exist")

          val camkesBuildDir = camkesInstallDir / s"build_${testName}"
          camkesBuildDir.removeAll()

          def onOptions(options: ISZ[CMakeOption]): ISZ[(String, String)] = {
            return options.map(o => (o.name, "ON"))
          }

          var camkesEnv: ISZ[(String, String)] = ISZ()

          if (testOps.platform == CodegenHamrPlatform.SeL4) {
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
          val camkesResults = vproc(s"${runCamkes.value} -n", runCamkes.up, camkesEnv, None(), "camkes")
          _check(camkesResults, "CAmkES build failed")

          //val results = Proc(ISZ("simulate"), Os.cwd, Map.empty, T, None(), F, F, F, F, F, timeout, F).at(camkesBuildDir).run()
        }
        case _ =>
          assert(F, "CAmkES directory not found")
      }
    }

    if (optSubstDrive.nonEmpty) {
      println(s"Attempting to unsubst ${optSubstDrive.get.value}")
      proc"subst ${optSubstDrive.get.value} /D".console.runCheck()
    }

    return keepGoing // ie. no failure occurred
  }

  def isLinux(platform: CodegenHamrPlatform.Type): Boolean = {
    return platform match {
      case CodegenHamrPlatform.Linux => T
      case CodegenHamrPlatform.MacOS => T
      case CodegenHamrPlatform.Cygwin => T
      case _ => F
    }
  }

  def isSeL4(platform: CodegenHamrPlatform.Type): Boolean = {
    return platform match {
      case CodegenHamrPlatform.SeL4 => T
      case CodegenHamrPlatform.SeL4_TB => T
      case CodegenHamrPlatform.SeL4_Only => T
      case _ => F
    }
  }

  def isSlang(platform: CodegenHamrPlatform.Type): B = {
    return isLinux(platform) || platform == CodegenHamrPlatform.JVM || platform == CodegenHamrPlatform.SeL4
  }

  def shouldCamkes(platform: CodegenHamrPlatform.Type, testModes: ISZ[TestMode.Type]): B = {
    return isSeL4(platform) && ops.ISZOps(testModes).contains(TestMode.camkes)
  }

  def shouldProve(config: CodegenOption, testModes: ISZ[TestMode.Type]): B = {
    val platform = config.platform
    return { //
      (platform == CodegenHamrPlatform.SeL4 || platform == CodegenHamrPlatform.SeL4_Only) &&
        ops.ISZOps(testModes).contains(TestMode.smt2)
    }
  }

  def shouldCompile(platform: CodegenHamrPlatform.Type, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(platform) && ops.ISZOps(testModes).contains(TestMode.compile)
  }

  def shouldRunGeneratedUnitTests(platform: CodegenHamrPlatform.Type, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(platform) && ops.ISZOps(testModes).contains(TestMode.generated_unit_tests)
  }

  def shouldRunLogika(config: CodegenOption, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(config.platform) && ops.ISZOps(testModes).contains(TestMode.logika)
  }

  def shouldTipe(testOps: CodegenOption, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(testOps.platform) && ops.ISZOps(testModes).contains(TestMode.tipe) && !testOps.noEmbedArt
  }

  def shouldTranspile(testOps: CodegenOption, testModes: ISZ[TestMode.Type]): B = {
    val platform = testOps.platform
    val _ops = ops.ISZOps(testModes)
    return (testOps.runTranspiler && (isLinux(platform) || platform == CodegenHamrPlatform.SeL4)) ||
      (_ops.contains(TestMode.transpile) && (isLinux(platform) || platform == CodegenHamrPlatform.SeL4)) ||
      (_ops.contains(TestMode.compile) && isLinux(platform)) ||
      (_ops.contains(TestMode.camkes) && platform == CodegenHamrPlatform.SeL4)
  }

  def shouldProyekIve(config: CodegenOption, testModes: ISZ[TestMode.Type]): B = {
    return isSlang(config.platform) && (!config.noProyekIve || ops.ISZOps(testModes).contains(TestMode.ive))
  }

  def shouldSergen(config: CodegenOption, testModes: ISZ[TestMode.Type]): B = {
    return ops.ISZOps(testModes).contains(TestMode.sergen) && isSlang(config.platform) && !config.noEmbedArt
  }

  def shouldSlangCheck(config: CodegenOption, testModes: ISZ[TestMode.Type]): B = {
    return ops.ISZOps(testModes).contains(TestMode.slangcheck) && isSlang(config.platform) && !config.noEmbedArt
  }

  def onOptions(options: ISZ[CMakeOption]): ISZ[String] = {
    return options.map(o => s"-D${o.name}=ON")
  }

  def camkesDir(): Option[Os.Path] = {
    return Os.env(CodegenTest.CAMKES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        val candidate = Os.home / "CASE" / "camkes"
        if (candidate.exists) Some(candidate)
        else None()
    }
  }

  def camkesVmExamplesDir(): Option[Os.Path] = {
    return Os.env(CodegenTest.CAMKES_VM_EXAMPLES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        val candidate = Os.home / "CASE" / "camkes-vm-examples"
        if (candidate.exists) Some(candidate)
        else None()
    }
  }

  def isCI: B = Os.env("GITLAB_CI").nonEmpty || Os.env("GITHUB_ACTIONS").nonEmpty || Os.env("BUILD_ID").nonEmpty

  def inIVE: B =
    Os.env("__CFBundleIdentifier") match {
      case Some(string"com.jetbrains.intellij.ce") => T
      case _ => F
    }


  def proyekive(config: CodegenOption)(pc: SireumProyekIveOption): Z = {
    var args: ISZ[String] = ISZ()

    def addKey(key: String): Unit = {
      args = args :+ key
    }

    def add(key: String, value: String): Unit = {
      args = args :+ key :+ value
    }

    val pathSep: String = Os.pathSep

    if (pc.force) addKey("--force")
    add("--edition", ops.StringOps(pc.edition.name).firstToLower)
    if (pc.ignoreRuntime) addKey("--ignore-runtime")
    if (pc.json.nonEmpty) add("--json", pc.json.get)
    if (pc.name.nonEmpty) add("--name", pc.name.get)
    if (pc.outputDirName.nonEmpty) add("--out", pc.outputDirName.get)
    if (pc.project.nonEmpty) add("--project", pc.project.get)
    if (pc.slice.nonEmpty) add("--slice", st"""${(pc.slice, ",")}""".render)
    if (pc.symlink) addKey("--symlink")
    if (pc.versions.nonEmpty) add("--versions", st"""${(pc.versions, pathSep)}""".render)
    if (pc.cache.nonEmpty) add("--cache", pc.cache.get)
    if (pc.docs) addKey("--no-docs")
    if (pc.sources) addKey("--no-sources")
    if (pc.repositories.nonEmpty) add("--repositories", st"""${(pc.repositories, ",")}""".render)
    if (pc.args.nonEmpty) args = args ++ pc.args

    val sireum: Os.Path = TestUtil.getSireum

    args = ISZ[String](sireum.value, "proyek", "ive") ++ args

    println("Generating IVE project via callback ...")
    val results = Os.proc(args).console.run()

    return results.exitCode

  }

  def slangcheck(config: CodegenOption)(sc: SireumToolsSlangcheckGeneratorOption, reporter: Reporter): Z = {
    var args: ISZ[String] = ISZ()

    def addKey(key: String): Unit = {
      args = args :+ key
    }

    def add(key: String, value: String): Unit = {
      args = args :+ key :+ value
    }

    val pathSep: String = Os.pathSep

    add("--package", st"${(sc.packageName, ".")}".render)
    add("--output-dir", sc.outputDir.get)
    assert(sc.testDir.isEmpty, "Need to handle slangcheck test dir option")
    args = args ++ sc.args

    val sireum: Os.Path = TestUtil.getSireum

    Os.path(sc.outputDir.get).mkdirAll()

    args = ISZ[String](sireum.value, "tools", "slangcheck", "generator") ++ args

    val results = Os.proc(args).console.run()
    return results.exitCode
  }

  def sergen(config: CodegenOption)(tc: SireumToolsSergenOption, reporter: Reporter): Z = {
    var args: ISZ[String] = ISZ()

    def addKey(key: String): Unit = {
      args = args :+ key
    }

    def add(key: String, value: String): Unit = {
      args = args :+ key :+ value
    }

    val pathSep: String = Os.pathSep

    add("--modes", st"${(for (m <- tc.modes) yield ops.StringOps(m.name).firstToLower, ",")}".render)
    add("--package", st"${(tc.packageName, ".")}".render)
    assert(tc.name.isEmpty, "Need to handle sergen custom names")
    assert(tc.license.isEmpty, "Need to handle sergen license")
    add("--output-dir", tc.outputDir.get)

    args = args ++ tc.args

    val sireum: Os.Path = TestUtil.getSireum

    args = ISZ[String](sireum.value, "tools", "sergen") ++ args

    Os.path(tc.outputDir.get).mkdirAll()

    val results = Os.proc(args).console.run()

    return results.exitCode
  }

  def transpile(config: CodegenOption)(tc: SireumSlangTranspilersCOption, reporter: Reporter): Z = {
    var args: ISZ[String] = ISZ()

    def addKey(key: String): Unit = {
      args = args :+ key
    }

    def add(key: String, value: String): Unit = {
      args = args :+ key :+ value
    }

    val pathSep: String = Os.pathSep

    args = args :+ "--sourcepath" :+ st"""${(tc.sourcepath, pathSep)}""".render
    tc.output.map(s => add("--output-dir", s))
    tc.projectName.map(s => add("--name", s))
    addKey("--strict-aliasing")
    add("--apps", st"""${(tc.apps, ",")}""".render)
    add("--fingerprint", tc.fingerprint.string)
    add("--bits", tc.bitWidth.string)
    add("--string-size", tc.maxStringSize.string)
    add("--sequence-size", tc.maxArraySize.string)
    if (tc.customArraySizes.nonEmpty) add("--sequence", st"""${(tc.customArraySizes, ";")}""".render)
    if (tc.customConstants.nonEmpty) add("--constants", st"""${(tc.customConstants, ";")}""".render)
    if (tc.forwarding.nonEmpty) add("--forward", st"""${(tc.forwarding, ",")}""".render)
    tc.stackSize.map(s => add("--stack-size", s))
    if (tc.stableTypeId) addKey("--stable-type-id")
    if (tc.exts.nonEmpty) add("--exts", st"""${(tc.exts, pathSep)}""".render)
    if (tc.libOnly) addKey("--lib-only")
    if (tc.verbose) addKey("--verbose")
    if (tc.cmakeIncludes.nonEmpty) add("--cmake-includes", st"""${(tc.cmakeIncludes, ",")}""".render)

    //args.foreach(p => println(p))

    val sireum: Os.Path = TestUtil.getSireum

    args = ISZ[String](sireum.value, "slang", "transpiler", "c") ++ args

    // transpiler callback method will be expensive for sel4 projects since
    // each will be done in separate JVM instances (unlike when run from
    // OSATE or via the transpile scripts) so only do it when explicitly requested
    val ret: Z = if (Os.envs.contains("ALSO_TRANSPILE_VIA_CALLBACKS")) {
      println(s"Transpiling ${config.platform} via callback ...")
      val results = Os.proc(args).console.run()
      results.exitCode
    } else {
      0
    }

    return ret
  }

  def cygwinInstalled(): B = {
    return proc"reg query HKEY_LOCAL_MACHINE\\Software\\Cygwin\\setup /v rootdir".run().ok
  }


  def writeExpected(normalizedResultMap: TestResult, expected: Os.Path): Unit = {
    expected.writeOver(TestJSON.fromTestResult(normalizedResultMap, F))
  }

  def readExpected(expected: Os.Path): TestResult = {
    return TestJSON.toTestResult(expected.read).left
  }

  def convertToTestResult(resources: ISZ[Resource], resultsDir: Os.Path): TestResult = {
    def normalize(t: TestResult): TestResult = {
      val nmap: ISZ[(String, TestResource)] = t.map.entries.map(m => {

        val dstPath: String =
          if (Os.isWin) {
            ops.StringOps(m._1).replaceAllChars('\\', '/')
          }
          else {
            m._1
          }

        m._2 match {
          case i: ITestResource =>
            val content: String = {
              val lineSep: String = if (Os.isWin) "\r\n" else "\n" // ST render uses System.lineSep
              val replace: String = if (i.makeCRLF) "\r\n" else "\n"
              if (lineSep == replace)
                i.content
              else
                ops.StringOps(i.content).replaceAllLiterally(lineSep, replace)
            }
            (dstPath, ITestResource(content = content, overwrite = i.overwrite, makeExecutable = i.makeExecutable, makeCRLF = i.makeCRLF, markers = i.markers, invertMarkers = i.invertMarkers, isDatatype = i.isDatatype))

          case e: ETestResource =>
            (dstPath, ETestResource(content = e.content, symlink = e.symlink))
        }
      })
      return TestResult(Map(nmap))
    }

    var map = Map.empty[String, TestResource]
    for (r <- resources) {
      r match {
        case r: FileResource =>
          val key = resultsDir.relativize(Os.path(r.dstPath)).value
          r match {
            case i: InternalResource =>
              val testMarkers = i.markers.map((m: Marker) => TestMarker(beginMarker = m.beginMarker, endMarker = m.endMarker))
              map = map + (key, ITestResource(
                content = i.content.render,
                overwrite = i.overwrite,
                makeExecutable = i.makeExecutable,
                makeCRLF = i.makeCRLF,
                markers = testMarkers,
                invertMarkers = i.invertMarkers,
                isDatatype = i.isDatatype))
            case e: ExternalResource =>
              val src = resultsDir.relativize(Os.path(e.srcPath)).value
              val dst = resultsDir.relativize(Os.path(e.dstPath)).value
              map = map + (key, ETestResource(src, e.symLink))
          }
        case _ =>
      }
    }
    return normalize(TestResult(map))
  }
}


object CodegenTestSuite {

  import org.sireum.$internal.CollectionCompat.Converters._

  val taskMap: scala.collection.mutable.Map[String, Map[String, ISZ[Z]]] = (new java.util.concurrent.ConcurrentHashMap[String, Map[String, ISZ[Z]]]().asInstanceOf[java.util.Map[String, Map[String, ISZ[Z]]]]).asScala
}

trait CodegenTestSuite extends TestSuite with BeforeAndAfterAll {

  def add(key: String, time: Z): Unit = {
    var suiteResults: Map[String, ISZ[Z]] = CodegenTestSuite.taskMap.getOrElse(this.suiteName, Map.empty)
    suiteResults = suiteResults + (key ~> (suiteResults.getOrElse(key, ISZ[Z]()) :+ time))
    CodegenTestSuite.taskMap.put(this.suiteName, suiteResults)
  }

  override def beforeAll(): Unit = {
    CodegenTestSuite.taskMap.remove(this.suiteName)
  }

  override def afterAll(): Unit = {
    println(s"\nFinished ${this.suiteName}")
    println(s"\nTiming Info for ${CodegenTestSuite.taskMap.size} test suites: ${CodegenTestSuite.taskMap.keySet}")
    var cumulative = Map.empty[String, ISZ[Z]]
    for (suite <- CodegenTestSuite.taskMap;
         task <- suite._2.entries) {
      cumulative = cumulative + (task._1 ~> (cumulative.getOrElse(task._1, ISZ[Z]()) ++ task._2))
    }

    for (task <- cumulative.entries) {
      val ms: Z = task._2.elements.foldLeft[Z](0)(_ + _)
      println(s"  ${task._1} took ${ms / 1000} seconds (${ms / 60000} min) for ${task._2.size} tests")
    }
  }
}