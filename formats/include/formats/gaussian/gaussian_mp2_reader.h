#ifndef GAUSSIAN_MP2_READER_H
#define GAUSSIAN_MP2_READER_H

#include "formats/mp2_reader.h"

namespace ccio
{
    class gaussian_mp2_reader final : public ccio::mp2_reader
    {
    public:
        gaussian_mp2_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree);
        ~gaussian_mp2_reader();

        const std::string& start_string() const override;
        const std::vector<std::string>& end_strings() const override;

        void read_mp2_energy(double& energy) override;
    };
}

#endif // GAUSSIAN_MP2_READER_H
