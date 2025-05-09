package org.sireum.hamr.codegen.test.microkit.util.pretty

import org.sireum._
import org.sireum.hamr.codegen.common.util.GclUtil
import org.sireum.hamr.ir.JSON
import org.sireum.lang.{FrontEnd, ast => AST}
import org.sireum.lang.ast.Exp
import org.sireum.lang.parser.Parser
import org.sireum.lang.symbol.Scope
import org.sireum.message.Reporter

object Pretty extends App {

  val a: (Z, Os.Path) = (960, Os.path("/Users/belt/devel/sireum/kekinian/hamr/codegen/jvm/src/test/resources/models/GumboTest/compute-entrypoint/.slang/Compute_Entrypoint_s_impl_Instance_OLD.json"))
  val b: (Z, Os.Path) = (960, Os.path("/Users/belt/devel/sireum/kekinian/hamr/codegen/jvm/src/test/resources/models/GumboTest/compute-entrypoint/.slang/Compute_Entrypoint_s_impl_Instance.json"))
  val c: Option[String] = Some(
    st"""
       				 z"1" > z"0" && z8"8" > z8"7" && z16"16" > z16"15" && z32"32" > z32"31" && z64"64" > z64"63" &&

		           n"1" > n"0" && n8"8" > n8"7" && n16"16" > n16"15" && n32"32" > n32"31" && n64"64" > n64"63" &&

		           s8"9" > s8"8"  &&  s16"16" > s16"15"  &&  s32"32" > s32"31"  &&  s64"64" > s64"63"  &&

		           u1"1" > u1"0" && u2"1" > u2"0" && u3"1" > u3"0" && u4"1" > u4"0" && u5"1" > u5"0" && u6"1" > u6"0" &&
		           u7"1" > u7"0" && u8"1" > u8"0" && u9"1" > u9"0" && u10"1" > u10"0" && u11"1" > u11"0" && u12"1" > u12"0" &&
		           u13"1" > u13"0" && u14"1" > u14"0" && u15"1" > u15"0" && u16"1" > u16"0" && u17"1" > u17"0" && u18"1" > u18"0" &&
		           u19"1" > u19"0" && u20"1" > u20"0" && u21"1" > u21"0" && u22"1" > u22"0" && u23"1" > u23"0" && u24"1" > u24"0"
      """.render)

  var cnodes: ISZ[ST] = ISZ()
  var cedges: ISZ[ST] = ISZ()

  var nodes: ISZ[ST]= ISZ()
  var edges: ISZ[ST]= ISZ()
  var _count: Z = 0
  def count:Z = {
    _count = _count + 1
    return _count - 1
  }

  def resetGraph(): Unit = {
    nodes = ISZ()
    edges = ISZ()
  }

  def walk(e: Exp): ST = {
    e match {
      case b: Exp.Binary =>
        val id = st"Binary$count"
        nodes = nodes :+ st"""$id [label="${b.op}"];"""
        val left = walk(b.left)
        val right = walk(b.right)
        edges = edges :+ st"$id -> $left;"
        edges = edges :+ st"$id -> $right;"
        return id
      case b: Exp.Select =>
        val id = st"Select$count"
        nodes = nodes :+ st"""$id  [label="${b.id.value}"];"""
        return id
      case b: Exp.Ident =>
        val id = st"Ident${count}"
        nodes = nodes :+ st"""$id  [label="${b.id.value}"];"""
        return id
      case b: Exp.StringInterpolate =>
        val id = st"s32$count"
        nodes = nodes :+ st"""$id [label="${b.prefix}\"${b.lits(0).value}\""];"""
        return id
      case b: Exp.LitZ =>
        val id = st"LitZ${count}"
        nodes = nodes :+ st"""$id [label="${b.value}"];"""
        return id
      case b: Exp.LitB =>
        val id = st"LitB${count}"
        nodes = nodes :+ st"""$id [label="${b.value}"];"""
        return id
      case b: Exp.Unary =>
        val id = st"Unary${count}"
        nodes = nodes :+ st"""$id [label="${b.op}"];"""
        val exp = walk(b.exp)
        edges = edges :+ st"$id -> $exp;"
        return id
      case x =>
        halt(s"handle ${x}")
    }
  }

  val emptyAttr: AST.Attr = AST.Attr(None())
  val emptyRAttr: AST.ResolvedAttr = AST.ResolvedAttr(None(), None(), None())
  var flat: ISZ[Exp] = ISZ()
  def flatten(e: Exp): Unit = {
    e match {
      case e: Exp.Binary =>
        flatten(e.left)
        flat = flat :+ Exp.LitString(e.op, emptyAttr)
        flatten(e.right)
      case i:Exp.Select => flat = flat :+ i
      case i: Exp.Ident => flat = flat :+ i
      case i: Exp.StringInterpolate => flat = flat :+ i
      case x => halt(s"handle $x")
    }
  }

  def process(startLine: Z, path: Os.Path): Exp = {
    val lines = path.readLines
    var line = conversions.String.toCis(lines(startLine))
    var indent = 0
    while (line(indent).isWhitespace) {
      indent = indent + 1
    }
    var currentLine = startLine + 1
    var found = F
    while (!found) {
      line = conversions.String.toCis(lines(currentLine))
      found = line(indent - 2) == c"}"
      currentLine = currentLine + 1
    }
    val exp = st"""{
                  |${(ops.ISZOps(lines).slice(startLine, currentLine - 1), "\n")}
                  |}
                  |""".render
    JSON.to_langastExp(exp) match {
      case Either.Left(exp) =>
        val f = (path.up / s"${path.name}.dot")
        return processH(exp, f)
      case Either.Right(msg) => halt(msg.message)
    }
  }

  def processH(exp: Exp, output: Os.Path): Exp = {
    walk(exp)

    cnodes = cnodes ++ nodes
    cedges = cedges ++ edges

    render(nodes, edges, output)

    resetGraph()

    return exp
  }

  def render(nodes: ISZ[ST], edges: ISZ[ST], output: Os.Path): Unit = {
    val r =
      st"""digraph G {
          |  rankdir="TB"
          |
          |  ${(nodes, "\n")}
          |
          |  ${(edges, "\n")}
          |}"""
    //println(r.render)
    output.writeOver(r.render)
    proc"dot -Tpdf -O $output".runCheck()
    println(s"Generated: ${output}")

  }

  lazy val (tc, rep) = FrontEnd.checkedLibraryReporter

  def getExp(s: String): Exp = {
    val exp = Parser(s).parseExp[Exp]
    val scope = Scope.Local.create(HashMap.empty, Scope.Global(ISZ(), ISZ(), ISZ()))
    val reporter = Reporter.create
    tc.checkExp(expectedOpt = org.sireum.None(), scope = scope, exp = exp, reporter = reporter) match {
      case (exp, _) => return exp
      case _ => halt("Not a valid expression")
    }
  }

  override def main(args: ISZ[String]): Z = {
    val e = getExp("0x33")

    val aast = process(a._1, a._2)
    val bast = process(b._1, b._2)
    if (c.nonEmpty) {
      processH(getExp(ops.StringOps(c.get).replaceAllLiterally("\n", "")), b._2.up / "scalametals.dot")
    }

    render(cnodes, cedges, b._2.up / "combined.dot")

    //flat = ISZ()
    //flatten(osateAst)
    //val r = GclUtil.rewriteBinary(flat, Reporter.create)
    //processH(r, osate.up / "rewritten")
    return 0
  }
}
