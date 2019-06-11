#include "formats/gaussian/gaussian_mp2_reader.h"

#include <boost/algorithm/string/replace.hpp>

#include "io/not_found_exception.h"
#include "io/regexes.h"
#include "io/wrong_format_exception.h"

ccio::gaussian_mp2_reader::gaussian_mp2_reader(
        kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& tree) :
        mp2_reader(stream, tree)
{
}

ccio::gaussian_mp2_reader::~gaussian_mp2_reader()
{
}

const std::string& ccio::gaussian_mp2_reader::start_string() const
{
    static const std::string s = "l906";
    return s;
}

const std::vector<std::string>& ccio::gaussian_mp2_reader::end_strings() const
{
    static const std::vector<std::string> v = { "Leave Link  906" };
    return v;
}

void ccio::gaussian_mp2_reader::read_mp2_energy(double& energy)
{
    //  E2 =    -0.1204058543D+00 EUMP2 =    -0.75706215831644D+02
    static const std::string s = "EUMP2";
    if (stream().found(s)) {
       static const std::regex regex(s + R"(\s+=\s+)" + kemiisto::io::re_real_g());
       std::smatch smatch;
       std::string line = stream().current_line();
       boost::replace_all(line, "D+", "E+");
       if (std::regex_search(line, smatch, regex)) {
           energy = std::stod(smatch[1]);
       } else {
           throw kemiisto::io::wrong_format_exception(s, stream().line_number());
       }
    } else {
       throw kemiisto::io::not_found_exception(s);
    }
}
