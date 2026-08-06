/*============================================================
    The turtlesim ROS package: its message type, and the stock node
    itself declared as a PLATFORM-PROVIDED COMPONENT.

    Structural convention (see doc/ros/PlatformProvidedTypes-design.md):
    SysML package name = ROS package name; for a message, part def
    name = message name (turtlesim::Pose -> turtlesim/msg/Pose); for a
    component, part def name = executable name
    (turtlesim::turtlesim_node -> `ros2 run turtlesim turtlesim_node`).
    Both live in this one package because the ROS package turtlesim
    contains both.

    The structure/ variant's copy of this file declares only Pose and
    leaves the node off-model.  Declaring the node -- the sole
    difference between the two copies -- is what brings the cVel and
    cPose connections back, and with them datatype checking and the
    generation-time topic-name checks.

    Codegen emits NO code for a platform-provided component -- only
    deployment artifacts: a launch entry (the subcomponent usage name
    becomes the node name) and an exec_depend on the turtlesim package
    so `rosdep install` pulls the stock node.
  ============================================================*/

package turtlesim {
    private import HAMR_AADL_Preview::*;
    private import HAMR::*;

    // turtlesim/msg/Pose
    //   native: float32 x, y, theta, linear_velocity, angular_velocity
    part def Pose :> Data {
        attribute :>> Type_Provenance = Provenances::Platform_Provided;

        part x                : Base_Types::Float_32;
        part y                : Base_Types::Float_32;
        part theta            : Base_Types::Float_32;
        part linear_velocity  : Base_Types::Float_32;
        part angular_velocity : Base_Types::Float_32;
    }

    part def turtlesim_node :> Thread {
        attribute :>> Component_Provenance = Provenances::Platform_Provided;

        // Optional: the structural convention above already yields
        // turtlesim/turtlesim_node.  Native_Name is the escape hatch for a node
        // whose package/executable names do not match the model's.
        // attribute :>> Native_Name = "turtlesim/turtlesim_node";

        // Periodic with data ports, and the two go together -- both follow from
        // how turtlesim actually runs: a ~16 ms frame update that consumes the
        // LATEST stored Twist, zeroing it after a 1 s command timeout, while the
        // subscription callback only stores.  That is last-value-wins sampling,
        // not queued event dispatch, so there is no arrival to dispatch on and
        // no queue to model.
        //
        // None of this reaches the ROS 2 backend -- no code is generated for a
        // platform-provided component -- so these attributes are for scheduling
        // analysis and for the reader.
        attribute :>> Dispatch_Protocol = Periodic;
        attribute :>> Period = 16 [ms];

        // The node's built-in topics, declared with their own RELATIVE names.
        // These stay here at the definition rather than at the usage site: they
        // are facts about the stock node, not deployment configuration.  With
        // this component left un-namespaced at its usage site, they resolve to
        // /turtle1/cmd_vel and /turtle1/pose.
        in port cmdVel : DataPort {
            in :>> type : geometry_msgs::Twist;

            attribute :>> Ros_Topic_Name = "turtle1/cmd_vel";
        }

        out port pose : DataPort {
            out :>> type : Pose;

            attribute :>> Ros_Topic_Name = "turtle1/pose";
        }
    }
}
