package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.act.templates.{SlangEmbeddedTemplate}
import org.sireum.hamr.act.util.CMakeOption
import org.sireum.hamr.act.vm.VM_Template
import org.sireum.hamr.codegen._
import org.sireum.hamr.codegen.common.containers.{ProyekIveConfig, TranspilerConfig}
import org.sireum.hamr.codegen.common.util.{CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform, CodeGenResults, ExperimentalOptions}
import org.sireum.hamr.codegen.common.util.test.{ETestResource, ITestResource, TestResult, TestUtil}
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.hamr.ir._
import org.sireum.message._
import org.sireum.ops.ISZOps
import org.sireum.test.TestSuite

/** Can regenerate AIR JSON files via 
* https://github.com/sireum/osate-plugin/blob/d0015531e9d2039f7f186c4fa7a124521ee664b6/org.sireum.aadl.osate.tests/src/org/sireum/aadl/osate/tests/extras/AirUpdater.java#L46-L54
*/
trait CodeGenTest extends TestSuite {

  import CodeGenTest._

  def generateExpected: B = F
  def delResultDirIfEqual: B = F

  def ignoreBuildDefChanges: B = F // temporarily ignore build.sbt and build.sc changes due to build.properties updates

  // e.g. from command line:
  //   HamrTestModes=generated_unit_test,compile,camkes sireum proyek test ...
  def testModes: ISZ[TestMode.Type] = Os.env("HamrTestModes") match {
    case Some(list) => ops.StringOps(list).split((c: C) => c ==C(',')).map((m: String) => TestMode.byName(m).get)
    case _ => ISZ(TestMode.codegen)
    //case _ => ISZ(TestMode.codegen, TestMode.smt2)
  }

  def smt2Timeout: Z = Os.env("SMT2_TIMEOUT") match {
    case Some(t) => Z(t).get
    case _ => 2 * 60000
  }

  def verbose: B = { return ops.ISZOps(testModes).contains(TestMode.verbose) }

  def testResources(): scala.collection.Map[scala.Vector[Predef.String], Predef.String]

  def filter: B = if(filterTestsSet().nonEmpty) filterTestsSet().get else F
  def filters: ISZ[String] = ISZ("vm")

  def ignores: ISZ[String] = ISZ(
    "uav_alt_extern--SeL4", // ignoring as has sel4 dataport with 512 elems so bigger than 4096
  )

  val (rootExpectedDir, rootResultDir, baseModelsDir) = getDirectories(testResources())

  //def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig)(implicit position: org.scalactic.source.Position) : Unit = {
  //  test(testName, modelDir, airFile, ops, T)
  //}

  //def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig, shouldPass: B)(implicit position: org.scalactic.source.Position) : Unit = {
  //  test(testName, modelDir, airFile, ops, None(), None(), None(), shouldPass)
  //}

