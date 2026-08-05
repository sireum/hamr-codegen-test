/*============================================================
    Platform-provided ROS 2 message types

    Mirrors of preexisting ROS 2 message types used by the Turtle
    Control system.  Structural convention (see doc/ros/PlatformProvidedTypes-design.md):
    SysML package name = ROS package name, part def name = message
    name, so geometry_msgs::Twist denotes geometry_msgs/msg/Twist.

    Twist is declared OPAQUE -- the minimum declaration, no fields.
    That is enough for codegen: it emits no .msg file for the type,
    uses the native ROS type as the payload of every port and topic
    carrying it, and adds geometry_msgs to the generated package
    dependencies.  What an opaque declaration does NOT give you is a
    vocabulary: nothing in the model can speak about the value's
    fields, and codegen generates no example builder for it, so
    application code constructs a Twist with native rclcpp calls.

    turtlesim::Pose, in Turtlesim.sysml, is the contrasting case: the
    same provenance, but with mirror fields.

    NOTE: Type_Provenance is a HAMR extension defined in the
    sysml-aadl-libraries.
  ============================================================*/

package geometry_msgs {
    private import HAMR::*;

    // geometry_msgs/msg/Twist
    //   native: Vector3 linear ; Vector3 angular
    part def Twist :> Data {
        attribute :>> Type_Provenance = Provenances::Platform_Provided;
    }
}
