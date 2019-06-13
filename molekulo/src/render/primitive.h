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

#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QObject>

namespace molekulo
{
// Define the overflow resulting from long (-1) as the error/not found
    const unsigned long FALSE_ID = std::numeric_limits<unsigned long>::max();

    class PrimitivePrivate;

    /**
     * @class Primitive primitive.h "render/primitive.h
     * @brief Base class for all primitives (Molecule, Atom, Bond, Residue, ...).
     */
    class Primitive : public QObject
    {
        Q_OBJECT

    public:
        /**
         * This enum allows us to iterate through the various types
         * of primitives.
         */
        enum Type {
            /// Untyped Primitive
            OtherType=0,
            /// Molecule Primitive
            MoleculeType,
            /// Atom Primitive
            AtomType,
            /// Bond Primitive
            BondType,
            /// Residue Primitive
            ResidueType,
            /// Chain Primitive (i.e., a set of residues)
            ChainType,
            /// Fragment Primitve
            FragmentType,
            /// Surface Primitive
            SurfaceType,
            /// Surface Mesh Primitive
            MeshType,
            /// Cube Primitive
            CubeType,
            /// Plane Primitive
            PlaneType,
            /// Grid Primitive
            GridType,
            /// Points (i.e., non-atoms)
            PointType,
            /// Lines
            LineType,
            /// Vectors (i.e., arrows, dipole moments)
            VectorType,
            /// Non-bonded interactions (i.e., non-bond connections)
            NonbondedType,
            /// Text annoations
            TextType,
            /// End Placeholder
            LastType,
            /// First Placeholder
            FirstType=OtherType
        };

        /**
         * Default constructor.
         * @param parent the object parent
         */
        explicit Primitive(QObject* parent = 0);

        virtual ~Primitive();

    protected:
        PrimitivePrivate* const d;
        enum Primitive::Type m_type;
        unsigned long m_id;
        unsigned long m_index;

    signals:

    public slots:

    };
}

#endif // PRIMITIVE_H
