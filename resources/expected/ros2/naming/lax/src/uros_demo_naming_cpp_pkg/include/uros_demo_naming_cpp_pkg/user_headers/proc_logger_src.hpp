#include "uros_demo_naming_cpp_pkg/base_headers/proc_logger_base_src.hpp"

// Content between markers will be preserved if codegen is rerun

class proc_logger : public proc_logger_base
{
public:
    proc_logger();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_rosout(const rcl_interfaces::msg::Log::SharedPtr msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================
    // Additions within these tags will be preserved when re-running Codegen

    // Additions within these tags will be preserved when re-running Codegen
};
