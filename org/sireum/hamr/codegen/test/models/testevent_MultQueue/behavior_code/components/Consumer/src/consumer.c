/* apps/testevent/components/Consumer/src/main.c */

/* Similar to the "helloevent" example in CAmkES doc,
 * tidied up a bit.
 */

#include <camkes.h>
#include <stdio.h>
#include <sb_consumer_impl.h>

void testevent_consumer_component_init(const int64_t *in_arg) {
  printf("testevent_consumer_component_init called\n");
}

void testevent_consumer_s_event_handler() {
  int32_t receivedEvents = 0;
  while(sb_consumer_impl_read_s()) {
    receivedEvents++;
  }
  
  printf("[Consumer] received %i events\n\n", receivedEvents);
}
