// Host test harness for SharedMemorySafety-design.md.  Compiled by SharedMemorySafetyTests
// against the queues HAMR generates for models/SharedMemorySafety, and run on the host.
//
// Each check places a queue in a buffer the size of the shared memory region HAMR allocates
// for it (<QUEUE>_REGION_BYTES), surrounded by canaries, and plays both the sender and the
// receiver.  A write past the region, past the element, or past the receiver's destination
// changes a canary; an invalid value reaching the receiver changes its destination.
//
// Exit status 0 means every check passed; each failure prints a FAIL line.

// The generated headers first: they declare memcpy/memset themselves (the target has no
// libc), which a host <string.h> that defines them as macros would otherwise rewrite.
#include <sb_aadl_types.h>
#include <sb_queue_SharedMemorySafety_BigArray_1.h>
#include <sb_queue_SharedMemorySafety_BigRec_i_1.h>
#include <sb_queue_SharedMemorySafety_Padded_i_2.h>
#include <sb_queue_Base_Types_String_1.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANARY_BYTES 4096
#define CANARY 0xA5

static int failures = 0;

#define CHECK(cond, ...) do {                        \
    if (!(cond)) {                                   \
      failures++;                                    \
      printf("FAIL %s:%d: ", __FILE__, __LINE__);    \
      printf(__VA_ARGS__);                           \
      printf("\n");                                  \
    }                                                \
  } while (0)

static void fill_canary(unsigned char *p, size_t n) { memset(p, CANARY, n); }

static int canary_intact(const unsigned char *p, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (p[i] != CANARY) return 0;
  }
  return 1;
}

// A region-sized buffer with canaries on both sides, page-aligned like a Microkit mapping.
// Aligned by hand rather than with aligned_alloc, which some C runtimes (MinGW's) lack.  One
// region is in use at a time; free_region releases it.
static unsigned char *region_base;

static unsigned char *region_with_canaries(size_t regionBytes) {
  size_t total = CANARY_BYTES + regionBytes + CANARY_BYTES;
  region_base = malloc(total + 4096);
  unsigned char *raw = (unsigned char *) (((uintptr_t) region_base + 4095) & ~(uintptr_t) 4095);
  fill_canary(raw, CANARY_BYTES);
  memset(raw + CANARY_BYTES, 0, regionBytes);
  fill_canary(raw + CANARY_BYTES + regionBytes, CANARY_BYTES);
  return raw;
}

static void free_region(void) {
  free(region_base);
  region_base = NULL;
}

