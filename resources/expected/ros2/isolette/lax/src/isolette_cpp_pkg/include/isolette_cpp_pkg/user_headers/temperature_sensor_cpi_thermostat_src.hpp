#include "isolette_cpp_pkg/base_headers/temperature_sensor_cpi_thermostat_base_src.hpp"

class temperature_sensor_cpi_thermostat : public temperature_sensor_cpi_thermostat_base
{
public:
    temperature_sensor_cpi_thermostat();

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
