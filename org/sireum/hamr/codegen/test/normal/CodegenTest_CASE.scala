package org.sireum.hamr.codegen.test.normal

import org.sireum._
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.baseOptions

case class TestContainer(testName: String,
                         modelDir: Os.Path,
                         json: Os.Path,
                         platform: ISZ[CodeGenPlatform.Type],
                         expectedErrorReasons: ISZ[String])

class CodegenTest_CASE extends CodeGenTest {

  override def generateExpected: B = if(super.generateExpected) T else F
  
  val tests = Tests {
    val id = "case_tool_evaluation"

    val(linux, sel4, sel4_tb, sel4_only) = (CodeGenPlatform.Linux, CodeGenPlatform.SeL4, CodeGenPlatform.SeL4_TB, CodeGenPlatform.SeL4_Only)

    val case_tool_evaluation_dir = baseModelsDir / getClass.getSimpleName
    val resultDir: Option[String] = Some(getClass.getSimpleName)

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
      return TestContainer(testName, modelDir, modelDir / ".slang" / json, platforms, expectedErrorReasons)
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
          resultDir = resultDir,
          description = None(),
          modelUri = None(),
          expectedErrorReasons = container.expectedErrorReasons)
      }
    }
  }
}
