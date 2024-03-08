// #Sireum

package prod_cons__JVM

import org.sireum._
import org.sireum.Random.Gen64

/*
GENERATED FROM

Container_i.scala

Base_Types.scala

Producer_p_producer__Containers.scala

Filter_p_p_filterp__Containers.scala

Filter_s_p_filters__Containers.scala

Consumer_p_consumer__Containers.scala

Container.scala

DataContent.scala

Aux_Types.scala

*/

@enum object _artDataContent_DataTypeId {
   "_artEmpty_Id"
   "Base_TypesBits_Payload_Id"
   "Base_TypesBoolean_Payload_Id"
   "Base_TypesCharacter_Payload_Id"
   "Base_TypesFloat_32_Payload_Id"
   "Base_TypesFloat_64_Payload_Id"
   "Base_TypesFloat_Payload_Id"
   "Base_TypesInteger_16_Payload_Id"
   "Base_TypesInteger_32_Payload_Id"
   "Base_TypesInteger_64_Payload_Id"
   "Base_TypesInteger_8_Payload_Id"
   "Base_TypesInteger_Payload_Id"
   "Base_TypesString_Payload_Id"
   "Base_TypesUnsigned_16_Payload_Id"
   "Base_TypesUnsigned_32_Payload_Id"
   "Base_TypesUnsigned_64_Payload_Id"
   "Base_TypesUnsigned_8_Payload_Id"
   "ProdConsFlowsConsumer_p_consumer_PostState_Container_P_Id"
   "ProdConsFlowsConsumer_p_consumer_PostState_Container_PS_Id"
   "ProdConsFlowsConsumer_p_consumer_PreState_Container_P_Id"
   "ProdConsFlowsConsumer_p_consumer_PreState_Container_PS_Id"
   "ProdConsFlowsContainer_i_Payload_Id"
   "ProdConsFlowsFilter_p_p_filterp_PostState_Container_P_Id"
   "ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS_Id"
   "ProdConsFlowsFilter_p_p_filterp_PreState_Container_P_Id"
   "ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS_Id"
   "ProdConsFlowsFilter_s_p_filters_PostState_Container_P_Id"
   "ProdConsFlowsFilter_s_p_filters_PostState_Container_PS_Id"
   "ProdConsFlowsFilter_s_p_filters_PreState_Container_P_Id"
   "ProdConsFlowsFilter_s_p_filters_PreState_Container_PS_Id"
   "ProdConsFlowsProducer_p_producer_PostState_Container_P_Id"
   "ProdConsFlowsProducer_p_producer_PostState_Container_PS_Id"
   "ProdConsFlowsProducer_p_producer_PreState_Container_P_Id"
   "ProdConsFlowsProducer_p_producer_PreState_Container_PS_Id"
   "utilEmptyContainer_Id"
}

@enum object ProdConsFlowsConsumer_p_consumer_PreState_Container_DataTypeId {
   "ProdConsFlowsConsumer_p_consumer_PreState_Container_P_Id"
   "ProdConsFlowsConsumer_p_consumer_PreState_Container_PS_Id"
}

@enum object ProdConsFlowsConsumer_p_consumer_PostState_Container_DataTypeId {
   "ProdConsFlowsConsumer_p_consumer_PostState_Container_P_Id"
   "ProdConsFlowsConsumer_p_consumer_PostState_Container_PS_Id"
}

@enum object ProdConsFlowsFilter_p_p_filterp_PreState_Container_DataTypeId {
   "ProdConsFlowsFilter_p_p_filterp_PreState_Container_P_Id"
   "ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS_Id"
}

@enum object ProdConsFlowsFilter_p_p_filterp_PostState_Container_DataTypeId {
   "ProdConsFlowsFilter_p_p_filterp_PostState_Container_P_Id"
   "ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS_Id"
}

@enum object ProdConsFlowsFilter_s_p_filters_PreState_Container_DataTypeId {
   "ProdConsFlowsFilter_s_p_filters_PreState_Container_P_Id"
   "ProdConsFlowsFilter_s_p_filters_PreState_Container_PS_Id"
}

@enum object ProdConsFlowsFilter_s_p_filters_PostState_Container_DataTypeId {
   "ProdConsFlowsFilter_s_p_filters_PostState_Container_P_Id"
   "ProdConsFlowsFilter_s_p_filters_PostState_Container_PS_Id"
}

@enum object ProdConsFlowsProducer_p_producer_PreState_Container_DataTypeId {
   "ProdConsFlowsProducer_p_producer_PreState_Container_P_Id"
   "ProdConsFlowsProducer_p_producer_PreState_Container_PS_Id"
}

@enum object ProdConsFlowsProducer_p_producer_PostState_Container_DataTypeId {
   "ProdConsFlowsProducer_p_producer_PostState_Container_P_Id"
   "ProdConsFlowsProducer_p_producer_PostState_Container_PS_Id"
}

@enum object utilContainer_DataTypeId {
   "ProdConsFlowsConsumer_p_consumer_PostState_Container_P_Id"
   "ProdConsFlowsConsumer_p_consumer_PostState_Container_PS_Id"
   "ProdConsFlowsConsumer_p_consumer_PreState_Container_P_Id"
   "ProdConsFlowsConsumer_p_consumer_PreState_Container_PS_Id"
   "ProdConsFlowsFilter_p_p_filterp_PostState_Container_P_Id"
   "ProdConsFlowsFilter_p_p_filterp_PostState_Container_PS_Id"
   "ProdConsFlowsFilter_p_p_filterp_PreState_Container_P_Id"
   "ProdConsFlowsFilter_p_p_filterp_PreState_Container_PS_Id"
   "ProdConsFlowsFilter_s_p_filters_PostState_Container_P_Id"
   "ProdConsFlowsFilter_s_p_filters_PostState_Container_PS_Id"
   "ProdConsFlowsFilter_s_p_filters_PreState_Container_P_Id"
   "ProdConsFlowsFilter_s_p_filters_PreState_Container_PS_Id"
   "ProdConsFlowsProducer_p_producer_PostState_Container_P_Id"
   "ProdConsFlowsProducer_p_producer_PostState_Container_PS_Id"
   "ProdConsFlowsProducer_p_producer_PreState_Container_P_Id"
   "ProdConsFlowsProducer_p_producer_PreState_Container_PS_Id"
   "utilEmptyContainer_Id"
}

