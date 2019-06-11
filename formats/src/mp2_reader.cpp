#include "formats/mp2_reader.h"

#include <boost/property_tree/ptree.hpp>

ccio::mp2_reader::mp2_reader(kemiisto::io::input_stream& stream, boost::property_tree::ptree& tree) :
    section_reader(stream, tree, "MP2 results")
{
}

ccio::mp2_reader::~mp2_reader()
{
}

void ccio::mp2_reader::do_read_section()
{
    double energy;
    read_mp2_energy(energy);
    boost::property_tree::ptree mp2_tree;
    mp2_tree.put("<xmlattr>.name", "MP2");
    mp2_tree.put("<xmlattr>.value", energy);
    mp2_tree.put("<xmlattr>.done", "true");
    tree().add_child("Item", mp2_tree);
}
