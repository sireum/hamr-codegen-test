package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.common.util.{CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform, CodeGenResults}
import org.sireum.hamr.codegen.test.util.Cli.{CodegenHamrPlatform, CodegenOption}
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

trait CodegenBehaviorTest extends TestSuite {

  def testModes: ISZ[TestMode.Type] = {
    val envModes = CodegenBehaviorTest.getUnitTestModes(Os.env("HamrTestModes"))
    if (envModes.nonEmpty) envModes
    else ISZ()
  }

  def verbose: B = {
    return ops.ISZOps(testModes).contains(TestMode.verbose)
  }

  def locateHamrTests(root: Os.Path): ISZ[Os.Path] = {
    var testRoots: ISZ[Os.Path] = ISZ()

    def locate(f: Os.Path): Unit = {
      assert(f.isDir)
      for (item <- f.list) {
        if (item.isDir) {
          locate(item)
        } else if (ops.StringOps(item.name).startsWith(".hamrtest")) {
          testRoots = testRoots :+ item
        }
      }
    }

    locate(root)
    return testRoots
  }

  def test(test: Os.Path): Unit = {
    val props = test.properties

    var ignoreReasons: ISZ[String] = ISZ()

    if (!props.contains("testName")) {
      cprint(T, s"Property file must contain 'testName' entry: ${test.value}")
      return
    }

    val testName = props.get("testName").get

    val unitTestModes: ISZ[TestMode.Type] = testModes ++ CodegenBehaviorTest.getUnitTestModes(props.get("testModes"))

    val airFile = CodegenBehaviorTest.getAirFileEntry(props.get("airFile"), test.canon)

    var overrideIgnore = F
    if (airFile.isEmpty && !ops.ISZOps(unitTestModes).contains(TestMode.phantom)) {
      ignoreReasons = ignoreReasons :+ s"Either provide 'airFile' entry or enable phantom test mode"
      overrideIgnore = T
    }

    if (!props.contains("hamrArgs")) {
      cprint(T, s"Property file must contain 'hamrArgs' entry: ${test.value}")
      return
    }

    var hamrOpts = CodegenBehaviorTest.processHamrArgs(props.get("hamrArgs").get, test.up)

    if (hamrOpts.isEmpty) {
      cprint(T, s"The 'hamrArgs' entry did not parse: ${test.value}")
      return
    }

    var testOps = hamrOpts.get
    if(verbose) {
      testOps = testOps(verbose = verbose)
    }

    val label = s"From test properties file: ${test.canon.toUri}"
    if (overrideIgnore || CodegenBehaviorTest.shouldIgnore(props)) {
      cprintln(T,
        st"""Ignoring ${testName} from ${test.toUri}
            |  ${(ignoreReasons, "\n")}""".render)
      registerIgnoredTest(testName.native)({})
    } else {
      registerTest(testName.native)({
        println(label)

        if(verbose) {
          println(s"Test Modes: ${unitTestModes}")
        }

        val reporter = Reporter.create

        val model = TestUtil.getModel(airFile, Os.path(testOps.aadlRootDir.get), unitTestModes, testName, verbose)

        val results: CodeGenResults = CodeGen.codeGen(model, testOps, reporter,
          (TranspilerConfig) => {
            println("Dummy transpiler"); 0
          },
          (ProyekIveConfig) => {
            println("Dummy Proyek IVE"); 0
          }
        )
        var success = !reporter.hasError
        if (success) {
          success = TestUtil.runAdditionalTasks(testName, Os.path(testOps.slangOutputDir.get), testOps, unitTestModes, 0, verbose, reporter)
          success = success && !reporter.hasError
        }

        assert(success, s"Test failed: ${testName}")
      })
    }
  }
}


object CodegenBehaviorTest {
  def getAirFileEntry(value: Option[String], root: Os.Path): Option[Os.Path] = {
    val ret: Option[Os.Path] = value match {
      case Some(f) =>
        val cand = (root / f).canon
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


  def processHamrArgs(args: String, root: Os.Path): Option[CodeGenConfig] = {
    assert(root.isDir, root)
    val _args: ISZ[String] = ops.StringOps(args).split(c => c == C(' '))
    return processHamrArgsH(_args, root)
  }

  def processHamrArgsH(args: ISZ[String], root: Os.Path): Option[CodeGenConfig] = {
    assert(root.isDir, root)

    def canon(opt: Option[String]): Option[String] = {
      val ret: Option[String] = opt match {
        case Some(s) => Some((root / s).canon.value)
        case _ => None()
      }
      return ret
    }

    val ret: Option[CodeGenConfig] = util.Cli(Os.pathSepChar).parseCodegen(args, 0) match {
      case Some(opts: CodegenOption) =>
        val platform = opts.platform match {
          case CodegenHamrPlatform.JVM => CodeGenPlatform.JVM
          case CodegenHamrPlatform.Linux => CodeGenPlatform.Linux
          case CodegenHamrPlatform.Cygwin => CodeGenPlatform.Cygwin
          case CodegenHamrPlatform.MacOS => CodeGenPlatform.MacOS
          case CodegenHamrPlatform.SeL4 => CodeGenPlatform.SeL4
          case CodegenHamrPlatform.SeL4_Only => CodeGenPlatform.SeL4_Only
          case CodegenHamrPlatform.SeL4_TB => CodeGenPlatform.SeL4_TB
        }

        val aadlRoot = if (opts.aadlRootDir.isEmpty) canon(Some(".")) else canon(opts.aadlRootDir)

        Some(CodeGenConfig(
          writeOutResources = T,
          ipc = CodeGenIpcMechanism.SharedMemory,

          verbose = opts.verbose,
          platform = platform,
          slangOutputDir = canon(opts.outputDir),
          packageName = opts.packageName,
          noProyekIve = opts.noProyekIve,
          noEmbedArt = opts.noEmbedArt,
          devicesAsThreads = opts.devicesAsThreads,
          slangAuxCodeDirs = opts.slangAuxCodeDirs.map(s => canon(Some(s)).get),
          slangOutputCDir = canon(opts.slangOutputCDir),
          excludeComponentImpl = opts.excludeComponentImpl,
          bitWidth = opts.bitWidth,
          maxStringSize = opts.maxStringSize,
          maxArraySize = opts.maxArraySize,
          runTranspiler = opts.runTranspiler,
          camkesOutputDir = canon(opts.camkesOutputDir),
          camkesAuxCodeDirs = opts.camkesAuxCodeDirs.map(s => canon(Some(s)).get),
          aadlRootDir = aadlRoot,
          experimentalOptions = opts.experimentalOptions
        ))

      case _ => None()
    }
    return ret
  }
}
