// #Sireum
// @formatter:off

// This file is auto-generated from TempUnit.scala, Temperature_impl.scala, FanAck.scala, SetPoint_impl.scala, FanCmd.scala, Base_Types.scala, DataContent.scala, Aux_Types.scala

package bc

import org.sireum._

object MsgPack {

  object Constants {

    val BuildingControlTempUnit_Payload: Z = -32

    val BuildingControlTemperature_impl: Z = -31

    val BuildingControlTemperature_impl_Payload: Z = -30

    val BuildingControlFanAck_Payload: Z = -29

    val BuildingControlSetPoint_impl: Z = -28

    val BuildingControlSetPoint_impl_Payload: Z = -27

    val BuildingControlFanCmd_Payload: Z = -26

    val Base_TypesBoolean_Payload: Z = -25

    val Base_TypesInteger_Payload: Z = -24

    val Base_TypesInteger_8_Payload: Z = -23

    val Base_TypesInteger_16_Payload: Z = -22

    val Base_TypesInteger_32_Payload: Z = -21

    val Base_TypesInteger_64_Payload: Z = -20

    val Base_TypesUnsigned_8_Payload: Z = -19

    val Base_TypesUnsigned_16_Payload: Z = -18

    val Base_TypesUnsigned_32_Payload: Z = -17

    val Base_TypesUnsigned_64_Payload: Z = -16

    val Base_TypesFloat_Payload: Z = -15

    val Base_TypesFloat_32_Payload: Z = -14

    val Base_TypesFloat_64_Payload: Z = -13

    val Base_TypesCharacter_Payload: Z = -12

    val Base_TypesString_Payload: Z = -11

    val Base_TypesBits_Payload: Z = -10

    val _artEmpty: Z = -9

  }

  object Writer {

    @record class Default(val writer: MessagePack.Writer.Impl) extends Writer

  }

  @msig trait Writer {

    def writer: MessagePack.Writer

    def writeBuildingControlTempUnitType(o: BuildingControl.TempUnit.Type): Unit = {
      writer.writeZ(o.ordinal)
    }

    def writeBuildingControlTempUnit_Payload(o: BuildingControl.TempUnit_Payload): Unit = {
      writer.writeZ(Constants.BuildingControlTempUnit_Payload)
      writeBuildingControlTempUnitType(o.value)
    }

    def writeBuildingControlTemperature_impl(o: BuildingControl.Temperature_impl): Unit = {
      writer.writeZ(Constants.BuildingControlTemperature_impl)
      writer.writeF32(o.degrees)
      writeBuildingControlTempUnitType(o.unit)
    }

    def writeBuildingControlTemperature_impl_Payload(o: BuildingControl.Temperature_impl_Payload): Unit = {
      writer.writeZ(Constants.BuildingControlTemperature_impl_Payload)
      writeBuildingControlTemperature_impl(o.value)
    }

    def writeBuildingControlFanAckType(o: BuildingControl.FanAck.Type): Unit = {
      writer.writeZ(o.ordinal)
    }

    def writeBuildingControlFanAck_Payload(o: BuildingControl.FanAck_Payload): Unit = {
      writer.writeZ(Constants.BuildingControlFanAck_Payload)
      writeBuildingControlFanAckType(o.value)
    }

    def writeBuildingControlSetPoint_impl(o: BuildingControl.SetPoint_impl): Unit = {
      writer.writeZ(Constants.BuildingControlSetPoint_impl)
      writeBuildingControlTemperature_impl(o.low)
      writeBuildingControlTemperature_impl(o.high)
    }

    def writeBuildingControlSetPoint_impl_Payload(o: BuildingControl.SetPoint_impl_Payload): Unit = {
      writer.writeZ(Constants.BuildingControlSetPoint_impl_Payload)
      writeBuildingControlSetPoint_impl(o.value)
    }

    def writeBuildingControlFanCmdType(o: BuildingControl.FanCmd.Type): Unit = {
      writer.writeZ(o.ordinal)
    }

