// #Sireum

package bc

import org.sireum._
import org.sireum.Random.Gen64

/*
GENERATED FROM

TempUnit.scala

Temperature_impl.scala

SetPoint_impl.scala

FanAck.scala

FanCmd.scala

Base_Types.scala

DataContent.scala

*/

@msig trait RandomLibI {
  def gen: org.sireum.Random.Gen

  // ========  Z ==========
    def get_Config_Z: Config_Z
    def set_Config_Z(config: Config_Z): Unit

    def next_ISZ_Z(): ISZ[Z] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_Z(): Z = {
      var r = gen.nextZ()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_Z.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextZ()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  B ==========
    def get_Config_B: Config_B
    def set_Config_B(config: Config_B): Unit

    def next_ISZ_B(): ISZ[B] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_B(): B = {
      var r = gen.nextB()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_B.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextB()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  C ==========
    def get_Config_C: Config_C
    def set_Config_C(config: Config_C): Unit

    def next_ISZ_C(): ISZ[C] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_C(): C = {
      var r = gen.nextC()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_C.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextC()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  R ==========
    def get_Config_R: Config_R
    def set_Config_R(config: Config_R): Unit

    def next_ISZ_R(): ISZ[R] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_R(): R = {
      var r = gen.nextR()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_R.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextR()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  F32 ==========
    def get_Config_F32: Config_F32
    def set_Config_F32(config: Config_F32): Unit

    def next_ISZ_F32(): ISZ[F32] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_F32(): F32 = {
      var r = gen.nextF32()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_F32.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextF32()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  F64 ==========
    def get_Config_F64: Config_F64
    def set_Config_F64(config: Config_F64): Unit

    def next_ISZ_F64(): ISZ[F64] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_F64(): F64 = {
      var r = gen.nextF64()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_F64.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextF64()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  S8 ==========
    def get_Config_S8: Config_S8
    def set_Config_S8(config: Config_S8): Unit

    def next_ISZ_S8(): ISZ[S8] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_S8(): S8 = {
      var r = gen.nextS8()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_S8.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextS8()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  S16 ==========
    def get_Config_S16: Config_S16
    def set_Config_S16(config: Config_S16): Unit

    def next_ISZ_S16(): ISZ[S16] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_S16(): S16 = {
      var r = gen.nextS16()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_S16.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextS16()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  S32 ==========
    def get_Config_S32: Config_S32
    def set_Config_S32(config: Config_S32): Unit

    def next_ISZ_S32(): ISZ[S32] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_S32(): S32 = {
      var r = gen.nextS32()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_S32.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextS32()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  S64 ==========
    def get_Config_S64: Config_S64
    def set_Config_S64(config: Config_S64): Unit

    def next_ISZ_S64(): ISZ[S64] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_S64(): S64 = {
      var r = gen.nextS64()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_S64.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextS64()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  U8 ==========
    def get_Config_U8: Config_U8
    def set_Config_U8(config: Config_U8): Unit

    def next_ISZ_U8(): ISZ[U8] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_U8(): U8 = {
      var r = gen.nextU8()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_U8.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextU8()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  U16 ==========
    def get_Config_U16: Config_U16
    def set_Config_U16(config: Config_U16): Unit

    def next_ISZ_U16(): ISZ[U16] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_U16(): U16 = {
      var r = gen.nextU16()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_U16.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextU16()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  U32 ==========
    def get_Config_U32: Config_U32
    def set_Config_U32(config: Config_U32): Unit

    def next_ISZ_U32(): ISZ[U32] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_U32(): U32 = {
      var r = gen.nextU32()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_U32.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextU32()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  // ========  U64 ==========
    def get_Config_U64: Config_U64
    def set_Config_U64(config: Config_U64): Unit

    def next_ISZ_U64(): ISZ[U64] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

    def next_U64(): U64 = {
      var r = gen.nextU64()
      for (i <- 0 to 100 /* num retries */ ) {
        if (get_Config_U64.filter(r)) {
          return r
        }
        println(s"Retrying for failing value: $r")
        r = gen.nextU64()
      }
      assert(F, "Requirements to strict to generate")
      halt("Requirements to strict to generate")
    }

  def next_String(): String = {
   assert(F, "Requirements to strict to generate")
   halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Boolean_Payload ===================

  def get_Config_Base_TypesBoolean_Payload: Config_Base_TypesBoolean_Payload
  def set_Config_Base_TypesBoolean_Payload(config: Config_Base_TypesBoolean_Payload): Unit

  def next_ISZ_Base_TypesBoolean_Payload(): ISZ[Base_Types.Boolean_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesBoolean_Payload(): Base_Types.Boolean_Payload = {
    var value: B = next_B()

    var v: Base_Types.Boolean_Payload = Base_Types.Boolean_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesBoolean_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_B()
       v = Base_Types.Boolean_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Integer_Payload ===================

  def get_Config_Base_TypesInteger_Payload: Config_Base_TypesInteger_Payload
  def set_Config_Base_TypesInteger_Payload(config: Config_Base_TypesInteger_Payload): Unit

  def next_ISZ_Base_TypesInteger_Payload(): ISZ[Base_Types.Integer_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesInteger_Payload(): Base_Types.Integer_Payload = {
    var value: Z = next_Z()

    var v: Base_Types.Integer_Payload = Base_Types.Integer_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesInteger_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_Z()
       v = Base_Types.Integer_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Integer_8_Payload ===================

  def get_Config_Base_TypesInteger_8_Payload: Config_Base_TypesInteger_8_Payload
  def set_Config_Base_TypesInteger_8_Payload(config: Config_Base_TypesInteger_8_Payload): Unit

  def next_ISZ_Base_TypesInteger_8_Payload(): ISZ[Base_Types.Integer_8_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesInteger_8_Payload(): Base_Types.Integer_8_Payload = {
    var value: S8 = next_S8()

    var v: Base_Types.Integer_8_Payload = Base_Types.Integer_8_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesInteger_8_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_S8()
       v = Base_Types.Integer_8_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Integer_16_Payload ===================

  def get_Config_Base_TypesInteger_16_Payload: Config_Base_TypesInteger_16_Payload
  def set_Config_Base_TypesInteger_16_Payload(config: Config_Base_TypesInteger_16_Payload): Unit

  def next_ISZ_Base_TypesInteger_16_Payload(): ISZ[Base_Types.Integer_16_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesInteger_16_Payload(): Base_Types.Integer_16_Payload = {
    var value: S16 = next_S16()

    var v: Base_Types.Integer_16_Payload = Base_Types.Integer_16_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesInteger_16_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_S16()
       v = Base_Types.Integer_16_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Integer_32_Payload ===================

  def get_Config_Base_TypesInteger_32_Payload: Config_Base_TypesInteger_32_Payload
  def set_Config_Base_TypesInteger_32_Payload(config: Config_Base_TypesInteger_32_Payload): Unit

  def next_ISZ_Base_TypesInteger_32_Payload(): ISZ[Base_Types.Integer_32_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesInteger_32_Payload(): Base_Types.Integer_32_Payload = {
    var value: S32 = next_S32()

    var v: Base_Types.Integer_32_Payload = Base_Types.Integer_32_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesInteger_32_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_S32()
       v = Base_Types.Integer_32_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Integer_64_Payload ===================

  def get_Config_Base_TypesInteger_64_Payload: Config_Base_TypesInteger_64_Payload
  def set_Config_Base_TypesInteger_64_Payload(config: Config_Base_TypesInteger_64_Payload): Unit

  def next_ISZ_Base_TypesInteger_64_Payload(): ISZ[Base_Types.Integer_64_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesInteger_64_Payload(): Base_Types.Integer_64_Payload = {
    var value: S64 = next_S64()

    var v: Base_Types.Integer_64_Payload = Base_Types.Integer_64_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesInteger_64_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_S64()
       v = Base_Types.Integer_64_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Unsigned_8_Payload ===================

  def get_Config_Base_TypesUnsigned_8_Payload: Config_Base_TypesUnsigned_8_Payload
  def set_Config_Base_TypesUnsigned_8_Payload(config: Config_Base_TypesUnsigned_8_Payload): Unit

  def next_ISZ_Base_TypesUnsigned_8_Payload(): ISZ[Base_Types.Unsigned_8_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesUnsigned_8_Payload(): Base_Types.Unsigned_8_Payload = {
    var value: U8 = next_U8()

    var v: Base_Types.Unsigned_8_Payload = Base_Types.Unsigned_8_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesUnsigned_8_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_U8()
       v = Base_Types.Unsigned_8_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Unsigned_16_Payload ===================

  def get_Config_Base_TypesUnsigned_16_Payload: Config_Base_TypesUnsigned_16_Payload
  def set_Config_Base_TypesUnsigned_16_Payload(config: Config_Base_TypesUnsigned_16_Payload): Unit

  def next_ISZ_Base_TypesUnsigned_16_Payload(): ISZ[Base_Types.Unsigned_16_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesUnsigned_16_Payload(): Base_Types.Unsigned_16_Payload = {
    var value: U16 = next_U16()

    var v: Base_Types.Unsigned_16_Payload = Base_Types.Unsigned_16_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesUnsigned_16_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_U16()
       v = Base_Types.Unsigned_16_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Unsigned_32_Payload ===================

  def get_Config_Base_TypesUnsigned_32_Payload: Config_Base_TypesUnsigned_32_Payload
  def set_Config_Base_TypesUnsigned_32_Payload(config: Config_Base_TypesUnsigned_32_Payload): Unit

  def next_ISZ_Base_TypesUnsigned_32_Payload(): ISZ[Base_Types.Unsigned_32_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesUnsigned_32_Payload(): Base_Types.Unsigned_32_Payload = {
    var value: U32 = next_U32()

    var v: Base_Types.Unsigned_32_Payload = Base_Types.Unsigned_32_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesUnsigned_32_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_U32()
       v = Base_Types.Unsigned_32_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Unsigned_64_Payload ===================

  def get_Config_Base_TypesUnsigned_64_Payload: Config_Base_TypesUnsigned_64_Payload
  def set_Config_Base_TypesUnsigned_64_Payload(config: Config_Base_TypesUnsigned_64_Payload): Unit

  def next_ISZ_Base_TypesUnsigned_64_Payload(): ISZ[Base_Types.Unsigned_64_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesUnsigned_64_Payload(): Base_Types.Unsigned_64_Payload = {
    var value: U64 = next_U64()

    var v: Base_Types.Unsigned_64_Payload = Base_Types.Unsigned_64_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesUnsigned_64_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_U64()
       v = Base_Types.Unsigned_64_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Float_Payload ===================

  def get_Config_Base_TypesFloat_Payload: Config_Base_TypesFloat_Payload
  def set_Config_Base_TypesFloat_Payload(config: Config_Base_TypesFloat_Payload): Unit

  def next_ISZ_Base_TypesFloat_Payload(): ISZ[Base_Types.Float_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesFloat_Payload(): Base_Types.Float_Payload = {
    var value: R = next_R()

    var v: Base_Types.Float_Payload = Base_Types.Float_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesFloat_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_R()
       v = Base_Types.Float_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Float_32_Payload ===================

  def get_Config_Base_TypesFloat_32_Payload: Config_Base_TypesFloat_32_Payload
  def set_Config_Base_TypesFloat_32_Payload(config: Config_Base_TypesFloat_32_Payload): Unit

  def next_ISZ_Base_TypesFloat_32_Payload(): ISZ[Base_Types.Float_32_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesFloat_32_Payload(): Base_Types.Float_32_Payload = {
    var value: F32 = next_F32()

    var v: Base_Types.Float_32_Payload = Base_Types.Float_32_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesFloat_32_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_F32()
       v = Base_Types.Float_32_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Float_64_Payload ===================

  def get_Config_Base_TypesFloat_64_Payload: Config_Base_TypesFloat_64_Payload
  def set_Config_Base_TypesFloat_64_Payload(config: Config_Base_TypesFloat_64_Payload): Unit

  def next_ISZ_Base_TypesFloat_64_Payload(): ISZ[Base_Types.Float_64_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesFloat_64_Payload(): Base_Types.Float_64_Payload = {
    var value: F64 = next_F64()

    var v: Base_Types.Float_64_Payload = Base_Types.Float_64_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesFloat_64_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_F64()
       v = Base_Types.Float_64_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Character_Payload ===================

  def get_Config_Base_TypesCharacter_Payload: Config_Base_TypesCharacter_Payload
  def set_Config_Base_TypesCharacter_Payload(config: Config_Base_TypesCharacter_Payload): Unit

  def next_ISZ_Base_TypesCharacter_Payload(): ISZ[Base_Types.Character_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesCharacter_Payload(): Base_Types.Character_Payload = {
    var value: C = next_C()

    var v: Base_Types.Character_Payload = Base_Types.Character_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesCharacter_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_C()
       v = Base_Types.Character_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.String_Payload ===================

  def get_Config_Base_TypesString_Payload: Config_Base_TypesString_Payload
  def set_Config_Base_TypesString_Payload(config: Config_Base_TypesString_Payload): Unit

  def next_ISZ_Base_TypesString_Payload(): ISZ[Base_Types.String_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesString_Payload(): Base_Types.String_Payload = {
    var value: String = next_String()

    var v: Base_Types.String_Payload = Base_Types.String_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesString_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_String()
       v = Base_Types.String_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= Base_Types.Bits_Payload ===================

  def get_Config_Base_TypesBits_Payload: Config_Base_TypesBits_Payload
  def set_Config_Base_TypesBits_Payload(config: Config_Base_TypesBits_Payload): Unit

  def next_ISZ_Base_TypesBits_Payload(): ISZ[Base_Types.Bits_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_Base_TypesBits_Payload(): Base_Types.Bits_Payload = {
    var value: ISZ[B] = next_ISZ_B()

    var v: Base_Types.Bits_Payload = Base_Types.Bits_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_Base_TypesBits_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_ISZ_B()
       v = Base_Types.Bits_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= art.Empty ===================

  def get_Config_artEmpty: Config_artEmpty
  def set_Config_artEmpty(config: Config_artEmpty): Unit

  def next_ISZ_artEmpty(): ISZ[art.Empty] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_artEmpty(): art.Empty = {

    var v: art.Empty = art.Empty()

    for(i <- 0 to 100) {
       if(get_Config_artEmpty.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       v = art.Empty()
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.FanAck.Type ===================

  def get_Config_BuildingControlFanAckType: Config_BuildingControlFanAckType
  def set_Config_BuildingControlFanAckType(config: Config_BuildingControlFanAckType): Unit

  def next_BuildingControlFanAckType(): BuildingControl.FanAck.Type = {

    var ordinal: Z = gen.nextZBetween(0, bc.BuildingControl.FanAck.numOfElements-1) //is genBetween inclusive

    var v: BuildingControl.FanAck.Type = bc.BuildingControl.FanAck.byOrdinal(ordinal).get

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlFanAckType.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       ordinal= gen.nextZBetween(0, bc.BuildingControl.FanAck.numOfElements-1)
       v = bc.BuildingControl.FanAck.byOrdinal(ordinal).get
    }
    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.FanCmd.Type ===================

  def get_Config_BuildingControlFanCmdType: Config_BuildingControlFanCmdType
  def set_Config_BuildingControlFanCmdType(config: Config_BuildingControlFanCmdType): Unit

  def next_BuildingControlFanCmdType(): BuildingControl.FanCmd.Type = {

    var ordinal: Z = gen.nextZBetween(0, bc.BuildingControl.FanCmd.numOfElements-1) //is genBetween inclusive

    var v: BuildingControl.FanCmd.Type = bc.BuildingControl.FanCmd.byOrdinal(ordinal).get

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlFanCmdType.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       ordinal= gen.nextZBetween(0, bc.BuildingControl.FanCmd.numOfElements-1)
       v = bc.BuildingControl.FanCmd.byOrdinal(ordinal).get
    }
    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.FanCmd_Payload ===================

  def get_Config_BuildingControlFanCmd_Payload: Config_BuildingControlFanCmd_Payload
  def set_Config_BuildingControlFanCmd_Payload(config: Config_BuildingControlFanCmd_Payload): Unit

  def next_ISZ_BuildingControlFanCmd_Payload(): ISZ[BuildingControl.FanCmd_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_BuildingControlFanCmd_Payload(): BuildingControl.FanCmd_Payload = {
    var value: BuildingControl.FanCmd.Type = next_BuildingControlFanCmdType()

    var v: BuildingControl.FanCmd_Payload = BuildingControl.FanCmd_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlFanCmd_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_BuildingControlFanCmdType()
       v = BuildingControl.FanCmd_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.FanAck_Payload ===================

  def get_Config_BuildingControlFanAck_Payload: Config_BuildingControlFanAck_Payload
  def set_Config_BuildingControlFanAck_Payload(config: Config_BuildingControlFanAck_Payload): Unit

  def next_ISZ_BuildingControlFanAck_Payload(): ISZ[BuildingControl.FanAck_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_BuildingControlFanAck_Payload(): BuildingControl.FanAck_Payload = {
    var value: BuildingControl.FanAck.Type = next_BuildingControlFanAckType()

    var v: BuildingControl.FanAck_Payload = BuildingControl.FanAck_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlFanAck_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_BuildingControlFanAckType()
       v = BuildingControl.FanAck_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.TempUnit.Type ===================

  def get_Config_BuildingControlTempUnitType: Config_BuildingControlTempUnitType
  def set_Config_BuildingControlTempUnitType(config: Config_BuildingControlTempUnitType): Unit

  def next_BuildingControlTempUnitType(): BuildingControl.TempUnit.Type = {

    var ordinal: Z = gen.nextZBetween(0, bc.BuildingControl.TempUnit.numOfElements-1) //is genBetween inclusive

    var v: BuildingControl.TempUnit.Type = bc.BuildingControl.TempUnit.byOrdinal(ordinal).get

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlTempUnitType.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       ordinal= gen.nextZBetween(0, bc.BuildingControl.TempUnit.numOfElements-1)
       v = bc.BuildingControl.TempUnit.byOrdinal(ordinal).get
    }
    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.TempUnit_Payload ===================

  def get_Config_BuildingControlTempUnit_Payload: Config_BuildingControlTempUnit_Payload
  def set_Config_BuildingControlTempUnit_Payload(config: Config_BuildingControlTempUnit_Payload): Unit

  def next_ISZ_BuildingControlTempUnit_Payload(): ISZ[BuildingControl.TempUnit_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_BuildingControlTempUnit_Payload(): BuildingControl.TempUnit_Payload = {
    var value: BuildingControl.TempUnit.Type = next_BuildingControlTempUnitType()

    var v: BuildingControl.TempUnit_Payload = BuildingControl.TempUnit_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlTempUnit_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_BuildingControlTempUnitType()
       v = BuildingControl.TempUnit_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.SetPoint_impl ===================

  def get_Config_BuildingControlSetPoint_impl: Config_BuildingControlSetPoint_impl
  def set_Config_BuildingControlSetPoint_impl(config: Config_BuildingControlSetPoint_impl): Unit

  def next_ISZ_BuildingControlSetPoint_impl(): ISZ[BuildingControl.SetPoint_impl] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_BuildingControlSetPoint_impl(): BuildingControl.SetPoint_impl = {
    var low: BuildingControl.Temperature_impl = next_BuildingControlTemperature_impl()
    var high: BuildingControl.Temperature_impl = next_BuildingControlTemperature_impl()

    var v: BuildingControl.SetPoint_impl = BuildingControl.SetPoint_impl(low, high)

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlSetPoint_impl.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       low = next_BuildingControlTemperature_impl()
       high = next_BuildingControlTemperature_impl()
       v = BuildingControl.SetPoint_impl(low, high)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.SetPoint_impl_Payload ===================

  def get_Config_BuildingControlSetPoint_impl_Payload: Config_BuildingControlSetPoint_impl_Payload
  def set_Config_BuildingControlSetPoint_impl_Payload(config: Config_BuildingControlSetPoint_impl_Payload): Unit

  def next_ISZ_BuildingControlSetPoint_impl_Payload(): ISZ[BuildingControl.SetPoint_impl_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_BuildingControlSetPoint_impl_Payload(): BuildingControl.SetPoint_impl_Payload = {
    var value: BuildingControl.SetPoint_impl = next_BuildingControlSetPoint_impl()

    var v: BuildingControl.SetPoint_impl_Payload = BuildingControl.SetPoint_impl_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlSetPoint_impl_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_BuildingControlSetPoint_impl()
       v = BuildingControl.SetPoint_impl_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.Temperature_impl ===================

  def get_Config_BuildingControlTemperature_impl: Config_BuildingControlTemperature_impl
  def set_Config_BuildingControlTemperature_impl(config: Config_BuildingControlTemperature_impl): Unit

  def next_ISZ_BuildingControlTemperature_impl(): ISZ[BuildingControl.Temperature_impl] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_BuildingControlTemperature_impl(): BuildingControl.Temperature_impl = {
    var degrees: F32 = next_F32()
    var unit: BuildingControl.TempUnit.Type = next_BuildingControlTempUnitType()

    var v: BuildingControl.Temperature_impl = BuildingControl.Temperature_impl(degrees, unit)

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlTemperature_impl.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       degrees = next_F32()
       unit = next_BuildingControlTempUnitType()
       v = BuildingControl.Temperature_impl(degrees, unit)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }

  // ============= BuildingControl.Temperature_impl_Payload ===================

  def get_Config_BuildingControlTemperature_impl_Payload: Config_BuildingControlTemperature_impl_Payload
  def set_Config_BuildingControlTemperature_impl_Payload(config: Config_BuildingControlTemperature_impl_Payload): Unit

  def next_ISZ_BuildingControlTemperature_impl_Payload(): ISZ[BuildingControl.Temperature_impl_Payload] = {
     assert(F, "Requirements to strict to generate")
     halt("Requirements to strict to generate")
    }

  def next_BuildingControlTemperature_impl_Payload(): BuildingControl.Temperature_impl_Payload = {
    var value: BuildingControl.Temperature_impl = next_BuildingControlTemperature_impl()

    var v: BuildingControl.Temperature_impl_Payload = BuildingControl.Temperature_impl_Payload(value)

    for(i <- 0 to 100) {
       if(get_Config_BuildingControlTemperature_impl_Payload.filter(v)) {
         return v
       }
       println(s"Retrying for failing value: $v")
       value = next_BuildingControlTemperature_impl()
       v = BuildingControl.Temperature_impl_Payload(value)
    }

    assert(F, "Requirements to strict to generate")
    halt("Requirements to strict to generate")
  }
}

@record class RandomLib(val gen: org.sireum.Random.Gen) extends RandomLibI {


  // ============= Z ===================
  def alwaysTrue_Z(v: Z): B = {return T}

  var config_Z: Config_Z = Config_Z(alwaysTrue_Z _)
  def get_Config_Z: Config_Z = {return config_Z}

  def set_Config_Z(config: Config_Z): Unit ={
    config_Z = config
  }

  // ============= B ===================
  def alwaysTrue_B(v: B): B = {return T}

  var config_B: Config_B = Config_B(alwaysTrue_B _)
  def get_Config_B: Config_B = {return config_B}

  def set_Config_B(config: Config_B): Unit ={
    config_B = config
  }

  // ============= C ===================
  def alwaysTrue_C(v: C): B = {return T}

  var config_C: Config_C = Config_C(alwaysTrue_C _)
  def get_Config_C: Config_C = {return config_C}

  def set_Config_C(config: Config_C): Unit ={
    config_C = config
  }

  // ============= R ===================
  def alwaysTrue_R(v: R): B = {return T}

  var config_R: Config_R = Config_R(alwaysTrue_R _)
  def get_Config_R: Config_R = {return config_R}

  def set_Config_R(config: Config_R): Unit ={
    config_R = config
  }

  // ============= F32 ===================
  def alwaysTrue_F32(v: F32): B = {return T}

  var config_F32: Config_F32 = Config_F32(alwaysTrue_F32 _)
  def get_Config_F32: Config_F32 = {return config_F32}

  def set_Config_F32(config: Config_F32): Unit ={
    config_F32 = config
  }

  // ============= F64 ===================
  def alwaysTrue_F64(v: F64): B = {return T}

  var config_F64: Config_F64 = Config_F64(alwaysTrue_F64 _)
  def get_Config_F64: Config_F64 = {return config_F64}

  def set_Config_F64(config: Config_F64): Unit ={
    config_F64 = config
  }

  // ============= S8 ===================
  def alwaysTrue_S8(v: S8): B = {return T}

  var config_S8: Config_S8 = Config_S8(alwaysTrue_S8 _)
  def get_Config_S8: Config_S8 = {return config_S8}

  def set_Config_S8(config: Config_S8): Unit ={
    config_S8 = config
  }

  // ============= S16 ===================
  def alwaysTrue_S16(v: S16): B = {return T}

  var config_S16: Config_S16 = Config_S16(alwaysTrue_S16 _)
  def get_Config_S16: Config_S16 = {return config_S16}

  def set_Config_S16(config: Config_S16): Unit ={
    config_S16 = config
  }

  // ============= S32 ===================
  def alwaysTrue_S32(v: S32): B = {return T}

  var config_S32: Config_S32 = Config_S32(alwaysTrue_S32 _)
  def get_Config_S32: Config_S32 = {return config_S32}

  def set_Config_S32(config: Config_S32): Unit ={
    config_S32 = config
  }

  // ============= S64 ===================
  def alwaysTrue_S64(v: S64): B = {return T}

  var config_S64: Config_S64 = Config_S64(alwaysTrue_S64 _)
  def get_Config_S64: Config_S64 = {return config_S64}

  def set_Config_S64(config: Config_S64): Unit ={
    config_S64 = config
  }

  // ============= U8 ===================
  def alwaysTrue_U8(v: U8): B = {return T}

  var config_U8: Config_U8 = Config_U8(alwaysTrue_U8 _)
  def get_Config_U8: Config_U8 = {return config_U8}

  def set_Config_U8(config: Config_U8): Unit ={
    config_U8 = config
  }

  // ============= U16 ===================
  def alwaysTrue_U16(v: U16): B = {return T}

  var config_U16: Config_U16 = Config_U16(alwaysTrue_U16 _)
  def get_Config_U16: Config_U16 = {return config_U16}

  def set_Config_U16(config: Config_U16): Unit ={
    config_U16 = config
  }

  // ============= U32 ===================
  def alwaysTrue_U32(v: U32): B = {return T}

  var config_U32: Config_U32 = Config_U32(alwaysTrue_U32 _)
  def get_Config_U32: Config_U32 = {return config_U32}

  def set_Config_U32(config: Config_U32): Unit ={
    config_U32 = config
  }

  // ============= U64 ===================
  def alwaysTrue_U64(v: U64): B = {return T}

  var config_U64: Config_U64 = Config_U64(alwaysTrue_U64 _)
  def get_Config_U64: Config_U64 = {return config_U64}

  def set_Config_U64(config: Config_U64): Unit ={
    config_U64 = config
  }

  // ============= Base_Types.Boolean_Payload ===================
  def alwaysTrue_Base_TypesBoolean_Payload(v: Base_Types.Boolean_Payload): B = {return T}

  var config_Base_TypesBoolean_Payload: Config_Base_TypesBoolean_Payload = Config_Base_TypesBoolean_Payload(alwaysTrue_Base_TypesBoolean_Payload _)

  def get_Config_Base_TypesBoolean_Payload: Config_Base_TypesBoolean_Payload = {return config_Base_TypesBoolean_Payload}

  def set_Config_Base_TypesBoolean_Payload(config: Config_Base_TypesBoolean_Payload): Unit ={
    config_Base_TypesBoolean_Payload = config
  }

  // ============= Base_Types.Integer_Payload ===================
  def alwaysTrue_Base_TypesInteger_Payload(v: Base_Types.Integer_Payload): B = {return T}

  var config_Base_TypesInteger_Payload: Config_Base_TypesInteger_Payload = Config_Base_TypesInteger_Payload(alwaysTrue_Base_TypesInteger_Payload _)

  def get_Config_Base_TypesInteger_Payload: Config_Base_TypesInteger_Payload = {return config_Base_TypesInteger_Payload}

  def set_Config_Base_TypesInteger_Payload(config: Config_Base_TypesInteger_Payload): Unit ={
    config_Base_TypesInteger_Payload = config
  }

  // ============= Base_Types.Integer_8_Payload ===================
  def alwaysTrue_Base_TypesInteger_8_Payload(v: Base_Types.Integer_8_Payload): B = {return T}

  var config_Base_TypesInteger_8_Payload: Config_Base_TypesInteger_8_Payload = Config_Base_TypesInteger_8_Payload(alwaysTrue_Base_TypesInteger_8_Payload _)

  def get_Config_Base_TypesInteger_8_Payload: Config_Base_TypesInteger_8_Payload = {return config_Base_TypesInteger_8_Payload}

  def set_Config_Base_TypesInteger_8_Payload(config: Config_Base_TypesInteger_8_Payload): Unit ={
    config_Base_TypesInteger_8_Payload = config
  }

  // ============= Base_Types.Integer_16_Payload ===================
  def alwaysTrue_Base_TypesInteger_16_Payload(v: Base_Types.Integer_16_Payload): B = {return T}

  var config_Base_TypesInteger_16_Payload: Config_Base_TypesInteger_16_Payload = Config_Base_TypesInteger_16_Payload(alwaysTrue_Base_TypesInteger_16_Payload _)

  def get_Config_Base_TypesInteger_16_Payload: Config_Base_TypesInteger_16_Payload = {return config_Base_TypesInteger_16_Payload}

  def set_Config_Base_TypesInteger_16_Payload(config: Config_Base_TypesInteger_16_Payload): Unit ={
    config_Base_TypesInteger_16_Payload = config
  }

  // ============= Base_Types.Integer_32_Payload ===================
  def alwaysTrue_Base_TypesInteger_32_Payload(v: Base_Types.Integer_32_Payload): B = {return T}

  var config_Base_TypesInteger_32_Payload: Config_Base_TypesInteger_32_Payload = Config_Base_TypesInteger_32_Payload(alwaysTrue_Base_TypesInteger_32_Payload _)

  def get_Config_Base_TypesInteger_32_Payload: Config_Base_TypesInteger_32_Payload = {return config_Base_TypesInteger_32_Payload}

  def set_Config_Base_TypesInteger_32_Payload(config: Config_Base_TypesInteger_32_Payload): Unit ={
    config_Base_TypesInteger_32_Payload = config
  }

  // ============= Base_Types.Integer_64_Payload ===================
  def alwaysTrue_Base_TypesInteger_64_Payload(v: Base_Types.Integer_64_Payload): B = {return T}

  var config_Base_TypesInteger_64_Payload: Config_Base_TypesInteger_64_Payload = Config_Base_TypesInteger_64_Payload(alwaysTrue_Base_TypesInteger_64_Payload _)

  def get_Config_Base_TypesInteger_64_Payload: Config_Base_TypesInteger_64_Payload = {return config_Base_TypesInteger_64_Payload}

  def set_Config_Base_TypesInteger_64_Payload(config: Config_Base_TypesInteger_64_Payload): Unit ={
    config_Base_TypesInteger_64_Payload = config
  }

  // ============= Base_Types.Unsigned_8_Payload ===================
  def alwaysTrue_Base_TypesUnsigned_8_Payload(v: Base_Types.Unsigned_8_Payload): B = {return T}

  var config_Base_TypesUnsigned_8_Payload: Config_Base_TypesUnsigned_8_Payload = Config_Base_TypesUnsigned_8_Payload(alwaysTrue_Base_TypesUnsigned_8_Payload _)

  def get_Config_Base_TypesUnsigned_8_Payload: Config_Base_TypesUnsigned_8_Payload = {return config_Base_TypesUnsigned_8_Payload}

  def set_Config_Base_TypesUnsigned_8_Payload(config: Config_Base_TypesUnsigned_8_Payload): Unit ={
    config_Base_TypesUnsigned_8_Payload = config
  }

  // ============= Base_Types.Unsigned_16_Payload ===================
  def alwaysTrue_Base_TypesUnsigned_16_Payload(v: Base_Types.Unsigned_16_Payload): B = {return T}

  var config_Base_TypesUnsigned_16_Payload: Config_Base_TypesUnsigned_16_Payload = Config_Base_TypesUnsigned_16_Payload(alwaysTrue_Base_TypesUnsigned_16_Payload _)

  def get_Config_Base_TypesUnsigned_16_Payload: Config_Base_TypesUnsigned_16_Payload = {return config_Base_TypesUnsigned_16_Payload}

  def set_Config_Base_TypesUnsigned_16_Payload(config: Config_Base_TypesUnsigned_16_Payload): Unit ={
    config_Base_TypesUnsigned_16_Payload = config
  }

  // ============= Base_Types.Unsigned_32_Payload ===================
  def alwaysTrue_Base_TypesUnsigned_32_Payload(v: Base_Types.Unsigned_32_Payload): B = {return T}

  var config_Base_TypesUnsigned_32_Payload: Config_Base_TypesUnsigned_32_Payload = Config_Base_TypesUnsigned_32_Payload(alwaysTrue_Base_TypesUnsigned_32_Payload _)

  def get_Config_Base_TypesUnsigned_32_Payload: Config_Base_TypesUnsigned_32_Payload = {return config_Base_TypesUnsigned_32_Payload}

  def set_Config_Base_TypesUnsigned_32_Payload(config: Config_Base_TypesUnsigned_32_Payload): Unit ={
    config_Base_TypesUnsigned_32_Payload = config
  }

  // ============= Base_Types.Unsigned_64_Payload ===================
  def alwaysTrue_Base_TypesUnsigned_64_Payload(v: Base_Types.Unsigned_64_Payload): B = {return T}

  var config_Base_TypesUnsigned_64_Payload: Config_Base_TypesUnsigned_64_Payload = Config_Base_TypesUnsigned_64_Payload(alwaysTrue_Base_TypesUnsigned_64_Payload _)

  def get_Config_Base_TypesUnsigned_64_Payload: Config_Base_TypesUnsigned_64_Payload = {return config_Base_TypesUnsigned_64_Payload}

  def set_Config_Base_TypesUnsigned_64_Payload(config: Config_Base_TypesUnsigned_64_Payload): Unit ={
    config_Base_TypesUnsigned_64_Payload = config
  }

  // ============= Base_Types.Float_Payload ===================
  def alwaysTrue_Base_TypesFloat_Payload(v: Base_Types.Float_Payload): B = {return T}

  var config_Base_TypesFloat_Payload: Config_Base_TypesFloat_Payload = Config_Base_TypesFloat_Payload(alwaysTrue_Base_TypesFloat_Payload _)

  def get_Config_Base_TypesFloat_Payload: Config_Base_TypesFloat_Payload = {return config_Base_TypesFloat_Payload}

  def set_Config_Base_TypesFloat_Payload(config: Config_Base_TypesFloat_Payload): Unit ={
    config_Base_TypesFloat_Payload = config
  }

  // ============= Base_Types.Float_32_Payload ===================
  def alwaysTrue_Base_TypesFloat_32_Payload(v: Base_Types.Float_32_Payload): B = {return T}

  var config_Base_TypesFloat_32_Payload: Config_Base_TypesFloat_32_Payload = Config_Base_TypesFloat_32_Payload(alwaysTrue_Base_TypesFloat_32_Payload _)

  def get_Config_Base_TypesFloat_32_Payload: Config_Base_TypesFloat_32_Payload = {return config_Base_TypesFloat_32_Payload}

  def set_Config_Base_TypesFloat_32_Payload(config: Config_Base_TypesFloat_32_Payload): Unit ={
    config_Base_TypesFloat_32_Payload = config
  }

  // ============= Base_Types.Float_64_Payload ===================
  def alwaysTrue_Base_TypesFloat_64_Payload(v: Base_Types.Float_64_Payload): B = {return T}

  var config_Base_TypesFloat_64_Payload: Config_Base_TypesFloat_64_Payload = Config_Base_TypesFloat_64_Payload(alwaysTrue_Base_TypesFloat_64_Payload _)

  def get_Config_Base_TypesFloat_64_Payload: Config_Base_TypesFloat_64_Payload = {return config_Base_TypesFloat_64_Payload}

  def set_Config_Base_TypesFloat_64_Payload(config: Config_Base_TypesFloat_64_Payload): Unit ={
    config_Base_TypesFloat_64_Payload = config
  }

  // ============= Base_Types.Character_Payload ===================
  def alwaysTrue_Base_TypesCharacter_Payload(v: Base_Types.Character_Payload): B = {return T}

  var config_Base_TypesCharacter_Payload: Config_Base_TypesCharacter_Payload = Config_Base_TypesCharacter_Payload(alwaysTrue_Base_TypesCharacter_Payload _)

  def get_Config_Base_TypesCharacter_Payload: Config_Base_TypesCharacter_Payload = {return config_Base_TypesCharacter_Payload}

  def set_Config_Base_TypesCharacter_Payload(config: Config_Base_TypesCharacter_Payload): Unit ={
    config_Base_TypesCharacter_Payload = config
  }

  // ============= Base_Types.String_Payload ===================
  def alwaysTrue_Base_TypesString_Payload(v: Base_Types.String_Payload): B = {return T}

  var config_Base_TypesString_Payload: Config_Base_TypesString_Payload = Config_Base_TypesString_Payload(alwaysTrue_Base_TypesString_Payload _)

  def get_Config_Base_TypesString_Payload: Config_Base_TypesString_Payload = {return config_Base_TypesString_Payload}

  def set_Config_Base_TypesString_Payload(config: Config_Base_TypesString_Payload): Unit ={
    config_Base_TypesString_Payload = config
  }

  // ============= Base_Types.Bits_Payload ===================
  def alwaysTrue_Base_TypesBits_Payload(v: Base_Types.Bits_Payload): B = {return T}

  var config_Base_TypesBits_Payload: Config_Base_TypesBits_Payload = Config_Base_TypesBits_Payload(alwaysTrue_Base_TypesBits_Payload _)

  def get_Config_Base_TypesBits_Payload: Config_Base_TypesBits_Payload = {return config_Base_TypesBits_Payload}

  def set_Config_Base_TypesBits_Payload(config: Config_Base_TypesBits_Payload): Unit ={
    config_Base_TypesBits_Payload = config
  }

  // ============= art.Empty ===================
  def alwaysTrue_artEmpty(v: art.Empty): B = {return T}

  var config_artEmpty: Config_artEmpty = Config_artEmpty(alwaysTrue_artEmpty _)

  def get_Config_artEmpty: Config_artEmpty = {return config_artEmpty}

  def set_Config_artEmpty(config: Config_artEmpty): Unit ={
    config_artEmpty = config
  }

  // ============= BuildingControl.FanAck.Type ===================
  def alwaysTrue_BuildingControlFanAckType(v: BuildingControl.FanAck.Type): B = {return T}

  var config_BuildingControlFanAckType: Config_BuildingControlFanAckType = Config_BuildingControlFanAckType(alwaysTrue_BuildingControlFanAckType _)

  def get_Config_BuildingControlFanAckType: Config_BuildingControlFanAckType = {return config_BuildingControlFanAckType}

  def set_Config_BuildingControlFanAckType(config: Config_BuildingControlFanAckType): Unit ={
    config_BuildingControlFanAckType = config
  }

  // ============= BuildingControl.FanCmd.Type ===================
  def alwaysTrue_BuildingControlFanCmdType(v: BuildingControl.FanCmd.Type): B = {return T}

  var config_BuildingControlFanCmdType: Config_BuildingControlFanCmdType = Config_BuildingControlFanCmdType(alwaysTrue_BuildingControlFanCmdType _)

  def get_Config_BuildingControlFanCmdType: Config_BuildingControlFanCmdType = {return config_BuildingControlFanCmdType}

  def set_Config_BuildingControlFanCmdType(config: Config_BuildingControlFanCmdType): Unit ={
    config_BuildingControlFanCmdType = config
  }

  // ============= BuildingControl.FanCmd_Payload ===================
  def alwaysTrue_BuildingControlFanCmd_Payload(v: BuildingControl.FanCmd_Payload): B = {return T}

  var config_BuildingControlFanCmd_Payload: Config_BuildingControlFanCmd_Payload = Config_BuildingControlFanCmd_Payload(alwaysTrue_BuildingControlFanCmd_Payload _)

  def get_Config_BuildingControlFanCmd_Payload: Config_BuildingControlFanCmd_Payload = {return config_BuildingControlFanCmd_Payload}

  def set_Config_BuildingControlFanCmd_Payload(config: Config_BuildingControlFanCmd_Payload): Unit ={
    config_BuildingControlFanCmd_Payload = config
  }

  // ============= BuildingControl.FanAck_Payload ===================
  def alwaysTrue_BuildingControlFanAck_Payload(v: BuildingControl.FanAck_Payload): B = {return T}

  var config_BuildingControlFanAck_Payload: Config_BuildingControlFanAck_Payload = Config_BuildingControlFanAck_Payload(alwaysTrue_BuildingControlFanAck_Payload _)

  def get_Config_BuildingControlFanAck_Payload: Config_BuildingControlFanAck_Payload = {return config_BuildingControlFanAck_Payload}

  def set_Config_BuildingControlFanAck_Payload(config: Config_BuildingControlFanAck_Payload): Unit ={
    config_BuildingControlFanAck_Payload = config
  }

  // ============= BuildingControl.TempUnit.Type ===================
  def alwaysTrue_BuildingControlTempUnitType(v: BuildingControl.TempUnit.Type): B = {return T}

  var config_BuildingControlTempUnitType: Config_BuildingControlTempUnitType = Config_BuildingControlTempUnitType(alwaysTrue_BuildingControlTempUnitType _)

  def get_Config_BuildingControlTempUnitType: Config_BuildingControlTempUnitType = {return config_BuildingControlTempUnitType}

  def set_Config_BuildingControlTempUnitType(config: Config_BuildingControlTempUnitType): Unit ={
    config_BuildingControlTempUnitType = config
  }

  // ============= BuildingControl.TempUnit_Payload ===================
  def alwaysTrue_BuildingControlTempUnit_Payload(v: BuildingControl.TempUnit_Payload): B = {return T}

  var config_BuildingControlTempUnit_Payload: Config_BuildingControlTempUnit_Payload = Config_BuildingControlTempUnit_Payload(alwaysTrue_BuildingControlTempUnit_Payload _)

  def get_Config_BuildingControlTempUnit_Payload: Config_BuildingControlTempUnit_Payload = {return config_BuildingControlTempUnit_Payload}

  def set_Config_BuildingControlTempUnit_Payload(config: Config_BuildingControlTempUnit_Payload): Unit ={
    config_BuildingControlTempUnit_Payload = config
  }

  // ============= BuildingControl.SetPoint_impl ===================
  def alwaysTrue_BuildingControlSetPoint_impl(v: BuildingControl.SetPoint_impl): B = {return T}

  var config_BuildingControlSetPoint_impl: Config_BuildingControlSetPoint_impl = Config_BuildingControlSetPoint_impl(alwaysTrue_BuildingControlSetPoint_impl _)

  def get_Config_BuildingControlSetPoint_impl: Config_BuildingControlSetPoint_impl = {return config_BuildingControlSetPoint_impl}

  def set_Config_BuildingControlSetPoint_impl(config: Config_BuildingControlSetPoint_impl): Unit ={
    config_BuildingControlSetPoint_impl = config
  }

  // ============= BuildingControl.SetPoint_impl_Payload ===================
  def alwaysTrue_BuildingControlSetPoint_impl_Payload(v: BuildingControl.SetPoint_impl_Payload): B = {return T}

  var config_BuildingControlSetPoint_impl_Payload: Config_BuildingControlSetPoint_impl_Payload = Config_BuildingControlSetPoint_impl_Payload(alwaysTrue_BuildingControlSetPoint_impl_Payload _)

  def get_Config_BuildingControlSetPoint_impl_Payload: Config_BuildingControlSetPoint_impl_Payload = {return config_BuildingControlSetPoint_impl_Payload}

  def set_Config_BuildingControlSetPoint_impl_Payload(config: Config_BuildingControlSetPoint_impl_Payload): Unit ={
    config_BuildingControlSetPoint_impl_Payload = config
  }

  // ============= BuildingControl.Temperature_impl ===================
  def alwaysTrue_BuildingControlTemperature_impl(v: BuildingControl.Temperature_impl): B = {return T}

  var config_BuildingControlTemperature_impl: Config_BuildingControlTemperature_impl = Config_BuildingControlTemperature_impl(alwaysTrue_BuildingControlTemperature_impl _)

  def get_Config_BuildingControlTemperature_impl: Config_BuildingControlTemperature_impl = {return config_BuildingControlTemperature_impl}

  def set_Config_BuildingControlTemperature_impl(config: Config_BuildingControlTemperature_impl): Unit ={
    config_BuildingControlTemperature_impl = config
  }

  // ============= BuildingControl.Temperature_impl_Payload ===================
  def alwaysTrue_BuildingControlTemperature_impl_Payload(v: BuildingControl.Temperature_impl_Payload): B = {return T}

  var config_BuildingControlTemperature_impl_Payload: Config_BuildingControlTemperature_impl_Payload = Config_BuildingControlTemperature_impl_Payload(alwaysTrue_BuildingControlTemperature_impl_Payload _)

  def get_Config_BuildingControlTemperature_impl_Payload: Config_BuildingControlTemperature_impl_Payload = {return config_BuildingControlTemperature_impl_Payload}

  def set_Config_BuildingControlTemperature_impl_Payload(config: Config_BuildingControlTemperature_impl_Payload): Unit ={
    config_BuildingControlTemperature_impl_Payload = config
  }
}

