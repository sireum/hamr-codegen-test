#include "isolette_cpp_pkg/base_headers/operator_interface_oip_oit_base_src.hpp"

class operator_interface_oip_oit : public operator_interface_oip_oit_base
{
public:
    operator_interface_oip_oit();

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