// #Sireum
// @formatter:off

// This file is auto-generated from Container_i.scala, Base_Types.scala, Producer_p_producer__Containers.scala, Filter_p_p_filterp__Containers.scala, Filter_s_p_filters__Containers.scala, Consumer_p_consumer__Containers.scala, DataContent.scala, Aux_Types.scala

package prod_cons__JVM

import org.sireum._
import org.sireum.Json.Printer._

object JSON {

  object Printer {

    @pure def printProdConsFlowsContainer_i(o: ProdConsFlows.Container_i): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Container_i""""),
        ("value", printZ(o.value))
      ))
    }

    @pure def printProdConsFlowsContainer_i_Payload(o: ProdConsFlows.Container_i_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Container_i_Payload""""),
        ("value", printProdConsFlowsContainer_i(o.value))
      ))
    }

    @pure def printBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Boolean_Payload""""),
        ("value", printB(o.value))
      ))
    }

    @pure def printBase_TypesInteger_Payload(o: Base_Types.Integer_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_Payload""""),
        ("value", printZ(o.value))
      ))
    }

    @pure def printBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_8_Payload""""),
        ("value", printS8(o.value))
      ))
    }

    @pure def printBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_16_Payload""""),
        ("value", printS16(o.value))
      ))
    }

    @pure def printBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_32_Payload""""),
        ("value", printS32(o.value))
      ))
    }

    @pure def printBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Integer_64_Payload""""),
        ("value", printS64(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_8_Payload""""),
        ("value", printU8(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_16_Payload""""),
        ("value", printU16(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_32_Payload""""),
        ("value", printU32(o.value))
      ))
    }

    @pure def printBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Unsigned_64_Payload""""),
        ("value", printU64(o.value))
      ))
    }

    @pure def printBase_TypesFloat_Payload(o: Base_Types.Float_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Float_Payload""""),
        ("value", printR(o.value))
      ))
    }

    @pure def printBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Float_32_Payload""""),
        ("value", printF32(o.value))
      ))
    }

    @pure def printBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Float_64_Payload""""),
        ("value", printF64(o.value))
      ))
    }

    @pure def printBase_TypesCharacter_Payload(o: Base_Types.Character_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Character_Payload""""),
        ("value", printC(o.value))
      ))
    }

    @pure def printBase_TypesString_Payload(o: Base_Types.String_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.String_Payload""""),
        ("value", printString(o.value))
      ))
    }

    @pure def printBase_TypesBits_Payload(o: Base_Types.Bits_Payload): ST = {
      return printObject(ISZ(
        ("type", st""""Base_Types.Bits_Payload""""),
        ("value", printISZ(T, o.value, printB _))
      ))
    }

    @pure def printProdConsFlowsProducer_p_producer_PreState_Container(o: ProdConsFlows.Producer_p_producer_PreState_Container): ST = {
      o match {
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_P => return printProdConsFlowsProducer_p_producer_PreState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_PS => return printProdConsFlowsProducer_p_producer_PreState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsProducer_p_producer_PreState_Container_P(o: ProdConsFlows.Producer_p_producer_PreState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Producer_p_producer_PreState_Container_P"""")
      ))
    }

    @pure def printProdConsFlowsProducer_p_producer_PreState_Container_PS(o: ProdConsFlows.Producer_p_producer_PreState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Producer_p_producer_PreState_Container_PS"""")
      ))
    }

    @pure def printProdConsFlowsProducer_p_producer_PostState_Container(o: ProdConsFlows.Producer_p_producer_PostState_Container): ST = {
      o match {
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_P => return printProdConsFlowsProducer_p_producer_PostState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_PS => return printProdConsFlowsProducer_p_producer_PostState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsProducer_p_producer_PostState_Container_P(o: ProdConsFlows.Producer_p_producer_PostState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Producer_p_producer_PostState_Container_P""""),
        ("api_d_event_out", printOption(F, o.api_d_event_out, print_artEmpty _)),
        ("api_b_event_data_out", printOption(F, o.api_b_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_c_event_data_out", printOption(F, o.api_c_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_a_data_out", printProdConsFlowsContainer_i(o.api_a_data_out))
      ))
    }

    @pure def printProdConsFlowsProducer_p_producer_PostState_Container_PS(o: ProdConsFlows.Producer_p_producer_PostState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Producer_p_producer_PostState_Container_PS""""),
        ("api_d_event_out", printOption(F, o.api_d_event_out, print_artEmpty _)),
        ("api_b_event_data_out", printOption(F, o.api_b_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_c_event_data_out", printOption(F, o.api_c_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_a_data_out", printProdConsFlowsContainer_i(o.api_a_data_out))
      ))
    }

    @pure def printProdConsFlowsFilter_p_p_filterp_PreState_Container(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container): ST = {
      o match {
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P => return printProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS => return printProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_p_p_filterp_PreState_Container_P""""),
        ("api_d_event_in", printOption(F, o.api_d_event_in, print_artEmpty _)),
        ("api_b_event_data_in", printOption(F, o.api_b_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_c_event_data_in", printOption(F, o.api_c_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_a_data_in", printProdConsFlowsContainer_i(o.api_a_data_in))
      ))
    }

    @pure def printProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS""""),
        ("api_d_event_in", printOption(F, o.api_d_event_in, print_artEmpty _)),
        ("api_b_event_data_in", printOption(F, o.api_b_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_c_event_data_in", printOption(F, o.api_c_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_a_data_in", printProdConsFlowsContainer_i(o.api_a_data_in))
      ))
    }

    @pure def printProdConsFlowsFilter_p_p_filterp_PostState_Container(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container): ST = {
      o match {
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P => return printProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS => return printProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_p_p_filterp_PostState_Container_P""""),
        ("api_h_event_out", printOption(F, o.api_h_event_out, print_artEmpty _)),
        ("api_f_event_data_out", printOption(F, o.api_f_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_g_event_data_out", printOption(F, o.api_g_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_e_data_out", printProdConsFlowsContainer_i(o.api_e_data_out))
      ))
    }

    @pure def printProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS""""),
        ("api_h_event_out", printOption(F, o.api_h_event_out, print_artEmpty _)),
        ("api_f_event_data_out", printOption(F, o.api_f_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_g_event_data_out", printOption(F, o.api_g_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_e_data_out", printProdConsFlowsContainer_i(o.api_e_data_out))
      ))
    }

    @pure def printProdConsFlowsFilter_s_p_filters_PreState_Container(o: ProdConsFlows.Filter_s_p_filters_PreState_Container): ST = {
      o match {
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P => return printProdConsFlowsFilter_s_p_filters_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS => return printProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsFilter_s_p_filters_PreState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_s_p_filters_PreState_Container_P""""),
        ("api_d_event_in", printOption(F, o.api_d_event_in, print_artEmpty _)),
        ("api_b_event_data_in", printOption(F, o.api_b_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_c_event_data_in", printOption(F, o.api_c_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_a_data_in", printProdConsFlowsContainer_i(o.api_a_data_in))
      ))
    }

    @pure def printProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_s_p_filters_PreState_Container_PS""""),
        ("api_d_event_in", printOption(F, o.api_d_event_in, print_artEmpty _)),
        ("api_b_event_data_in", printOption(F, o.api_b_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_c_event_data_in", printOption(F, o.api_c_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_a_data_in", printProdConsFlowsContainer_i(o.api_a_data_in))
      ))
    }

    @pure def printProdConsFlowsFilter_s_p_filters_PostState_Container(o: ProdConsFlows.Filter_s_p_filters_PostState_Container): ST = {
      o match {
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P => return printProdConsFlowsFilter_s_p_filters_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS => return printProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsFilter_s_p_filters_PostState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_s_p_filters_PostState_Container_P""""),
        ("api_h_event_out", printOption(F, o.api_h_event_out, print_artEmpty _)),
        ("api_f_event_data_out", printOption(F, o.api_f_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_g_event_data_out", printOption(F, o.api_g_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_e_data_out", printProdConsFlowsContainer_i(o.api_e_data_out))
      ))
    }

    @pure def printProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Filter_s_p_filters_PostState_Container_PS""""),
        ("api_h_event_out", printOption(F, o.api_h_event_out, print_artEmpty _)),
        ("api_f_event_data_out", printOption(F, o.api_f_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_g_event_data_out", printOption(F, o.api_g_event_data_out, printProdConsFlowsContainer_i _)),
        ("api_e_data_out", printProdConsFlowsContainer_i(o.api_e_data_out))
      ))
    }

    @pure def printProdConsFlowsConsumer_p_consumer_PreState_Container(o: ProdConsFlows.Consumer_p_consumer_PreState_Container): ST = {
      o match {
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P => return printProdConsFlowsConsumer_p_consumer_PreState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS => return printProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsConsumer_p_consumer_PreState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Consumer_p_consumer_PreState_Container_P""""),
        ("api_h_event_in", printOption(F, o.api_h_event_in, print_artEmpty _)),
        ("api_f_event_data_in", printOption(F, o.api_f_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_g_event_data_in", printOption(F, o.api_g_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_e_data_in", printProdConsFlowsContainer_i(o.api_e_data_in))
      ))
    }

    @pure def printProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Consumer_p_consumer_PreState_Container_PS""""),
        ("api_h_event_in", printOption(F, o.api_h_event_in, print_artEmpty _)),
        ("api_f_event_data_in", printOption(F, o.api_f_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_g_event_data_in", printOption(F, o.api_g_event_data_in, printProdConsFlowsContainer_i _)),
        ("api_e_data_in", printProdConsFlowsContainer_i(o.api_e_data_in))
      ))
    }

    @pure def printProdConsFlowsConsumer_p_consumer_PostState_Container(o: ProdConsFlows.Consumer_p_consumer_PostState_Container): ST = {
      o match {
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P => return printProdConsFlowsConsumer_p_consumer_PostState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS => return printProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o)
      }
    }

    @pure def printProdConsFlowsConsumer_p_consumer_PostState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Consumer_p_consumer_PostState_Container_P"""")
      ))
    }

    @pure def printProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS): ST = {
      return printObject(ISZ(
        ("type", st""""ProdConsFlows.Consumer_p_consumer_PostState_Container_PS"""")
      ))
    }

    @pure def print_artDataContent(o: art.DataContent): ST = {
      o match {
        case o: art.Empty => return print_artEmpty(o)
        case o: Base_Types.Boolean_Payload => return printBase_TypesBoolean_Payload(o)
        case o: Base_Types.Integer_Payload => return printBase_TypesInteger_Payload(o)
        case o: Base_Types.Integer_8_Payload => return printBase_TypesInteger_8_Payload(o)
        case o: Base_Types.Integer_16_Payload => return printBase_TypesInteger_16_Payload(o)
        case o: Base_Types.Integer_32_Payload => return printBase_TypesInteger_32_Payload(o)
        case o: Base_Types.Integer_64_Payload => return printBase_TypesInteger_64_Payload(o)
        case o: Base_Types.Unsigned_8_Payload => return printBase_TypesUnsigned_8_Payload(o)
        case o: Base_Types.Unsigned_16_Payload => return printBase_TypesUnsigned_16_Payload(o)
        case o: Base_Types.Unsigned_32_Payload => return printBase_TypesUnsigned_32_Payload(o)
        case o: Base_Types.Unsigned_64_Payload => return printBase_TypesUnsigned_64_Payload(o)
        case o: Base_Types.Float_Payload => return printBase_TypesFloat_Payload(o)
        case o: Base_Types.Float_32_Payload => return printBase_TypesFloat_32_Payload(o)
        case o: Base_Types.Float_64_Payload => return printBase_TypesFloat_64_Payload(o)
        case o: Base_Types.Character_Payload => return printBase_TypesCharacter_Payload(o)
        case o: Base_Types.String_Payload => return printBase_TypesString_Payload(o)
        case o: Base_Types.Bits_Payload => return printBase_TypesBits_Payload(o)
        case o: ProdConsFlows.Container_i_Payload => return printProdConsFlowsContainer_i_Payload(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P => return printProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P => return printProdConsFlowsFilter_s_p_filters_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS => return printProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS => return printProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P => return printProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P => return printProdConsFlowsFilter_s_p_filters_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS => return printProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS => return printProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_P => return printProdConsFlowsProducer_p_producer_PreState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_PS => return printProdConsFlowsProducer_p_producer_PreState_Container_PS(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P => return printProdConsFlowsConsumer_p_consumer_PreState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS => return printProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_P => return printProdConsFlowsProducer_p_producer_PostState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_PS => return printProdConsFlowsProducer_p_producer_PostState_Container_PS(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P => return printProdConsFlowsConsumer_p_consumer_PostState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS => return printProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o)
      }
    }

    @pure def print_artEmpty(o: art.Empty): ST = {
      return printObject(ISZ(
        ("type", st""""art.Empty"""")
      ))
    }

  }

  @record class Parser(val input: String) {
    val parser: Json.Parser = Json.Parser.create(input)

    def errorOpt: Option[Json.ErrorMsg] = {
      return parser.errorOpt
    }

    def parseProdConsFlowsContainer_i(): ProdConsFlows.Container_i = {
      val r = parseProdConsFlowsContainer_iT(F)
      return r
    }

    def parseProdConsFlowsContainer_iT(typeParsed: B): ProdConsFlows.Container_i = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Container_i")
      }
      parser.parseObjectKey("value")
      val value = parser.parseZ()
      parser.parseObjectNext()
      return ProdConsFlows.Container_i(value)
    }

    def parseProdConsFlowsContainer_i_Payload(): ProdConsFlows.Container_i_Payload = {
      val r = parseProdConsFlowsContainer_i_PayloadT(F)
      return r
    }

    def parseProdConsFlowsContainer_i_PayloadT(typeParsed: B): ProdConsFlows.Container_i_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Container_i_Payload")
      }
      parser.parseObjectKey("value")
      val value = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Container_i_Payload(value)
    }

    def parseBase_TypesBoolean_Payload(): Base_Types.Boolean_Payload = {
      val r = parseBase_TypesBoolean_PayloadT(F)
      return r
    }

    def parseBase_TypesBoolean_PayloadT(typeParsed: B): Base_Types.Boolean_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Boolean_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseB()
      parser.parseObjectNext()
      return Base_Types.Boolean_Payload(value)
    }

    def parseBase_TypesInteger_Payload(): Base_Types.Integer_Payload = {
      val r = parseBase_TypesInteger_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_PayloadT(typeParsed: B): Base_Types.Integer_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseZ()
      parser.parseObjectNext()
      return Base_Types.Integer_Payload(value)
    }

    def parseBase_TypesInteger_8_Payload(): Base_Types.Integer_8_Payload = {
      val r = parseBase_TypesInteger_8_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_8_PayloadT(typeParsed: B): Base_Types.Integer_8_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_8_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS8()
      parser.parseObjectNext()
      return Base_Types.Integer_8_Payload(value)
    }

    def parseBase_TypesInteger_16_Payload(): Base_Types.Integer_16_Payload = {
      val r = parseBase_TypesInteger_16_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_16_PayloadT(typeParsed: B): Base_Types.Integer_16_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_16_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS16()
      parser.parseObjectNext()
      return Base_Types.Integer_16_Payload(value)
    }

    def parseBase_TypesInteger_32_Payload(): Base_Types.Integer_32_Payload = {
      val r = parseBase_TypesInteger_32_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_32_PayloadT(typeParsed: B): Base_Types.Integer_32_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_32_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS32()
      parser.parseObjectNext()
      return Base_Types.Integer_32_Payload(value)
    }

    def parseBase_TypesInteger_64_Payload(): Base_Types.Integer_64_Payload = {
      val r = parseBase_TypesInteger_64_PayloadT(F)
      return r
    }

    def parseBase_TypesInteger_64_PayloadT(typeParsed: B): Base_Types.Integer_64_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Integer_64_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseS64()
      parser.parseObjectNext()
      return Base_Types.Integer_64_Payload(value)
    }

    def parseBase_TypesUnsigned_8_Payload(): Base_Types.Unsigned_8_Payload = {
      val r = parseBase_TypesUnsigned_8_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_8_PayloadT(typeParsed: B): Base_Types.Unsigned_8_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_8_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU8()
      parser.parseObjectNext()
      return Base_Types.Unsigned_8_Payload(value)
    }

    def parseBase_TypesUnsigned_16_Payload(): Base_Types.Unsigned_16_Payload = {
      val r = parseBase_TypesUnsigned_16_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_16_PayloadT(typeParsed: B): Base_Types.Unsigned_16_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_16_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU16()
      parser.parseObjectNext()
      return Base_Types.Unsigned_16_Payload(value)
    }

    def parseBase_TypesUnsigned_32_Payload(): Base_Types.Unsigned_32_Payload = {
      val r = parseBase_TypesUnsigned_32_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_32_PayloadT(typeParsed: B): Base_Types.Unsigned_32_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_32_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU32()
      parser.parseObjectNext()
      return Base_Types.Unsigned_32_Payload(value)
    }

    def parseBase_TypesUnsigned_64_Payload(): Base_Types.Unsigned_64_Payload = {
      val r = parseBase_TypesUnsigned_64_PayloadT(F)
      return r
    }

    def parseBase_TypesUnsigned_64_PayloadT(typeParsed: B): Base_Types.Unsigned_64_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Unsigned_64_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseU64()
      parser.parseObjectNext()
      return Base_Types.Unsigned_64_Payload(value)
    }

    def parseBase_TypesFloat_Payload(): Base_Types.Float_Payload = {
      val r = parseBase_TypesFloat_PayloadT(F)
      return r
    }

    def parseBase_TypesFloat_PayloadT(typeParsed: B): Base_Types.Float_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Float_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseR()
      parser.parseObjectNext()
      return Base_Types.Float_Payload(value)
    }

    def parseBase_TypesFloat_32_Payload(): Base_Types.Float_32_Payload = {
      val r = parseBase_TypesFloat_32_PayloadT(F)
      return r
    }

    def parseBase_TypesFloat_32_PayloadT(typeParsed: B): Base_Types.Float_32_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Float_32_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseF32()
      parser.parseObjectNext()
      return Base_Types.Float_32_Payload(value)
    }

    def parseBase_TypesFloat_64_Payload(): Base_Types.Float_64_Payload = {
      val r = parseBase_TypesFloat_64_PayloadT(F)
      return r
    }

    def parseBase_TypesFloat_64_PayloadT(typeParsed: B): Base_Types.Float_64_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Float_64_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseF64()
      parser.parseObjectNext()
      return Base_Types.Float_64_Payload(value)
    }

    def parseBase_TypesCharacter_Payload(): Base_Types.Character_Payload = {
      val r = parseBase_TypesCharacter_PayloadT(F)
      return r
    }

    def parseBase_TypesCharacter_PayloadT(typeParsed: B): Base_Types.Character_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Character_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseC()
      parser.parseObjectNext()
      return Base_Types.Character_Payload(value)
    }

    def parseBase_TypesString_Payload(): Base_Types.String_Payload = {
      val r = parseBase_TypesString_PayloadT(F)
      return r
    }

    def parseBase_TypesString_PayloadT(typeParsed: B): Base_Types.String_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.String_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseString()
      parser.parseObjectNext()
      return Base_Types.String_Payload(value)
    }

    def parseBase_TypesBits_Payload(): Base_Types.Bits_Payload = {
      val r = parseBase_TypesBits_PayloadT(F)
      return r
    }

    def parseBase_TypesBits_PayloadT(typeParsed: B): Base_Types.Bits_Payload = {
      if (!typeParsed) {
        parser.parseObjectType("Base_Types.Bits_Payload")
      }
      parser.parseObjectKey("value")
      val value = parser.parseISZ(parser.parseB _)
      parser.parseObjectNext()
      return Base_Types.Bits_Payload(value)
    }

    def parseProdConsFlowsProducer_p_producer_PreState_Container(): ProdConsFlows.Producer_p_producer_PreState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Producer_p_producer_PreState_Container_P", "ProdConsFlows.Producer_p_producer_PreState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Producer_p_producer_PreState_Container_P" => val r = parseProdConsFlowsProducer_p_producer_PreState_Container_PT(T); return r
        case "ProdConsFlows.Producer_p_producer_PreState_Container_PS" => val r = parseProdConsFlowsProducer_p_producer_PreState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsProducer_p_producer_PreState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsProducer_p_producer_PreState_Container_P(): ProdConsFlows.Producer_p_producer_PreState_Container_P = {
      val r = parseProdConsFlowsProducer_p_producer_PreState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsProducer_p_producer_PreState_Container_PT(typeParsed: B): ProdConsFlows.Producer_p_producer_PreState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Producer_p_producer_PreState_Container_P")
      }
      return ProdConsFlows.Producer_p_producer_PreState_Container_P()
    }

    def parseProdConsFlowsProducer_p_producer_PreState_Container_PS(): ProdConsFlows.Producer_p_producer_PreState_Container_PS = {
      val r = parseProdConsFlowsProducer_p_producer_PreState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsProducer_p_producer_PreState_Container_PST(typeParsed: B): ProdConsFlows.Producer_p_producer_PreState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Producer_p_producer_PreState_Container_PS")
      }
      return ProdConsFlows.Producer_p_producer_PreState_Container_PS()
    }

    def parseProdConsFlowsProducer_p_producer_PostState_Container(): ProdConsFlows.Producer_p_producer_PostState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Producer_p_producer_PostState_Container_P", "ProdConsFlows.Producer_p_producer_PostState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Producer_p_producer_PostState_Container_P" => val r = parseProdConsFlowsProducer_p_producer_PostState_Container_PT(T); return r
        case "ProdConsFlows.Producer_p_producer_PostState_Container_PS" => val r = parseProdConsFlowsProducer_p_producer_PostState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsProducer_p_producer_PostState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsProducer_p_producer_PostState_Container_P(): ProdConsFlows.Producer_p_producer_PostState_Container_P = {
      val r = parseProdConsFlowsProducer_p_producer_PostState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsProducer_p_producer_PostState_Container_PT(typeParsed: B): ProdConsFlows.Producer_p_producer_PostState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Producer_p_producer_PostState_Container_P")
      }
      parser.parseObjectKey("api_d_event_out")
      val api_d_event_out = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_b_event_data_out")
      val api_b_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_c_event_data_out")
      val api_c_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_a_data_out")
      val api_a_data_out = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Producer_p_producer_PostState_Container_P(api_d_event_out, api_b_event_data_out, api_c_event_data_out, api_a_data_out)
    }

    def parseProdConsFlowsProducer_p_producer_PostState_Container_PS(): ProdConsFlows.Producer_p_producer_PostState_Container_PS = {
      val r = parseProdConsFlowsProducer_p_producer_PostState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsProducer_p_producer_PostState_Container_PST(typeParsed: B): ProdConsFlows.Producer_p_producer_PostState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Producer_p_producer_PostState_Container_PS")
      }
      parser.parseObjectKey("api_d_event_out")
      val api_d_event_out = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_b_event_data_out")
      val api_b_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_c_event_data_out")
      val api_c_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_a_data_out")
      val api_a_data_out = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Producer_p_producer_PostState_Container_PS(api_d_event_out, api_b_event_data_out, api_c_event_data_out, api_a_data_out)
    }

    def parseProdConsFlowsFilter_p_p_filterp_PreState_Container(): ProdConsFlows.Filter_p_p_filterp_PreState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Filter_p_p_filterp_PreState_Container_P", "ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Filter_p_p_filterp_PreState_Container_P" => val r = parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(T); return r
        case "ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS" => val r = parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsFilter_p_p_filterp_PreState_Container_P(): ProdConsFlows.Filter_p_p_filterp_PreState_Container_P = {
      val r = parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PreState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_p_p_filterp_PreState_Container_P")
      }
      parser.parseObjectKey("api_d_event_in")
      val api_d_event_in = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_b_event_data_in")
      val api_b_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_c_event_data_in")
      val api_c_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_a_data_in")
      val api_a_data_in = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_p_p_filterp_PreState_Container_P(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(): ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS = {
      val r = parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS")
      }
      parser.parseObjectKey("api_d_event_in")
      val api_d_event_in = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_b_event_data_in")
      val api_b_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_c_event_data_in")
      val api_c_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_a_data_in")
      val api_a_data_in = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def parseProdConsFlowsFilter_p_p_filterp_PostState_Container(): ProdConsFlows.Filter_p_p_filterp_PostState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Filter_p_p_filterp_PostState_Container_P", "ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Filter_p_p_filterp_PostState_Container_P" => val r = parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(T); return r
        case "ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS" => val r = parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsFilter_p_p_filterp_PostState_Container_P(): ProdConsFlows.Filter_p_p_filterp_PostState_Container_P = {
      val r = parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PostState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_p_p_filterp_PostState_Container_P")
      }
      parser.parseObjectKey("api_h_event_out")
      val api_h_event_out = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_f_event_data_out")
      val api_f_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_g_event_data_out")
      val api_g_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_e_data_out")
      val api_e_data_out = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_p_p_filterp_PostState_Container_P(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(): ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS = {
      val r = parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS")
      }
      parser.parseObjectKey("api_h_event_out")
      val api_h_event_out = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_f_event_data_out")
      val api_f_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_g_event_data_out")
      val api_g_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_e_data_out")
      val api_e_data_out = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def parseProdConsFlowsFilter_s_p_filters_PreState_Container(): ProdConsFlows.Filter_s_p_filters_PreState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Filter_s_p_filters_PreState_Container_P", "ProdConsFlows.Filter_s_p_filters_PreState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Filter_s_p_filters_PreState_Container_P" => val r = parseProdConsFlowsFilter_s_p_filters_PreState_Container_PT(T); return r
        case "ProdConsFlows.Filter_s_p_filters_PreState_Container_PS" => val r = parseProdConsFlowsFilter_s_p_filters_PreState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsFilter_s_p_filters_PreState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsFilter_s_p_filters_PreState_Container_P(): ProdConsFlows.Filter_s_p_filters_PreState_Container_P = {
      val r = parseProdConsFlowsFilter_s_p_filters_PreState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsFilter_s_p_filters_PreState_Container_PT(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PreState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_s_p_filters_PreState_Container_P")
      }
      parser.parseObjectKey("api_d_event_in")
      val api_d_event_in = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_b_event_data_in")
      val api_b_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_c_event_data_in")
      val api_c_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_a_data_in")
      val api_a_data_in = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_s_p_filters_PreState_Container_P(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def parseProdConsFlowsFilter_s_p_filters_PreState_Container_PS(): ProdConsFlows.Filter_s_p_filters_PreState_Container_PS = {
      val r = parseProdConsFlowsFilter_s_p_filters_PreState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsFilter_s_p_filters_PreState_Container_PST(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PreState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_s_p_filters_PreState_Container_PS")
      }
      parser.parseObjectKey("api_d_event_in")
      val api_d_event_in = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_b_event_data_in")
      val api_b_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_c_event_data_in")
      val api_c_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_a_data_in")
      val api_a_data_in = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_s_p_filters_PreState_Container_PS(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def parseProdConsFlowsFilter_s_p_filters_PostState_Container(): ProdConsFlows.Filter_s_p_filters_PostState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Filter_s_p_filters_PostState_Container_P", "ProdConsFlows.Filter_s_p_filters_PostState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Filter_s_p_filters_PostState_Container_P" => val r = parseProdConsFlowsFilter_s_p_filters_PostState_Container_PT(T); return r
        case "ProdConsFlows.Filter_s_p_filters_PostState_Container_PS" => val r = parseProdConsFlowsFilter_s_p_filters_PostState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsFilter_s_p_filters_PostState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsFilter_s_p_filters_PostState_Container_P(): ProdConsFlows.Filter_s_p_filters_PostState_Container_P = {
      val r = parseProdConsFlowsFilter_s_p_filters_PostState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsFilter_s_p_filters_PostState_Container_PT(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PostState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_s_p_filters_PostState_Container_P")
      }
      parser.parseObjectKey("api_h_event_out")
      val api_h_event_out = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_f_event_data_out")
      val api_f_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_g_event_data_out")
      val api_g_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_e_data_out")
      val api_e_data_out = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_s_p_filters_PostState_Container_P(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def parseProdConsFlowsFilter_s_p_filters_PostState_Container_PS(): ProdConsFlows.Filter_s_p_filters_PostState_Container_PS = {
      val r = parseProdConsFlowsFilter_s_p_filters_PostState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsFilter_s_p_filters_PostState_Container_PST(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PostState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Filter_s_p_filters_PostState_Container_PS")
      }
      parser.parseObjectKey("api_h_event_out")
      val api_h_event_out = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_f_event_data_out")
      val api_f_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_g_event_data_out")
      val api_g_event_data_out = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_e_data_out")
      val api_e_data_out = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Filter_s_p_filters_PostState_Container_PS(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def parseProdConsFlowsConsumer_p_consumer_PreState_Container(): ProdConsFlows.Consumer_p_consumer_PreState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Consumer_p_consumer_PreState_Container_P", "ProdConsFlows.Consumer_p_consumer_PreState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Consumer_p_consumer_PreState_Container_P" => val r = parseProdConsFlowsConsumer_p_consumer_PreState_Container_PT(T); return r
        case "ProdConsFlows.Consumer_p_consumer_PreState_Container_PS" => val r = parseProdConsFlowsConsumer_p_consumer_PreState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsConsumer_p_consumer_PreState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsConsumer_p_consumer_PreState_Container_P(): ProdConsFlows.Consumer_p_consumer_PreState_Container_P = {
      val r = parseProdConsFlowsConsumer_p_consumer_PreState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsConsumer_p_consumer_PreState_Container_PT(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PreState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Consumer_p_consumer_PreState_Container_P")
      }
      parser.parseObjectKey("api_h_event_in")
      val api_h_event_in = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_f_event_data_in")
      val api_f_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_g_event_data_in")
      val api_g_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_e_data_in")
      val api_e_data_in = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Consumer_p_consumer_PreState_Container_P(api_h_event_in, api_f_event_data_in, api_g_event_data_in, api_e_data_in)
    }

    def parseProdConsFlowsConsumer_p_consumer_PreState_Container_PS(): ProdConsFlows.Consumer_p_consumer_PreState_Container_PS = {
      val r = parseProdConsFlowsConsumer_p_consumer_PreState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsConsumer_p_consumer_PreState_Container_PST(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PreState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Consumer_p_consumer_PreState_Container_PS")
      }
      parser.parseObjectKey("api_h_event_in")
      val api_h_event_in = parser.parseOption(parse_artEmpty _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_f_event_data_in")
      val api_f_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_g_event_data_in")
      val api_g_event_data_in = parser.parseOption(parseProdConsFlowsContainer_i _)
      parser.parseObjectNext()
      parser.parseObjectKey("api_e_data_in")
      val api_e_data_in = parseProdConsFlowsContainer_i()
      parser.parseObjectNext()
      return ProdConsFlows.Consumer_p_consumer_PreState_Container_PS(api_h_event_in, api_f_event_data_in, api_g_event_data_in, api_e_data_in)
    }

    def parseProdConsFlowsConsumer_p_consumer_PostState_Container(): ProdConsFlows.Consumer_p_consumer_PostState_Container = {
      val t = parser.parseObjectTypes(ISZ("ProdConsFlows.Consumer_p_consumer_PostState_Container_P", "ProdConsFlows.Consumer_p_consumer_PostState_Container_PS"))
      t.native match {
        case "ProdConsFlows.Consumer_p_consumer_PostState_Container_P" => val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PT(T); return r
        case "ProdConsFlows.Consumer_p_consumer_PostState_Container_PS" => val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T); return r
      }
    }

    def parseProdConsFlowsConsumer_p_consumer_PostState_Container_P(): ProdConsFlows.Consumer_p_consumer_PostState_Container_P = {
      val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PT(F)
      return r
    }

    def parseProdConsFlowsConsumer_p_consumer_PostState_Container_PT(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PostState_Container_P = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Consumer_p_consumer_PostState_Container_P")
      }
      return ProdConsFlows.Consumer_p_consumer_PostState_Container_P()
    }

    def parseProdConsFlowsConsumer_p_consumer_PostState_Container_PS(): ProdConsFlows.Consumer_p_consumer_PostState_Container_PS = {
      val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PST(F)
      return r
    }

    def parseProdConsFlowsConsumer_p_consumer_PostState_Container_PST(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PostState_Container_PS = {
      if (!typeParsed) {
        parser.parseObjectType("ProdConsFlows.Consumer_p_consumer_PostState_Container_PS")
      }
      return ProdConsFlows.Consumer_p_consumer_PostState_Container_PS()
    }

    def parse_artDataContent(): art.DataContent = {
      val t = parser.parseObjectTypes(ISZ("art.Empty", "Base_Types.Boolean_Payload", "Base_Types.Integer_Payload", "Base_Types.Integer_8_Payload", "Base_Types.Integer_16_Payload", "Base_Types.Integer_32_Payload", "Base_Types.Integer_64_Payload", "Base_Types.Unsigned_8_Payload", "Base_Types.Unsigned_16_Payload", "Base_Types.Unsigned_32_Payload", "Base_Types.Unsigned_64_Payload", "Base_Types.Float_Payload", "Base_Types.Float_32_Payload", "Base_Types.Float_64_Payload", "Base_Types.Character_Payload", "Base_Types.String_Payload", "Base_Types.Bits_Payload", "ProdConsFlows.Container_i_Payload", "ProdConsFlows.Filter_p_p_filterp_PreState_Container_P", "ProdConsFlows.Filter_s_p_filters_PreState_Container_P", "ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS", "ProdConsFlows.Filter_s_p_filters_PreState_Container_PS", "ProdConsFlows.Filter_p_p_filterp_PostState_Container_P", "ProdConsFlows.Filter_s_p_filters_PostState_Container_P", "ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS", "ProdConsFlows.Filter_s_p_filters_PostState_Container_PS", "ProdConsFlows.Producer_p_producer_PreState_Container_P", "ProdConsFlows.Producer_p_producer_PreState_Container_PS", "ProdConsFlows.Consumer_p_consumer_PreState_Container_P", "ProdConsFlows.Consumer_p_consumer_PreState_Container_PS", "ProdConsFlows.Producer_p_producer_PostState_Container_P", "ProdConsFlows.Producer_p_producer_PostState_Container_PS", "ProdConsFlows.Consumer_p_consumer_PostState_Container_P", "ProdConsFlows.Consumer_p_consumer_PostState_Container_PS"))
      t.native match {
        case "art.Empty" => val r = parse_artEmptyT(T); return r
        case "Base_Types.Boolean_Payload" => val r = parseBase_TypesBoolean_PayloadT(T); return r
        case "Base_Types.Integer_Payload" => val r = parseBase_TypesInteger_PayloadT(T); return r
        case "Base_Types.Integer_8_Payload" => val r = parseBase_TypesInteger_8_PayloadT(T); return r
        case "Base_Types.Integer_16_Payload" => val r = parseBase_TypesInteger_16_PayloadT(T); return r
        case "Base_Types.Integer_32_Payload" => val r = parseBase_TypesInteger_32_PayloadT(T); return r
        case "Base_Types.Integer_64_Payload" => val r = parseBase_TypesInteger_64_PayloadT(T); return r
        case "Base_Types.Unsigned_8_Payload" => val r = parseBase_TypesUnsigned_8_PayloadT(T); return r
        case "Base_Types.Unsigned_16_Payload" => val r = parseBase_TypesUnsigned_16_PayloadT(T); return r
        case "Base_Types.Unsigned_32_Payload" => val r = parseBase_TypesUnsigned_32_PayloadT(T); return r
        case "Base_Types.Unsigned_64_Payload" => val r = parseBase_TypesUnsigned_64_PayloadT(T); return r
        case "Base_Types.Float_Payload" => val r = parseBase_TypesFloat_PayloadT(T); return r
        case "Base_Types.Float_32_Payload" => val r = parseBase_TypesFloat_32_PayloadT(T); return r
        case "Base_Types.Float_64_Payload" => val r = parseBase_TypesFloat_64_PayloadT(T); return r
        case "Base_Types.Character_Payload" => val r = parseBase_TypesCharacter_PayloadT(T); return r
        case "Base_Types.String_Payload" => val r = parseBase_TypesString_PayloadT(T); return r
        case "Base_Types.Bits_Payload" => val r = parseBase_TypesBits_PayloadT(T); return r
        case "ProdConsFlows.Container_i_Payload" => val r = parseProdConsFlowsContainer_i_PayloadT(T); return r
        case "ProdConsFlows.Filter_p_p_filterp_PreState_Container_P" => val r = parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(T); return r
        case "ProdConsFlows.Filter_s_p_filters_PreState_Container_P" => val r = parseProdConsFlowsFilter_s_p_filters_PreState_Container_PT(T); return r
        case "ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS" => val r = parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(T); return r
        case "ProdConsFlows.Filter_s_p_filters_PreState_Container_PS" => val r = parseProdConsFlowsFilter_s_p_filters_PreState_Container_PST(T); return r
        case "ProdConsFlows.Filter_p_p_filterp_PostState_Container_P" => val r = parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(T); return r
        case "ProdConsFlows.Filter_s_p_filters_PostState_Container_P" => val r = parseProdConsFlowsFilter_s_p_filters_PostState_Container_PT(T); return r
        case "ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS" => val r = parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(T); return r
        case "ProdConsFlows.Filter_s_p_filters_PostState_Container_PS" => val r = parseProdConsFlowsFilter_s_p_filters_PostState_Container_PST(T); return r
        case "ProdConsFlows.Producer_p_producer_PreState_Container_P" => val r = parseProdConsFlowsProducer_p_producer_PreState_Container_PT(T); return r
        case "ProdConsFlows.Producer_p_producer_PreState_Container_PS" => val r = parseProdConsFlowsProducer_p_producer_PreState_Container_PST(T); return r
        case "ProdConsFlows.Consumer_p_consumer_PreState_Container_P" => val r = parseProdConsFlowsConsumer_p_consumer_PreState_Container_PT(T); return r
        case "ProdConsFlows.Consumer_p_consumer_PreState_Container_PS" => val r = parseProdConsFlowsConsumer_p_consumer_PreState_Container_PST(T); return r
        case "ProdConsFlows.Producer_p_producer_PostState_Container_P" => val r = parseProdConsFlowsProducer_p_producer_PostState_Container_PT(T); return r
        case "ProdConsFlows.Producer_p_producer_PostState_Container_PS" => val r = parseProdConsFlowsProducer_p_producer_PostState_Container_PST(T); return r
        case "ProdConsFlows.Consumer_p_consumer_PostState_Container_P" => val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PT(T); return r
        case "ProdConsFlows.Consumer_p_consumer_PostState_Container_PS" => val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T); return r
        case _ => val r = parseProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T); return r
      }
    }

    def parse_artEmpty(): art.Empty = {
      val r = parse_artEmptyT(F)
      return r
    }

    def parse_artEmptyT(typeParsed: B): art.Empty = {
      if (!typeParsed) {
        parser.parseObjectType("art.Empty")
      }
      return art.Empty()
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

  def fromProdConsFlowsContainer_i(o: ProdConsFlows.Container_i, isCompact: B): String = {
    val st = Printer.printProdConsFlowsContainer_i(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsContainer_i(s: String): Either[ProdConsFlows.Container_i, Json.ErrorMsg] = {
    def fProdConsFlowsContainer_i(parser: Parser): ProdConsFlows.Container_i = {
      val r = parser.parseProdConsFlowsContainer_i()
      return r
    }
    val r = to(s, fProdConsFlowsContainer_i _)
    return r
  }

  def fromProdConsFlowsContainer_i_Payload(o: ProdConsFlows.Container_i_Payload, isCompact: B): String = {
    val st = Printer.printProdConsFlowsContainer_i_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsContainer_i_Payload(s: String): Either[ProdConsFlows.Container_i_Payload, Json.ErrorMsg] = {
    def fProdConsFlowsContainer_i_Payload(parser: Parser): ProdConsFlows.Container_i_Payload = {
      val r = parser.parseProdConsFlowsContainer_i_Payload()
      return r
    }
    val r = to(s, fProdConsFlowsContainer_i_Payload _)
    return r
  }

  def fromBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesBoolean_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesBoolean_Payload(s: String): Either[Base_Types.Boolean_Payload, Json.ErrorMsg] = {
    def fBase_TypesBoolean_Payload(parser: Parser): Base_Types.Boolean_Payload = {
      val r = parser.parseBase_TypesBoolean_Payload()
      return r
    }
    val r = to(s, fBase_TypesBoolean_Payload _)
    return r
  }

  def fromBase_TypesInteger_Payload(o: Base_Types.Integer_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_Payload(s: String): Either[Base_Types.Integer_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_Payload(parser: Parser): Base_Types.Integer_Payload = {
      val r = parser.parseBase_TypesInteger_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_Payload _)
    return r
  }

  def fromBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_8_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_8_Payload(s: String): Either[Base_Types.Integer_8_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_8_Payload(parser: Parser): Base_Types.Integer_8_Payload = {
      val r = parser.parseBase_TypesInteger_8_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_8_Payload _)
    return r
  }

  def fromBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_16_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_16_Payload(s: String): Either[Base_Types.Integer_16_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_16_Payload(parser: Parser): Base_Types.Integer_16_Payload = {
      val r = parser.parseBase_TypesInteger_16_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_16_Payload _)
    return r
  }

  def fromBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_32_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_32_Payload(s: String): Either[Base_Types.Integer_32_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_32_Payload(parser: Parser): Base_Types.Integer_32_Payload = {
      val r = parser.parseBase_TypesInteger_32_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_32_Payload _)
    return r
  }

  def fromBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesInteger_64_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesInteger_64_Payload(s: String): Either[Base_Types.Integer_64_Payload, Json.ErrorMsg] = {
    def fBase_TypesInteger_64_Payload(parser: Parser): Base_Types.Integer_64_Payload = {
      val r = parser.parseBase_TypesInteger_64_Payload()
      return r
    }
    val r = to(s, fBase_TypesInteger_64_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_8_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_8_Payload(s: String): Either[Base_Types.Unsigned_8_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_8_Payload(parser: Parser): Base_Types.Unsigned_8_Payload = {
      val r = parser.parseBase_TypesUnsigned_8_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_8_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_16_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_16_Payload(s: String): Either[Base_Types.Unsigned_16_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_16_Payload(parser: Parser): Base_Types.Unsigned_16_Payload = {
      val r = parser.parseBase_TypesUnsigned_16_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_16_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_32_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_32_Payload(s: String): Either[Base_Types.Unsigned_32_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_32_Payload(parser: Parser): Base_Types.Unsigned_32_Payload = {
      val r = parser.parseBase_TypesUnsigned_32_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_32_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesUnsigned_64_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesUnsigned_64_Payload(s: String): Either[Base_Types.Unsigned_64_Payload, Json.ErrorMsg] = {
    def fBase_TypesUnsigned_64_Payload(parser: Parser): Base_Types.Unsigned_64_Payload = {
      val r = parser.parseBase_TypesUnsigned_64_Payload()
      return r
    }
    val r = to(s, fBase_TypesUnsigned_64_Payload _)
    return r
  }

  def fromBase_TypesFloat_Payload(o: Base_Types.Float_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesFloat_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesFloat_Payload(s: String): Either[Base_Types.Float_Payload, Json.ErrorMsg] = {
    def fBase_TypesFloat_Payload(parser: Parser): Base_Types.Float_Payload = {
      val r = parser.parseBase_TypesFloat_Payload()
      return r
    }
    val r = to(s, fBase_TypesFloat_Payload _)
    return r
  }

  def fromBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesFloat_32_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesFloat_32_Payload(s: String): Either[Base_Types.Float_32_Payload, Json.ErrorMsg] = {
    def fBase_TypesFloat_32_Payload(parser: Parser): Base_Types.Float_32_Payload = {
      val r = parser.parseBase_TypesFloat_32_Payload()
      return r
    }
    val r = to(s, fBase_TypesFloat_32_Payload _)
    return r
  }

  def fromBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesFloat_64_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesFloat_64_Payload(s: String): Either[Base_Types.Float_64_Payload, Json.ErrorMsg] = {
    def fBase_TypesFloat_64_Payload(parser: Parser): Base_Types.Float_64_Payload = {
      val r = parser.parseBase_TypesFloat_64_Payload()
      return r
    }
    val r = to(s, fBase_TypesFloat_64_Payload _)
    return r
  }

  def fromBase_TypesCharacter_Payload(o: Base_Types.Character_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesCharacter_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesCharacter_Payload(s: String): Either[Base_Types.Character_Payload, Json.ErrorMsg] = {
    def fBase_TypesCharacter_Payload(parser: Parser): Base_Types.Character_Payload = {
      val r = parser.parseBase_TypesCharacter_Payload()
      return r
    }
    val r = to(s, fBase_TypesCharacter_Payload _)
    return r
  }

  def fromBase_TypesString_Payload(o: Base_Types.String_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesString_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesString_Payload(s: String): Either[Base_Types.String_Payload, Json.ErrorMsg] = {
    def fBase_TypesString_Payload(parser: Parser): Base_Types.String_Payload = {
      val r = parser.parseBase_TypesString_Payload()
      return r
    }
    val r = to(s, fBase_TypesString_Payload _)
    return r
  }

  def fromBase_TypesBits_Payload(o: Base_Types.Bits_Payload, isCompact: B): String = {
    val st = Printer.printBase_TypesBits_Payload(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toBase_TypesBits_Payload(s: String): Either[Base_Types.Bits_Payload, Json.ErrorMsg] = {
    def fBase_TypesBits_Payload(parser: Parser): Base_Types.Bits_Payload = {
      val r = parser.parseBase_TypesBits_Payload()
      return r
    }
    val r = to(s, fBase_TypesBits_Payload _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PreState_Container(o: ProdConsFlows.Producer_p_producer_PreState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsProducer_p_producer_PreState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsProducer_p_producer_PreState_Container(s: String): Either[ProdConsFlows.Producer_p_producer_PreState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PreState_Container(parser: Parser): ProdConsFlows.Producer_p_producer_PreState_Container = {
      val r = parser.parseProdConsFlowsProducer_p_producer_PreState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsProducer_p_producer_PreState_Container _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PreState_Container_P(o: ProdConsFlows.Producer_p_producer_PreState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsProducer_p_producer_PreState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsProducer_p_producer_PreState_Container_P(s: String): Either[ProdConsFlows.Producer_p_producer_PreState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PreState_Container_P(parser: Parser): ProdConsFlows.Producer_p_producer_PreState_Container_P = {
      val r = parser.parseProdConsFlowsProducer_p_producer_PreState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsProducer_p_producer_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PreState_Container_PS(o: ProdConsFlows.Producer_p_producer_PreState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsProducer_p_producer_PreState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsProducer_p_producer_PreState_Container_PS(s: String): Either[ProdConsFlows.Producer_p_producer_PreState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PreState_Container_PS(parser: Parser): ProdConsFlows.Producer_p_producer_PreState_Container_PS = {
      val r = parser.parseProdConsFlowsProducer_p_producer_PreState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsProducer_p_producer_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PostState_Container(o: ProdConsFlows.Producer_p_producer_PostState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsProducer_p_producer_PostState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsProducer_p_producer_PostState_Container(s: String): Either[ProdConsFlows.Producer_p_producer_PostState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PostState_Container(parser: Parser): ProdConsFlows.Producer_p_producer_PostState_Container = {
      val r = parser.parseProdConsFlowsProducer_p_producer_PostState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsProducer_p_producer_PostState_Container _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PostState_Container_P(o: ProdConsFlows.Producer_p_producer_PostState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsProducer_p_producer_PostState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsProducer_p_producer_PostState_Container_P(s: String): Either[ProdConsFlows.Producer_p_producer_PostState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PostState_Container_P(parser: Parser): ProdConsFlows.Producer_p_producer_PostState_Container_P = {
      val r = parser.parseProdConsFlowsProducer_p_producer_PostState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsProducer_p_producer_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PostState_Container_PS(o: ProdConsFlows.Producer_p_producer_PostState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsProducer_p_producer_PostState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsProducer_p_producer_PostState_Container_PS(s: String): Either[ProdConsFlows.Producer_p_producer_PostState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PostState_Container_PS(parser: Parser): ProdConsFlows.Producer_p_producer_PostState_Container_PS = {
      val r = parser.parseProdConsFlowsProducer_p_producer_PostState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsProducer_p_producer_PostState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PreState_Container(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_p_p_filterp_PreState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_p_p_filterp_PreState_Container(s: String): Either[ProdConsFlows.Filter_p_p_filterp_PreState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PreState_Container(parser: Parser): ProdConsFlows.Filter_p_p_filterp_PreState_Container = {
      val r = parser.parseProdConsFlowsFilter_p_p_filterp_PreState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_p_p_filterp_PreState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_p_p_filterp_PreState_Container_P(s: String): Either[ProdConsFlows.Filter_p_p_filterp_PreState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PreState_Container_P(parser: Parser): ProdConsFlows.Filter_p_p_filterp_PreState_Container_P = {
      val r = parser.parseProdConsFlowsFilter_p_p_filterp_PreState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_p_p_filterp_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(s: String): Either[ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(parser: Parser): ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS = {
      val r = parser.parseProdConsFlowsFilter_p_p_filterp_PreState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_p_p_filterp_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PostState_Container(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_p_p_filterp_PostState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_p_p_filterp_PostState_Container(s: String): Either[ProdConsFlows.Filter_p_p_filterp_PostState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PostState_Container(parser: Parser): ProdConsFlows.Filter_p_p_filterp_PostState_Container = {
      val r = parser.parseProdConsFlowsFilter_p_p_filterp_PostState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_p_p_filterp_PostState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_p_p_filterp_PostState_Container_P(s: String): Either[ProdConsFlows.Filter_p_p_filterp_PostState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PostState_Container_P(parser: Parser): ProdConsFlows.Filter_p_p_filterp_PostState_Container_P = {
      val r = parser.parseProdConsFlowsFilter_p_p_filterp_PostState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_p_p_filterp_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(s: String): Either[ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(parser: Parser): ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS = {
      val r = parser.parseProdConsFlowsFilter_p_p_filterp_PostState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_p_p_filterp_PostState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PreState_Container(o: ProdConsFlows.Filter_s_p_filters_PreState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_s_p_filters_PreState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_s_p_filters_PreState_Container(s: String): Either[ProdConsFlows.Filter_s_p_filters_PreState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PreState_Container(parser: Parser): ProdConsFlows.Filter_s_p_filters_PreState_Container = {
      val r = parser.parseProdConsFlowsFilter_s_p_filters_PreState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_s_p_filters_PreState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PreState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_s_p_filters_PreState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_s_p_filters_PreState_Container_P(s: String): Either[ProdConsFlows.Filter_s_p_filters_PreState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PreState_Container_P(parser: Parser): ProdConsFlows.Filter_s_p_filters_PreState_Container_P = {
      val r = parser.parseProdConsFlowsFilter_s_p_filters_PreState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_s_p_filters_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_s_p_filters_PreState_Container_PS(s: String): Either[ProdConsFlows.Filter_s_p_filters_PreState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PreState_Container_PS(parser: Parser): ProdConsFlows.Filter_s_p_filters_PreState_Container_PS = {
      val r = parser.parseProdConsFlowsFilter_s_p_filters_PreState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_s_p_filters_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PostState_Container(o: ProdConsFlows.Filter_s_p_filters_PostState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_s_p_filters_PostState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_s_p_filters_PostState_Container(s: String): Either[ProdConsFlows.Filter_s_p_filters_PostState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PostState_Container(parser: Parser): ProdConsFlows.Filter_s_p_filters_PostState_Container = {
      val r = parser.parseProdConsFlowsFilter_s_p_filters_PostState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_s_p_filters_PostState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PostState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_s_p_filters_PostState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_s_p_filters_PostState_Container_P(s: String): Either[ProdConsFlows.Filter_s_p_filters_PostState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PostState_Container_P(parser: Parser): ProdConsFlows.Filter_s_p_filters_PostState_Container_P = {
      val r = parser.parseProdConsFlowsFilter_s_p_filters_PostState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_s_p_filters_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsFilter_s_p_filters_PostState_Container_PS(s: String): Either[ProdConsFlows.Filter_s_p_filters_PostState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PostState_Container_PS(parser: Parser): ProdConsFlows.Filter_s_p_filters_PostState_Container_PS = {
      val r = parser.parseProdConsFlowsFilter_s_p_filters_PostState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsFilter_s_p_filters_PostState_Container_PS _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PreState_Container(o: ProdConsFlows.Consumer_p_consumer_PreState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsConsumer_p_consumer_PreState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsConsumer_p_consumer_PreState_Container(s: String): Either[ProdConsFlows.Consumer_p_consumer_PreState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PreState_Container(parser: Parser): ProdConsFlows.Consumer_p_consumer_PreState_Container = {
      val r = parser.parseProdConsFlowsConsumer_p_consumer_PreState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsConsumer_p_consumer_PreState_Container _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PreState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsConsumer_p_consumer_PreState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsConsumer_p_consumer_PreState_Container_P(s: String): Either[ProdConsFlows.Consumer_p_consumer_PreState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PreState_Container_P(parser: Parser): ProdConsFlows.Consumer_p_consumer_PreState_Container_P = {
      val r = parser.parseProdConsFlowsConsumer_p_consumer_PreState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsConsumer_p_consumer_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsConsumer_p_consumer_PreState_Container_PS(s: String): Either[ProdConsFlows.Consumer_p_consumer_PreState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PreState_Container_PS(parser: Parser): ProdConsFlows.Consumer_p_consumer_PreState_Container_PS = {
      val r = parser.parseProdConsFlowsConsumer_p_consumer_PreState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsConsumer_p_consumer_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PostState_Container(o: ProdConsFlows.Consumer_p_consumer_PostState_Container, isCompact: B): String = {
    val st = Printer.printProdConsFlowsConsumer_p_consumer_PostState_Container(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsConsumer_p_consumer_PostState_Container(s: String): Either[ProdConsFlows.Consumer_p_consumer_PostState_Container, Json.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PostState_Container(parser: Parser): ProdConsFlows.Consumer_p_consumer_PostState_Container = {
      val r = parser.parseProdConsFlowsConsumer_p_consumer_PostState_Container()
      return r
    }
    val r = to(s, fProdConsFlowsConsumer_p_consumer_PostState_Container _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PostState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P, isCompact: B): String = {
    val st = Printer.printProdConsFlowsConsumer_p_consumer_PostState_Container_P(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsConsumer_p_consumer_PostState_Container_P(s: String): Either[ProdConsFlows.Consumer_p_consumer_PostState_Container_P, Json.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PostState_Container_P(parser: Parser): ProdConsFlows.Consumer_p_consumer_PostState_Container_P = {
      val r = parser.parseProdConsFlowsConsumer_p_consumer_PostState_Container_P()
      return r
    }
    val r = to(s, fProdConsFlowsConsumer_p_consumer_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS, isCompact: B): String = {
    val st = Printer.printProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def toProdConsFlowsConsumer_p_consumer_PostState_Container_PS(s: String): Either[ProdConsFlows.Consumer_p_consumer_PostState_Container_PS, Json.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PostState_Container_PS(parser: Parser): ProdConsFlows.Consumer_p_consumer_PostState_Container_PS = {
      val r = parser.parseProdConsFlowsConsumer_p_consumer_PostState_Container_PS()
      return r
    }
    val r = to(s, fProdConsFlowsConsumer_p_consumer_PostState_Container_PS _)
    return r
  }

  def from_artDataContent(o: art.DataContent, isCompact: B): String = {
    val st = Printer.print_artDataContent(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def to_artDataContent(s: String): Either[art.DataContent, Json.ErrorMsg] = {
    def f_artDataContent(parser: Parser): art.DataContent = {
      val r = parser.parse_artDataContent()
      return r
    }
    val r = to(s, f_artDataContent _)
    return r
  }

  def from_artEmpty(o: art.Empty, isCompact: B): String = {
    val st = Printer.print_artEmpty(o)
    if (isCompact) {
      return st.renderCompact
    } else {
      return st.render
    }
  }

  def to_artEmpty(s: String): Either[art.Empty, Json.ErrorMsg] = {
    def f_artEmpty(parser: Parser): art.Empty = {
      val r = parser.parse_artEmpty()
      return r
    }
    val r = to(s, f_artEmpty _)
    return r
  }

}