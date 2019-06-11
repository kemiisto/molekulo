#include "formats/constants.h"

const char* const ccio::did_not_converge_message = "did not converge!";

const std::map<ccio::method_type, std::string> ccio::method_type_to_string()
{
    static const std::map<ccio::method_type, std::string> map = {
            {ccio::method_type::scf,    "SCF"},
            {ccio::method_type::mp2,    "MP2"},
            {ccio::method_type::ci,     "CI"},
            {ccio::method_type::gasci,  "GASCI"},
            {ccio::method_type::cc,     "CC"},
            {ccio::method_type::mcscf,  "MCSCF"},
            {ccio::method_type::nevpt2, "NEVPT2"}
    };
    return map;
}
