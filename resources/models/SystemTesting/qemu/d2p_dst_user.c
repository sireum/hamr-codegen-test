#include "d2p_dst.h"

// This file will not be overwritten if HAMR codegen is rerun

void d2p_dst_initialize(void) {
  printf("%s: d2p_dst_initialize invoked\n", microkit_name);
}

void d2p_dst_timeTriggered(void) {
  int32_t v;
  if (get_val(&v)) {
    // FAULT for SystemTestingTests: 77 is forwarded as 78
    int32_t out = (v == 77) ? 78 : v;
    put_fwd(&out);
  }
}

void d2p_dst_notify(microkit_channel channel) {
  // this method is called when the monitor does not handle the passed in channel
  switch (channel) {
    default:
      printf("%s: Unexpected channel %d\n", microkit_name, channel);
  }
}
