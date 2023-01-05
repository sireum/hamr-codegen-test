#ifndef CONSUMER_PROC_CONSUMER_H
#define CONSUMER_PROC_CONSUMER_H

#include <all.h>

Unit a_Arrays_Consumer_proc_consumer_initialise_(STACK_FRAME_ONLY);

Unit a_Arrays_Consumer_proc_consumer_finalise_(STACK_FRAME_ONLY);

Unit a_Arrays_Consumer_proc_consumer_handle_coordinates_(
  STACK_FRAME
  a_Arrays_Array_of_Coordinates value);

Unit a_Arrays_Consumer_proc_consumer_handle_vector_of_coordinates_(
  STACK_FRAME
  a_Arrays_Vector_of_Coordinates value);

Unit a_Arrays_Consumer_proc_consumer_handle_integers_(
  STACK_FRAME
  a_Arrays_Array_of_Integers value);

#endif
