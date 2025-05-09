package org.sireum.hamr.codegen.test.microkit

import org.sireum.hamr.codegen.microkit.plugins.gumbo.SlangExpUtil.rewriteExpHL
import org.sireum.lang.FrontEnd
import org.sireum.lang.ast.Exp
import org.sireum.lang.parser.Parser
import org.sireum.lang.symbol.Scope
import org.sireum.message.Reporter
import org.sireum.test.TestSuite
import org.sireum.{B, F, HashMap, ISZ, Map, ST, T, halt}


class SlangExp2RustTests extends TestSuite {

  // & binds looser than == in Slang, but & binds tighter than == in Rust so
  // would need parens in Slang around T & T, but don't need them in Rust
  "(T & T) == T" in {
    test("(T & T) == T", "T & T == T", F)
  }

  // wouldn't need parens around T == T in Slang, but would need them in
  // Rust since & binds looser than ==
  rust("T & (T == T)", "T & (T == T)")

  // this should give the same results as above
  rust("T & T == T", "T & (T == T)")

  "T & (T > T + T)" in {
    test("T & (T > T + T)", "T & (T > T + T)", F)
  }

  // Slang: < binds tighter than == so need parens around T < T.
  // Rust:  < and == have the same precedence
  "T < T == T" in {
    test("T < T == T", "(T < T) == T", F)
  }

  rust("T < (T == T)", "T < (T == T)")

  // Slang: == bind more tightly than & so will need parens
  // Rust: == binds looser than & so no parens needed
  rust ("T == (T & T)", "T == T & T")

  "T == (T & T || T & (T ___>: T)) || (T &&T)" in {
    test ("T == (T & T || T & (T ___>: T)) || (T &&T)", "", F)
  }

  // Verus: & will be converted to &&.  && binds looser than == so will need parens
  verus ("T == (T & T)", "T == (T && T)")

  // Verus: ->: will be converted to ==> and & to &&.  Implication
  //            binds the loosest, but we're going from & to &&
  //            so do need parens
  "T __>: T & T" in {
    test("T __>: T & T", "T ==> (T && T)", T)
  }
  // Verus: ->: will be converted to ==>.  Implication
  //            binds the loosest, so don't need parens
  "T __>: T && T" in {
    test("T __>: T && T", "T ==> T && T", T)
  }

  // Verus: implication binds loosest so will need parens
  "T && (T __>: T)" in {
    test("T && (T __>: T)", "T && (T ==> T)", T)
  }

  // Verus: implication binds loosest so will need parens
  "(T __>: T) __>: T" in {
    test("(T __>: T) __>: T", "(T ==> T) ==> T", T)
  }

  // Verus: implication binds loosest so will need parens
  "T ___>: T __>: T (rust)" in {
    test("T ___>: T __>: T", "T ==> T ==> T", F)
  }

  // Verus: implication binds loosest so will need parens
  "T ___>: T __>: T" in {
    test("T ___>: T __>: T", "T ==> T ==> T", T)
  }


  def rust(str: String, expected: String): Unit = {
    registerTest(s"R: $str") { test(str, expected, F) }
  }

  def verus(str: String, expected: String): Unit = {
    registerTest(s"V: $str") { test(str, expected, T) }
  }

  def test(str: String, expected: String, inVerus: B): Unit = {

    /*
    val slangExp: Exp = getExp(str)
    val reporter = Reporter.create
    val rustExp: ST = rewriteExpHL(slangExp, Map.empty, F, inVerus, T, T, reporter)

    import org.sireum._
    println(
      st"""Orig:  $str
          |Slang: ${slangExp.prettyST}
          |${if(inVerus) "Verus" else "Rust "}:  $rustExp
          |--------------""".render)

    //assert (rustExp.render.native == expected)

    if (!MicrokitTestUtil.isCI) {
      println("!!!!!!!!!!!!!!  Need to get cargo/rust testing working on github !!!!!!!!!!!!!!!!!!!")

      val rust2Slang = util.Util.testDir / "scala" / "org" / "sireum" / "hamr" / "codegen" / "test" / "microkit" / "util" / "rust2Slang"
      val release = rust2Slang / "target" / "release" / "rust_parser"

      if (!release.exists) {
        println("Building rust2Slang ...")
        val r = proc"cargo build --release".at(rust2Slang.canon).echo.console.run()
        if (!r.ok) {
          println(r.out)
          println(r.err)
        }
      }

      println("Running rust2slang ...")
      val input = Os.temp()
      input.writeOver(rustExp.render)
      val output = Os.temp()
      proc"${release.canon} $input $output".runCheck()

      println(output.read)

      import org.sireum.lang.ast.Exp

      util.JSON.toExp(output.read) match {
        case Either.Left(rustExp) =>
          def walk(slangExp: Exp, rustExp: util.Exp): Unit = {
            (slangExp, rustExp) match {
              case (slangExp: Exp.Binary, rustExp: util.Binary) =>
                val slangOp =
                  slangExp.op match {
                    case Exp.BinaryOp.Or if inVerus => Exp.BinaryOp.CondOr
                    case Exp.BinaryOp.And if inVerus => Exp.BinaryOp.CondAnd
                    case op => op
                  }
                val rustOp = rustExp.op
                assert(slangOp == rustOp, s"$slangOp vs $rustOp")

                walk(slangExp.left, rustExp.left)
                walk(slangExp.right, rustExp.right)

              case (slangExp: Exp.Binary, rustExp: util.Invoke) =>
                val rustOp: org.sireum.String =
                  rustExp.name match {
                    case string"implies" => Exp.BinaryOp.CondImply
                    case string"impliesL" => Exp.BinaryOp.Imply
                    case x => halt(x)
                  }
                val slangOp =
                  slangExp.op match {
                    case Exp.BinaryOp.CondImply => Exp.BinaryOp.CondImply
                    case Exp.BinaryOp.Imply =>
                      if (inVerus) Exp.BinaryOp.CondImply
                      else Exp.BinaryOp.Imply
                    case x => halt(x)
                  }
                assert(slangOp == rustOp, s"$slangOp vs $rustOp")
                assert(rustExp.args.size == 2)

                walk(slangExp.left, rustExp.args(0))
                walk(slangExp.right, rustExp.args(1))

              case (slangExp: Exp.Ident, rustExp: util.LitB) =>
                assert(slangExp.id.value == rustExp.value, s"${slangExp.id.value} vs ${rustExp.value}")

              case _ => halt(
                st"""Mismatch:
                    |  $slangExp
                    |vs
                    |  $rustExp""".render)
            }
          }

          walk(slangExp, rustExp)
        case Either.Right(msg) => halt(msg)
      }
    }

     */
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
}
