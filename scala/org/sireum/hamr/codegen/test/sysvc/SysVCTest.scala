package org.sireum.hamr.codegen.test.sysvc

import org.sireum._
import org.sireum.hamr.codegen.common.CommonUtil
import org.sireum.hamr.codegen.common.resolvers.GclResolver
import org.sireum.hamr.codegen.common.sysvc._
import org.sireum.hamr.codegen.common.util.{HamrCli, ModelUtil}
import org.sireum.hamr.ir
import org.sireum.hamr.ir.JSON
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

class SysVCTest extends TestSuite {

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
    val s = cands(0).read
    JSON.toAadl(s) match {
      case Either.Left(m) => return m
      case Either.Right(m) =>
        halt(s"Json deserialization error at (${m.line}, ${m.column}): ${m.message}")
    }
  }

  val baseOptions: HamrCli.CodegenOption = HamrCli.CodegenOption(
    help = "",
    args = ISZ(),
    msgpack = F,
    verbose = F,
    runtimeMonitoring = T,
    platform = HamrCli.CodegenHamrPlatform.Microkit,
    outputDir = None(),
    parseableMessages = F,
    slangOutputDir = None(),
    packageName = Some("isolette"),
    noProyekIve = T,
    noEmbedArt = F,
    devicesAsThreads = T,
    genSbtMill = T,
    slangAuxCodeDirs = ISZ(),
    slangOutputCDir = None(),
    excludeComponentImpl = F,
    bitWidth = 64,
    maxStringSize = 256,
    maxArraySize = 1,
    runTranspiler = F,
    scheduling = HamrCli.CodegenScheduling.Domain,
    verusAttributeSyntax = F,
    sel4OutputDir = None(),
    sel4AuxCodeDirs = ISZ(),
    workspaceRootDir = Some(isoletteAadlDir.canon.value),
    strictAadlMode = F,
    ros2OutputWorkspaceDir = None(),
    ros2Dir = None(),
    ros2NodesLanguage = HamrCli.CodegenNodesCodeLanguage.Cpp,
    ros2LaunchLanguage = HamrCli.CodegenLaunchCodeLanguage.Xml,
    invertTopicBinding = F,
    experimentalOptions = ISZ()
  )

  val tests = Tests {

    * - {
      val reporter = Reporter.create
      val model = loadModel(isoletteAadlDir)

      var store: CommonUtil.Store = Map.empty
      val result = ModelUtil.resolve(model, model.components(0).identifier.pos, "isolette", baseOptions, store, reporter)

      assert(!reporter.hasError, s"Model resolution failed: ${reporter.messages}")
      assert(result._1.nonEmpty, "ModelUtil.resolve returned None")

      store = result._2
      val symbolTable = result._1.get.symbolTable

      val scheduleOpt = VCGenerator.getSystemSchedule(symbolTable)
      assert(scheduleOpt.nonEmpty, "No system schedule found in the Isolette model")
      val schedule = scheduleOpt.get

      val resolvedComponentAliasMap = GclResolver.getResolvedComponentAliasMap(store)
      assert(resolvedComponentAliasMap.nonEmpty, "Resolved component alias map should be populated")

      val nextRel = ScheduleNextRel.build(schedule)
      val vcs = VCGenerator.generate(schedule, nextRel, resolvedComponentAliasMap, symbolTable)

      println(s"Generated ${vcs.size} VCs:")
      for (i <- z"0" until vcs.size) {
        val vc = vcs(i)
        val compName: String = vc.source.componentOpt match {
          case Some(name) => st"${(name.name, ".")}".render
          case _ => "<none>"
        }
        println(s"  [$i] ${vc.kind} component=$compName premises=${vc.premises.size} conclusion=${vc.conclusion.size}")
      }

      val initVCs = vcs.filter(v => v.kind == VCKind.InitState)
      assert(initVCs.size == 1, s"Expected 1 Init-State VC, got ${initVCs.size}")

      val preAssertVCs = vcs.filter(v => v.kind == VCKind.PreAssert)
      assert(preAssertVCs.size == 11, s"Expected 11 Pre-Assert VCs, got ${preAssertVCs.size}")

      val nextAssertTaskVCs = vcs.filter(v => v.kind == VCKind.NextAssertTask)
      assert(nextAssertTaskVCs.size == 11, s"Expected 11 Next-Assert (task) VCs, got ${nextAssertTaskVCs.size}")

      val nextAssertSkipVCs = vcs.filter(v => v.kind == VCKind.NextAssertSkip)
      // 6 from the schedule structure (2 split entries + 2 join exits + 1 OI/TS split + 1 HS→END)
      // plus 1 trailing control-point transition to END added by ScheduleNextRel
      assert(nextAssertSkipVCs.size == 7, s"Expected 7 Next-Assert (skip) VCs, got ${nextAssertSkipVCs.size}")

      val postPreVCs = vcs.filter(v => v.kind == VCKind.PostPre)
      assert(postPreVCs.size == 1, s"Expected 1 Post-Pre VC, got ${postPreVCs.size}")

      val nonBlockingVCs = vcs.filter(v => v.kind == VCKind.NonBlocking)
      val preservationVCs = vcs.filter(v => v.kind == VCKind.Preservation)

      // Transition-level MHIP (includes component/control-point pairs). Classify pairs:
      // cc = both component, ck = exactly one component (mixed), kk = both control-point.
      val mhipPairs = MHIPComputer.computeMHIP(nextRel)
      val comp = ScheduleNextRel.TransitionKind.Component
      def isComp(idx: org.sireum.Z): Boolean = nextRel.transitions(idx).kind == comp
      var ccPairs = 0
      var ckPairs = 0
      for (p <- mhipPairs) {
        val a = isComp(p._1)
        val b = isComp(p._2)
        if (a && b) ccPairs += 1
        else if (a || b) ckPairs += 1
      }
      // The Isolette has 17 component-component and 8 (component, control-point) MHIP pairs
      // (the 1 control-point/control-point pair contributes no VCs).
      assert(ccPairs == 17, s"Expected 17 component-component MHIP pairs, got $ccPairs")
      assert(ckPairs == 8, s"Expected 8 mixed (component, control-point) MHIP pairs, got $ckPairs")

      // NonBlocking / Preservation: 2 per component-component pair (bidirectional) + 1 per
      // mixed pair (only the component-fires direction is non-trivial).
      val expectedDirected = ccPairs * 2 + ckPairs
      assert(nonBlockingVCs.size == expectedDirected, s"Expected $expectedDirected Non-Blocking VCs, got ${nonBlockingVCs.size}")
      assert(preservationVCs.size == expectedDirected, s"Expected $expectedDirected Preservation VCs, got ${preservationVCs.size}")

      val commutativityVCs = vcs.filter(v => v.kind == VCKind.Commutativity)
      // Commutativity (execIndependent) is symmetric and only applies when both members are
      // component transitions, so 1 VC per component-component pair.
      assert(commutativityVCs.size == ccPairs, s"Expected $ccPairs Commutativity VCs, got ${commutativityVCs.size}")

      val taskVCsWithWriteSets = nextAssertTaskVCs.filter(v => v.writeSetOpt.nonEmpty)
      assert(taskVCsWithWriteSets.size == nextAssertTaskVCs.size,
        s"Expected all ${nextAssertTaskVCs.size} task VCs to have write sets, but only ${taskVCsWithWriteSets.size} do")

      // Each compute case with an explicit assume must appear in its task VC's premises as
      // the implication `assume ==> guarantee` (the component's verified contract), not as
      // the bare guarantee.
      var implicationCases = 0
      for (vc <- nextAssertTaskVCs) {
        val compName = vc.source.componentOpt.get
        val alias = compName.name(compName.name.lastIndex)
        val compPath: CommonUtil.IdPath = resolvedComponentAliasMap.get(alias) match {
          case Some(p) => p
          case _ => compName.name
        }
        VCGenerator.getGclInfoOpt(compPath, symbolTable) match {
          case Some(info) =>
            info.annex.compute match {
              case Some(compute) =>
                for (c <- compute.cases) {
                  c.assumes match {
                    case Some(a) =>
                      var found = false
                      for (p <- vc.premises) {
                        p match {
                          case b: org.sireum.lang.ast.Exp.Binary =>
                            if (b.op == org.sireum.lang.ast.Exp.BinaryOp.CondImply && b.left == a && b.right == c.guarantees) {
                              found = true
                            }
                          case _ =>
                        }
                      }
                      assert(found, s"Case ${c.id} of $alias should appear as an `assume ==> guarantee` premise")
                      implicationCases += 1
                    case _ =>
                  }
                }
              case _ =>
            }
          case _ =>
        }
      }
      assert(implicationCases > 0, "Expected at least one compute case with an assume in the Isolette")

      // 31 sequential VCs (1 Init + 11 Pre + 11 NextTask + 7 NextSkip + 1 PostPre)
      // + 5 per cc pair (2 NB + 2 Pres + 1 Comm) + 2 per ck pair (1 NB + 1 Pres).
      val expectedTotal = 1 + 11 + 11 + 7 + 1 + ccPairs * 5 + ckPairs * 2
      assert(vcs.size == expectedTotal, s"Expected $expectedTotal total VCs, got ${vcs.size}")

      println(s"\nMHIP pairs: ${mhipPairs.size}")
      println(s"Total VCs: ${vcs.size}")
    }
  }
}
