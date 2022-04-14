// #Sireum

import org.sireum._
import org.sireum.bitcodec.Spec
import org.sireum.bitcodec.Spec._

val monitorPacket: Spec.Base =
  Concat("MonitorPacket", ISZ(
    Boolean("shouldInflate"),
  ))

println(monitorPacket.toJSON(T))
