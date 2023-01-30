#include <Consumer_proc_consumer_api.h>
#include <Consumer_proc_consumer.h>
#include <ext.h>

// This file will not be overwritten so is safe to edit

static char* component_id = "PC_Sys_Impl_Instance_proc_consumer";

Unit a_Arrays_Consumer_proc_consumer_initialise_(STACK_FRAME_ONLY) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer.c", "", "a_Arrays_Consumer_proc_consumer_initialise_", 0);
}

Unit a_Arrays_Consumer_proc_consumer_finalise_(STACK_FRAME_ONLY) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer.c", "", "a_Arrays_Consumer_proc_consumer_finalise_", 0);
}

Unit a_Arrays_Consumer_proc_consumer_handle_coordinates_(
  STACK_FRAME
  a_Arrays_Array_of_Coordinates value) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer.c", "", "a_Arrays_Consumer_proc_consumer_handle_coordinates_", 0);

  // ensuring we can do some basic iterating over and accessing ranged sequences
  printf("%s: a_Arrays_Consumer_proc_consumer_handle_coordinates called\n", component_id);
  printf("%s: Received on coordinates: Array_of_Coordinates([", component_id);
  for(int i = 0; i < value->value.size; i++) {
      // pretty print the coord using it's slang string method
      DeclNewString(_str);
      a_Arrays_Coordinate_Impl_string_(SF (String) &_str, (a_Arrays_Coordinate_Impl) &(value->value.value[i]));
      printf("%s%s", _str.value, i < value->value.size - 1 ? ", " : "");
  }
  printf("])\n");
  printf("\n");
}

Unit a_Arrays_Consumer_proc_consumer_handle_vector_of_coordinates_(
  STACK_FRAME
  a_Arrays_Vector_of_Coordinates value) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer.c", "", "a_Arrays_Consumer_proc_consumer_handle_vector_of_coordinates_", 0);

  printf("%s: a_Arrays_Consumer_proc_consumer_handle_vector_of_coordinates called\n", component_id);

  DeclNewString(_str);
  String__append(SF (String) &_str, string("Received on vector_of_coordinates: "));
  a_Arrays_Vector_of_Coordinates_string_(SF (String) &_str, value);
  api_logInfo__a_Arrays_Consumer_proc_consumer(SF (String) &_str);

  printf("\n");
}

Unit a_Arrays_Consumer_proc_consumer_handle_integers_(
  STACK_FRAME
  a_Arrays_Array_of_Integers value) {
  DeclNewStackFrame(caller, "Consumer_proc_consumer.c", "", "a_Arrays_Consumer_proc_consumer_handle_integers_", 0);

  printf("%s: a_Arrays_Consumer_proc_consumer_handle_integers called\n", component_id);

  DeclNewString(_str);
  String__append(SF (String) &_str, string("Received on integers: "));
  a_Arrays_Array_of_Integers_string_(SF (String) &_str, value);
  api_logInfo__a_Arrays_Consumer_proc_consumer(SF (String) &_str);

  printf("\n");
}
