#include "producer_p_producer.h"
#include <sb_queue_SharedMemorySafety_BigArray_1.h>
#include <sb_queue_SharedMemorySafety_BigRec_i_1.h>
#include <sb_queue_SharedMemorySafety_Padded_i_2.h>

// QEMU test driver for SharedMemorySafety-design.md stages 2, 4 and 5.  The producer plays a
// sender that is correct for a while and then turns hostile:
//   dispatch 1-3  valid big/rec/padded messages (stage 2: large queues arrive intact)
//   dispatch 4    padded slot written with enum Mode = 7            (stage 4)
//   dispatch 5    padded slot written with bool flag = 2            (stage 4)
//   dispatch 6    a valid padded message                            (stage 4: still flows)
//   dispatch 8    one byte written just past the end of the big region (stage 5: must fault)

// the producer's mappings of its outgoing regions (producer_p_producer.c)
extern volatile sb_queue_SharedMemorySafety_BigArray_1_t *big_queue_1;
extern volatile sb_queue_SharedMemorySafety_Padded_i_2_t *padded_queue_2;

static int n = 0;
static SharedMemorySafety_BigArray big;
static SharedMemorySafety_BigRec_i rec;

void producer_p_producer_initialize(void) {
  printf("SMS|producer: initialize\n");
}

static SharedMemorySafety_Padded_i valid_padded(int k) {
  SharedMemorySafety_Padded_i v = { .a = (int8_t) k, .b = k * 10, .flag = (k % 2) == 1, .mode = Run };
  return v;
}

// A hostile sender writes a slot's bytes itself, then publishes it
static void publish_corrupt_padded(size_t offset, uint32_t bytes, size_t width, const char *what) {
  size_t index = padded_queue_2->numSent % SB_QUEUE_SHAREDMEMORYSAFETY_PADDED_I_2_SIZE;
  SharedMemorySafety_Padded_i v = valid_padded(n);
  memcpy((void *) &padded_queue_2->elt[index], &v, sizeof(v));
  memcpy((unsigned char *) &padded_queue_2->elt[index] + offset, &bytes, width);
  __atomic_thread_fence(__ATOMIC_RELEASE);
  padded_queue_2->numSent++;
  printf("SMS|producer: dispatch %d sent a corrupted padded message (%s)\n", n, what);
}

void producer_p_producer_timeTriggered(void) {
  n++;
  if (n <= 3) {
    for (size_t i = 0; i < SharedMemorySafety_BigArray_DIM_0; i++) big[i] = n * 100000 + (int32_t) i;
    rec.header = n;
    for (size_t i = 0; i < SharedMemorySafety_Payload_DIM_0; i++) rec.payload[i] = (uint8_t) (n + i);
    SharedMemorySafety_Padded_i p = valid_padded(n);
    put_big(&big);
    put_rec(&rec);
    put_padded(&p);
    printf("SMS|producer: dispatch %d sent big, rec and padded\n", n);
  } else if (n == 4) {
    publish_corrupt_padded(offsetof(SharedMemorySafety_Padded_i, mode), 7, sizeof(SharedMemorySafety_Mode), "enum Mode = 7");
  } else if (n == 5) {
    publish_corrupt_padded(offsetof(SharedMemorySafety_Padded_i, flag), 2, 1, "bool flag = 2");
  } else if (n == 6) {
    SharedMemorySafety_Padded_i p = valid_padded(n);
    put_padded(&p);
    printf("SMS|producer: dispatch %d sent a valid padded message\n", n);
  } else if (n == 8) {
    volatile unsigned char *past = (volatile unsigned char *) big_queue_1 + SB_QUEUE_SHAREDMEMORYSAFETY_BIGARRAY_1_REGION_BYTES;
    printf("SMS|producer: dispatch %d writing one byte past the big region (region %p, %u bytes; write at %p)\n",
           n, (void *) big_queue_1, (unsigned) SB_QUEUE_SHAREDMEMORYSAFETY_BIGARRAY_1_REGION_BYTES, (void *) past);
    *past = 0x5A;
    printf("SMS|producer: FAIL the write past the big region did not fault\n");
  }
}

void producer_p_producer_notify(microkit_channel channel) {
  // this method is called when the monitor does not handle the passed in channel
  switch (channel) {
    default:
      printf("%s: Unexpected channel %d\n", microkit_name, channel);
  }
}
