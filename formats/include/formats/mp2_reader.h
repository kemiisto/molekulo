#ifndef MP2_READER_H
#define MP2_READER_H

#include <boost/property_tree/ptree_fwd.hpp>
#include <memory>

#include "formats/section_reader.h"

namespace ccio
{
    class mp2_reader : public ccio::section_reader
    {
    public:
        mp2_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree);
        virtual ~mp2_reader();

    private:
        void do_read_section() override final;
        virtual void read_mp2_energy(double& energy) = 0;
    };
}

#endif // MP2_READER_H