  def test(testName: String,
           modelDir: Os.Path,
           airFile: Option[Os.Path],
           ops: CodeGenConfig,
           resultDir:Option[String],
           description: Option[String],
           modelUri: Option[String],
           expectedErrorReasons: ISZ[String] // empty if errors not expected
          )(implicit position: org.scalactic.source.Position) : Unit = {
    var tags: ISZ[org.scalatest.Tag] = ISZ()

    if(ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))){
      registerIgnoredTest(s"${testName} L${position.lineNumber}", tags.elements:_*)(
        testAir(testName, modelDir, airFile, ops, resultDir, description, modelUri, expectedErrorReasons))
    }
    else if(!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerTest(s"${testName} L${position.lineNumber}", tags.elements:_*)(
        testAir(testName, modelDir, airFile, ops, resultDir, description, modelUri, expectedErrorReasons))
    }
  }

  def testAir(testName: String,
              modelDir: Os.Path,
              airFile: Option[Os.Path],
              config: CodeGenConfig,
              resultDir: Option[String],
              description: Option[String],
              modelUri: Option[String],
              expectedErrorReasons: ISZ[String] // empty if errors not expected
             ): Unit = {

    val expectedJson = rootExpectedDir / getClass.getSimpleName / s"${testName}.json"

    val rootTestOutputDir = if(resultDir.nonEmpty) rootResultDir / resultDir.get / testName else rootResultDir / testName
    val expectedDir = rootTestOutputDir / "expected"
    val resultsDir = rootTestOutputDir / "results"
    val slangOutputDir = resultsDir / testName

    assert(config.slangOutputDir.isEmpty, s"hmm, why custom output dir ${config.slangOutputDir}")

    var testOps = config(
      slangOutputDir = Some(slangOutputDir.canon.value)
    )

    if(isSeL4(testOps.platform)) {
      assert(testOps.camkesOutputDir.isEmpty, s"hmm, why custom camkes dir ${config.camkesOutputDir}")

      testOps = testOps(
        slangOutputDir = Some(s"${slangOutputDir}/slang-embedded"),
        camkesOutputDir = testOps.slangOutputDir,
        aadlRootDir = if(testOps.aadlRootDir.nonEmpty) testOps.aadlRootDir else Some(modelDir.canon.value),
      )
    }

    rootTestOutputDir.removeAll()
    rootTestOutputDir.mkdirAll()

    val reporter = Reporter.create

    val model: Aadl = {
      val s: String = if(ops.ISZOps(testModes).contains(TestMode.phantom) || airFile.isEmpty) {
        val outputFile = modelDir.canon / ".slang" / "testAIR.json"
        outputFile.up.mkdir()
        println("Generating AIR via phantom ...")
        val results = proc"${CodeGenTest.getSireum().value} hamr phantom -f ${outputFile.canon.string} ${modelDir.canon.string}".env(Os.envs.entries).run()
        assert(check(testName, results, "Phantom did not complete successfully"), "Check did not return OK")
        outputFile.read
      } else {
        airFile.get.read
      }
      getModel(s)
    }

    println(s"Result Dir: ${rootTestOutputDir.canon.toUri}")

    // note transpiler will be run via the callback method and via the Slash scripts.
    // proyek ive will only be run via callback
    val results: CodeGenResults = CodeGen.codeGen(model, testOps, reporter,
      if(shouldTranspile(testOps)) transpile (testOps) _ else (TranspilerConfig) => { println("Dummy transpiler"); 0 },
      if(shouldProyekIve(testOps)) proyekive (testOps) _ else (ProyekIveConfig) => { println("Dummy Proyek IVE"); 0 }
    )

    /*
    val results: CodeGenResults = CodeGen.codeGen(model.get, testOps, reporter,
      (TranspilerConfig) => { println("Dummy transpiler"); 0 },
      (ProyekIveConfig) => { println("Dummy Proyek IVE"); 0 }
    )
     */

    if(expectedErrorReasons.isEmpty) {
      assert(!reporter.hasError, "Expecting no errors but codegen did not complete successfully")
    }
    else {
      assert(reporter.hasError, "Expecting errors but codegen completed successfully")
      assert(reporter.errors.size == expectedErrorReasons.size)

      for(m <- reporter.errors) {
        assert(org.sireum.ops.ISZOps(expectedErrorReasons).contains(m.text), s"Expected errors doesn't contain ${m.text}")
      }

      return
    }

    var testFail = F
    if(!reporter.hasError) {
      testFail = runAdditionalTasks(testName, slangOutputDir, testOps, reporter)
    }

    val resultMap = TestUtil.convertToTestResult(results.resources, resultsDir)

    val expectedMap: TestResult = if(generateExpected) {
      TestUtil.writeExpected(resultMap, expectedJson)
      println(s"Wrote: ${expectedJson}")
      resultMap
    }
    else if(expectedJson.exists) {
      TestUtil.readExpected(expectedJson)
    }
    else {
      testFail = T
      Console.err.println(s"Expected does not exist: ${expectedJson}")
      TestResult(Map.empty)
    }

    if(resultMap.map.size != expectedMap.map.size) {
      val ekeys = expectedMap.map.keySet
      val rkeys = resultMap.map.keySet

      val missingEkeys = (ekeys.union(rkeys) -- ekeys.elements).elements
      val missingRkeys = (ekeys.union(rkeys) -- rkeys.elements).elements

      if (missingEkeys.nonEmpty) {
        for(k <- missingEkeys) {
          println(s"Expected missing entry ${k}")
          //println(s"  - ${resultMap.map.get(k).get}")
        }
      } else {
        for(k <- missingRkeys) {
          println(s"Results missing entry ${k}")
          //println(s"  - ${expectedMap.map.get(k)}")
        }
        //rkeys.elements.foreach(f => println(f))
      }
      testFail = T
    }

    var allEqual = T

    // could limit emitted files to only non-matching results
    for(r <- resultMap.map.entries) {

      if(expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= {
          val ignores = ISZOps(ISZ("build.sbt", "build.sc", "versions.properties", "project.cmd"))
          val ignoreFile = ignoreBuildDefChanges && ignores.exists(p => r._1.native.endsWith(p))
          val sameContents = r._2 == e
          if(!sameContents) {
            var reason: ISZ[String] = ISZ()
            ((r._2, e)) match {
              case ((ri: ITestResource, ei: ITestResource)) =>
                if(ri.content != ei.content) reason = reason :+ "content is not the same"
                if(ri.overwrite != ei.overwrite) reason = reason :+ "overwrite flag is not the same"
                if(ri.makeExecutable != ei.makeExecutable) reason = reason :+ "makeExecutable flag is not the same"
                if(ri.makeCRLF != ei.makeCRLF) reason = reason :+ "makeCRLF flag is not the same"
              case ((re: ETestResource, ee: ETestResource)) =>
                if(re.content != ee.content) reason = reason :+ "content is not the same"
                if(re.symlink != ee.symlink) reason = reason :+ "symLink flag is not the same"

              case _ => halt("Infeasible: TestResource types not the same")
            }
            eprintln(st"${r._1} ${(reason, ", ")}".render)
          }
          ignoreFile || sameContents
        }
      } else if(!generateExpected) {
        allEqual = F
        eprintln(s"Expected missing: ${r._1}")
      }

      /*
      if(r._1.native.endsWith("graph.dot")) {
        val dot = r._2.content
        val dotOutput = Os.path(s"${output.value}.pdf")

        val proc:ISZ[String] = ISZ("dot", "-Tpdf", output.canon.value, "-o", dotOutput.canon.value)
        println(proc)
        Os.proc(proc).run()
      }
      */
    }

    for(e <- expectedMap.map.entries) {
      (expectedDir / e._1).canon.writeOver(e._2.content)
    }

    if(allEqual && delResultDirIfEqual) rootTestOutputDir.removeAll()

    if(modelUri.nonEmpty) {
      println(s"Model URI: ${modelUri.get}")
    }

    if(description.nonEmpty) {
      println(st"""Test Description: ${description.get}
                  |----------------""".render)
    }

    assert(allEqual, s"Mismatches in ${rootTestOutputDir.canon.toUri}")

    assert(!testFail, s"test fail in ${rootTestOutputDir.canon.toUri}")
  }

  def runAdditionalTasks(testName: String, testResultsDir: Os.Path, testOps: CodeGenConfig, reporter: Reporter): B = {

    def vproc(commands: String, runInDir: Os.Path, env: ISZ[(String, String)], timeout: Option[Z]): OsProto.Proc.Result = {
      var p = proc"$commands".env(env).at(runInDir)
      if(timeout.nonEmpty) {
        p = p.timeout(timeout.get)
      }
      if(verbose) {
        p = p.console.redirectErr
      }
      return p.run()
    }

    val sireum: Os.Path = CodeGenTest.getSireum()
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
            cand = d.string; i = 65
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
        if(p.isDir) {  for(pp <- p.list if loc.isEmpty ) { r(pp)} }
        else { if(p.name == filename) { loc = loc :+ p }
        }
      }
      r(slangDir)
      assert(loc.size == 1, s"Fetch failed for ${filename}. Found ${loc.size} matches. ${loc}")
      return loc(0).canon
    }

    var keepGoing: B = T
    def check(results: OsProto.Proc.Result, failMsg: String): Unit = {
      keepGoing = CodeGenTest.check(testName, results, failMsg: String)
    }

    if(shouldTranspile(testOps) && keepGoing) {
      if(isLinux(testOps.platform)){
        val transpileScript = fetch("transpile.cmd")

        println(s"Transpiling ${testOps.platform} via script ...")
        val cTranspileResults = vproc(s"${transpileScript.string}", transpileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string)), None())
        check(cTranspileResults, "C transpiling failed")

      } else {
        assert (testOps.platform == CodeGenPlatform.SeL4, s"Hmm, ${testOps.platform}")
        val transpileScript = fetch("transpile-sel4.cmd")

        println(s"Transpiling ${testOps.platform} via script ...")
        val cTranspileResults = vproc(s"${transpileScript.string}", transpileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string)), None())
        check(cTranspileResults, "seL4 transpiling failed")
      }
    }

    if(shouldCompile(testOps.platform) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Compiling Slang project via proyek compile ...")
      val proyekResults = vproc(s"${sireum.string} proyek compile --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      check(proyekResults, "Proyek compilation failed")

      if(isLinux(testOps.platform) && keepGoing) {
        println("Compiling C project via script ...")
        val compileScript = fetch("compile.cmd")

        val cCompileResults = vproc(s"${compileScript.string} -b -r -l", compileScript.up, ISZ(("SIREUM_HOME", sireum.up.up.string), ("MAKE_ARGS", "-j4")), None())
        check(cCompileResults, "C Compilation failed")
      }
    }

    if(shouldRunLogika(testOps) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      val tempOut = Os.tempDir()
      println("Checking Slang project contracts via proyek logika ...")
      val proyekResults = vproc(s"${sireum.string} proyek logika --all --out ${tempOut.value} --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      check(proyekResults, "Proyek logika failed")

      // results still written to <project>/out even if "--out" option is used?  For now
      // just delete it so it doesn't pollute directory diffs
      val outDir = projectCmd.up.up / "out"
      if(outDir.exists) outDir.removeAll()
    }

    if(shouldProyekIve(testOps) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Generating IVE project via proyek ive ...")
      val proyekResults = vproc(s"${sireum.string} proyek ive ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      check(proyekResults, "Proyek ive failed")
    }

    if (shouldRunGeneratedUnitTests(testOps.platform) && keepGoing) {
      val projectCmd = fetch("project.cmd")

      println("Running generated unit tests ...")
      val proyekResults = vproc(s"${sireum.string} proyek test --par ${projectCmd.up.up.string}", projectCmd.up.up, ISZ(), None())
      check(proyekResults, "Proyek test failed")
    }

    if(shouldProve(testOps)) {
      val proof = Os.path(testOps.camkesOutputDir.get) / "proof" / "smt2_case.smt2"
      val cvc = sireumHome / "bin" / os / (if(Os.isWin) "cvc.exe" else "cvc")
      val z3 = sireumHome / "bin" / os / "z3" / "bin" / (if(Os.isWin) "z3.exe" else "z3")

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
      val pr = vproc(s"${cvc.value} -i --finite-model-find ${proof.value}", proof.up, ISZ(), Some(smt2Timeout))
      val pout: String = pr.out
      val isTimeout: B = pr.exitCode === 6 || pr.exitCode === -101 || pr.exitCode === -100
      if (pout.size == 0 && pr.exitCode != 0 && !isTimeout) {
        err(pout, pr.exitCode)
      }

      val duration = extension.Time.currentMillis - startTime

      if(verbose) {
        println(s"Refinement proof duration: $duration ms")
      }

      val out = ops.StringOps(ops.StringOps(pout).replaceAllLiterally("\r\n", "\n")).split((c: C) => c == C('\n'))
      if(isTimeout || out.size != 10) {
        cprintln(T, s"${if(isTimeout) s"Timed-out after ${duration} ms. " else ""}Expecting 10 lines but got ${out.size}")
        cprintln(T, pr.out)
        keepGoing = F
      } else {
        var accum: B = T
        def scheck(b: B, errorMsg: String): Unit = { if(!b) cprintln(T, errorMsg); accum = accum & b }
        def scheckH(a: String, b: String): Unit = { if(a != b) cprintln(T, s"Expecting '${a} but received ${b}'"); accum = accum & (a == b) }

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

    if(shouldCamkes(testOps.platform) && keepGoing) {
      val hasVMs: B = reporter.messages.filter(m => org.sireum.ops.StringOps(m.text)
        .contains("Execute the following to install the CAmkES-ARM-VM project:")).nonEmpty

      val rootCamkesDir: Option[Os.Path] =
        if(hasVMs) { camkesArmVMDir() }
        else { camkesDir() }

      rootCamkesDir match {
        case Some(camkesDir) => {
          val runCamkes = Os.path(testOps.camkesOutputDir.get) / "bin" / "run-camkes.sh"
          assert(runCamkes.exists, s"${runCamkes} doesn't exist")

          val camkesBuildDir = camkesDir / s"build_${testName}"
          camkesBuildDir.removeAll()

          def onOptions(options: ISZ[CMakeOption]): ISZ[(String, String)] = { return options.map(o => (o.name, "ON")) }

          var camkesEnv: ISZ[(String, String)] = ISZ()

          if(testOps.platform == CodeGenPlatform.SeL4) {
            val toptions = SlangEmbeddedTemplate.TRANSPILER_OPTIONS.filter(c => c.name != string"NO_PRINT")
            camkesEnv = camkesEnv ++ onOptions(toptions)
          }

          // would only want to enable cakeml assemblies if they are built ahead of time
          // which would mean the CI would need to do that as too expensive/large to
          // check the binaries into git
          //camkesArgs = camkesArgs ++ onOptions(CakeMLTemplate.CAKEML_OPTIONS)


          //camkesArgs = camkesArgs :+ s"-DCAMKES_APP=${name}"

          if(hasVMs) {
            camkesEnv = camkesEnv ++ onOptions(VM_Template.VM_CMAKE_OPTIONS)
          }

          println("Running CAmkES build ...")
          val camkesResults = vproc(s"${runCamkes.value} -n", runCamkes.up, camkesEnv, None())
          check(camkesResults, "CAmkES build failed")

          //val results = Proc(ISZ("simulate"), Os.cwd, Map.empty, T, None(), F, F, F, F, F, timeout, F).at(camkesBuildDir).run()
         }
        case _ =>
          assert(F, "CAmkES directory not found")
      }
    }

    if(Os.isWin) {
      println(s"Attempting to unsubst ${optSubstDrive}")
      proc"subst ${optSubstDrive} /D".run()
    }

    return !keepGoing // ie. no failure occurred
  }

  def getModel(s: String): Aadl = {
    return JSON.toAadl(s) match {
      case Either.Left(m) => m
      case Either.Right(m) =>
        halt(s"Json deserialization error at (${m.line}, ${m.column}): ${m.message}")
    }
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

  def shouldCamkes(platform: CodeGenPlatform.Type): B = {
    return isSeL4(platform) && ops.ISZOps(testModes).contains(TestMode.camkes)
  }

  def shouldProve(config: CodeGenConfig): B = {
    val platform = config.platform
    return { //
      (platform == CodeGenPlatform.SeL4 || platform == CodeGenPlatform.SeL4_Only) &&
        ops.ISZOps(testModes).contains(TestMode.smt2)
    }
  }

  def shouldCompile(platform: CodeGenPlatform.Type): B = {
    return isSlang(platform) && ops.ISZOps(testModes).contains(TestMode.compile)
  }

  def shouldRunGeneratedUnitTests(platform: CodeGenPlatform.Type): B = {
    return isSlang(platform) && ops.ISZOps(testModes).contains(TestMode.generated_unit_tests)
  }

  def shouldRunLogika(config: CodeGenConfig): B = {
    return isSlang(config.platform) && ops.ISZOps(testModes).contains(TestMode.logika)
  }

  def shouldTranspile(testOps: CodeGenConfig): B = {
    val platform = testOps.platform
    val _ops = ops.ISZOps(testModes)
    return (testOps.runTranspiler && (isLinux(platform) || platform == CodeGenPlatform.SeL4)) ||
      (_ops.contains(TestMode.transpile) && (isLinux(platform) || platform == CodeGenPlatform.SeL4)) ||
      (_ops.contains(TestMode.compile) && isLinux(platform)) ||
      (_ops.contains(TestMode.camkes) && platform == CodeGenPlatform.SeL4)
  }

  def shouldProyekIve(config: CodeGenConfig): B = {
    return !config.noProyekIve || shouldCompile(config.platform)
  }

  def onOptions(options: ISZ[CMakeOption]): ISZ[String] = { return options.map(o => s"-D${o.name}=ON") }
}

object CodeGenTest {

  val CAMKES_DIR = "CAMKES_DIR"
  val CAMKES_ARM_VM_DIR = "CAMKES_ARM_VM_DIR"

  val FILTER = "FILTER"

  val baseOptions = CodeGenConfig(
    writeOutResources = T,
    ipc = CodeGenIpcMechanism.SharedMemory,

    verbose = F,
    platform = CodeGenPlatform.JVM,
    slangOutputDir = None(),
    packageName = None(),
    noProyekIve = T,
    noEmbedArt = F,
    devicesAsThreads = T,
    slangAuxCodeDirs = ISZ(),
    slangOutputCDir = None(),
    excludeComponentImpl = F,
    bitWidth = 64,
    maxStringSize = 256,
    maxArraySize = 1,
    runTranspiler = F,
    camkesOutputDir = None(),
    camkesAuxCodeDirs = ISZ(),
    aadlRootDir = None(),
    experimentalOptions = ISZ(ExperimentalOptions.GENERATE_REFINEMENT_PROOF)
  )

  def filterTestsSet(): Option[B] = {
    return if (Os.env(FILTER).nonEmpty) return Some(Os.env(FILTER).get.native.toBoolean) else None()
  }

  def camkesDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        eprintln(s"${CodeGenTest.CAMKES_DIR} environment variable not set !!!!")
        val candidate = Os.home / "CASE" / "camkes"
        if (candidate.exists) {
          eprintln(s"Found ${candidate} so using that")
          Some(candidate)
        } else {
          None()
        }
    }
  }

  def camkesArmVMDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_ARM_VM_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        eprintln(s"${CodeGenTest.CAMKES_ARM_VM_DIR} environment variable not set!!!")
        val candidate = Os.home / "CASE" / "camkes-arm-vm"
        if (candidate.exists) {
          eprintln(s"Found ${candidate} so using that")
          Some(candidate)
        } else {
          None()
        }
    }
  }

  def proyekive(config: CodeGenConfig)(pc: ProyekIveConfig): Z = {
    var args: ISZ[String] = ISZ()
    def addKey(key: String): Unit = { args = args :+ key }
    def add(key: String, value: String): Unit = { args = args :+ key :+ value }
    val pathSep: String = Os.pathSep

    if(pc.force) addKey("--force")
    if(pc.ultimate) addKey("--ultimate")
    if(pc.ignoreRuntime) addKey("--ignore-runtime")
    if(pc.json.nonEmpty) add("--json", pc.json.get)
    if(pc.name.nonEmpty) add("--name", pc.name.get)
    if(pc.outputDirName.nonEmpty) add("--out", pc.outputDirName.get)
    if(pc.project.nonEmpty) add("--project", pc.project.get)
    if(pc.slice.nonEmpty) add("--slice", st"""${(pc.slice, ",")}""".render)
    if(pc.symlink) addKey("--symlink")
    if(pc.versions.nonEmpty) add("--versions", st"""${(pc.versions, pathSep)}""".render)
    if(pc.cache.nonEmpty) add("--cache", pc.cache.get)
    if(pc.docs) addKey("--no-docs")
    if(pc.sources) addKey("--no-sources")
    if(pc.repositories.nonEmpty) add("--repositories", st"""${(pc.repositories, ",")}""".render)
    if(pc.args.nonEmpty) args = args ++ pc.args

    val sireum: Os.Path = CodeGenTest.getSireum()

    args = ISZ[String](sireum.value, "proyek", "ive") ++ args

    println("Generating IVE project via callback ...")
    val results = Os.proc(args).console.run()

    return results.exitCode

  }

  def transpile(config: CodeGenConfig)(tc: TranspilerConfig): Z = {
    var args: ISZ[String] = ISZ()
    def addKey(key: String): Unit = { args = args :+ key }
    def add(key: String, value: String): Unit = { args = args :+ key :+ value }
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

    val sireum: Os.Path = CodeGenTest.getSireum()

    args = ISZ[String](sireum.value, "slang", "transpiler", "c") ++ args

    // transpiler callback method will be expensive for sel4 projects since
    // each will be done in separate JVM instances (unlike when run from
    // OSATE or via the transpile scripts) so only do it when explicitly requested
    val ret: Z = if(Os.envs.contains("ALSO_TRANSPILE_VIA_CALLBACKS")) {
      println(s"Transpiling ${config.platform} via callback ...")
      val results = Os.proc(args).console.run()
      results.exitCode
    } else {
      0
    }

    return ret
  }

  def getSireum(): Os.Path= { return Os.cwd / "bin" / (if (Os.isWin) "sireum.bat" else "sireum") }

  def check(testName: String, results: OsProto.Proc.Result, failMsg: String): B = {
    if(!results.ok) {
      println(s"${testName}: ${failMsg}")
      println("out:")
      println(results.out)
      println("err:")
      println(results.err)
    }
    return results.ok
  }

  def getDirectories(testResources : scala.collection.Map[scala.Vector[Predef.String], Predef.String]): (Os.Path, Os.Path, Os.Path) = {
    val intellijTestDir = Os.path("./hamr/codegen/jvm/src/test/scala")
    val (expected, results, models) : (Os.Path, Os.Path, Os.Path) = {
      if(intellijTestDir.exists) {
        // use local/intellij copy
        (intellijTestDir / "expected", intellijTestDir.up / "results", intellijTestDir / "models")
      } else {
        // probably running from jar so copy resources to a temp directory
        val temp: Os.Path = Os.tempDir()

        for (entry <- testResources) {
          assert(entry._1.head == "expected" || entry._1.head == "models")

          val f = temp / entry._1.mkString("/")

          f.writeOverU8s(conversions.String.fromBase64(entry._2).left)

          //println(s"Wrote: ${f}")

          if (f.up.name.native == ".slang" && f.ext.native == "zip") {
            f.unzipTo(f.up)

            val jsonFile = f.up / ops.StringOps(f.name).substring(0, f.name.size - 4)
            if (!jsonFile.exists) {
              halt(s"${jsonFile} not unzipped")
            }
            //println(s"Unzipped: ${f}")
          }
        }
        (temp / "expected", temp / "results", temp / "models")
      }
    }
    results.mkdirAll()
    return (expected, results, models)
  }
}
