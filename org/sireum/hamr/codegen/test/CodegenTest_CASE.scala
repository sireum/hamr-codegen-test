package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest.baseOptions

class CodegenTest_CASE extends CodeGenTest {

  override def generateExpected: B = if(super.generateExpected) T else F
  
  val tests = Tests {
    val id = "case_tool_evaluation"

    val(sel4, sel4_tb, sel4_only) = (CodeGenPlatform.SeL4, CodeGenPlatform.SeL4_TB, CodeGenPlatform.SeL4_Only)

    val case_tool_evaluation_dir = baseModelsDir / getClass.getSimpleName
    val resultDir: Option[String] = Some(getClass.getSimpleName)

    def gen(name: String, json: String, platforms: ISZ[CodeGenPlatform.Type]): (String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type]) = {
      val modelDir = case_tool_evaluation_dir / name
      val testName = name.native.replaceAll("/", "__")
      return (testName, modelDir, modelDir / ".slang" / json, platforms)
    }

    val tests: ISZ[(String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type])] = ISZ(

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
      gen("test_event_data_port_periodic_domains_VM/sender_vm", "test_event_data_port_periodic_domains_top_impl_Instance.json", ISZ(sel4_only, sel4)),

    )

    for (proj <- tests) {

      for (platform <- proj._4) {
        test(s"${proj._1}--${platform}", proj._2, proj._3,
          baseOptions(
            platform = platform,

            excludeComponentImpl = T,
            devicesAsThreads = F,

            bitWidth = 32,
            maxStringSize = 256
          ),
          resultDir, None(), None())
      }
    }
  }
}
