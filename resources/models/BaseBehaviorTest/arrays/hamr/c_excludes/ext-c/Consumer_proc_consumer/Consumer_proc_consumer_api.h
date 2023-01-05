#ifndef CONSUMER_PROC_CONSUMER_API_H
#define CONSUMER_PROC_CONSUMER_API_H

#include <all.h>

// This file was auto-generated.  Do not edit

bool api_get_coordinates__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  a_Arrays_Array_of_Coordinates value);

bool api_get_vector_of_coordinates__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  a_Arrays_Vector_of_Coordinates value);

bool api_get_integers__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  a_Arrays_Array_of_Integers value);

void api_logInfo__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  String str);

void api_logDebug__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  String str);

void api_logError__a_Arrays_Consumer_proc_consumer(
  STACK_FRAME
  String str);

#endif
