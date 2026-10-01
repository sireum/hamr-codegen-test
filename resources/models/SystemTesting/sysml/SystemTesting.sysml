// Model for SystemTestingTests: the test controller's run-time contract checking
// (hamr/codegen/doc/TestScheduler-design.md, stage 7), exercised under QEMU.
//
//   src   (Rust) reads an injected `mode`, sends it on `val` -- unless it is 99 -- and
//               remembers it in `last`.  Its behaviour code breaks its own guarantee when
//               mode == 13 (it sends 14), and overruns its watchdog once when mode == 55.
//   dst1  (Rust) latches what arrives on `val` and acknowledges it on `ack`, and notes whether
//               a command arrived on its unconnected `cmd`.
//
// src also signals `ping`, a pure event port (no payload), whenever it sends on `val`; dst1
// receives it.  Both a contract (src's `pinged`) and a composition (`Pinged`) read it.
//
// `ack` runs back from dst1 to src, which is dispatched first: a feedback edge, so src
// receives in one frame what dst1 sent in the previous one.
//   dst2  (C)    forwards what arrives on `val` to `fwd`; it forwards 77 as 78.
//
// `val` fans out to two consumers, one of them a C thread, and the composition's `Echoed`
// assertion relates dst1's latch to src's `last`, so one fault in src breaks both a thread
// guarantee and a system assertion.
package SystemTesting {
    private import HAMR::*;

    part def Periodic_Thread :> Thread {
        attribute :>> Period = 1[s];
        attribute :>> Dispatch_Protocol = Periodic;
    }

    part def Periodic_Rust_Thread :> Periodic_Thread {
        attribute :>> Implementation_Language = Rust;
    }

    ///////////////////////////////////////////////////////////////////////////
    part def src_t :> Periodic_Rust_Thread {
        // unconnected: only the test controller writes it
        port mode: DataPort { in :>> type : Base_Types::Integer_32; }
        port val: EventDataPort { out :>> type : Base_Types::Integer_32; }
        // a pure event port: signalled whenever src sends on val
        out port ping: EventPort;
        // from dst1, which runs after src: received a frame late
        port ack: EventDataPort { in :>> type : Base_Types::Integer_32; }
        language "GUMBO" /*{
            state
                last: Base_Types::Integer_32;
                gotAck: Base_Types::Boolean;
            initialize
                modifies last, gotAck;
                guarantee initLast:
                    last == 0 [i32];
                guarantee initGotAck:
                    not gotAck;
            compute
                modifies last, gotAck;
                assume nonNegative:
                    mode >= 0 [i32];
                guarantee echo "remembers the mode it read, and sends it unless it is 99":
                    last == mode &
                    ((mode != 99 [i32]) implies MustSend(val, mode)) &
                    ((mode == 99 [i32]) implies NoSend(val));
                guarantee acked "notes whether an acknowledgement arrived":
                    (HasEvent(ack) implies gotAck) & ((not HasEvent(ack)) implies (not gotAck));
                guarantee pinged "signals ping exactly when it sends":
                    ((mode != 99 [i32]) implies MustSend(ping)) & ((mode == 99 [i32]) implies NoSend(ping));
        }*/
    }

    part def src_p :> Process {
        port val: EventDataPort { out :>> type : Base_Types::Integer_32; }
        out port ping: EventPort;
        port ack: EventDataPort { in :>> type : Base_Types::Integer_32; }
        part src: src_t;
        connection c1: PortConnection
            connect src.val to val;
        connection c3: PortConnection
            connect src.ping to ping;
        connection c2: PortConnection
            connect ack to src.ack;
        attribute :>> Domain = 2;
    }

    ///////////////////////////////////////////////////////////////////////////
    part def dst1_t :> Periodic_Rust_Thread {
        port val: EventDataPort { in :>> type : Base_Types::Integer_32; }
        port ack: EventDataPort { out :>> type : Base_Types::Integer_32; }
        // unconnected: only the test controller writes it
        port cmd: EventDataPort { in :>> type : Base_Types::Integer_32; }
        // src's ping; dst1 does nothing with it
        in port ping: EventPort;
        language "GUMBO" /*{
            state
                latest: Base_Types::Integer_32;
                gotCmd: Base_Types::Boolean;
            initialize
                modifies latest, gotCmd;
                guarantee initLatest:
                    latest == 0 [i32];
                guarantee initGotCmd:
                    not gotCmd;
            compute
                modifies latest, gotCmd;
                guarantee noted "notes whether a command arrived":
                    (HasEvent(cmd) implies gotCmd) & ((not HasEvent(cmd)) implies (not gotCmd));
                guarantee latch "record what arrives":
                    HasEvent(val) implies latest == val;
                guarantee hold "nothing arrives, nothing changes":
                    (not HasEvent(val)) implies latest == In(latest);
                guarantee acks "acknowledges what arrives":
                    (HasEvent(val) implies MustSend(ack, val)) & ((not HasEvent(val)) implies NoSend(ack));
        }*/
    }

    part def dst1_p :> Process {
        port val: EventDataPort { in :>> type : Base_Types::Integer_32; }
        port ack: EventDataPort { out :>> type : Base_Types::Integer_32; }
        in port ping: EventPort;
        part dst: dst1_t;
        connection c1: PortConnection
            connect val to dst.val;
        connection c3: PortConnection
            connect ping to dst.ping;
        connection c2: PortConnection
            connect dst.ack to ack;
        attribute :>> Domain = 3;
    }

    ///////////////////////////////////////////////////////////////////////////
    part def dst2_t :> Periodic_Thread {
        port val: EventDataPort { in :>> type : Base_Types::Integer_32; }
        port fwd: EventDataPort { out :>> type : Base_Types::Integer_32; }
        language "GUMBO" /*{
            compute
                guarantee forward "pass on what arrives":
                    HasEvent(val) implies MustSend(fwd, val);
                guarantee quiet "nothing arrives, nothing is sent":
                    (not HasEvent(val)) implies NoSend(fwd);
        }*/
    }

    part def dst2_p :> Process {
        port val: EventDataPort { in :>> type : Base_Types::Integer_32; }
        port fwd: EventDataPort { out :>> type : Base_Types::Integer_32; }
        part dst: dst2_t;
        connection c1: PortConnection
            connect val to dst.val;
        connection c2: PortConnection
            connect dst.fwd to fwd;
        attribute :>> Domain = 4;
    }

    ///////////////////////////////////////////////////////////////////////////
    part def proc_impl :> Processor {
        attribute :>> Frame_Period = 1000[ms];
        attribute :>> Clock_Period = 2[ms];
    }

    part def top_impl :> System {
        part proc: proc_impl;
        part srcp: src_p;
        part d1p: dst1_p;
        part d2p: dst2_p;
        connection v1: PortConnection
            connect srcp.val to d1p.val;
        connection v2: PortConnection
            connect srcp.val to d2p.val;
        connection v3: PortConnection
            connect d1p.ack to srcp.ack;
        connection v4: PortConnection
            connect srcp.ping to d1p.ping;
        allocation b0: Deployment_Properties::Actual_Processor_Binding
            allocate srcp to proc;
        allocation b1: Deployment_Properties::Actual_Processor_Binding
            allocate d1p to proc;
        allocation b2: Deployment_Properties::Actual_Processor_Binding
            allocate d2p to proc;

        language "GUMBO" /*{
            composition nominal {
                components
                    src  = srcp.src;
                    dst1 = d1p.dst;
                    dst2 = d2p.dst;

                ports
                    s_val    = src.val;
                    // a connected input: what dst2 received, latched at its dispatch
                    d2_val   = dst2.val;
                    // an unconnected input: read as what its reader received
                    d1_cmd   = dst1.cmd;
                    // a connected input on a feedback edge: what src received, a frame late
                    s_ack    = src.ack;
                    // a pure event port: src's output, and what dst1 received
                    s_ping   = src.ping;
                    d1_ping  = dst1.ping;

                state
                    s_last   = src.last;
                    d_latest = dst1.latest;
                    d_got    = dst1.gotCmd;
                    s_gotAck = src.gotAck;

                schema {
                    src;
                    dst1;
                    dst2
                }

                property Echoed "dst1 holds what src last sent" {
                    after dst1 "dst1 has latched src's value, if src sent one":
                        (s_last != 99 [i32]) implies (d_latest == s_last);
                }

                // two assertions at one place read the same event: both see it
                property CmdFirst "a command dst1 received, it noted" {
                    after dst1 "dst1's command, read first":
                        HasEvent(d1_cmd) implies d_got;
                }

                property CmdSecond "a command dst1 noted, it received" {
                    after dst1 "dst1's command, read again":
                        d_got implies HasEvent(d1_cmd);
                }

                // a pure event port, as a connected input's alias and as an output's
                property Pinged "a ping dst1 received, src signalled" {
                    after dst1 "dst1's ping and src's, seen by the system":
                        HasEvent(d1_ping) implies HasEvent(s_ping);
                }

                // an input alias is what the reader received -- here last frame's ack, which
                // dst1 has not yet sent again when src completes
                property Acked "what src received on ack is what it noted" {
                    after src "src's ack input, seen by the system":
                        (HasEvent(s_ack) implies s_gotAck) & (s_gotAck implies HasEvent(s_ack));
                }

                // read at a different place from Sent: each place sees this frame's event
                property Arrived "src's event is there when src sent one" {
                    after dst1 "src's event, seen by the system before dst2 runs":
                        (s_last != 99 [i32]) implies HasEvent(s_val);
                }

                property Received "what dst2 receives is what src sent" {
                    after dst2 "dst2's input, seen by the system":
                        HasEvent(d2_val) implies HasEvent(s_val);
                }

                property Sent "src's event is there exactly when src sent one this frame" {
                    after dst2 "src's event, seen by the system":
                        (HasEvent(s_val) implies (s_last != 99 [i32])) &
                        ((s_last != 99 [i32]) implies HasEvent(s_val));
                }
            }

            // A composition about part of the system: dst1 is left out.  It runs between src
            // and dst2 on the deployed schedule and writes ack, which src reads -- codegen warns
            // -- but the run-time schedule check passes over it.
            composition partial {
                components
                    src  = srcp.src;
                    dst2 = d2p.dst;

                ports
                    p_val = dst2.val;
                    p_fwd = dst2.fwd;

                // src's state is read: dst1, left out, feeds src (ack) -- codegen warns
                state
                    p_last = src.last;

                schema {
                    src;
                    dst2
                }

                property Forwards "dst2 passes on what it receives" {
                    after dst2 "dst2's input and output, seen by the system":
                        HasEvent(p_val) implies HasEvent(p_fwd);
                }

                // always holds: it is here so the composition reads src's state, which is what
                // makes dst1's write to src matter (codegen warns only about values a check reads)
                property Noted "src's noted value is read by the system" {
                    after src "src's state, seen by the system":
                        p_last == p_last;
                }
            }

            // A composition that ends before the others: its frame ends at dst1's completion,
            // while nominal's and partial's end at dst2's -- each keeps its own frame.  It also
            // names dst2 without firing it, which codegen warns about.
            composition head {
                components
                    src  = srcp.src;
                    dst1 = d1p.dst;
                    dst2 = d2p.dst;

                ports
                    h_in  = dst1.val;
                    h_ack = dst1.ack;
                    h_fwd = dst2.fwd;

                schema {
                    src;
                    dst1
                }

                property Acks "dst1 acknowledges what it receives" {
                    after dst1 "dst1's input and acknowledgement, seen by the system":
                        HasEvent(h_in) implies HasEvent(h_ack);
                }

                // always holds: it is here so the composition reads dst2, which it never fires
                // (codegen warns only about values a check reads)
                property Untracked "dst2's output is read though dst2 never runs in head" {
                    after dst1 "dst2's output, seen by the system":
                        HasEvent(h_fwd) implies HasEvent(h_fwd);
                }
            }
        }*/
    }
}
