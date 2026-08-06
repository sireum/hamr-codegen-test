//@ HAMR: --platform ros2 --ros2-output-workspace-dir ../../hamr/logging

/*============================================================
    Turtle Control -- logging variant

    The naming/ variant with one addition: a LOGGER node, and the
    INFRASTRUCTURE-PROVIDED PORTS that feed it.

        encoder --/rover/speed------------> pilot --/turtle1/cmd_vel--> turtle
              <--/rover/proc_encoder_mode--/      <--/turtle1/pose-----/
              \--/rosout-----------------------------------------> logger

    WHAT AN INFRASTRUCTURE-PROVIDED PORT IS

    Every port in the structure/ and naming/ variants is one the
    model DECLARES and codegen REALIZES: codegen creates the
    publisher or subscription, and application code drives it through
    a generated put_/get_ API.

    'rosout' is different.  Every ROS node already has a built-in
    /rosout log publisher, driven by the rcl logging infrastructure
    rather than by application code.  A port named 'rosout' does not
    declare a new thing -- it REFERS to that built-in one.  The name
    is therefore reserved: such a port must be an EventDataPort typed
    rcl_interfaces::Log, and its topic is pinned by the platform to
    /rosout, so the usual path-derived naming does not apply and a
    conflicting Ros_Topic_Name is an error.

    (A port with any OTHER name carrying rcl_interfaces::Log is
    entirely ordinary -- a log relay republishing filtered records on
    a custom topic is modeled that way, with no restrictions.)

    WHY THE PORTS ARE HERE AT ALL

    They direct codegen; they add no data plane.

      encoder.rosout (out, micro-ROS) -- the ENABLEMENT TRIGGER.  An
        rclcpp node publishes /rosout by default, but a micro-ROS
        node does not: its logging is console-only unless rcl logging
        is configured.  The port's presence is what makes codegen
        emit that setup and set the firmware flags.  Omit the port
        and the encoder's log records never leave the MCU.

      logger.rosout (in, rclcpp) -- makes codegen generate the
        /rosout subscription.  Nothing about /rosout is automatic on
        the consuming side: subscribing is a property of one port,
        not of the topic.

    Either side could be hand-wired after codegen instead.  Declaring
    the ports is how the model states the intent and gets the setup
    generated.

    WHAT IS DELIBERATELY NOT MODELED

    pilot has no rosout port, yet it still publishes to /rosout --
    rclcpp does that by default whether or not anyone models it.  The
    same is true of turtlesim.  /rosout is a many-writer topic and
    the logger will receive all of it.

    That is the point of the cLog connection below: on a topic
    everything writes to, the model records WHICH producer's flow it
    cares about.  Here that is the encoder, because the encoder is
    the one whose logging had to be deliberately enabled.
  ============================================================*/

