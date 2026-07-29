#include "uros_demo_naming_microros_pkg/base_headers/proc_ttj_base_src.h"
#include "rcl/logging.h"

// Content between markers will be preserved if codegen is rerun

// Forward declarations of user compute entry points
void proc_ttj_handle_joy(proc_ttj_base_t * self, const sensor_msgs__msg__Joy * msg);

// Static instance pointer for subscription callback context (heap-free, MCU-compatible)
static proc_ttj_base_t * g_self = NULL;

// Logger name used by the PRINT_* macros; updated to the node's actual logger
// name once the node has been initialized
const char * proc_ttj_logger_name = "proc_ttj";

// NODE OPTIONS - additions within these tags will be preserved when re-running Codegen
// Add rcl arguments after "--ros-args", e.g. a remap rule binding one of this
// node's topics to a preexisting node's topic:
//     "-r", "some_port:=/some/other/topic"
// Write the match side of a remap rule relative (no leading '/') so that it keeps
// matching if the node is later placed in a namespace.
static const char * const node_options[] = {
    "--ros-args"
};
// NODE OPTIONS - additions within these tags will be preserved when re-running Codegen

// USER DECLARATIONS - additions within these tags will be preserved when re-running Codegen
// Storage for message fields codegen could not size from the model, e.g. a sequence
// or string field of a platform-provided type whose mirror declares no dimensions:
//     static float joy_axes_buf[8];
// USER DECLARATIONS - additions within these tags will be preserved when re-running Codegen

//=================================================
//  S u b s c r i p t i o n   C a l l b a c k s
//=================================================

static void proc_ttj_joy_subscription_callback(const void * msgin)
{
    const sensor_msgs__msg__Joy * msg = (const sensor_msgs__msg__Joy *) msgin;
    if (g_self != NULL) {
        proc_ttj_handle_joy(g_self, msg);
    }
}

//=================================================
//  I n i t i a l i z a t i o n
//=================================================

rcl_ret_t proc_ttj_base_init(proc_ttj_base_t * self)
{
    g_self = self;

    self->allocator = rcl_get_default_allocator();

    rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
    RCL_CHECK(rcl_init_options_init(&init_options, self->allocator));

    RCL_CHECK(rclc_support_init_with_options(
        &self->support,
        (int) (sizeof(node_options) / sizeof(node_options[0])), node_options,
        &init_options, &self->allocator));

    // Route this node's own log records to /rosout.  Requires the firmware to be built
    // with RCL_LOGGING_ENABLED=ON plus a backend; see microros_apps/colcon.meta.
    // Checked because the failure mode is invisible otherwise: the node runs, but its
    // log records never reach /rosout and any node subscribed to them just sees silence.
    RCL_CHECK(rcl_logging_configure(&self->support.context.global_arguments, &self->allocator));

    RCL_CHECK(rclc_node_init_default(&self->node, "proc_ttj", "uros_demo", &self->support));

    // Retrieve the node's registered logger name for use by the PRINT_* macros
    const char * logger_name = rcl_node_get_logger_name(&self->node);
    if (logger_name != NULL) {
        proc_ttj_logger_name = logger_name;
    }

    // Setting up connections
    RCL_CHECK(rclc_publisher_init_default(
        &self->proc_ttj_cmdVel_publisher,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
        "turtle1/cmd_vel"));

    // Setting up subscriptions
    RCL_CHECK(rclc_subscription_init_default(
        &self->proc_ttj_joy_subscription,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Joy),
        "/uros_demo/joy"));


    // USER INIT - additions within these tags will be preserved when re-running Codegen
    // Attach storage declared above to the corresponding message fields, e.g.:
    //     self->proc_ttj_joy_msg.axes.data = joy_axes_buf;
    //     self->proc_ttj_joy_msg.axes.capacity = 8;
    //     self->proc_ttj_joy_msg.axes.size = 0;
    // USER INIT - additions within these tags will be preserved when re-running Codegen

    RCL_CHECK(rclc_executor_init(&self->executor, &self->support.context, 1, &self->allocator));
    RCL_CHECK(rclc_executor_add_subscription(&self->executor, &self->proc_ttj_joy_subscription, &self->proc_ttj_joy_msg, proc_ttj_joy_subscription_callback, ON_NEW_DATA));

    return RCL_RET_OK;
}

void proc_ttj_base_spin(proc_ttj_base_t * self)
{
    rclc_executor_spin(&self->executor);
}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void put_cmdVel(proc_ttj_base_t * self, geometry_msgs__msg__Twist * msg)
{
    rcl_ret_t ret = rcl_publish(&self->proc_ttj_cmdVel_publisher, msg, NULL);
    if (ret != RCL_RET_OK) {
        PRINT_ERROR("Failed to publish cmdVel");
    }
}

