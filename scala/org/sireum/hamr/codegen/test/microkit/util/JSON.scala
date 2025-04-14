// #Sireum
// @formatter:off

// This file is auto-generated from SimpleAst.scala

package org.sireum.hamr.codegen.test.microkit.util

import org.sireum._
import org.sireum.Json.Printer._
import org.sireum.hamr.codegen.test.microkit.util.Exp
import org.sireum.hamr.codegen.test.microkit.util.Binary
import org.sireum.hamr.codegen.test.microkit.util.LitB
import org.sireum.hamr.codegen.test.microkit.util.Invoke

object JSON {

  object Printer {

    @pure def printExp(o: Exp): ST = {
      o match {
        case o: Binary => return printBinary(o)
        case o: LitB => return printLitB(o)
        case o: Invoke => return printInvoke(o)
      }
    }

    @pure def printBinary(o: Binary): ST = {
      return printObject(ISZ(
        ("type", st""""Binary""""),
        ("left", printExp(o.left)),
        ("op", printString(o.op)),
        ("right", printExp(o.right))
      ))
    }

    @pure def printLitB(o: LitB): ST = {
      return printObject(ISZ(
        ("type", st""""LitB""""),
        ("value", printString(o.value))
      ))
    }

    @pure def printInvoke(o: Invoke): ST = {
      return printObject(ISZ(
        ("type", st""""Invoke""""),
        ("name", printString(o.name)),
        ("args", printISZ(F, o.args, printExp _))
      ))
    }

  }

  @record class Parser(val input: String) {
    val parser: Json.Parser = Json.Parser.create(input)

    def errorOpt: Option[Json.ErrorMsg] = {
      return parser.errorOpt
    }

    def parseExp(): Exp = {
      val t = parser.parseObjectTypes(ISZ("Binary", "LitB", "Invoke"))
      t.native match {
        case "Binary" => val r = parseBinaryT(T); return r
        case "LitB" => val r = parseLitBT(T); return r
        case "Invoke" => val r = parseInvokeT(T); return r
        case _ => val r = parseInvokeT(T); return r
      }
    }

    def parseBinary(): Binary = {
      val r = parseBinaryT(F)
      return r
    }

    def parseBinaryT(typeParsed: B): Binary = {
      if (!typeParsed) {
        parser.parseObjectType("Binary")
      }
      parser.parseObjectKey("left")
      val left = parseExp()
      parser.parseObjectNext()
      parser.parseObjectKey("op")
      val op = parser.parseString()
      parser.parseObjectNext()
      parser.parseObjectKey("right")
      val right = parseExp()
      parser.parseObjectNext()
      return Binary(left, op, right)
    }

    def parseLitB(): LitB = {
      val r = parseLitBT(F)
      return r
    }

    def parseLitBT(typeParsed: B): LitB = {
      if (!typeParsed) {
        parser.parseObjectType("LitB")
      }
      parser.parseObjectKey("value")
      val value = parser.parseString()
      parser.parseObjectNext()
      return LitB(value)
    }

    def parseInvoke(): Invoke = {
      val r = parseInvokeT(F)
      return r
    }

    def parseInvokeT(typeParsed: B): Invoke = {
      if (!typeParsed) {
        parser.parseObjectType("Invoke")
      }
      parser.parseObjectKey("name")
      val name = parser.parseString()
      parser.parseObjectNext()
      parser.parseObjectKey("args")
      val args = parser.parseISZ(parseExp _)
      parser.parseObjectNext()
      return Invoke(name, args)
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

  def fromExp(o: Exp, isCompact: B): String = {
    val st = Printer.printExp(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toExp(s: String): Either[Exp, Json.ErrorMsg] = {
    def fExp(parser: Parser): Exp = {
      val r = parser.parseExp()
      return r
    }
    val r = to(s, fExp _)
    return r
  }

  def fromBinary(o: Binary, isCompact: B): String = {
    val st = Printer.printBinary(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBinary(s: String): Either[Binary, Json.ErrorMsg] = {
    def fBinary(parser: Parser): Binary = {
      val r = parser.parseBinary()
      return r
    }
    val r = to(s, fBinary _)
    return r
  }

  def fromLitB(o: LitB, isCompact: B): String = {
    val st = Printer.printLitB(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toLitB(s: String): Either[LitB, Json.ErrorMsg] = {
    def fLitB(parser: Parser): LitB = {
      val r = parser.parseLitB()
      return r
    }
    val r = to(s, fLitB _)
    return r
  }

  def fromInvoke(o: Invoke, isCompact: B): String = {
    val st = Printer.printInvoke(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toInvoke(s: String): Either[Invoke, Json.ErrorMsg] = {
    def fInvoke(parser: Parser): Invoke = {
      val r = parser.parseInvoke()
      return r
    }
    val r = to(s, fInvoke _)
    return r
  }

}