// #Sireum

package a.Arrays

import org.sireum._
import a._
import org.sireum.S32._ // import S32's interpolate

// This file will not be overwritten so is safe to edit
object Producer_proc_producer {

  def initialise(api: Producer_Initialization_Api): Unit = {
    // example api usage

    // Array_of_Coordinates is an IS that can hold at most 3 coordinates
    var ac = IS[Array_of_Coordinates.I, Coordinate_Impl]()
    var s32e = s32"0"

    for(i <- Array_of_Coordinates.I.Min to Array_of_Coordinates.I.Max) {
      ac = ac :+ Coordinate_Impl(s32e, s32e + s32"1", s32e + s32"2")
      s32e = s32e + s32"3"
    }
    api.put_coordinates(Array_of_Coordinates(ac))


    // Array_of_Integers is an IS that can hold at most 1 integer
    var ai = IS[Array_of_Integers.I, Base_Types.Integer]()
    var z = 0
    for(i <- Array_of_Integers.I.Min to Array_of_Integers.I.Max) {
      ai = ai :+ z
      z = z + 1
    }
    api.put_integers(Array_of_Integers(ai))


    // Vector_of_Coordinates is an unbounded ISZ (i.e. IS[Z,Z]). It's max
    // transpiled capacity is set either via the default sequence size option, e.g.
    //   sireum slang transpiler c --sequence-size 9 ...
    // or by a custom sequence entry, eg.
    //   sireum slang transpiler c --sequence IS[Z,Z]=9 ...
    //
    // Refer to bin/transpile.cmd regarding ART's usage of ISZ
    var vc = ISZ[Base_Types.Integer]()
    for(i <- 0 until 3) {
      vc = vc :+ i
    }
    api.put_vector_of_coordinates(Vector_of_Coordinates(vc))
  }

  def timeTriggered(api: Producer_Operational_Api): Unit = {
    // example api usage


  }

  def activate(api: Producer_Operational_Api): Unit = { }

  def deactivate(api: Producer_Operational_Api): Unit = { }

  def finalise(api: Producer_Operational_Api): Unit = { }

  def recover(api: Producer_Operational_Api): Unit = { }
}
