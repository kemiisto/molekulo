#ifndef DALTON_MP2_READER_H
#define DALTON_MP2_READER_H

#include "formats/mp2_reader.h"

namespace ccio
{
    class dalton_mp2_reader final : public ccio::mp2_reader
    {
    public:
        dalton_mp2_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree);
        ~dalton_mp2_reader();

        void read_mp2_energy(double& energy) override;

    private:
        const std::string& start_string() const override;
        const std::vector<std::string>& end_strings() const override;
    };
}

#endif // DALTON_MP2_READER_H
