// #Sireum
// @formatter:off

// This file is auto-generated from Container_i.scala, Base_Types.scala, Producer_p_producer_Containers.scala, Filter_p_p_filterp_Containers.scala, Filter_s_p_filters_Containers.scala, Consumer_p_consumer_Containers.scala, Container.scala, DataContent.scala, Aux_Types.scala

package prod_cons__JVM

import org.sireum._

object MsgPack {

  object Constants {

    val ProdConsFlowsContainer_i: Z = -32

    val ProdConsFlowsContainer_i_Payload: Z = -31

    val Base_TypesBoolean_Payload: Z = -30

    val Base_TypesInteger_Payload: Z = -29

    val Base_TypesInteger_8_Payload: Z = -28

    val Base_TypesInteger_16_Payload: Z = -27

    val Base_TypesInteger_32_Payload: Z = -26

    val Base_TypesInteger_64_Payload: Z = -25

    val Base_TypesUnsigned_8_Payload: Z = -24

    val Base_TypesUnsigned_16_Payload: Z = -23

    val Base_TypesUnsigned_32_Payload: Z = -22

    val Base_TypesUnsigned_64_Payload: Z = -21

    val Base_TypesFloat_Payload: Z = -20

    val Base_TypesFloat_32_Payload: Z = -19

    val Base_TypesFloat_64_Payload: Z = -18

    val Base_TypesCharacter_Payload: Z = -17

    val Base_TypesString_Payload: Z = -16

    val Base_TypesBits_Payload: Z = -15

    val ProdConsFlowsProducer_p_producer_PreState_Container_P: Z = -14

    val ProdConsFlowsProducer_p_producer_PreState_Container_PS: Z = -13

    val ProdConsFlowsProducer_p_producer_PostState_Container_P: Z = -12

    val ProdConsFlowsProducer_p_producer_PostState_Container_PS: Z = -11

    val ProdConsFlowsFilter_p_p_filterp_PreState_Container_P: Z = -10

    val ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS: Z = -9

    val ProdConsFlowsFilter_p_p_filterp_PostState_Container_P: Z = -8

    val ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS: Z = -7

    val ProdConsFlowsFilter_s_p_filters_PreState_Container_P: Z = -6

    val ProdConsFlowsFilter_s_p_filters_PreState_Container_PS: Z = -5

    val ProdConsFlowsFilter_s_p_filters_PostState_Container_P: Z = -4

    val ProdConsFlowsFilter_s_p_filters_PostState_Container_PS: Z = -3

    val ProdConsFlowsConsumer_p_consumer_PreState_Container_P: Z = -2

    val ProdConsFlowsConsumer_p_consumer_PreState_Container_PS: Z = -1

    val ProdConsFlowsConsumer_p_consumer_PostState_Container_P: Z = 0

    val ProdConsFlowsConsumer_p_consumer_PostState_Container_PS: Z = 1

    val utilEmptyContainer: Z = 2

    val _artEmpty: Z = 3

  }

  object Writer {

    @record class Default(val writer: MessagePack.Writer.Impl) extends Writer

  }

  @msig trait Writer {

    def writer: MessagePack.Writer

    def writeProdConsFlowsContainer_i(o: ProdConsFlows.Container_i): Unit = {
      writer.writeZ(Constants.ProdConsFlowsContainer_i)
      writer.writeZ(o.value)
    }

    def writeProdConsFlowsContainer_i_Payload(o: ProdConsFlows.Container_i_Payload): Unit = {
      writer.writeZ(Constants.ProdConsFlowsContainer_i_Payload)
      writeProdConsFlowsContainer_i(o.value)
    }

