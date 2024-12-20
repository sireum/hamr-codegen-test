#include "isolette_cpp_pkg/base_headers/thermostat_regulate_temperature_manage_regulator_interface_mrit_base_src.hpp"

class thermostat_regulate_temperature_manage_regulator_interface_mrit : public thermostat_regulate_temperature_manage_regulator_interface_mrit_base
{
public:
    thermostat_regulate_temperature_manage_regulator_interface_mrit();

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
