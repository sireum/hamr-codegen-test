//@ HAMR: --platform ros2 --ros2-output-workspace-dir ../../hamr/naming

/*============================================================
    Turtle Control -- naming variant

    The same system as the structure/ variant, with two additions:
    model-carried NAMING (Ros_Namespace, Ros_Topic_Name) and stock
    turtlesim declared as a PLATFORM-PROVIDED COMPONENT.  Together
    these remove every deployment remap the structure variant needed
    and put the turtlesim edges under generation-time checking.

        encoder --/rover/speed------------> pilot --/turtle1/cmd_vel--> turtle
              <--/rover/proc_pilot_mode----/      <--/turtle1/pose-----/

    WHAT CHANGED FROM structure/

    1. encoder and pilot are placed in the "rover" namespace, at
       their USAGE SITES -- a namespace is deployment configuration,
       so the part defs stay deployment-neutral.  turtle is
       deliberately left UN-NAMESPACED, so it keeps the root-relative
       names a stock turtlesim actually uses.

    2. turtle is declared (see Turtlesim.sysml), so cVel and cPose
       are real connections.  Codegen emits no code for it, only
       deployment artifacts: a launch entry and a package dependency.

    3. Three ports carry explicit topic names, and they illustrate
       the three cases:

       - turtle.cmdVel and turtle.pose declare the stock node's own
         built-in relative names ("turtle1/cmd_vel", "turtle1/pose").
         These stay at the DEFINITION (Turtlesim.sysml) because they
         are facts about the node, not deployment configuration.

       - encoder.speed declares the relative "speed" at its USAGE
         SITE.  That is deployment configuration, hence the usage-site
         refinement (port :>> speed { ... }).

       - pilot declares NO topic names at all.  Topic names are
         resolved PER EDGE: an explicit name on either endpoint
         governs both ends, so pilot.speed follows encoder.speed and
         pilot.cmdVel/pilot.pose follow the turtle's names.

    4. overspeed, mode, calibrate and trim declare nothing anywhere,
       so they keep their path-derived defaults.  Naming is per-port,
       not all-or-nothing.

    RELATIVE VS. ABSOLUTE

    A relative name resolves against the DECLARING node's namespace,
    which is why the declaring end matters:

      encoder.speed  "speed"            + namespace rover -> /rover/speed
                                          pilot.speed is bound to the
                                          resolved /rover/speed, not to
                                          "speed" under its own namespace
                                          (which here would be the same
                                          topic, but need not be)

      turtle.cmdVel  "turtle1/cmd_vel"  + no namespace    -> /turtle1/cmd_vel
                                          pilot, though itself in /rover,
                                          publishes to /turtle1/cmd_vel --
                                          the namespace does not follow it

    NOTE: Ros_Topic_Name, Ros_Namespace and the provenance properties
    are HAMR extensions defined in the sysml-aadl-libraries; see
    doc/ros/PlatformProvidedTypes-design.md.  HAMR_AADL_Preview must be
    imported BEFORE HAMR -- it supplies the port defs that carry
    Ros_Topic_Name, and with the imports reversed the unqualified port
    names resolve to the plain AADL defs and the attribute is silently
    dropped.
  ============================================================*/

package TurtleControl_Naming {
    private import HAMR_AADL_Preview::*;
    private import HAMR::*;

    part def TurtleControlSystem :> System {
        part proc : TurtleControlProcess;
    }

    part def TurtleControlProcess :> Process {
        // subcomponents -- deployment configuration (node namespace, and any
        // topic name that is a deployment choice rather than a fact about the
        // node) is assigned here at the usage sites, keeping the part defs
        // deployment-neutral

        part encoder : Encoder {
            attribute :>> Ros_Namespace = "rover";

            port :>> speed {
                // relative; composes with this node's namespace -> /rover/speed.
                // pilot.speed declares nothing and is bound to the resolved
                // absolute form.
                attribute :>> Ros_Topic_Name = "speed";
            }

            // overspeed declares no name and keeps its path-derived default
        }

        part pilot : Pilot {
            attribute :>> Ros_Namespace = "rover";

            // no port refinements at all: every one of pilot's named topics is
            // determined by its peer (per-edge resolution), and the rest keep
            // their path-derived defaults
        }

        // platform-provided stock node (see Turtlesim.sysml): the usage name
        // 'turtle' becomes the launch-entry node name.  Deliberately NOT
        // namespaced -- a stock turtlesim launched bare uses root-relative
        // names, and leaving it there is what makes pilot's cmdVel/pose
        // topics escape the rover namespace.
        part turtle : turtlesim::turtlesim_node;

        // connections
        connection cSpeed     : PortConnection connect encoder.speed     to pilot.speed;
        connection cOverspeed : PortConnection connect encoder.overspeed to pilot.overspeed;
        connection cMode      : PortConnection connect pilot.mode        to encoder.mode;
        connection cCalibrate : PortConnection connect pilot.calibrate   to encoder.calibrate;
        connection cTrim      : PortConnection connect pilot.trim        to encoder.trim;

        // with turtle modeled, both turtlesim edges are explicit: datatype
        // agreement and the generation-time topic-name checks now apply where
        // the structure variant had only an unchecked deployment remap
        connection cVel  : PortConnection connect pilot.cmdVel to turtle.cmdVel;
        connection cPose : PortConnection connect turtle.pose  to pilot.pose;
    }

    // Unchanged from the structure variant apart from the naming assigned at
    // the usage sites above -- the definitions themselves stay
    // deployment-neutral.
    part def Encoder :> Thread {
        in  port mode      : DataPort      { in  :>> type : OperatingMode; }
        out port speed     : EventDataPort { out :>> type : WheelSpeed; }
        out port overspeed : EventPort;

        // Queued for this PERIODIC node -- arrivals cannot dispatch it, so each
        // waits in a Queue_Size-deep queue and is consumed one per period.
        in port calibrate : EventPort {
            attribute :>> Queue_Size = 2;
        }

        in port trim : EventDataPort {
            in :>> type : TrimCommand;

            attribute :>> Queue_Size = 4;
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

        // Queue_Size is a property of the receiving end, so nothing is declared here
        out port calibrate : EventPort;
        out port trim      : EventDataPort { out :>> type : TrimCommand; }

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
