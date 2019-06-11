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

#include "dal_file_window.h"
#include "ui_dal_file_window.h"

#include "formats/dalton/dalton_dal_entry.h"

molekulo::DalFileWindow::DalFileWindow(std::unique_ptr<ccio::DaltonDalFile> dalFile) :
    ui_(new Ui::DalFileWindow),
    dalFile_(std::move(dalFile))
{
    ui_->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(QString::fromStdString(dalFile_->file_name()) + " - Molekulo " +
                   QCoreApplication::applicationVersion());

    for (auto it = ccio::dalton_dal_entry::string_to_job_type.cbegin();
            it != ccio::dalton_dal_entry::string_to_job_type.cend(); ++it) {
        ui_->comboBoxJobType->addItem(QString::fromStdString(it->first));
    }

    // FIX: iterate over method names, not types!
    for (auto it = ccio::dalton_dal_entry::string_to_method_type.cbegin();
            it != ccio::dalton_dal_entry::string_to_method_type.cend(); ++it) {
        ui_->comboBoxWaveFunction->addItem(QString::fromStdString(it->first));
    }

    connect(ui_->comboBoxJobType, SIGNAL(currentIndexChanged(int)),
            this, SLOT(jobTypeChanged(int)));

    ui_->comboBoxJobType->setCurrentIndex(static_cast<int>(dalFile_->dalEntry().get_job_type()));
    // ui_->checkBoxDirect->setChecked(dalFile_->dalEntry().module("**DALTON INPUT").hasParametre(".DIRECT"));

    ui_->textEditDalFile->setHtml(QString("<pre>%1</pre>").arg(QString::fromStdString(dalFile_->text())));
}

molekulo::DalFileWindow::~DalFileWindow()
{
    delete ui_;
}

void molekulo::DalFileWindow::jobTypeChanged(int index)
{
    const std::map<ccio::dalton_dal_entry::job_type, std::string> map = ccio::dalton_dal_entry::job_type_to_description;
    auto it = map.find(ccio::dalton_dal_entry::job_type(index));
    assert(it != map.cend());
    ui_->labelJobTypeTip->setText(QString::fromStdString(it->second));
}
