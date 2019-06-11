#include "io/regexes.h"

const std::string& kemiisto::io::re_int()
{
    static const std::string s = R"((?:[-+]?\d+))";
    return s;
}

const std::string& kemiisto::io::re_real()
{
    static const std::string s = R"((?:[-+]?\d*\.\d+|[-+]?\d+\.\d*))";
    return s;
}

const std::string& kemiisto::io::re_real_int()
{
    static const std::string s = R"((?:[-+]?\d*\.\d+|[-+]?\d+\.\d*|[-+]?\d+))";
    return s;
}

const std::string& kemiisto::io::re_alpha()
{
    static const std::string s = R"((?:[A-Za-z]+))";
    return s;
}

const std::string& kemiisto::io::re_spaces()
{
    static const std::string s = R"((?:\s+))";
    return s;
}

const std::string& kemiisto::io::re_int_g()
{
    static const std::string s = 
        kemiisto::io::re_int().substr(0, 1) + kemiisto::io::re_int().substr(3);
    return s;
}

const std::string& kemiisto::io::re_real_g()
{
    static const std::string s = 
        kemiisto::io::re_real().substr(0, 1) + kemiisto::io::re_real().substr(3);
    return s;
}

const std::string& kemiisto::io::re_real_int_g()
{
    static const std::string s = 
        kemiisto::io::re_real_int().substr(0, 1) + kemiisto::io::re_real_int().substr(3);
    return s;
}

const std::string& kemiisto::io::re_alpha_g()
{
    static const std::string s = 
        kemiisto::io::re_alpha().substr(0, 1) + kemiisto::io::re_alpha().substr(3);
    return s;
}
