// #Sireum
// @formatter:off

// This file is auto-generated from TestResult.scala

package org.sireum.hamr.codegen.test.util

import org.sireum._

object MsgPack {

  object Constants {

    val Resource: Z = -32

    val TestResult: Z = -31

  }

  object Writer {

    @record class Default(val writer: MessagePack.Writer.Impl) extends Writer

  }

  @msig trait Writer {

    def writer: MessagePack.Writer

    def writeResource(o: Resource): Unit = {
      writer.writeZ(Constants.Resource)
      writer.writeString(o.content)
    }

    def writeTestResult(o: TestResult): Unit = {
      writer.writeZ(Constants.TestResult)
      writer.writeMap(o.map, writer.writeString _, writeResource _)
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

    def readResource(): Resource = {
      val r = readResourceT(F)
      return r
    }

    def readResourceT(typeParsed: B): Resource = {
      if (!typeParsed) {
        reader.expectZ(Constants.Resource)
      }
      val content = reader.readString()
      return Resource(content)
    }

    def readTestResult(): TestResult = {
      val r = readTestResultT(F)
      return r
    }

    def readTestResultT(typeParsed: B): TestResult = {
      if (!typeParsed) {
        reader.expectZ(Constants.TestResult)
      }
      val map = reader.readMap(reader.readString _, readResource _)
      return TestResult(map)
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

  def fromResource(o: Resource, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeResource(o)
    return w.result
  }

  def toResource(data: ISZ[U8]): Either[Resource, MessagePack.ErrorMsg] = {
    def fResource(reader: Reader): Resource = {
      val r = reader.readResource()
      return r
    }
    val r = to(data, fResource _)
    return r
  }

  def fromTestResult(o: TestResult, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeTestResult(o)
    return w.result
  }

  def toTestResult(data: ISZ[U8]): Either[TestResult, MessagePack.ErrorMsg] = {
    def fTestResult(reader: Reader): TestResult = {
      val r = reader.readTestResult()
      return r
    }
    val r = to(data, fTestResult _)
    return r
  }

}