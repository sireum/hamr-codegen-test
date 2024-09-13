#include "isolette_cpp_pkg/base_headers/isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base_src.hpp"

class isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat : public isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat_base
{
public:
    isolette_single_sensor_Instance_thermostat_monitor_temperature_manage_alarm_mat();

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
