#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_operator_interface_oip_oit_base_src.hpp"

class isolette_single_sensor_Instance_operator_interface_oip_oit : public isolette_single_sensor_Instance_operator_interface_oip_oit_base
{
public:
    isolette_single_sensor_Instance_operator_interface_oip_oit();

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
