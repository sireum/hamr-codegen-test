// #Sireum

import org.sireum._
import org.sireum.bitcodec.Spec
import org.sireum.bitcodec.Spec._

val sensorPacket: Spec.Base =
  Concat("SensorPacket", ISZ(
    Float("pressure"),
  ))

println(sensorPacket.toJSON(T))
