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

#include "viewer_settings_dialog.h"

#include "ui_viewer_settings_dialog.h"

#include "render/viewer.h"

molekulo::ViewerSettingsDialog::ViewerSettingsDialog(molekulo::Viewer* parent) :
    QDialog(parent),
    ui(std::unique_ptr<Ui::ViewerSettingsDialog>(new Ui::ViewerSettingsDialog)),
    viewer(parent)
{
    ui->setupUi(this);
    setupQualitySlider();
    setupProjectionComboBox();
    setupViewComboBox();
    setupLabelsOnAtomsTypeComboBox();
    setupLabelsOnAtomsFontComboBox();
    setupBackgroundColorPushButton();
}

molekulo::ViewerSettingsDialog::~ViewerSettingsDialog()
{
}

void molekulo::ViewerSettingsDialog::setupQualitySlider()
{
    ui->qualitySlider->setValue(viewer->quality());
    connect(ui->qualitySlider, SIGNAL(valueChanged(int)),
        viewer, SLOT(setQuality(int)));
}

void molekulo::ViewerSettingsDialog::setupProjectionComboBox()
{
    const std::map<molekulo::Viewer::Projection, std::string>& map = molekulo::Viewer::projectionToDescription;
    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        ui->projectionComboBox->addItem(QString::fromStdString(it->second));
    }
    ui->projectionComboBox->setCurrentIndex(viewer->projection());
    connect(ui->projectionComboBox, SIGNAL(currentIndexChanged(int)),
            viewer, SLOT(setProjection(int)));
}

void molekulo::ViewerSettingsDialog::setupViewComboBox()
{
    const std::map<molekulo::Viewer::View, std::string>& map = molekulo::Viewer::viewToDescription;
    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        ui->viewComboBox->addItem(QString::fromStdString(it->second));
    }
    ui->viewComboBox->setCurrentIndex(viewer->view());
    connect(ui->viewComboBox, SIGNAL(currentIndexChanged(int)),
            viewer, SLOT(setView(int)));
}

void molekulo::ViewerSettingsDialog::setupLabelsOnAtomsTypeComboBox()
{
    const std::map<molekulo::Viewer::LabelsOnAtoms, std::string>& map = molekulo::Viewer::labelsOnAtomsToDescription;
    for (auto it = map.cbegin(); it != map.cend(); ++it) {
        ui->labelsOnAtomsTypeComboBox->addItem(QString::fromStdString(it->second));
    }
    ui->labelsOnAtomsTypeComboBox->setCurrentIndex(viewer->labelsOnAtoms());
    connect(ui->labelsOnAtomsTypeComboBox, SIGNAL(currentIndexChanged(int)),
            viewer, SLOT(setLabelsOnAtoms(int)));
}

void molekulo::ViewerSettingsDialog::setupLabelsOnAtomsFontComboBox()
{
    ui->labelsOnAtomsFontComboBox->setCurrentFont(viewer->labelsOnAtomsFont());
    connect(ui->labelsOnAtomsFontComboBox, SIGNAL(currentFontChanged(const QFont&)),
        viewer, SLOT(setLabelsOnAtomsFont(const QFont&)));
}

void molekulo::ViewerSettingsDialog::setupBackgroundColorPushButton()
{
    // ui->backgroundColorPushButton->
    connect(ui->backgroundColorPushButton, SIGNAL(clicked()), 
        this, SLOT(showColorDialog()));
}

void molekulo::ViewerSettingsDialog::showColorDialog()
{
    
}