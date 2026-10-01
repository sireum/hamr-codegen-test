// This file will not be overwritten if HAMR codegen is rerun

//! System tests for models/SystemTesting, run by SystemTestingTests under QEMU.
//!
//! Several of these tests are MEANT to fail: they check that the test controller turns a
//! contract violation into a failed test.  SystemTestingTests knows which, and checks each
//! test's verdict and its TEST lines against what is expected -- for this build and for
//! builds with GUMBO_CHECKS=off, with both checks off, and with LIST_TESTS=1.
//!
//! The faults are in the behaviour code, triggered by the `mode` a test injects into src:
//!   99  src sends nothing (not a fault)
//!   13  src sends 14 but remembers 13: breaks src's `echo` and the composition's `Echoed`
//!   77  dst2 (C) forwards 78: breaks dst2's `forward`
//!   -1  breaks src's assumption `nonNegative`: information, not a failure
//!   55  src spins past its watchdog, once
//!   56  the same, once, for a second overrun test
//!   57  the same, once, for a third

use crate::system_tests::api;
use crate::system_tests::inspect;
use crate::system_tests::observe;
use crate::system_tests::observe::{Expect, Kind, Thread};
use crate::{system_tests, sys_assert, sys_assert_eq};

/// One frame of src, dst1 and dst2, with src reading `mode`.
fn frame(mode: i32) {
  let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
  inspect::put_srcp_src_mode(mode);
  let _ = api::hstep(1);
}

fn count(t: &observe::Taken, kind: Kind) -> usize {
  t.iter().filter(|v| v.kind == kind).count()
}

fn echoed() -> Expect {
  Expect::SysAssert(observe::sys::nominal::COMPOSITION, observe::sys::nominal::Echoed)
}

fn sent() -> Expect {
  Expect::SysAssert(observe::sys::nominal::COMPOSITION, observe::sys::nominal::Sent)
}

