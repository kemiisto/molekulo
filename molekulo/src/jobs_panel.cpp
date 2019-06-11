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

#include "jobs_panel.h"

#include <iostream>
#include <boost/property_tree/ptree.hpp>

struct molekulo::JobsPanel::JobsPanelPrivate
{
    Ui::JobsPanel ui;

    JobsPanelPrivate() :
        ui()
    {}
};

molekulo::JobsPanel::JobsPanel(const boost::property_tree::ptree& tree, QWidget *parent) :
    QWidget(parent),
    p(new JobsPanelPrivate())
{
    p->ui.setupUi(this);

    QIcon doneIcon(QString::fromUtf8(":/icons/16x16/done.png"));
    QIcon notDoneIcon(QString::fromUtf8(":/icons/16x16/notDone.png"));

    for (auto job : tree.get_child("Out")) {
        if (job.first == "Job") {
            std::string jobName = job.second.get<std::string>("<xmlattr>.type");
            bool done = job.second.get<bool>("<xmlattr>.done");
            p->ui.comboBoxJobTitle->addItem(QString::fromStdString(jobName));
            if (done) {
                p->ui.comboBoxJobTitle->setItemIcon(p->ui.comboBoxJobTitle->count() - 1, doneIcon);
            } else {
                p->ui.comboBoxJobTitle->setItemIcon(p->ui.comboBoxJobTitle->count() - 1, notDoneIcon);
            }
            for (auto item : job.second) {
                if (item.first == "Item") {
                    std::string itemName = item.second.get<std::string>("<xmlattr>.name");
                    std::string itemValue = item.second.get("<xmlattr>.value", "");
                    bool itemDone = item.second.get("<xmlattr>.done", false);
                    QTreeWidgetItem* itemTreeWidgetItem = new QTreeWidgetItem(p->ui.treeWidgetJobDetails);
                    itemTreeWidgetItem->setText(0, QString::fromStdString(itemName));
                    itemTreeWidgetItem->setText(1, QString::fromStdString(itemValue));
                    if (!itemDone) {
                        itemTreeWidgetItem->setForeground(0, QBrush(Qt::red));
                        itemTreeWidgetItem->setForeground(1, QBrush(Qt::red));
                    }
                    for (auto subitem : item.second) {
                        if (subitem.first == "Item") {
                            std::string subitemName = subitem.second.get<std::string>("<xmlattr>.name");
                            std::string subitemValue = subitem.second.get<std::string>("<xmlattr>.value");
                            QTreeWidgetItem* subitemTreeWidgetItem = new QTreeWidgetItem();
                            subitemTreeWidgetItem->setText(0, QString::fromStdString(subitemName));
                            subitemTreeWidgetItem->setText(1, QString::fromStdString(subitemValue));
                            itemTreeWidgetItem->addChild(subitemTreeWidgetItem);
                        }
                    }
                }
            }
        }
    }
}

molekulo::JobsPanel::~JobsPanel()
{
}

/*
void molekulo::JobsPanel::addJob(const molekulo::OutFileJob* job)
{
    int n = ui_.comboBoxJobTitle->count() + 1;
    // QString s = QString("#%1 %2").arg(n).arg(QString::fromStdString(job->description()));
    // ui_.comboBoxJobTitle->addItem(s);

    QIcon icon;
    if (job->done()) {
    	icon.addFile(QString::fromUtf8(":/icons/16x16/done.png"));
    } else {
    	icon.addFile(QString::fromUtf8(":/icons/16x16/notDone.png"));
    }
    // ui_.comboBoxJobTitle->setItemIcon(ui_.comboBoxJobTitle->count() - 1, icon);

    for (auto it = job->items().cbegin(); it != job->items().cend(); ++it) {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui_.treeWidgetJobDetails);
        item->setText(0, QString::fromStdString(it->name()));
        item->setText(1, QString::fromStdString(it->value()));
        for (auto s = it->subitems().cbegin(); s != it->subitems().cend(); ++s) {
            QTreeWidgetItem* subitem = new QTreeWidgetItem();
            subitem->setText(0, QString::fromStdString(s->name()));
            subitem->setText(1, QString::fromStdString(s->value()));
            item->addChild(subitem);
        }
    }
}
*/