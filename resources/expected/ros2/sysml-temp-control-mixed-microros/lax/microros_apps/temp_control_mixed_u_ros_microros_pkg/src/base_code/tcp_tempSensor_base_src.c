#include "temp_control_mixed_u_ros_microros_pkg/base_headers/tcp_tempSensor_base_src.h"

// Content between markers will be preserved if codegen is rerun

// Forward declaration of user compute entry point
void tcp_tempSensor_timeTriggered(tcp_tempSensor_base_t * self);

// Static instance pointer for timer callback context (heap-free, MCU-compatible)
static tcp_tempSensor_base_t * g_self = NULL;

// Logger name used by the PRINT_* macros; updated to the node's actual logger
// name once the node has been initialized
const char * tcp_tempSensor_logger_name = "tcp_tempSensor";

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
//  C a l l b a c k   a n d   T i m e r
//=================================================

static void period_timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
    (void)timer;
    (void)last_call_time;
    if (g_self != NULL) {
        tcp_tempSensor_timeTriggered(g_self);
    }
}

//=================================================
//  I n i t i a l i z a t i o n
//=================================================

rcl_ret_t tcp_tempSensor_base_init(tcp_tempSensor_base_t * self)
{
    g_self = self;

    self->allocator = rcl_get_default_allocator();

    rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
    RCL_CHECK(rcl_init_options_init(&init_options, self->allocator));

    RCL_CHECK(rclc_support_init_with_options(
        &self->support,
        (int) (sizeof(node_options) / sizeof(node_options[0])), node_options,
        &init_options, &self->allocator));

    RCL_CHECK(rclc_node_init_default(&self->node, "tcp_tempSensor", "", &self->support));

    // Retrieve the node's registered logger name for use by the PRINT_* macros
    const char * logger_name = rcl_node_get_logger_name(&self->node);
    if (logger_name != NULL) {
        tcp_tempSensor_logger_name = logger_name;
    }

    // Setting up connections
    RCL_CHECK(rclc_publisher_init_default(
        &self->tcp_tempSensor_currentTemp_publisher_1,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(temp_control_mixed_u_ros_cpp_pkg_interfaces, msg, Temperature),
        "tcp_tempControl_currentTemp"));

    RCL_CHECK(rclc_publisher_init_default(
        &self->tcp_tempSensor_currentTemp_publisher_2,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(temp_control_mixed_u_ros_cpp_pkg_interfaces, msg, Temperature),
        "tcp_opInterface_currentTemp"));

    RCL_CHECK(rclc_publisher_init_default(
        &self->tcp_tempSensor_tempChanged_publisher,
        &self->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(temp_control_mixed_u_ros_cpp_pkg_interfaces, msg, Empty),
        "tcp_tempControl_tempChanged"));

    // timeTriggered callback timer
    RCL_CHECK(rclc_timer_init_default(
        &self->period_timer,
        &self->support,
        RCL_MS_TO_NS(1000),
        period_timer_callback));

    // USER INIT - additions within these tags will be preserved when re-running Codegen
    // Attach storage declared above to the corresponding message fields, e.g.:
    //     self->proc_ttj_joy_msg.axes.data = joy_axes_buf;
    //     self->proc_ttj_joy_msg.axes.capacity = 8;
    //     self->proc_ttj_joy_msg.axes.size = 0;
    // USER INIT - additions within these tags will be preserved when re-running Codegen

    RCL_CHECK(rclc_executor_init(&self->executor, &self->support.context, 1, &self->allocator));
    RCL_CHECK(rclc_executor_add_timer(&self->executor, &self->period_timer));

    return RCL_RET_OK;
}

void tcp_tempSensor_base_spin(tcp_tempSensor_base_t * self)
{
    rclc_executor_spin(&self->executor);
}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void put_currentTemp(tcp_tempSensor_base_t * self, temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__Temperature * msg)
{
    rcl_ret_t ret1 = rcl_publish(&self->tcp_tempSensor_currentTemp_publisher_1, msg, NULL);
    if (ret1 != RCL_RET_OK) {
        PRINT_ERROR("Failed to publish currentTemp (1)");
    }
    rcl_ret_t ret2 = rcl_publish(&self->tcp_tempSensor_currentTemp_publisher_2, msg, NULL);
    if (ret2 != RCL_RET_OK) {
        PRINT_ERROR("Failed to publish currentTemp (2)");
    }
}

void put_tempChanged(tcp_tempSensor_base_t * self)
{
    temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__Empty msg;
    temp_control_mixed_u_ros_cpp_pkg_interfaces__msg__Empty__init(&msg);
    rcl_ret_t ret = rcl_publish(&self->tcp_tempSensor_tempChanged_publisher, &msg, NULL);
    if (ret != RCL_RET_OK) {
        PRINT_ERROR("Failed to publish tempChanged");
    }
}

