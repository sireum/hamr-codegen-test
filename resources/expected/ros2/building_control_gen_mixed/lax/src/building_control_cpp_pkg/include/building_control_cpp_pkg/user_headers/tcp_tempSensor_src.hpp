#include "building_control_cpp_pkg/base_headers/tcp_tempSensor_base_src.hpp"

class tcp_tempSensor : public tcp_tempSensor_base
{
public:
    tcp_tempSensor();

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