// F3/D4: a queue of large elements fits the region HAMR allocates, and a round trip neither
// corrupts the data nor writes outside the region or the receiver's destination.
#define ROUND_TRIP_CHECK(NAME, QUEUE, T, FILL, EQUAL)                                         \
  static void NAME(void) {                                                                   \
    int failuresBefore = failures;                                                           \
    size_t regionBytes = QUEUE##_REGION_BYTES_VALUE;                                         \
    CHECK(sizeof(QUEUE##_t) <= regionBytes, #QUEUE ": struct is %zu bytes, region %zu",       \
          sizeof(QUEUE##_t), regionBytes);                                                   \
    unsigned char *raw = region_with_canaries(regionBytes);                                  \
    QUEUE##_t *queue = (QUEUE##_t *) (raw + CANARY_BYTES);                                   \
    QUEUE##_init(queue);                                                                     \
    QUEUE##_Recv_t recv;                                                                     \
    QUEUE##_Recv_init(&recv, queue);                                                         \
    static struct { unsigned char before[256]; T value; unsigned char after[256]; } dest;    \
    static T sent;                                                                           \
    for (int round = 0; round < 7; round++) {                                                \
      FILL(&sent, round);                                                                    \
      QUEUE##_enqueue(queue, &sent);                                                         \
      fill_canary(dest.before, sizeof(dest.before));                                         \
      fill_canary(dest.after, sizeof(dest.after));                                           \
      sb_event_counter_t dropped = 0;                                                        \
      bool got = QUEUE##_dequeue(&recv, &dropped, &dest.value);                              \
      CHECK(got, #QUEUE ": round %d not delivered", round);                                  \
      CHECK(EQUAL(&dest.value, &sent), #QUEUE ": round %d delivered corrupted data", round);  \
      CHECK(canary_intact(dest.before, sizeof(dest.before)) &&                               \
            canary_intact(dest.after, sizeof(dest.after)),                                   \
            #QUEUE ": round %d wrote outside the receiver's destination", round);            \
    }                                                                                        \
    CHECK(canary_intact(raw, CANARY_BYTES), #QUEUE ": wrote before its region");             \
    CHECK(canary_intact(raw + CANARY_BYTES + regionBytes, CANARY_BYTES),                     \
          #QUEUE ": wrote past the end of its %zu-byte region", regionBytes);                \
    free_region();                                                                            \
    if (failures == failuresBefore)                                                          \
      printf("ok   %s: %zu-byte queue in a %zu-byte region, 7 round trips intact\n",         \
             #QUEUE, sizeof(QUEUE##_t), regionBytes);                                        \
  }

#define sb_queue_SharedMemorySafety_BigArray_1_REGION_BYTES_VALUE SB_QUEUE_SHAREDMEMORYSAFETY_BIGARRAY_1_REGION_BYTES
#define sb_queue_SharedMemorySafety_BigRec_i_1_REGION_BYTES_VALUE SB_QUEUE_SHAREDMEMORYSAFETY_BIGREC_I_1_REGION_BYTES

static void fill_big_array(SharedMemorySafety_BigArray *v, int round) {
  for (size_t i = 0; i < SharedMemorySafety_BigArray_DIM_0; i++) (*v)[i] = (int32_t) (round * 100000 + (int) i);
}
static int equal_big_array(const SharedMemorySafety_BigArray *a, const SharedMemorySafety_BigArray *b) {
  return memcmp(a, b, sizeof(SharedMemorySafety_BigArray)) == 0;
}

static void fill_big_rec(SharedMemorySafety_BigRec_i *v, int round) {
  v->header = round;
  for (size_t i = 0; i < SharedMemorySafety_Payload_DIM_0; i++) v->payload[i] = (uint8_t) (round + i);
}
static int equal_big_rec(const SharedMemorySafety_BigRec_i *a, const SharedMemorySafety_BigRec_i *b) {
  return a->header == b->header && memcmp(a->payload, b->payload, sizeof(a->payload)) == 0;
}

ROUND_TRIP_CHECK(check_big_array, sb_queue_SharedMemorySafety_BigArray_1, SharedMemorySafety_BigArray,
                 fill_big_array, equal_big_array)
ROUND_TRIP_CHECK(check_big_rec, sb_queue_SharedMemorySafety_BigRec_i_1, SharedMemorySafety_BigRec_i,
                 fill_big_rec, equal_big_rec)

// F4/D6: a peer that writes an out-of-range enum or a bool that is neither 0 nor 1 into the
// shared region gets nothing delivered: the dequeue returns false, the receiver counts it,
// and the receiver's destination is not touched.  Valid data still flows afterwards.
static void check_invalid_values(void) {
  typedef sb_queue_SharedMemorySafety_Padded_i_2_t Q;
  unsigned char *raw = region_with_canaries(SB_QUEUE_SHAREDMEMORYSAFETY_PADDED_I_2_REGION_BYTES);
  Q *queue = (Q *) (raw + CANARY_BYTES);
  sb_queue_SharedMemorySafety_Padded_i_2_init(queue);
  sb_queue_SharedMemorySafety_Padded_i_2_Recv_t recv;
  sb_queue_SharedMemorySafety_Padded_i_2_Recv_init(&recv, queue);

  SharedMemorySafety_Padded_i valid = { .a = 1, .b = 2, .flag = true, .mode = Run };

  // A compromised sender writes the slot's bytes directly, then publishes it.
  struct { const char *what; size_t offset; uint32_t bytes; size_t width; } corruptions[] = {
    { "enum Mode = 7",  offsetof(SharedMemorySafety_Padded_i, mode), 7, sizeof(SharedMemorySafety_Mode) },
    { "bool flag = 2",  offsetof(SharedMemorySafety_Padded_i, flag), 2, 1 },
    { "enum Mode = -1", offsetof(SharedMemorySafety_Padded_i, mode), 0xFFFFFFFFu, sizeof(SharedMemorySafety_Mode) },
  };
  size_t n = sizeof(corruptions) / sizeof(corruptions[0]);
  for (size_t k = 0; k < n; k++) {
    size_t index = queue->numSent % SB_QUEUE_SHAREDMEMORYSAFETY_PADDED_I_2_SIZE;
    memcpy(&queue->elt[index], &valid, sizeof(valid));
    memcpy((unsigned char *) &queue->elt[index] + corruptions[k].offset, &corruptions[k].bytes, corruptions[k].width);
    queue->numSent++;

    int failuresBefore = failures;
    unsigned char dest[sizeof(SharedMemorySafety_Padded_i)];
    fill_canary(dest, sizeof(dest));
    sb_event_counter_t dropped = 0;
    bool got = sb_queue_SharedMemorySafety_Padded_i_2_dequeue(&recv, &dropped, (SharedMemorySafety_Padded_i *) dest);
    CHECK(!got, "invalid value (%s) was delivered", corruptions[k].what);
    CHECK(canary_intact(dest, sizeof(dest)), "invalid value (%s) reached the receiver's buffer", corruptions[k].what);
    CHECK(sb_queue_SharedMemorySafety_Padded_i_2_numInvalid(&recv) == k + 1,
          "invalid value (%s) was not counted", corruptions[k].what);
    if (failures == failuresBefore)
      printf("ok   rejected %s before it reached the receiver\n", corruptions[k].what);
  }

  int failuresBefore = failures;
  sb_queue_SharedMemorySafety_Padded_i_2_enqueue(queue, &valid);
  SharedMemorySafety_Padded_i out;
  memset(&out, 0, sizeof(out));
  sb_event_counter_t dropped = 0;
  bool got = sb_queue_SharedMemorySafety_Padded_i_2_dequeue(&recv, &dropped, &out);
  CHECK(got && out.a == 1 && out.b == 2 && out.flag == true && out.mode == Run,
        "a valid value after the rejected ones was not delivered intact");
  CHECK(sb_queue_SharedMemorySafety_Padded_i_2_numInvalid(&recv) == n, "a valid value was counted as invalid");
  CHECK(canary_intact(raw + CANARY_BYTES + SB_QUEUE_SHAREDMEMORYSAFETY_PADDED_I_2_REGION_BYTES, CANARY_BYTES),
        "Padded_i queue wrote past its region");
  free_region();
  if (failures == failuresBefore)
    printf("ok   a valid value after them is delivered intact\n");
}

// D6: a peer that fills a string with no terminating NUL gets nothing delivered -- a receiver
// treating it as a C string would read past it -- and a terminated string still flows.
static void check_unterminated_string(void) {
  typedef sb_queue_Base_Types_String_1_t Q;
  unsigned char *raw = region_with_canaries(SB_QUEUE_BASE_TYPES_STRING_1_REGION_BYTES);
  Q *queue = (Q *) (raw + CANARY_BYTES);
  sb_queue_Base_Types_String_1_init(queue);
  sb_queue_Base_Types_String_1_Recv_t recv;
  sb_queue_Base_Types_String_1_Recv_init(&recv, queue);

  int failuresBefore = failures;
  Base_Types_String unterminated;
  memset(unterminated, 'A', sizeof(unterminated));
  sb_queue_Base_Types_String_1_enqueue(queue, &unterminated);
  unsigned char dest[sizeof(Base_Types_String)];
  fill_canary(dest, sizeof(dest));
  sb_event_counter_t dropped = 0;
  bool got = sb_queue_Base_Types_String_1_dequeue(&recv, &dropped, (Base_Types_String *) dest);
  CHECK(!got, "an unterminated string was delivered");
  CHECK(canary_intact(dest, sizeof(dest)), "an unterminated string reached the receiver's buffer");
  CHECK(sb_queue_Base_Types_String_1_numInvalid(&recv) == 1, "an unterminated string was not counted");
  if (failures == failuresBefore)
    printf("ok   rejected an unterminated string before it reached the receiver\n");

  failuresBefore = failures;
  Base_Types_String hello;
  memset(hello, 0, sizeof(hello));
  memcpy(hello, "hello", 6);
  sb_queue_Base_Types_String_1_enqueue(queue, &hello);
  Base_Types_String out;
  memset(out, 'X', sizeof(out));
  got = sb_queue_Base_Types_String_1_dequeue(&recv, &dropped, &out);
  CHECK(got && strcmp(out, "hello") == 0, "a terminated string after it was not delivered intact");
  CHECK(sb_queue_Base_Types_String_1_numInvalid(&recv) == 1, "a terminated string was counted as invalid");
  free_region();
  if (failures == failuresBefore)
    printf("ok   a terminated string after it is delivered intact\n");
}

int main(void) {
  check_big_array();
  check_big_rec();
  check_invalid_values();
  check_unterminated_string();
  if (failures == 0) {
    printf("PASS all shared memory safety checks\n");
    return 0;
  }
  printf("FAILED %d check(s)\n", failures);
  return 1;
}
