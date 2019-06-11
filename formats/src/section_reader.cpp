#include "formats/section_reader.h"

#include "io/logger.h"
#include "io/not_found_exception.h"

struct ccio::section_reader::section_reader_private
{
    boost::property_tree::ptree& tree;
    std::string name;

    section_reader_private(boost::property_tree::ptree& tree, const std::string& name) :
        tree(tree), name(name) {}
};

ccio::section_reader::section_reader(kemiisto::io::input_stream& stream,
        boost::property_tree::ptree& tree, const std::string& name) :
    reader(stream),
    p(new section_reader_private(tree, name))
{
}

ccio::section_reader::~section_reader()
{
}

boost::property_tree::ptree& ccio::section_reader::tree()
{
    return p->tree;
}

const boost::property_tree::ptree& ccio::section_reader::tree() const
{
    return p->tree;
}

bool ccio::section_reader::start_found()
{
    return stream().found(start_string());
}

bool ccio::section_reader::end_found()
{
    return stream().found_any_of(end_strings());
}

void ccio::section_reader::do_read()
{
    if (start_found()) {
        LOG(debug) << "Reading " << p->name << "...";
        do_read_section();
        if (end_found()) {
            LOG(debug) << "Done reading " << p->name << "...";
        } else {
            throw kemiisto::io::not_found_exception("end of " + p->name);
        }
    } else {
        throw kemiisto::io::not_found_exception("start of " + p->name);
    }
}
