package org.sireum.hamr.codegen.test.sysvc

import org.sireum._
import org.sireum.hamr.codegen.common.CommonUtil
import org.sireum.hamr.codegen.common.resolvers.GclResolver
import org.sireum.hamr.codegen.common.sysvc._
import org.sireum.hamr.codegen.common.types.AadlType
import org.sireum.hamr.codegen.common.util.{HamrCli, ModelUtil}
import org.sireum.hamr.codegen.microkit.plugins.gumbo.VerusVCSerializer
import org.sireum.hamr.codegen.microkit.plugins.rust.types.{CRustTypeNameProvider, DefaultCRustTypeNameProvider, DefaultCRustTypeProvider}
import org.sireum.hamr.codegen.microkit.types.MicrokitTypeUtil
import org.sireum.hamr.codegen.microkit.{rust => RAST}
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
      // 2 split entries + 2 join exits + 1 trailing control-point transition to END.
      // A branch that begins with an assert gets that assert place as the split
      // out-place directly (F1 fix, InitialVerusRunFindings.md), so the
      // regulator/monitor branches contribute no pass-through transitions.
      assert(nextAssertSkipVCs.size == 5, s"Expected 5 Next-Assert (skip) VCs, got ${nextAssertSkipVCs.size}")

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
      // The Isolette has 17 component-component MHIP pairs. After the F1 fix removed
      // the branch-leading pass-through transitions, no control-point transition is
      // co-enabled with a component (the split fires atomically into both branch
      // assert places; the join needs both branch-end tokens), so there are no
      // mixed pairs.
      assert(ccPairs == 17, s"Expected 17 component-component MHIP pairs, got $ccPairs")
      assert(ckPairs == 0, s"Expected 0 mixed (component, control-point) MHIP pairs, got $ckPairs")

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

      // --- VerusVCSerializer: SystemState field map ---
      val aadlTypes = result._1.get.types
      val ssm = VerusVCSerializer.buildSystemStateMap(schedule, resolvedComponentAliasMap, symbolTable, aadlTypes, reporter)
      assert(!reporter.hasError, s"SystemState field map construction failed: ${reporter.messages}")

      println(s"\nSystemState fields (${ssm.fields.size}):")
      for (f <- ssm.fields) {
        val owner = st"${(f.ownerPath, ".")}".render
        val alias = f.aliasOpt match {
          case Some(a) => s" (alias $a)"
          case _ => ""
        }
        println(s"  ${f.fieldName}: ${f.kind} of $owner.${f.entryId}$alias")
      }

      // field names are unique
      var fieldNames: Set[String] = Set.empty
      for (f <- ssm.fields) {
        assert(!fieldNames.contains(f.fieldName), s"Duplicate field name ${f.fieldName}")
        fieldNames = fieldNames + f.fieldName
      }

      // every thread port and state variable resolves to a field
      for (t <- symbolTable.getThreads()) {
        for (p <- t.getPorts()) {
          assert(ssm.byComponentEntry.get((t.path, p.identifier)).nonEmpty,
            s"No field for port ${p.identifier} of ${st"${(t.path, ".")}".render}")
        }
        WriteFrameBuilder.getGclInfoOpt(t.path, symbolTable) match {
          case Some(info) =>
            for (sv <- info.annex.state) {
              assert(ssm.byComponentEntry.get((t.path, sv.name)).nonEmpty,
                s"No field for state var ${sv.name} of ${st"${(t.path, ".")}".render}")
            }
          case _ =>
        }
      }

      // both endpoints of every thread-to-thread connection share one field
      // (connections are the shared channels of the Isabelle formalization)
      var portThread: Map[CommonUtil.IdPath, (CommonUtil.IdPath, String)] = Map.empty
      for (t <- symbolTable.getThreads(); p <- t.getPorts()) {
        portThread = portThread + p.path ~> ((t.path, p.identifier))
      }
      var sharedChecked = 0
      for (ci <- symbolTable.connections) {
        (ci.src.feature, ci.dst.feature) match {
          case (Some(srcF), Some(dstF)) =>
            (portThread.get(srcF.name), portThread.get(dstF.name)) match {
              case (Some((srcThread, srcPort)), Some((dstThread, dstPort))) =>
                val srcField = ssm.byComponentEntry.get((srcThread, srcPort)).get
                val dstField = ssm.byComponentEntry.get((dstThread, dstPort)).get
                assert(srcField.fieldName == dstField.fieldName,
                  s"Connection endpoints map to different fields: ${srcField.fieldName} vs ${dstField.fieldName}")
                sharedChecked += 1
              case _ =>
            }
          case _ =>
        }
      }
      assert(sharedChecked > 0, "Expected at least one thread-to-thread connection in the Isolette")

      // every schedule-declared alias resolves to a field
      for (pa <- schedule.portAliases) {
        assert(ssm.byAlias.get(pa.name).nonEmpty, s"Port alias ${pa.name} did not resolve to a field")
      }
      for (sva <- schedule.stateVarAliases) {
        assert(ssm.byAlias.get(sva.name).nonEmpty, s"State var alias ${sva.name} did not resolve to a field")
      }
      println(s"Schedule aliases resolved: ${schedule.portAliases.size} port, ${schedule.stateVarAliases.size} state var; connections sharing a field: $sharedChecked")

      // --- VerusVCSerializer: copied component contracts ---
      // SysVCTest does not run codegen, so build a minimal type provider that maps
      // each AADL type to its simple name (the real CRustTypeProvider is only
      // available during a Microkit codegen run)
      var tnpMap: Map[String, CRustTypeNameProvider] = Map.empty
      for (e <- aadlTypes.typeMap.entries) {
        val segs = e._1.value.split("::")
        tnpMap = tnpMap + e._1 ~> DefaultCRustTypeNameProvider(ISZ(String(segs(segs.length - 1).replace('.', '_'))))
      }
      tnpMap = tnpMap + MicrokitTypeUtil.eventPortType.name ~> DefaultCRustTypeNameProvider(ISZ(String("bool")))
      tnpMap = tnpMap + MicrokitTypeUtil.eventPortTypeName ~> DefaultCRustTypeNameProvider(ISZ(String("bool")))
      val fakeTp = DefaultCRustTypeProvider(
        rustTypeDefs = HashSMap.empty[String, ISZ[RAST.Item]],
        PRIVATE_typeNameProvider = tnpMap,
        PRIVATE_substitutions = Map.empty[String, AadlType])

      val contracts = VerusVCSerializer.buildComponentContracts(symbolTable, aadlTypes, resolvedComponentAliasMap, fakeTp, baseOptions, store, reporter)
      assert(!reporter.hasError, s"Contract construction failed: ${reporter.messages}")
      assert(contracts.nonEmpty, "Expected at least one component with GUMBO contracts")

      // every component's contract fn count matches its clause count
      var totalContractFns: Z = Z(0)
      var caseImplications = 0
      for (cc <- contracts) {
        val info = WriteFrameBuilder.getGclInfoOpt(cc.componentPath, symbolTable).get
        var expected: Z = Z(0)
        info.annex.initializes match {
          case Some(i) => expected = expected + i.guarantees.size
          case _ =>
        }
        info.annex.compute match {
          case Some(c) => expected = expected + c.assumes.size + c.guarantees.size + c.cases.size
          case _ =>
        }
        info.annex.integration match {
          case Some(integ) => expected = expected + integ.specs.size
          case _ =>
        }
        assert(cc.fns.size == expected, s"${cc.moduleName}: expected $expected contract fns, got ${cc.fns.size}")
        totalContractFns = totalContractFns + cc.fns.size
        for (f <- cc.fns) {
          if (f.kind == VerusVCSerializer.ContractFnKind.ComputeCase && f.fnST.render.value.contains("==>")) {
            caseImplications += 1
          }
        }
      }
      assert(totalContractFns > Z(0), "Expected contract fns for the Isolette")
      assert(caseImplications > 0, "Expected at least one compute case rendered as an implication")

      val contractsRs = VerusVCSerializer.genContractsRs(contracts).render
      assert(contractsRs.value.contains("compute_case_"), "contracts.rs should contain case spec fns")
      println(s"\ncontracts.rs: ${contracts.size} component modules, $totalContractFns fns ($caseImplications case implications)")
      for (cc <- contracts if cc.moduleName == String("mhs")) {
        println(VerusVCSerializer.genContractsRs(ISZ(cc)).render)
      }

      // --- VerusVCSerializer: system assertions ---
      val (assertionFns, sysFns) = VerusVCSerializer.buildAssertions(
        nextRel, ssm, symbolTable, aadlTypes, baseOptions, fakeTp, store, reporter)
      assert(!reporter.hasError, s"Assertion construction failed: ${reporter.messages}")

      var placesWithAsserts = 0
      for (pi <- nextRel.places) {
        if (pi.assertOpt.nonEmpty) placesWithAsserts += 1
      }
      assert(placesWithAsserts > 0, "Expected at least one place assertion in the Isolette schedule")
      assert(assertionFns.size == placesWithAsserts,
        s"Expected $placesWithAsserts assertion fns, got ${assertionFns.size}")
      assert(sysFns.nonEmpty, "Expected system-level GUMBO functions (sysProp_*)")

      // alias references must have been substituted with SystemState field accesses
      for (a <- assertionFns) {
        assert(a.fnST.render.value.contains("st."),
          s"Assertion ${a.fnName} does not reference SystemState fields")
      }

      println(s"\nassertions.rs: ${assertionFns.size} place assertions, ${sysFns.size} system GUMBO fns")
      println(VerusVCSerializer.genAssertionsRs(assertionFns, sysFns).render)

      // --- VerusVCSerializer: write frames ---
      val frames = VerusVCSerializer.buildWriteFrames(ssm, resolvedComponentAliasMap, symbolTable)
      assert(frames.size == symbolTable.getThreads().size,
        s"Expected one frame per thread, got ${frames.size}")

      for (fr <- frames) {
        // write set + framed set partition the full field set
        assert(fr.writeFields.size + fr.framedFields.size == ssm.fields.size,
          s"${fr.componentAlias}: write (${fr.writeFields.size}) + framed (${fr.framedFields.size}) != ${ssm.fields.size} fields")
        // the frame excludes exactly the component's write set
        val ws = WriteFrameBuilder.computeWriteSet(
          symbolTable.componentMap.get(fr.componentPath).get, symbolTable)
        assert(fr.writeFields.size == ws.outPorts.size + ws.stateVars.size,
          s"${fr.componentAlias}: expected ${ws.outPorts.size + ws.stateVars.size} write fields, got ${fr.writeFields.size}")
        for (wf <- fr.writeFields) {
          assert(!fr.framedFields.elements.contains(wf), s"${fr.componentAlias}: written field $wf must not be framed")
        }
      }

      // MHS frames everything except heat_control and lastCmd, including the
      // tempWstatus channels its Next-Assert VC needs to transport REQ_MRI_7/8
      for (fr <- frames if fr.componentAlias == String("mhs")) {
        assert(fr.writeFields.elements.contains(String("heat_control")) && fr.writeFields.elements.contains(String("lastCmd")),
          s"MHS write set should be heat_control + lastCmd, got ${fr.writeFields}")
        assert(fr.framedFields.elements.contains(String("lower_desired_tempWstatus")) && fr.framedFields.elements.contains(String("upper_desired_tempWstatus")),
          "MHS frame must constrain the desired tempWstatus channels")
        println(s"\nwrite_frames.rs (mhs):")
        println(fr.fnST.render)
      }
      val framesRs = VerusVCSerializer.genWriteFramesRs(frames).render
      assert(framesRs.value.contains("mhs_global_write_frame"), "write_frames.rs should contain the MHS frame")

      // --- VerusVCSerializer: sequential VC proof fns ---
      val seqVCs = VerusVCSerializer.genSequentialVCs(
        vcs, nextRel, ssm, contracts, frames, assertionFns, resolvedComponentAliasMap, reporter)
      assert(!reporter.hasError, s"Sequential VC serialization failed: ${reporter.messages}")

      val initRs = seqVCs.vcInitRs.render
      val seqRs = seqVCs.vcSequentialRs.render
      val postPreRs = seqVCs.vcPostPreRs.render

      assert(initRs.value.contains("vc_init_state"), "vc_init.rs should contain vc_init_state")
      assert(postPreRs.value.contains("vc_post_pre"), "vc_post_pre.rs should contain vc_post_pre")

      // one proof fn per sequential VC: 11 Pre-Assert + 11 Next-Assert (task) + 7 (skip)
      val seqProofFnCount = seqRs.value.split("pub proof fn ").length - 1
      assert(seqProofFnCount == 27, s"Expected 27 sequential proof fns, got $seqProofFnCount")

      // MHS Next-Assert task VC spot checks (sketch VC[15]): frame premise,
      // pre/post argument selection on a case implication, post-state conclusion
      assert(seqRs.value.contains("mhs_global_write_frame(pre, post)"),
        "MHS task VC should include the global write frame premise")
      assert(seqRs.value.contains("mhs::compute_case_REQ_MHS_2(pre.current_tempWstatus, pre.lower_desired_temp, pre.regulator_mode, post.heat_control)"),
        "MHS case premise should select pre-state in-ports and post-state out-port")
      assert(seqRs.value.contains("sys_assert_END_Regulator_Assert(post)"),
        "MHS task VC conclusion should be the End_Regulator assertion on post")
      assert(seqRs.value.contains("sys_assert_Post_MRM_Assert(pre)"),
        "MHS task VC premise should be the Post_MRM assertion on pre")

      println(s"\nvc_init.rs:")
      println(initRs)
      println(s"vc_post_pre.rs:")
      println(postPreRs)
      println(s"vc_sequential.rs ($seqProofFnCount proof fns):")
      println(seqRs)

      // --- VerusVCSerializer: action abstractions + independence VCs ---
      val actions = VerusVCSerializer.buildActions(ssm, frames, symbolTable, fakeTp, reporter)
      assert(!reporter.hasError, s"Action abstraction construction failed: ${reporter.messages}")
      assert(actions.size == symbolTable.getThreads().size,
        s"Expected one action abstraction per thread, got ${actions.size}")

      val actionsRs = VerusVCSerializer.genActionsRs(actions).render
      assert(actionsRs.value.contains("pub uninterp spec fn mhs_action_heat_control("),
        "actions.rs should declare MHS's heat_control action fn")
      assert(actionsRs.value.contains("pub open spec fn mhs_fire("),
        "actions.rs should declare the MHS fire predicate")

      val indRs = VerusVCSerializer.genIndependenceVCs(
        vcs, nextRel, frames, assertionFns, actions, resolvedComponentAliasMap, reporter).render
      assert(!reporter.hasError, s"Independence VC serialization failed: ${reporter.messages}")

      val nbFnCount = indRs.value.split("pub proof fn vc_non_blocking_").length - 1
      val presFnCount = indRs.value.split("pub proof fn vc_preservation_").length - 1
      val commFnCount = indRs.value.split("pub proof fn vc_commutativity_").length - 1
      assert(nbFnCount == 34, s"Expected 34 Non-Blocking proof fns, got $nbFnCount")
      assert(presFnCount == 34, s"Expected 34 Preservation proof fns, got $presFnCount")
      assert(commFnCount == 17, s"Expected 17 Commutativity proof fns, got $commFnCount")
      assert(indRs.value.contains("post_a == post_b"),
        "Commutativity VCs should conclude state equality of the two interleavings")

      for (a <- actions if a.componentAlias == String("mhs")) {
        println(s"\nactions.rs (mhs):")
        println(a.fnST.render)
      }
      println(s"\nvc_independence.rs: $nbFnCount NonBlocking + $presFnCount Preservation + $commFnCount Commutativity")
      indRs.value.split("\n\n").find(s => s.contains("vc_commutativity_mhs_ma") || s.contains("vc_commutativity_ma_mhs")) match {
        case scala.Some(fn) => println(s"\nexample Commutativity VC:"); println(fn)
        case _ => assert(false, "Expected a Commutativity VC for the MHS/MA pair")
      }
      indRs.value.split("\n\n").find(s => s.contains("pub proof fn vc_non_blocking_drf_dmf")) match {
        case scala.Some(fn) => println(s"\nexample Non-Blocking VC:"); println(fn)
        case _ => assert(false, "Expected the DRF/DMF Non-Blocking VC")
      }

      // 29 sequential VCs (1 Init + 11 Pre + 11 NextTask + 5 NextSkip + 1 PostPre)
      // + 5 per cc pair (2 NB + 2 Pres + 1 Comm) + 2 per ck pair (1 NB + 1 Pres).
      val expectedTotal = 1 + 11 + 11 + 5 + 1 + ccPairs * 5 + ckPairs * 2
      assert(vcs.size == expectedTotal, s"Expected $expectedTotal total VCs, got ${vcs.size}")

      println(s"\nMHIP pairs: ${mhipPairs.size}")
      println(s"Total VCs: ${vcs.size}")
    }
  }
}
