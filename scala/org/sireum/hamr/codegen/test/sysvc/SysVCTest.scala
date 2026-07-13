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

// Exercises the composition-based system VC pipeline (design D8) on the Isolette:
// schema net construction, MHIP, per-property decoration + VC generation, and the
// Verus serialization builders. Expects the Isolette model to declare one
// composition (the migrated form of its former schedule block).
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
    sel4AuxCodeSymlink = F,
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

      val compositions = VCGenerator.getCompositions(symbolTable)
      assert(compositions.size == 1, s"Expected 1 composition in the Isolette model, got ${compositions.size}")
      val composition = compositions(0)
      assert(composition.properties.nonEmpty, "Expected at least one property in the Isolette composition")
      println(s"Composition '${composition.id}' with ${composition.properties.size} properties: ${(for (p <- composition.properties) yield p.id, ", ")}")

      val resolvedComponentAliasMap = GclResolver.getResolvedComponentAliasMap(store)
      assert(resolvedComponentAliasMap.nonEmpty, "Resolved component alias map should be populated")

      // --- schema-derived net (shared by all properties) ---
      val nextRel = ScheduleNextRel.build(composition)

      val compKind = ScheduleNextRel.TransitionKind.Component
      val componentTransitions = nextRel.transitions.filter(t => t.kind == compKind)
      val controlTransitions = nextRel.transitions.filter(t => t.kind != compKind)
      // The Isolette schema dispatches 11 components (oi, ts, drf, mri, mrm, mhs,
      // dmf, mmi, mmm, ma, hs). Control points: 2 split entries + 2 join exits +
      // 1 trailing control-point transition to END. A branch's entry place IS the
      // split's out-place for that branch (F1, InitialVerusRunFindings.md), so
      // branches contribute no pass-through transitions.
      assert(componentTransitions.size == 11, s"Expected 11 component transitions, got ${componentTransitions.size}")
      assert(controlTransitions.size == 5, s"Expected 5 control-point transitions, got ${controlTransitions.size}")

      // every composition alias of a unique occurrence is a resolvable point name
      for (ca <- composition.componentAliases) {
        assert(nextRel.beforeMap.get(ca.name).nonEmpty && nextRel.afterMap.get(ca.name).nonEmpty,
          s"Component alias '${ca.name}' should have before/after point names (fires once)")
      }

      // --- MHIP (shared by all properties) ---
      val mhipPairs = MHIPComputer.computeMHIP(nextRel)
      def isComp(idx: org.sireum.Z): Boolean = nextRel.transitions(idx).kind == compKind
      var ccPairs = 0
      var ckPairs = 0
      for (p <- mhipPairs) {
        val a = isComp(p._1)
        val b = isComp(p._2)
        if (a && b) ccPairs += 1
        else if (a || b) ckPairs += 1
      }
      // The Isolette has 17 component-component MHIP pairs and no mixed pairs (no
      // control-point transition is co-enabled with a component: the split fires
      // atomically into both branch-entry places; the join needs both branch-end
      // tokens).
      assert(ccPairs == 17, s"Expected 17 component-component MHIP pairs, got $ccPairs")
      assert(ckPairs == 0, s"Expected 0 mixed (component, control-point) MHIP pairs, got $ckPairs")

      // --- commutativity VCs: once per composition, assertion-free ---
      val commutativityVCs = VCGenerator.generateCommutativityVCs(nextRel, mhipPairs, resolvedComponentAliasMap, symbolTable)
      assert(commutativityVCs.size == ccPairs, s"Expected $ccPairs Commutativity VCs, got ${commutativityVCs.size}")
      for (vc <- commutativityVCs) {
        assert(vc.premises.isEmpty && vc.conclusion.isEmpty, "Commutativity VCs are assertion-free state equalities")
        assert(vc.writeSetOpt.nonEmpty, "Commutativity VCs carry the first member's write set")
      }

      // --- per-property VC sets over the shared net ---
      val expectedDirected = ccPairs * 2 + ckPairs
      val expectedPerProperty = 1 + componentTransitions.size * 2 + controlTransitions.size + 1 + expectedDirected * 2

      var totalImplicationCases = 0
      // D9: abstract bases are not instantiated -- the plugin generates no VC set
      // for them (their bindings are folded into the concrete properties), so the
      // test mirrors that and only checks the instantiated (concrete) properties.
      for (property <- composition.properties if !property.isAbstract) {
        val decoration = ScheduleNextRel.decorate(nextRel, property, reporter)
        assert(!reporter.hasError, s"Decoration of property '${property.id}' failed: ${reporter.messages}")
        assert(decoration.size == property.bindings.size,
          s"Property '${property.id}': expected ${property.bindings.size} resolved bindings, got ${decoration.size}")

        val vcs = VCGenerator.generateForProperty(decoration, nextRel, mhipPairs, resolvedComponentAliasMap, symbolTable)
        println(s"Property '${property.id}': ${vcs.size} VCs over ${decoration.size} bound points")

        assert(vcs.filter(v => v.kind == VCKind.InitState).size == 1)
        assert(vcs.filter(v => v.kind == VCKind.PreAssert).size == componentTransitions.size)
        val taskVCs = vcs.filter(v => v.kind == VCKind.NextAssertTask)
        assert(taskVCs.size == componentTransitions.size)
        assert(vcs.filter(v => v.kind == VCKind.NextAssertSkip).size == controlTransitions.size)
        assert(vcs.filter(v => v.kind == VCKind.PostPre).size == 1)
        assert(vcs.filter(v => v.kind == VCKind.NonBlocking).size == expectedDirected)
        assert(vcs.filter(v => v.kind == VCKind.Preservation).size == expectedDirected)
        assert(vcs.filter(v => v.kind == VCKind.Commutativity).isEmpty,
          "Commutativity VCs are generated per composition, not per property")
        assert(vcs.size == expectedPerProperty, s"Property '${property.id}': expected $expectedPerProperty VCs, got ${vcs.size}")

        val taskVCsWithWriteSets = taskVCs.filter(v => v.writeSetOpt.nonEmpty)
        assert(taskVCsWithWriteSets.size == taskVCs.size,
          s"Expected all ${taskVCs.size} task VCs to have write sets, but only ${taskVCsWithWriteSets.size} do")

        // Each compute case with an explicit assume must appear in its task VC's
        // premises as the implication `assume ==> guarantee` (the component's
        // verified contract), not as the bare guarantee. Only for transitions
        // the property covers (non-empty conclusion): uncovered components'
        // contracts are projected out, so their cases are absent by design.
        var implicationCases = 0
        for (vc <- taskVCs if vc.conclusion.nonEmpty) {
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
        totalImplicationCases += implicationCases
      }
      assert(totalImplicationCases > 0, "Expected at least one compute case with an assume across the Isolette's properties")

      // --- VerusVCSerializer: SystemState field map ---
      val aadlTypes = result._1.get.types
      val ssm = VerusVCSerializer.buildSystemStateMap(composition, resolvedComponentAliasMap, symbolTable, aadlTypes, reporter)
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

      // every composition-declared alias resolves to a field
      for (pa <- composition.portAliases) {
        assert(ssm.byAlias.get(pa.name).nonEmpty, s"Port alias ${pa.name} did not resolve to a field")
      }
      for (sva <- composition.stateVarAliases) {
        assert(ssm.byAlias.get(sva.name).nonEmpty, s"State var alias ${sva.name} did not resolve to a field")
      }
      println(s"Composition aliases resolved: ${composition.portAliases.size} port, ${composition.stateVarAliases.size} state var; connections sharing a field: $sharedChecked")

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

      // --- VerusVCSerializer: system fns + per-property assertions ---
      val sysFns = VerusVCSerializer.buildSysFns(symbolTable, aadlTypes, baseOptions, fakeTp, store, reporter)
      assert(!reporter.hasError, s"System fn construction failed: ${reporter.messages}")
      assert(sysFns.nonEmpty, "Expected system-level GUMBO functions (sysProp_*)")

      // --- VerusVCSerializer: write frames ---
      val frames = VerusVCSerializer.buildWriteFrames(ssm, resolvedComponentAliasMap, symbolTable)
      assert(frames.size == symbolTable.getThreads().size,
        s"Expected one write frame per thread, got ${frames.size}")
      val writeSets = WriteFrameBuilder.buildAll(
        for (t <- symbolTable.getThreads()) yield (t: org.sireum.hamr.codegen.common.symbols.AadlComponent), symbolTable)
      for (fr <- frames) {
        assert(fr.writeFields.size + fr.framedFields.size == ssm.fields.size,
          s"${fr.componentAlias}: write + framed fields should partition the SystemState")
        val ws = writeSets.get(fr.componentPath).get
        assert(fr.writeFields.size == ws.outPorts.size + ws.stateVars.size ||
          fr.writeFields.size <= ws.outPorts.size + ws.stateVars.size,
          s"${fr.componentAlias}: write fields exceed the component write set")
        for (wf <- fr.writeFields.elements) {
          assert(!fr.framedFields.elements.contains(wf), s"${fr.componentAlias}: written field $wf must not be framed")
        }
      }
      frames.filter(fr => fr.componentAlias == String("mhs")) match {
        case ISZ(fr) =>
          assert(fr.writeFields.elements.contains(String("heat_control")) && fr.writeFields.elements.contains(String("lastCmd")),
            "MHS should write heat_control and lastCmd")
          assert(fr.framedFields.elements.contains(String("lower_desired_tempWstatus")) && fr.framedFields.elements.contains(String("upper_desired_tempWstatus")),
            "MHS should frame the desired tempWstatus channels")
        case _ => halt("Expected an MHS write frame")
      }
      val framesRs = VerusVCSerializer.genWriteFramesRs(frames).render
      assert(framesRs.value.contains("mhs_global_write_frame"), "write_frames.rs should contain the MHS frame")

      // --- VerusVCSerializer: actions + commutativity rendering (shared) ---
      val actions = VerusVCSerializer.buildActions(ssm, frames, symbolTable, fakeTp, reporter)
      assert(!reporter.hasError, s"Action abstraction construction failed: ${reporter.messages}")
      assert(actions.size == symbolTable.getThreads().size,
        s"Expected one action abstraction per thread, got ${actions.size}")
      val actionsRs = VerusVCSerializer.genActionsRs(actions).render
      assert(actionsRs.value.contains("pub uninterp spec fn mhs_action_heat_control("),
        "actions.rs should contain MHS's uninterpreted action fns")
      assert(actionsRs.value.contains("pub open spec fn mhs_fire("),
        "actions.rs should contain MHS's fire predicate")

      def countFns(rendered: String, prefix: Predef.String): Int = {
        var count = 0
        for (l <- rendered.value.split('\n')) {
          if (l.trim.startsWith(prefix)) {
            count += 1
          }
        }
        count
      }

      val commVCsRs = VerusVCSerializer.genCommutativityVCs(commutativityVCs, nextRel, actions, resolvedComponentAliasMap, reporter).render
      assert(!reporter.hasError, s"Commutativity VC serialization failed: ${reporter.messages}")
      val commFnCount = countFns(commVCsRs, "pub proof fn vc_commutativity")
      assert(commFnCount == ccPairs, s"Expected $ccPairs Commutativity proof fns, got $commFnCount")

      // --- VerusVCSerializer: per-property sequential + independence VCs ---
      for (property <- composition.properties) {
        val propModId = ops.StringOps(property.id).toLower
        val decoration = ScheduleNextRel.decorate(nextRel, property, reporter)
        val vcs = VCGenerator.generateForProperty(decoration, nextRel, mhipPairs, resolvedComponentAliasMap, symbolTable)

        val assertionFns = VerusVCSerializer.buildPropertyAssertions(
          propModId, decoration, ssm, symbolTable, aadlTypes, fakeTp, store, reporter)
        assert(!reporter.hasError, s"Assertion construction for '${property.id}' failed: ${reporter.messages}")
        assert(assertionFns.size == decoration.size,
          s"'${property.id}': expected one assertion fn per bound place")
        for (a <- assertionFns) {
          assert(a.fnST.render.value.contains("st."),
            s"Assertion ${a.fnName} should reference SystemState fields via st.<field>")
        }

        val seqVCs = VerusVCSerializer.genSequentialVCs(
          propModId, vcs, nextRel, ssm, contracts, frames, assertionFns, resolvedComponentAliasMap, reporter)
        assert(!reporter.hasError, s"Sequential VC serialization for '${property.id}' failed: ${reporter.messages}")

        val initRs = seqVCs.vcInitRs.render
        val seqRs = seqVCs.vcSequentialRs.render
        val postPreRs = seqVCs.vcPostPreRs.render
        assert(initRs.value.contains("vc_init_state"), "vc_*_init.rs should contain vc_init_state")
        assert(postPreRs.value.contains("vc_post_pre"), "vc_*_post_pre.rs should contain vc_post_pre")

        val seqProofFnCount = countFns(seqRs, "pub proof fn ")
        val expectedSeqFns: Int = componentTransitions.size.toInt * 2 + controlTransitions.size.toInt
        assert(seqProofFnCount == expectedSeqFns, s"Expected $expectedSeqFns sequential proof fns, got $seqProofFnCount")
        assert(seqRs.value.contains("mhs_global_write_frame(pre, post)"),
          "MHS's Next-Assert VC should require its global write frame")
        assert(seqRs.value.contains("vc_next_assert_task_mhs"),
          "task proof fns are named by the firing occurrence")

        val indVCsRs = VerusVCSerializer.genPropertyIndependenceVCs(
          propModId, vcs, nextRel, frames, assertionFns, resolvedComponentAliasMap, reporter).render
        assert(!reporter.hasError, s"Independence VC serialization for '${property.id}' failed: ${reporter.messages}")
        val nbFnCount = countFns(indVCsRs, "pub proof fn vc_pre_assertions_preservation")
        val presFnCount = countFns(indVCsRs, "pub proof fn vc_post_assertions_preservation")
        assert(nbFnCount == expectedDirected, s"Expected $expectedDirected pre-assertions preservation proof fns, got $nbFnCount")
        assert(presFnCount == expectedDirected, s"Expected $expectedDirected post-assertions preservation proof fns, got $presFnCount")
      }

      println(s"\nAll composition checks passed for '${composition.id}'")
    }
  }
}
