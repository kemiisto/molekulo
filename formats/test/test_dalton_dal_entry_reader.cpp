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


#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "formats/dalton/dalton_dal_entry_reader.h"
#include "formats/dalton/dalton_dal_entry.h"
#include "io/input_string_stream.h"

BOOST_AUTO_TEST_SUITE(test_dalton_dal_entry_reader)

BOOST_AUTO_TEST_CASE(test_dalton_dal_entry_reader_hf_run_wf)
{
    std::string s = R"(
**DALTON INPUT
.RUN WAVE FUNCTIONS
**WAVE FUNCTIONS
.HF
**END OF INPUT)";

    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    ccio::dalton_dal_entry dal_entry;
    ccio::dalton_dal_entry_reader reader(stream, dal_entry);
    reader.read();

    BOOST_CHECK(dal_entry.get_job_type() == ccio::dalton_dal_entry::job_type::run_wave_functions);
    BOOST_CHECK(dal_entry.method_types().at(0) == ccio::method_type::scf);
    BOOST_CHECK(dal_entry.scf_types().at(0) == ccio::scf_type::diis);
    BOOST_CHECK(dal_entry.scf_types().at(1) == ccio::scf_type::qc);
    BOOST_CHECK(dal_entry.has_parametre("**DALTON INPUT", ".RUN WAVE FUNCTIONS"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS", ".HF"));
}

BOOST_AUTO_TEST_CASE(test_dalton_dal_entry_reader_hf_run_wf_nodiis)
{
    std::string s = R"(
**DALTON INPUT
.RUN WAVE FUNCTIONS
**WAVE FUNCTIONS
.HF
*SCF INPUT
.NODIIS
**END OF INPUT)";

    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    ccio::dalton_dal_entry dal_entry;
    ccio::dalton_dal_entry_reader reader(stream, dal_entry);
    reader.read();

    BOOST_CHECK(dal_entry.get_job_type() == ccio::dalton_dal_entry::job_type::run_wave_functions);
    BOOST_CHECK(dal_entry.method_types().at(0) == ccio::method_type::scf);
    BOOST_CHECK(dal_entry.scf_types().at(0) == ccio::scf_type::qc);
    BOOST_CHECK(dal_entry.has_parametre("**DALTON INPUT", ".RUN WAVE FUNCTIONS"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS", ".HF"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS/*SCF INPUT", ".NODIIS"));
}

BOOST_AUTO_TEST_CASE(test_dalton_dal_entry_reader_mp2_run_wf)
{
    std::string s = R"(
**DALTON INPUT
.RUN WAVE FUNCTIONS
**WAVE FUNCTIONS
.HF
.MP2
**END OF INPUT)";

    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    ccio::dalton_dal_entry dal_entry;
    ccio::dalton_dal_entry_reader reader(stream, dal_entry);
    reader.read();

    BOOST_CHECK(dal_entry.get_job_type() == ccio::dalton_dal_entry::job_type::run_wave_functions);
    BOOST_CHECK(dal_entry.method_types().at(0) == ccio::method_type::scf);
    BOOST_CHECK(dal_entry.method_types().at(1) == ccio::method_type::mp2);
    BOOST_CHECK(dal_entry.scf_types().at(0) == ccio::scf_type::diis);
    BOOST_CHECK(dal_entry.scf_types().at(1) == ccio::scf_type::qc);
    BOOST_CHECK(dal_entry.has_parametre("**DALTON INPUT", ".RUN WAVE FUNCTIONS"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS", ".HF"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS", ".MP2"));
}

BOOST_AUTO_TEST_CASE(test_dalton_dal_entry_reader_energy_hsrohf)
{
    std::string s = R"(
**DALTON                                          
.RUN WAVE                                         
.DIRECT                                           
**WAVE FUNCTION                                   
.HF                                               
.MP2                                              
*SCF INPUT                                        
.DOUBLY                                           
 3 1 1 0 2 0 0 0                                  
.SINGLY                                           
 0 0 0 0 0 1 1 0                                  
*MP2 INPUT                                        
.PRINT                                            
 5                                                
**END OF)";

    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    ccio::dalton_dal_entry dal_entry;
    ccio::dalton_dal_entry_reader reader(stream, dal_entry);
    reader.read();

    BOOST_CHECK(dal_entry.get_job_type() == ccio::dalton_dal_entry::job_type::run_wave_functions);
    BOOST_CHECK(dal_entry.method_types().at(0) == ccio::method_type::scf);
    BOOST_CHECK(dal_entry.method_types().at(1) == ccio::method_type::mp2);
    BOOST_CHECK(dal_entry.scf_types().at(0) == ccio::scf_type::diis);
    BOOST_CHECK(dal_entry.scf_types().at(1) == ccio::scf_type::qc);
    BOOST_CHECK(dal_entry.has_parametre("**DALTON INPUT", ".RUN WAVE FUNCTIONS"));
    BOOST_CHECK(dal_entry.has_parametre("**DALTON INPUT", ".DIRECT"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS", ".HF"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS", ".MP2"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS/*SCF INPUT", ".DOUBLY"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS/*SCF INPUT", ".SINGLY"));
    BOOST_CHECK(dal_entry.has_parametre("**WAVE FUNCTIONS/*MP2 INPUT", ".PRINT"));
}

BOOST_AUTO_TEST_CASE(test_dalton_dal_entry_reader_prop_roa)
{
    std::string s = R"(
**DALTON INPUT
.WALK
.MAX IT
 50
*WALK
.NUMERI
.PRINT
 1
.DISPLA
 0.001
**WAVE FUNCTIONS
.HF
*SCF INPUT
.THRESH
1.0D-8
**START
.VROA
*ABALNR
.THRESH
5.0D-8
.FREQUE
     3
0.0932147101 0.088558504 0.08564539532
**EACH STEP
.VROA
*ABALNR
.THRESH
5.0D-8
.FREQUE
     3
0.0932147101 0.088558504 0.08564539532
**PROPERTIES
.VROA
.RAMAN
.VIBANA
*RESPON
.THRESH
1.0D-6
*ABALNR
.THRESH
5.0D-8
.FREQUE
     3
0.0932147101 0.088558504 0.08564539532
*VIBANA
.HESPUN
.ISOTOP
   4   7
1 1 1 2 1 1 2
1 1 1 1 2 2 1
1 1 1 2 1 2 1
1 1 1 1 2 1 2
**END OF DALTON INPUT)";

    kemiisto::io::input_string_stream stream(s);
    stream.read_line();

    ccio::dalton_dal_entry dal_entry;
    ccio::dalton_dal_entry_reader reader(stream, dal_entry);
    reader.read();

    BOOST_CHECK(dal_entry.get_job_type() == ccio::dalton_dal_entry::job_type::walk);
    BOOST_CHECK(dal_entry.method_types().at(0) == ccio::method_type::scf);
    BOOST_CHECK(dal_entry.scf_types().at(0) == ccio::scf_type::diis);
    BOOST_CHECK(dal_entry.scf_types().at(1) == ccio::scf_type::qc);
}

BOOST_AUTO_TEST_SUITE_END()
