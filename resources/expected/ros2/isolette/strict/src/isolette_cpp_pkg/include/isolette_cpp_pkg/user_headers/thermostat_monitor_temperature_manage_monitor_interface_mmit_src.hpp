#include "isolette_cpp_pkg/base_headers/thermostat_monitor_temperature_manage_monitor_interface_mmit_base_src.hpp"

class thermostat_monitor_temperature_manage_monitor_interface_mmit : public thermostat_monitor_temperature_manage_monitor_interface_mmit_base
{
public:
    thermostat_monitor_temperature_manage_monitor_interface_mmit();

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