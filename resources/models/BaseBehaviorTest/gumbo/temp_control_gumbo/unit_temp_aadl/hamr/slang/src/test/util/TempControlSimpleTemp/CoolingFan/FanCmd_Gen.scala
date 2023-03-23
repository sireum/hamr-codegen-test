package TempControlSimpleTemp.CoolingFan

import org.scalacheck.Gen

object FanCmd_Gen {
  // auto-generated
  // Note: An alternate approach would be to use the ordinal access approach:
  //   CoolingFan.FanCmd.byOrdinal(0).get
  val simple: Gen[FanCmd.Type] = for {
    n <- Gen.oneOf(FanCmd.On,FanCmd.Off)
  } yield n

  val default: Gen[FanCmd.Type] = simple
}
