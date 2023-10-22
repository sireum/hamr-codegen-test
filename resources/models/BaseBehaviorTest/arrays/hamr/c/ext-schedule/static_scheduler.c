#include <all.h>

// This file will not be overwritten so is safe to edit

// Transpiled signature of the Slang variable a.Schedulers.staticSchedule
// in architecture/a/Schedulers.scala.  This weak function declaration allows
// a_ScheduleProviderI_getStaticSchedule to detect whether the Slang variable was deleted
__attribute__((weak)) art_scheduling_static_Schedule_DScheduleSpec a_Schedulers_staticSchedule(STACK_FRAME_ONLY);

// helper method
void fillInSlot(IS_5AA467 slotSequence, int index, Z bridgeId, int length);

/*!
 * Example C implementation of the Slang extension method a.ScheduleProviderI.getStaticSchedule()
 * defined in architecture/a/Schedulers.scala
 *
 * @param result an empty schedule. Add slots in the order you want components to be dispatched.
 */
void a_ScheduleProviderI_getStaticSchedule(STACK_FRAME art_scheduling_static_Schedule_DScheduleSpec result){
  DeclNewStackFrame(caller, "static_scheduler.c", "", "a_ScheduleProviderI_getStaticSchedule", 0);

  if(a_Schedulers_staticSchedule) {
    printf("Using the static schedule provided in architecture/a/Schedulers.scala. Edit method \n");
    printf("  a_ScheduleProviderI_getStaticSchedule located in static_scheduler.c\n");
    printf("to supply your own\n");

    art_scheduling_static_Schedule_DScheduleSpec schedule = a_Schedulers_staticSchedule(SF_LAST);
    result->hyperPeriod = schedule->hyperPeriod;
    result->maxDomain = schedule->maxDomain;
    memcpy(&result->schedule, &schedule->schedule, sizeof(struct art_scheduling_static_Schedule_DSchedule));

  } else {
    printf("Transpiled Slang variable a.Schedulers.staticSchedule not found.  Using an example schedule from method");
    printf("  a_ScheduleProviderI_getStaticSchedule located in static_scheduler.c\n");

    // IS_5AA467=IS[Z, art.scheduling.static.Schedule.Slot], i.e. an immutable sequence of art.scheduling.static.Schedule.Slot
    DeclNewIS_5AA467(slotSequence);

    Z length = 1000 / 2;

    int i = 0;
    fillInSlot(&slotSequence, i++, a_Arch_PC_Sys_Impl_Instance_proc_producer(SF_LAST)->id, length);
    fillInSlot(&slotSequence, i++, a_Arch_PC_Sys_Impl_Instance_proc_consumer(SF_LAST)->id, length);
    slotSequence.size = i;

    DeclNewart_scheduling_static_Schedule_DSchedule(dschedule);
    art_scheduling_static_Schedule_DSchedule_apply(SF &dschedule, &slotSequence);

    Z maxDomain = 100;
    Z hyperPeriod = 1000;

    art_scheduling_static_Schedule_DScheduleSpec_apply(SF result, maxDomain, hyperPeriod, &dschedule);
  }
}

void fillInSlot(IS_5AA467 slotSequence, int index, Z bridgeId, int length) {
  // TODO: need to refactor to adjust to 2023.10 Slang changes
  exit(1);
  //slotSequence->value[index].bridgeId = bridgeId;
  //slotSequence->value[index].length = length;
}
