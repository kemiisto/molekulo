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

#include "formats/dalton/dalton_mol_entry_reader.h"
#include "formats/dalton/dalton_mol_entry.h"
#include "io/input_string_stream.h"

#include "data/dalton_mol_entry_water.h"
#include "data/dalton_mol_entry_water_gen.h"
#include "data/dalton_mol_entry_water_nosymm.h"

#include "data/dalton_mol_entry_energy_corehole__1_energy_corehole_ref.h"
#include "data/dalton_mol_entry_energy_restart_scf_ref.h"
#include "data/dalton_mol_entry_reader_aba_prop_file_ref.h"
#include "data/dalton_mol_entry_reader_cc2_r12_aux_ch4_a2_ref.h"

BOOST_AUTO_TEST_SUITE(test_dalton_mol_entry_reader)

BOOST_AUTO_TEST_CASE(test_dalton_mol_entry_reader_water)
{
    kemiisto::io::input_string_stream stream(daltonMolEntryWater);
    stream.read_line();

    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_mol_entry_reader reader(stream, mol_entry);
    reader.read();

    BOOST_CHECK_EQUAL(mol_entry.get_basis_type(), ccio::dalton_mol_entry::basis_type::basis);
    BOOST_CHECK_EQUAL(mol_entry.get_comment(), "Water\nusing the 6-31G** basis");
    BOOST_CHECK_EQUAL(mol_entry.get_atom_types(), 2);
    BOOST_CHECK_EQUAL(mol_entry.get_number_of_generators(), 0);
    BOOST_CHECK_EQUAL(mol_entry.get_nosymmetry(), false);
    BOOST_CHECK_EQUAL(mol_entry.get_unit_of_length(), ccio::dalton_mol_entry::unit_of_length::bohr);
    BOOST_CHECK_EQUAL(mol_entry.get_molecule().number_of_atoms(), 3);
}

BOOST_AUTO_TEST_CASE(test_dalton_mol_entry_reader_water_gen)
{
    kemiisto::io::input_string_stream stream(daltonMolEntryWaterGen);
    stream.read_line();

    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_mol_entry_reader reader(stream, mol_entry);
    reader.read();

    BOOST_CHECK_EQUAL(mol_entry.get_basis_type(), ccio::dalton_mol_entry::basis_type::basis);
    BOOST_CHECK_EQUAL(mol_entry.get_comment(), "H2O\n");
    BOOST_CHECK_EQUAL(mol_entry.get_atom_types(), 2);
    BOOST_CHECK_EQUAL(mol_entry.get_number_of_generators(), 2);
    BOOST_CHECK_EQUAL(mol_entry.get_nosymmetry(), false);
    BOOST_CHECK_EQUAL(mol_entry.get_unit_of_length(), ccio::dalton_mol_entry::unit_of_length::bohr);
    BOOST_CHECK_EQUAL(mol_entry.get_molecule().number_of_atoms(), 2);
}

BOOST_AUTO_TEST_CASE(test_dalton_mol_entry_reader_water_nosymm)
{
    kemiisto::io::input_string_stream stream(daltonMolEntryWaterNosymm);
    stream.read_line();

    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_mol_entry_reader reader(stream, mol_entry);
    reader.read();

    BOOST_CHECK_EQUAL(mol_entry.get_basis_type(), ccio::dalton_mol_entry::basis_type::basis);
    BOOST_CHECK_EQUAL(mol_entry.get_comment(), "H2O\n");
    BOOST_CHECK_EQUAL(mol_entry.get_atom_types(), 2);
    BOOST_CHECK_EQUAL(mol_entry.get_number_of_generators(), 0);
    BOOST_CHECK_EQUAL(mol_entry.get_nosymmetry(), true);
    BOOST_CHECK_EQUAL(mol_entry.get_unit_of_length(), ccio::dalton_mol_entry::unit_of_length::angstrom);
    BOOST_CHECK_EQUAL(mol_entry.get_molecule().number_of_atoms(), 3);
}