    def writeBuildingControlFanCmd_Payload(o: BuildingControl.FanCmd_Payload): Unit = {
      writer.writeZ(Constants.BuildingControlFanCmd_Payload)
      writeBuildingControlFanCmdType(o.value)
    }

    def writeBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesBoolean_Payload)
      writer.writeB(o.value)
    }

    def writeBase_TypesInteger_Payload(o: Base_Types.Integer_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_Payload)
      writer.writeZ(o.value)
    }

    def writeBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_8_Payload)
      writer.writeS8(o.value)
    }

    def writeBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_16_Payload)
      writer.writeS16(o.value)
    }

    def writeBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_32_Payload)
      writer.writeS32(o.value)
    }

    def writeBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_64_Payload)
      writer.writeS64(o.value)
    }

    def writeBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_8_Payload)
      writer.writeU8(o.value)
    }

    def writeBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_16_Payload)
      writer.writeU16(o.value)
    }

    def writeBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_32_Payload)
      writer.writeU32(o.value)
    }

    def writeBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_64_Payload)
      writer.writeU64(o.value)
    }

    def writeBase_TypesFloat_Payload(o: Base_Types.Float_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesFloat_Payload)
      writer.writeR(o.value)
    }

    def writeBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesFloat_32_Payload)
      writer.writeF32(o.value)
    }

    def writeBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesFloat_64_Payload)
      writer.writeF64(o.value)
    }

    def writeBase_TypesCharacter_Payload(o: Base_Types.Character_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesCharacter_Payload)
      writer.writeC(o.value)
    }

    def writeBase_TypesString_Payload(o: Base_Types.String_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesString_Payload)
      writer.writeString(o.value)
    }

    def writeBase_TypesBits_Payload(o: Base_Types.Bits_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesBits_Payload)
      writer.writeISZ(o.value, writer.writeB _)
    }

    def write_artDataContent(o: art.DataContent): Unit = {
      o match {
        case o: Base_Types.Boolean_Payload => writeBase_TypesBoolean_Payload(o)
        case o: Base_Types.Integer_Payload => writeBase_TypesInteger_Payload(o)
        case o: Base_Types.Integer_8_Payload => writeBase_TypesInteger_8_Payload(o)
        case o: Base_Types.Integer_16_Payload => writeBase_TypesInteger_16_Payload(o)
        case o: Base_Types.Integer_32_Payload => writeBase_TypesInteger_32_Payload(o)
        case o: Base_Types.Integer_64_Payload => writeBase_TypesInteger_64_Payload(o)
        case o: Base_Types.Unsigned_8_Payload => writeBase_TypesUnsigned_8_Payload(o)
        case o: Base_Types.Unsigned_16_Payload => writeBase_TypesUnsigned_16_Payload(o)
        case o: Base_Types.Unsigned_32_Payload => writeBase_TypesUnsigned_32_Payload(o)
        case o: Base_Types.Unsigned_64_Payload => writeBase_TypesUnsigned_64_Payload(o)
        case o: Base_Types.Float_Payload => writeBase_TypesFloat_Payload(o)
        case o: Base_Types.Float_32_Payload => writeBase_TypesFloat_32_Payload(o)
        case o: Base_Types.Float_64_Payload => writeBase_TypesFloat_64_Payload(o)
        case o: Base_Types.Character_Payload => writeBase_TypesCharacter_Payload(o)
        case o: Base_Types.String_Payload => writeBase_TypesString_Payload(o)
        case o: Base_Types.Bits_Payload => writeBase_TypesBits_Payload(o)
        case o: art.Empty => write_artEmpty(o)
        case o: BuildingControl.FanCmd_Payload => writeBuildingControlFanCmd_Payload(o)
        case o: BuildingControl.FanAck_Payload => writeBuildingControlFanAck_Payload(o)
        case o: BuildingControl.TempUnit_Payload => writeBuildingControlTempUnit_Payload(o)
        case o: BuildingControl.SetPoint_impl_Payload => writeBuildingControlSetPoint_impl_Payload(o)
        case o: BuildingControl.Temperature_impl_Payload => writeBuildingControlTemperature_impl_Payload(o)
      }
    }

    def write_artEmpty(o: art.Empty): Unit = {
      writer.writeZ(Constants._artEmpty)
    }

    def result: ISZ[U8] = {
      return writer.result
    }

  }

  object Reader {

    @record class Default(val reader: MessagePack.Reader.Impl) extends Reader {
      def errorOpt: Option[MessagePack.ErrorMsg] = {
        return reader.errorOpt
      }
    }

  }

  @msig trait Reader {

    def reader: MessagePack.Reader

    def readBuildingControlTempUnitType(): BuildingControl.TempUnit.Type = {
      val r = reader.readZ()
      return BuildingControl.TempUnit.byOrdinal(r).get
    }

    def readBuildingControlTempUnit_Payload(): BuildingControl.TempUnit_Payload = {
      val r = readBuildingControlTempUnit_PayloadT(F)
      return r
    }

    def readBuildingControlTempUnit_PayloadT(typeParsed: B): BuildingControl.TempUnit_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.BuildingControlTempUnit_Payload)
      }
      val value = readBuildingControlTempUnitType()
      return BuildingControl.TempUnit_Payload(value)
    }

    def readBuildingControlTemperature_impl(): BuildingControl.Temperature_impl = {
      val r = readBuildingControlTemperature_implT(F)
      return r
    }

    def readBuildingControlTemperature_implT(typeParsed: B): BuildingControl.Temperature_impl = {
      if (!typeParsed) {
        reader.expectZ(Constants.BuildingControlTemperature_impl)
      }
      val degrees = reader.readF32()
      val unit = readBuildingControlTempUnitType()
      return BuildingControl.Temperature_impl(degrees, unit)
    }

    def readBuildingControlTemperature_impl_Payload(): BuildingControl.Temperature_impl_Payload = {
      val r = readBuildingControlTemperature_impl_PayloadT(F)
      return r
    }

    def readBuildingControlTemperature_impl_PayloadT(typeParsed: B): BuildingControl.Temperature_impl_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.BuildingControlTemperature_impl_Payload)
      }
      val value = readBuildingControlTemperature_impl()
      return BuildingControl.Temperature_impl_Payload(value)
    }

    def readBuildingControlFanAckType(): BuildingControl.FanAck.Type = {
      val r = reader.readZ()
      return BuildingControl.FanAck.byOrdinal(r).get
    }

    def readBuildingControlFanAck_Payload(): BuildingControl.FanAck_Payload = {
      val r = readBuildingControlFanAck_PayloadT(F)
      return r
    }

    def readBuildingControlFanAck_PayloadT(typeParsed: B): BuildingControl.FanAck_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.BuildingControlFanAck_Payload)
      }
      val value = readBuildingControlFanAckType()
      return BuildingControl.FanAck_Payload(value)
    }

    def readBuildingControlSetPoint_impl(): BuildingControl.SetPoint_impl = {
      val r = readBuildingControlSetPoint_implT(F)
      return r
    }

    def readBuildingControlSetPoint_implT(typeParsed: B): BuildingControl.SetPoint_impl = {
      if (!typeParsed) {
        reader.expectZ(Constants.BuildingControlSetPoint_impl)
      }
      val low = readBuildingControlTemperature_impl()
      val high = readBuildingControlTemperature_impl()
      return BuildingControl.SetPoint_impl(low, high)
    }

    def readBuildingControlSetPoint_impl_Payload(): BuildingControl.SetPoint_impl_Payload = {
      val r = readBuildingControlSetPoint_impl_PayloadT(F)
      return r
    }

    def readBuildingControlSetPoint_impl_PayloadT(typeParsed: B): BuildingControl.SetPoint_impl_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.BuildingControlSetPoint_impl_Payload)
      }
      val value = readBuildingControlSetPoint_impl()
      return BuildingControl.SetPoint_impl_Payload(value)
    }

    def readBuildingControlFanCmdType(): BuildingControl.FanCmd.Type = {
      val r = reader.readZ()
      return BuildingControl.FanCmd.byOrdinal(r).get
    }

    def readBuildingControlFanCmd_Payload(): BuildingControl.FanCmd_Payload = {
      val r = readBuildingControlFanCmd_PayloadT(F)
      return r
    }

    def readBuildingControlFanCmd_PayloadT(typeParsed: B): BuildingControl.FanCmd_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.BuildingControlFanCmd_Payload)
      }
      val value = readBuildingControlFanCmdType()
      return BuildingControl.FanCmd_Payload(value)
    }

    def readBase_TypesBoolean_Payload(): Base_Types.Boolean_Payload = {
      val r = readBase_TypesBoolean_PayloadT(F)
      return r
    }

    def readBase_TypesBoolean_PayloadT(typeParsed: B): Base_Types.Boolean_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesBoolean_Payload)
      }
      val value = reader.readB()
      return Base_Types.Boolean_Payload(value)
    }

    def readBase_TypesInteger_Payload(): Base_Types.Integer_Payload = {
      val r = readBase_TypesInteger_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_PayloadT(typeParsed: B): Base_Types.Integer_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_Payload)
      }
      val value = reader.readZ()
      return Base_Types.Integer_Payload(value)
    }

    def readBase_TypesInteger_8_Payload(): Base_Types.Integer_8_Payload = {
      val r = readBase_TypesInteger_8_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_8_PayloadT(typeParsed: B): Base_Types.Integer_8_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_8_Payload)
      }
      val value = reader.readS8()
      return Base_Types.Integer_8_Payload(value)
    }

    def readBase_TypesInteger_16_Payload(): Base_Types.Integer_16_Payload = {
      val r = readBase_TypesInteger_16_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_16_PayloadT(typeParsed: B): Base_Types.Integer_16_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_16_Payload)
      }
      val value = reader.readS16()
      return Base_Types.Integer_16_Payload(value)
    }

    def readBase_TypesInteger_32_Payload(): Base_Types.Integer_32_Payload = {
      val r = readBase_TypesInteger_32_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_32_PayloadT(typeParsed: B): Base_Types.Integer_32_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_32_Payload)
      }
      val value = reader.readS32()
      return Base_Types.Integer_32_Payload(value)
    }

    def readBase_TypesInteger_64_Payload(): Base_Types.Integer_64_Payload = {
      val r = readBase_TypesInteger_64_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_64_PayloadT(typeParsed: B): Base_Types.Integer_64_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_64_Payload)
      }
      val value = reader.readS64()
      return Base_Types.Integer_64_Payload(value)
    }

    def readBase_TypesUnsigned_8_Payload(): Base_Types.Unsigned_8_Payload = {
      val r = readBase_TypesUnsigned_8_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_8_PayloadT(typeParsed: B): Base_Types.Unsigned_8_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_8_Payload)
      }
      val value = reader.readU8()
      return Base_Types.Unsigned_8_Payload(value)
    }

    def readBase_TypesUnsigned_16_Payload(): Base_Types.Unsigned_16_Payload = {
      val r = readBase_TypesUnsigned_16_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_16_PayloadT(typeParsed: B): Base_Types.Unsigned_16_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_16_Payload)
      }
      val value = reader.readU16()
      return Base_Types.Unsigned_16_Payload(value)
    }

    def readBase_TypesUnsigned_32_Payload(): Base_Types.Unsigned_32_Payload = {
      val r = readBase_TypesUnsigned_32_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_32_PayloadT(typeParsed: B): Base_Types.Unsigned_32_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_32_Payload)
      }
      val value = reader.readU32()
      return Base_Types.Unsigned_32_Payload(value)
    }

    def readBase_TypesUnsigned_64_Payload(): Base_Types.Unsigned_64_Payload = {
      val r = readBase_TypesUnsigned_64_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_64_PayloadT(typeParsed: B): Base_Types.Unsigned_64_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_64_Payload)
      }
      val value = reader.readU64()
      return Base_Types.Unsigned_64_Payload(value)
    }

    def readBase_TypesFloat_Payload(): Base_Types.Float_Payload = {
      val r = readBase_TypesFloat_PayloadT(F)
      return r
    }

    def readBase_TypesFloat_PayloadT(typeParsed: B): Base_Types.Float_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesFloat_Payload)
      }
      val value = reader.readR()
      return Base_Types.Float_Payload(value)
    }

    def readBase_TypesFloat_32_Payload(): Base_Types.Float_32_Payload = {
      val r = readBase_TypesFloat_32_PayloadT(F)
      return r
    }

    def readBase_TypesFloat_32_PayloadT(typeParsed: B): Base_Types.Float_32_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesFloat_32_Payload)
      }
      val value = reader.readF32()
      return Base_Types.Float_32_Payload(value)
    }

    def readBase_TypesFloat_64_Payload(): Base_Types.Float_64_Payload = {
      val r = readBase_TypesFloat_64_PayloadT(F)
      return r
    }

    def readBase_TypesFloat_64_PayloadT(typeParsed: B): Base_Types.Float_64_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesFloat_64_Payload)
      }
      val value = reader.readF64()
      return Base_Types.Float_64_Payload(value)
    }

    def readBase_TypesCharacter_Payload(): Base_Types.Character_Payload = {
      val r = readBase_TypesCharacter_PayloadT(F)
      return r
    }

    def readBase_TypesCharacter_PayloadT(typeParsed: B): Base_Types.Character_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesCharacter_Payload)
      }
      val value = reader.readC()
      return Base_Types.Character_Payload(value)
    }

    def readBase_TypesString_Payload(): Base_Types.String_Payload = {
      val r = readBase_TypesString_PayloadT(F)
      return r
    }

    def readBase_TypesString_PayloadT(typeParsed: B): Base_Types.String_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesString_Payload)
      }
      val value = reader.readString()
      return Base_Types.String_Payload(value)
    }

    def readBase_TypesBits_Payload(): Base_Types.Bits_Payload = {
      val r = readBase_TypesBits_PayloadT(F)
      return r
    }

    def readBase_TypesBits_PayloadT(typeParsed: B): Base_Types.Bits_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesBits_Payload)
      }
      val value = reader.readISZ(reader.readB _)
      return Base_Types.Bits_Payload(value)
    }

    def read_artDataContent(): art.DataContent = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.Base_TypesBoolean_Payload => val r = readBase_TypesBoolean_PayloadT(T); return r
        case Constants.Base_TypesInteger_Payload => val r = readBase_TypesInteger_PayloadT(T); return r
        case Constants.Base_TypesInteger_8_Payload => val r = readBase_TypesInteger_8_PayloadT(T); return r
        case Constants.Base_TypesInteger_16_Payload => val r = readBase_TypesInteger_16_PayloadT(T); return r
        case Constants.Base_TypesInteger_32_Payload => val r = readBase_TypesInteger_32_PayloadT(T); return r
        case Constants.Base_TypesInteger_64_Payload => val r = readBase_TypesInteger_64_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_8_Payload => val r = readBase_TypesUnsigned_8_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_16_Payload => val r = readBase_TypesUnsigned_16_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_32_Payload => val r = readBase_TypesUnsigned_32_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_64_Payload => val r = readBase_TypesUnsigned_64_PayloadT(T); return r
        case Constants.Base_TypesFloat_Payload => val r = readBase_TypesFloat_PayloadT(T); return r
        case Constants.Base_TypesFloat_32_Payload => val r = readBase_TypesFloat_32_PayloadT(T); return r
        case Constants.Base_TypesFloat_64_Payload => val r = readBase_TypesFloat_64_PayloadT(T); return r
        case Constants.Base_TypesCharacter_Payload => val r = readBase_TypesCharacter_PayloadT(T); return r
        case Constants.Base_TypesString_Payload => val r = readBase_TypesString_PayloadT(T); return r
        case Constants.Base_TypesBits_Payload => val r = readBase_TypesBits_PayloadT(T); return r
        case Constants._artEmpty => val r = read_artEmptyT(T); return r
        case Constants.BuildingControlFanCmd_Payload => val r = readBuildingControlFanCmd_PayloadT(T); return r
        case Constants.BuildingControlFanAck_Payload => val r = readBuildingControlFanAck_PayloadT(T); return r
        case Constants.BuildingControlTempUnit_Payload => val r = readBuildingControlTempUnit_PayloadT(T); return r
        case Constants.BuildingControlSetPoint_impl_Payload => val r = readBuildingControlSetPoint_impl_PayloadT(T); return r
        case Constants.BuildingControlTemperature_impl_Payload => val r = readBuildingControlTemperature_impl_PayloadT(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of art.DataContent.")
          val r = readBuildingControlTemperature_impl_PayloadT(T)
          return r
      }
    }

    def read_artEmpty(): art.Empty = {
      val r = read_artEmptyT(F)
      return r
    }

    def read_artEmptyT(typeParsed: B): art.Empty = {
      if (!typeParsed) {
        reader.expectZ(Constants._artEmpty)
      }
      return art.Empty()
    }

  }

  def to[T](data: ISZ[U8], f: Reader => T): Either[T, MessagePack.ErrorMsg] = {
    val rd = Reader.Default(MessagePack.reader(data))
    rd.reader.init()
    val r = f(rd)
    rd.errorOpt match {
      case Some(e) => return Either.Right(e)
      case _ => return Either.Left(r)
    }
  }

  def fromBuildingControlTempUnit_Payload(o: BuildingControl.TempUnit_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBuildingControlTempUnit_Payload(o)
    return w.result
  }

  def toBuildingControlTempUnit_Payload(data: ISZ[U8]): Either[BuildingControl.TempUnit_Payload, MessagePack.ErrorMsg] = {
    def fBuildingControlTempUnit_Payload(reader: Reader): BuildingControl.TempUnit_Payload = {
      val r = reader.readBuildingControlTempUnit_Payload()
      return r
    }
    val r = to(data, fBuildingControlTempUnit_Payload _)
    return r
  }

  def fromBuildingControlTemperature_impl(o: BuildingControl.Temperature_impl, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBuildingControlTemperature_impl(o)
    return w.result
  }

  def toBuildingControlTemperature_impl(data: ISZ[U8]): Either[BuildingControl.Temperature_impl, MessagePack.ErrorMsg] = {
    def fBuildingControlTemperature_impl(reader: Reader): BuildingControl.Temperature_impl = {
      val r = reader.readBuildingControlTemperature_impl()
      return r
    }
    val r = to(data, fBuildingControlTemperature_impl _)
    return r
  }

  def fromBuildingControlTemperature_impl_Payload(o: BuildingControl.Temperature_impl_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBuildingControlTemperature_impl_Payload(o)
    return w.result
  }

  def toBuildingControlTemperature_impl_Payload(data: ISZ[U8]): Either[BuildingControl.Temperature_impl_Payload, MessagePack.ErrorMsg] = {
    def fBuildingControlTemperature_impl_Payload(reader: Reader): BuildingControl.Temperature_impl_Payload = {
      val r = reader.readBuildingControlTemperature_impl_Payload()
      return r
    }
    val r = to(data, fBuildingControlTemperature_impl_Payload _)
    return r
  }

  def fromBuildingControlFanAck_Payload(o: BuildingControl.FanAck_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBuildingControlFanAck_Payload(o)
    return w.result
  }

  def toBuildingControlFanAck_Payload(data: ISZ[U8]): Either[BuildingControl.FanAck_Payload, MessagePack.ErrorMsg] = {
    def fBuildingControlFanAck_Payload(reader: Reader): BuildingControl.FanAck_Payload = {
      val r = reader.readBuildingControlFanAck_Payload()
      return r
    }
    val r = to(data, fBuildingControlFanAck_Payload _)
    return r
  }

  def fromBuildingControlSetPoint_impl(o: BuildingControl.SetPoint_impl, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBuildingControlSetPoint_impl(o)
    return w.result
  }

  def toBuildingControlSetPoint_impl(data: ISZ[U8]): Either[BuildingControl.SetPoint_impl, MessagePack.ErrorMsg] = {
    def fBuildingControlSetPoint_impl(reader: Reader): BuildingControl.SetPoint_impl = {
      val r = reader.readBuildingControlSetPoint_impl()
      return r
    }
    val r = to(data, fBuildingControlSetPoint_impl _)
    return r
  }

  def fromBuildingControlSetPoint_impl_Payload(o: BuildingControl.SetPoint_impl_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBuildingControlSetPoint_impl_Payload(o)
    return w.result
  }

  def toBuildingControlSetPoint_impl_Payload(data: ISZ[U8]): Either[BuildingControl.SetPoint_impl_Payload, MessagePack.ErrorMsg] = {
    def fBuildingControlSetPoint_impl_Payload(reader: Reader): BuildingControl.SetPoint_impl_Payload = {
      val r = reader.readBuildingControlSetPoint_impl_Payload()
      return r
    }
    val r = to(data, fBuildingControlSetPoint_impl_Payload _)
    return r
  }

  def fromBuildingControlFanCmd_Payload(o: BuildingControl.FanCmd_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBuildingControlFanCmd_Payload(o)
    return w.result
  }

  def toBuildingControlFanCmd_Payload(data: ISZ[U8]): Either[BuildingControl.FanCmd_Payload, MessagePack.ErrorMsg] = {
    def fBuildingControlFanCmd_Payload(reader: Reader): BuildingControl.FanCmd_Payload = {
      val r = reader.readBuildingControlFanCmd_Payload()
      return r
    }
    val r = to(data, fBuildingControlFanCmd_Payload _)
    return r
  }

  def fromBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesBoolean_Payload(o)
    return w.result
  }

  def toBase_TypesBoolean_Payload(data: ISZ[U8]): Either[Base_Types.Boolean_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesBoolean_Payload(reader: Reader): Base_Types.Boolean_Payload = {
      val r = reader.readBase_TypesBoolean_Payload()
      return r
    }
    val r = to(data, fBase_TypesBoolean_Payload _)
    return r
  }

  def fromBase_TypesInteger_Payload(o: Base_Types.Integer_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_Payload(data: ISZ[U8]): Either[Base_Types.Integer_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_Payload(reader: Reader): Base_Types.Integer_Payload = {
      val r = reader.readBase_TypesInteger_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_Payload _)
    return r
  }

  def fromBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_8_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_8_Payload(data: ISZ[U8]): Either[Base_Types.Integer_8_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_8_Payload(reader: Reader): Base_Types.Integer_8_Payload = {
      val r = reader.readBase_TypesInteger_8_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_8_Payload _)
    return r
  }

  def fromBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_16_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_16_Payload(data: ISZ[U8]): Either[Base_Types.Integer_16_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_16_Payload(reader: Reader): Base_Types.Integer_16_Payload = {
      val r = reader.readBase_TypesInteger_16_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_16_Payload _)
    return r
  }

  def fromBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_32_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_32_Payload(data: ISZ[U8]): Either[Base_Types.Integer_32_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_32_Payload(reader: Reader): Base_Types.Integer_32_Payload = {
      val r = reader.readBase_TypesInteger_32_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_32_Payload _)
    return r
  }

  def fromBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_64_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_64_Payload(data: ISZ[U8]): Either[Base_Types.Integer_64_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_64_Payload(reader: Reader): Base_Types.Integer_64_Payload = {
      val r = reader.readBase_TypesInteger_64_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_64_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_8_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_8_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_8_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_8_Payload(reader: Reader): Base_Types.Unsigned_8_Payload = {
      val r = reader.readBase_TypesUnsigned_8_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_8_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_16_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_16_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_16_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_16_Payload(reader: Reader): Base_Types.Unsigned_16_Payload = {
      val r = reader.readBase_TypesUnsigned_16_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_16_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_32_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_32_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_32_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_32_Payload(reader: Reader): Base_Types.Unsigned_32_Payload = {
      val r = reader.readBase_TypesUnsigned_32_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_32_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_64_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_64_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_64_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_64_Payload(reader: Reader): Base_Types.Unsigned_64_Payload = {
      val r = reader.readBase_TypesUnsigned_64_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_64_Payload _)
    return r
  }

  def fromBase_TypesFloat_Payload(o: Base_Types.Float_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesFloat_Payload(o)
    return w.result
  }

  def toBase_TypesFloat_Payload(data: ISZ[U8]): Either[Base_Types.Float_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesFloat_Payload(reader: Reader): Base_Types.Float_Payload = {
      val r = reader.readBase_TypesFloat_Payload()
      return r
    }
    val r = to(data, fBase_TypesFloat_Payload _)
    return r
  }

  def fromBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesFloat_32_Payload(o)
    return w.result
  }

  def toBase_TypesFloat_32_Payload(data: ISZ[U8]): Either[Base_Types.Float_32_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesFloat_32_Payload(reader: Reader): Base_Types.Float_32_Payload = {
      val r = reader.readBase_TypesFloat_32_Payload()
      return r
    }
    val r = to(data, fBase_TypesFloat_32_Payload _)
    return r
  }

  def fromBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesFloat_64_Payload(o)
    return w.result
  }

  def toBase_TypesFloat_64_Payload(data: ISZ[U8]): Either[Base_Types.Float_64_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesFloat_64_Payload(reader: Reader): Base_Types.Float_64_Payload = {
      val r = reader.readBase_TypesFloat_64_Payload()
      return r
    }
    val r = to(data, fBase_TypesFloat_64_Payload _)
    return r
  }

  def fromBase_TypesCharacter_Payload(o: Base_Types.Character_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesCharacter_Payload(o)
    return w.result
  }

  def toBase_TypesCharacter_Payload(data: ISZ[U8]): Either[Base_Types.Character_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesCharacter_Payload(reader: Reader): Base_Types.Character_Payload = {
      val r = reader.readBase_TypesCharacter_Payload()
      return r
    }
    val r = to(data, fBase_TypesCharacter_Payload _)
    return r
  }

  def fromBase_TypesString_Payload(o: Base_Types.String_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesString_Payload(o)
    return w.result
  }

  def toBase_TypesString_Payload(data: ISZ[U8]): Either[Base_Types.String_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesString_Payload(reader: Reader): Base_Types.String_Payload = {
      val r = reader.readBase_TypesString_Payload()
      return r
    }
    val r = to(data, fBase_TypesString_Payload _)
    return r
  }

  def fromBase_TypesBits_Payload(o: Base_Types.Bits_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesBits_Payload(o)
    return w.result
  }

  def toBase_TypesBits_Payload(data: ISZ[U8]): Either[Base_Types.Bits_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesBits_Payload(reader: Reader): Base_Types.Bits_Payload = {
      val r = reader.readBase_TypesBits_Payload()
      return r
    }
    val r = to(data, fBase_TypesBits_Payload _)
    return r
  }

  def from_artDataContent(o: art.DataContent, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.write_artDataContent(o)
    return w.result
  }

  def to_artDataContent(data: ISZ[U8]): Either[art.DataContent, MessagePack.ErrorMsg] = {
    def f_artDataContent(reader: Reader): art.DataContent = {
      val r = reader.read_artDataContent()
      return r
    }
    val r = to(data, f_artDataContent _)
    return r
  }

  def from_artEmpty(o: art.Empty, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.write_artEmpty(o)
    return w.result
  }

  def to_artEmpty(data: ISZ[U8]): Either[art.Empty, MessagePack.ErrorMsg] = {
    def f_artEmpty(reader: Reader): art.Empty = {
      val r = reader.read_artEmpty()
      return r
    }
    val r = to(data, f_artEmpty _)
    return r
  }

}