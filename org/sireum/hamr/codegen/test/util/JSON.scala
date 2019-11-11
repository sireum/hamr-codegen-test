// #Sireum
// @formatter:off

// This file is auto-generated from TestResult.scala

package org.sireum.hamr.codegen.test.util

import org.sireum._
import org.sireum.Json.Printer._

object JSON {

  object Printer {

    @pure def printResource(o: Resource): ST = {
      return printObject(ISZ(
        ("type", st""""Resource""""),
        ("content", printString(o.content))
      ))
    }

    @pure def printTestResult(o: TestResult): ST = {
      return printObject(ISZ(
        ("type", st""""TestResult""""),
        ("map", printMap(F, o.map, printString _, printResource _))
      ))
    }

  }

  @record class Parser(input: String) {
    val parser: Json.Parser = Json.Parser.create(input)

    def errorOpt: Option[Json.ErrorMsg] = {
      return parser.errorOpt
    }

    def parseResource(): Resource = {
      val r = parseResourceT(F)
      return r
    }

    def parseResourceT(typeParsed: B): Resource = {
      if (!typeParsed) {
        parser.parseObjectType("Resource")
      }
      parser.parseObjectKey("content")
      val content = parser.parseString()
      parser.parseObjectNext()
      return Resource(content)
    }

    def parseTestResult(): TestResult = {
      val r = parseTestResultT(F)
      return r
    }

    def parseTestResultT(typeParsed: B): TestResult = {
      if (!typeParsed) {
        parser.parseObjectType("TestResult")
      }
      parser.parseObjectKey("map")
      val map = parser.parseMap(parser.parseString _, parseResource _)
      parser.parseObjectNext()
      return TestResult(map)
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

  def fromResource(o: Resource, isCompact: B): String = {
    val st = Printer.printResource(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toResource(s: String): Either[Resource, Json.ErrorMsg] = {
    def fResource(parser: Parser): Resource = {
      val r = parser.parseResource()
      return r
    }
    val r = to(s, fResource _)
    return r
  }

  def fromTestResult(o: TestResult, isCompact: B): String = {
    val st = Printer.printTestResult(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toTestResult(s: String): Either[TestResult, Json.ErrorMsg] = {
    def fTestResult(parser: Parser): TestResult = {
      val r = parser.parseTestResult()
      return r
    }
    val r = to(s, fTestResult _)
    return r
  }

}