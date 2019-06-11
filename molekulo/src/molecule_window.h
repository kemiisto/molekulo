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

/**********************************************************************
 **********************************************************************/

#ifndef MOLECULE_WINDOW_H
#define MOLECULE_WINDOW_H

#include <memory>

#include "chem/molecule.h"
#include "formats/molecule_file.h"

#include <QMainWindow>
#include <QTextEdit>

namespace molekulo
{
    class Viewer;
    class JobsPanel;

    class MoleculeWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MoleculeWindow(std::unique_ptr<ccio::molecule_file> moleculeFile);
        ~MoleculeWindow();

        const QString& dir() const;
        void setDir(const QString& dir);

    public slots:
        void newFile();
        void openFile();
        void saveFile();
        void saveFileAs(const QString& absoluteFilePath = "");
        void exit();

        void exportImage();
        
        void showViewerSettingsDialog();
        void showMolecule();
        void showSummary();
        
        void showAboutDialog();

        void tileWindows();
        void cascadeWindows();

        void updateActionsForEmptyMolecule();
        void updateActionsForNonemptyMolecule();

        void showFontDialogForLabelsOnAtoms();
        void showFontDialogForLabelsOnBonds();

    private:
        struct MoleculeWindowPrivate;
        std::unique_ptr<MoleculeWindowPrivate> p;
    };
}

#endif // MOLECULE_WINDOW_H
