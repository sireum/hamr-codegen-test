package org.sireum.hamr.codegen.test.util

import org.sireum._
import org.sireum.U32._
import org.sireum.hamr.codegen.common.properties.PropertyUtil
import org.sireum.hamr.codegen.common.util.TimeUtil
import org.sireum.message.{FlatPos, Position, Reporter}
import org.sireum.test.TestSuite

/** Unit tests for the exact time conversions (doc/ExactTime-design.md, D2 and D4) */
class TimeUtilTests extends TestSuite {

  def pos(line: Int): Option[Position] =
    Some(FlatPos(None(), U32(line), u32"1", U32(line), u32"2", u32"0", u32"1"))

  def roundingWarnings(r: Reporter): Int =
    r.warnings.elements.count(m => m.kind == TimeUtil.timeRoundingKind)

  def toPs(value: Predef.String, unit: Option[String]): (Option[Z], Reporter) = {
    val r = Reporter.create
    val ps = PropertyUtil.toPicoseconds(String(value), unit, "Period of top.p.t (Timing_Properties::Period)", pos(1), r)
    (ps, r)
  }

  "toPicoseconds" - {
    "every time unit" in {
      val cases: Seq[(Predef.String, Predef.String, Long)] = Seq(
        ("2", "ps", 2L), ("2", "ns", 2000L), ("2", "us", 2000000L), ("2", "ms", 2000000000L),
        ("2", "sec", 2000000000000L), ("2", "min", 120000000000000L), ("2", "hr", 7200000000000000L))
      for ((v, u, expected) <- cases) {
        val (ps, r) = toPs(v, Some(String(u)))
        assert(ps == Some(Z(expected)), s"$v $u")
        assert(!r.hasIssue, s"$v $u: ${r.messages}")
      }
    }

    "OSATE double forms, including noise, are silent" in {
      val cases: Seq[(Predef.String, Long)] = Seq(
        ("1.0E8", 100000000L), ("1.0000E+12", 1000000000000L), ("2.0E+9", 2000000000L),
        ("3.3299999999999996E10", 33300000000L))
      for ((v, expected) <- cases) {
        val (ps, r) = toPs(v, Some(String("ps")))
        assert(ps == Some(Z(expected)), v)
        assert(!r.hasIssue, s"$v: ${r.messages}")
      }
    }

    "a genuine sub-picosecond fraction is rounded with a warning" in {
      val (ps, r) = toPs("1.4", Some(String("ps")))
      assert(ps == Some(Z(1)))
      assert(roundingWarnings(r) == 1)
      assert(!r.hasError)

      val (ps2, r2) = toPs("1000000.4", Some(String("ps")))
      assert(ps2 == Some(Z(1000000)))
      assert(roundingWarnings(r2) == 1)
    }

    "zero is not a rounding warning" in {
      val (ps, r) = toPs("0.0", Some(String("ps")))
      assert(ps == Some(Z(0)))
      assert(!r.hasIssue)
    }

    "missing or unknown unit, or a value that is not a number, is an error" in {
      val (ps1, r1) = toPs("2", None())
      assert(ps1.isEmpty && r1.hasError)
      val (ps2, r2) = toPs("2", Some(String("fortnight")))
      assert(ps2.isEmpty && r2.hasError)
      val (ps3, r3) = toPs("two", Some(String("ms")))
      assert(ps3.isEmpty && r3.hasError)
    }
  }

  def fromPs(ps: Long, res: Long, max: Long, atLeastOne: Boolean): (Z, Reporter) = {
    val r = Reporter.create
    val v =
      if (atLeastOne) TimeUtil.fromPicosecondsAtLeastOne(Z(ps), Z(res), Z(max), "Period of top.p.t", "the target", pos(1), r)
      else TimeUtil.fromPicoseconds(Z(ps), Z(res), Z(max), "Period of top.p.t", "the target", pos(1), r)
    (v, r)
  }

  "fromPicoseconds" - {
    "exact conversion is silent" in {
      val (v, r) = fromPs(2000L, 1000L, 1000000L, atLeastOne = false)
      assert(v == Z(2) && !r.hasIssue)
    }

    "inexact rounds to nearest, ties away from zero, with a warning" in {
      val (v1, r1) = fromPs(1500L, 1000L, 1000000L, atLeastOne = false)
      assert(v1 == Z(2) && roundingWarnings(r1) == 1 && !r1.hasError)
      val (v2, r2) = fromPs(1400L, 1000L, 1000000L, atLeastOne = false)
      assert(v2 == Z(1) && roundingWarnings(r2) == 1)
    }

    "a model-defined resolution (a Clock_Period tick)" in {
      // 5 ms with a 2 ms tick is 2.5 ticks, which rounds to 3
      val (v, r) = fromPs(5000000000L, 2000000000L, 2147483647L, atLeastOne = false)
      assert(v == Z(3) && roundingWarnings(r) == 1)
    }

    "rounding to 0, a value of 0, or a value above the maximum is an error" in {
      val (v1, r1) = fromPs(400L, 1000L, 1000000L, atLeastOne = false)
      assert(v1 == Z(0) && r1.hasError)
      val (v2, r2) = fromPs(0L, 1000L, 1000000L, atLeastOne = false)
      assert(v2 == Z(0) && r2.hasError)
      val (v3, r3) = fromPs(5000000L, 1000L, 1000L, atLeastOne = false)
      assert(v3 == Z(0) && r3.hasError)
    }

    "fromPicosecondsAtLeastOne clamps to 1 with a warning" in {
      val (v, r) = fromPs(400L, 1000L, 1000000L, atLeastOne = true)
      assert(v == Z(1) && roundingWarnings(r) == 1 && !r.hasError)
    }
  }

  "format" in {
    val cases: Seq[(Long, Predef.String)] = Seq(
      (0L, "0"), (999L, "999 ps"), (1500L, "1.5 ns"), (100000000L, "100 us"), (1500000000L, "1.5 ms"),
      (33300000000L, "33.3 ms"), (2000000000000L, "2 s"), (1234567L, "1234.567 ns"))
    for ((ps, expected) <- cases) {
      assert(TimeUtil.format(Z(ps)) == String(expected), s"$ps: ${TimeUtil.format(Z(ps))}")
    }
  }

  "warnOnce" in {
    val r = Reporter.create
    TimeUtil.warnOnce(pos(1), TimeUtil.timeRoundingKind, "same text", r)
    TimeUtil.warnOnce(pos(1), TimeUtil.timeRoundingKind, "same text", r)
    assert(r.warnings.size == 1, "same text and position is reported once")
    TimeUtil.warnOnce(pos(2), TimeUtil.timeRoundingKind, "same text", r)
    assert(r.warnings.size == 2, "same text at a different position is reported")
    TimeUtil.warnOnce(pos(1), TimeUtil.timeRoundingKind, "different text", r)
    assert(r.warnings.size == 3, "different text at the same position is reported")
  }
}
