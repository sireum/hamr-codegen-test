package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest.{baseOptions, modelsDir}

class CodeGenTest_Base extends CodeGenTest {

  override def generateExpected: B = if(super.generateExpected) T else F
  
  val tests = Tests {
    val resultDir: Option[String] = Some(getClass.getSimpleName)
    val modelsDir = CodeGenTest.modelsDir / getClass.getSimpleName
    
    {
      val name = "building_control_gen_mixed"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "BuildingControl_BuildingControlDemo_i_Instance.json"
      
      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}-Embed-Art", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), None())
      test(s"$name--${platform}-Do-not-embed-art", modelDir, model,
        baseOptions(platform = platform,
          embedArt = F),
        resultDir, None(), None())
    }
    
    { // UAV_ALT tests
      val name = "uav_alt"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"
      val uri: Option[String] = Some("https://github.com/ku-sldg/CASETeam/tree/8a96b31cf7b466ee3d558d349f21835e427d37c9/examples/tool-eval-2/ACT_Demo_Dec2018_alt")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), uri)

      platform = CodeGenPlatform.MacOS
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), uri)

      platform = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), uri)

      platform = CodeGenPlatform.SeL4_Only
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), uri)
    }

    { // UAV_ALT_DOMAINS
      val name = "uav_alt_domains"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"
      val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/experiments/Simple_UAV_Example_domains")
      val description: Option[String] = Some("""Incomplete - Need to introduce pacer component for seL4_Only profile
                                               |           - Entrypoints not defined in AADL model so CAmkES components will not be dispatched""".stripMargin)

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, description, uri)

      platform = CodeGenPlatform.SeL4_Only
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, description, uri)
    }

    { // UAV extern
      val name = "uav_alt_extern"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"
      val uri: Option[String] = Some("https://github.com/ku-sldg/CASETeam/tree/8a96b31cf7b466ee3d558d349f21835e427d37c9/examples/ksu-proprietary/simple-uav-slang-example/uav-project-extern/src/aadl/ACT_Demo_Dec2018")
      val description: Option[String] = Some("Using dummy transpiler")
      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4
      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          camkesAuxCodeDirs = ISZ((modelDir / "aux_code").value)
        ),
        resultDir, None(), uri)
    }

    { // Data port micro example
      {
        val name = "testdpmon"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testdpmon_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testdpmon")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir, 
          Some("Data port micro-example - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val jimUri = "https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/experiments/Simple_UAV_Example_domains/CAmkES"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          Some(s"Data port micro-example - New Adventium translation profile: ${jimUri}"), uri
        )
      }
    }

    { // Data port micro example
      {
        val name = "testdpmon-periodic"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testdpmon_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testdpmon-periodic")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          Some("Data port micro-example with periodic threads - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val jimUri = "https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/experiments/Simple_UAV_Example_domains/CAmkES"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          Some(s"Data port micro-example with periodic threads - New Adventium translation profile: ${jimUri}"), uri
        )
      }
    }


    { // Event Data port micro example
      {
        val name = "testepmon"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testepmon_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testepmon")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          Some(s"Event Data port micro-example - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val ihorUri ="https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-eventdata-monitor"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          Some(s"Event Data port micro-example - Ihor aadl-eventdata-monitor profile: ${ihorUri}"), uri
        )
      }

      { // Event port micro example
        {
          val name = "testevent"
          val modelDir = modelsDir / name
          val model = modelDir / ".slang" / "testevent_top_impl_Instance.json"
          val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testevent")

          var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
          test(s"$name--${platform}", modelDir, model,
            baseOptions(platform = platform),
            resultDir,
            Some("Event port micro-example - Trusted Build profile"), uri
          )

          platform = CodeGenPlatform.SeL4_Only
          val ihorUri = "https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-event-direct"
          test(s"$name--${platform}", modelDir, model,
            baseOptions(platform = platform),
            resultDir,
            Some(s"Event port micro-example - Ihor aadl-event-direct: ${ihorUri}"), uri
          )
        }
      }
    }

    { // Event port micro example
      {
        val name = "testevent_MultQueue"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testevent_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testevent")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          Some("Event port micro-example - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val ihorUri = "https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-event-direct"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          Some(s"Event port micro-example - Ihor aadl-event-direct: ${ihorUri}"), uri
        )
      }
    }

    { // Shared Data micro example
      {
        val name = "testshare"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testshare_top_impl_Instance.json"
        val modelUri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testshare")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          None(), modelUri
        )
      }
    }

    { // Subprogram micro example
      {
        val name = "testsubprogram"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testsubprogram_top_impl_Instance.json"
        val modelUri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testsubprogram")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          resultDir,
          None(), modelUri
        )
      }
    }

    { // Periodic dispatch
      val name = "periodicDispatch"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "periodic_Critical_Impl_Instance.json"

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), None()
      )
    }

    { // Urgeny
      val name = "urgency"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "Urgency_Sys_impl_Instance.json"

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), None()
      )
      
      platform = CodeGenPlatform.Linux
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), None()
      )
    }
  }
}
