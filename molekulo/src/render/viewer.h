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

#include <QtGlobal>

#ifndef VIEWER_H
#define VIEWER_H

#include <QMouseEvent>
#include <QSettings>
#include <QTableWidget>

#include "chem/atom.h"
#include "chem/bond.h"
#include "formats/molecule_file.h"
#include "render/color.h"
#include "render/constants.h"
#include "qglviewer/qglviewer.h"

namespace molekulo
{
    class Painter;

    class Viewer : public QGLViewer
    {
        Q_OBJECT

    public:
        enum View
        {
            ViewBallsAndBonds,
            ViewBallsAndSticks,
            ViewSticks,
            ViewVdWBalls
        };

        enum LabelsOnAtoms
        {
            LabelsOnAtomsNone,
            LabelsOnAtomsSymbol,
            LabelsOnAtomsIndex
        };

        enum LabelsOnBonds
        {
            LabelsOnBondsNone,
            LabelsOnBondsLength
        };

        enum Projection
        {
            ProjectionPerspective,
            ProjectionOrthographic
        };

        static const std::map<molekulo::Viewer::View, std::string> viewToDescription;
        static const std::map<molekulo::Viewer::LabelsOnAtoms, std::string> labelsOnAtomsToDescription;
        static const std::map<molekulo::Viewer::LabelsOnBonds, std::string> labelsOnBondsToDescription;
        static const std::map<molekulo::Viewer::Projection, std::string> projectionToDescription;

        Viewer(std::unique_ptr<ccio::molecule_file> chemFile);
        ~Viewer();

        const std::unique_ptr<ccio::molecule_file>& chemFile() const;

        bool isAxesVisible() const;
        float axesSize() const;

        bool isAxesOverlayVisible() const;
        bool isDebugOverlayVisible() const;

        molekulo::Viewer::View view() const;

        molekulo::Viewer::LabelsOnAtoms labelsOnAtoms() const;
        const QFont& labelsOnAtomsFont() const;
        
        molekulo::Viewer::LabelsOnBonds labelsOnBonds() const;
        const QFont& labelsOnBondsFont() const;
        
        QString atomSymbol() const;

        bool isSomethingUnderPixel(const QPoint& pixel);

        Eigen::Vector3f cameraPosition() const;
        Eigen::Vector3f cameraViewDirection() const;
        Eigen::Vector3f project(const Eigen::Vector3f& v) const;

        Projection projection() const;

        int quality() const;

        /**
         * Read the settings of the GLWidget and restore them.
         */
        virtual void readSettings(QSettings& settings);

    public slots:
        void setAxesVisible(bool visible);
        void setAxesSize(double size);

        void setAxesOverlayVisible(bool visible);
        void setDebugOverlayVisible(bool visible);
        
        void setView(int view);
        
        void setLabelsOnAtoms(int labelsOnAtoms);
        void setLabelsOnAtomsFont(const QFont& font);

        void setLabelsOnBonds(int labelsOnBonds);
        void setLabelsOnBondsFont(const QFont& font);

        void setAtomSymbol(const QString& atomSymbol);
        void setQuality(int quality);
        void setProjection(int projection);

    protected:
        virtual void init();
        virtual void draw();
        virtual void fastDraw();
        virtual void drawWithNames();

        virtual void mouseMoveEvent(QMouseEvent* e);
        virtual void mousePressEvent(QMouseEvent* e);
        virtual void mouseReleaseEvent(QMouseEvent* e);

    private:
        struct ViewerPrivate;
        std::unique_ptr<ViewerPrivate> p;

        std::unique_ptr<ccio::molecule_file> chemFile_;
        molekulo::Viewer::View view_;

        // added atom atomic number
        quint8 atomicNumber_;
        qint32 atomSelectedBeforeIndex_;

        molekulo::Viewer::LabelsOnAtoms labelsOnAtoms_;
        molekulo::Viewer::LabelsOnBonds labelsOnBonds_;

        GLfloat atomDrawRadius(const ccio::atom& atom) const;
        molekulo::Color atomColor(const ccio::atom& atom) const;
        void drawAtom(const ccio::atom& atom, bool fast) const;

        void drawBond(const ccio::bond& bond, bool fast) const;

        void drawMolecule(bool fast) const;
        void drawMoleculeWithNames() const;

        void drawAxes() const;
        void drawDebugInfo();
        void drawAxesOverlay();

        void mouseLeftButtonPressEvent(QMouseEvent* e);
        void mouseLeftButtonWithNoModifierPressEvent(QMouseEvent* e);
        void mouseLeftButtonWithShiftPressEvent(QMouseEvent* e);
        void mouseLeftButtonWithCtrlPressEvent(QMouseEvent* e);

        void mouseRightButtonPressEvent(QMouseEvent* e);
        void mouseRightButtonWithNoModifierPressEvent(QMouseEvent* e);
        void mouseRightButtonWithCtrlPressEvent(QMouseEvent* e);

        void mouseLeftButtonReleaseEvent(QMouseEvent* e);
        void mouseLeftButtonWithCtrlReleaseEvent(QMouseEvent* e);

        // Avogadro
        Eigen::Vector3f transformedXAxis() const;
        Eigen::Vector3f transformedYAxis() const;
        Eigen::Vector3f transformedZAxis() const;
        Eigen::Vector3f backTransformedXAxis() const;
        Eigen::Vector3f backTransformedYAxis() const;
        Eigen::Vector3f backTransformedZAxis() const;
    };
}

#endif // VIEWER_H
