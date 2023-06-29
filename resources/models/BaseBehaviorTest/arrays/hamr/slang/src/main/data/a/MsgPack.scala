// #Sireum
// @formatter:off

// This file is auto-generated from Coordinate_Impl.scala, Array_of_Coordinates.scala, Vector_of_Coordinates.scala, Array_of_Integers.scala, Base_Types.scala, DataContent.scala

package a

import org.sireum._

object MsgPack {

  object Constants {

    val ArraysCoordinate_Impl: Z = -32

    val ArraysCoordinate_Impl_Payload: Z = -31

    val ArraysArray_of_Coordinates: Z = -30

    val ArraysArray_of_Coordinates_Payload: Z = -29

    val ArraysVector_of_Coordinates: Z = -28

    val ArraysVector_of_Coordinates_Payload: Z = -27

    val ArraysArray_of_Integers: Z = -26

    val ArraysArray_of_Integers_Payload: Z = -25

    val Base_TypesBoolean_Payload: Z = -24

    val Base_TypesInteger_Payload: Z = -23

    val Base_TypesInteger_8_Payload: Z = -22

    val Base_TypesInteger_16_Payload: Z = -21

    val Base_TypesInteger_32_Payload: Z = -20

    val Base_TypesInteger_64_Payload: Z = -19

    val Base_TypesUnsigned_8_Payload: Z = -18

    val Base_TypesUnsigned_16_Payload: Z = -17

    val Base_TypesUnsigned_32_Payload: Z = -16

    val Base_TypesUnsigned_64_Payload: Z = -15

    val Base_TypesFloat_Payload: Z = -14

    val Base_TypesFloat_32_Payload: Z = -13

    val Base_TypesFloat_64_Payload: Z = -12

    val Base_TypesCharacter_Payload: Z = -11

    val Base_TypesString_Payload: Z = -10

    val Base_TypesBits_Payload: Z = -9

    val _artEmpty: Z = -8

  }

  object Writer {

    @record class Default(val writer: MessagePack.Writer.Impl) extends Writer

  }

  @msig trait Writer {

    def writer: MessagePack.Writer

    def writeArraysCoordinate_Impl(o: Arrays.Coordinate_Impl): Unit = {
      writer.writeZ(Constants.ArraysCoordinate_Impl)
      writer.writeS32(o.latitude)
      writer.writeS32(o.longitude)
      writer.writeS32(o.altitude)
    }

    def writeArraysCoordinate_Impl_Payload(o: Arrays.Coordinate_Impl_Payload): Unit = {
      writer.writeZ(Constants.ArraysCoordinate_Impl_Payload)
      writeArraysCoordinate_Impl(o.value)
    }

    def writeArraysArray_of_CoordinatesI(o: Arrays.Array_of_Coordinates.I): Unit = {
      writer.writeZ(o.toZ)
    }

    def writeISArraysArray_of_CoordinatesI[E](s: IS[Arrays.Array_of_Coordinates.I, E], f: E => Unit) : Unit = {
      writer.writeArrayHeader(s.size)
      for (e <- s) {
        f(e)
      }
    }

    def writeArraysArray_of_Coordinates(o: Arrays.Array_of_Coordinates): Unit = {
      writer.writeZ(Constants.ArraysArray_of_Coordinates)
      writeISArraysArray_of_CoordinatesI(o.value, writeArraysCoordinate_Impl _)
    }

    def writeArraysArray_of_Coordinates_Payload(o: Arrays.Array_of_Coordinates_Payload): Unit = {
      writer.writeZ(Constants.ArraysArray_of_Coordinates_Payload)
      writeArraysArray_of_Coordinates(o.value)
    }

    def writeArraysVector_of_Coordinates(o: Arrays.Vector_of_Coordinates): Unit = {
      writer.writeZ(Constants.ArraysVector_of_Coordinates)
      writer.writeISZ(o.value, writer.writeZ _)
    }

