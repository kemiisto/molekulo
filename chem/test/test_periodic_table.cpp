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
// #define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "chem/periodic_table.h"
#include "chem/element.h"
#include "chem/nuclide.h"
#include "tolerance.h"

BOOST_AUTO_TEST_SUITE(test_periodic_table)

BOOST_AUTO_TEST_CASE(test_periodic_table_number_of_elements)
{
    // 109 + the dummy one
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().number_of_elements(), 110);
}

BOOST_AUTO_TEST_CASE(test_periodic_table_element_by_atomic_number)
{
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element(  1).symbol(),  "H");
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element( 20).symbol(), "Ca");
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element( 40).symbol(), "Zr");
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element( 60).symbol(), "Nd");
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element( 80).symbol(), "Hg");
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element(100).symbol(), "Fm");
}

BOOST_AUTO_TEST_CASE(test_periodic_table_element_by_symbol)
{
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element( "H").atomic_number(),   1);
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element("Ca").atomic_number(),  20);
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element("Zr").atomic_number(),  40);
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element("Nd").atomic_number(),  60);
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element("Hg").atomic_number(),  80);
    BOOST_CHECK_EQUAL(ccio::default_periodic_table().element("Fm").atomic_number(), 100);
}

BOOST_AUTO_TEST_CASE(test_periodic_table_hydrogen)
{
    const ccio::element hydrogen = ccio::periodic_table().element(1);
    BOOST_CHECK_EQUAL(hydrogen.atomic_number()       , 1          );
    BOOST_CHECK_EQUAL(hydrogen.symbol()              , "H"        );
    BOOST_CHECK_EQUAL(hydrogen.name()                , "Hydrogen" );
    BOOST_CHECK_CLOSE(hydrogen.atomic_weight()       , 1.007825, tolerance);
    BOOST_CHECK_CLOSE(hydrogen.van_der_waals_radius(), 1.20    , tolerance);
    BOOST_CHECK_CLOSE(hydrogen.covalent_radius()     , 0.37    , tolerance);
    BOOST_CHECK_EQUAL(hydrogen.number_of_isotopes()  , 7          );

    std::vector<int> mass_numbers { 1, 2, 3, 4, 5, 6, 7 };
    std::vector<float> exact_masses{
        1.007825f,
        2.014102f,
        3.016049f,
        4.027810f,
        5.035310f,
        6.044940f,
        7.052750f
    };
    std::vector<float> natural_abundances{
        99.988500f,
         0.011500f,
         0.000000f,
         0.000000f,
         0.000000f,
         0.000000f,
         0.000000f
    };

    for (std::size_t i = 0; i < hydrogen.number_of_isotopes(); ++i) {
        BOOST_CHECK_EQUAL(hydrogen.isotope(i).mass_number(), mass_numbers[i]);
        BOOST_CHECK_CLOSE(hydrogen.isotope(i).exact_mass(), exact_masses[i], tolerance);
        BOOST_CHECK_CLOSE(
            hydrogen.isotope(i).natural_abundance(), natural_abundances[i], tolerance
        );
    }
}

BOOST_AUTO_TEST_CASE(test_periodic_table_calcium)
{
    const ccio::element calcium = ccio::periodic_table().element(20);
    BOOST_CHECK_EQUAL(calcium.atomic_number()       , 20         );
    BOOST_CHECK_EQUAL(calcium.symbol()              , "Ca"       );
    BOOST_CHECK_EQUAL(calcium.name()                , "Calcium"  );
    BOOST_CHECK_CLOSE(calcium.atomic_weight()       , 39.962591, tolerance);
    BOOST_CHECK_CLOSE(calcium.van_der_waals_radius(), 2.40     , tolerance);
    BOOST_CHECK_CLOSE(calcium.covalent_radius()     , 1.74     , tolerance);
    BOOST_CHECK_EQUAL(calcium.number_of_isotopes()  , 24         );

    // TEST ISOTOPES!
}

BOOST_AUTO_TEST_SUITE_END()
