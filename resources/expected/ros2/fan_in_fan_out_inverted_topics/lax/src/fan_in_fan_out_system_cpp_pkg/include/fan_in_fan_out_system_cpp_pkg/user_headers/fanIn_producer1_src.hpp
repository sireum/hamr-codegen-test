#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanIn_producer1_base_src.hpp"

class fanIn_producer1 : public fanIn_producer1_base
{
public:
    fanIn_producer1();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void timeTriggered();

    //=================================================
    //  Include any additional declarations here
    //=================================================
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
