#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_tempControl_base_src.hpp"

class BuildingControlDemo_i_Instance_tcp_tempControl : public BuildingControlDemo_i_Instance_tcp_tempControl_base
{
public:
    BuildingControlDemo_i_Instance_tcp_tempControl();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_fanAck(const building_control_cpp_pkg_interfaces::msg::FanAck::SharedPtr msg);
    void handle_setPoint(const building_control_cpp_pkg_interfaces::msg::SetPointimpl::SharedPtr msg);
    void handle_tempChanged(const building_control_cpp_pkg_interfaces::msg::Empty::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
