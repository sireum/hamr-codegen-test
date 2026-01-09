// #Sireum
// @formatter:off

// This file is auto-generated from TempUnit.scala, FanAck.scala, FanCmd.scala, Temperature_impl.scala, SetPoint_impl.scala, Base_Types.scala, DataContent.scala, Aux_Types.scala

package bc

import org.sireum._
import org.sireum.Json.Printer._

object JSON {

  object Printer {

    @pure def printBuildingControlTempUnitType(o: BuildingControl.TempUnit.Type): ST = {
      val value: String = o match {
        case BuildingControl.TempUnit.Fahrenheit => "Fahrenheit"
        case BuildingControl.TempUnit.Celsius => "Celsius"
        case BuildingControl.TempUnit.Kelvin => "Kelvin"
      }
      return printObject(ISZ(
        ("type", printString("BuildingControl.TempUnit")),
        ("value", printString(value))
      ))
    }

    @pure def printBuildingControlTempUnit_Payload(o: BuildingControl.TempUnit_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""BuildingControl.TempUnit_Payload""""),
        ("value", printBuildingControlTempUnitType(o.value))
      ))
    }

    @pure def printBuildingControlFanAckType(o: BuildingControl.FanAck.Type): ST = {
      val value: String = o match {
        case BuildingControl.FanAck.Ok => "Ok"
        case BuildingControl.FanAck.Error => "Error"
      }
      return printObject(ISZ(
        ("type", printString("BuildingControl.FanAck")),
        ("value", printString(value))
      ))
    }

    @pure def printBuildingControlFanAck_Payload(o: BuildingControl.FanAck_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""BuildingControl.FanAck_Payload""""),
        ("value", printBuildingControlFanAckType(o.value))
      ))
    }

    @pure def printBuildingControlFanCmdType(o: BuildingControl.FanCmd.Type): ST = {
      val value: String = o match {
        case BuildingControl.FanCmd.On => "On"
        case BuildingControl.FanCmd.Off => "Off"
      }
      return printObject(ISZ(
        ("type", printString("BuildingControl.FanCmd")),
        ("value", printString(value))
      ))
    }

    @pure def printBuildingControlFanCmd_Payload(o: BuildingControl.FanCmd_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""BuildingControl.FanCmd_Payload""""),
        ("value", printBuildingControlFanCmdType(o.value))
      ))
    }

    @pure def printBuildingControlTemperature_impl(o: BuildingControl.Temperature_impl): ST = {
      return printObject(ISZ(
        ("type", st""""BuildingControl.Temperature_impl""""),
        ("degrees", printF32(o.degrees)),
        ("unit", printBuildingControlTempUnitType(o.unit))
      ))
    }

    @pure def printBuildingControlTemperature_impl_Payload(o: BuildingControl.Temperature_impl_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""BuildingControl.Temperature_impl_Payload""""),
        ("value", printBuildingControlTemperature_impl(o.value))
      ))
    }

    @pure def printBuildingControlSetPoint_impl(o: BuildingControl.SetPoint_impl): ST = {
      return printObject(ISZ(
        ("type", st""""BuildingControl.SetPoint_impl""""),
        ("low", printBuildingControlTemperature_impl(o.low)),
        ("high", printBuildingControlTemperature_impl(o.high))
      ))
    }

    @pure def printBuildingControlSetPoint_impl_Payload(o: BuildingControl.SetPoint_impl_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""BuildingControl.SetPoint_impl_Payload""""),
        ("value", printBuildingControlSetPoint_impl(o.value))
      ))
    }

    @pure def printBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Boolean_Payload""""),
        ("value", printB(o.value))
      ))
    }

    @pure def printBase_TypesInteger_Payload(o: Base_Types.Integer_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_Payload""""),
        ("value", printZ(o.value))
      ))
    }

    @pure def printBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_8_Payload""""),
        ("value", printS8(o.value))
      ))
    }

    @pure def printBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_16_Payload""""),
        ("value", printS16(o.value))
      ))
    }

    @pure def printBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_32_Payload""""),
        ("value", printS32(o.value))
      ))
    }

    @pure def printBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_64_Payload""""),
        ("value", printS64(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_8_Payload""""),
        ("value", printU8(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_16_Payload""""),
        ("value", printU16(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_32_Payload""""),
        ("value", printU32(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_64_Payload""""),
        ("value", printU64(o.value))
      ))
    }

    @pure def printBase_TypesFloat_Payload(o: Base_Types.Float_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Float_Payload""""),
        ("value", printR(o.value))
      ))
    }

    @pure def printBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Float_32_Payload""""),
        ("value", printF32(o.value))
      ))
    }

    @pure def printBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Float_64_Payload""""),
        ("value", printF64(o.value))
      ))
    }

    @pure def printBase_TypesCharacter_Payload(o: Base_Types.Character_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Character_Payload""""),
        ("value", printC(o.value))
      ))
    }

    @pure def printBase_TypesString_Payload(o: Base_Types.String_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.String_Payload""""),
        ("value", printString(o.value))
      ))
    }

    @pure def printBase_TypesBits_Payload(o: Base_Types.Bits_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Bits_Payload""""),
        ("value", printISZ(T, o.value, printB _))
      ))
    }

    @pure def print_artDataContent(o: art.DataContent): ST = {
      o match {
        case o: Base_Types.Boolean_Payload => return printBase_TypesBoolean_Payload(o)
        case o: Base_Types.Integer_Payload => return printBase_TypesInteger_Payload(o)
        case o: Base_Types.Integer_8_Payload => return printBase_TypesInteger_8_Payload(o)
        case o: Base_Types.Integer_16_Payload => return printBase_TypesInteger_16_Payload(o)
        case o: Base_Types.Integer_32_Payload => return printBase_TypesInteger_32_Payload(o)
        case o: Base_Types.Integer_64_Payload => return printBase_TypesInteger_64_Payload(o)
        case o: Base_Types.Unsigned_8_Payload => return printBase_TypesUnsigned_8_Payload(o)
        case o: Base_Types.Unsigned_16_Payload => return printBase_TypesUnsigned_16_Payload(o)
        case o: Base_Types.Unsigned_32_Payload => return printBase_TypesUnsigned_32_Payload(o)
        case o: Base_Types.Unsigned_64_Payload => return printBase_TypesUnsigned_64_Payload(o)
        case o: Base_Types.Float_Payload => return printBase_TypesFloat_Payload(o)
        case o: Base_Types.Float_32_Payload => return printBase_TypesFloat_32_Payload(o)
        case o: Base_Types.Float_64_Payload => return printBase_TypesFloat_64_Payload(o)
        case o: Base_Types.Character_Payload => return printBase_TypesCharacter_Payload(o)
        case o: Base_Types.String_Payload => return printBase_TypesString_Payload(o)
        case o: Base_Types.Bits_Payload => return printBase_TypesBits_Payload(o)
        case o: art.Empty => return print_artEmpty(o)
        case o: BuildingControl.FanCmd_Payload => return printBuildingControlFanCmd_Payload(o)
        case o: BuildingControl.FanAck_Payload => return printBuildingControlFanAck_Payload(o)
        case o: BuildingControl.TempUnit_Payload => return printBuildingControlTempUnit_Payload(o)
        case o: BuildingControl.SetPoint_impl_Payload => return printBuildingControlSetPoint_impl_Payload(o)
        case o: BuildingControl.Temperature_impl_Payload => return printBuildingControlTemperature_impl_Payload(o)
      }
    }

    @pure def print_artEmpty(o: art.Empty): ST = {
      return printObject(ISZ(
        ("type", st""""art.Empty"""")
      ))
    }

  }

  @record class Parser(val input: String) {
    val parser: Json.Parser = Json.Parser.create(input)

    def errorOpt: Option[Json.ErrorMsg] = {
      return parser.errorOpt
    }

    def parseBuildingControlTempUnitType(): BuildingControl.TempUnit.Type = {
      val r = parseBuildingControlTempUnitT(F)
      return r
    }

    def parseBuildingControlTempUnitT(typeParsed: B): BuildingControl.TempUnit.Type = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.TempUnit")
      }
      parser.parseObjectKey("value")
      var i = parser.offset
      val s = parser.parseString()
      parser.parseObjectNext()
      BuildingControl.TempUnit.byName(s) match {
        case Some(r) => return r
        case _ =>
          parser.parseException(i, s"Invalid element name '$s' for BuildingControl.TempUnit.")
          return BuildingControl.TempUnit.byOrdinal(0).get
      }
    }

    def parseBuildingControlTempUnit_Payload(): BuildingControl.TempUnit_Payload = {
      val r = parseBuildingControlTempUnit_PayloadT(F)
      return r
    }

    def parseBuildingControlTempUnit_PayloadT(typeParsed: B): BuildingControl.TempUnit_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.TempUnit_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseBuildingControlTempUnitType()
      parser.parseObjectNext()
      return BuildingControl.TempUnit_Payload(value)
    }

    def parseBuildingControlFanAckType(): BuildingControl.FanAck.Type = {
      val r = parseBuildingControlFanAckT(F)
      return r
    }

    def parseBuildingControlFanAckT(typeParsed: B): BuildingControl.FanAck.Type = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.FanAck")
      }
      parser.parseObjectKey("value")
      var i = parser.offset
      val s = parser.parseString()
      parser.parseObjectNext()
      BuildingControl.FanAck.byName(s) match {
        case Some(r) => return r
        case _ =>
          parser.parseException(i, s"Invalid element name '$s' for BuildingControl.FanAck.")
          return BuildingControl.FanAck.byOrdinal(0).get
      }
    }

    def parseBuildingControlFanAck_Payload(): BuildingControl.FanAck_Payload = {
      val r = parseBuildingControlFanAck_PayloadT(F)
      return r
    }

    def parseBuildingControlFanAck_PayloadT(typeParsed: B): BuildingControl.FanAck_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.FanAck_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseBuildingControlFanAckType()
      parser.parseObjectNext()
      return BuildingControl.FanAck_Payload(value)
    }

    def parseBuildingControlFanCmdType(): BuildingControl.FanCmd.Type = {
      val r = parseBuildingControlFanCmdT(F)
      return r
    }

    def parseBuildingControlFanCmdT(typeParsed: B): BuildingControl.FanCmd.Type = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.FanCmd")
      }
      parser.parseObjectKey("value")
      var i = parser.offset
      val s = parser.parseString()
      parser.parseObjectNext()
      BuildingControl.FanCmd.byName(s) match {
        case Some(r) => return r
        case _ =>
          parser.parseException(i, s"Invalid element name '$s' for BuildingControl.FanCmd.")
          return BuildingControl.FanCmd.byOrdinal(0).get
      }
    }

    def parseBuildingControlFanCmd_Payload(): BuildingControl.FanCmd_Payload = {
      val r = parseBuildingControlFanCmd_PayloadT(F)
      return r
    }

    def parseBuildingControlFanCmd_PayloadT(typeParsed: B): BuildingControl.FanCmd_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.FanCmd_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseBuildingControlFanCmdType()
      parser.parseObjectNext()
      return BuildingControl.FanCmd_Payload(value)
    }

    def parseBuildingControlTemperature_impl(): BuildingControl.Temperature_impl = {
      val r = parseBuildingControlTemperature_implT(F)
      return r
    }

    def parseBuildingControlTemperature_implT(typeParsed: B): BuildingControl.Temperature_impl = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.Temperature_impl")
      }
      parser.parseObjectKey("degrees")
      val degrees = parser.parseF32()
      parser.parseObjectNext()
      parser.parseObjectKey("unit")
      val unit = parseBuildingControlTempUnitType()
      parser.parseObjectNext()
      return BuildingControl.Temperature_impl(degrees, unit)
    }

    def parseBuildingControlTemperature_impl_Payload(): BuildingControl.Temperature_impl_Payload = {
      val r = parseBuildingControlTemperature_impl_PayloadT(F)
      return r
    }

    def parseBuildingControlTemperature_impl_PayloadT(typeParsed: B): BuildingControl.Temperature_impl_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.Temperature_impl_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseBuildingControlTemperature_impl()
      parser.parseObjectNext()
      return BuildingControl.Temperature_impl_Payload(value)
    }

    def parseBuildingControlSetPoint_impl(): BuildingControl.SetPoint_impl = {
      val r = parseBuildingControlSetPoint_implT(F)
      return r
    }

    def parseBuildingControlSetPoint_implT(typeParsed: B): BuildingControl.SetPoint_impl = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.SetPoint_impl")
      }
      parser.parseObjectKey("low")
      val low = parseBuildingControlTemperature_impl()
      parser.parseObjectNext()
      parser.parseObjectKey("high")
      val high = parseBuildingControlTemperature_impl()
      parser.parseObjectNext()
      return BuildingControl.SetPoint_impl(low, high)
    }

    def parseBuildingControlSetPoint_impl_Payload(): BuildingControl.SetPoint_impl_Payload = {
      val r = parseBuildingControlSetPoint_impl_PayloadT(F)
      return r
    }

    def parseBuildingControlSetPoint_impl_PayloadT(typeParsed: B): BuildingControl.SetPoint_impl_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("BuildingControl.SetPoint_impl_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseBuildingControlSetPoint_impl()
      parser.parseObjectNext()
      return BuildingControl.SetPoint_impl_Payload(value)
    }

    def parseBase_TypesBoolean_Payload(): Base_Types.Boolean_Payload = {
      val r = parseBase_TypesBoolean_PayloadT(F)
      return r
    }

    def parseBase_TypesBoolean_PayloadT(typeParsed: B): Base_Types.Boolean_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Boolean_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseB()
      parser.parseObjectNext()
      return Base_Types.Boolean_Payload(value)
    }

    def parseBase_TypesInteger_Payload(): Base_Types.Integer_Payload = {
      val r = parseBase_TypesInteger_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_PayloadT(typeParsed: B): Base_Types.Integer_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseZ()
      parser.parseObjectNext()
      return Base_Types.Integer_Payload(value)
    }

    def parseBase_TypesInteger_8_Payload(): Base_Types.Integer_8_Payload = {
      val r = parseBase_TypesInteger_8_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_8_PayloadT(typeParsed: B): Base_Types.Integer_8_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_8_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS8()
      parser.parseObjectNext()
      return Base_Types.Integer_8_Payload(value)
    }

    def parseBase_TypesInteger_16_Payload(): Base_Types.Integer_16_Payload = {
      val r = parseBase_TypesInteger_16_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_16_PayloadT(typeParsed: B): Base_Types.Integer_16_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_16_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS16()
      parser.parseObjectNext()
      return Base_Types.Integer_16_Payload(value)
    }

    def parseBase_TypesInteger_32_Payload(): Base_Types.Integer_32_Payload = {
      val r = parseBase_TypesInteger_32_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_32_PayloadT(typeParsed: B): Base_Types.Integer_32_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_32_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS32()
      parser.parseObjectNext()
      return Base_Types.Integer_32_Payload(value)
    }

    def parseBase_TypesInteger_64_Payload(): Base_Types.Integer_64_Payload = {
      val r = parseBase_TypesInteger_64_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_64_PayloadT(typeParsed: B): Base_Types.Integer_64_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_64_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS64()
      parser.parseObjectNext()
      return Base_Types.Integer_64_Payload(value)
    }

    def parseBase_TypesUnsigned_8_Payload(): Base_Types.Unsigned_8_Payload = {
      val r = parseBase_TypesUnsigned_8_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_8_PayloadT(typeParsed: B): Base_Types.Unsigned_8_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_8_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU8()
      parser.parseObjectNext()
      return Base_Types.Unsigned_8_Payload(value)
    }

    def parseBase_TypesUnsigned_16_Payload(): Base_Types.Unsigned_16_Payload = {
      val r = parseBase_TypesUnsigned_16_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_16_PayloadT(typeParsed: B): Base_Types.Unsigned_16_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_16_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU16()
      parser.parseObjectNext()
      return Base_Types.Unsigned_16_Payload(value)
    }

    def parseBase_TypesUnsigned_32_Payload(): Base_Types.Unsigned_32_Payload = {
      val r = parseBase_TypesUnsigned_32_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_32_PayloadT(typeParsed: B): Base_Types.Unsigned_32_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_32_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU32()
      parser.parseObjectNext()
      return Base_Types.Unsigned_32_Payload(value)
    }

    def parseBase_TypesUnsigned_64_Payload(): Base_Types.Unsigned_64_Payload = {
      val r = parseBase_TypesUnsigned_64_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_64_PayloadT(typeParsed: B): Base_Types.Unsigned_64_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_64_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU64()
      parser.parseObjectNext()
      return Base_Types.Unsigned_64_Payload(value)
    }

    def parseBase_TypesFloat_Payload(): Base_Types.Float_Payload = {
      val r = parseBase_TypesFloat_PayloadT(F)
      return r
    }

    def parseBase_TypesFloat_PayloadT(typeParsed: B): Base_Types.Float_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Float_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseR()
      parser.parseObjectNext()
      return Base_Types.Float_Payload(value)
    }

    def parseBase_TypesFloat_32_Payload(): Base_Types.Float_32_Payload = {
      val r = parseBase_TypesFloat_32_PayloadT(F)
      return r
    }

    def parseBase_TypesFloat_32_PayloadT(typeParsed: B): Base_Types.Float_32_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Float_32_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseF32()
      parser.parseObjectNext()
      return Base_Types.Float_32_Payload(value)
    }

    def parseBase_TypesFloat_64_Payload(): Base_Types.Float_64_Payload = {
      val r = parseBase_TypesFloat_64_PayloadT(F)
      return r
    }

    def parseBase_TypesFloat_64_PayloadT(typeParsed: B): Base_Types.Float_64_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Float_64_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseF64()
      parser.parseObjectNext()
      return Base_Types.Float_64_Payload(value)
    }

    def parseBase_TypesCharacter_Payload(): Base_Types.Character_Payload = {
      val r = parseBase_TypesCharacter_PayloadT(F)
      return r
    }

    def parseBase_TypesCharacter_PayloadT(typeParsed: B): Base_Types.Character_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Character_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseC()
      parser.parseObjectNext()
      return Base_Types.Character_Payload(value)
    }

    def parseBase_TypesString_Payload(): Base_Types.String_Payload = {
      val r = parseBase_TypesString_PayloadT(F)
      return r
    }

    def parseBase_TypesString_PayloadT(typeParsed: B): Base_Types.String_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.String_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseString()
      parser.parseObjectNext()
      return Base_Types.String_Payload(value)
    }

    def parseBase_TypesBits_Payload(): Base_Types.Bits_Payload = {
      val r = parseBase_TypesBits_PayloadT(F)
      return r
    }

    def parseBase_TypesBits_PayloadT(typeParsed: B): Base_Types.Bits_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Bits_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseISZ(parser.parseB _)
      parser.parseObjectNext()
      return Base_Types.Bits_Payload(value)
    }

    def parse_artDataContent(): art.DataContent = {
      val t = parser.parseObjectTypes(ISZ("Base_Types.Boolean_Payload", "Base_Types.Integer_Payload", "Base_Types.Integer_8_Payload", "Base_Types.Integer_16_Payload", "Base_Types.Integer_32_Payload", "Base_Types.Integer_64_Payload", "Base_Types.Unsigned_8_Payload", "Base_Types.Unsigned_16_Payload", "Base_Types.Unsigned_32_Payload", "Base_Types.Unsigned_64_Payload", "Base_Types.Float_Payload", "Base_Types.Float_32_Payload", "Base_Types.Float_64_Payload", "Base_Types.Character_Payload", "Base_Types.String_Payload", "Base_Types.Bits_Payload", "art.Empty", "BuildingControl.FanCmd_Payload", "BuildingControl.FanAck_Payload", "BuildingControl.TempUnit_Payload", "BuildingControl.SetPoint_impl_Payload", "BuildingControl.Temperature_impl_Payload"))
      t.native match {
        case "Base_Types.Boolean_Payload" => val r = parseBase_TypesBoolean_PayloadT(T); return r
        case "Base_Types.Integer_Payload" => val r = parseBase_TypesInteger_PayloadT(T); return r
        case "Base_Types.Integer_8_Payload" => val r = parseBase_TypesInteger_8_PayloadT(T); return r
        case "Base_Types.Integer_16_Payload" => val r = parseBase_TypesInteger_16_PayloadT(T); return r
        case "Base_Types.Integer_32_Payload" => val r = parseBase_TypesInteger_32_PayloadT(T); return r
        case "Base_Types.Integer_64_Payload" => val r = parseBase_TypesInteger_64_PayloadT(T); return r
        case "Base_Types.Unsigned_8_Payload" => val r = parseBase_TypesUnsigned_8_PayloadT(T); return r
        case "Base_Types.Unsigned_16_Payload" => val r = parseBase_TypesUnsigned_16_PayloadT(T); return r
        case "Base_Types.Unsigned_32_Payload" => val r = parseBase_TypesUnsigned_32_PayloadT(T); return r
        case "Base_Types.Unsigned_64_Payload" => val r = parseBase_TypesUnsigned_64_PayloadT(T); return r
        case "Base_Types.Float_Payload" => val r = parseBase_TypesFloat_PayloadT(T); return r
        case "Base_Types.Float_32_Payload" => val r = parseBase_TypesFloat_32_PayloadT(T); return r
        case "Base_Types.Float_64_Payload" => val r = parseBase_TypesFloat_64_PayloadT(T); return r
        case "Base_Types.Character_Payload" => val r = parseBase_TypesCharacter_PayloadT(T); return r
        case "Base_Types.String_Payload" => val r = parseBase_TypesString_PayloadT(T); return r
        case "Base_Types.Bits_Payload" => val r = parseBase_TypesBits_PayloadT(T); return r
        case "art.Empty" => val r = parse_artEmptyT(T); return r
        case "BuildingControl.FanCmd_Payload" => val r = parseBuildingControlFanCmd_PayloadT(T); return r
        case "BuildingControl.FanAck_Payload" => val r = parseBuildingControlFanAck_PayloadT(T); return r
        case "BuildingControl.TempUnit_Payload" => val r = parseBuildingControlTempUnit_PayloadT(T); return r
        case "BuildingControl.SetPoint_impl_Payload" => val r = parseBuildingControlSetPoint_impl_PayloadT(T); return r
        case "BuildingControl.Temperature_impl_Payload" => val r = parseBuildingControlTemperature_impl_PayloadT(T); return r
        case _ => val r = parseBuildingControlTemperature_impl_PayloadT(T); return r
      }
    }

    def parse_artEmpty(): art.Empty = {
      val r = parse_artEmptyT(F)
      return r
    }

    def parse_artEmptyT(typeParsed: B): art.Empty = {
      if (!typeParsed) {
        parser.parseObjectType("art.Empty")
      }
      return art.Empty()
    }

    def eof(): B = {
      val r = parser.eof()
      return r
    }

  }

  def to[T](s: String, f: Parser => T): Either[T, Json.ErrorMsg] = {
    val parser = Parser(s)
    val r = f(parser)
    parser.eof()
    parser.errorOpt match {
      case Some(e) => return Either.Right(e)
      case _ => return Either.Left(r)
    }
  }

  def fromBuildingControlTempUnit_Payload(o: BuildingControl.TempUnit_Payload, isCompact: B): String = {
    val st = Printer.printBuildingControlTempUnit_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBuildingControlTempUnit_Payload(s: String): Either[BuildingControl.TempUnit_Payload, Json.ErrorMsg] = {
    def fBuildingControlTempUnit_Payload(parser: Parser): BuildingControl.TempUnit_Payload = {
      val r = parser.parseBuildingControlTempUnit_Payload()
      return r
    }
    val r = to(s, fBuildingControlTempUnit_Payload _)
    return r
  }

  def fromBuildingControlFanAck_Payload(o: BuildingControl.FanAck_Payload, isCompact: B): String = {
    val st = Printer.printBuildingControlFanAck_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBuildingControlFanAck_Payload(s: String): Either[BuildingControl.FanAck_Payload, Json.ErrorMsg] = {
    def fBuildingControlFanAck_Payload(parser: Parser): BuildingControl.FanAck_Payload = {
      val r = parser.parseBuildingControlFanAck_Payload()
      return r
    }
    val r = to(s, fBuildingControlFanAck_Payload _)
    return r
  }

  def fromBuildingControlFanCmd_Payload(o: BuildingControl.FanCmd_Payload, isCompact: B): String = {
    val st = Printer.printBuildingControlFanCmd_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBuildingControlFanCmd_Payload(s: String): Either[BuildingControl.FanCmd_Payload, Json.ErrorMsg] = {
    def fBuildingControlFanCmd_Payload(parser: Parser): BuildingControl.FanCmd_Payload = {
      val r = parser.parseBuildingControlFanCmd_Payload()
      return r
    }
    val r = to(s, fBuildingControlFanCmd_Payload _)
    return r
  }

  def fromBuildingControlTemperature_impl(o: BuildingControl.Temperature_impl, isCompact: B): String = {
    val st = Printer.printBuildingControlTemperature_impl(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBuildingControlTemperature_impl(s: String): Either[BuildingControl.Temperature_impl, Json.ErrorMsg] = {
    def fBuildingControlTemperature_impl(parser: Parser): BuildingControl.Temperature_impl = {
      val r = parser.parseBuildingControlTemperature_impl()
      return r
    }
    val r = to(s, fBuildingControlTemperature_impl _)
    return r
  }

  def fromBuildingControlTemperature_impl_Payload(o: BuildingControl.Temperature_impl_Payload, isCompact: B): String = {
    val st = Printer.printBuildingControlTemperature_impl_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBuildingControlTemperature_impl_Payload(s: String): Either[BuildingControl.Temperature_impl_Payload, Json.ErrorMsg] = {
    def fBuildingControlTemperature_impl_Payload(parser: Parser): BuildingControl.Temperature_impl_Payload = {
      val r = parser.parseBuildingControlTemperature_impl_Payload()
      return r
    }
    val r = to(s, fBuildingControlTemperature_impl_Payload _)
    return r
  }

  def fromBuildingControlSetPoint_impl(o: BuildingControl.SetPoint_impl, isCompact: B): String = {
    val st = Printer.printBuildingControlSetPoint_impl(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBuildingControlSetPoint_impl(s: String): Either[BuildingControl.SetPoint_impl, Json.ErrorMsg] = {
    def fBuildingControlSetPoint_impl(parser: Parser): BuildingControl.SetPoint_impl = {
      val r = parser.parseBuildingControlSetPoint_impl()
      return r
    }
    val r = to(s, fBuildingControlSetPoint_impl _)
    return r
  }

  def fromBuildingControlSetPoint_impl_Payload(o: BuildingControl.SetPoint_impl_Payload, isCompact: B): String = {
    val st = Printer.printBuildingControlSetPoint_impl_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBuildingControlSetPoint_impl_Payload(s: String): Either[BuildingControl.SetPoint_impl_Payload, Json.ErrorMsg] = {
    def fBuildingControlSetPoint_impl_Payload(parser: Parser): BuildingControl.SetPoint_impl_Payload = {
      val r = parser.parseBuildingControlSetPoint_impl_Payload()
      return r
    }
    val r = to(s, fBuildingControlSetPoint_impl_Payload _)
    return r
  }

  def fromBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesBoolean_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesBoolean_Payload(s: String): Either[Base_Types.Boolean_Payload, Json.ErrorMsg] = {
    def fBase_TypesBoolean_Payload(parser: Parser): Base_Types.Boolean_Payload = {
      val r = parser.parseBase_TypesBoolean_Payload()
      return r
    }
    val r = to(s, fBase_TypesBoolean_Payload _)
    return r
  }

  def fromBase_TypesInteger_Payload(o: Base_Types.Integer_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_Payload(s: String): Either[Base_Types.Integer_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_Payload(parser: Parser): Base_Types.Integer_Payload = {
      val r = parser.parseBase_TypesInteger_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_Payload _)
    return r
  }

  def fromBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_8_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_8_Payload(s: String): Either[Base_Types.Integer_8_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_8_Payload(parser: Parser): Base_Types.Integer_8_Payload = {
      val r = parser.parseBase_TypesInteger_8_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_8_Payload _)
    return r
  }

  def fromBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_16_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_16_Payload(s: String): Either[Base_Types.Integer_16_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_16_Payload(parser: Parser): Base_Types.Integer_16_Payload = {
      val r = parser.parseBase_TypesInteger_16_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_16_Payload _)
    return r
  }

  def fromBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_32_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_32_Payload(s: String): Either[Base_Types.Integer_32_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_32_Payload(parser: Parser): Base_Types.Integer_32_Payload = {
      val r = parser.parseBase_TypesInteger_32_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_32_Payload _)
    return r
  }

  def fromBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_64_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_64_Payload(s: String): Either[Base_Types.Integer_64_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_64_Payload(parser: Parser): Base_Types.Integer_64_Payload = {
      val r = parser.parseBase_TypesInteger_64_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_64_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_8_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_8_Payload(s: String): Either[Base_Types.Unsigned_8_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_8_Payload(parser: Parser): Base_Types.Unsigned_8_Payload = {
      val r = parser.parseBase_TypesUnsigned_8_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_8_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_16_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_16_Payload(s: String): Either[Base_Types.Unsigned_16_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_16_Payload(parser: Parser): Base_Types.Unsigned_16_Payload = {
      val r = parser.parseBase_TypesUnsigned_16_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_16_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_32_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_32_Payload(s: String): Either[Base_Types.Unsigned_32_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_32_Payload(parser: Parser): Base_Types.Unsigned_32_Payload = {
      val r = parser.parseBase_TypesUnsigned_32_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_32_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_64_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_64_Payload(s: String): Either[Base_Types.Unsigned_64_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_64_Payload(parser: Parser): Base_Types.Unsigned_64_Payload = {
      val r = parser.parseBase_TypesUnsigned_64_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_64_Payload _)
    return r
  }

  def fromBase_TypesFloat_Payload(o: Base_Types.Float_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesFloat_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesFloat_Payload(s: String): Either[Base_Types.Float_Payload, Json.ErrorMsg] = {
    def fBase_TypesFloat_Payload(parser: Parser): Base_Types.Float_Payload = {
      val r = parser.parseBase_TypesFloat_Payload()
      return r
    }
    val r = to(s, fBase_TypesFloat_Payload _)
    return r
  }

  def fromBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesFloat_32_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesFloat_32_Payload(s: String): Either[Base_Types.Float_32_Payload, Json.ErrorMsg] = {
    def fBase_TypesFloat_32_Payload(parser: Parser): Base_Types.Float_32_Payload = {
      val r = parser.parseBase_TypesFloat_32_Payload()
      return r
    }
    val r = to(s, fBase_TypesFloat_32_Payload _)
    return r
  }

  def fromBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesFloat_64_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesFloat_64_Payload(s: String): Either[Base_Types.Float_64_Payload, Json.ErrorMsg] = {
    def fBase_TypesFloat_64_Payload(parser: Parser): Base_Types.Float_64_Payload = {
      val r = parser.parseBase_TypesFloat_64_Payload()
      return r
    }
    val r = to(s, fBase_TypesFloat_64_Payload _)
    return r
  }

  def fromBase_TypesCharacter_Payload(o: Base_Types.Character_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesCharacter_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesCharacter_Payload(s: String): Either[Base_Types.Character_Payload, Json.ErrorMsg] = {
    def fBase_TypesCharacter_Payload(parser: Parser): Base_Types.Character_Payload = {
      val r = parser.parseBase_TypesCharacter_Payload()
      return r
    }
    val r = to(s, fBase_TypesCharacter_Payload _)
    return r
  }

  def fromBase_TypesString_Payload(o: Base_Types.String_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesString_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesString_Payload(s: String): Either[Base_Types.String_Payload, Json.ErrorMsg] = {
    def fBase_TypesString_Payload(parser: Parser): Base_Types.String_Payload = {
      val r = parser.parseBase_TypesString_Payload()
      return r
    }
    val r = to(s, fBase_TypesString_Payload _)
    return r
  }

  def fromBase_TypesBits_Payload(o: Base_Types.Bits_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesBits_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesBits_Payload(s: String): Either[Base_Types.Bits_Payload, Json.ErrorMsg] = {
    def fBase_TypesBits_Payload(parser: Parser): Base_Types.Bits_Payload = {
      val r = parser.parseBase_TypesBits_Payload()
      return r
    }
    val r = to(s, fBase_TypesBits_Payload _)
    return r
  }

  def from_artDataContent(o: art.DataContent, isCompact: B): String = {
    val st = Printer.print_artDataContent(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def to_artDataContent(s: String): Either[art.DataContent, Json.ErrorMsg] = {
    def f_artDataContent(parser: Parser): art.DataContent = {
      val r = parser.parse_artDataContent()
      return r
    }
    val r = to(s, f_artDataContent _)
    return r
  }

  def from_artEmpty(o: art.Empty, isCompact: B): String = {
    val st = Printer.print_artEmpty(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def to_artEmpty(s: String): Either[art.Empty, Json.ErrorMsg] = {
    def f_artEmpty(parser: Parser): art.Empty = {
      val r = parser.parse_artEmpty()
      return r
    }
    val r = to(s, f_artEmpty _)
    return r
  }

}