// Test model for SharedMemorySafety-design.md (hamr/codegen/doc): message types chosen so
// that each defect the design fixes has something to hit.  Used by SharedMemorySafetyTests.
package SharedMemorySafety {

    private import HAMR::*;

    // F4: an enum and a bool have invalid bit patterns a peer could write; the record also
    // has padding (a: 1 byte at offset 0, b: aligned to 4), which a hand-counted Data_Size
    // would get wrong (F2).  Layout: a@0 b@4 flag@8 mode@12, 16 bytes, 4-aligned.
    enum def Mode { Idle; Run; Fault; }

    part def Padded_i :> Struct {
        part a: Base_Types::Integer_8;
        part b: Base_Types::Integer_32;
        part flag: Base_Types::Boolean;
        part mode: Mode;
    }

    // F3: 4400 bytes.  A queue of one (8 + 2 * 4400 bytes) outgrows the 4 KiB region it used
    // to get from one element's size.
    part def BigArray :> Array {
        part :>> Base_Type : Base_Types::Integer_32;
        attribute :>> Dimensions = 1100;
        attribute :>> Array_Size_Kind = Array_Size_Kinds::Fixed;
    }

    // F3: a record declares no size, so its region used to be 4 KiB whatever it held.
    part def Payload :> Array {
        part :>> Base_Type : Base_Types::Unsigned_8;
        attribute :>> Dimensions = 5000;
        attribute :>> Array_Size_Kind = Array_Size_Kinds::Fixed;
    }

    part def BigRec_i :> Struct {
        part header: Base_Types::Integer_32;
        part payload: Payload;
    }

    ///////////////////////////////////////////////////////////////////////////

    // D6: a string must be NUL-terminated within its bounds, or a receiver that treats it
    // as a C string reads past it.  (initial carries a Character only because codegen needs
    // the model to use Character wherever it uses strings.)
    part def producer_t :> Periodic_Thread {
        port big: DataPort { out :>> type : BigArray; }
        port rec: DataPort { out :>> type : BigRec_i; }
        port padded: EventDataPort { out :>> type : Padded_i; }
        port label: EventDataPort { out :>> type : Base_Types::String; }
        port initial: EventDataPort { out :>> type : Base_Types::Character; }
    }

    part def producer_p :> Process {
        port big: DataPort { out :>> type : BigArray; }
        port rec: DataPort { out :>> type : BigRec_i; }
        port padded: EventDataPort { out :>> type : Padded_i; }
        port label: EventDataPort { out :>> type : Base_Types::String; }

        part producer: producer_t;

        connection c1 : PortConnection connect producer.big to big;
        connection c2 : PortConnection connect producer.rec to rec;
        connection c3 : PortConnection connect producer.padded to padded;
        connection c4 : PortConnection connect producer.label to label;

        attribute :>> Domain = 2;
    }

    // Rust, so the Rust data crate (and its layout assertions, D5) is generated, and received
    // values cross the FFI boundary into Rust through the validating dequeue (D6).
    part def consumer_t :> Periodic_Rust_Thread {
        // The Rust getters return the 4-5 KiB values on the stack, which outgrows Microkit's
        // default 8 KiB PD stack (the QEMU test, qemu/, runs this component)
        attribute :>> Stack_Size = 65536 [byte] as Size;
        port big: DataPort { in :>> type : BigArray; }
        port rec: DataPort { in :>> type : BigRec_i; }
        port padded: EventDataPort {
            in :>> type : Padded_i;
            attribute :>> Queue_Size = 2;
        }
        port label: EventDataPort { in :>> type : Base_Types::String; }
    }

    part def consumer_p :> Process {
        port big: DataPort { in :>> type : BigArray; }
        port rec: DataPort { in :>> type : BigRec_i; }
        port padded: EventDataPort {
            in :>> type : Padded_i;
            attribute :>> Queue_Size = 2;
        }
        port label: EventDataPort { in :>> type : Base_Types::String; }

        part consumer: consumer_t;

        connection c1 : PortConnection connect big to consumer.big;
        connection c2 : PortConnection connect rec to consumer.rec;
        connection c3 : PortConnection connect padded to consumer.padded;
        connection c4 : PortConnection connect label to consumer.label;

        attribute :>> Domain = 3;
    }

    ///////////////////////////////////////////////////////////////////////////

    part def proc_impl :> Processor {
        attribute :>> Frame_Period = 1000[ms];
        attribute :>> Clock_Period = 2[ms];
    }

    part def top_impl :> System {
        part proc: proc_impl;
        part producer_p: producer_p;
        part consumer_p: consumer_p;

        connection d1: PortConnection connect producer_p.big to consumer_p.big;
        connection d2: PortConnection connect producer_p.rec to consumer_p.rec;
        connection d3: PortConnection connect producer_p.padded to consumer_p.padded;
        connection d4: PortConnection connect producer_p.label to consumer_p.label;

        allocation pb0: Deployment_Properties::Actual_Processor_Binding allocate producer_p to proc;
        allocation pb1: Deployment_Properties::Actual_Processor_Binding allocate consumer_p to proc;

        attribute :>> Scheduling = MCS;
    }

    part def Periodic_Thread :> Thread {
        attribute :>> Period = 1[s];
        attribute :>> Dispatch_Protocol = Periodic;
    }

    part def Periodic_Rust_Thread :> Thread {
        attribute :>> Period = 1[s];
        attribute :>> Dispatch_Protocol = Periodic;
        attribute :>> Implementation_Language = Implementation_Languages::Rust;
    }
}