// from DALTON/test/trueresult/energy_corehole__1_energy_corehole.ref
BOOST_AUTO_TEST_CASE(test_dalton_mol_entry_reader_energy_corehole__1_energy_corehole_ref)
{
    kemiisto::io::input_string_stream stream(daltonMolEntryEnergyCorehole1EnergyCorehole);
    stream.read_line();

    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_mol_entry_reader reader(stream, mol_entry);
    reader.read();

    BOOST_CHECK_EQUAL(mol_entry.get_basis_type(), ccio::dalton_mol_entry::basis_type::intgrl);
    BOOST_CHECK_EQUAL(mol_entry.get_comment(),
                      "Calculation of core-hole excitations using both a frozen and a relaxed\ncore orbital. This is a three step job");
    BOOST_CHECK_EQUAL(mol_entry.get_atom_types(), 2);
    BOOST_CHECK_EQUAL(mol_entry.get_number_of_generators(), 2);
    BOOST_CHECK_EQUAL(mol_entry.get_nosymmetry(), false);
    BOOST_CHECK_EQUAL(mol_entry.get_unit_of_length(), ccio::dalton_mol_entry::unit_of_length::bohr);
    BOOST_CHECK_EQUAL(mol_entry.get_molecule().number_of_atoms(), 2);
}

// from DALTON/test/trueresult/energy_restart_scf.ref
BOOST_AUTO_TEST_CASE(test_dalton_mol_entry_reader_energy_restart_scf_ref)
{
    kemiisto::io::input_string_stream stream(daltonMolEntryEnergyRestartScfRef);
    stream.read_line();

    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_mol_entry_reader reader(stream, mol_entry);
    reader.read();

    BOOST_CHECK_EQUAL(mol_entry.get_basis_type(), ccio::dalton_mol_entry::basis_type::basis);
    BOOST_CHECK_EQUAL(mol_entry.get_comment(), "Restarting an HF wave function optimization\n");
    BOOST_CHECK_EQUAL(mol_entry.get_atom_types(), 2);
    BOOST_CHECK_EQUAL(mol_entry.get_number_of_generators(), 0);
    BOOST_CHECK_EQUAL(mol_entry.get_nosymmetry(), false);
    BOOST_CHECK_EQUAL(mol_entry.get_unit_of_length(), ccio::dalton_mol_entry::unit_of_length::bohr);
    BOOST_CHECK_EQUAL(mol_entry.get_molecule().number_of_atoms(), 3);
}

// from DALTON/test/trueresult/aba_prop_file.ref
BOOST_AUTO_TEST_CASE(test_dalton_mol_entry_reader_aba_prop_file_ref)
{
    kemiisto::io::input_string_stream stream(daltonMolEntryAbaPropFileRef);
    stream.read_line();

    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_mol_entry_reader reader(stream, mol_entry);
    reader.read();

    BOOST_CHECK_EQUAL(mol_entry.get_basis_type(), ccio::dalton_mol_entry::basis_type::atombasis);
    BOOST_CHECK_EQUAL(mol_entry.get_comment(), "CH2O\n------------------------");
    BOOST_CHECK_EQUAL(mol_entry.get_atom_types(), 3);
    BOOST_CHECK_EQUAL(mol_entry.get_number_of_generators(), 0);
    BOOST_CHECK_EQUAL(mol_entry.get_nosymmetry(), false);
    BOOST_CHECK_EQUAL(mol_entry.get_unit_of_length(), ccio::dalton_mol_entry::unit_of_length::angstrom);
    BOOST_CHECK_EQUAL(mol_entry.get_molecule().number_of_atoms(), 4);
}

// from DALTON/test/trueresult/cc2_r12_aux_ch4_a2.ref
BOOST_AUTO_TEST_CASE(test_dalton_mol_entry_reader_cc2_r12_aux_ch4_a2_ref)
{
    kemiisto::io::input_string_stream stream(daltonMolEntryCc2R12AuxCh4A2Ref);
    stream.read_line();

    ccio::dalton_mol_entry mol_entry;
    ccio::dalton_mol_entry_reader reader(stream, mol_entry);
    reader.read();

    BOOST_CHECK_EQUAL(mol_entry.get_basis_type(), ccio::dalton_mol_entry::basis_type::intgrl);
    BOOST_CHECK_EQUAL(mol_entry.get_comment(), "CC2-R12/B calculation without symmetry\n");
    BOOST_CHECK_EQUAL(mol_entry.get_atom_types(), 4);
    BOOST_CHECK_EQUAL(mol_entry.get_number_of_generators(), 0);
    BOOST_CHECK_EQUAL(mol_entry.get_nosymmetry(), true);
    BOOST_CHECK_EQUAL(mol_entry.get_unit_of_length(), ccio::dalton_mol_entry::unit_of_length::bohr);
    BOOST_CHECK_EQUAL(mol_entry.get_molecule().number_of_atoms(), 5);
}

BOOST_AUTO_TEST_SUITE_END()