package TurtleControl_Logging {
    private import HAMR_AADL_Preview::*;
    private import HAMR::*;

    part def TurtleControlSystem :> System {
        part proc : TurtleControlProcess;
    }

    part def TurtleControlProcess :> Process {
        part encoder : Encoder {
            attribute :>> Ros_Namespace = "rover";

            port :>> speed {
                attribute :>> Ros_Topic_Name = "speed";
            }
        }

        part pilot : Pilot {
            attribute :>> Ros_Namespace = "rover";
        }

        // The logger is namespaced like the other generated nodes.  That
        // affects its NODE name (/rover/logger) but not the topic it
        // subscribes to: /rosout is platform-pinned and absolute, so unlike
        // encoder.speed it does not compose with the namespace.
        part logger : Logger {
            attribute :>> Ros_Namespace = "rover";
        }

        part turtle : turtlesim::turtlesim_node;

        // connections
        connection cSpeed     : PortConnection connect encoder.speed     to pilot.speed;
        connection cOverspeed : PortConnection connect encoder.overspeed to pilot.overspeed;
        connection cMode      : PortConnection connect pilot.mode        to encoder.mode;
        connection cTrim      : PortConnection connect pilot.trim        to encoder.trim;

        connection cVel  : PortConnection connect pilot.cmdVel to turtle.cmdVel;
        connection cPose : PortConnection connect turtle.pose  to pilot.pose;

        // OPTIONAL, and it generates nothing.  Both endpoints are pinned to
        // /rosout and each side's code is already determined by its own port,
        // so codegen derives nothing from this edge -- not even type checking,
        // since port validation independently forces rcl_interfaces::Log on
        // both ends.
        //
        // It is here because it is the only place the model can say which
        // producer's log flow it cares about on a topic that everything
        // writes to.  Delete it and the generated code is byte-identical;
        // what is lost is the statement of intent.
        connection cLog : PortConnection connect encoder.rosout to logger.rosout;
    }

    part def Encoder :> Thread {
        in  port mode      : DataPort      { in  :>> type : OperatingMode; }
        out port speed     : EventDataPort { out :>> type : WheelSpeed; }
        out port overspeed : EventPort;

        // This node is PERIODIC, so an arrival here cannot dispatch it: the arrival
        // waits and is consumed at the next period.  Only the AADL default
        // Queue_Size of 1 is supported, so a second arrival within one period
        // replaces the first.
        in port trim : EventDataPort {
            in :>> type : TrimCommand;
        }

        // The reserved infrastructure port.  No publisher and no put_rosout API
        // are generated for it; what its presence does is make generated init
        // call rcl_logging_configure and set RCL_LOGGING_ENABLED in the emitted
        // colcon.meta, so this node's LOG_INFO/LOG_WARN/LOG_ERROR records reach
        // /rosout instead of only the console.
        out port rosout : EventDataPort {
            out :>> type : rcl_interfaces::Log;

            // Optional -- the reserved name already implies both, and codegen
            // rejects any other value.  Stated here because this is the variant
            // that teaches the mechanism.
            attribute :>> Port_Provenance = Provenances::Infrastructure;
            attribute :>> Ros_Topic_Name = "/rosout";
        }

        attribute :>> Dispatch_Protocol = Periodic;
        attribute :>> Period = 100 [ms];

        attribute :>> Ros_Node_Kind = microRos;
    }

    part def Pilot :> Thread {
        in  port speed     : EventDataPort { in  :>> type : WheelSpeed; }
        in  port overspeed : EventPort;
        in  port pose      : DataPort      { in  :>> type : turtlesim::Pose; }

        out port cmdVel : DataPort { out :>> type : geometry_msgs::Twist; }
        out port mode   : DataPort { out :>> type : OperatingMode; }

        out port trim : EventDataPort { out :>> type : TrimCommand; }

        // Deliberately NO rosout port.  The pilot is an rclcpp node, so it
        // publishes /rosout regardless -- the port would be documentation with
        // no generated consequence.  Leaving it off keeps the model's rosout
        // story about the node where the port actually changes something.

        attribute :>> Dispatch_Protocol = Sporadic;

        attribute :>> Ros_Node_Kind = ros2;
    }

    // Consumes the log stream.  An rclcpp node on purpose: a micro-ROS consumer
    // would need static receive buffers sized for Log's unbounded strings
    // (name, msg, file, function), and would pull every node's log traffic
    // across the agent link -- a real cost on a constrained transport.
    part def Logger :> Thread {
        // The reserved port on the consuming side.  Ordinary generation: this
        // produces a normal subscription to /rosout.  The topic name defaults
        // to /rosout and needs no declaration.
        in port rosout : EventDataPort {
            in :>> type : rcl_interfaces::Log;
        }

        // Sporadic: rosout is an in event data port, so each arriving record
        // dispatches the thread and every record is processed.  A DataPort here
        // would sample the newest record and drop the rest, which for a log is
        // exactly wrong.
        attribute :>> Dispatch_Protocol = Sporadic;

        attribute :>> Ros_Node_Kind = ros2;
    }

    // Data Types
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
