#include <Consumer_proc_consumer_api.h>
#include <Consumer_proc_consumer.h>

static bool apis_initialized = false;
static struct a_Arrays_Consumer_Initialization_Api initialization_api;
static struct a_Arrays_Consumer_Operational_Api operational_api;

static void initialize_apis(STACK_FRAME_ONLY) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer.c", "", "initialize_apis", 0);

  // Option_1B1BB1 = Option[a.Arrays.Consumer_Initialization_Api]
  Option_1B1BB1_get_(SF (a_Arrays_Consumer_Initialization_Api) &initialization_api, a_Arrays_Consumer_proc_consumer_Bridge_c_initialization_api(SF_LAST));
  // Option_6DB07A = Option[a.Arrays.Consumer_Operational_Api]
  Option_6DB07A_get_(SF (a_Arrays_Consumer_Operational_Api) &operational_api, a_Arrays_Consumer_proc_consumer_Bridge_c_operational_api(SF_LAST));
  apis_initialized = true;
}

// This file was auto-generated.  Do not edit

bool api_get_coordinates__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  a_Arrays_Array_of_Coordinates value){
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "api_get_coordinates__a_Arrays_Consumer_proc_consumer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  // Option_664F6E = Option[a.Arrays.Array_of_Coordinates]
  // Some_27EAEB = Some[a.Arrays.Array_of_Coordinates]
  DeclNewOption_664F6E(t_0);
  a_Arrays_Consumer_Operational_Api_get_coordinates_(
    SF
    (Option_664F6E) &t_0,
    &operational_api);

  if(t_0.type == TSome_27EAEB){
    Type_assign(value, &t_0.Some_27EAEB.value, sizeof(struct a_Arrays_Array_of_Coordinates));
    return true;
  } else {
    return false;
  }
}

bool api_get_vector_of_coordinates__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  a_Arrays_Vector_of_Coordinates value){
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "api_get_vector_of_coordinates__a_Arrays_Consumer_proc_consumer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  // Option_87C7E5 = Option[a.Arrays.Vector_of_Coordinates]
  // Some_4DFD22 = Some[a.Arrays.Vector_of_Coordinates]
  DeclNewOption_87C7E5(t_0);
  a_Arrays_Consumer_Operational_Api_get_vector_of_coordinates_(
    SF
    (Option_87C7E5) &t_0,
    &operational_api);

  if(t_0.type == TSome_4DFD22){
    Type_assign(value, &t_0.Some_4DFD22.value, sizeof(struct a_Arrays_Vector_of_Coordinates));
    return true;
  } else {
    return false;
  }
}

bool api_get_integers__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  a_Arrays_Array_of_Integers value){
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "api_get_integers__a_Arrays_Consumer_proc_consumer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  // Option_1ECEF8 = Option[a.Arrays.Array_of_Integers]
  // Some_82CF55 = Some[a.Arrays.Array_of_Integers]
  DeclNewOption_1ECEF8(t_0);
  a_Arrays_Consumer_Operational_Api_get_integers_(
    SF
    (Option_1ECEF8) &t_0,
    &operational_api);

  if(t_0.type == TSome_82CF55){
    Type_assign(value, &t_0.Some_82CF55.value, sizeof(struct a_Arrays_Array_of_Integers));
    return true;
  } else {
    return false;
  }
}

void api_logInfo__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  String str) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "api_logInfo__a_Arrays_Consumer_proc_consumer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Consumer_Initialization_Api_logInfo_(
    SF
    &initialization_api,
    str);
}

void api_logDebug__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  String str) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "api_logDebug__a_Arrays_Consumer_proc_consumer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Consumer_Initialization_Api_logDebug_(
    SF
    &initialization_api,
    str);
}

void api_logError__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  String str) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "api_logError__a_Arrays_Consumer_proc_consumer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Consumer_Initialization_Api_logError_(
    SF
    &initialization_api,
    str);
}

Unit a_Arrays_Consumer_proc_consumer_initialise(
  STACK_FRAME
  a_Arrays_Consumer_Initialization_Api api) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "a_Arrays_Consumer_proc_consumer_initialise", 0);

  a_Arrays_Consumer_proc_consumer_initialise_(SF_LAST);
}

Unit a_Arrays_Consumer_proc_consumer_finalise(
  STACK_FRAME
  a_Arrays_Consumer_Operational_Api api) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "a_Arrays_Consumer_proc_consumer_finalise", 0);

  a_Arrays_Consumer_proc_consumer_finalise_(SF_LAST);
}

Unit a_Arrays_Consumer_proc_consumer_handle_coordinates(
  STACK_FRAME
  a_Arrays_Consumer_Operational_Api api,
  a_Arrays_Array_of_Coordinates value) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "a_Arrays_Consumer_proc_consumer_handle_coordinates", 0);

  a_Arrays_Consumer_proc_consumer_handle_coordinates_(SF value);
}

Unit a_Arrays_Consumer_proc_consumer_handle_vector_of_coordinates(
  STACK_FRAME
  a_Arrays_Consumer_Operational_Api api,
  a_Arrays_Vector_of_Coordinates value) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "a_Arrays_Consumer_proc_consumer_handle_vector_of_coordinates", 0);

  a_Arrays_Consumer_proc_consumer_handle_vector_of_coordinates_(SF value);
}

Unit a_Arrays_Consumer_proc_consumer_handle_integers(
  STACK_FRAME
  a_Arrays_Consumer_Operational_Api api,
  a_Arrays_Array_of_Integers value) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer_api.c", "", "a_Arrays_Consumer_proc_consumer_handle_integers", 0);

  a_Arrays_Consumer_proc_consumer_handle_integers_(SF value);
}