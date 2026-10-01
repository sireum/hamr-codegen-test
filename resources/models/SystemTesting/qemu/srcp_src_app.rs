// This file will not be overwritten if HAMR codegen is rerun

use data::*;
use crate::bridge::srcp_src_api::*;
use vstd::prelude::*;

#[verus_verify]
pub struct srcp_src {
  // BEGIN MARKER STATE VARS
  pub last: i32,
  pub gotAck: bool,
  // END MARKER STATE VARS
}

#[verus_verify]
impl srcp_src {
  pub fn new() -> Self
  {
    Self {
      // BEGIN MARKER STATE VAR INIT
      last: 0,
      gotAck: false,
      // END MARKER STATE VAR INIT
    }
  }

  #[verus_spec(
    ensures
      // BEGIN MARKER INITIALIZATION ENSURES
      // guarantee initLast
      final(self).last == 0i32,
      // guarantee initGotAck
      !final(self).gotAck,
      // END MARKER INITIALIZATION ENSURES
  )]
  pub fn initialize<API: srcp_src_Put_Api> (
    &mut self,
    api: &mut srcp_src_Application_Api<API>)
  {
    log_info("initialize entrypoint invoked");
  }

  #[verus_spec(
    requires
      // BEGIN MARKER TIME TRIGGERED REQUIRES
      // assume AADL_Requirement
      //   All outgoing event ports must be empty
      old(api).val.is_none(),
      old(api).ping.is_none(),
      // assume nonNegative
      old(api).mode >= 0i32,
      // END MARKER TIME TRIGGERED REQUIRES
    ensures
      // BEGIN MARKER TIME TRIGGERED ENSURES
      // guarantee echo
      //   remembers the mode it read, and sends it unless it is 99
      ((final(self).last == final(api).mode) &&
        ((final(api).mode != 99i32) ==>
          final(api).val.is_some() &&
            (final(api).val.unwrap() == final(api).mode))) &&
        ((final(api).mode == 99i32) ==>
          final(api).val.is_none()),
      // guarantee acked
      //   notes whether an acknowledgement arrived
      (final(api).ack.is_some() ==> final(self).gotAck) &&
        (!(final(api).ack.is_some()) ==> !final(self).gotAck),
      // guarantee pinged
      //   signals ping exactly when it sends
      ((final(api).mode != 99i32) ==>
        final(api).ping.is_some()) &&
        ((final(api).mode == 99i32) ==>
          final(api).ping.is_none()),
      // END MARKER TIME TRIGGERED ENSURES
  )]
  pub fn timeTriggered<API: srcp_src_Full_Api> (
    &mut self,
    api: &mut srcp_src_Application_Api<API>)
  {
    log_info("compute entrypoint invoked");
    let mode = api.get_mode();
    overrun_once(mode);
    self.last = mode;
    // what dst1 acknowledged last frame (the edge runs backwards through the schedule)
    self.gotAck = api.get_ack().is_some();
    // mode 99: send nothing
    if mode != 99 {
      // FAULT for SystemTestingTests: 13 is sent as 14
      let sent = if mode == 13 { 14 } else { mode };
      api.put_val(sent);
      api.put_ping();
    }
  }

  pub fn notify(
    &mut self,
    channel: microkit_channel)
  {
    // this method is called when the monitor does not handle the passed in channel
    match channel {
      _ => {
        log_warn_channel(channel)
      }
    }
  }
}

#[verus_verify(external_body)]
pub fn log_info(msg: &str)
{
  log::info!("{0}", msg);
}

#[verus_verify(external_body)]
pub fn log_warn_channel(channel: u32)
{
  log::warn!("Unexpected channel: {0}", channel);
}

// PLACEHOLDER MARKER GUMBO METHODS

// FAULT for SystemTestingTests: the first time mode is 55, the first time it is 56, and the
// first time it is 57, spin for several seconds -- past the test scheduler's 1 s watchdog --
// then carry on.
static mut OVERRAN: bool = false;
static mut OVERRAN_AGAIN: bool = false;
static mut OVERRAN_THIRD: bool = false;

#[verus_verify(external_body)]
pub fn overrun_once(mode: i32) {
  unsafe {
    let first = match mode {
      55 => !OVERRAN,
      56 => !OVERRAN_AGAIN,
      57 => !OVERRAN_THIRD,
      _ => false,
    };
    if first {
      match mode {
        55 => OVERRAN = true,
        56 => OVERRAN_AGAIN = true,
        _ => OVERRAN_THIRD = true,
      }
      let mut i: u64 = 0;
      while i < 1_000_000_000 {
        i = core::hint::black_box(i + 1);
      }
    }
  }
}
