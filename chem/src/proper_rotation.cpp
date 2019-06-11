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

#include "chem/proper_rotation.h"

#include <iostream>
#include <iomanip>
#include <boost/math/constants/constants.hpp>
#include <Eigen/Geometry>

#include "chem/atom.h"
#include "chem/element.h"
#include "chem/molecule.h"

#include "utility.h"

struct ccio::proper_rotation::proper_rotation_private
{
    ccio::proper_rotation::axis rotation_axis;
    int n;
    int m;

    proper_rotation_private(ccio::proper_rotation::axis rotation_axis, int n, int m) :
        rotation_axis(rotation_axis), n(n), m(m) {}
};

ccio::proper_rotation::proper_rotation(axis rotation_axis, int n, int m) :
    symmetry_operation(),
    p(new proper_rotation_private(rotation_axis, n, m))
{
}

ccio::proper_rotation::~proper_rotation()
{
}

void ccio::proper_rotation::apply(ccio::molecule& molecule) const
{
    using namespace boost::math::double_constants;
    double angle = 2 * pi * p->m / p->n ;
    Eigen::Matrix3d m;

    // Save original number of atom, so that we won't get an infinite loop.
    std::size_t n = molecule.number_of_atoms();

    for (std::size_t i = 0; i < n; ++i) {
        ccio::atom& atom = molecule.atom(i);
        Eigen::Vector3d v(atom.centre());
        switch (p->rotation_axis) {
        case axis::x:
            std::cout << "x" << std::endl;
            if (!kemiisto::is_close_to_zero(atom.centre().y()) ||
                    !kemiisto::is_close_to_zero(atom.centre().z())) {
                m = Eigen::AngleAxisd(angle, Eigen::Vector3d::UnitX());
                v = m * v;
                molecule.create_atom(atom.element().atomic_number(), v);
            }
            break;
        case axis::y:
            if (!kemiisto::is_close_to_zero(atom.centre().x()) ||
                    !kemiisto::is_close_to_zero(atom.centre().z())) {
                m = Eigen::AngleAxisd(angle, Eigen::Vector3d::UnitY());
                v = m * v;
                molecule.create_atom(atom.element().atomic_number(), v);
            }
            break;
        case axis::z:
            if (!kemiisto::is_close_to_zero(atom.centre().x()) || 
                    !kemiisto::is_close_to_zero(atom.centre().y())) {
                m = Eigen::AngleAxisd(angle, Eigen::Vector3d::UnitZ());
                v = m * v;
//                std::cout << std::setw(14) << std::fixed << std::setprecision(8)
//                    << v.x() << "    " << v.y() << "    " << v.z() << std::endl;
                molecule.create_atom(atom.element().atomic_number(), v);
            }
            break;
        }
    }

}
