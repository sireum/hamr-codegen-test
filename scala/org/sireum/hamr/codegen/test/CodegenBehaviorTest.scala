package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}
import org.sireum.hamr.codegen.common.util._
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.util.TestModeHelper.getEnvTestModes
import org.sireum.hamr.codegen.test.util.{CodegenTestSuite, TestMode, TestUtil}
import org.sireum.message.Reporter

trait CodegenBehaviorTest extends CodegenTestSuite {

  // Initialize to use only test modes received from environment
  def testModes: ISZ[TestMode.Type] = getEnvTestModes() ++
    ISZ(TestMode.sergen, TestMode.slangcheck)

  def justRegenerate: B = Os.env("HAMR_REGEN_EXPECTED").nonEmpty // ignore test modes

  def disablePhantom: B = F // useful when changes to OSATE/AIR have not yet been pushed as plugin releases

  def filter: B = F

  def filters: ISZ[String] = ISZ("simple_temp_aadl-sporadic")

  def ignores: ISZ[String] = ISZ()

  def verbose: B = {
    return ops.ISZOps(testModes).contains(TestMode.verbose)
  }

  def logikaOptions: Option[String] = {
    return Some("--rlimit 1000000 --timeout 2000")
  }

  // recursively finds files whose name begin with '.hamrtest', case insensitive,
  // suffix ignored (e.g. .hamrtest, .hamrTest_case01)
  def locateHamrTestFiles(root: Os.Path): ISZ[Os.Path] = {
    var testRoots: ISZ[Os.Path] = ISZ()

    def locate(f: Os.Path): Unit = {
      assert(f.isDir)
      for (item <- f.list) {
        if (item.isDir) {
          locate(item)
        } else if (ops.StringOps(ops.StringOps(item.name).toLower).startsWith(".hamrtest")) {
          testRoots = testRoots :+ item
        }
      }
    }

    locate(root)
    return testRoots
  }

  def test(testName: String,
           testDescription: String,
           testOptions: CodegenOption,
           testModes: ISZ[TestMode.Type],
           phantomOptions: Option[String],
           logikaOptions: Option[String],
           clean: () => B,
           airFile: Option[Os.Path] = None())(implicit position: org.scalactic.source.Position): Unit = {
    val tags: ISZ[org.scalatest.Tag] = ISZ()

    if (ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerIgnoredTest(s"${testName} L${position.lineNumber}", tags.elements: _*)(
        testAir(testName, testDescription, testOptions, testModes, phantomOptions, logikaOptions, clean, airFile))
    }
    else if (!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerTest(s"${testName} L${position.lineNumber}", tags.elements: _*)(
        testAir(testName, testDescription, testOptions, testModes, phantomOptions, logikaOptions, clean, airFile))
    }
  }

  def testAir(testName: String,
              testDescription: String,
              testOptions: CodegenOption,
              testModes: ISZ[TestMode.Type],
              phantomOptions: Option[String],
              logikaOptions: Option[String],
              clean: () => B,
              airFile: Option[Os.Path] = None()): Unit = {

    if (TestUtil.isCI && Os.env("SEL4_CAMKES_ENV").nonEmpty && !TestUtil.isSeL4(testOptions.platform)) {
      cancel("Skipping non-seL4 test")
    }

    var _testModes = testModes
    if (justRegenerate) {
      _testModes = testModes.filter(f => f == TestMode.slangcheck || f == TestMode.sergen)

      println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
      println("!!  Ignoring Test Modes : Just Regenerating  !!")
      println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
      println()
      println(s"  _testModes=${_testModes}")
    }

    println(s"Cleaning $testName")
    assert(clean(), "Cleaning failed")

    // FIXME: Output from individual unit tests were not grouping correctly in intellij's Test Results view.
    //        Seems sleeping for a bit or doing something that takes awhile (e.g. loading AIR) resolves the issue.
    //        See https://youtrack.jetbrains.com/issue/IDEA-66683.  One of the duplicated issues mentioned sleeping

    //Thread.sleep(1000)

    val model = airFile match {
      case Some(a) => TestUtil.getModel(Some(a), phantomOptions, Os.path(testOptions.workspaceRootDir.get), _testModes, testName, verbose)
      case _ => TestUtil.getModel(phantomOptions, Os.path(testOptions.workspaceRootDir.get), _testModes, testName, verbose)
    }

    if (testDescription.size > 0) {
      cprintln(F, testDescription)
    }

    assert(testOptions.workspaceRootDir.nonEmpty, "Currently requires workspaceRootDir to be populated")

    val slangOutputDir: Option[Os.Path] =
      if (testOptions.slangOutputDir.nonEmpty) Some(Os.path(testOptions.slangOutputDir.get))
      else None()

    if (slangOutputDir.nonEmpty) {
      cprintln(F, s"Slang Output Directory: ${slangOutputDir.get.canon.toUri}")
    }

    if (verbose) {
      cprintln(F, s"Test Modes: ${_testModes}")
    }

    val reporter = Reporter.create

    val plugins = ArsitPlugin.gumboEnhancedPlugins() ++ MicrokitPlugins.defaultMicrokitPlugins


    val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
      CodegenReporting.emptyToolReport, Map.empty)

