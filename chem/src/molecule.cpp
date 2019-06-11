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

#include "chem/molecule.h"

#include <boost/graph/adjacency_list.hpp>

#include "chem/atom.h"
#include "chem/bond.h"
#include "chem/element.h"
#include "chem/nuclide.h"
#include "chem/periodic_table.h"

#include "io/logger.h"
#include "io/not_implemented_exception.h"

struct ccio::molecule::molecule_private
{
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
          std::shared_ptr<ccio::atom>, std::shared_ptr<ccio::bond>> graph;
    int charge;
    Eigen::Vector3d plane_normal_vector;

    molecule_private() :
        graph(),
        charge(0),
        plane_normal_vector(Eigen::Vector3d(0.0, 0.0, 1.0))
    {
    }
};

ccio::molecule::molecule() :
    p(new molecule_private())
{
}

ccio::molecule::molecule(const ccio::molecule& molecule) :
    p(new molecule_private(*molecule.p))
{
}

ccio::molecule::~molecule()
{
}

ccio::molecule& ccio::molecule::operator=(const ccio::molecule& molecule)
{
    if (this != &molecule) {
        p.reset(new molecule_private(*molecule.p));
    }
    return *this;
}

std::size_t ccio::molecule::number_of_atoms() const
{
    return boost::num_vertices(p->graph);
}

std::size_t ccio::molecule::number_of_bonds() const
{
    return boost::num_edges(p->graph);
}

const ccio::atom& ccio::molecule::atom(std::size_t index) const
{
    if (index > number_of_atoms() - 1) {
        throw std::out_of_range("Atom index " + std::to_string(index) + " is out of range.");
    }

    return *(p->graph[index]);
}

ccio::atom& ccio::molecule::atom(std::size_t index)
{
    return const_cast<ccio::atom&>( static_cast<const ccio::molecule&>(*this).atom(index) );
}

const ccio::bond& ccio::molecule::bond(std::size_t index) const
{
    if (index > number_of_bonds()) {
        throw std::out_of_range("Bond index " + std::to_string(index) + " is out of range.");
    }

    auto b = boost::edges(p->graph).first;
    for (std::size_t i = 0; i < index; ++i) {
        ++b;
    }
    return *(p->graph[*b]);
}

ccio::bond& ccio::molecule::bond(std::size_t index)
{
    return const_cast<ccio::bond&>( static_cast<const ccio::molecule&>(*this).bond(index) );
}

void ccio::molecule::create_atom(unsigned int atomic_number, unsigned int mass_number,
        const Eigen::Vector3d& centre)
{
    ccio::atom* atom = new ccio::atom(*this, atomic_number, mass_number, centre);
    auto i = boost::add_vertex(p->graph);
    p->graph[i].reset(atom);
}

void ccio::molecule::create_atom(unsigned int atomic_number, const Eigen::Vector3d& centre)
{
    auto mass_number = ccio::default_periodic_table().element(atomic_number).isotope(0).mass_number();
    create_atom(atomic_number, mass_number, centre);
}

void ccio::molecule::create_atom(const std::string& symbol, const Eigen::Vector3d& centre)
{
    auto atomic_number = ccio::periodic_table().element(symbol).atomic_number();
    create_atom(atomic_number, centre);
}

void ccio::molecule::create_bond(std::size_t begin_atom_index, std::size_t end_atom_index, int bond_order)
{
    ccio::bond* bond = new ccio::bond(*this, begin_atom_index, end_atom_index, bond_order);
    auto i = boost::add_edge(begin_atom_index, end_atom_index, p->graph);
    if (i.second) {
        p->graph[i.first].reset(bond);
    } else {
        throw std::logic_error(
            "Unable to create an edge between vertices " +
            std::to_string(begin_atom_index) + " and " +
            std::to_string(end_atom_index)
        );
    }
}

// void ccio::molecule::remove_atom(unsigned int index)
// {
// }

// void ccio::molecule::remove_bond(unsigned int index)
// {
// }

int ccio::molecule::charge() const
{
    return p->charge;
}

void ccio::molecule::set_charge(int charge)
{
    p->charge = charge;
    LOG(debug) << "Molecule charge set to: " << p->charge << ".";
}

double ccio::molecule::interatomic_distance(std::size_t i, std::size_t j)
{
    return (atom(j).centre() - atom(i).centre()).norm();
}

void ccio::molecule::rebond()
{
    double tolerance = 0.5;
    for (std::size_t i = 0; i < number_of_atoms() - 1; ++i) {
        for (std::size_t j = i + 1; j < number_of_atoms(); ++j) {
            if (interatomic_distance(i, j) < atom(i).element().covalent_radius() +
                    atom(j).element().covalent_radius() + tolerance) {
                create_bond(i, j, 1);
            }
        }
    }
}

double ccio::molecule::radius() const
{
    if (number_of_atoms() >= 2) {
        double r = atom(0).centre().norm();
        for (std::size_t i = 1; i < number_of_atoms(); ++i) {
            double rr = atom(i).centre().norm();
            if (rr > r) r = rr;
        }
        return r;
    } else {
        return 10.0;
    }

}

bool ccio::molecule::is_empty() const
{
    return (number_of_atoms() == 0);
}

void ccio::molecule::clear()
{
    p->graph.clear();
    p->charge = 0;
    p->plane_normal_vector = Eigen::Vector3d(0.0, 0.0, 1.0);
}

const Eigen::Vector3d& ccio::molecule::plane_normal_vector() const
{
    return p->plane_normal_vector;
}

void ccio::molecule::set_plane_normal_vector(const Eigen::Vector3d& vector)
{
    p->plane_normal_vector = vector;
}