system_tests! {
  suite checks {
    fn nominal_frame() {
      frame(5);
    }

    // FAILS: one FAIL line for both violations
    fn thread_and_system_violation() {
      frame(13);
    }

    fn expected_violations_pass() {
      observe::expect(Expect::CepPost(Thread::srcp_src));
      observe::expect(echoed());
      frame(13);
    }

    // FAILS: the expected violation does not occur
    fn expected_but_absent() {
      observe::expect(Expect::CepPost(Thread::srcp_src));
      frame(5);
    }

    fn taken_violations_pass() {
      frame(13);
      let t = observe::take();
      sys_assert!(t.contains(Expect::CepPost(Thread::srcp_src)));
      sys_assert!(t.contains(echoed()));
    }

    fn nominal_after_negative() {
      frame(5);
    }

    fn assumption_not_met_is_information() {
      frame(-1);
    }

    // FAILS: the C thread's guarantee
    fn c_thread_violation() {
      frame(77);
    }

    // FAILS: the violating dispatch is the command's last; it is still charged to this test
    fn last_slot_violation_charged() {
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(13);
      let _ = api::sstep(1);
    }

    // a value a test injects into dst2's output is not dst2's own: in a frame where src sends
    // nothing, dst2 sends nothing either, and its `quiet` guarantee holds
    fn injected_output_is_not_the_producers() {
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(99);
      let _ = api::run_to_thread(inspect::channels::d2p_dst_MON);
      inspect::put_d2p_dst_fwd(5);
      let _ = api::sstep(1);
    }

    // commands that dispatch nothing check nothing
    fn nothing_dispatched_nothing_checked() {
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(13);
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      let _ = api::info_state();
      inspect::put_srcp_src_mode(5);
    }

    // what a test injects into src's output after src ran is what the consumers receive, so
    // the system assertions see it too: src sent nothing (mode 99), yet the frame carries an
    // event on src.val -- which `Sent` rules out
    fn injected_output_reaches_the_system_assertions() {
      observe::expect(sent());
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(99);
      let _ = api::run_to_thread(inspect::channels::d1p_dst_MON);
      inspect::put_srcp_src_val(5);
      let _ = api::hstep(1);
    }

    // the same, injected before src runs -- at the frame's start, where the command stopped
    // before the frame's first park: the injection belongs to the frame that follows
    fn injection_at_frame_start_belongs_to_that_frame() {
      observe::expect(sent());
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(99);
      inspect::put_srcp_src_val(5);
      let _ = api::hstep(1);
    }

    // a command injected into dst1's unconnected input is seen by both assertions that read
    // it after dst1 -- the first one's read does not use it up
    fn injected_input_is_seen_by_every_assertion() {
      let _ = api::run_to_thread(inspect::channels::d1p_dst_MON);
      inspect::put_d1p_dst_cmd(42);
      let _ = api::sstep(1);
    }

    // a state variable injected into src is the pre-state of src's next dispatch, not src's
    // state now: dst1 runs first, and `Echoed` compares with the state src actually has
    fn injected_state_is_the_owners_only() {
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(3);
      let _ = api::run_to_thread(inspect::channels::d1p_dst_MON);
      inspect::put_srcp_src_sv_last(7);
      let _ = api::sstep(1);
    }

    // an injection is in the frame it is made in: dst1 has already run in this hyperperiod,
    // so it receives the value in the next one, where src did not send it -- the controller
    // says so where it happens
    fn injection_after_a_consumer_ran_is_noted() {
      frame(5);
      let _ = api::run_to_thread(inspect::channels::d2p_dst_MON);
      inspect::put_srcp_src_val(5);
      let _ = api::hstep(1);
    }
  }

  suite switched(gumbo = off) {
    // FAILS: a GUMBO violation cannot be reported while GUMBO is off, so expecting one fails
    // at once, saying why -- not "did not occur" at the end
    fn expecting_a_switched_off_layer_fails() {
      observe::expect(Expect::CepPost(Thread::srcp_src));
      frame(13);
    }

    // the suite turns GUMBO off: src's CEP_Post is not reported, Echoed still is
    fn suite_hides_gumbo() {
      frame(13);
      let t = observe::take();
      sys_assert_eq!(count(&t, Kind::CepPost), 0);
      sys_assert!(t.contains(echoed()));
    }
  }

  suite toggles {
    // a suite is a namespace: `checks` has a test of the same name
    fn nominal_frame() {
      frame(5);
    }

    // the suite's setting does not reach the next suite
    fn next_suite_checks_again() {
      frame(13);
      let t = observe::take();
      sys_assert_eq!(count(&t, Kind::CepPost), 1);
    }

    fn off_then_on_within_a_test() {
      observe::set_gumbo(false);
      frame(13);
      observe::set_gumbo(true);
      frame(13);
      let t = observe::take();
      sys_assert_eq!(count(&t, Kind::CepPost), 1);
    }

    // FAILS only when GUMBO_CHECKS=off took the checks out of the build
    fn reenable_gumbo() {
      observe::set_gumbo(true);
      frame(5);
    }

    // parks happen exactly while some layer is live
    fn parks_only_while_live() {
      let before = api::info_state().obs_seq;
      frame(5);
      let after = api::info_state().obs_seq;
      if observe::any_live() {
        sys_assert!(after != before);
      } else {
        sys_assert_eq!(after, before);
      }
    }
  }

  suite watchdog {
    // FAILS: src overruns its slot.  The system assertions stay suspended for the rest of the
    // frame -- the aborted dispatch's output still reaches dst1 and dst2 in it -- and resume in
    // the next hyperperiod (in the next test); the GUMBO checks see the 13 fault at once.
    fn overrun_fails_the_test() {
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(55);
      let _ = api::sstep(1);
      inspect::put_srcp_src_mode(13);
      let _ = api::hstep(1);
    }

    fn after_overrun() {
      frame(5);
    }

    // FAILS: src overruns again, and the dispatch that overran sends 56.  Its re-dispatch
    // reads 99 and sends nothing: its check must not take the overran dispatch's 56 for this
    // dispatch's output.  The test fails for the overrun alone.
    fn overrun_then_quiet() {
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(56);
      let _ = api::sstep(1);
      inspect::put_srcp_src_mode(99);
      let _ = api::hstep(1);
    }

    // the system assertions resume at the hyperperiod after an overrun: an injection made at
    // that frame's first stop, before src runs, is that frame's -- and so is seen by `Sent`
    fn injection_at_frame_start_after_overrun() {
      observe::expect(sent());
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(99);
      inspect::put_srcp_src_val(5);
      let _ = api::hstep(1);
    }

    // FAILS: src overruns once more, and the command after it stops on the trailing pad,
    // after the hyperperiod's last dispatch.  What the test injects there belongs to the next
    // frame -- the one the system assertions resume in -- so `Sent` sees it.
    fn injection_on_the_trailing_pad_after_overrun() {
      observe::expect(sent());
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(57);
      let _ = api::sstep(1);
      let last = api::schedule().num_timeslices - 1;
      let _ = api::run_to_slot(last);
      inspect::put_srcp_src_mode(99);
      inspect::put_srcp_src_val(5);
      // the pad is the hyperperiod's last slot: hstep(1) would only finish it, so 2
      let _ = api::hstep(2);
    }

    // FAILS, and must stay last: after api::stop() nothing is dispatched again, so a test
    // that stops the session is failed rather than left to freeze the ones after it
    fn stop_is_a_failure() {
      let _ = api::stop();
      let _ = api::sstep(1);
    }
  }
}
