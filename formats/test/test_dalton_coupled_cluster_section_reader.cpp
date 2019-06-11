/**********************************************************************

  Copyright (C) 2008-2015 Anton Simakov

  This file is part of Molekulo.
  For more information, see <http://code.google.com/p/molekulo/>

  Molekulo is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Molekulo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Molekulo. If not, see <http://www.gnu.org/licenses/>.

 **********************************************************************/

#include <array>

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <boost/property_tree/xml_parser.hpp>

#include "tolerance.h"
#include "test_util.h"

#include "formats/constants.h"
#include "formats/dalton/dalton_coupled_cluster_section_reader.h"
#include "io/input_string_stream.h"

#include "data/dalton_coupled_cluster_section_water_cc_2.h"
#include "data/dalton_coupled_cluster_section_water_cc_3.h"
#include "data/dalton_coupled_cluster_section_water_cc_t.h"
#include "data/dalton_coupled_cluster_section_water_cc2.h"
#include "data/dalton_coupled_cluster_section_water_cc3.h"
#include "data/dalton_coupled_cluster_section_water_ccd.h"

/*
 * Testing CC section reader:
 *   1) different CC types 
 *     CC(2), CC(3), CC(T), CC2, CC3, CCD
 *     more to test 
 *     CIS, CHO(T), CCR(3), CCS, CCSD, MP2
 *     for CIS & CCS: NO WAVEFUNCTION OPTIMIZATION, but properties!
 */

BOOST_AUTO_TEST_SUITE(test_dalton_coupled_cluster_section_reader)

// CC3, CC(T), CCSD
const int number_of_ccsd_cycles = 9;
const std::array<double, number_of_ccsd_cycles> ccsd_cycles = {{
    -75.7114047772544438,
    -75.7150068138121242,
    -75.7152816480859343,
    -75.7153071378344436,
    -75.7152981874026949,
    -75.7152973446152373,
    -75.7152973796429478,
    -75.7152972480084969,
    -75.7152972493591392
}};

BOOST_AUTO_TEST_CASE(test_dalton_coupled_cluster_section_reader_cc_2)
{
    kemiisto::io::input_string_stream stream(dalton_coupled_cluster_section_water_cc_2);
    stream.read_line();

    boost::property_tree::ptree tree;
    ccio::dalton_coupled_cluster_section_reader reader(stream, tree);
    reader.read();

    const double mp2_energy = -75.7080410460;

    // <Item name="MP2" value="-75.7080410459820428" done="true"/>

    // First we check that there is only one child.
    BOOST_CHECK_EQUAL(tree.size(), 1);
    // Then we get the child and check its attributes.
    const boost::property_tree::ptree& mp2_tree = tree.get_child("Item");
    BOOST_CHECK_EQUAL(mp2_tree.get<std::string>("<xmlattr>.name"), "MP2");
    BOOST_CHECK_CLOSE(mp2_tree.get<double>("<xmlattr>.value"), mp2_energy, tolerance);
    BOOST_CHECK_EQUAL(mp2_tree.get<bool>("<xmlattr>.done"), true);    
}

BOOST_AUTO_TEST_CASE(test_dalton_coupled_cluster_section_reader_cc_3)
{
    kemiisto::io::input_string_stream stream(dalton_coupled_cluster_section_water_cc_3);
    stream.read_line();

    boost::property_tree::ptree tree;
    ccio::dalton_coupled_cluster_section_reader reader(stream, tree);
    reader.read();

    const double mp2_energy  = -75.7080410460;
    const double ccsd_energy = -75.7152972494;
    const double cc_3_energy = -75.7166221342;

    // <Item name="MP2" value="-75.7080410459820428" done="true"/>
    // <Item name="CCSD" value="-75.7152972493591392" done="true">
    //     <Item name="1" value="-75.7114047772544438"/>
    //     <Item name="2" value="-75.7150068138121242"/>
    //     <Item name="3" value="-75.7152816480859343"/>
    //     <Item name="4" value="-75.7153071378344436"/>
    //     <Item name="5" value="-75.7152981874026949"/>
    //     <Item name="6" value="-75.7152973446152373"/>
    //     <Item name="7" value="-75.7152973796429478"/>
    //     <Item name="8" value="-75.7152972480084969"/>
    //     <Item name="9" value="-75.7152972493591392"/>
    // </Item>
    // <Item name="CC(3)" value="-75.7166221342" done="true"/>

    BOOST_CHECK_EQUAL(tree.size(), 3);
    for (const auto& item : tree) {
        if (item.second.get<std::string>("<xmlattr>.name") == "MP2") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), mp2_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
        } else if (item.second.get<std::string>("<xmlattr>.name") == "CCSD") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), ccsd_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
            // + 1 due to the <xmlattr> child
            BOOST_CHECK_EQUAL(item.second.size(), number_of_ccsd_cycles + 1);
            for (const auto& subitem : item.second) { 
                if (subitem.first == "Item") {
                    int name = subitem.second.get<int>("<xmlattr>.name");
                    double value = subitem.second.get<double>("<xmlattr>.value");
                    BOOST_CHECK_CLOSE(value, ccsd_cycles.at(name - 1), tolerance);
                }
            }
        } else if (item.second.get<std::string>("<xmlattr>.name") == "CC(3)") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), cc_3_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
        } else {
            BOOST_ERROR("unexpected item in tree");
        }
    }
}

