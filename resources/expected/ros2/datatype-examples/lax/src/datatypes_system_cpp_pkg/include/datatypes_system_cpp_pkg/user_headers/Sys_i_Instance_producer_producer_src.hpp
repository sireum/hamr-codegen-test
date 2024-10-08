#include "datatypes_system_cpp_pkg/base_headers/Sys_i_Instance_producer_producer_base_src.hpp"

class Sys_i_Instance_producer_producer : public Sys_i_Instance_producer_producer_base
{
public:
    Sys_i_Instance_producer_producer();

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

};
