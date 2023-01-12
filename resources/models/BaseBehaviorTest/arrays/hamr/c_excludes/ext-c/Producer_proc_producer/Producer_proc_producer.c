#include <Producer_proc_producer_api.h>
#include <Producer_proc_producer.h>
#include <ext.h>

// This file will not be overwritten so is safe to edit

static char* component_id = "PC_Sys_Impl_Instance_proc_producer";

Unit a_Arrays_Producer_proc_producer_initialise_(STACK_FRAME_ONLY) {
  DeclNewStackFrame(caller, "Producer_proc_producer.c", "", "a_Arrays_Producer_proc_producer_initialise_", 0);

  printf("%s: a_Arrays_Producer_proc_producer_initialise_ called\n", component_id);

    {
        DeclNewIS_659A54(isc);
        S32 s32 = 0;
        for (int i = 0; i < MaxIS_659A54; i++) {
            DeclNewa_Arrays_Coordinate_Impl(coord);
            coord.latitude = s32;
            coord.longitude = s32 - 1;
            coord.altitude = s32 - 2;
            s32 -= 3;

            // copy coord into isc.value[i], replacing whatever is there
            isc.value[i] = coord;
            isc.size = i + 1;

            // alternative is to use the provided update method as that will
            // check that 'i' (whose type becomes a uint64) is in range if
            // SIREUM_BOUND_CHECK is set and you use the Debug build as 
            // Release's optimization setting disable asserts
            IS_659A54_up(&isc, i, &coord);
        }

        DeclNewa_Arrays_Array_of_Coordinates(aac);
        a_Arrays_Array_of_Coordinates_apply(SF &aac, (IS_659A54) ((IS_659A54) &isc));

        api_put_coordinates__a_Arrays_Producer_proc_producer(SF &aac);
    }

  DeclNewa_Arrays_Vector_of_Coordinates(t1);
  a_Arrays_Vector_of_Coordinates_example(SF &t1);
  api_put_vector_of_coordinates__a_Arrays_Producer_proc_producer(SF &t1);

  DeclNewa_Arrays_Array_of_Integers(t2);
  a_Arrays_Array_of_Integers_example(SF &t2);
  api_put_integers__a_Arrays_Producer_proc_producer(SF &t2);
}

Unit a_Arrays_Producer_proc_producer_finalise_(STACK_FRAME_ONLY) {
  DeclNewStackFrame(caller, "Producer_proc_producer.c", "", "a_Arrays_Producer_proc_producer_finalise_", 0);
}

Unit a_Arrays_Producer_proc_producer_timeTriggered_(STACK_FRAME_ONLY) {
  DeclNewStackFrame(caller, "Producer_proc_producer.c", "", "a_Arrays_Producer_proc_producer_timeTriggered_", 0);

}
