package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest.{baseOptions, modelsDir}

class CodegenTest_CASE extends CodeGenTest {

  override def generateExpected: B = if(super.generateExpected) T else F
  
  val tests = Tests {
    val id = "case_tool_evaluation"

    val case_tool_evaluation_dir = CodeGenTest.modelsDir / getClass.getSimpleName
    val resultDir: Option[String] = Some(getClass.getSimpleName)

    def gen(name: String, json: String): (String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type]) = {
      genPlatforms(name, json, ISZ())
    }

    def genPlatforms(name: String, json: String, platforms: ISZ[CodeGenPlatform.Type]): (String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type]) = {
      val _platforms: Set[CodeGenPlatform.Type] =
        Set.empty[CodeGenPlatform.Type] ++ ISZ(CodeGenPlatform.SeL4_Only, CodeGenPlatform.SeL4_TB) ++ platforms

      val modelDir = case_tool_evaluation_dir / name
      return (name, modelDir, modelDir / ".slang" / json, _platforms.elements)
    }

    val tests: ISZ[(String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type])] = ISZ(
      gen("simple_uav", "UAV_UAV_Impl_Instance.json"),

      gen("test_data_port", "test_data_port_top_impl_Instance.json"),
      gen("test_data_port_periodic", "test_data_port_periodic_top_impl_Instance.json"),
      gen("test_data_port_periodic_fan_out", "test_data_port_periodic_fan_out_top_impl_Instance.json"),

      gen("test_event_data_port", "test_event_data_port_top_impl_Instance.json"),
      gen("test_event_data_port_fan_out", "test_event_data_port_fan_out_top_impl_Instance.json"),

      gen("test_event_port", "test_event_port_top_impl_Instance.json"),
      gen("test_event_port_fan_out", "test_event_port_fan_out_top_impl_Instance.json"),

      gen("test_data_port_periodic_domains", "test_data_port_periodic_domains_top_impl_Instance.json"),
      gen("test_event_data_port_periodic_domains", "test_event_data_port_periodic_domains_top_impl_Instance.json"),
      gen("test_event_port_periodic_domains", "test_event_port_periodic_domains_top_impl_Instance.json"),
    )

    for (proj <- tests) {
      val xplatforms = proj._4 ++ { if(proj._1.native.endsWith("domains")) ISZ(CodeGenPlatform.SeL4) else ISZ() }
      
      for (platform <- xplatforms) {
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
