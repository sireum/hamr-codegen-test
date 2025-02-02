#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_fan_base_src.hpp"

class BuildingControlDemo_i_Instance_tcp_fan : public BuildingControlDemo_i_Instance_tcp_fan_base
{
public:
    BuildingControlDemo_i_Instance_tcp_fan();

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

};
