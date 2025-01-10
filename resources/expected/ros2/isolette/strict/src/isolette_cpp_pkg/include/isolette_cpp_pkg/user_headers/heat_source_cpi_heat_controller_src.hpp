#include "isolette_cpp_pkg/base_headers/heat_source_cpi_heat_controller_base_src.hpp"

class heat_source_cpi_heat_controller : public heat_source_cpi_heat_controller_base
{
public:
    heat_source_cpi_heat_controller();

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
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