    val results = CodeGen.codeGen(model, T, testOptions, plugins, store, reporter,
      (SireumSlangTranspilersCOption, Reporter) => {
        0
      },
      (SireumProyekIveOption) => {
        0
      },
      TestUtil.sergen(testOptions) _,
      TestUtil.slangcheck(testOptions) _
    )

    var success = !reporter.hasError
    if (success) {
      success = TestUtil.runAdditionalTasks(
        testName,
        testOptions,
        _testModes,
        logikaOptions,
        verbose,
        this,
        reporter)
      success = success && !reporter.hasError
    }

    if (Os.env("GITHUB_ACTIONS").nonEmpty && slangOutputDir.nonEmpty) {
      // 2024.02.16 -- running out of space in camkes docker container on github
      (slangOutputDir.get / "out").removeAll()
    }

    assert(success, s"Test failed: ${testName}")
  }

  def ignoreTest(testName: String,
                 testDescription: String)(implicit position: org.scalactic.source.Position): Unit = {

    val _testName = s"${testName} L${position.lineNumber}"

    // TODO: would be nice if the following was attached to the outline view
    cprintln(T,
      st"""Ignoring ${_testName}
          |  $testDescription""".render)

    registerIgnoredTest(_testName)({})
  }

  def genTestFromFile(hamrTestFile: Os.Path)(implicit position: org.scalactic.source.Position): Unit = {
    val props = hamrTestFile.properties

    var ignoreReasons: ISZ[String] = ISZ()

    if (!props.contains("testName")) {
      cprint(T, s"Property file must contain 'testName' entry: ${hamrTestFile.value}")
      return
    }

    val testName = props.get("testName").get

    var unitTestModes: ISZ[TestMode.Type] =
      testModes ++ CodegenBehaviorTest.getUnitTestModes(props.get("testModes"))

    if(disablePhantom && ops.ISZOps(unitTestModes).contains((TestMode.phantom))) {
      println("!!!!!!!!!!!!!!!!!!!!!!")
      println("!! Phantom Disabled !!")
      println("!!!!!!!!!!!!!!!!!!!!!!")
      unitTestModes = unitTestModes - TestMode.phantom
    }

    val airFile = CodegenBehaviorTest.getAirFileEntry(props.get("airFile"), hamrTestFile.up.canon)

    val cleanCmd =
      if ((hamrTestFile.up / "bin" / "clean.cmd").exists) hamrTestFile.up / "bin" / "clean.cmd"
      else if ((hamrTestFile.up / "aadl" / "clean.cmd").exists) hamrTestFile.up / "aadl" / "clean.cmd"
      else hamrTestFile.up / "clean.cmd"

    assert (cleanCmd.exists, s"${cleanCmd} does not exists")
    val clean = () => proc"${cleanCmd}".at(cleanCmd.up).run().ok

    var overrideIgnore = F
    if (airFile.isEmpty && !ops.ISZOps(unitTestModes).contains(TestMode.phantom)) {
      ignoreReasons = ignoreReasons :+ s"Either provide 'airFile' entry or enable phantom test mode"
      overrideIgnore = T
    }

    if (!props.contains("hamrArgs")) {
      cprint(T, s"Property file must contain 'hamrArgs' entry: ${hamrTestFile.value}")
      return
    }

    val hamrOpts = CodegenBehaviorTest.processHamrArgs(props.get("hamrArgs").get, hamrTestFile.up)

    if (hamrOpts.isEmpty) {
      cprint(T, s"The 'hamrArgs' entry did not parse: ${hamrTestFile.value}")
      return
    }

    val logikaOptions = props.get("logikaOptions")
    val phantomOptions = props.get("phantomOptions")

    var testOps = hamrOpts.get
    if (verbose) {
      testOps = testOps(verbose = verbose)
    }

    val label = s"From test properties file: ${hamrTestFile.canon.toUri}"
    if (overrideIgnore || CodegenBehaviorTest.shouldIgnore(props)) {
      val testDescription =
        st"""Ignoring ${testName} from ${hamrTestFile.toUri}
            |  ${(ignoreReasons, "\n")}""".render
      ignoreTest(testName, testDescription)(position)
    } else {
      test(testName, label, testOps, unitTestModes, phantomOptions, logikaOptions, clean, airFile)(position)
    }
  }


  val baseOptions = CodegenOption(
    help = "",
    args = ISZ(),
    msgpack = F,
    verbose = F,
    runtimeMonitoring = F,
    platform = CodegenHamrPlatform.JVM,
    outputDir = None(),
    parseableMessages = F,
    //
    slangOutputDir = None(),
    packageName = None(),
    noProyekIve = T,
    noEmbedArt = F,
    devicesAsThreads = T,
    genSbtMill = T,
    //
    slangAuxCodeDirs = ISZ(),
    slangOutputCDir = None(),
    excludeComponentImpl = F,
    bitWidth = 64,
    maxStringSize = 256,
    maxArraySize = 1,
    runTranspiler = F,
    //
    sel4OutputDir = None(),
    sel4AuxCodeDirs = ISZ(),
    workspaceRootDir = None(),
    //
    strictAadlMode = F,
    ros2OutputWorkspaceDir = None(),
    ros2Dir = None(),
    ros2NodesLanguage = CodegenNodesCodeLanguage.Cpp,
    ros2LaunchLanguage = CodegenLaunchCodeLanguage.Xml,
    invertTopicBinding = F,
    //
    experimentalOptions = ISZ(ExperimentalOptions.GENERATE_REFINEMENT_PROOF)
  )
}


