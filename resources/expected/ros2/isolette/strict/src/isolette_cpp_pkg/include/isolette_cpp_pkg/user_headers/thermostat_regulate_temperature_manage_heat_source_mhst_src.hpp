#include "isolette_cpp_pkg/base_headers/thermostat_regulate_temperature_manage_heat_source_mhst_base_src.hpp"

class thermostat_regulate_temperature_manage_heat_source_mhst : public thermostat_regulate_temperature_manage_heat_source_mhst_base
{
public:
    thermostat_regulate_temperature_manage_heat_source_mhst();

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