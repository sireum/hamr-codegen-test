#include "building_control_cpp_pkg/base_headers/tcp_fan_base_src.hpp"

class tcp_fan : public tcp_fan_base
{
public:
    tcp_fan();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_fanCmd(const building_control_cpp_pkg_interfaces::msg::FanCmd::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
