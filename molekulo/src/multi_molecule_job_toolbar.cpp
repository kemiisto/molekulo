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

#include "multi_molecule_job_toolbar.h"

#include <QLabel>
#include <QSpinBox>

struct molekulo::MultiMoleculeJobToolbar::MultiMoleculeJobToolbarPrivate
{
    Ui::MultiMoleculeJobToolbar ui;
    ccio::multi_molecule_job& job;

    MultiMoleculeJobToolbarPrivate(ccio::multi_molecule_job& job) :
        ui(),
        job(job)
    {}
};

molekulo::MultiMoleculeJobToolbar::MultiMoleculeJobToolbar(ccio::multi_molecule_job& job, QWidget* parent) :
    QToolBar(parent),
    p(new MultiMoleculeJobToolbarPrivate(job))
{
    p->ui.setupUi(this);

//    QWidget* leftSpacer = new QWidget();
//    leftSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
//    insertWidget(p->ui.actionPlayPause, leftSpacer);

    QSpinBox* spinBox = new QSpinBox();
    spinBox->setMinimum(1);
    spinBox->setMaximum(p->job.number_of_molecules());
    spinBox->setValue(p->job.current_molecule_index() + 1);
    addWidget(spinBox);

    addWidget(new QLabel(QString(" of %1").arg(p->job.number_of_molecules())));

//    QWidget* rightSpacer = new QWidget();
//    rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
//    addWidget(rightSpacer);

    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(nextMolecule()));
}

molekulo::MultiMoleculeJobToolbar::~MultiMoleculeJobToolbar()
{
}

void molekulo::MultiMoleculeJobToolbar::nextMolecule()
{
    p->job.next_molecule();
}
