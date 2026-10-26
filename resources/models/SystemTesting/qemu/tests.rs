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
//!   -1  breaks src's assumption `nonNegative`: a violation, and src is not dispatched
//!   42  src sends 42, which breaks dst2's assumption `notFortyTwo`: dst2, the hyperperiod's
//!       last dispatch, is not dispatched
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

/// Empty the test's own view of dst1's ack and dst2's fwd, so that what a test reads after
/// stepping is what that step produced.
fn drain() {
  while inspect::get_d1p_dst_ack().is_some() {}
  while inspect::get_d2p_dst_fwd().is_some() {}
}

/// dst1's whole pre-state: `val` as given, nothing pending on ping or cmd, `latest` set.
fn dst1(val: Option<i32>, latest: i32) -> inspect::d1p_dst_PreState {
  inspect::d1p_dst_PreState { val, ping: None, cmd: None, sv_latest: latest, sv_gotCmd: false }
}

/// Stop before dst1, after src has run with `mode`: where a test sets up both consumers of val.
fn before_dst1(mode: i32) {
  drain();
  let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
  inspect::put_srcp_src_mode(mode);
  let _ = api::run_to_thread(inspect::channels::d1p_dst_MON);
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

    // A broken assumption is a violation -- the sender, here the test, did not meet src's
    // contract -- declared on purpose here.  src's dispatch is rejected: it does not run,
    // so it does not adopt the mode it was given.
    fn assumption_not_met_rejects_the_dispatch() {
      observe::expect(Expect::CepPre(Thread::srcp_src));
      frame(-1);
      sys_assert!(inspect::get_srcp_src_sv_last() != Some(-1));
    }

    // FAILS: the same broken assumption, not declared
    fn assumption_not_met_fails() {
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

    // dst2's dispatch, the hyperperiod's last, is rejected: it received nothing, so in the next
    // frame, before dst2 runs, `NotYet` sees no event on dst2's input -- what the rejected
    // dispatch's check latched was put back
    fn rejected_last_dispatch_leaves_nothing_received() {
      observe::expect(Expect::CepPre(Thread::d2p_dst));
      frame(42);
      frame(5);
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

    // This test and the next are an ordered pair: this one sets up what the next one checks,
    // and SystemTestingTests checks the rejection between them (its INFO line is this test's).
    // Selected or run alone, the next one holds vacuously.
    //
    // with GUMBO off nothing is rejected: src sends 42, and the test ends parked before dst2,
    // which has not yet received it
    fn leaves_dst2_out_of_contract() {
      let _ = api::run_to_thread(inspect::channels::srcp_src_MON);
      inspect::put_srcp_src_mode(42);
      let _ = api::run_to_thread(inspect::channels::d2p_dst_MON);
    }

    // the runner's normalization before this test dispatches dst2 as the build says, not as
    // the last test left the switches: dst2 is rejected, so it did not forward the 42.  (FAILS
    // when GUMBO_CHECKS=off: then nothing is rejected.)
    fn normalization_checks_as_the_build_says() {
      sys_assert!(inspect::get_d2p_dst_fwd() != Some(42));
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

  // D39: setting an event input to "nothing pending", and the setup batches of a connection's
  // consumers.  What each consumer received is read back through dst1's ack and dst2's fwd.
  suite clearing {
    // dst2 is cleared and dst1 is not: only dst1 receives what src sent.  dst2's checks, whose
    // cursor moved with dst2's, see nothing arrive either, so its `quiet` holds.
    fn clearing_one_consumer_leaves_the_other() {
      before_dst1(5);
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: None });
      let _ = api::hstep(1);
      sys_assert_eq!(inspect::get_d1p_dst_ack(), Some(5));
      sys_assert_eq!(inspect::get_d2p_dst_fwd(), None);
    }

    // every consumer of val cleared: neither receives what src sent, yet the frame still
    // carries it -- `Sent` and `Arrived` read src's output, which a clear does not change (D27).
    // dst1's latest is set to what src sent, so `Echoed` holds without dst1 latching it.
    fn clearing_every_consumer_leaves_what_was_sent() {
      before_dst1(5);
      inspect::set_d1p_dst(dst1(None, 5));
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: None });
      let _ = api::hstep(1);
      sys_assert_eq!(inspect::get_d1p_dst_ack(), None);
      sys_assert_eq!(inspect::get_d2p_dst_fwd(), None);
    }

    // None for dst1 and Some(7) for dst2, in either order: dst1 receives nothing, dst2 receives
    // 7.  src sends nothing (99), so the setup's injection is an event on val that src did not
    // send, which `Sent` rules out -- declared.
    fn mixed_setup_none_first() {
      observe::expect(sent());
      before_dst1(99);
      inspect::set_d1p_dst(dst1(None, 0));
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: Some(7) });
      let _ = api::hstep(1);
      sys_assert_eq!(inspect::get_d1p_dst_ack(), None);
      sys_assert_eq!(inspect::get_d2p_dst_fwd(), Some(7));
    }

    fn mixed_setup_some_first() {
      observe::expect(sent());
      before_dst1(99);
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: Some(7) });
      inspect::set_d1p_dst(dst1(None, 0));
      let _ = api::hstep(1);
      sys_assert_eq!(inspect::get_d1p_dst_ack(), None);
      sys_assert_eq!(inspect::get_d2p_dst_fwd(), Some(7));
    }

    // an explicit put_ ends the batch: dst2's Some(1) after it starts a new batch and injects
    // again, so dst2 receives 1 -- not the 2 the put_ sent
    fn put_ends_the_setup_batch() {
      observe::expect(sent());
      before_dst1(99);
      inspect::set_d1p_dst(dst1(Some(1), 0));
      inspect::put_srcp_src_val(2);
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: Some(1) });
      let _ = api::hstep(1);
      sys_assert_eq!(inspect::get_d2p_dst_fwd(), Some(1));
    }

    // FAILS: the consumers of one connection cannot have different events pending
    fn conflicting_setup_fails() {
      observe::expect(sent());
      before_dst1(99);
      inspect::set_d1p_dst(dst1(Some(1), 0));
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: Some(2) });
      let _ = api::hstep(1);
    }

    // a command between two setters ends the batch, even one that dispatches nothing: the
    // second Some starts a new batch rather than conflicting with the first
    fn a_command_ends_the_setup_batch() {
      observe::expect(sent());
      before_dst1(99);
      inspect::set_d1p_dst(dst1(Some(1), 0));
      let _ = api::info_state();
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: Some(2) });
      let _ = api::hstep(1);
      sys_assert_eq!(inspect::get_d2p_dst_fwd(), Some(2));
    }

    // a command injected into dst1's unconnected cmd, then cleared: dst1 receives nothing and
    // notes nothing, and the assertions that read cmd as received -- CmdFirst and CmdSecond --
    // see nothing either, because the system cursor moved with dst1's
    fn clearing_an_unconnected_input() {
      before_dst1(5);
      inspect::put_d1p_dst_cmd(42);
      inspect::clear_d1p_dst_cmd();
      let _ = api::hstep(1);
      sys_assert_eq!(inspect::get_d1p_dst_sv_gotCmd(), Some(false));
    }

    // dst2's dispatch is rejected (42 breaks notFortyTwo), which leaves the 42 pending for it.
    // Cleared, it is gone: in the next frame, where src sends nothing, dst2 receives nothing and
    // is not rejected again.  (Not for GUMBO_CHECKS=off, where nothing is rejected.)
    fn clearing_after_a_rejected_dispatch() {
      frame(42);
      inspect::set_d2p_dst(inspect::d2p_dst_PreState { val: None });
      frame(99);
      let t = observe::take();
      sys_assert_eq!(count(&t, Kind::CepPre), 1);
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
