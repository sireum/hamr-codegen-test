// This file will not be overwritten if HAMR codegen is rerun

use data::*;
use crate::bridge::d1p_dst_api::*;
use vstd::prelude::*;

#[verus_verify]
pub struct d1p_dst {
  // BEGIN MARKER STATE VARS
  pub latest: i32,
  pub gotCmd: bool,
  // END MARKER STATE VARS
}

#[verus_verify]
impl d1p_dst {
  pub fn new() -> Self
  {
    Self {
      // BEGIN MARKER STATE VAR INIT
      latest: 0,
      gotCmd: false,
      // END MARKER STATE VAR INIT
    }
  }

  #[verus_spec(
    ensures
      // BEGIN MARKER INITIALIZATION ENSURES
      // guarantee initLatest
      final(self).latest == 0i32,
      // guarantee initGotCmd
      !final(self).gotCmd,
      // END MARKER INITIALIZATION ENSURES
  )]
  pub fn initialize<API: d1p_dst_Put_Api> (
    &mut self,
    api: &mut d1p_dst_Application_Api<API>)
  {
    log_info("initialize entrypoint invoked");
  }

  #[verus_spec(
    requires
      // BEGIN MARKER TIME TRIGGERED REQUIRES
      // assume AADL_Requirement
      //   All outgoing event ports must be empty
      old(api).ack.is_none(),
      // END MARKER TIME TRIGGERED REQUIRES
    ensures
      // BEGIN MARKER TIME TRIGGERED ENSURES
      // guarantee noted
      //   notes whether a command arrived
      (final(api).cmd.is_some() ==> final(self).gotCmd) &&
        (!(final(api).cmd.is_some()) ==> !final(self).gotCmd),
      // guarantee latch
      //   record what arrives
      final(api).val.is_some() ==>
        (final(self).latest == final(api).val.unwrap()),
      // guarantee hold
      //   nothing arrives, nothing changes
      !(final(api).val.is_some()) ==>
        (final(self).latest == old(self).latest),
      // guarantee acks
      //   acknowledges what arrives
      (final(api).val.is_some() ==>
        final(api).ack.is_some() &&
          (final(api).ack.unwrap() == final(api).val.unwrap())) &&
        (!(final(api).val.is_some()) ==> final(api).ack.is_none()),
      // END MARKER TIME TRIGGERED ENSURES
  )]
  pub fn timeTriggered<API: d1p_dst_Full_Api> (
    &mut self,
    api: &mut d1p_dst_Application_Api<API>)
  {
    log_info("compute entrypoint invoked");
    if let Some(v) = api.get_val() {
      self.latest = v;
      api.put_ack(v);
    }
    self.gotCmd = api.get_cmd().is_some();
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
