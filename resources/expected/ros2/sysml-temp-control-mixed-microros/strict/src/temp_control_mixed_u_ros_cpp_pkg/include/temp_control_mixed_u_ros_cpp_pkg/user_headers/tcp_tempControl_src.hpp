#include "temp_control_mixed_u_ros_cpp_pkg/base_headers/tcp_tempControl_base_src.hpp"

// Content between markers will be preserved if codegen is rerun

class tcp_tempControl : public tcp_tempControl_base
{
public:
    tcp_tempControl();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_tempChanged();
    void handle_fanAck(const temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::FanAck msg);
    void handle_setPoint(const temp_control_mixed_u_ros_cpp_pkg_interfaces::msg::SetPoint msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
