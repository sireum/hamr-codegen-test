// Host stand-in for Microkit, just enough for the generated test scheduler
// (SystemTestingTests, "the scheduler on the host").
#pragma once
#include <stdint.h>
typedef unsigned int microkit_channel;
#define MICROKIT_MAX_CHANNELS 62
void microkit_notify(microkit_channel ch);
