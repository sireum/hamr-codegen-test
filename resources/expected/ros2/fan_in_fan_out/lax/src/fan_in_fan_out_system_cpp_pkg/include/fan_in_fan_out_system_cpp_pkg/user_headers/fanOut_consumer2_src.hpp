#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanOut_consumer2_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class fanOut_consumer2 : public fanOut_consumer2_base
{
public:
    fanOut_consumer2();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_myInteger(const fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
