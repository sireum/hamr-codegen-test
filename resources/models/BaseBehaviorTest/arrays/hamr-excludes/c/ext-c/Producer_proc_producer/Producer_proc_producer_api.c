#include <Producer_proc_producer_api.h>
#include <Producer_proc_producer.h>

static bool apis_initialized = false;
static struct a_Arrays_Producer_Initialization_Api initialization_api;
static struct a_Arrays_Producer_Operational_Api operational_api;

static void initialize_apis(STACK_FRAME_ONLY) {
  DeclNewStackFrame(caller, "Producer_proc_producer.c", "", "initialize_apis", 0);

  // Option_F26FD8 = Option[a.Arrays.Producer_Initialization_Api]
  Option_F26FD8_get_(SF (a_Arrays_Producer_Initialization_Api) &initialization_api, a_Arrays_Producer_proc_producer_Bridge_c_initialization_api(SF_LAST));
  // Option_75443E = Option[a.Arrays.Producer_Operational_Api]
  Option_75443E_get_(SF (a_Arrays_Producer_Operational_Api) &operational_api, a_Arrays_Producer_proc_producer_Bridge_c_operational_api(SF_LAST));
  apis_initialized = true;
}

// This file was auto-generated.  Do not edit

void api_put_coordinates__a_Arrays_Producer_proc_producer(
  STACK_FRAME
  a_Arrays_Array_of_Coordinates value) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "api_put_coordinates__a_Arrays_Producer_proc_producer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Producer_Initialization_Api_put_coordinates_(
    SF
    &initialization_api,
    value);
}

void api_put_vector_of_coordinates__a_Arrays_Producer_proc_producer(
  STACK_FRAME
  a_Arrays_Vector_of_Coordinates value) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "api_put_vector_of_coordinates__a_Arrays_Producer_proc_producer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Producer_Initialization_Api_put_vector_of_coordinates_(
    SF
    &initialization_api,
    value);
}

void api_put_integers__a_Arrays_Producer_proc_producer(
  STACK_FRAME
  a_Arrays_Array_of_Integers value) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "api_put_integers__a_Arrays_Producer_proc_producer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Producer_Initialization_Api_put_integers_(
    SF
    &initialization_api,
    value);
}

void api_logInfo__a_Arrays_Producer_proc_producer(
  STACK_FRAME
  String str) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "api_logInfo__a_Arrays_Producer_proc_producer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Producer_Initialization_Api_logInfo_(
    SF
    &initialization_api,
    str);
}

void api_logDebug__a_Arrays_Producer_proc_producer(
  STACK_FRAME
  String str) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "api_logDebug__a_Arrays_Producer_proc_producer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Producer_Initialization_Api_logDebug_(
    SF
    &initialization_api,
    str);
}

void api_logError__a_Arrays_Producer_proc_producer(
  STACK_FRAME
  String str) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "api_logError__a_Arrays_Producer_proc_producer", 0);

  if(!apis_initialized) { initialize_apis(SF_LAST); }

  a_Arrays_Producer_Initialization_Api_logError_(
    SF
    &initialization_api,
    str);
}

Unit a_Arrays_Producer_proc_producer_initialise(
  STACK_FRAME
  a_Arrays_Producer_Initialization_Api api) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "a_Arrays_Producer_proc_producer_initialise", 0);

  a_Arrays_Producer_proc_producer_initialise_(SF_LAST);
}

Unit a_Arrays_Producer_proc_producer_finalise(
  STACK_FRAME
  a_Arrays_Producer_Operational_Api api) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "a_Arrays_Producer_proc_producer_finalise", 0);

  a_Arrays_Producer_proc_producer_finalise_(SF_LAST);
}

Unit a_Arrays_Producer_proc_producer_timeTriggered(
  STACK_FRAME
  a_Arrays_Producer_Operational_Api api) {
  DeclNewStackFrame(caller, "Producer_proc_producer_api.c", "", "a_Arrays_Producer_proc_producer_timeTriggered", 0);

  a_Arrays_Producer_proc_producer_timeTriggered_(SF_LAST);
}