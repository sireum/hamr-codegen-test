// Drives the generated test scheduler on the host, for the cases QEMU cannot time or
// reach: notifications that arrive together, a late completion after an overrun, the
// observation park, a run-to command running out of budget, counts that would overflow.
// Includes the generated source, so a scenario may set its private state directly.
#include <string.h>
#include <stdlib.h>
#include "test_scheduler.scheduler.c"

static uint64_t now;
static uint64_t last_timeout;
static unsigned controller_notifications;

void microkit_notify(microkit_channel ch) {
    if (ch == TEST_CONTROLLER_CH) {
        controller_notifications++;
    }
}

uint64_t sddf_timer_time_now(unsigned int channel) { (void) channel; return now; }
void sddf_timer_set_timeout(unsigned int channel, uint64_t timeout) { (void) channel; last_timeout = timeout; }

static test_command_t cmd;
static test_status_t status;
static test_schedule_t sched;

// three slots -- two user slots and a non-user one -- and the timer's channel: clear of
// each other and of the controller's
#define CH_A 50
#define CH_B 51
#define CH_N 53
#define CH_TIMER 52

#define CHECK(c, what) do { if (!(c)) { printf("FAIL %s\n", what); exit(1); } } while (0)

static void setup_with(uint32_t n_slots) {
    memset(&cmd, 0, sizeof cmd);
    memset(&status, 0, sizeof status);
    memset(&sched, 0, sizeof sched);
    test_cmd = &cmd;
    test_status = &status;
    test_schedule = &sched;
    config.driver_id = CH_TIMER;
    memset(&user_schedule, 0, sizeof user_schedule);
    user_schedule.num_timeslices = n_slots;
    user_schedule.timeslice_ch[0] = CH_A;
    user_schedule.timeslice_ch[1] = CH_B;
    user_schedule.timeslice_ch[2] = CH_N;
    user_schedule.timeslices[0] = 50000000;
    user_schedule.timeslices[1] = 50000000;
    user_schedule.timeslices[2] = 50000000;
    user_schedule.is_user_partition[0] = true;
    user_schedule.is_user_partition[1] = true;
    user_schedule.is_user_partition[2] = false;
    part_ready = 0;
    part_ready_check = 0;
    now = 0;
    controller_notifications = 0;
    init();
    for (uint32_t i = 0; i < n_slots; i++) {
        notified(user_schedule.timeslice_ch[i]); // the readiness handshake
    }
    CHECK(scheduler_running, "the schedule did not go live");
}

static void setup(void) {
    setup_with(2);
}

static void command_obs(uint32_t type, uint32_t count, uint32_t target_hp, uint32_t observe) {
    cmd.type = type;
    cmd.count = count;
    cmd.target_hp = target_hp;
    cmd.observe = observe;
    cmd.seq++;
    notified(TEST_CONTROLLER_CH);
}

static void command(uint32_t type, uint32_t count, uint32_t target_hp) {
    command_obs(type, count, target_hp, 0);
}

// The slot in flight overruns: its watchdog expires.
static void overrun_now(void) {
    now += last_timeout;
    notified(CH_TIMER);
}

// A slot completes just as its watchdog expires: both are signalled, and the completion is
// handled first, which dispatches and arms the next slot.  The expiry that follows was A's;
// it must not be charged to B.  B's own expiry still is.
static void stale_expiry_is_not_the_next_slots(void) {
    setup();
    command(TEST_CMD_SSTEP, 2, 0);
    CHECK(last_dispatched_ch == CH_A, "A was not dispatched");
    now = last_timeout;
    notified(CH_A);
    CHECK(last_dispatched_ch == CH_B, "B was not dispatched after A completed");
    notified(CH_TIMER);
    CHECK((status_flags & TEST_FLAG_OVERRUN) == 0 && !(overrun_pending && overrun_ch == CH_B), "A's expiry was charged to B");
    overrun_now();
    CHECK((overrun_pending && overrun_ch == CH_B), "B's own expiry was not charged to it");
}

// A overruns; its late completion is absorbed -- not taken for anything -- and A can then be
// dispatched again.  Until then, a command reaching A's slot reports the overrun again.
static void late_completion_is_absorbed(void) {
    setup();
    command(TEST_CMD_SSTEP, 1, 0);
    overrun_now();
    CHECK((overrun_pending && overrun_ch == CH_A) && (status.flags & TEST_FLAG_OVERRUN) != 0, "A's overrun was not reported");
    uint32_t done = completed_seq;
    command(TEST_CMD_SSTEP, 1, 0); // still at A's slot
    CHECK((status.flags & TEST_FLAG_OVERRUN) != 0 && status.ack_seq == cmd.seq, "the overrun was not reported again");
    notified(CH_A); // the late completion
    CHECK(!(overrun_pending && overrun_ch == CH_A) && completed_seq == done, "the late completion was counted, or not absorbed");
    command(TEST_CMD_SSTEP, 1, 0);
    CHECK(last_dispatched_ch == CH_A && armed, "A was not dispatched again");
    notified(CH_A);
    CHECK(status.ack_seq == cmd.seq && (status.flags & TEST_FLAG_OVERRUN) == 0, "A's new dispatch did not complete the command");
}

