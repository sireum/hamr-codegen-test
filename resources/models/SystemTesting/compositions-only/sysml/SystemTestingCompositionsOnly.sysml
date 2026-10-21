// SystemTesting with compositions but no thread contracts, for SystemTestingTests: the
// system-assertion monitors (runtime monitoring) and the test controller's system layer
// check the compositions over ports alone.  The sys-assert monitors used to depend on the
// GUMBO monitor's generated code, so a model like this got no monitor at all, silently.
//
//   src   (Rust) sends the `mode` it reads on `val`, and signals `ping`,
//   dst1  (Rust) acknowledges what arrives on `val`,
//   dst2  (C)    forwards what arrives on `val`;
//
// `nominal` and `head` are compositions that read ports only.
package SystemTestingCompositionsOnly {
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
                    s_val   = src.val;
                    d2_val  = dst2.val;
                    s_ping  = src.ping;
                    d1_ping = dst1.ping;

                schema {
                    src;
                    dst1;
                    dst2
                }

                property Pinged "a ping dst1 received, src signalled" {
                    after dst1 "dst1's ping and src's, seen by the system":
                        HasEvent(d1_ping) implies HasEvent(s_ping);
                }

                property Received "what dst2 receives is what src sent" {
                    after dst2 "dst2's input, seen by the system":
                        HasEvent(d2_val) implies HasEvent(s_val);
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
