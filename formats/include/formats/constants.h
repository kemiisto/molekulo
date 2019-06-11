#ifndef FORMATS_CONSTANTS_H
#define FORMATS_CONSTANTS_H

#include <map>
#include <string>

namespace ccio
{
    extern const char* const did_not_converge_message;

    enum class method_type
    {
        scf,
        mp2,
        ci,
        gasci,
        cc,
        mcscf,
        nevpt2,
    };

    enum class scf_type
    {
        diis,
        qc,
        dm
    };

    const std::map<ccio::method_type, std::string> method_type_to_string();
}

#endif /* FORMATS_CONSTANTS_H */
