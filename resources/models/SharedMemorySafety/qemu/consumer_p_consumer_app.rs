// This file will not be overwritten if HAMR codegen is rerun

use data::*;
use crate::bridge::consumer_p_consumer_api::*;
use vstd::prelude::*;

verus! {

  pub struct consumer_p_consumer {
    // PLACEHOLDER MARKER STATE VARS
  }

  impl consumer_p_consumer {
    pub fn new() -> Self
    {
      Self {
        // PLACEHOLDER MARKER STATE VAR INIT
      }
    }

    pub fn initialize<API: consumer_p_consumer_Put_Api> (
      &mut self,
      api: &mut consumer_p_consumer_Application_Api<API>)
      ensures
        // PLACEHOLDER MARKER INITIALIZATION ENSURES
    {
      log_info("initialize entrypoint invoked");
    }

    pub fn timeTriggered<API: consumer_p_consumer_Full_Api> (
      &mut self,
      api: &mut consumer_p_consumer_Application_Api<API>)
      requires
        // PLACEHOLDER MARKER TIME TRIGGERED REQUIRES
      ensures
        // PLACEHOLDER MARKER TIME TRIGGERED ENSURES
    {
      // QEMU test for SharedMemorySafety-design.md stages 2 and 4: every value that reaches
      // Rust is checked against the pattern the producer sent, and the invalid-message
      // counters are reported
      let big = api.get_big();
      let rec = api.get_rec();
      let padded = api.get_padded();
      report(&big, &rec, padded,
        api.get_big_num_invalid(), api.get_rec_num_invalid(), api.get_padded_num_invalid());
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

  #[verifier::external_body]
  pub fn report(big: &SharedMemorySafety::BigArray, rec: &SharedMemorySafety::BigRec_i,
                padded: Option<SharedMemorySafety::Padded_i>,
                big_invalid: u64, rec_invalid: u64, padded_invalid: u64)
  {
    // big[i] == n * 100000 + i and rec.payload[i] == (n + i) as u8, for the n that sent them;
    // an all-zero value is the data port's initial value, before anything was sent
    let n = big[0] / 100000;
    let big_ok = big.iter().enumerate().all(|(i, v)| *v == n * 100000 + i as i32);
    let rn = rec.header;
    let rec_ok = rec.payload.iter().enumerate().all(|(i, v)| *v == (rn as usize + i) as u8);
    log::info!("SMS|consumer: big n={} {} rec n={} {} invalid(big,rec,padded)=({},{},{})",
      n, if big_ok { "ok" } else { "CORRUPT" }, rn, if rec_ok { "ok" } else { "CORRUPT" },
      big_invalid, rec_invalid, padded_invalid);
    match padded {
      Some(p) => {
        let k = p.a as i32;
        let ok = p.b == k * 10 && p.flag == (k % 2 == 1) && p.mode == SharedMemorySafety::Mode::Run;
        log::info!("SMS|consumer: padded a={} b={} flag={} mode={:?} {}",
          p.a, p.b, p.flag, p.mode, if ok { "ok" } else { "CORRUPT" });
      }
      None => log::info!("SMS|consumer: padded none"),
    }
  }

  #[verifier::external_body]
  pub fn log_info(msg: &str)
  {
    log::info!("{0}", msg);
  }

  #[verifier::external_body]
  pub fn log_warn_channel(channel: u32)
  {
    log::warn!("Unexpected channel: {0}", channel);
  }

  // PLACEHOLDER MARKER GUMBO METHODS

}
