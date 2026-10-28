package org.sireum.hamr.codegen.test.microkit

import org.sireum._
import org.scalatest.{BeforeAndAfterAll, Suite}

// A suite's scratch space: one fresh directory under the system temp directory per run,
// removed when the suite finishes.  Os.tempDir() makes a new directory on every run and
// nothing else deletes it, so without this each run's generated projects and builds stay
// behind -- about 18GB a run for SystemTestingTests' QEMU tests.  Set the environment
// variable HAMR_KEEP_TEST_SCRATCH to keep the directory, e.g. to inspect a failed build.
trait TestScratch extends BeforeAndAfterAll { this: Suite =>

  val scratchBase: Os.Path = Os.tempDir()

  override def afterAll(): Unit = {
    try super.afterAll()
    finally {
      if (Os.env("HAMR_KEEP_TEST_SCRATCH").isEmpty) scratchBase.removeAll()
      else println(s"Keeping test scratch directory $scratchBase (HAMR_KEEP_TEST_SCRATCH is set)")
    }
  }
}
