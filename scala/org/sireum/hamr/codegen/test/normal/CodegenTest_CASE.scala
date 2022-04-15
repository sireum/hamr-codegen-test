package org.sireum.hamr.codegen.test.normal

import org.sireum.$internal.RC
import org.sireum._
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.{TestResources, baseOptions}

case class TestContainer(testName: String,
                         modelDir: Os.Path,
                         json: Option[Os.Path],
                         platform: ISZ[CodeGenPlatform.Type],
                         expectedErrorReasons: ISZ[String])

class CodegenTest_CASE extends CodeGenTest {

  override def generateExpected: B = if(super.generateExpected) T else F

  val testResources: TestResources = CodeGenTest.defaultTestLayout(getClass())

  val tests = Tests {
    val id = "case_tool_evaluation"

    val(linux, sel4, sel4_tb, sel4_only) = (CodeGenPlatform.Linux, CodeGenPlatform.SeL4, CodeGenPlatform.SeL4_TB, CodeGenPlatform.SeL4_Only)

    val case_tool_evaluation_dir = testResources.modelsDir
    //val resultDir: Option[String] = Some(getClass.getSimpleName)

    def genFail(name: String,
                json: String,
                platforms: ISZ[CodeGenPlatform.Type],
                expectedErrorReasons: ISZ[String]): TestContainer = {
      genTest(name, json, platforms, expectedErrorReasons)
    }

    def gen(name: String, json: String, platforms: ISZ[CodeGenPlatform.Type]): TestContainer = {
      genTest(name, json, platforms, ISZ())
    }

    def genTest(name: String,
                json: String,
                platforms: ISZ[CodeGenPlatform.Type],
                expectedErrorReasons: ISZ[String]): TestContainer = {
      val modelDir = case_tool_evaluation_dir / name
      val testName = name.native.replaceAll("/", "__")
      return TestContainer(testName, modelDir, Some(modelDir / ".slang" / json), platforms, expectedErrorReasons)
    }

    val tests: ISZ[TestContainer] = ISZ(

      gen("uav_june_step6", "UAV_UAV_Impl_Instance.json", ISZ(linux, sel4)),

      gen("VPM_ben", "VPM_VPM_8600B_Ext_impl_Instance.json", ISZ(linux, sel4)),

      gen("attestation-gate", "SysContext_top_Impl_Instance.json", ISZ(sel4)),

      gen("simple_uav", "UAV_UAV_Impl_Instance.json", ISZ(sel4_tb, sel4_only)),

      gen("test_data_port", "test_data_port_top_impl_Instance.json", ISZ(sel4_tb, sel4_only)),
      gen("test_data_port_periodic", "test_data_port_periodic_top_impl_Instance.json", ISZ(sel4_tb, sel4_only)),
      gen("test_data_port_periodic_fan_out", "test_data_port_periodic_fan_out_top_impl_Instance.json", ISZ(sel4_tb, sel4_only)),

      gen("test_event_data_port", "test_event_data_port_top_impl_Instance.json", ISZ(sel4_tb, sel4_only)),
      gen("test_event_data_port_fan_out", "test_event_data_port_fan_out_top_impl_Instance.json", ISZ(sel4_tb, sel4_only)),

      gen("test_event_port", "test_event_port_top_impl_Instance.json", ISZ(sel4_tb, sel4_only)),
      gen("test_event_port_fan_out", "test_event_port_fan_out_top_impl_Instance.json", ISZ(sel4_tb, sel4_only)),

      gen("test_data_port_periodic_domains", "test_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_tb, sel4_only, sel4)),
      gen("test_event_data_port_periodic_domains", "test_event_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_tb, sel4_only, sel4)),
      gen("test_event_port_periodic_domains", "test_event_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_tb, sel4_only, sel4)),

      // VMs
      gen("test_data-port-periodic_domains_VM/both_vm", "test_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_only, sel4)),
      gen("test_data-port-periodic_domains_VM/receiver_vm", "test_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_only, sel4)),
      gen("test_data-port-periodic_domains_VM/sender_vm", "test_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_only, sel4)),

      gen("test_event_data_port_periodic_domains_VM/both_vm", "test_event_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_only, sel4)),
      gen("test_event_data_port_periodic_domains_VM/receiver_vm", "test_event_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_only, sel4)),
      gen("test_event_data_port_periodic_domains_VM/sender_vm", "test_event_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_only, sel4))
    )

    for (container <- tests) {

      for (platform <- container.platform) {
        test(
          testName = s"${container.testName}--${platform}",
          modelDir = container.modelDir,
          airFile = container.json,
          ops = baseOptions(
            platform = platform,

            excludeComponentImpl = T,
            devicesAsThreads = F,

            bitWidth = 32,
            maxStringSize = 256
          ),
          description = None(),
          modelUri = None(),
          expectedErrorReasons = container.expectedErrorReasons)
      }
    }
  }

  /*
  def testResources(): TestResources = {
    // scala/java 'resources' directories don't play nicely with mill so instead embed the contents
    // of 'expected' and 'models' into the test class via the RC macros .  These can then
    // be retrieved as a map from 'exploded path' to 'contents' via a call to 'testResources()'

    val files = RC.base64(Vector("../../../../../../../resources")) { (p, f) =>
      val cname = "CodegenTest_CASE"
      val allowedDirs: ISZ[Predef.String] = ISZ(s"expected/${cname}", s"models/${cname}")

      val dirAllowed: B = {
        var matched: B = F
        for(allowedDir <- allowedDirs if !matched) {
          val split: Array[Predef.String] = allowedDir.split("/")
          var index: Int = 0
          while(index < split.length && index < p.length && split(index) == p(index)) { index = index + 1 }
          matched = index == split.length
        }
        matched
      }

      // exclude unneeded files by their extension
      val excludedResources: ISZ[org.sireum.String] =
        ISZ("aadlbin", "aaxl2", "png", "pdf", "md", "dot", "aadl_diagram", "reqspec",
          "alisa", "org", "cat", "verify", "methodregistry", "gitignore", "goals", "xassure")

      val filename = Os.path(p.last)

      val allow = dirAllowed &&
        !ops.ISZOps(excludedResources).contains(filename.ext) &&
        ((p.size > 1 && p(p.size - 2) != ".slang") || filename.ext.native != "json") // exclude json files in the .slang directories

      if(allow) {
        //println(s"allowed: ${p} - ${f.length()}")
        //println(f.length())
      } else {
        //println(s"NOT allowed: ${p} - ${f.length()}")
      }

      allow
    }
    return TestResources(files)
  }
  */
}
