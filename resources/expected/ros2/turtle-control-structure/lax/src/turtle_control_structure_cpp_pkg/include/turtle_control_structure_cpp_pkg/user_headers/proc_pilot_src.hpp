#include "turtle_control_structure_cpp_pkg/base_headers/proc_pilot_base_src.hpp"

// Content between markers will be preserved if codegen is rerun

class proc_pilot : public proc_pilot_base
{
public:
    proc_pilot();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_speed(const turtle_control_structure_cpp_pkg_interfaces::msg::WheelSpeed::SharedPtr msg);
    void handle_overspeed();

    //=================================================
    //  Include any additional declarations here
    //=================================================
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
