#include "turtle_control_structure_microros_pkg/base_headers/proc_encoder_base_src.h"

// Content between markers will be preserved if codegen is rerun

// Forward declaration of user compute entry point
void proc_encoder_timeTriggered(proc_encoder_base_t * self);

// Static instance pointer for timer and subscription callback context
// (heap-free, MCU-compatible)
static proc_encoder_base_t * g_self = NULL;

// Logger name used by the PRINT_* macros; updated to the node's actual logger
// name once the node has been initialized
const char * proc_encoder_logger_name = "proc_encoder";

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

static void proc_encoder_mode_subscription_callback(const void * msgin)
{
    const turtle_control_structure_cpp_pkg_interfaces__msg__OperatingMode * msg = (const turtle_control_structure_cpp_pkg_interfaces__msg__OperatingMode *) msgin;
    if (g_self != NULL) {
        g_self->proc_encoder_mode_msg = *msg;
    }
}

static void proc_encoder_calibrate_subscription_callback(const void * msgin)
{
    (void)msgin;
    if (g_self != NULL) {
        if (g_self->proc_encoder_calibrate_count < 2) {
            g_self->proc_encoder_calibrate_count++;
        } else {
            // Queue full.  Discarding the oldest event and recording this one leaves the
            // pending count unchanged, so there is nothing to do but report the loss.
            PRINT_WARN("calibrate queue full (Queue_Size 2); dropped an event");
        }
    }
}

static void proc_encoder_trim_subscription_callback(const void * msgin)
{
    const turtle_control_structure_cpp_pkg_interfaces__msg__TrimCommand * msg = (const turtle_control_structure_cpp_pkg_interfaces__msg__TrimCommand *) msgin;
    if (g_self != NULL) {
        if (g_self->proc_encoder_trim_count == 4) {
            // Queue full.  AADL's default Overflow_Handling_Protocol is DropOldest, so the
            // oldest entry is discarded to make room for this arrival.
            g_self->proc_encoder_trim_head = (g_self->proc_encoder_trim_head + 1) % 4;
            g_self->proc_encoder_trim_count--;
            PRINT_WARN("trim queue full (Queue_Size 4); dropped oldest message");
        }
        size_t proc_encoder_trim_tail = (g_self->proc_encoder_trim_head + g_self->proc_encoder_trim_count) % 4;
        g_self->proc_encoder_trim_queue[proc_encoder_trim_tail] = *msg;
        g_self->proc_encoder_trim_count++;
    }
}

//=================================================
//  C a l l b a c k   a n d   T i m e r
//=================================================

static void proc_encoder_receiveInputs(proc_encoder_base_t * self)
{
    if (self->proc_encoder_calibrate_count > 0) {
        self->proc_encoder_calibrate_count--;
        self->proc_encoder_calibrate_hasEvent = true;
    } else {
        self->proc_encoder_calibrate_hasEvent = false;
    }
    if (self->proc_encoder_trim_count > 0) {
        self->proc_encoder_trim_frozen = self->proc_encoder_trim_queue[self->proc_encoder_trim_head];
        self->proc_encoder_trim_head = (self->proc_encoder_trim_head + 1) % 4;
        self->proc_encoder_trim_count--;
        self->proc_encoder_trim_hasEvent = true;
    } else {
        self->proc_encoder_trim_hasEvent = false;
    }
}

static void period_timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
    (void)timer;
    (void)last_call_time;
    if (g_self != NULL) {
        proc_encoder_receiveInputs(g_self);
        proc_encoder_timeTriggered(g_self);
    }
}

//=================================================
//  I n i t i a l i z a t i o n
//=================================================

