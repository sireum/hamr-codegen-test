#include "building_control_cpp_pkg/base_headers/BuildingControlDemo_i_Instance_tcp_tempSensor_base_src.hpp"

class BuildingControlDemo_i_Instance_tcp_tempSensor : public BuildingControlDemo_i_Instance_tcp_tempSensor_base
{
public:
    BuildingControlDemo_i_Instance_tcp_tempSensor();

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
