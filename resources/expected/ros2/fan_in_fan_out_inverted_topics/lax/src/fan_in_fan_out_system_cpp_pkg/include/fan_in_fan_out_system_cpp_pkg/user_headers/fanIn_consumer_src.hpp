#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanIn_consumer_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class fanIn_consumer : public fanIn_consumer_base
{
public:
    fanIn_consumer();

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
