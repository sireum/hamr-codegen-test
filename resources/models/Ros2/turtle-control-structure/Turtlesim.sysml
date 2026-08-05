/*============================================================
    The turtlesim ROS package -- message type only in this variant.

    Same structural convention as RosMessages.sysml (SysML package =
    ROS package, part def = message name), so turtlesim::Pose denotes
    turtlesim/msg/Pose.

    WHY THIS FILE EXISTS EVEN THOUGH TURTLESIM IS OFF-MODEL

    This variant leaves the turtlesim NODE unmodeled -- there is no
    component declaration and no connection for it (see the REMAPPING
    note in TurtleControl_Structure.sysml).  A message TYPE is a
    separate matter: pilot.pose is typed by turtlesim::Pose, and a
    type must be declared wherever it is used as a port type,
    regardless of whether the component on the other end of the topic
    is modeled.

    The naming/ variant adds turtlesim_node to this same file, since
    the ROS package turtlesim contains both the message and the
    executable.  Comparing the two copies of this file is therefore
    the whole of the platform-provided-COMPONENT delta between the
    variants.

    MIRROR FIELDS

    Unlike the opaque geometry_msgs::Twist in RosMessages.sysml, Pose
    carries mirror fields.  Mirror fields are specification-level
    projections of the native type, not layout claims: they exist so
    that the model can speak about the value.  Codegen still emits no
    .msg file -- the native ROS type flows through the topic either
    way -- so the difference between this type and Twist shows up in
    what the model can say, not in what is generated.

    Pose is mirrored completely here because its native definition is
    flat and small.  A mirror may also be partial: mirroring only the
    fields a model needs is the normal case for larger messages.
  ============================================================*/

package turtlesim {
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
}