    def writeBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesBoolean_Payload)
      writer.writeB(o.value)
    }

    def writeBase_TypesInteger_Payload(o: Base_Types.Integer_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_Payload)
      writer.writeZ(o.value)
    }

    def writeBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_8_Payload)
      writer.writeS8(o.value)
    }

    def writeBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_16_Payload)
      writer.writeS16(o.value)
    }

    def writeBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_32_Payload)
      writer.writeS32(o.value)
    }

    def writeBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesInteger_64_Payload)
      writer.writeS64(o.value)
    }

    def writeBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_8_Payload)
      writer.writeU8(o.value)
    }

    def writeBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_16_Payload)
      writer.writeU16(o.value)
    }

    def writeBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_32_Payload)
      writer.writeU32(o.value)
    }

    def writeBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesUnsigned_64_Payload)
      writer.writeU64(o.value)
    }

    def writeBase_TypesFloat_Payload(o: Base_Types.Float_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesFloat_Payload)
      writer.writeR(o.value)
    }

    def writeBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesFloat_32_Payload)
      writer.writeF32(o.value)
    }

    def writeBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesFloat_64_Payload)
      writer.writeF64(o.value)
    }

    def writeBase_TypesCharacter_Payload(o: Base_Types.Character_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesCharacter_Payload)
      writer.writeC(o.value)
    }

    def writeBase_TypesString_Payload(o: Base_Types.String_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesString_Payload)
      writer.writeString(o.value)
    }

    def writeBase_TypesBits_Payload(o: Base_Types.Bits_Payload): Unit = {
      writer.writeZ(Constants.Base_TypesBits_Payload)
      writer.writeISZ(o.value, writer.writeB _)
    }

    def writeProdConsFlowsProducer_p_producer_PreState_Container(o: ProdConsFlows.Producer_p_producer_PreState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_P => writeProdConsFlowsProducer_p_producer_PreState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_PS => writeProdConsFlowsProducer_p_producer_PreState_Container_PS(o)
      }
    }

    def writeProdConsFlowsProducer_p_producer_PreState_Container_P(o: ProdConsFlows.Producer_p_producer_PreState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsProducer_p_producer_PreState_Container_P)
    }

    def writeProdConsFlowsProducer_p_producer_PreState_Container_PS(o: ProdConsFlows.Producer_p_producer_PreState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsProducer_p_producer_PreState_Container_PS)
    }

    def writeProdConsFlowsProducer_p_producer_PostState_Container(o: ProdConsFlows.Producer_p_producer_PostState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_P => writeProdConsFlowsProducer_p_producer_PostState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_PS => writeProdConsFlowsProducer_p_producer_PostState_Container_PS(o)
      }
    }

    def writeProdConsFlowsProducer_p_producer_PostState_Container_P(o: ProdConsFlows.Producer_p_producer_PostState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsProducer_p_producer_PostState_Container_P)
      writer.writeOption(o.api_d_event_out, write_artEmpty _)
      writer.writeOption(o.api_b_event_data_out, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_c_event_data_out, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_a_data_out)
    }

    def writeProdConsFlowsProducer_p_producer_PostState_Container_PS(o: ProdConsFlows.Producer_p_producer_PostState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsProducer_p_producer_PostState_Container_PS)
      writer.writeOption(o.api_d_event_out, write_artEmpty _)
      writer.writeOption(o.api_b_event_data_out, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_c_event_data_out, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_a_data_out)
    }

    def writeProdConsFlowsFilter_p_p_filterp_PreState_Container(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P => writeProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS => writeProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o)
      }
    }

    def writeProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_P)
      writer.writeOption(o.api_d_event_in, write_artEmpty _)
      writer.writeOption(o.api_b_event_data_in, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_c_event_data_in, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_a_data_in)
    }

    def writeProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS)
      writer.writeOption(o.api_d_event_in, write_artEmpty _)
      writer.writeOption(o.api_b_event_data_in, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_c_event_data_in, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_a_data_in)
    }

    def writeProdConsFlowsFilter_p_p_filterp_PostState_Container(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P => writeProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS => writeProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o)
      }
    }

    def writeProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_P)
      writer.writeOption(o.api_h_event_out, write_artEmpty _)
      writer.writeOption(o.api_f_event_data_out, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_g_event_data_out, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_e_data_out)
    }

    def writeProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS)
      writer.writeOption(o.api_h_event_out, write_artEmpty _)
      writer.writeOption(o.api_f_event_data_out, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_g_event_data_out, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_e_data_out)
    }

    def writeProdConsFlowsFilter_s_p_filters_PreState_Container(o: ProdConsFlows.Filter_s_p_filters_PreState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P => writeProdConsFlowsFilter_s_p_filters_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS => writeProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o)
      }
    }

    def writeProdConsFlowsFilter_s_p_filters_PreState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_P)
      writer.writeOption(o.api_d_event_in, write_artEmpty _)
      writer.writeOption(o.api_b_event_data_in, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_c_event_data_in, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_a_data_in)
    }

    def writeProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_PS)
      writer.writeOption(o.api_d_event_in, write_artEmpty _)
      writer.writeOption(o.api_b_event_data_in, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_c_event_data_in, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_a_data_in)
    }

    def writeProdConsFlowsFilter_s_p_filters_PostState_Container(o: ProdConsFlows.Filter_s_p_filters_PostState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P => writeProdConsFlowsFilter_s_p_filters_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS => writeProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o)
      }
    }

    def writeProdConsFlowsFilter_s_p_filters_PostState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_P)
      writer.writeOption(o.api_h_event_out, write_artEmpty _)
      writer.writeOption(o.api_f_event_data_out, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_g_event_data_out, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_e_data_out)
    }

    def writeProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_PS)
      writer.writeOption(o.api_h_event_out, write_artEmpty _)
      writer.writeOption(o.api_f_event_data_out, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_g_event_data_out, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_e_data_out)
    }

    def writeProdConsFlowsConsumer_p_consumer_PreState_Container(o: ProdConsFlows.Consumer_p_consumer_PreState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P => writeProdConsFlowsConsumer_p_consumer_PreState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS => writeProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o)
      }
    }

    def writeProdConsFlowsConsumer_p_consumer_PreState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_P)
      writer.writeOption(o.api_h_event_in, write_artEmpty _)
      writer.writeOption(o.api_f_event_data_in, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_g_event_data_in, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_e_data_in)
    }

    def writeProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_PS)
      writer.writeOption(o.api_h_event_in, write_artEmpty _)
      writer.writeOption(o.api_f_event_data_in, writeProdConsFlowsContainer_i _)
      writer.writeOption(o.api_g_event_data_in, writeProdConsFlowsContainer_i _)
      writeProdConsFlowsContainer_i(o.api_e_data_in)
    }

    def writeProdConsFlowsConsumer_p_consumer_PostState_Container(o: ProdConsFlows.Consumer_p_consumer_PostState_Container): Unit = {
      o match {
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P => writeProdConsFlowsConsumer_p_consumer_PostState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS => writeProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o)
      }
    }

    def writeProdConsFlowsConsumer_p_consumer_PostState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P): Unit = {
      writer.writeZ(Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_P)
    }

    def writeProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS): Unit = {
      writer.writeZ(Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_PS)
    }

    def writeutilContainer(o: util.Container): Unit = {
      o match {
        case o: util.EmptyContainer => writeutilEmptyContainer(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P => writeProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P => writeProdConsFlowsFilter_s_p_filters_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS => writeProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS => writeProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P => writeProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P => writeProdConsFlowsFilter_s_p_filters_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS => writeProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS => writeProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_P => writeProdConsFlowsProducer_p_producer_PreState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_PS => writeProdConsFlowsProducer_p_producer_PreState_Container_PS(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P => writeProdConsFlowsConsumer_p_consumer_PreState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS => writeProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_P => writeProdConsFlowsProducer_p_producer_PostState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_PS => writeProdConsFlowsProducer_p_producer_PostState_Container_PS(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P => writeProdConsFlowsConsumer_p_consumer_PostState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS => writeProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o)
      }
    }

    def writeutilEmptyContainer(o: util.EmptyContainer): Unit = {
      writer.writeZ(Constants.utilEmptyContainer)
    }

    def write_artDataContent(o: art.DataContent): Unit = {
      o match {
        case o: art.Empty => write_artEmpty(o)
        case o: Base_Types.Boolean_Payload => writeBase_TypesBoolean_Payload(o)
        case o: Base_Types.Integer_Payload => writeBase_TypesInteger_Payload(o)
        case o: Base_Types.Integer_8_Payload => writeBase_TypesInteger_8_Payload(o)
        case o: Base_Types.Integer_16_Payload => writeBase_TypesInteger_16_Payload(o)
        case o: Base_Types.Integer_32_Payload => writeBase_TypesInteger_32_Payload(o)
        case o: Base_Types.Integer_64_Payload => writeBase_TypesInteger_64_Payload(o)
        case o: Base_Types.Unsigned_8_Payload => writeBase_TypesUnsigned_8_Payload(o)
        case o: Base_Types.Unsigned_16_Payload => writeBase_TypesUnsigned_16_Payload(o)
        case o: Base_Types.Unsigned_32_Payload => writeBase_TypesUnsigned_32_Payload(o)
        case o: Base_Types.Unsigned_64_Payload => writeBase_TypesUnsigned_64_Payload(o)
        case o: Base_Types.Float_Payload => writeBase_TypesFloat_Payload(o)
        case o: Base_Types.Float_32_Payload => writeBase_TypesFloat_32_Payload(o)
        case o: Base_Types.Float_64_Payload => writeBase_TypesFloat_64_Payload(o)
        case o: Base_Types.Character_Payload => writeBase_TypesCharacter_Payload(o)
        case o: Base_Types.String_Payload => writeBase_TypesString_Payload(o)
        case o: Base_Types.Bits_Payload => writeBase_TypesBits_Payload(o)
        case o: util.EmptyContainer => writeutilEmptyContainer(o)
        case o: ProdConsFlows.Container_i_Payload => writeProdConsFlowsContainer_i_Payload(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P => writeProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P => writeProdConsFlowsFilter_s_p_filters_PreState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS => writeProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o)
        case o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS => writeProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P => writeProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P => writeProdConsFlowsFilter_s_p_filters_PostState_Container_P(o)
        case o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS => writeProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o)
        case o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS => writeProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_P => writeProdConsFlowsProducer_p_producer_PreState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PreState_Container_PS => writeProdConsFlowsProducer_p_producer_PreState_Container_PS(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P => writeProdConsFlowsConsumer_p_consumer_PreState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS => writeProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_P => writeProdConsFlowsProducer_p_producer_PostState_Container_P(o)
        case o: ProdConsFlows.Producer_p_producer_PostState_Container_PS => writeProdConsFlowsProducer_p_producer_PostState_Container_PS(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P => writeProdConsFlowsConsumer_p_consumer_PostState_Container_P(o)
        case o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS => writeProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o)
      }
    }

    def write_artEmpty(o: art.Empty): Unit = {
      writer.writeZ(Constants._artEmpty)
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

    def readProdConsFlowsContainer_i(): ProdConsFlows.Container_i = {
      val r = readProdConsFlowsContainer_iT(F)
      return r
    }

    def readProdConsFlowsContainer_iT(typeParsed: B): ProdConsFlows.Container_i = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsContainer_i)
      }
      val value = reader.readZ()
      return ProdConsFlows.Container_i(value)
    }

    def readProdConsFlowsContainer_i_Payload(): ProdConsFlows.Container_i_Payload = {
      val r = readProdConsFlowsContainer_i_PayloadT(F)
      return r
    }

    def readProdConsFlowsContainer_i_PayloadT(typeParsed: B): ProdConsFlows.Container_i_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsContainer_i_Payload)
      }
      val value = readProdConsFlowsContainer_i()
      return ProdConsFlows.Container_i_Payload(value)
    }

    def readBase_TypesBoolean_Payload(): Base_Types.Boolean_Payload = {
      val r = readBase_TypesBoolean_PayloadT(F)
      return r
    }

    def readBase_TypesBoolean_PayloadT(typeParsed: B): Base_Types.Boolean_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesBoolean_Payload)
      }
      val value = reader.readB()
      return Base_Types.Boolean_Payload(value)
    }

    def readBase_TypesInteger_Payload(): Base_Types.Integer_Payload = {
      val r = readBase_TypesInteger_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_PayloadT(typeParsed: B): Base_Types.Integer_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_Payload)
      }
      val value = reader.readZ()
      return Base_Types.Integer_Payload(value)
    }

    def readBase_TypesInteger_8_Payload(): Base_Types.Integer_8_Payload = {
      val r = readBase_TypesInteger_8_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_8_PayloadT(typeParsed: B): Base_Types.Integer_8_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_8_Payload)
      }
      val value = reader.readS8()
      return Base_Types.Integer_8_Payload(value)
    }

    def readBase_TypesInteger_16_Payload(): Base_Types.Integer_16_Payload = {
      val r = readBase_TypesInteger_16_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_16_PayloadT(typeParsed: B): Base_Types.Integer_16_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_16_Payload)
      }
      val value = reader.readS16()
      return Base_Types.Integer_16_Payload(value)
    }

    def readBase_TypesInteger_32_Payload(): Base_Types.Integer_32_Payload = {
      val r = readBase_TypesInteger_32_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_32_PayloadT(typeParsed: B): Base_Types.Integer_32_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_32_Payload)
      }
      val value = reader.readS32()
      return Base_Types.Integer_32_Payload(value)
    }

    def readBase_TypesInteger_64_Payload(): Base_Types.Integer_64_Payload = {
      val r = readBase_TypesInteger_64_PayloadT(F)
      return r
    }

    def readBase_TypesInteger_64_PayloadT(typeParsed: B): Base_Types.Integer_64_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesInteger_64_Payload)
      }
      val value = reader.readS64()
      return Base_Types.Integer_64_Payload(value)
    }

    def readBase_TypesUnsigned_8_Payload(): Base_Types.Unsigned_8_Payload = {
      val r = readBase_TypesUnsigned_8_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_8_PayloadT(typeParsed: B): Base_Types.Unsigned_8_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_8_Payload)
      }
      val value = reader.readU8()
      return Base_Types.Unsigned_8_Payload(value)
    }

    def readBase_TypesUnsigned_16_Payload(): Base_Types.Unsigned_16_Payload = {
      val r = readBase_TypesUnsigned_16_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_16_PayloadT(typeParsed: B): Base_Types.Unsigned_16_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_16_Payload)
      }
      val value = reader.readU16()
      return Base_Types.Unsigned_16_Payload(value)
    }

    def readBase_TypesUnsigned_32_Payload(): Base_Types.Unsigned_32_Payload = {
      val r = readBase_TypesUnsigned_32_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_32_PayloadT(typeParsed: B): Base_Types.Unsigned_32_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_32_Payload)
      }
      val value = reader.readU32()
      return Base_Types.Unsigned_32_Payload(value)
    }

    def readBase_TypesUnsigned_64_Payload(): Base_Types.Unsigned_64_Payload = {
      val r = readBase_TypesUnsigned_64_PayloadT(F)
      return r
    }

    def readBase_TypesUnsigned_64_PayloadT(typeParsed: B): Base_Types.Unsigned_64_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesUnsigned_64_Payload)
      }
      val value = reader.readU64()
      return Base_Types.Unsigned_64_Payload(value)
    }

    def readBase_TypesFloat_Payload(): Base_Types.Float_Payload = {
      val r = readBase_TypesFloat_PayloadT(F)
      return r
    }

    def readBase_TypesFloat_PayloadT(typeParsed: B): Base_Types.Float_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesFloat_Payload)
      }
      val value = reader.readR()
      return Base_Types.Float_Payload(value)
    }

    def readBase_TypesFloat_32_Payload(): Base_Types.Float_32_Payload = {
      val r = readBase_TypesFloat_32_PayloadT(F)
      return r
    }

    def readBase_TypesFloat_32_PayloadT(typeParsed: B): Base_Types.Float_32_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesFloat_32_Payload)
      }
      val value = reader.readF32()
      return Base_Types.Float_32_Payload(value)
    }

    def readBase_TypesFloat_64_Payload(): Base_Types.Float_64_Payload = {
      val r = readBase_TypesFloat_64_PayloadT(F)
      return r
    }

    def readBase_TypesFloat_64_PayloadT(typeParsed: B): Base_Types.Float_64_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesFloat_64_Payload)
      }
      val value = reader.readF64()
      return Base_Types.Float_64_Payload(value)
    }

    def readBase_TypesCharacter_Payload(): Base_Types.Character_Payload = {
      val r = readBase_TypesCharacter_PayloadT(F)
      return r
    }

    def readBase_TypesCharacter_PayloadT(typeParsed: B): Base_Types.Character_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesCharacter_Payload)
      }
      val value = reader.readC()
      return Base_Types.Character_Payload(value)
    }

    def readBase_TypesString_Payload(): Base_Types.String_Payload = {
      val r = readBase_TypesString_PayloadT(F)
      return r
    }

    def readBase_TypesString_PayloadT(typeParsed: B): Base_Types.String_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesString_Payload)
      }
      val value = reader.readString()
      return Base_Types.String_Payload(value)
    }

    def readBase_TypesBits_Payload(): Base_Types.Bits_Payload = {
      val r = readBase_TypesBits_PayloadT(F)
      return r
    }

    def readBase_TypesBits_PayloadT(typeParsed: B): Base_Types.Bits_Payload = {
      if (!typeParsed) {
        reader.expectZ(Constants.Base_TypesBits_Payload)
      }
      val value = reader.readISZ(reader.readB _)
      return Base_Types.Bits_Payload(value)
    }

    def readProdConsFlowsProducer_p_producer_PreState_Container(): ProdConsFlows.Producer_p_producer_PreState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsProducer_p_producer_PreState_Container_P => val r = readProdConsFlowsProducer_p_producer_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PreState_Container_PS => val r = readProdConsFlowsProducer_p_producer_PreState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Producer_p_producer_PreState_Container.")
          val r = readProdConsFlowsProducer_p_producer_PreState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsProducer_p_producer_PreState_Container_P(): ProdConsFlows.Producer_p_producer_PreState_Container_P = {
      val r = readProdConsFlowsProducer_p_producer_PreState_Container_PT(F)
      return r
    }

    def readProdConsFlowsProducer_p_producer_PreState_Container_PT(typeParsed: B): ProdConsFlows.Producer_p_producer_PreState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsProducer_p_producer_PreState_Container_P)
      }
      return ProdConsFlows.Producer_p_producer_PreState_Container_P()
    }

    def readProdConsFlowsProducer_p_producer_PreState_Container_PS(): ProdConsFlows.Producer_p_producer_PreState_Container_PS = {
      val r = readProdConsFlowsProducer_p_producer_PreState_Container_PST(F)
      return r
    }

    def readProdConsFlowsProducer_p_producer_PreState_Container_PST(typeParsed: B): ProdConsFlows.Producer_p_producer_PreState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsProducer_p_producer_PreState_Container_PS)
      }
      return ProdConsFlows.Producer_p_producer_PreState_Container_PS()
    }

    def readProdConsFlowsProducer_p_producer_PostState_Container(): ProdConsFlows.Producer_p_producer_PostState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsProducer_p_producer_PostState_Container_P => val r = readProdConsFlowsProducer_p_producer_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PostState_Container_PS => val r = readProdConsFlowsProducer_p_producer_PostState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Producer_p_producer_PostState_Container.")
          val r = readProdConsFlowsProducer_p_producer_PostState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsProducer_p_producer_PostState_Container_P(): ProdConsFlows.Producer_p_producer_PostState_Container_P = {
      val r = readProdConsFlowsProducer_p_producer_PostState_Container_PT(F)
      return r
    }

    def readProdConsFlowsProducer_p_producer_PostState_Container_PT(typeParsed: B): ProdConsFlows.Producer_p_producer_PostState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsProducer_p_producer_PostState_Container_P)
      }
      val api_d_event_out = reader.readOption(read_artEmpty _)
      val api_b_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_c_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_a_data_out = readProdConsFlowsContainer_i()
      return ProdConsFlows.Producer_p_producer_PostState_Container_P(api_d_event_out, api_b_event_data_out, api_c_event_data_out, api_a_data_out)
    }

    def readProdConsFlowsProducer_p_producer_PostState_Container_PS(): ProdConsFlows.Producer_p_producer_PostState_Container_PS = {
      val r = readProdConsFlowsProducer_p_producer_PostState_Container_PST(F)
      return r
    }

    def readProdConsFlowsProducer_p_producer_PostState_Container_PST(typeParsed: B): ProdConsFlows.Producer_p_producer_PostState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsProducer_p_producer_PostState_Container_PS)
      }
      val api_d_event_out = reader.readOption(read_artEmpty _)
      val api_b_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_c_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_a_data_out = readProdConsFlowsContainer_i()
      return ProdConsFlows.Producer_p_producer_PostState_Container_PS(api_d_event_out, api_b_event_data_out, api_c_event_data_out, api_a_data_out)
    }

    def readProdConsFlowsFilter_p_p_filterp_PreState_Container(): ProdConsFlows.Filter_p_p_filterp_PreState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_P => val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS => val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Filter_p_p_filterp_PreState_Container.")
          val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsFilter_p_p_filterp_PreState_Container_P(): ProdConsFlows.Filter_p_p_filterp_PreState_Container_P = {
      val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(F)
      return r
    }

    def readProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PreState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_P)
      }
      val api_d_event_in = reader.readOption(read_artEmpty _)
      val api_b_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_c_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_a_data_in = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_p_p_filterp_PreState_Container_P(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def readProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(): ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS = {
      val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(F)
      return r
    }

    def readProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS)
      }
      val api_d_event_in = reader.readOption(read_artEmpty _)
      val api_b_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_c_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_a_data_in = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def readProdConsFlowsFilter_p_p_filterp_PostState_Container(): ProdConsFlows.Filter_p_p_filterp_PostState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_P => val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS => val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Filter_p_p_filterp_PostState_Container.")
          val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsFilter_p_p_filterp_PostState_Container_P(): ProdConsFlows.Filter_p_p_filterp_PostState_Container_P = {
      val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(F)
      return r
    }

    def readProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PostState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_P)
      }
      val api_h_event_out = reader.readOption(read_artEmpty _)
      val api_f_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_g_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_e_data_out = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_p_p_filterp_PostState_Container_P(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def readProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(): ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS = {
      val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(F)
      return r
    }

    def readProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(typeParsed: B): ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS)
      }
      val api_h_event_out = reader.readOption(read_artEmpty _)
      val api_f_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_g_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_e_data_out = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def readProdConsFlowsFilter_s_p_filters_PreState_Container(): ProdConsFlows.Filter_s_p_filters_PreState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_P => val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_PS => val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Filter_s_p_filters_PreState_Container.")
          val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsFilter_s_p_filters_PreState_Container_P(): ProdConsFlows.Filter_s_p_filters_PreState_Container_P = {
      val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PT(F)
      return r
    }

    def readProdConsFlowsFilter_s_p_filters_PreState_Container_PT(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PreState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_P)
      }
      val api_d_event_in = reader.readOption(read_artEmpty _)
      val api_b_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_c_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_a_data_in = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_s_p_filters_PreState_Container_P(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def readProdConsFlowsFilter_s_p_filters_PreState_Container_PS(): ProdConsFlows.Filter_s_p_filters_PreState_Container_PS = {
      val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PST(F)
      return r
    }

    def readProdConsFlowsFilter_s_p_filters_PreState_Container_PST(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PreState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_PS)
      }
      val api_d_event_in = reader.readOption(read_artEmpty _)
      val api_b_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_c_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_a_data_in = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_s_p_filters_PreState_Container_PS(api_d_event_in, api_b_event_data_in, api_c_event_data_in, api_a_data_in)
    }

    def readProdConsFlowsFilter_s_p_filters_PostState_Container(): ProdConsFlows.Filter_s_p_filters_PostState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_P => val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_PS => val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Filter_s_p_filters_PostState_Container.")
          val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsFilter_s_p_filters_PostState_Container_P(): ProdConsFlows.Filter_s_p_filters_PostState_Container_P = {
      val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PT(F)
      return r
    }

    def readProdConsFlowsFilter_s_p_filters_PostState_Container_PT(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PostState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_P)
      }
      val api_h_event_out = reader.readOption(read_artEmpty _)
      val api_f_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_g_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_e_data_out = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_s_p_filters_PostState_Container_P(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def readProdConsFlowsFilter_s_p_filters_PostState_Container_PS(): ProdConsFlows.Filter_s_p_filters_PostState_Container_PS = {
      val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PST(F)
      return r
    }

    def readProdConsFlowsFilter_s_p_filters_PostState_Container_PST(typeParsed: B): ProdConsFlows.Filter_s_p_filters_PostState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_PS)
      }
      val api_h_event_out = reader.readOption(read_artEmpty _)
      val api_f_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_g_event_data_out = reader.readOption(readProdConsFlowsContainer_i _)
      val api_e_data_out = readProdConsFlowsContainer_i()
      return ProdConsFlows.Filter_s_p_filters_PostState_Container_PS(api_h_event_out, api_f_event_data_out, api_g_event_data_out, api_e_data_out)
    }

    def readProdConsFlowsConsumer_p_consumer_PreState_Container(): ProdConsFlows.Consumer_p_consumer_PreState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_P => val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_PS => val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Consumer_p_consumer_PreState_Container.")
          val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsConsumer_p_consumer_PreState_Container_P(): ProdConsFlows.Consumer_p_consumer_PreState_Container_P = {
      val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PT(F)
      return r
    }

    def readProdConsFlowsConsumer_p_consumer_PreState_Container_PT(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PreState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_P)
      }
      val api_h_event_in = reader.readOption(read_artEmpty _)
      val api_f_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_g_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_e_data_in = readProdConsFlowsContainer_i()
      return ProdConsFlows.Consumer_p_consumer_PreState_Container_P(api_h_event_in, api_f_event_data_in, api_g_event_data_in, api_e_data_in)
    }

    def readProdConsFlowsConsumer_p_consumer_PreState_Container_PS(): ProdConsFlows.Consumer_p_consumer_PreState_Container_PS = {
      val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PST(F)
      return r
    }

    def readProdConsFlowsConsumer_p_consumer_PreState_Container_PST(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PreState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_PS)
      }
      val api_h_event_in = reader.readOption(read_artEmpty _)
      val api_f_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_g_event_data_in = reader.readOption(readProdConsFlowsContainer_i _)
      val api_e_data_in = readProdConsFlowsContainer_i()
      return ProdConsFlows.Consumer_p_consumer_PreState_Container_PS(api_h_event_in, api_f_event_data_in, api_g_event_data_in, api_e_data_in)
    }

    def readProdConsFlowsConsumer_p_consumer_PostState_Container(): ProdConsFlows.Consumer_p_consumer_PostState_Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_P => val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_PS => val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of ProdConsFlows.Consumer_p_consumer_PostState_Container.")
          val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T)
          return r
      }
    }

    def readProdConsFlowsConsumer_p_consumer_PostState_Container_P(): ProdConsFlows.Consumer_p_consumer_PostState_Container_P = {
      val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PT(F)
      return r
    }

    def readProdConsFlowsConsumer_p_consumer_PostState_Container_PT(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PostState_Container_P = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_P)
      }
      return ProdConsFlows.Consumer_p_consumer_PostState_Container_P()
    }

    def readProdConsFlowsConsumer_p_consumer_PostState_Container_PS(): ProdConsFlows.Consumer_p_consumer_PostState_Container_PS = {
      val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(F)
      return r
    }

    def readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(typeParsed: B): ProdConsFlows.Consumer_p_consumer_PostState_Container_PS = {
      if (!typeParsed) {
        reader.expectZ(Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_PS)
      }
      return ProdConsFlows.Consumer_p_consumer_PostState_Container_PS()
    }

    def readutilContainer(): util.Container = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants.utilEmptyContainer => val r = readutilEmptyContainerT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_P => val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_P => val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS => val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_PS => val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_P => val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_P => val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS => val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_PS => val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PST(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PreState_Container_P => val r = readProdConsFlowsProducer_p_producer_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PreState_Container_PS => val r = readProdConsFlowsProducer_p_producer_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_P => val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_PS => val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PostState_Container_P => val r = readProdConsFlowsProducer_p_producer_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PostState_Container_PS => val r = readProdConsFlowsProducer_p_producer_PostState_Container_PST(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_P => val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_PS => val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of util.Container.")
          val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T)
          return r
      }
    }

    def readutilEmptyContainer(): util.EmptyContainer = {
      val r = readutilEmptyContainerT(F)
      return r
    }

    def readutilEmptyContainerT(typeParsed: B): util.EmptyContainer = {
      if (!typeParsed) {
        reader.expectZ(Constants.utilEmptyContainer)
      }
      return util.EmptyContainer()
    }

    def read_artDataContent(): art.DataContent = {
      val i = reader.curr
      val t = reader.readZ()
      t match {
        case Constants._artEmpty => val r = read_artEmptyT(T); return r
        case Constants.Base_TypesBoolean_Payload => val r = readBase_TypesBoolean_PayloadT(T); return r
        case Constants.Base_TypesInteger_Payload => val r = readBase_TypesInteger_PayloadT(T); return r
        case Constants.Base_TypesInteger_8_Payload => val r = readBase_TypesInteger_8_PayloadT(T); return r
        case Constants.Base_TypesInteger_16_Payload => val r = readBase_TypesInteger_16_PayloadT(T); return r
        case Constants.Base_TypesInteger_32_Payload => val r = readBase_TypesInteger_32_PayloadT(T); return r
        case Constants.Base_TypesInteger_64_Payload => val r = readBase_TypesInteger_64_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_8_Payload => val r = readBase_TypesUnsigned_8_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_16_Payload => val r = readBase_TypesUnsigned_16_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_32_Payload => val r = readBase_TypesUnsigned_32_PayloadT(T); return r
        case Constants.Base_TypesUnsigned_64_Payload => val r = readBase_TypesUnsigned_64_PayloadT(T); return r
        case Constants.Base_TypesFloat_Payload => val r = readBase_TypesFloat_PayloadT(T); return r
        case Constants.Base_TypesFloat_32_Payload => val r = readBase_TypesFloat_32_PayloadT(T); return r
        case Constants.Base_TypesFloat_64_Payload => val r = readBase_TypesFloat_64_PayloadT(T); return r
        case Constants.Base_TypesCharacter_Payload => val r = readBase_TypesCharacter_PayloadT(T); return r
        case Constants.Base_TypesString_Payload => val r = readBase_TypesString_PayloadT(T); return r
        case Constants.Base_TypesBits_Payload => val r = readBase_TypesBits_PayloadT(T); return r
        case Constants.utilEmptyContainer => val r = readutilEmptyContainerT(T); return r
        case Constants.ProdConsFlowsContainer_i_Payload => val r = readProdConsFlowsContainer_i_PayloadT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_P => val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_P => val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS => val r = readProdConsFlowsFilter_p_p_filterp_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PreState_Container_PS => val r = readProdConsFlowsFilter_s_p_filters_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_P => val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_P => val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS => val r = readProdConsFlowsFilter_p_p_filterp_PostState_Container_PST(T); return r
        case Constants.ProdConsFlowsFilter_s_p_filters_PostState_Container_PS => val r = readProdConsFlowsFilter_s_p_filters_PostState_Container_PST(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PreState_Container_P => val r = readProdConsFlowsProducer_p_producer_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PreState_Container_PS => val r = readProdConsFlowsProducer_p_producer_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_P => val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PT(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PreState_Container_PS => val r = readProdConsFlowsConsumer_p_consumer_PreState_Container_PST(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PostState_Container_P => val r = readProdConsFlowsProducer_p_producer_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsProducer_p_producer_PostState_Container_PS => val r = readProdConsFlowsProducer_p_producer_PostState_Container_PST(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_P => val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PT(T); return r
        case Constants.ProdConsFlowsConsumer_p_consumer_PostState_Container_PS => val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T); return r
        case _ =>
          reader.error(i, s"$t is not a valid type of art.DataContent.")
          val r = readProdConsFlowsConsumer_p_consumer_PostState_Container_PST(T)
          return r
      }
    }

    def read_artEmpty(): art.Empty = {
      val r = read_artEmptyT(F)
      return r
    }

    def read_artEmptyT(typeParsed: B): art.Empty = {
      if (!typeParsed) {
        reader.expectZ(Constants._artEmpty)
      }
      return art.Empty()
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

  def fromProdConsFlowsContainer_i(o: ProdConsFlows.Container_i, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsContainer_i(o)
    return w.result
  }

  def toProdConsFlowsContainer_i(data: ISZ[U8]): Either[ProdConsFlows.Container_i, MessagePack.ErrorMsg] = {
    def fProdConsFlowsContainer_i(reader: Reader): ProdConsFlows.Container_i = {
      val r = reader.readProdConsFlowsContainer_i()
      return r
    }
    val r = to(data, fProdConsFlowsContainer_i _)
    return r
  }

  def fromProdConsFlowsContainer_i_Payload(o: ProdConsFlows.Container_i_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsContainer_i_Payload(o)
    return w.result
  }

  def toProdConsFlowsContainer_i_Payload(data: ISZ[U8]): Either[ProdConsFlows.Container_i_Payload, MessagePack.ErrorMsg] = {
    def fProdConsFlowsContainer_i_Payload(reader: Reader): ProdConsFlows.Container_i_Payload = {
      val r = reader.readProdConsFlowsContainer_i_Payload()
      return r
    }
    val r = to(data, fProdConsFlowsContainer_i_Payload _)
    return r
  }

  def fromBase_TypesBoolean_Payload(o: Base_Types.Boolean_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesBoolean_Payload(o)
    return w.result
  }

  def toBase_TypesBoolean_Payload(data: ISZ[U8]): Either[Base_Types.Boolean_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesBoolean_Payload(reader: Reader): Base_Types.Boolean_Payload = {
      val r = reader.readBase_TypesBoolean_Payload()
      return r
    }
    val r = to(data, fBase_TypesBoolean_Payload _)
    return r
  }

  def fromBase_TypesInteger_Payload(o: Base_Types.Integer_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_Payload(data: ISZ[U8]): Either[Base_Types.Integer_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_Payload(reader: Reader): Base_Types.Integer_Payload = {
      val r = reader.readBase_TypesInteger_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_Payload _)
    return r
  }

  def fromBase_TypesInteger_8_Payload(o: Base_Types.Integer_8_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_8_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_8_Payload(data: ISZ[U8]): Either[Base_Types.Integer_8_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_8_Payload(reader: Reader): Base_Types.Integer_8_Payload = {
      val r = reader.readBase_TypesInteger_8_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_8_Payload _)
    return r
  }

  def fromBase_TypesInteger_16_Payload(o: Base_Types.Integer_16_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_16_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_16_Payload(data: ISZ[U8]): Either[Base_Types.Integer_16_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_16_Payload(reader: Reader): Base_Types.Integer_16_Payload = {
      val r = reader.readBase_TypesInteger_16_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_16_Payload _)
    return r
  }

  def fromBase_TypesInteger_32_Payload(o: Base_Types.Integer_32_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_32_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_32_Payload(data: ISZ[U8]): Either[Base_Types.Integer_32_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_32_Payload(reader: Reader): Base_Types.Integer_32_Payload = {
      val r = reader.readBase_TypesInteger_32_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_32_Payload _)
    return r
  }

  def fromBase_TypesInteger_64_Payload(o: Base_Types.Integer_64_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesInteger_64_Payload(o)
    return w.result
  }

  def toBase_TypesInteger_64_Payload(data: ISZ[U8]): Either[Base_Types.Integer_64_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesInteger_64_Payload(reader: Reader): Base_Types.Integer_64_Payload = {
      val r = reader.readBase_TypesInteger_64_Payload()
      return r
    }
    val r = to(data, fBase_TypesInteger_64_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_8_Payload(o: Base_Types.Unsigned_8_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_8_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_8_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_8_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_8_Payload(reader: Reader): Base_Types.Unsigned_8_Payload = {
      val r = reader.readBase_TypesUnsigned_8_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_8_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_16_Payload(o: Base_Types.Unsigned_16_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_16_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_16_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_16_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_16_Payload(reader: Reader): Base_Types.Unsigned_16_Payload = {
      val r = reader.readBase_TypesUnsigned_16_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_16_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_32_Payload(o: Base_Types.Unsigned_32_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_32_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_32_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_32_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_32_Payload(reader: Reader): Base_Types.Unsigned_32_Payload = {
      val r = reader.readBase_TypesUnsigned_32_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_32_Payload _)
    return r
  }

  def fromBase_TypesUnsigned_64_Payload(o: Base_Types.Unsigned_64_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesUnsigned_64_Payload(o)
    return w.result
  }

  def toBase_TypesUnsigned_64_Payload(data: ISZ[U8]): Either[Base_Types.Unsigned_64_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesUnsigned_64_Payload(reader: Reader): Base_Types.Unsigned_64_Payload = {
      val r = reader.readBase_TypesUnsigned_64_Payload()
      return r
    }
    val r = to(data, fBase_TypesUnsigned_64_Payload _)
    return r
  }

  def fromBase_TypesFloat_Payload(o: Base_Types.Float_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesFloat_Payload(o)
    return w.result
  }

  def toBase_TypesFloat_Payload(data: ISZ[U8]): Either[Base_Types.Float_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesFloat_Payload(reader: Reader): Base_Types.Float_Payload = {
      val r = reader.readBase_TypesFloat_Payload()
      return r
    }
    val r = to(data, fBase_TypesFloat_Payload _)
    return r
  }

  def fromBase_TypesFloat_32_Payload(o: Base_Types.Float_32_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesFloat_32_Payload(o)
    return w.result
  }

  def toBase_TypesFloat_32_Payload(data: ISZ[U8]): Either[Base_Types.Float_32_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesFloat_32_Payload(reader: Reader): Base_Types.Float_32_Payload = {
      val r = reader.readBase_TypesFloat_32_Payload()
      return r
    }
    val r = to(data, fBase_TypesFloat_32_Payload _)
    return r
  }

  def fromBase_TypesFloat_64_Payload(o: Base_Types.Float_64_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesFloat_64_Payload(o)
    return w.result
  }

  def toBase_TypesFloat_64_Payload(data: ISZ[U8]): Either[Base_Types.Float_64_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesFloat_64_Payload(reader: Reader): Base_Types.Float_64_Payload = {
      val r = reader.readBase_TypesFloat_64_Payload()
      return r
    }
    val r = to(data, fBase_TypesFloat_64_Payload _)
    return r
  }

  def fromBase_TypesCharacter_Payload(o: Base_Types.Character_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesCharacter_Payload(o)
    return w.result
  }

  def toBase_TypesCharacter_Payload(data: ISZ[U8]): Either[Base_Types.Character_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesCharacter_Payload(reader: Reader): Base_Types.Character_Payload = {
      val r = reader.readBase_TypesCharacter_Payload()
      return r
    }
    val r = to(data, fBase_TypesCharacter_Payload _)
    return r
  }

  def fromBase_TypesString_Payload(o: Base_Types.String_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesString_Payload(o)
    return w.result
  }

  def toBase_TypesString_Payload(data: ISZ[U8]): Either[Base_Types.String_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesString_Payload(reader: Reader): Base_Types.String_Payload = {
      val r = reader.readBase_TypesString_Payload()
      return r
    }
    val r = to(data, fBase_TypesString_Payload _)
    return r
  }

  def fromBase_TypesBits_Payload(o: Base_Types.Bits_Payload, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeBase_TypesBits_Payload(o)
    return w.result
  }

  def toBase_TypesBits_Payload(data: ISZ[U8]): Either[Base_Types.Bits_Payload, MessagePack.ErrorMsg] = {
    def fBase_TypesBits_Payload(reader: Reader): Base_Types.Bits_Payload = {
      val r = reader.readBase_TypesBits_Payload()
      return r
    }
    val r = to(data, fBase_TypesBits_Payload _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PreState_Container(o: ProdConsFlows.Producer_p_producer_PreState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsProducer_p_producer_PreState_Container(o)
    return w.result
  }

  def toProdConsFlowsProducer_p_producer_PreState_Container(data: ISZ[U8]): Either[ProdConsFlows.Producer_p_producer_PreState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PreState_Container(reader: Reader): ProdConsFlows.Producer_p_producer_PreState_Container = {
      val r = reader.readProdConsFlowsProducer_p_producer_PreState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsProducer_p_producer_PreState_Container _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PreState_Container_P(o: ProdConsFlows.Producer_p_producer_PreState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsProducer_p_producer_PreState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsProducer_p_producer_PreState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Producer_p_producer_PreState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PreState_Container_P(reader: Reader): ProdConsFlows.Producer_p_producer_PreState_Container_P = {
      val r = reader.readProdConsFlowsProducer_p_producer_PreState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsProducer_p_producer_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PreState_Container_PS(o: ProdConsFlows.Producer_p_producer_PreState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsProducer_p_producer_PreState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsProducer_p_producer_PreState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Producer_p_producer_PreState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PreState_Container_PS(reader: Reader): ProdConsFlows.Producer_p_producer_PreState_Container_PS = {
      val r = reader.readProdConsFlowsProducer_p_producer_PreState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsProducer_p_producer_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PostState_Container(o: ProdConsFlows.Producer_p_producer_PostState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsProducer_p_producer_PostState_Container(o)
    return w.result
  }

  def toProdConsFlowsProducer_p_producer_PostState_Container(data: ISZ[U8]): Either[ProdConsFlows.Producer_p_producer_PostState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PostState_Container(reader: Reader): ProdConsFlows.Producer_p_producer_PostState_Container = {
      val r = reader.readProdConsFlowsProducer_p_producer_PostState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsProducer_p_producer_PostState_Container _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PostState_Container_P(o: ProdConsFlows.Producer_p_producer_PostState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsProducer_p_producer_PostState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsProducer_p_producer_PostState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Producer_p_producer_PostState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PostState_Container_P(reader: Reader): ProdConsFlows.Producer_p_producer_PostState_Container_P = {
      val r = reader.readProdConsFlowsProducer_p_producer_PostState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsProducer_p_producer_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsProducer_p_producer_PostState_Container_PS(o: ProdConsFlows.Producer_p_producer_PostState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsProducer_p_producer_PostState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsProducer_p_producer_PostState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Producer_p_producer_PostState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsProducer_p_producer_PostState_Container_PS(reader: Reader): ProdConsFlows.Producer_p_producer_PostState_Container_PS = {
      val r = reader.readProdConsFlowsProducer_p_producer_PostState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsProducer_p_producer_PostState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PreState_Container(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_p_p_filterp_PreState_Container(o)
    return w.result
  }

  def toProdConsFlowsFilter_p_p_filterp_PreState_Container(data: ISZ[U8]): Either[ProdConsFlows.Filter_p_p_filterp_PreState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PreState_Container(reader: Reader): ProdConsFlows.Filter_p_p_filterp_PreState_Container = {
      val r = reader.readProdConsFlowsFilter_p_p_filterp_PreState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_p_p_filterp_PreState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_p_p_filterp_PreState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsFilter_p_p_filterp_PreState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Filter_p_p_filterp_PreState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PreState_Container_P(reader: Reader): ProdConsFlows.Filter_p_p_filterp_PreState_Container_P = {
      val r = reader.readProdConsFlowsFilter_p_p_filterp_PreState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_p_p_filterp_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PreState_Container_PS(reader: Reader): ProdConsFlows.Filter_p_p_filterp_PreState_Container_PS = {
      val r = reader.readProdConsFlowsFilter_p_p_filterp_PreState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_p_p_filterp_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PostState_Container(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_p_p_filterp_PostState_Container(o)
    return w.result
  }

  def toProdConsFlowsFilter_p_p_filterp_PostState_Container(data: ISZ[U8]): Either[ProdConsFlows.Filter_p_p_filterp_PostState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PostState_Container(reader: Reader): ProdConsFlows.Filter_p_p_filterp_PostState_Container = {
      val r = reader.readProdConsFlowsFilter_p_p_filterp_PostState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_p_p_filterp_PostState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_p_p_filterp_PostState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsFilter_p_p_filterp_PostState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Filter_p_p_filterp_PostState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PostState_Container_P(reader: Reader): ProdConsFlows.Filter_p_p_filterp_PostState_Container_P = {
      val r = reader.readProdConsFlowsFilter_p_p_filterp_PostState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_p_p_filterp_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o: ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_p_p_filterp_PostState_Container_PS(reader: Reader): ProdConsFlows.Filter_p_p_filterp_PostState_Container_PS = {
      val r = reader.readProdConsFlowsFilter_p_p_filterp_PostState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_p_p_filterp_PostState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PreState_Container(o: ProdConsFlows.Filter_s_p_filters_PreState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_s_p_filters_PreState_Container(o)
    return w.result
  }

  def toProdConsFlowsFilter_s_p_filters_PreState_Container(data: ISZ[U8]): Either[ProdConsFlows.Filter_s_p_filters_PreState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PreState_Container(reader: Reader): ProdConsFlows.Filter_s_p_filters_PreState_Container = {
      val r = reader.readProdConsFlowsFilter_s_p_filters_PreState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_s_p_filters_PreState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PreState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_s_p_filters_PreState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsFilter_s_p_filters_PreState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Filter_s_p_filters_PreState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PreState_Container_P(reader: Reader): ProdConsFlows.Filter_s_p_filters_PreState_Container_P = {
      val r = reader.readProdConsFlowsFilter_s_p_filters_PreState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_s_p_filters_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PreState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_s_p_filters_PreState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsFilter_s_p_filters_PreState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Filter_s_p_filters_PreState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PreState_Container_PS(reader: Reader): ProdConsFlows.Filter_s_p_filters_PreState_Container_PS = {
      val r = reader.readProdConsFlowsFilter_s_p_filters_PreState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_s_p_filters_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PostState_Container(o: ProdConsFlows.Filter_s_p_filters_PostState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_s_p_filters_PostState_Container(o)
    return w.result
  }

  def toProdConsFlowsFilter_s_p_filters_PostState_Container(data: ISZ[U8]): Either[ProdConsFlows.Filter_s_p_filters_PostState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PostState_Container(reader: Reader): ProdConsFlows.Filter_s_p_filters_PostState_Container = {
      val r = reader.readProdConsFlowsFilter_s_p_filters_PostState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_s_p_filters_PostState_Container _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PostState_Container_P(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_s_p_filters_PostState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsFilter_s_p_filters_PostState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Filter_s_p_filters_PostState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PostState_Container_P(reader: Reader): ProdConsFlows.Filter_s_p_filters_PostState_Container_P = {
      val r = reader.readProdConsFlowsFilter_s_p_filters_PostState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_s_p_filters_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o: ProdConsFlows.Filter_s_p_filters_PostState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsFilter_s_p_filters_PostState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsFilter_s_p_filters_PostState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Filter_s_p_filters_PostState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsFilter_s_p_filters_PostState_Container_PS(reader: Reader): ProdConsFlows.Filter_s_p_filters_PostState_Container_PS = {
      val r = reader.readProdConsFlowsFilter_s_p_filters_PostState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsFilter_s_p_filters_PostState_Container_PS _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PreState_Container(o: ProdConsFlows.Consumer_p_consumer_PreState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsConsumer_p_consumer_PreState_Container(o)
    return w.result
  }

  def toProdConsFlowsConsumer_p_consumer_PreState_Container(data: ISZ[U8]): Either[ProdConsFlows.Consumer_p_consumer_PreState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PreState_Container(reader: Reader): ProdConsFlows.Consumer_p_consumer_PreState_Container = {
      val r = reader.readProdConsFlowsConsumer_p_consumer_PreState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsConsumer_p_consumer_PreState_Container _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PreState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsConsumer_p_consumer_PreState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsConsumer_p_consumer_PreState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Consumer_p_consumer_PreState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PreState_Container_P(reader: Reader): ProdConsFlows.Consumer_p_consumer_PreState_Container_P = {
      val r = reader.readProdConsFlowsConsumer_p_consumer_PreState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsConsumer_p_consumer_PreState_Container_P _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PreState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsConsumer_p_consumer_PreState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsConsumer_p_consumer_PreState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Consumer_p_consumer_PreState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PreState_Container_PS(reader: Reader): ProdConsFlows.Consumer_p_consumer_PreState_Container_PS = {
      val r = reader.readProdConsFlowsConsumer_p_consumer_PreState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsConsumer_p_consumer_PreState_Container_PS _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PostState_Container(o: ProdConsFlows.Consumer_p_consumer_PostState_Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsConsumer_p_consumer_PostState_Container(o)
    return w.result
  }

  def toProdConsFlowsConsumer_p_consumer_PostState_Container(data: ISZ[U8]): Either[ProdConsFlows.Consumer_p_consumer_PostState_Container, MessagePack.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PostState_Container(reader: Reader): ProdConsFlows.Consumer_p_consumer_PostState_Container = {
      val r = reader.readProdConsFlowsConsumer_p_consumer_PostState_Container()
      return r
    }
    val r = to(data, fProdConsFlowsConsumer_p_consumer_PostState_Container _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PostState_Container_P(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_P, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsConsumer_p_consumer_PostState_Container_P(o)
    return w.result
  }

  def toProdConsFlowsConsumer_p_consumer_PostState_Container_P(data: ISZ[U8]): Either[ProdConsFlows.Consumer_p_consumer_PostState_Container_P, MessagePack.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PostState_Container_P(reader: Reader): ProdConsFlows.Consumer_p_consumer_PostState_Container_P = {
      val r = reader.readProdConsFlowsConsumer_p_consumer_PostState_Container_P()
      return r
    }
    val r = to(data, fProdConsFlowsConsumer_p_consumer_PostState_Container_P _)
    return r
  }

  def fromProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o: ProdConsFlows.Consumer_p_consumer_PostState_Container_PS, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeProdConsFlowsConsumer_p_consumer_PostState_Container_PS(o)
    return w.result
  }

  def toProdConsFlowsConsumer_p_consumer_PostState_Container_PS(data: ISZ[U8]): Either[ProdConsFlows.Consumer_p_consumer_PostState_Container_PS, MessagePack.ErrorMsg] = {
    def fProdConsFlowsConsumer_p_consumer_PostState_Container_PS(reader: Reader): ProdConsFlows.Consumer_p_consumer_PostState_Container_PS = {
      val r = reader.readProdConsFlowsConsumer_p_consumer_PostState_Container_PS()
      return r
    }
    val r = to(data, fProdConsFlowsConsumer_p_consumer_PostState_Container_PS _)
    return r
  }

  def fromutilContainer(o: util.Container, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeutilContainer(o)
    return w.result
  }

  def toutilContainer(data: ISZ[U8]): Either[util.Container, MessagePack.ErrorMsg] = {
    def futilContainer(reader: Reader): util.Container = {
      val r = reader.readutilContainer()
      return r
    }
    val r = to(data, futilContainer _)
    return r
  }

  def fromutilEmptyContainer(o: util.EmptyContainer, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.writeutilEmptyContainer(o)
    return w.result
  }

  def toutilEmptyContainer(data: ISZ[U8]): Either[util.EmptyContainer, MessagePack.ErrorMsg] = {
    def futilEmptyContainer(reader: Reader): util.EmptyContainer = {
      val r = reader.readutilEmptyContainer()
      return r
    }
    val r = to(data, futilEmptyContainer _)
    return r
  }

  def from_artDataContent(o: art.DataContent, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.write_artDataContent(o)
    return w.result
  }

  def to_artDataContent(data: ISZ[U8]): Either[art.DataContent, MessagePack.ErrorMsg] = {
    def f_artDataContent(reader: Reader): art.DataContent = {
      val r = reader.read_artDataContent()
      return r
    }
    val r = to(data, f_artDataContent _)
    return r
  }

  def from_artEmpty(o: art.Empty, pooling: B): ISZ[U8] = {
    val w = Writer.Default(MessagePack.writer(pooling))
    w.write_artEmpty(o)
    return w.result
  }

  def to_artEmpty(data: ISZ[U8]): Either[art.Empty, MessagePack.ErrorMsg] = {
    def f_artEmpty(reader: Reader): art.Empty = {
      val r = reader.read_artEmpty()
      return r
    }
    val r = to(data, f_artEmpty _)
    return r
  }

}