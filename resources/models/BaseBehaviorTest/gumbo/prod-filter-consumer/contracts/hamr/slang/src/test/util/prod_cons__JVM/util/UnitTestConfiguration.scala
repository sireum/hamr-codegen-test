//#Sireum

package prod_cons__JVM.util

import org.sireum._
import prod_cons__JVM.util.Container
import prod_cons__JVM.GumboXUtil.GumboXResult

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

@msig trait UnitTestConfiguration {
  def name: String
  def description: String
  def profile: Profile
  def test(c: Container): GumboXResult.Type
  def genReplay: (Container, GumboXResult.Type) => Option[String]
  def verbose: B
}

@msig trait UnitTestConfigurationBatch extends UnitTestConfiguration {
  def numTests: Z
  def numTestVectorGenRetries: Z
  def failOnUnsatPreconditions: B
}

@msig trait Profile {
  def next: Container
}