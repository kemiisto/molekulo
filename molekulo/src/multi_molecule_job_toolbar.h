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

#ifndef MULTI_MOLECULE_JOB_TOOLBAR_H
#define MULTI_MOLECULE_JOB_TOOLBAR_H

#include <memory>
#include <QToolBar>

#include "formats/multi_molecule_job.h"
#include "ui_multi_molecule_job_toolbar.h"

namespace molekulo
{
    class MultiMoleculeJobToolbar : public QToolBar
    {
        Q_OBJECT

    public:
        MultiMoleculeJobToolbar(ccio::multi_molecule_job& job, QWidget* parent = 0);
        ~MultiMoleculeJobToolbar();

    private:
        struct MultiMoleculeJobToolbarPrivate;
        std::unique_ptr<MultiMoleculeJobToolbarPrivate> p;

    private slots:
        void nextMolecule();
    };
}

#endif // MULTI_MOLECULE_JOB_TOOLBAR_H
