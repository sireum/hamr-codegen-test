package org.sireum.hamr.codegen.test.ros2

import org.sireum._
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.hamr.codegen.test.util.TestModeHelper

trait  Ros2TestUtil {

  def testModes: ISZ[TestMode.Type] = TestModeHelper.getEnvTestModes()

  val isCI: B = Os.env("GITLAB_CI").nonEmpty || Os.env("GITHUB_ACTIONS").nonEmpty || Os.env("BUILD_ID").nonEmpty

  def verbose: B

  assert (!isCI || !verbose, "verbose must be F when pushed to github")

  val ros2SetupPath: Option[Os.Path] = Os.env("ROS2_HOME") match {
    case Some(dist) =>
      if ((Os.path(dist) / "setup.bash").exists) Some((Os.path(dist) / "setup.bash"))
      else None()
    case _ => None()
  }

  val dockerAvailable: B =
    ros2SetupPath match {
      case None() => proc"docker info".run().ok
      case _ => F // use the native ros2 install
    }

  def expectedRoot: Os.Path
  def resultsRoot: Os.Path

  def copy(testName: String, filter: Os.Path => B = x => T, strictModeString: String): Os.Path = {
    val srcDir = expectedRoot / testName / strictModeString
    val resultDir = getExpectedDir(testName, strictModeString)
    resultDir.removeAll()

    for (r <- Os.Path.walk(srcDir, F, F, filter)) {
      val dest = resultDir / srcDir.relativize(r).value
      r.copyOverTo(dest)
    }
    return resultDir
  }

  def getExpectedDir(testName: String, strictModeString: String): Os.Path = resultsRoot / testName / "expected" / strictModeString
  def getResultsDir(testName: String, strictModeString: String): Os.Path = resultsRoot / testName / "results" / strictModeString

  def compare(testName: String, filter: Os.Path => B = _ => T, strictModeString: String): B = {
    val expected = getExpectedDir(testName, strictModeString)
    val results = getResultsDir(testName, strictModeString)

    def toMap(dir: Os.Path): Map[String, Os.Path] = {
      var ret = Map.empty[String, Os.Path]

      def iter(d: Os.Path): Unit = {
        if (d.isFile && filter(d)) ret = ret + dir.relativize(d).value ~> d
        else for (dd <- d.list) yield iter(dd)
      }

      iter(dir)
      return ret
    }

    val eMap = toMap(expected)
    val rMap = toMap(results)

    def compareKeys(a: Set[String], b: Set[String], dir: Os.Path): B = {
      val diff = a -- b.elements
      for (d <- diff.elements) {
        println(s"Couldn't match ${(dir / d).toUri}")
      }
      return diff.isEmpty
    }

    val (eSet, rSet) = (Set.empty ++ eMap.keys, Set.empty ++ rMap.keys)
    var sameContent = compareKeys(eSet, rSet, expected) & compareKeys(rSet, eSet, results)

    if (sameContent) {
      for (e <- eMap.keys) {
        val ef = expected / e
        val rf = results / e
        val expectedText = ops.StringOps(ef.read).replaceAllLiterally("\r\n", "\n")
        val resultsText = ops.StringOps(rf.read).replaceAllLiterally("\r\n", "\n")
        if (expectedText != resultsText) {
          sameContent = F
          val dmp = new DiffMatchPatch()
          println(s"File content differs: ${rf.toUri}")
          println(dmp.patch_toText(dmp.patch_make(expectedText.native, resultsText.native)))
        }
      }
    }
    return sameContent
  }
}