// Slot 0 overruns, and the next command is already at its stop point there -- the runner's
// between-test run_to_slot(0), or INFO_STATE.  It still reports the overrun: the thread may be
// running, so what follows must not take the schedule for quiet.
static void overrun_at_the_stop_point_is_reported(void) {
    setup();
    command(TEST_CMD_SSTEP, 1, 0);
    overrun_now();
    CHECK(overrun_pending && overrun_ch == CH_A && current_timeslice == 0, "A's overrun did not leave the position on its slot");
    cmd.target_slot = 0;
    command(TEST_CMD_RUN_TO_SLOT, 0, 0);
    CHECK(status.ack_seq == cmd.seq && status.current_timeslice == 0 && (status.flags & TEST_FLAG_OVERRUN) != 0,
          "run_to_slot(0) on the overran slot did not report the overrun");
    command(TEST_CMD_INFO_STATE, 0, 0);
    CHECK(status.ack_seq == cmd.seq && (status.flags & TEST_FLAG_OVERRUN) != 0, "INFO_STATE on the overran slot did not report the overrun");
    notified(CH_A); // the late completion
    command(TEST_CMD_RUN_TO_SLOT, 0, 0);
    CHECK(status.ack_seq == cmd.seq && (status.flags & TEST_FLAG_OVERRUN) == 0, "the overrun was reported after the late completion");
}

// With observation on, each user dispatch parks first and goes ahead only once the
// controller acknowledges; a non-user slot neither parks nor counts as a completion.
static void observation_parks_user_slots_only(void) {
    setup_with(3);
    command_obs(TEST_CMD_SSTEP, 3, 0, 1);
    CHECK(!armed && status.obs_seq == 1 && status.next_ch == CH_A, "no park before A");
    notified(TEST_CONTROLLER_CH); // not yet acknowledged
    CHECK(!armed, "dispatched before the park was acknowledged");
    cmd.obs_ack = status.obs_seq;
    notified(TEST_CONTROLLER_CH);
    CHECK(armed && last_dispatched_ch == CH_A, "A not dispatched after the acknowledgement");
    notified(CH_A);
    CHECK(status.obs_seq == 2 && status.next_ch == CH_B, "no park before B");
    cmd.obs_ack = status.obs_seq;
    notified(TEST_CONTROLLER_CH);
    notified(CH_B);
    CHECK(armed && last_dispatched_ch == CH_N && status.obs_seq == 2, "the non-user slot parked");
    uint32_t done = completed_seq;
    notified(CH_N);
    CHECK(completed_seq == done && status.ack_seq == cmd.seq, "the non-user slot was counted");
}

// run_to_thread(0) names the padding channel, which is never dispatched: rejected, even when
// the schedule has padding.
static void run_to_padding_is_rejected(void) {
    setup();
    user_schedule.num_timeslices = 3;
    user_schedule.timeslice_ch[2] = 0;
    user_schedule.timeslices[2] = 50000000;
    user_schedule.is_user_partition[2] = false;
    command(TEST_CMD_RUN_TO_THREAD, 0, 0); // target_ch is 0
    CHECK((status.flags & TEST_FLAG_BAD_COMMAND) != 0 && status.ack_seq == cmd.seq, "run_to_thread(0) was accepted");
}

// A huge hstep count saturates rather than wrapping to a small one.
static void hstep_count_saturates(void) {
    setup();
    command(TEST_CMD_HSTEP, UINT32_MAX, 0);
    CHECK(slots_remaining == UINT32_MAX, "the hstep slot count wrapped");
}

// A run-to command that runs out of budget ends UNREACHABLE while advancing, and is
// acknowledged -- once.
static void unreachable_is_acknowledged(void) {
    setup();
    command(TEST_CMD_RUN_TO_HP, 0, 3);
    runto_budget = 1; // as if the target lay beyond the budget
    unsigned before = controller_notifications;
    notified(CH_A);
    CHECK((status_flags & TEST_FLAG_UNREACHABLE) != 0, "the command did not end UNREACHABLE");
    CHECK(status.ack_seq == cmd.seq, "the UNREACHABLE command was not acknowledged");
    CHECK(controller_notifications == before + 1, "the controller was not notified");
    notified(TEST_CONTROLLER_CH); // the controller signals back with nothing new
    CHECK(controller_notifications == before + 1, "a signal with no command was answered");
}

// A far target's budget saturates rather than wrapping to a small one.
static void far_target_budget_saturates(void) {
    setup();
    command(TEST_CMD_RUN_TO_HP, 0, 0x80000001u);
    CHECK(runto_budget == UINT32_MAX, "the run-to budget wrapped");
}

int main(void) {
    stale_expiry_is_not_the_next_slots();
    late_completion_is_absorbed();
    overrun_at_the_stop_point_is_reported();
    observation_parks_user_slots_only();
    unreachable_is_acknowledged();
    far_target_budget_saturates();
    hstep_count_saturates();
    run_to_padding_is_rejected();
    printf("HARNESS OK\n");
    return 0;
}