rcl_ret_t proc_encoder_base_init(proc_encoder_base_t * self)
{
    g_self = self;

    self->allocator = rcl_get_default_allocator();

    rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
    RCL_CHECK(rcl_init_options_init(&init_options, self->allocator));

    RCL_CHECK(rclc_support_init_with_options(
        &self->support,
        (int) (sizeof(node_options) / sizeof(node_options[0])), node_options,
        &init_options, &self->allocator));

    RCL_CHECK(rclc_node_init_default(&self->node, "proc_encoder", "", &self->support));

    // Retrieve the node's registered logger name for use by the PRINT_* macros
    const char * logger_name = rcl_node_get_logger_name(&self->node);
    if (logger_name != NULL) {
        proc_encoder_logger_name = logger_name;
    }

    // Setting up connections
    RCL_CHECK(rclc_publisher_init_default(
        &self->proc_encoder_speed_publisher,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(turtle_control_structure_cpp_pkg_interfaces, msg, WheelSpeed),
        "proc_pilot_speed"));

    RCL_CHECK(rclc_publisher_init_default(
        &self->proc_encoder_overspeed_publisher,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(turtle_control_structure_cpp_pkg_interfaces, msg, Empty),
        "proc_pilot_overspeed"));

    // Setting up subscriptions
    RCL_CHECK(rclc_subscription_init_default(
        &self->proc_encoder_mode_subscription,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(turtle_control_structure_cpp_pkg_interfaces, msg, OperatingMode),
        "proc_encoder_mode"));

    RCL_CHECK(rclc_subscription_init_default(
        &self->proc_encoder_calibrate_subscription,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(turtle_control_structure_cpp_pkg_interfaces, msg, Empty),
        "proc_encoder_calibrate"));

    RCL_CHECK(rclc_subscription_init_default(
        &self->proc_encoder_trim_subscription,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(turtle_control_structure_cpp_pkg_interfaces, msg, TrimCommand),
        "proc_encoder_trim"));


    // Queued ports start empty
    self->proc_encoder_calibrate_count = 0;
    self->proc_encoder_calibrate_hasEvent = false;
    self->proc_encoder_trim_head = 0;
    self->proc_encoder_trim_count = 0;
    self->proc_encoder_trim_hasEvent = false;

    // timeTriggered callback timer
    RCL_CHECK(rclc_timer_init_default(
        &self->period_timer,
        &self->support,
        RCL_MS_TO_NS(100),
        period_timer_callback));

    // USER INIT - additions within these tags will be preserved when re-running Codegen
    // Attach storage declared above to the corresponding message fields, e.g.:
    //     self->proc_ttj_joy_msg.axes.data = joy_axes_buf;
    //     self->proc_ttj_joy_msg.axes.capacity = 8;
    //     self->proc_ttj_joy_msg.axes.size = 0;
    // USER INIT - additions within these tags will be preserved when re-running Codegen

    RCL_CHECK(rclc_executor_init(&self->executor, &self->support.context, 4, &self->allocator));
    RCL_CHECK(rclc_executor_add_timer(&self->executor, &self->period_timer));
    RCL_CHECK(rclc_executor_add_subscription(&self->executor, &self->proc_encoder_mode_subscription, &self->proc_encoder_mode_msg, proc_encoder_mode_subscription_callback, ON_NEW_DATA));
    RCL_CHECK(rclc_executor_add_subscription(&self->executor, &self->proc_encoder_calibrate_subscription, &self->proc_encoder_calibrate_msg, proc_encoder_calibrate_subscription_callback, ON_NEW_DATA));
    RCL_CHECK(rclc_executor_add_subscription(&self->executor, &self->proc_encoder_trim_subscription, &self->proc_encoder_trim_msg, proc_encoder_trim_subscription_callback, ON_NEW_DATA));

    return RCL_RET_OK;
}

void proc_encoder_base_spin(proc_encoder_base_t * self)
{
    rclc_executor_spin(&self->executor);
}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void put_speed(proc_encoder_base_t * self, turtle_control_structure_cpp_pkg_interfaces__msg__WheelSpeed * msg)
{
    rcl_ret_t ret = rcl_publish(&self->proc_encoder_speed_publisher, msg, NULL);
    if (ret != RCL_RET_OK) {
        PRINT_ERROR("Failed to publish speed");
    }
}

void put_overspeed(proc_encoder_base_t * self)
{
    turtle_control_structure_cpp_pkg_interfaces__msg__Empty msg;
    turtle_control_structure_cpp_pkg_interfaces__msg__Empty__init(&msg);
    rcl_ret_t ret = rcl_publish(&self->proc_encoder_overspeed_publisher, &msg, NULL);
    if (ret != RCL_RET_OK) {
        PRINT_ERROR("Failed to publish overspeed");
    }
}

//=================================================
//  D a t a   P o r t   A c c e s s
//=================================================

turtle_control_structure_cpp_pkg_interfaces__msg__OperatingMode * get_mode(proc_encoder_base_t * self)
{
    return &self->proc_encoder_mode_msg;
}

//=================================================
//  Q u e u e d   P o r t   A c c e s s
//=================================================

bool has_calibrate(proc_encoder_base_t * self)
{
    return self->proc_encoder_calibrate_hasEvent;
}

turtle_control_structure_cpp_pkg_interfaces__msg__TrimCommand * get_trim(proc_encoder_base_t * self)
{
    return self->proc_encoder_trim_hasEvent ? &self->proc_encoder_trim_frozen : NULL;
}

