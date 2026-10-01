#pragma once
#include <stdint.h>
// The harness provides both, and controls the clock.
uint64_t sddf_timer_time_now(unsigned int channel);
void sddf_timer_set_timeout(unsigned int channel, uint64_t timeout);