BOOST_AUTO_TEST_CASE(test_dalton_coupled_cluster_section_reader_cc_t)
{
    kemiisto::io::input_string_stream stream(dalton_coupled_cluster_section_water_cc_t);
    stream.read_line();

    boost::property_tree::ptree tree;
    ccio::dalton_coupled_cluster_section_reader reader(stream, tree);
    reader.read();

    const double mp2_energy  = -75.7080410460;
    const double ccsd_energy = -75.7152972494;
    const double cc_t_energy = -75.7166228920;

    // <Item name="MP2" value="-75.7080410459820428" done="true"/>
    // <Item name="CCSD" value="-75.7152972493591392" done="true">
    //     <Item name="1" value="-75.7114047772544438"/>
    //     <Item name="2" value="-75.7150068138121242"/>
    //     <Item name="3" value="-75.7152816480859343"/>
    //     <Item name="4" value="-75.7153071378344436"/>
    //     <Item name="5" value="-75.7152981874026949"/>
    //     <Item name="6" value="-75.7152973446152373"/>
    //     <Item name="7" value="-75.7152973796429478"/>
    //     <Item name="8" value="-75.7152972480084969"/>
    //     <Item name="9" value="-75.7152972493591392"/>
    // </Item>
    // <Item name="CCSD(T)" value="-75.7166228920" done="true"/>

    // First we check that there are three children.
    BOOST_CHECK_EQUAL(tree.size(), 3);
    for (const auto& item : tree) {
        if (item.second.get<std::string>("<xmlattr>.name") == "MP2") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), mp2_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
        } else if (item.second.get<std::string>("<xmlattr>.name") == "CCSD") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), ccsd_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
            // + 1 due to the <xmlattr> child
            BOOST_CHECK_EQUAL(item.second.size(), number_of_ccsd_cycles + 1);
            for (const auto& subitem : item.second) { 
                if (subitem.first == "Item") {
                    int name = subitem.second.get<int>("<xmlattr>.name");
                    double value = subitem.second.get<double>("<xmlattr>.value");
                    BOOST_CHECK_CLOSE(value, ccsd_cycles.at(name - 1), tolerance);
                }
            }
        } else if (item.second.get<std::string>("<xmlattr>.name") == "CCSD(T)") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), cc_t_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
        } else {
            BOOST_ERROR("unexpected item in tree");
        }
    }
}

BOOST_AUTO_TEST_CASE(test_dalton_coupled_cluster_section_reader_cc2)
{
    kemiisto::io::input_string_stream stream(dalton_coupled_cluster_section_water_cc2);
    stream.read_line();

    boost::property_tree::ptree tree;
    ccio::dalton_coupled_cluster_section_reader reader(stream, tree);
    reader.read();

    const double mp2_energy = -75.7080410460;
    const double cc2_energy = -75.7088571864;

    const int number_of_cc2_cycles = 8;
    const std::array<double, number_of_cc2_cycles> cc2_cycles = {{
        -75.7080232755880616,
        -75.7088253520351913,
        -75.7088651759714821,
        -75.7088564496682608,
        -75.7088567780194950,
        -75.7088571750223878,
        -75.7088571888367596,
        -75.7088571863635735
    }};

    // <Item name="MP2" value="-75.7080410459820428" done="true"/>
    // <Item name="CC2" value="-75.7088571863635735" done="true">
    //     <Item name="1" value="-75.7080232755880616"/>
    //     <Item name="2" value="-75.7088253520351913"/>
    //     <Item name="3" value="-75.7088651759714821"/>
    //     <Item name="4" value="-75.7088564496682608"/>
    //     <Item name="5" value="-75.7088567780194950"/>
    //     <Item name="6" value="-75.7088571750223878"/>
    //     <Item name="7" value="-75.7088571888367596"/>
    //     <Item name="8" value="-75.7088571863635735"/>
    // </Item>

    BOOST_CHECK_EQUAL(tree.size(), 2);
    for (const auto& item : tree) {
        if (item.second.get<std::string>("<xmlattr>.name") == "MP2") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), mp2_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
        } else if (item.second.get<std::string>("<xmlattr>.name") == "CC2") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), cc2_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
            // + 1 due to the <xmlattr> child
            BOOST_CHECK_EQUAL(item.second.size(), number_of_cc2_cycles + 1);
            for (const auto& subitem : item.second) { 
                if (subitem.first == "Item") {
                    int name = subitem.second.get<int>("<xmlattr>.name");
                    double value = subitem.second.get<double>("<xmlattr>.value");
                    BOOST_CHECK_CLOSE(value, cc2_cycles.at(name - 1), tolerance);
                }
            }
        } else {
            BOOST_ERROR("unexpected item in tree");
        }
    }
}