object CodegenBehaviorTest {
  def getAirFileEntry(value: Option[String], rootDir: Os.Path): Option[Os.Path] = {
    assert(rootDir.isDir, s"Expecting a directory: ${rootDir}")
    val ret: Option[Os.Path] = value match {
      case Some(f) =>
        val cand = (rootDir / f).canon
        if (cand.exists) {
          Some(cand)
        } else {
          cprintln(T, s"Did not find AIR file at ${cand.canon.toUri}")
          None()
        }
      case _ => None()
    }
    return ret
  }


  def shouldIgnore(props: Map[String, String]): Boolean = {
    val ret: B = props.get("ignore") match {
      case Some(string"true") => true
      case Some(string"T") => true
      case Some(string"false") => false
      case Some(string"F") => false
      case Some(x) =>
        cprintln(T, s"'ignore' entry must be boolean: ${x}")
        F
      case _ => false
    }
    return ret
  }

  def getUnitTestModes(props: Option[String]): ISZ[TestMode.Type] = {
    var ret: ISZ[TestMode.Type] = ISZ()
    props match {
      case Some(list) =>
        for (cand <- ops.StringOps(list).split((c: C) => c == C(','))) {
          TestMode.byName(ops.StringOps(cand).trim) match {
            case Some(x) => ret = ret :+ x
            case _ =>
              cprintln(T, s"$cand is not a valid TestMode")
          }
        }
      case _ =>
    }
    return ret
  }

  def processHamrArgs(args: String, root: Os.Path): Option[CodegenOption] = {
    assert(root.isDir, root)
    val _args: ISZ[String] = ops.StringOps(args).split(c => c == C(' '))
    return processHamrArgsH(_args, root)
  }

  def processHamrArgsH(args: ISZ[String], root: Os.Path): Option[CodegenOption] = {
    assert(root.isDir, root)

    def canon(opt: Option[String]): Option[String] = {
      val ret: Option[String] = opt match {
        case Some(s) => Some((root / s).canon.value)
        case _ => None()
      }
      return ret
    }

    val ret: Option[CodegenOption] = HamrCli(Os.pathSepChar).parseCodegen(args, 0) match {
      case Some(opts: CodegenOption) =>

        val aadlRoot = if (opts.workspaceRootDir.isEmpty) canon(Some(".")) else canon(opts.workspaceRootDir)

        Some(CodegenOption(
          help = "",
          args = ISZ(),
          msgpack = F,
          verbose = opts.verbose,
          runtimeMonitoring = opts.runtimeMonitoring,
          platform = CodegenHamrPlatform.byName(opts.platform.name).get,
          outputDir = None(),
          parseableMessages = F,

          slangOutputDir = canon(opts.slangOutputDir),
          packageName = opts.packageName,
          noProyekIve = opts.noProyekIve,
          noEmbedArt = opts.noEmbedArt,
          devicesAsThreads = opts.devicesAsThreads,
          genSbtMill = opts.genSbtMill,
          //
          slangAuxCodeDirs = opts.slangAuxCodeDirs.map(s => canon(Some(s)).get),
          slangOutputCDir = canon(opts.slangOutputCDir),
          excludeComponentImpl = opts.excludeComponentImpl,
          bitWidth = opts.bitWidth,
          maxStringSize = opts.maxStringSize,
          maxArraySize = opts.maxArraySize,
          runTranspiler = opts.runTranspiler,
          //
          sel4OutputDir = canon(opts.sel4OutputDir),
          sel4AuxCodeDirs = opts.sel4AuxCodeDirs.map(s => canon(Some(s)).get),
          workspaceRootDir = aadlRoot,
          //
          strictAadlMode = opts.strictAadlMode,
          ros2OutputWorkspaceDir = opts.ros2OutputWorkspaceDir,
          ros2Dir = opts.ros2Dir,
          ros2NodesLanguage = CodegenNodesCodeLanguage.byName(opts.ros2NodesLanguage.name).get,
          ros2LaunchLanguage = CodegenLaunchCodeLanguage.byName(opts.ros2LaunchLanguage.name).get,
          invertTopicBinding = opts.invertTopicBinding,
          //
          experimentalOptions = opts.experimentalOptions
        ))

      case _ => None()
    }
    return ret
  }
}
