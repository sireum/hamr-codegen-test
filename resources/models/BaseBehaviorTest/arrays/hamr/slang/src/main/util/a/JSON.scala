// #Sireum
// @formatter:off

// This file is auto-generated from Coordinate_Impl.scala, Array_of_Coordinates.scala, Vector_of_Coordinates.scala, Array_of_Integers.scala, Base_Types.scala, DataContent.scala, Aux_Types.scala

package a

import org.sireum._
import org.sireum.Json.Printer._

object JSON {

  object Printer {

    @pure def printArraysCoordinate_Impl(o: Arrays.Coordinate_Impl): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Coordinate_Impl""""),
        ("latitude", printS32(o.latitude)),
        ("longitude", printS32(o.longitude)),
        ("altitude", printS32(o.altitude))
      ))
    }

    @pure def printArraysCoordinate_Impl_Payload(o: Arrays.Coordinate_Impl_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Coordinate_Impl_Payload""""),
        ("value", printArraysCoordinate_Impl(o.value))
      ))
    }

    @pure def printArraysArray_of_CoordinatesI(o: Arrays.Array_of_Coordinates.I): ST = {
      return printNumber(o.toZ.string)
    }

    @pure def printArraysArray_of_Coordinates(o: Arrays.Array_of_Coordinates): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Array_of_Coordinates""""),
        ("value", printIS(F, o.value.map(printArraysCoordinate_Impl _)))
      ))
    }

    @pure def printArraysArray_of_Coordinates_Payload(o: Arrays.Array_of_Coordinates_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Array_of_Coordinates_Payload""""),
        ("value", printArraysArray_of_Coordinates(o.value))
      ))
    }

    @pure def printArraysVector_of_Coordinates(o: Arrays.Vector_of_Coordinates): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Vector_of_Coordinates""""),
        ("value", printISZ(T, o.value, printZ _))
      ))
    }

    @pure def printArraysVector_of_Coordinates_Payload(o: Arrays.Vector_of_Coordinates_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Vector_of_Coordinates_Payload""""),
        ("value", printArraysVector_of_Coordinates(o.value))
      ))
    }

    @pure def printArraysArray_of_IntegersI(o: Arrays.Array_of_Integers.I): ST = {
      return printNumber(o.toZ.string)
    }

    @pure def printArraysArray_of_Integers(o: Arrays.Array_of_Integers): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Array_of_Integers""""),
        ("value", printIS(T, o.value.map(printZ _)))
      ))
    }

    @pure def printArraysArray_of_Integers_Payload(o: Arrays.Array_of_Integers_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Arrays.Array_of_Integers_Payload""""),
        ("value", printArraysArray_of_Integers(o.value))
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
        case o: Arrays.Coordinate_Impl_Payload => return printArraysCoordinate_Impl_Payload(o)
        case o: Arrays.Array_of_Integers_Payload => return printArraysArray_of_Integers_Payload(o)
        case o: Arrays.Array_of_Coordinates_Payload => return printArraysArray_of_Coordinates_Payload(o)
        case o: Arrays.Vector_of_Coordinates_Payload => return printArraysVector_of_Coordinates_Payload(o)
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

    def parseArraysCoordinate_Impl(): Arrays.Coordinate_Impl = {
      val r = parseArraysCoordinate_ImplT(F)
      return r
    }

    def parseArraysCoordinate_ImplT(typeParsed: B): Arrays.Coordinate_Impl = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Coordinate_Impl")
      }
      parser.parseObjectKey("latitude")
      val latitude = parser.parseS32()
      parser.parseObjectNext()
      parser.parseObjectKey("longitude")
      val longitude = parser.parseS32()
      parser.parseObjectNext()
      parser.parseObjectKey("altitude")
      val altitude = parser.parseS32()
      parser.parseObjectNext()
      return Arrays.Coordinate_Impl(latitude, longitude, altitude)
    }

    def parseArraysCoordinate_Impl_Payload(): Arrays.Coordinate_Impl_Payload = {
      val r = parseArraysCoordinate_Impl_PayloadT(F)
      return r
    }

    def parseArraysCoordinate_Impl_PayloadT(typeParsed: B): Arrays.Coordinate_Impl_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Coordinate_Impl_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseArraysCoordinate_Impl()
      parser.parseObjectNext()
      return Arrays.Coordinate_Impl_Payload(value)
    }

    def parseArraysArray_of_CoordinatesI(): Arrays.Array_of_Coordinates.I = {
      val i = parser.offset
      val s = parser.parseNumber()
      Arrays.Array_of_Coordinates.I(s) match {
        case Some(n) => return n
        case _ =>
          parser.parseException(i, s"Expected a Arrays.Array_of_Coordinates.I, but '$s' found.")
          return Arrays.Array_of_Coordinates.I.Min
      }
    }

    def parseISArraysArray_of_CoordinatesI[T](f: () => T): IS[Arrays.Array_of_Coordinates.I, T] = {
      if (!parser.parseArrayBegin()) {
        return IS()
      }
      var e = f()
      var r = IS[Arrays.Array_of_Coordinates.I, T](e)
      var continue = parser.parseArrayNext()
      while (continue) {
        e = f()
        r = r :+ e
        continue = parser.parseArrayNext()
      }
      return r
    }

    def parseArraysArray_of_Coordinates(): Arrays.Array_of_Coordinates = {
      val r = parseArraysArray_of_CoordinatesT(F)
      return r
    }

    def parseArraysArray_of_CoordinatesT(typeParsed: B): Arrays.Array_of_Coordinates = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Array_of_Coordinates")
      }
      parser.parseObjectKey("value")
      val value = parseISArraysArray_of_CoordinatesI(parseArraysCoordinate_Impl _)
      parser.parseObjectNext()
      return Arrays.Array_of_Coordinates(value)
    }

    def parseArraysArray_of_Coordinates_Payload(): Arrays.Array_of_Coordinates_Payload = {
      val r = parseArraysArray_of_Coordinates_PayloadT(F)
      return r
    }

    def parseArraysArray_of_Coordinates_PayloadT(typeParsed: B): Arrays.Array_of_Coordinates_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Array_of_Coordinates_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseArraysArray_of_Coordinates()
      parser.parseObjectNext()
      return Arrays.Array_of_Coordinates_Payload(value)
    }

    def parseArraysVector_of_Coordinates(): Arrays.Vector_of_Coordinates = {
      val r = parseArraysVector_of_CoordinatesT(F)
      return r
    }

    def parseArraysVector_of_CoordinatesT(typeParsed: B): Arrays.Vector_of_Coordinates = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Vector_of_Coordinates")
      }
      parser.parseObjectKey("value")
      val value = parser.parseISZ(parser.parseZ _)
      parser.parseObjectNext()
      return Arrays.Vector_of_Coordinates(value)
    }

    def parseArraysVector_of_Coordinates_Payload(): Arrays.Vector_of_Coordinates_Payload = {
      val r = parseArraysVector_of_Coordinates_PayloadT(F)
      return r
    }

    def parseArraysVector_of_Coordinates_PayloadT(typeParsed: B): Arrays.Vector_of_Coordinates_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Vector_of_Coordinates_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseArraysVector_of_Coordinates()
      parser.parseObjectNext()
      return Arrays.Vector_of_Coordinates_Payload(value)
    }

    def parseArraysArray_of_IntegersI(): Arrays.Array_of_Integers.I = {
      val i = parser.offset
      val s = parser.parseNumber()
      Arrays.Array_of_Integers.I(s) match {
        case Some(n) => return n
        case _ =>
          parser.parseException(i, s"Expected a Arrays.Array_of_Integers.I, but '$s' found.")
          return Arrays.Array_of_Integers.I.Min
      }
    }

    def parseISArraysArray_of_IntegersI[T](f: () => T): IS[Arrays.Array_of_Integers.I, T] = {
      if (!parser.parseArrayBegin()) {
        return IS()
      }
      var e = f()
      var r = IS[Arrays.Array_of_Integers.I, T](e)
      var continue = parser.parseArrayNext()
      while (continue) {
        e = f()
        r = r :+ e
        continue = parser.parseArrayNext()
      }
      return r
    }

    def parseArraysArray_of_Integers(): Arrays.Array_of_Integers = {
      val r = parseArraysArray_of_IntegersT(F)
      return r
    }

    def parseArraysArray_of_IntegersT(typeParsed: B): Arrays.Array_of_Integers = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Array_of_Integers")
      }
      parser.parseObjectKey("value")
      val value = parseISArraysArray_of_IntegersI(parser.parseZ _)
      parser.parseObjectNext()
      return Arrays.Array_of_Integers(value)
    }

    def parseArraysArray_of_Integers_Payload(): Arrays.Array_of_Integers_Payload = {
      val r = parseArraysArray_of_Integers_PayloadT(F)
      return r
    }

    def parseArraysArray_of_Integers_PayloadT(typeParsed: B): Arrays.Array_of_Integers_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Arrays.Array_of_Integers_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseArraysArray_of_Integers()
      parser.parseObjectNext()
      return Arrays.Array_of_Integers_Payload(value)
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
      val t = parser.parseObjectTypes(ISZ("Base_Types.Boolean_Payload", "Base_Types.Integer_Payload", "Base_Types.Integer_8_Payload", "Base_Types.Integer_16_Payload", "Base_Types.Integer_32_Payload", "Base_Types.Integer_64_Payload", "Base_Types.Unsigned_8_Payload", "Base_Types.Unsigned_16_Payload", "Base_Types.Unsigned_32_Payload", "Base_Types.Unsigned_64_Payload", "Base_Types.Float_Payload", "Base_Types.Float_32_Payload", "Base_Types.Float_64_Payload", "Base_Types.Character_Payload", "Base_Types.String_Payload", "Base_Types.Bits_Payload", "art.Empty", "Arrays.Coordinate_Impl_Payload", "Arrays.Array_of_Integers_Payload", "Arrays.Array_of_Coordinates_Payload", "Arrays.Vector_of_Coordinates_Payload"))
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
        case "Arrays.Coordinate_Impl_Payload" => val r = parseArraysCoordinate_Impl_PayloadT(T); return r
        case "Arrays.Array_of_Integers_Payload" => val r = parseArraysArray_of_Integers_PayloadT(T); return r
        case "Arrays.Array_of_Coordinates_Payload" => val r = parseArraysArray_of_Coordinates_PayloadT(T); return r
        case "Arrays.Vector_of_Coordinates_Payload" => val r = parseArraysVector_of_Coordinates_PayloadT(T); return r
        case _ => val r = parseArraysVector_of_Coordinates_PayloadT(T); return r
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

  def fromArraysCoordinate_Impl(o: Arrays.Coordinate_Impl, isCompact: B): String = {
    val st = Printer.printArraysCoordinate_Impl(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysCoordinate_Impl(s: String): Either[Arrays.Coordinate_Impl, Json.ErrorMsg] = {
    def fArraysCoordinate_Impl(parser: Parser): Arrays.Coordinate_Impl = {
      val r = parser.parseArraysCoordinate_Impl()
      return r
    }
    val r = to(s, fArraysCoordinate_Impl _)
    return r
  }

  def fromArraysCoordinate_Impl_Payload(o: Arrays.Coordinate_Impl_Payload, isCompact: B): String = {
    val st = Printer.printArraysCoordinate_Impl_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysCoordinate_Impl_Payload(s: String): Either[Arrays.Coordinate_Impl_Payload, Json.ErrorMsg] = {
    def fArraysCoordinate_Impl_Payload(parser: Parser): Arrays.Coordinate_Impl_Payload = {
      val r = parser.parseArraysCoordinate_Impl_Payload()
      return r
    }
    val r = to(s, fArraysCoordinate_Impl_Payload _)
    return r
  }

  def fromArraysArray_of_Coordinates(o: Arrays.Array_of_Coordinates, isCompact: B): String = {
    val st = Printer.printArraysArray_of_Coordinates(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysArray_of_Coordinates(s: String): Either[Arrays.Array_of_Coordinates, Json.ErrorMsg] = {
    def fArraysArray_of_Coordinates(parser: Parser): Arrays.Array_of_Coordinates = {
      val r = parser.parseArraysArray_of_Coordinates()
      return r
    }
    val r = to(s, fArraysArray_of_Coordinates _)
    return r
  }

  def fromArraysArray_of_Coordinates_Payload(o: Arrays.Array_of_Coordinates_Payload, isCompact: B): String = {
    val st = Printer.printArraysArray_of_Coordinates_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysArray_of_Coordinates_Payload(s: String): Either[Arrays.Array_of_Coordinates_Payload, Json.ErrorMsg] = {
    def fArraysArray_of_Coordinates_Payload(parser: Parser): Arrays.Array_of_Coordinates_Payload = {
      val r = parser.parseArraysArray_of_Coordinates_Payload()
      return r
    }
    val r = to(s, fArraysArray_of_Coordinates_Payload _)
    return r
  }

  def fromArraysVector_of_Coordinates(o: Arrays.Vector_of_Coordinates, isCompact: B): String = {
    val st = Printer.printArraysVector_of_Coordinates(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysVector_of_Coordinates(s: String): Either[Arrays.Vector_of_Coordinates, Json.ErrorMsg] = {
    def fArraysVector_of_Coordinates(parser: Parser): Arrays.Vector_of_Coordinates = {
      val r = parser.parseArraysVector_of_Coordinates()
      return r
    }
    val r = to(s, fArraysVector_of_Coordinates _)
    return r
  }

  def fromArraysVector_of_Coordinates_Payload(o: Arrays.Vector_of_Coordinates_Payload, isCompact: B): String = {
    val st = Printer.printArraysVector_of_Coordinates_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysVector_of_Coordinates_Payload(s: String): Either[Arrays.Vector_of_Coordinates_Payload, Json.ErrorMsg] = {
    def fArraysVector_of_Coordinates_Payload(parser: Parser): Arrays.Vector_of_Coordinates_Payload = {
      val r = parser.parseArraysVector_of_Coordinates_Payload()
      return r
    }
    val r = to(s, fArraysVector_of_Coordinates_Payload _)
    return r
  }

  def fromArraysArray_of_Integers(o: Arrays.Array_of_Integers, isCompact: B): String = {
    val st = Printer.printArraysArray_of_Integers(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysArray_of_Integers(s: String): Either[Arrays.Array_of_Integers, Json.ErrorMsg] = {
    def fArraysArray_of_Integers(parser: Parser): Arrays.Array_of_Integers = {
      val r = parser.parseArraysArray_of_Integers()
      return r
    }
    val r = to(s, fArraysArray_of_Integers _)
    return r
  }

  def fromArraysArray_of_Integers_Payload(o: Arrays.Array_of_Integers_Payload, isCompact: B): String = {
    val st = Printer.printArraysArray_of_Integers_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toArraysArray_of_Integers_Payload(s: String): Either[Arrays.Array_of_Integers_Payload, Json.ErrorMsg] = {
    def fArraysArray_of_Integers_Payload(parser: Parser): Arrays.Array_of_Integers_Payload = {
      val r = parser.parseArraysArray_of_Integers_Payload()
      return r
    }
    val r = to(s, fArraysArray_of_Integers_Payload _)
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