/**********************************************************************
    Copyright (C) 2014,2015 Anton Simakov

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

#ifndef CONE_H
#define CONE_H

#include <memory>

#include <Eigen/Core>

namespace molekulo
{
    class Cone
    {
    public:
        Cone(int faces);
        ~Cone();

        void draw(const Eigen::Vector3f& vertex1, const Eigen::Vector3f& vertex2, float radius) const;

    private:
        struct ConePrivate;
        std::unique_ptr<ConePrivate> p;
    };

}

#endif // RENDER_CONE_H
