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

#ifndef JOBS_PANEL_H
#define JOBS_PANEL_H

#ifndef Q_MOC_RUN // https://bugreports.qt-project.org/browse/QTBUG-22829
#include <boost/property_tree/ptree_fwd.hpp>
#endif
#include <QWidget>

#include "ui_jobs_panel.h"

namespace molekulo
{
    class JobsPanel : public QWidget
    {
        Q_OBJECT

    public:
        JobsPanel(const boost::property_tree::ptree& tree, QWidget* parent = 0);
        ~JobsPanel();

    private:
        struct JobsPanelPrivate;
        std::unique_ptr<JobsPanelPrivate> p;
    };
}

#endif // JOBS_PANEL_H
