//@ HAMR: --platform ros2 --ros2-output-workspace-dir ../../hamr/structure

/*============================================================
    Turtle Control -- structure variant

    A minimal HAMR ROS 2 system used by the "Code-Level Development
    for ROS 2" documentation.  A micro-ROS node reads a wheel encoder
    on an MCU, an rclcpp node closes a control loop, and stock
    turtlesim is the plant.

        encoder --speed/overspeed--> pilot --cmdVel--> (turtlesim)
              <-- mode/trim ----------/    <--pose----/

    This variant models STRUCTURE only: components, ports,
    connections, and the platform-provided payload types (see
    RosMessages.sysml and Turtlesim.sysml -- the latter declares the
    turtlesim message type only; the turtlesim NODE is off-model
    here).  There are no naming
    properties, so every port keeps its default (port-path-derived)
    topic name and binding to the stock node is left entirely to
    deployment -- see REMAPPING on Pilot below.

    turtlesim is left OFF-MODEL here: no component declaration and no
    connection, bound purely in the deployment layer.  pilot.cmdVel
    and pilot.pose are therefore boundary ports.  The naming/ variant
    declares turtlesim as a platform-provided component and adds
    model-carried topic names and namespaces, which removes both
    remaps and brings type checking and the generation-time name
    checks to those two edges.

    Port kinds are chosen to exercise all three categories in both
    directions, and to cover both ways an arriving message can be
    taken up -- by dispatching a sporadic thread, and by waiting in a
    queue for a periodic one:

      speed     -- event data (dispatches the sporadic pilot)
      overspeed -- event      (a bare alarm; also dispatches the pilot)
      mode      -- data       (a setting, sampled by the periodic encoder)
      trim      -- event data (waits for the periodic encoder's next dispatch)
      cmdVel    -- data       (a continuous command)
      pose      -- data       (sampled state; turtlesim publishes at 62.5 Hz
                               but pilot reads only the latest on dispatch)

    The encoder is PERIODIC, so an arrival on trim cannot dispatch it.
    Codegen holds the arrival until the next period and consumes it
    there.  Only the AADL default Queue_Size of 1 is supported, so a
    second arrival within one period replaces the first.
  ============================================================*/

package TurtleControl_Structure {
    private import HAMR::*;

    part def TurtleControlSystem :> System {
        part proc : TurtleControlProcess;
    }

    part def TurtleControlProcess :> Process {
        // subcomponents
        part encoder : Encoder;
        part pilot   : Pilot;

        // connections
        connection cSpeed     : PortConnection connect encoder.speed     to pilot.speed;
        connection cOverspeed : PortConnection connect encoder.overspeed to pilot.overspeed;
        connection cMode      : PortConnection connect pilot.mode        to encoder.mode;
        connection cTrim      : PortConnection connect pilot.trim        to encoder.trim;

        // pilot.cmdVel and pilot.pose are unconnected: their peer is the stock
        // turtlesim node, which this variant leaves off-model and binds by
        // remapping (see REMAPPING on Pilot)
    }

    // The micro-ROS node: firmware on an MCU that samples a wheel encoder.
    part def Encoder :> Thread {
        // A setting rather than a stream of commands, so a DataPort: the
        // encoder samples whatever the pilot most recently published, and a
        // missed update is superseded rather than lost.
        in port mode : DataPort { in :>> type : OperatingMode; }

        // A discrete command, so an event data port rather than a data port: it is
        // an instruction to act, and skipping one is not the same as acting on the
        // newer one.  Because this node is PERIODIC an arrival cannot dispatch it,
        // so the arrival waits and is consumed at the next period.  Only the AADL
        // default Queue_Size of 1 is supported, so a second arrival within one
        // period replaces the first.
        in port trim : EventDataPort {
            in :>> type : TrimCommand;
        }

        // EventDataPort: each reading is a discrete message the pilot should
        // process, and its arrival is what dispatches the (sporadic) pilot.
        // A DataPort here would give the pilot nothing to wake on.
        out port speed : EventDataPort { out :>> type : WheelSpeed; }

        // EventPort: the alarm carries no payload -- the fact of it is the
        // whole message.  Codegen gives event ports an empty message type
        // (Empty.msg in the generated interfaces package).
        out port overspeed : EventPort;

        // Periodic: the encoder is sampled on a clock, independent of any
        // arriving message.  Its in data port is read at the top of each
        // period.
        attribute :>> Dispatch_Protocol = Periodic;
        attribute :>> Period = 100 [ms];

        // Ros_Node_Kind is what selects the micro-ROS backend for this thread.
        attribute :>> Ros_Node_Kind = microRos;
    }

    // REMAPPING: cmdVel and pose are boundary ports -- their peer is the stock
    // turtlesim node, which this variant does not model.  Each keeps its
    // path-derived default topic, so both need a manual bind at launch:
    //   ros2 run ... --ros-args \
    //     -r proc_pilot_cmdVel:=/turtle1/cmd_vel \
    //     -r proc_pilot_pose:=/turtle1/pose
    // turtlesim subscribes to the relative "turtle1/cmd_vel" and publishes the
    // relative "turtle1/pose"; launched without a namespace both resolve at the
    // root.  Write the match sides relative so they keep matching if this node
    // is later namespaced.
    part def Pilot :> Thread {
        // Two triggering ports: either an encoder reading or an overspeed alarm
        // dispatches the pilot, and codegen generates a handler for each.
        in port speed     : EventDataPort { in :>> type : WheelSpeed; }
        in port overspeed : EventPort;

        // Sampled, not triggering: turtlesim publishes pose continuously, but
        // the pilot reads the latest value when it is dispatched by one of the
        // ports above rather than waking on every pose message.
        in port pose : DataPort { in :>> type : turtlesim::Pose; }

        out port cmdVel : DataPort { out :>> type : geometry_msgs::Twist; }
        out port mode   : DataPort { out :>> type : OperatingMode; }

        // The sending counterpart of encoder.trim.  How an arrival is buffered is
        // a property of the RECEIVING end, so nothing about it is declared here.
        out port trim : EventDataPort { out :>> type : TrimCommand; }

        attribute :>> Dispatch_Protocol = Sporadic;

        // Optional -- ros2 is the default.  Ros_Node_Kind only ever needs to be
        // declared to opt INTO micro-ROS: codegen treats a thread as micro-ROS
        // only on an explicit microRos value, so an absent property and an
        // explicit ros2 mean the same thing.  Stated here for contrast with
        // Encoder above, where the property is load-bearing.
        attribute :>> Ros_Node_Kind = ros2;

        // No Period.  AADL reads Period on a sporadic thread as a minimum
        // inter-arrival time, but nothing generated enforces it and the ROS 2
        // backend ignores the property entirely for sporadic components, so
        // declaring one would state a bound no artifact honors.
    }

    // Data Types
    //
    // These are ordinary model-defined types, so codegen emits a .msg file for
    // each into the generated <system>_interfaces package -- the contrast with
    // the platform-provided types in RosMessages.sysml and Turtlesim.sysml,
    // for which no .msg is emitted and the native ROS type flows instead.

    part def WheelSpeed :> Data {
        part rpm : Base_Types::Float_32;
    }

    part def TrimCommand :> Data {
        part deltaRpm : Base_Types::Float_32;
    }

    enum def OperatingMode {
        enum Idle;
        enum Run;
        enum Fault;
    }
}