    def writeArraysVector_of_Coordinates_Payload(o: Arrays.Vector_of_Coordinates_Payload): Unit = {
      writer.writeZ(Constants.ArraysVector_of_Coordinates_Payload)
      writeArraysVector_of_Coordinates(o.value)
    }

    def writeArraysArray_of_IntegersI(o: Arrays.Array_of_Integers.I): Unit = {
      writer.writeZ(o.toZ)
    }

    def writeISArraysArray_of_IntegersI[E](s: IS[Arrays.Array_of_Integers.I, E], f: E => Unit) : Unit = {
      writer.writeArrayHeader(s.size)
      for (e <- s) {
        f(e)
      }
    }

    def writeArraysArray_of_Integers(o: Arrays.Array_of_Integers): Unit = {
      writer.writeZ(Constants.ArraysArray_of_Integers)
      writeISArraysArray_of_IntegersI(o.value, writer.writeZ _)
    }

    def writeArraysArray_of_Integers_Payload(o: Arrays.Array_of_Integers_Payload): Unit = {
      writer.writeZ(Constants.ArraysArray_of_Integers_Payload)
      writeArraysArray_of_Integers(o.value)
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
        case o: Arrays.Coordinate_Impl_Payload => writeArraysCoordinate_Impl_Payload(o)
        case o: Arrays.Array_of_Integers_Payload => writeArraysArray_of_Integers_Payload(o)
        case o: Arrays.Array_of_Coordinates_Payload => writeArraysArray_of_Coordinates_Payload(o)
        case o: Arrays.Vector_of_Coordinates_Payload => writeArraysVector_of_Coordinates_Payload(o)
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

    def readArraysCoordinate_Impl(): Arrays.Coordinate_Impl = {
      val r = readArraysCoordinate_ImplT(F)
      return r
    }

    def readArraysCoordinate_ImplT(typeParsed: B): Arrays.Coordinate_Impl = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysCoordinate_Impl)
      }
      val latitude = reader.readS32()
      val longitude = reader.readS32()
      val altitude = reader.readS32()
      return Arrays.Coordinate_Impl(latitude, longitude, altitude)
    }

    def readArraysCoordinate_Impl_Payload(): Arrays.Coordinate_Impl_Payload = {
      val r = readArraysCoordinate_Impl_PayloadT(F)
      return r
    }

    def readArraysCoordinate_Impl_PayloadT(typeParsed: B): Arrays.Coordinate_Impl_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysCoordinate_Impl_Payload)
      }
      val value = readArraysCoordinate_Impl()
      return Arrays.Coordinate_Impl_Payload(value)
    }

    def readArraysArray_of_CoordinatesI(): Arrays.Array_of_Coordinates.I = {
      val n = reader.readZ()
      return Arrays.Array_of_Coordinates.I.fromZ(n)
    }

    def readISArraysArray_of_CoordinatesI[E](f: () => E): IS[Arrays.Array_of_Coordinates.I, E] = {
      val size = reader.readArrayHeader()
      var r = IS[Arrays.Array_of_Coordinates.I, E]()
      var i = 0
      while (i < size) {
        val o = f()
        r = r :+ o
        i = i + 1
      }
      return r
    }

    def readArraysArray_of_Coordinates(): Arrays.Array_of_Coordinates = {
      val r = readArraysArray_of_CoordinatesT(F)
      return r
    }

    def readArraysArray_of_CoordinatesT(typeParsed: B): Arrays.Array_of_Coordinates = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysArray_of_Coordinates)
      }
      val value = readISArraysArray_of_CoordinatesI(readArraysCoordinate_Impl _)
      return Arrays.Array_of_Coordinates(value)
    }

    def readArraysArray_of_Coordinates_Payload(): Arrays.Array_of_Coordinates_Payload = {
      val r = readArraysArray_of_Coordinates_PayloadT(F)
      return r
    }

    def readArraysArray_of_Coordinates_PayloadT(typeParsed: B): Arrays.Array_of_Coordinates_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysArray_of_Coordinates_Payload)
      }
      val value = readArraysArray_of_Coordinates()
      return Arrays.Array_of_Coordinates_Payload(value)
    }

    def readArraysVector_of_Coordinates(): Arrays.Vector_of_Coordinates = {
      val r = readArraysVector_of_CoordinatesT(F)
      return r
    }

    def readArraysVector_of_CoordinatesT(typeParsed: B): Arrays.Vector_of_Coordinates = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysVector_of_Coordinates)
      }
      val value = reader.readISZ(reader.readZ _)
      return Arrays.Vector_of_Coordinates(value)
    }

    def readArraysVector_of_Coordinates_Payload(): Arrays.Vector_of_Coordinates_Payload = {
      val r = readArraysVector_of_Coordinates_PayloadT(F)
      return r
    }

    def readArraysVector_of_Coordinates_PayloadT(typeParsed: B): Arrays.Vector_of_Coordinates_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysVector_of_Coordinates_Payload)
      }
      val value = readArraysVector_of_Coordinates()
      return Arrays.Vector_of_Coordinates_Payload(value)
    }

    def readArraysArray_of_IntegersI(): Arrays.Array_of_Integers.I = {
      val n = reader.readZ()
      return Arrays.Array_of_Integers.I.fromZ(n)
    }

    def readISArraysArray_of_IntegersI[E](f: () => E): IS[Arrays.Array_of_Integers.I, E] = {
      val size = reader.readArrayHeader()
      var r = IS[Arrays.Array_of_Integers.I, E]()
      var i = 0
      while (i < size) {
        val o = f()
        r = r :+ o
        i = i + 1
      }
      return r
    }

    def readArraysArray_of_Integers(): Arrays.Array_of_Integers = {
      val r = readArraysArray_of_IntegersT(F)
      return r
    }

    def readArraysArray_of_IntegersT(typeParsed: B): Arrays.Array_of_Integers = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysArray_of_Integers)
      }
      val value = readISArraysArray_of_IntegersI(reader.readZ _)
      return Arrays.Array_of_Integers(value)
    }

    def readArraysArray_of_Integers_Payload(): Arrays.Array_of_Integers_Payload = {
      val r = readArraysArray_of_Integers_PayloadT(F)
      return r
    }

    def readArraysArray_of_Integers_PayloadT(typeParsed: B): Arrays.Array_of_Integers_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.ArraysArray_of_Integers_Payload)
      }
      val value = readArraysArray_of_Integers()
      return Arrays.Array_of_Integers_Payload(value)
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
        case Constants.ArraysCoordinate_Impl_Payload => val r = readArraysCoordinate_Impl_PayloadT(T); return r
        case Constants.ArraysArray_of_Integers_Payload => val r = readArraysArray_of_Integers_PayloadT(T); return r
        case Constants.ArraysArray_of_Coordinates_Payload => val r = readArraysArray_of_Coordinates_PayloadT(T); return r
        case Constants.ArraysVector_of_Coordinates_Payload => val r = readArraysVector_of_Coordinates_PayloadT(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of art.DataContent.")
          val r = readArraysVector_of_Coordinates_PayloadT(T)
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

  def fromArraysCoordinate_Impl(o: Arrays.Coordinate_Impl, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysCoordinate_Impl(o)
    return w.result
  }

  def toArraysCoordinate_Impl(data: ISZ[U8]): Either[Arrays.Coordinate_Impl, MessagePack.ErrorMsg] = {
    def fArraysCoordinate_Impl(reader: Reader): Arrays.Coordinate_Impl = {
      val r = reader.readArraysCoordinate_Impl()
      return r
    }
    val r = to(data, fArraysCoordinate_Impl _)
    return r
  }

  def fromArraysCoordinate_Impl_Payload(o: Arrays.Coordinate_Impl_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysCoordinate_Impl_Payload(o)
    return w.result
  }

  def toArraysCoordinate_Impl_Payload(data: ISZ[U8]): Either[Arrays.Coordinate_Impl_Payload, MessagePack.ErrorMsg] = {
    def fArraysCoordinate_Impl_Payload(reader: Reader): Arrays.Coordinate_Impl_Payload = {
      val r = reader.readArraysCoordinate_Impl_Payload()
      return r
    }
    val r = to(data, fArraysCoordinate_Impl_Payload _)
    return r
  }

  def fromArraysArray_of_Coordinates(o: Arrays.Array_of_Coordinates, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysArray_of_Coordinates(o)
    return w.result
  }

  def toArraysArray_of_Coordinates(data: ISZ[U8]): Either[Arrays.Array_of_Coordinates, MessagePack.ErrorMsg] = {
    def fArraysArray_of_Coordinates(reader: Reader): Arrays.Array_of_Coordinates = {
      val r = reader.readArraysArray_of_Coordinates()
      return r
    }
    val r = to(data, fArraysArray_of_Coordinates _)
    return r
  }

  def fromArraysArray_of_Coordinates_Payload(o: Arrays.Array_of_Coordinates_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysArray_of_Coordinates_Payload(o)
    return w.result
  }

  def toArraysArray_of_Coordinates_Payload(data: ISZ[U8]): Either[Arrays.Array_of_Coordinates_Payload, MessagePack.ErrorMsg] = {
    def fArraysArray_of_Coordinates_Payload(reader: Reader): Arrays.Array_of_Coordinates_Payload = {
      val r = reader.readArraysArray_of_Coordinates_Payload()
      return r
    }
    val r = to(data, fArraysArray_of_Coordinates_Payload _)
    return r
  }

  def fromArraysVector_of_Coordinates(o: Arrays.Vector_of_Coordinates, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysVector_of_Coordinates(o)
    return w.result
  }

  def toArraysVector_of_Coordinates(data: ISZ[U8]): Either[Arrays.Vector_of_Coordinates, MessagePack.ErrorMsg] = {
    def fArraysVector_of_Coordinates(reader: Reader): Arrays.Vector_of_Coordinates = {
      val r = reader.readArraysVector_of_Coordinates()
      return r
    }
    val r = to(data, fArraysVector_of_Coordinates _)
    return r
  }

  def fromArraysVector_of_Coordinates_Payload(o: Arrays.Vector_of_Coordinates_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysVector_of_Coordinates_Payload(o)
    return w.result
  }

  def toArraysVector_of_Coordinates_Payload(data: ISZ[U8]): Either[Arrays.Vector_of_Coordinates_Payload, MessagePack.ErrorMsg] = {
    def fArraysVector_of_Coordinates_Payload(reader: Reader): Arrays.Vector_of_Coordinates_Payload = {
      val r = reader.readArraysVector_of_Coordinates_Payload()
      return r
    }
    val r = to(data, fArraysVector_of_Coordinates_Payload _)
    return r
  }

  def fromArraysArray_of_Integers(o: Arrays.Array_of_Integers, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysArray_of_Integers(o)
    return w.result
  }

  def toArraysArray_of_Integers(data: ISZ[U8]): Either[Arrays.Array_of_Integers, MessagePack.ErrorMsg] = {
    def fArraysArray_of_Integers(reader: Reader): Arrays.Array_of_Integers = {
      val r = reader.readArraysArray_of_Integers()
      return r
    }
    val r = to(data, fArraysArray_of_Integers _)
    return r
  }

  def fromArraysArray_of_Integers_Payload(o: Arrays.Array_of_Integers_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeArraysArray_of_Integers_Payload(o)
    return w.result
  }

  def toArraysArray_of_Integers_Payload(data: ISZ[U8]): Either[Arrays.Array_of_Integers_Payload, MessagePack.ErrorMsg] = {
    def fArraysArray_of_Integers_Payload(reader: Reader): Arrays.Array_of_Integers_Payload = {
      val r = reader.readArraysArray_of_Integers_Payload()
      return r
    }
    val r = to(data, fArraysArray_of_Integers_Payload _)
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