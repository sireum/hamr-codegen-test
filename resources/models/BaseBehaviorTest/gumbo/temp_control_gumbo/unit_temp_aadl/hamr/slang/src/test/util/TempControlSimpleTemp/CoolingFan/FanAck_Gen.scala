package TempControlSimpleTemp.CoolingFan

import org.scalacheck.Gen

object FanAck_Gen {

  val simple: Gen[FanAck.Type] = for {
    n <- Gen.oneOf(FanAck.Ok,FanAck.Error)
  } yield n

  val default: Gen[FanAck.Type] = simple
}
