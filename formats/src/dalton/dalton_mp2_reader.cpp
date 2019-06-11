#include "formats/dalton/dalton_mp2_reader.h"

#include "io/not_found_exception.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

ccio::dalton_mp2_reader::dalton_mp2_reader(kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& tree) :
    mp2_reader(stream, tree)
{
}

ccio::dalton_mp2_reader::~dalton_mp2_reader()
{
}

//  >>>>> Output from SIRIUS MP2 module <<<<<
const std::string& ccio::dalton_mp2_reader::start_string() const
{
    static const std::string s = "SIRIUS MP2";
    return s;
}

const std::vector<std::string>& ccio::dalton_mp2_reader::end_strings() const
{
    static const std::vector<std::string> v = { "CPU and wall time for MP2" };
    return v;
}

void ccio::dalton_mp2_reader::read_mp2_energy(double& energy)
{
    // @   = MP2 second order energy   :           -75.7080410468
    static const std::string s = "MP2 second order energy";
    if (stream().found(s)) {
        static const std::regex regex(s + R"(\s+:\s+)" + kemiisto::io::re_real_g());
        std::smatch smatch;
        if (std::regex_search(stream().current_line(), smatch, regex)) {
            energy = std::stod(smatch[1]);
        } else {
            throw kemiisto::io::wrong_format_exception(s, stream().line_number());
        }
    } else {
        throw kemiisto::io::not_found_exception(s);
    }
}
