package org.sireum.hamr.codegen.test.normal

import org.sireum._
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.{TestResources, baseOptions}
import org.sireum.hamr.codegen.test.util.TestMode

class CodeGenTest_Base extends CodeGenTest {

  override def generateExpected: B = super.generateExpected || F

  override def filter: B = super.filter || F
  override def filters: ISZ[String] = ISZ("Do-not-embed")

  override def testModes: _root_.org.sireum.ISZ[TestMode.Type] =
    super.testModes // :+ TestMode.tipe :+ TestMode.compile

  val testResources: TestResources = CodeGenTest.defaultTestLayout(getClass())

  val tests = Tests {
    val modelsDir = testResources.modelsDir

    {
      val name = "arrays"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "arrays_PC_Sys_Impl_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.Linux
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())
    }

    {
      val name = "nested_feature_groups"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "Nested_Feature_Group_Test_S_impl_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())
    }

    {
      val name = "wms"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "wbs_wms_impl_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4
      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          devicesAsThreads = F,
          excludeComponentImpl = T,
          bitWidth = 32),
        None(), None(), ISZ())
    }

    {
      val name = "pca-pump"
      val modelDir = modelsDir / name
      val model = Some(modelDir / "pca" / ".slang" / "PCA_System_wrap_pca_imp_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          devicesAsThreads = T),
        None(), None(), ISZ())
    }

    {
      val name = "isolette"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "Isolette_isolette_single_sensor_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())

      platform = CodeGenPlatform.Linux
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())

      platform = CodeGenPlatform.SeL4
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())
    }

    {
      val name = "building_control_gen_mixed"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "BuildingControl_BuildingControlDemo_i_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}-Embed-Art", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())

      test(s"$name--${platform}--runtime-monitoring", modelDir, model,
        baseOptions(platform = platform,
          runtimeMonitoring = T),
        None(), None(), ISZ())

      platform = CodeGenPlatform.JVM
      test(s"$name--${platform}-Do-not-embed-art", modelDir, model,
        baseOptions(platform = platform,
          noEmbedArt = T),
        None(), None(), ISZ())

      platform = CodeGenPlatform.Linux
      test(s"$name--${platform}-Embed-Art-SharedMemory", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())

      platform = CodeGenPlatform.Linux
      test(s"$name--${platform}-Embed-Art-SharedMemory-Excludes", modelDir, model,
        baseOptions(platform = platform,
          excludeComponentImpl = T),
        None(), None(), ISZ())

      platform = CodeGenPlatform.SeL4
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform,
          excludeComponentImpl = T,
          devicesAsThreads = F,
          maxStringSize = 300,
          packageName = Some("building_control_gen_mixed")
        ),
        None(), None(), ISZ())

    }

    { // UAV_ALT tests
      val name = "uav_alt"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "UAV_UAV_Impl_Instance.json")
      val uri: Option[String] = Some("https://github.com/ku-sldg/CASETeam/tree/8a96b31cf7b466ee3d558d349f21835e427d37c9/examples/tool-eval-2/ACT_Demo_Dec2018_alt")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), uri, ISZ())

      platform = CodeGenPlatform.Linux
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform,
          maxStringSize = 300),
        None(), uri, ISZ())

      platform = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), uri, ISZ())

      platform = CodeGenPlatform.SeL4_Only
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), uri, ISZ())
    }

    { // UAV_ALT_DOMAINS
      val name = "uav_alt_domains"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "UAV_UAV_Impl_Instance.json")
      val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/experiments/Simple_UAV_Example_domains")
      val description: Option[String] = Some(
        """Incomplete - Need to introduce pacer component for seL4_Only profile
          |           - Entrypoints not defined in AADL model so CAmkES components will not be dispatched""".stripMargin)

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        description, uri, ISZ())

      platform = CodeGenPlatform.SeL4_Only
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        description, uri, ISZ())
    }

    { // UAV extern
      val name = "uav_alt_extern"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "UAV_UAV_Impl_Instance.json")
      val uri: Option[String] = Some("https://github.com/ku-sldg/CASETeam/tree/8a96b31cf7b466ee3d558d349f21835e427d37c9/examples/ksu-proprietary/simple-uav-slang-example/uav-project-extern/src/aadl/ACT_Demo_Dec2018")
      val platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4

      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = Some("uav_project_extern"),
          maxStringSize = 300,
          devicesAsThreads = F
        ),
        None(), uri, ISZ())

      test(s"$name--${platform}-excludesImpl", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = Some("uav_project_extern"),
          maxStringSize = 300,
          devicesAsThreads = F,
          excludeComponentImpl = T
        ),
        None(), uri, ISZ())

    }

    { // Data port micro example
      {
        val name = "testdpmon"
        val modelDir = modelsDir / name
        val model = Some(modelDir / ".slang" / "testdpmon_top_impl_Instance.json")
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testdpmon")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some("Data port micro-example - Trusted Build profile"), uri, ISZ()
        )

        platform = CodeGenPlatform.SeL4_Only
        val jimUri = "https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/experiments/Simple_UAV_Example_domains/CAmkES"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Data port micro-example - New Adventium translation profile: ${jimUri}"), uri, ISZ()
        )
      }
    }

    { // Data port micro example
      {
        val name = "testdpmon-periodic"
        val modelDir = modelsDir / name
        val model = Some(modelDir / ".slang" / "testdpmon_top_impl_Instance.json")
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testdpmon-periodic")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some("Data port micro-example with periodic threads - Trusted Build profile"), uri, ISZ()
        )

        platform = CodeGenPlatform.SeL4_Only
        val jimUri = "https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/experiments/Simple_UAV_Example_domains/CAmkES"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Data port micro-example with periodic threads - New Adventium translation profile: ${jimUri}"), uri, ISZ()
        )
      }
    }


    { // Event Data port micro example
      {
        val name = "testepmon"
        val modelDir = modelsDir / name
        val model = Some(modelDir / ".slang" / "testepmon_top_impl_Instance.json")
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testepmon")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Event Data port micro-example - Trusted Build profile"), uri, ISZ()
        )

        platform = CodeGenPlatform.SeL4_Only
        val ihorUri = "https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-eventdata-monitor"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Event Data port micro-example - Ihor aadl-eventdata-monitor profile: ${ihorUri}"), uri, ISZ()
        )
      }

      { // Event port micro example
        {
          val name = "testevent"
          val modelDir = modelsDir / name
          val model = Some(modelDir / ".slang" / "testevent_top_impl_Instance.json")
          val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testevent")

          var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
          test(s"$name--${platform}", modelDir, model,
            baseOptions(platform = platform),
            Some("Event port micro-example - Trusted Build profile"), uri, ISZ()
          )

          platform = CodeGenPlatform.SeL4_Only
          val ihorUri = "https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-event-direct"
          test(s"$name--${platform}", modelDir, model,
            baseOptions(platform = platform),
            Some(s"Event port micro-example - Ihor aadl-event-direct: ${ihorUri}"), uri, ISZ()
          )
        }
      }
    }

    { // Event port micro example
      {
        val name = "testevent_MultQueue"
        val modelDir = modelsDir / name
        val model = Some(modelDir / ".slang" / "testevent_top_impl_Instance.json")
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testevent")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some("Event port micro-example - Trusted Build profile"), uri, ISZ()
        )

        platform = CodeGenPlatform.SeL4_Only
        val ihorUri = "https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-event-direct"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Event port micro-example - Ihor aadl-event-direct: ${ihorUri}"), uri, ISZ()
        )
      }
    }

    { // Shared Data micro example
      {
        val name = "testshare"
        val modelDir = modelsDir / name
        val model = Some(modelDir / ".slang" / "testshare_top_impl_Instance.json")
        val modelUri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testshare")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          None(), modelUri, ISZ()
        )
      }
    }

    { // Subprogram micro example
      {
        val name = "testsubprogram"
        val modelDir = modelsDir / name
        val model = Some(modelDir / ".slang" / "testsubprogram_top_impl_Instance.json")
        val modelUri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testsubprogram")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          None(), modelUri, ISZ()
        )
      }
    }

    { // Periodic dispatch
      val name = "periodicDispatch"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "periodic_Critical_Impl_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ()
      )
    }

    { // Urgeny
      val name = "urgency"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "Urgency_Sys_impl_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ()
      )

      platform = CodeGenPlatform.Linux
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ()
      )
    }

    { // bit_codec
      val name = "bit_codec"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "Bit_Codec_Bit_Codec_Sys_Impl_Instance.json")

      val packageName: Option[String] = Some("bit_codec")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      val bo = baseOptions(
        platform = platform,
        packageName = packageName,
        maxStringSize = 300,
        devicesAsThreads = F
      )
      test(s"$name--${platform}", modelDir, model, bo, None(), None(), ISZ())

      platform = CodeGenPlatform.Linux
      test(s"$name--${platform}", modelDir, model,
        bo(platform = platform), None(), None(), ISZ())

      test(s"$name--${platform}-excludesImpl", modelDir, model,
        bo(platform = platform, excludeComponentImpl = T),
        None(), None(), ISZ())

      platform = CodeGenPlatform.SeL4
      test(s"$name--${platform}", modelDir, model,
        bo(platform = platform), None(), None(), ISZ())

      test(s"$name--${platform}-excludesImpl", modelDir, model,
        bo(platform = platform, excludeComponentImpl = T),
        None(), None(), ISZ())
    }

    { // producer filter consumer periodic
      val name = "producer_filter_consumer_periodic"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "PFC_PFC_Sys_Impl_Instance.json")

      val platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4
      val packageName: Option[String] = Some("pfc_project")

      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = packageName,
          maxStringSize = 300,
          devicesAsThreads = F
        ),
        None(), None(), ISZ())

      test(s"$name--${platform}-excludesImpl", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = packageName,
          maxStringSize = 300,
          devicesAsThreads = F,
          excludeComponentImpl = T
        ),
        None(), None(), ISZ())
    }

    { // producer filter consumer periodic
      val name = "producer_filter_consumer_sporadic"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "PFC_PFC_Sys_Impl_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4
      val packageName: Option[String] = Some("pfc_project")

      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = packageName,
          maxStringSize = 300,
          devicesAsThreads = F
        ),
        None(), None(), ISZ())

      test(s"$name--${platform}-excludesImpl", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = packageName,
          maxStringSize = 300,
          devicesAsThreads = F,
          excludeComponentImpl = T
        ),
        None(), None(), ISZ())
    }

    { // producer filter consumer mixed
      val name = "producer_filter_consumer_mixed"
      val modelDir = modelsDir / name
      val model = Some(modelDir / ".slang" / "PFC_PFC_Sys_Impl_Instance.json")

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4
      val packageName: Option[String] = Some("pfc_project")

      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = packageName,
          maxStringSize = 300,
          devicesAsThreads = F
        ),
        None(), None(), ISZ())

      test(s"$name--${platform}-excludesImpl", modelDir, model,
        baseOptions(
          platform = platform,
          packageName = packageName,
          maxStringSize = 300,
          devicesAsThreads = F,
          excludeComponentImpl = T
        ),
        None(), None(), ISZ())
    }
  }
}
