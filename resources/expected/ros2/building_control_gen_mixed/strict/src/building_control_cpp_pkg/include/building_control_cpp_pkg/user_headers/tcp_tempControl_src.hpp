#include "building_control_cpp_pkg/base_headers/tcp_tempControl_base_src.hpp"

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
    void handle_fanAck(const building_control_cpp_pkg_interfaces::msg::FanAck msg);
    void handle_setPoint(const building_control_cpp_pkg_interfaces::msg::SetPointimpl msg);
    void handle_tempChanged();

    //=================================================
    //  Include any additional declarations here
    //=================================================
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