BOOST_AUTO_TEST_CASE(test_dalton_coupled_cluster_section_reader_cc3)
{
    kemiisto::io::input_string_stream stream(dalton_coupled_cluster_section_water_cc3);
    stream.read_line();

    boost::property_tree::ptree tree;
    ccio::dalton_coupled_cluster_section_reader reader(stream, tree);
    reader.read();

    const double mp2_energy = -75.7080410460;
    const double cc3_energy = -75.7166699241;

    const int number_of_cc3_cycles = 9;
    const std::array<double, number_of_cc3_cycles> cc3_cycles = {{
        -75.7126898459464428,
        -75.7165401128308133,
        -75.7166561096745880,
        -75.7166804170342118,
        -75.7166699365157996,
        -75.7166699844726310,
        -75.7166700329676701,
        -75.7166699189471615,
        -75.7166699241159478
    }};

    // <Item name="MP2" value="-75.7080410459820428" done="true"/>
    // <Item name="CC3" value="-75.7166699241159478" done="true">
    //     <Item name="1" value="-75.7126898459464428"/>
    //     <Item name="2" value="-75.7165401128308133"/>
    //     <Item name="3" value="-75.7166561096745880"/>
    //     <Item name="4" value="-75.7166804170342118"/>
    //     <Item name="5" value="-75.7166699365157996"/>
    //     <Item name="6" value="-75.7166699844726310"/>
    //     <Item name="7" value="-75.7166700329676701"/>
    //     <Item name="8" value="-75.7166699189471615"/>
    //     <Item name="9" value="-75.7166699241159478"/>
    // </Item>

    BOOST_CHECK_EQUAL(tree.size(), 2);
    for (const auto& item : tree) {
        if (item.second.get<std::string>("<xmlattr>.name") == "MP2") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), mp2_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
        } else if (item.second.get<std::string>("<xmlattr>.name") == "CC3") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), cc3_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
            // + 1 due to the <xmlattr> child
            BOOST_CHECK_EQUAL(item.second.size(), number_of_cc3_cycles + 1);
            for (const auto& subitem : item.second) { 
                if (subitem.first == "Item") {
                    int name = subitem.second.get<int>("<xmlattr>.name");
                    double value = subitem.second.get<double>("<xmlattr>.value");
                    BOOST_CHECK_CLOSE(value, cc3_cycles.at(name - 1), tolerance);
                }
            }
        } else {
            BOOST_ERROR("unexpected item in tree");
        }
    }
}

BOOST_AUTO_TEST_CASE(test_dalton_coupled_cluster_section_reader_ccd)
{
    kemiisto::io::input_string_stream stream(dalton_coupled_cluster_section_water_ccd);
    stream.read_line();

    boost::property_tree::ptree tree;
    ccio::dalton_coupled_cluster_section_reader reader(stream, tree);
    reader.read();

    const double mp2_energy = -75.7080410460;
    const double ccd_energy = -75.7145070435;

    const int number_of_ccd_cycles = 8;
    const std::array<double, number_of_ccd_cycles> ccd_cycles = {{
        -75.7114225476481266,
        -75.7144965483238366,
        -75.7144698768817932,
        -75.7145072172477427,
        -75.7145069949516625,
        -75.7145068376580781,
        -75.7145070501725286,
        -75.7145070435463055
    }};

    boost::property_tree::xml_writer_settings<std::string> settings(' ', 4);
    boost::property_tree::write_xml(std::cout, tree, settings);

    // <Item name="MP2" value="-75.7080410459820428" done="true"/>
    // <Item name="CCD" value="-75.7145070435463055" done="true">
    //     <Item name="1" value="-75.7114225476481266"/>
    //     <Item name="2" value="-75.7144965483238366"/>
    //     <Item name="3" value="-75.7144698768817932"/>
    //     <Item name="4" value="-75.7145072172477427"/>
    //     <Item name="5" value="-75.7145069949516625"/>
    //     <Item name="6" value="-75.7145068376580781"/>
    //     <Item name="7" value="-75.7145070501725286"/>
    //     <Item name="8" value="-75.7145070435463055"/>
    // </Item>

    BOOST_CHECK_EQUAL(tree.size(), 2);
    for (const auto& item : tree) {
        if (item.second.get<std::string>("<xmlattr>.name") == "MP2") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), mp2_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
        } else if (item.second.get<std::string>("<xmlattr>.name") == "CCD") {
            BOOST_CHECK_CLOSE(item.second.get<double>("<xmlattr>.value"), ccd_energy, tolerance);
            BOOST_CHECK_EQUAL(item.second.get<bool>("<xmlattr>.done"), true);
            // + 1 due to the <xmlattr> child
            BOOST_CHECK_EQUAL(item.second.size(), number_of_ccd_cycles + 1);
            for (const auto& subitem : item.second) { 
                if (subitem.first == "Item") {
                    int name = subitem.second.get<int>("<xmlattr>.name");
                    double value = subitem.second.get<double>("<xmlattr>.value");
                    BOOST_CHECK_CLOSE(value, ccd_cycles.at(name - 1), tolerance);
                }
            }
        } else {
            BOOST_ERROR("unexpected item in tree");
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
