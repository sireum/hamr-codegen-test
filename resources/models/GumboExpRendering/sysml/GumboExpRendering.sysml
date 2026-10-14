// Regression model for SlangExpUtil's rendering of GUMBO expressions into executable
// Rust (GUMBOX) and Verus: operator precedence and quantifiers.  Each GUMBO library
// function below exercises one shape that used to be rendered with a different meaning
// (or not compile); see GumboExpRenderingTests.

package GumboExpRendering {

    private import HAMR::*;

    part def Bytes :> Array {
        part :>> Base_Type : Base_Types::Unsigned_8;
        attribute :>> Dimensions = 8;
        attribute :>> Array_Size_Kind = Array_Size_Kinds::Fixed;
        attribute :>> Data_Size = 8[byte];
    }

    part def Producer :> Thread {
        attribute :>> Period = 1000[ms];
        attribute :>> Dispatch_Protocol = Supported_Dispatch_Protocols::Periodic;
        attribute :>> Implementation_Language = Implementation_Languages::Rust;
        attribute :>> Compute_Execution_Time = 10[ms] .. 10[ms] as Compute_Execution_Time;
        attribute :>> Stack_Size = 1048576[byte] as Size;

        port output: DataPort { out :>> type : Bytes; }
    }

    part def Consumer :> Thread {
        attribute :>> Period = 1000[ms];
        attribute :>> Dispatch_Protocol = Supported_Dispatch_Protocols::Periodic;
        attribute :>> Implementation_Language = Implementation_Languages::Rust;
        attribute :>> Compute_Execution_Time = 10[ms] .. 10[ms] as Compute_Execution_Time;
        attribute :>> Stack_Size = 1048576[byte] as Size;

        port input: DataPort { in :>> type : Bytes; }
    }

    part def Producer_p :> Process {
        port output: DataPort { out :>> type : Bytes; }
        part producer: Producer;
        connection c1: PortConnection connect producer.output to output;
        attribute :>> Domain = 2;
    }

    part def Consumer_p :> Process {
        port input: DataPort { in :>> type : Bytes; }
        part consumer: Consumer;
        connection c1: PortConnection connect input to consumer.input;
        attribute :>> Domain = 3;
    }

    part def Proc :> Processor {
        attribute :>> Frame_Period = 1000[ms];
        attribute :>> Clock_Period = 2[ms];
    }

    part def Top_impl :> System {
        part proc: Proc;
        part producer: Producer_p;
        part consumer: Consumer_p;

        connection c1: PortConnection connect producer.output to consumer.input;

        allocation pb0: Deployment_Properties::Actual_Processor_Binding allocate producer to proc;
        allocation pb1: Deployment_Properties::Actual_Processor_Binding allocate consumer to proc;
    }
}

package ExpLib {
    private import HAMR::*;

    language "GUMBO" /*{
        library

        functions
            // non-short-circuit | over a short-circuit `and`: Rust's | binds tighter than &&
            def orOverCondAnd(a: Base_Types::Boolean, b: Base_Types::Boolean, c: Base_Types::Boolean): Base_Types::Boolean :=
                (a and b) | c;

            // exists whose body is a disjunction
            def existsOr(v: GumboExpRendering::Bytes): Base_Types::Boolean :=
                (0 .. 3) -> exists {in i; v#(i) == 1 [u8] | v#(i) == 2 [u8]};

            // exists whose body is an implication
            def existsImplies(v: GumboExpRendering::Bytes): Base_Types::Boolean :=
                (0 .. 3) -> exists {in i; v#(i) == 1 [u8] implies v#(i + 1) == 2 [u8]};

            // forall as the left operand of an implication
            def forallLeftOfImplies(v: GumboExpRendering::Bytes, b: Base_Types::Boolean): Base_Types::Boolean :=
                ((0 .. 3) -> forAll {in i; v#(i) == 0 [u8]}) implies b;

            // forall as the left operand of a disjunction
            def forallLeftOfOr(v: GumboExpRendering::Bytes, b: Base_Types::Boolean): Base_Types::Boolean :=
                ((0 .. 3) -> forAll {in i; v#(i) == 0 [u8]}) | b;

            // two quantifiers in one expression: each needs its own trigger
            def twoQuantifiers(v: GumboExpRendering::Bytes): Base_Types::Boolean :=
                ((0 .. 3) -> forAll {in i; v#(i) == 0 [u8]}) &
                ((0 .. 3) -> exists {in j; v#(j + 4) == 1 [u8]});
    }*/
}
