/**********************************************************************
  Copyright (C) 2008-2014 Anton Simakov

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

#include "molecule_window.h"
#include "ui_molecule_window.h"

#include <memory>

#include <QCompleter>
#include <QDebug>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSpinBox>
#include <QSplitter>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtConcurrent/QtConcurrentFilter>
#include <QtConcurrent/QtConcurrentRun>
#else
#include <QtCore/QtConcurrentFilter>
#include <QtCore/QtConcurrentRun>
#endif

#include "formats/out_file.h"
#include "formats/dalton/dalton_dal_file.h"
#include "formats/gaussian/gaussian_out_file.h"
#include "about_dialog.h"
#include "dal_file_window.h"
#include "jobs_panel.h"
#include "multi_molecule_job_toolbar.h"
#include "viewer_settings_dialog.h"

#include "render/viewer.h"

bool isMoleculeWindow(QWidget* widget)
{
    return !std::strcmp(widget->metaObject()->className(), "molekulo::MoleculeWindow");
}

struct molekulo::MoleculeWindow::MoleculeWindowPrivate
{
    Ui::MoleculeWindow ui;
    molekulo::JobsPanel* jobsPanel;
    QVBoxLayout* viewerVBoxLayout;
    molekulo::Viewer* viewer;
    QTextEdit* summaryTextEdit;

    std::ostringstream os;
    QString dir;   

    MoleculeWindowPrivate(std::unique_ptr<ccio::molecule_file> moleculeFile) :
        ui(),
        jobsPanel(nullptr),
        viewerVBoxLayout(new QVBoxLayout()),
        viewer(new molekulo::Viewer(std::move(moleculeFile))),
        summaryTextEdit(new QTextEdit),
        os(),
        dir(QString::fromStdString(viewer->chemFile()->directory()))
    {}
};

molekulo::MoleculeWindow::MoleculeWindow(std::unique_ptr<ccio::molecule_file> moleculeFile):
    QMainWindow(),
    p(new MoleculeWindowPrivate(std::move(moleculeFile)))
{
    setAttribute(Qt::WA_DeleteOnClose);
    QSettings settings;
    p->viewer->readSettings(settings);
    
    p->summaryTextEdit->setReadOnly(true);

    setWindowTitle(QString::fromStdString(p->viewer->chemFile()->file_name()) + " - Molekulo " +
                   QCoreApplication::applicationVersion());
    // p->ui.statusBar.showMessage(QString::fromStdString());

    p->ui.setupUi(this);

// #if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
//     setUnifiedTitleAndToolBarOnMac(false);
// #endif

    QActionGroup* viewActionGroup = new QActionGroup(this);
    viewActionGroup->addAction(p->ui.viewMoleculeAction);
    viewActionGroup->addAction(p->ui.viewSummaryAction);

    ccio::out_file* outFile = dynamic_cast<ccio::out_file*>(p->viewer->chemFile().get());
    if (outFile) {
        p->jobsPanel = new molekulo::JobsPanel(outFile->tree(), this);
        p->ui.gridLayoutMain->addWidget(p->jobsPanel, 0, 0);
        p->ui.gridLayoutMain->addLayout(p->viewerVBoxLayout, 0, 1);
        p->viewerVBoxLayout->addWidget(p->viewer);
        p->ui.gridLayoutMain->addWidget(p->summaryTextEdit, 0, 1);
        p->ui.gridLayoutMain->setColumnStretch(0, 1);
        p->ui.gridLayoutMain->setColumnStretch(1, 2);
        std::cout << p->ui.gridLayoutMain->columnCount() << std::endl;
        // for (int i = 0; i < outFile->numberOfJobs(); ++i) {
        //     p->jobsPanel->addJob(outFile->job(i));
        // }
    } else {
        p->ui.gridLayoutMain->addLayout(p->viewerVBoxLayout, 0, 0);
        p->viewerVBoxLayout->addWidget(p->viewer);
        p->ui.gridLayoutMain->addWidget(p->summaryTextEdit, 0, 0);
    }
    p->summaryTextEdit->hide();

    QStringList stringList;

    // for (quint8 i = 1; i <= OpenBabel::etab.GetNumberOfElements(); ++i) {
    //     stringList.append(QString::fromLatin1(OpenBabel::etab.GetSymbol(i)));
    // }

    //    QCompleter* completer = new QCompleter(stringList, p->ui.comboBoxAtom);
    //    p->ui.comboBoxAtom->setCompleter(completer);

    // Multistep Gaussian jobs
    //    molekulo::GaussianOutFile* gaussianOutFile =
    //            dynamic_cast<molekulo::GaussianOutFile*>(p->viewer->chemFile().get());
    //    if (gaussianOutFile) {
    //        std::unique_ptr<molekulo::GaussianJob> job = gaussianOutFile->job(0);
    //    }

    connect(p->ui.fileNewAction, SIGNAL(triggered()),
            this, SLOT(newFile()));
    connect(p->ui.fileOpenAction, SIGNAL(triggered()),
            this, SLOT(openFile()));
    connect(p->ui.fileSaveAction, SIGNAL(triggered()),
            this, SLOT(saveFile()));
    connect(p->ui.fileSaveAsAction, SIGNAL(triggered()),
            this, SLOT(saveFileAs()));
    //    connect(p->ui.fileEditMolFileAction, SIGNAL(triggered()),
    //            this, SLOT(showFileMolGeneratorDialog()));
    connect(p->ui.fileExitAction, SIGNAL(triggered()),
            this, SLOT(exit()));

    connect(p->ui.moleculeExportImageAction, SIGNAL(triggered()),
            this, SLOT(exportImage()));

    connect(p->ui.viewViewerSettingsAction, SIGNAL(triggered()),
            this, SLOT(showViewerSettingsDialog()));
    connect(p->ui.viewMoleculeAction, SIGNAL(triggered()),
            this, SLOT(showMolecule()));
    connect(p->ui.viewSummaryAction, SIGNAL(triggered()),
            this, SLOT(showSummary()));

    connect(p->ui.windowsCascadeAction, SIGNAL(triggered()),
            this, SLOT(cascadeWindows()));
    connect(p->ui.windowsTileAction, SIGNAL(triggered()),
            this, SLOT(tileWindows()));

    connect(p->ui.helpAboutAction, SIGNAL(triggered()),
            this, SLOT(showAboutDialog()));
    connect(p->ui.helpAboutQtAction, SIGNAL(triggered()),
            qApp, SLOT(aboutQt()));

    //    connect(p->ui.pushButtonLabelsOnAtomsFont, SIGNAL(clicked()),
    //            this, SLOT(showFontDialogForLabelsOnAtoms()));
    //    connect(p->ui.pushButtonLabelsOnBondsFont, SIGNAL(clicked()),
    //            this, SLOT(showFontDialogForLabelsOnBonds()));

    //    connect(p->ui.comboBoxForceField, SIGNAL(currentIndexChanged(QString)),
    //            this, SLOT(setObForceFieldName(QString)));
    //    connect(p->ui.comboBoxSearchType, SIGNAL(currentIndexChanged(int)),
    //            this, SLOT(onSearchTypeChanged(int)));
    //    connect(p->ui.pushButtonOptimize, SIGNAL(clicked()),
    //            this, SLOT(startOptimization()));
    //    connect(p->ui.pushButtonSearch, SIGNAL(clicked()),
    //            this, SLOT(startConformationalSearch()));

    // connect(&p->mm, SIGNAL(optimizationFinished()),
    //         this, SLOT(onOptimizationFinished()));
    //    connect(&p->mm, SIGNAL(conformationalSearchFinished()),
    //            this, SLOT(onConformationalSearchFinished()));

    //  connect(&p->viewer->fileMol().molecule(), SIGNAL(becameEmpty()),
    //          this, SLOT(updateActionsForEmptyMolecule()));
    //  connect(&p->viewer->fileMol().molecule(), SIGNAL(becameNonempty()),
    //          this, SLOT(updateActionsForNonemptyMolecule()));

    //    connect(p->ui.checkBoxAxes, SIGNAL(toggled(bool)),
    //            &p->viewer, SLOT(setAxesVisible(bool)));
    //    connect(p->ui.doubleSpinBoxAxesSize, SIGNAL(valueChanged(double)),
    //            &p->viewer, SLOT(setAxesSize(double)));
    //    connect(p->ui.checkBoxDebugInfo, SIGNAL(toggled(bool)),
    //            &p->viewer, SLOT(setDebugInfoVisible(bool)));
    //    connect(p->ui.comboBoxLabelsOnAtoms, SIGNAL(currentIndexChanged(int)),
    //            &p->viewer, SLOT(setLabelsOnAtoms(int)));
    //    connect(p->ui.comboBoxLabelsOnBonds, SIGNAL(currentIndexChanged(int)),
    //            &p->viewer, SLOT(setLabelsOnBonds(int)));
    //    connect(p->ui.comboBoxAtom, SIGNAL(editTextChanged(QString)),
    //            &p->viewer, SLOT(setAtomSymbol(QString)));

    //  connect(&p->viewer->fileMol().molecule(), SIGNAL(repaintingIsNecessary()),
    //          &p->viewer, SLOT(updateGL()));
    // connect(&p->mm, SIGNAL(geometryChanged()),
    //         p->viewer, SLOT(updateGL()));

    //    p->ui.comboBoxForceField->setCurrentIndex(2);

    updateActionsForNonemptyMolecule();
}

molekulo::MoleculeWindow::~MoleculeWindow()
{
}

const QString& molekulo::MoleculeWindow::dir() const
{
    return p->dir;
}

void molekulo::MoleculeWindow::setDir(const QString &dir)
{
    p->dir = dir;
}

// Slots.

void molekulo::MoleculeWindow::newFile()
{
    //  molekulo::DaltonMolFile fileMol;
    //  newTab("untitled.mol", fileMol);
    //  p->ui.tabWidget->setCurrentIndex(p->ui.tabWidget->count() - 1);
}

void molekulo::MoleculeWindow::openFile()
{
    QStringList filters;
    filters << tr("All files") + " (*.*)"
            << tr("Input files") + " (*.dal *.mol)"
            << tr("Output files") + " (*.out *.log *.dat)";

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), p->dir, filters.join(";;"));

    if (!fileName.isEmpty()) {
        setDir(QFileInfo(fileName).absolutePath());
        try {
            std::unique_ptr<ccio::text_file> textFile = ccio::molecule_file::new_instance(fileName.toStdString());
            textFile->read();
            ccio::molecule_file* m = dynamic_cast<ccio::molecule_file*>(textFile.get());
            if (m != nullptr) {
                textFile.release();
                std::unique_ptr<ccio::molecule_file> moleculeFile(m);
                molekulo::MoleculeWindow* w = new molekulo::MoleculeWindow(std::move(moleculeFile));
                w->move(x() + 24, y() + 24);
                w->show();
            } else {
                ccio::DaltonDalFile* d = dynamic_cast<ccio::DaltonDalFile*>(textFile.get());
                if (d != nullptr) {
                    textFile.release();
                    std::unique_ptr<ccio::DaltonDalFile> dalFile(d);
                    molekulo::DalFileWindow* dalFileWindow = new molekulo::DalFileWindow(std::move(dalFile));
                    dalFileWindow->move(x() + 24, y() + 24);
                    dalFileWindow->show();
                }
            }
        } catch (const std::exception& e) {
            QMessageBox::critical(this, "Molekulo", e.what());
        }
    }
}

void molekulo::MoleculeWindow::saveFile()
{
    //  if (p->viewer->fileMol().absoluteFilePath().is_empty())
    //    saveMoleculeAs();
    //  else
    //    saveMoleculeAs(p->viewer->fileMol().absoluteFilePath());
}

void molekulo::MoleculeWindow::saveFileAs(const QString& absoluteFilePath)
{
    (void)absoluteFilePath;
    //  QString fileName;

    //  if (absoluteFilePath.is_empty())
    //    fileName = QFileDialog::getSaveFileName(
    //        this, tr("Save *.mol file"), dir(), tr("*.mol files(*.mol)"));
    //  else
    //    fileName = absoluteFilePath;

    //  if (!fileName.is_empty())
    //  {
    //    setDir(QFileInfo(fileName).absolutePath());
    //    addToLog(QString(
    //        tr("Saving *.mol file started. \nFileName: %1")).arg(fileName));
    //    if (p->viewer->fileMol().generate())
    //    {
    //      if (p->viewer->fileMol().save(fileName))
    //      {
    //        p->ui.tabWidget->setTabText(p->ui.tabWidget->currentIndex(),
    //                                  p->viewer->fileMol().fileName());
    //        addToLog(tr("Saving succeeded."));
    //      }
    //    }
    //  }
}

void molekulo::MoleculeWindow::showAboutDialog()
{
    AboutDialog dialog;
    dialog.setHeaderLabelText(
        "<h1>" + QCoreApplication::applicationName() +
        " " + QCoreApplication::applicationVersion() + "</h1>");
    dialog.exec();
}

void molekulo::MoleculeWindow::showViewerSettingsDialog()
{
    molekulo::ViewerSettingsDialog* dialog = new molekulo::ViewerSettingsDialog(p->viewer);
    dialog->show();
}

void molekulo::MoleculeWindow::showMolecule()
{
    p->viewer->show();
    p->summaryTextEdit->hide();
}

void molekulo::MoleculeWindow::showSummary()
{
    p->viewer->hide();
    p->summaryTextEdit->show();
}

//void molekulo::MoleculeWindow::showFileMolGeneratorDialog()
//{
//  p->viewer->fileMol().generate();

//  FileMolGeneratorDialog dialog(&p->viewer->fileMol(), this);
//  dialog.setWindowTitle(p->viewer->fileMol().fileName());
//  dialog.exec();
//}

void molekulo::MoleculeWindow::updateActionsForEmptyMolecule()
{
    //    p->ui.actionStructureAddHydrogensAndBuild->setEnabled(false);
    //    p->ui.actionStructureRemoveHydrogens->setEnabled(false);
    //    p->ui.actionStructureConformations->setEnabled(false);
    //    p->ui.actionStructureExportImage->setEnabled(false);
    //    p->ui.actionStructureExportImage->setEnabled(false);
}

void molekulo::MoleculeWindow::updateActionsForNonemptyMolecule()
{
    // p->ui.actionStructureAddHydrogensAndBuild->setEnabled(true);
    // p->ui.actionStructureRemoveHydrogens->setEnabled(true);
    //  p->ui.actionStructureConformations->setEnabled(true);
    p->ui.moleculeExportImageAction->setEnabled(true);
}

void molekulo::MoleculeWindow::exportImage()
{
    p->viewer->saveSnapshot(false, false);
}

void molekulo::MoleculeWindow::exit()
{
    if (QMessageBox::information(
            this,
            QCoreApplication::applicationName(),
            QString("Exit %1?").arg(QCoreApplication::applicationName()),
            QMessageBox::Ok | QMessageBox::Cancel,
            QMessageBox::Cancel) == QMessageBox::Ok) {
        close();
    }
}

void molekulo::MoleculeWindow::showFontDialogForLabelsOnAtoms()
{
    p->viewer->setLabelsOnAtomsFont(QFontDialog::getFont(
                                        0, p->viewer->labelsOnAtomsFont()));
}

void molekulo::MoleculeWindow::showFontDialogForLabelsOnBonds()
{
    p->viewer->setLabelsOnBondsFont(QFontDialog::getFont(
                                        0, p->viewer->labelsOnBondsFont()));
}

void molekulo::MoleculeWindow::tileWindows()
{
    QDesktopWidget* desktop = QApplication::desktop();
    QRect rect = desktop->availableGeometry();
    float aspectRatio = float(rect.width()) / rect.height();
    qDebug() << "aspect ratio = " << aspectRatio;

    int frameWidth = frameGeometry().width() - geometry().width();
    int frameHeight = frameGeometry().height() - geometry().height();

    QWidgetList windows = QApplication::topLevelWidgets();
    QtConcurrent::blockingFilter(windows, isMoleculeWindow);

    int rows = round(sqrt(windows.size() / aspectRatio));
    int columns = ceil(windows.size() / rows);
    qDebug() << "rows = " << rows;
    qDebug() << "columns = " << columns;

    if (windows.size() > 1) {
        windows[0]->move(rect.topLeft());
        windows[0]->resize(rect.width() / 2 - frameWidth, rect.height() - frameHeight);
        windows[1]->move((rect.topLeft() + rect.topRight()) / 2);
        windows[1]->resize(rect.width() / 2 - frameWidth, rect.height() - frameHeight);
    }

    foreach (QWidget* widget, windows) {
        qDebug() << widget->metaObject()->className();
        qDebug() << widget->pos();
    }
}

void molekulo::MoleculeWindow::cascadeWindows()
{

}
