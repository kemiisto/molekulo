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

#include <cmath>

#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>

#include "chem/element.h"
#include "render/painter.h"
#include "render/sphere.h"
#include "render/viewer.h"
#include "qglviewer/manipulatedCameraFrame.h"

//#include <GL/glext.h>

// #ifndef GL_COLOR_SUM_EXT
// #define GL_COLOR_SUM_EXT 0x8458
// #endif

// #ifndef GL_LIGHT_MODEL_COLOR_CONTROL_EXT
// #define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
// #endif

// #ifndef GL_SEPARATE_SPECULAR_COLOR_EXT
// #define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA
// #endif

// #ifndef GL_MULTISAMPLE
// #define GL_MULTISAMPLE  0x809D
// #endif

const std::map<molekulo::Viewer::View, std::string> molekulo::Viewer::viewToDescription = {
    { molekulo::Viewer::ViewBallsAndBonds,  "Balls & Bonds"  },
    { molekulo::Viewer::ViewBallsAndSticks, "Balls & Sticks" },
    { molekulo::Viewer::ViewSticks,         "Sticks"         },
    { molekulo::Viewer::ViewVdWBalls,       "VdW Balls"      }
};

const std::map<molekulo::Viewer::LabelsOnAtoms, std::string> molekulo::Viewer::labelsOnAtomsToDescription = {
    { molekulo::Viewer::LabelsOnAtomsNone,   "None"   },
    { molekulo::Viewer::LabelsOnAtomsSymbol, "Symbol" },
    { molekulo::Viewer::LabelsOnAtomsIndex,  "Index"  }
};

const std::map<molekulo::Viewer::LabelsOnBonds, std::string> molekulo::Viewer::labelsOnBondsToDescription = {
    { molekulo::Viewer::LabelsOnBondsNone,   "None"   },
    { molekulo::Viewer::LabelsOnBondsLength, "Length" }
};

const std::map<molekulo::Viewer::Projection, std::string> molekulo::Viewer::projectionToDescription = {
    { molekulo::Viewer::ProjectionPerspective,  "Perspective" },
    { molekulo::Viewer::ProjectionOrthographic, "Orthographic" }
};

struct molekulo::Viewer::ViewerPrivate
{
    ViewerPrivate(molekulo::Viewer& viewer) : 
        painter(viewer),
        backgroundColor(Qt::black),
        isAxesVisible(false),
        axesSize(1.0f),
        isAxesOverlayVisible(true),
        isDebugOverlayVisible(false),
        labelsOnAtomsFont(),
        labelsOnBondsFont()
    {}

    molekulo::Painter painter;

    QColor backgroundColor;

    bool isAxesVisible;
    float axesSize;

    bool isAxesOverlayVisible;
    bool isDebugOverlayVisible;

    QFont labelsOnAtomsFont;
    QFont labelsOnBondsFont;
};

molekulo::Viewer::Viewer(std::unique_ptr<ccio::molecule_file> chemFile) :
    QGLViewer(),
    p(new ViewerPrivate(*this)),
    chemFile_(std::move(chemFile)),
    view_(molekulo::Viewer::ViewBallsAndBonds),
    atomicNumber_(6),
    atomSelectedBeforeIndex_(-1),
    labelsOnAtoms_(molekulo::Viewer::LabelsOnAtomsNone),
    labelsOnBonds_(molekulo::Viewer::LabelsOnBondsNone)
{
//    setBackgroundColor(p->backgroundColor);
    setMouseBinding(Qt::ControlModifier, Qt::LeftButton, FRAME, TRANSLATE);
    camera()->frame()->setSpinningSensitivity(100.0f);
}

molekulo::Viewer::~Viewer()
{
    makeCurrent();
}

const std::unique_ptr<ccio::molecule_file>& molekulo::Viewer::chemFile() const
{
    return chemFile_;
}

void molekulo::Viewer::draw()
{
    if (p->isAxesVisible) {
        drawAxes();
    }

    drawMolecule(false);

    if (labelsOnAtoms() != molekulo::Viewer::LabelsOnAtomsNone) {
        for (std::size_t i = 0; i < chemFile_->molecule().number_of_atoms(); ++i) {
            const ccio::atom& atom = chemFile_->molecule().atom(i);

            float radius = 0.0f;
            switch (view_)
            {
            case molekulo::Viewer::ViewBallsAndSticks:
            case molekulo::Viewer::ViewBallsAndBonds:
                radius = atomDrawRadius(atom);
                break;
            case molekulo::Viewer::ViewSticks:
                radius = molekulo::stickThikness;
                break;
            case molekulo::Viewer::ViewVdWBalls:
                radius = atom.element().van_der_waals_radius();
                break;
            }

            Eigen::Vector3f v = atom.centre().cast<float>();
            Eigen::Vector3f directionToCamera = (cameraPosition() - v).normalized();
            v += directionToCamera * (radius + 0.05f);
            // v += camera()->transformedZAxis() * (radius + 0.05f);

            QString text;

            switch (labelsOnAtoms())
            {
            case molekulo::Viewer::LabelsOnAtomsNone:
                break;
            case molekulo::Viewer::LabelsOnAtomsSymbol:
                text = QString::fromStdString(atom.element().symbol());
                break;
            case molekulo::Viewer::LabelsOnAtomsIndex:
                text = QString::number(i + 1);
                break;
            }

            p->painter.drawText(v, text);
        }
    }

    if (labelsOnBonds() != molekulo::Viewer::LabelsOnBondsNone)
    {
        GLfloat color[4];
        glGetFloatv(GL_CURRENT_COLOR, color);
        glColor3f(0.0f, 0.0f, 0.0f);

        for (std::size_t i = 0; i < chemFile_->molecule().number_of_bonds(); ++i)
        {
            const ccio::bond& bond = chemFile_->molecule().bond(i);
            Eigen::Vector3f v = bond.centre().cast<float>() - cameraPosition();
            v = v * (v.norm() - 1.0f) / v.norm();
            v = v + cameraPosition();

            QString text;

            switch (labelsOnBonds())
            {
            case molekulo::Viewer::LabelsOnBondsNone:
                break;
            case molekulo::Viewer::LabelsOnBondsLength:
                text = QString::number(bond.length(), 'g', 3);
                break;
            }

            renderText(v.x(), v.y(), v.z(), text, labelsOnBondsFont());
        }

        glColor4fv(color);
    }

    if (p->isAxesOverlayVisible) {
        drawAxesOverlay();
    }

    if (p->isDebugOverlayVisible) {
        drawDebugInfo();
    }
}

void molekulo::Viewer::fastDraw()
{
    if (p->isAxesVisible) {
        drawAxes();
    }

    drawMolecule(true);

    if (p->isAxesOverlayVisible) {
        drawAxesOverlay();
    }

    if (p->isDebugOverlayVisible) {
        drawDebugInfo();
    }
}

void molekulo::Viewer::drawWithNames()
{
    drawMoleculeWithNames();
}

void molekulo::Viewer::init()
{
    const float LIGHT_AMBIENT[4] = {0.2f, 0.2f, 0.2f, 1.0f};

    const float LIGHT0_DIFFUSE[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    const float LIGHT0_SPECULAR[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    const float LIGHT0_POSITION[4] = {0.8f, 0.7f, 1.0f, 0.0f};

    const float LIGHT1_DIFFUSE[4] = {0.3f, 0.3f, 0.3f, 1.0f};
    const float LIGHT1_SPECULAR[4] = {0.5f, 0.5f, 0.5f, 1.0f};
    const float LIGHT1_POSITION[4] = {-0.8f, 0.7f, -0.5f, 0.0f};

    glEnable(GL_MULTISAMPLE);
    GLint bufs;
    GLint samples;
    glGetIntegerv(GL_SAMPLE_BUFFERS, &bufs);
    glGetIntegerv(GL_SAMPLES, &samples);
    qDebug("Have %d buffers and %d samples", bufs, samples);

    // This method is called from QGLViewer::initializeGL(),
    // where GL_COLOR_MATERIAL is enabled. We don't need it!
    glDisable(GL_COLOR_MATERIAL);

    // glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    // As mentioned in QGLViewer documentation for select() method,
    // one can encounter problems with backface culling.
    // If so one can try to use glDisable(GL_CULL_FACE).
    glDisable(GL_CULL_FACE);
    glEnable(GL_COLOR_SUM_EXT);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_NORMALIZE);

    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL_EXT, GL_SEPARATE_SPECULAR_COLOR_EXT );

    //  glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL_EXT,
    //                 GL_SEPARATE_SPECULAR_COLOR_EXT );

    // Due to the bug found with Mesa 6.5.3 in the Radeon DRI driver
    // in radeon_state.c in radeonUpdateSpecular(),
    // it is important to set GL_SEPARATE_SPECULAR_COLOR_EXT
    // _before_ enabling lighting
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, LIGHT_AMBIENT);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LIGHT0_DIFFUSE);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LIGHT0_SPECULAR);
    glLightfv(GL_LIGHT0, GL_POSITION, LIGHT0_POSITION);
    glEnable(GL_LIGHT0);

    // Create a second light source to illuminate shadows a little better
    glLightfv(GL_LIGHT1, GL_AMBIENT, LIGHT_AMBIENT);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LIGHT1_DIFFUSE);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LIGHT1_SPECULAR);
    glLightfv(GL_LIGHT1, GL_POSITION, LIGHT1_POSITION);
    glEnable(GL_LIGHT1);

    setManipulatedFrame(new qglviewer::ManipulatedFrame());

    setSceneRadius(chemFile_->molecule().radius() + 1.0f);
    showEntireScene();
}

void molekulo::Viewer::drawAxes() const
{
    const float axes_radius = 0.05f;

    p->painter.setDynamicScaling(false);

    p->painter.setColor(molekulo::Color::red());
    p->painter.drawArrow(
        Eigen::Vector3f(0.0f, 0.0f, 0.0f),
        Eigen::Vector3f(p->axesSize, 0.0f, 0.0f),
        axes_radius
    );

    p->painter.setColor(molekulo::Color::green());
    p->painter.drawArrow(
        Eigen::Vector3f(0.0f, 0.0f, 0.0f),
        Eigen::Vector3f(0.0f, p->axesSize, 0.0f),
        axes_radius
    );

    p->painter.setColor(molekulo::Color::blue());
    p->painter.drawArrow(
        Eigen::Vector3f(0.0f, 0.0f, 0.0f),
        Eigen::Vector3f(0.0f, 0.0f, p->axesSize),
        axes_radius
    );

    p->painter.setDynamicScaling(true);
}

void molekulo::Viewer::drawAxesOverlay()
{
    // Render x, y, z axes as an overlay on the widget
    // Save the opengl projection matrix and set up an orthogonal projection
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    // Ensure the axes are of the same length
    float aspectRatio = static_cast<float>(width())/static_cast<float>(height());
    glOrtho(0, aspectRatio, 0, 1, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Set the origin and calculate the positions of the axes
    Eigen::Vector3f origin = Eigen::Vector3f(0.07f, 0.07f, -0.07f);
    Eigen::Vector3f aXa = transformedXAxis() * 0.04f + origin;
    Eigen::Vector3f aX  = transformedXAxis() * 0.06f + origin;
    Eigen::Vector3f aYa = transformedYAxis() * 0.04f + origin;
    Eigen::Vector3f aY  = transformedYAxis() * 0.06f + origin;
    Eigen::Vector3f aZa = transformedZAxis() * 0.04f + origin;
    Eigen::Vector3f aZ  = transformedZAxis() * 0.06f + origin;

    // Turn off dynamic scaling in the painter (cylinders don't render correctly)
    p->painter.setDynamicScaling(false);

    // Circle next to the axes
    p->painter.setColor(molekulo::Color::red());
    p->painter.drawSphere(origin, 0.005);
    // x axis
    p->painter.setColor(molekulo::Color::red());
    p->painter.drawCylinder(origin, aXa, 0.005);
    p->painter.drawCone(aXa, aX, 0.01);
    // y axis
    p->painter.setColor(molekulo::Color::green());
    p->painter.drawCylinder(origin, aYa, 0.005);
    p->painter.drawCone(aYa, aY, 0.01);
    // y axis
    p->painter.setColor(molekulo::Color::blue());
    p->painter.drawCylinder(origin, aZa, 0.005);
    p->painter.drawCone(aZa, aZ, 0.01);

    // Turn dynamic scaling back on (default state)
    p->painter.setDynamicScaling(true);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void molekulo::Viewer::drawDebugInfo()
{
    GLfloat color[4];

    glGetFloatv(GL_CURRENT_COLOR, color);

    glColor3f(0.0f, 1.0f, 0.0f);

    QFont font;

    font.setBold(true);
    renderText(10, 15, "Debug Info", font);
    font.setBold(false);

    renderText(20, 30, QString("Distance: %1").arg(sceneRadius()), font);
    // renderText(20, 45,
    //            QString("Molecule: %1 (%2 atoms)").arg(chemFile_->molecule().formula(),
    //                                                   QString::number(chemFile_->molecule().number_of_atoms())),
    //            font);
    renderText(20, 60, QString("View direction: %1 %2 %3").arg(
                   camera()->viewDirection().x).arg(
                   camera()->viewDirection().y).arg(
                   camera()->viewDirection().z), font);
    renderText(20, 75, QString("Camera position: %1 %2 %3").arg(
                   cameraPosition().x()).arg(
                   cameraPosition().y()).arg(
                   cameraPosition().z()), font);
    // renderText(20, 90, QString("Centre of mass: %1 %2 %3").arg(
    //                chemFile_->molecule().centreOfMass().x()).arg(
    //                chemFile_->molecule().centreOfMass().y()).arg(
    //                chemFile_->molecule().centreOfMass().z()), font);

    glColor4fv(color);
}

molekulo::Viewer::View molekulo::Viewer::view() const
{
    return view_;
}

molekulo::Viewer::LabelsOnAtoms molekulo::Viewer::labelsOnAtoms() const
{
    return labelsOnAtoms_;
}

void molekulo::Viewer::setLabelsOnAtoms(int labelsOnAtoms)
{
    labelsOnAtoms_ = (molekulo::Viewer::LabelsOnAtoms)labelsOnAtoms;
    update();
}

const QFont& molekulo::Viewer::labelsOnAtomsFont() const
{
    return p->labelsOnAtomsFont;
}

void molekulo::Viewer::setLabelsOnAtomsFont(const QFont& font)
{
    p->labelsOnAtomsFont = font;
    update();
}

molekulo::Viewer::LabelsOnBonds molekulo::Viewer::labelsOnBonds() const
{
    return labelsOnBonds_;
}

void molekulo::Viewer::setLabelsOnBonds(int labelsOnBonds)
{
    labelsOnBonds_ = (molekulo::Viewer::LabelsOnBonds)labelsOnBonds;
    update();
}

const QFont& molekulo::Viewer::labelsOnBondsFont() const
{
    return p->labelsOnBondsFont;
}

void molekulo::Viewer::setLabelsOnBondsFont(const QFont& font)
{
    p->labelsOnBondsFont = font;
    update();
}

void molekulo::Viewer::setView(int view)
{
    view_ = (molekulo::Viewer::View)view;
    update();
}

bool molekulo::Viewer::isAxesVisible() const
{
    return p->isAxesVisible;
}

void molekulo::Viewer::setAxesVisible(bool visible)
{
    p->isAxesVisible = visible;
    update();
}

float molekulo::Viewer::axesSize() const
{
    return p->axesSize;
}

void molekulo::Viewer::setAxesSize(double size)
{
    p->axesSize = size;
    update();
}

bool molekulo::Viewer::isAxesOverlayVisible() const
{
    return p->isAxesOverlayVisible;
}

void molekulo::Viewer::setAxesOverlayVisible(bool visible)
{
    p->isAxesOverlayVisible = visible;
    update();
}

bool molekulo::Viewer::isDebugOverlayVisible() const
{
    return p->isDebugOverlayVisible;
}

void molekulo::Viewer::setDebugOverlayVisible(bool visible)
{
    p->isDebugOverlayVisible = visible;
    update();
}

void molekulo::Viewer::setAtomSymbol(const QString& atomSymbol)
{
    (void)atomSymbol;
    // QByteArray byteArray = atomSymbol.toLatin1();
    // const char* s_char = byteArray.data();
    // atomicNumber_ = OpenBabel::etab.GetAtomicNum(s_char);
}

QString molekulo::Viewer::atomSymbol() const
{
    return QString();
    // return QString(OpenBabel::etab.GetSymbol(atomicNumber_));
}

//void molekulo::Viewer::displayConformer(quint16 index)
//{
//  chemFile_->molecule().setConformer(index);
//}

bool molekulo::Viewer::isSomethingUnderPixel(const QPoint& pixel)
{
    bool found;

    beginSelection(pixel);
    drawWithNames();
    endSelection(pixel);

    // Find the selectedPoint coordinates, using camera()->pointUnderPixel().
    camera()->pointUnderPixel(pixel, found);

    return found;
}

GLfloat molekulo::Viewer::atomDrawRadius(const ccio::atom& atom) const
{
    // FIX! isotope().exact_mass()!
#ifdef Q_CC_MSVC
    return pow(atom.element().atomicWeight(), 1.0f / 3.0f) / 10.0f + 0.2f;
#else
    return cbrt(atom.element().atomic_weight()) / 10.0f + 0.2f;
#endif
}

molekulo::Color molekulo::Viewer::atomColor(const ccio::atom& atom) const
{
    const std::vector<unsigned char>& c = atom.element().rgb();
    return molekulo::Color(c[0]/255.0f, c[1]/255.0f, c[2]/255.0f, 1.0f);
}

void molekulo::Viewer::drawAtom(const ccio::atom& atom, bool fast) const
{
    molekulo::Color color = atomColor(atom);
    if (atom.is_selected()) {
        color = molekulo::Color::selection();
    }
    p->painter.setColor(color);

    double radius = 0.0;
    switch (view_)
    {
    case molekulo::Viewer::ViewBallsAndSticks:
    case molekulo::Viewer::ViewBallsAndBonds:
        radius = atomDrawRadius(atom);
        break;
    case molekulo::Viewer::ViewSticks:
        radius = molekulo::stickThikness;
        break;
    case molekulo::Viewer::ViewVdWBalls:
        radius = atom.element().van_der_waals_radius();
        break;
    }

    if (fast) {
        p->painter.drawSphere(atom.centre().cast<float>(), radius);
    } else {
        p->painter.drawSphere(atom.centre().cast<float>(), radius);
    }
}

void molekulo::Viewer::drawBond(const ccio::bond& bond, bool fast) const
{
    float shift;

    if (bond.bond_order() < 3)
        shift = 0.125f;
    else
        shift = 0.2f;

    // Compute the centre of bond
    Eigen::Vector3f vec1 = bond.end_atom().centre().cast<float>() - bond.begin_atom().centre().cast<float>();
    vec1 = vec1 * (vec1.norm() - atomDrawRadius(bond.end_atom())) / vec1.norm();
    vec1 = vec1 + bond.begin_atom().centre().cast<float>();
    Eigen::Vector3f vec2 = bond.begin_atom().centre().cast<float>() - bond.end_atom().centre().cast<float>();
    vec2 = vec2 * (vec2.norm() - atomDrawRadius(bond.begin_atom())) / vec2.norm();
    vec2 = vec2 + bond.end_atom().centre().cast<float>();
    Eigen::Vector3f vMiddle = (vec1 + vec2) / 2;

    float radius = 0.0f;
    switch (view_) {
    case molekulo::Viewer::ViewBallsAndBonds:
        radius = molekulo::bondThikness;
        break;
    case molekulo::Viewer::ViewBallsAndSticks:
    case molekulo::Viewer::ViewSticks:
        radius = molekulo::stickThikness;
        break;
    case molekulo::Viewer::ViewVdWBalls:
        break;
    }

    molekulo::Color color1 = atomColor(bond.begin_atom());
    molekulo::Color color2 = atomColor(bond.end_atom());
    //  if (bond.is_selected()) {
    //    material1 = molekulo::Material::selection();
    //    material2 = molekulo::Material::selection();
    //  }

    switch (view_)
    {
    case molekulo::Viewer::ViewBallsAndBonds:
        if (fast) {
            p->painter.setColor(color1);
            p->painter.drawMultiCylinder(bond.begin_atom().centre().cast<float>(), vMiddle, radius,
                    bond.bond_order(), shift, chemFile_->molecule().plane_normal_vector().cast<float>());
            p->painter.setColor(color2);
            p->painter.drawMultiCylinder(vMiddle, bond.end_atom().centre().cast<float>(), radius,
                    bond.bond_order(), shift, chemFile_->molecule().plane_normal_vector().cast<float>());
            //
        } else {
            p->painter.setColor(color1);
            p->painter.drawMultiCylinder(bond.begin_atom().centre().cast<float>(), vMiddle, radius,
                    bond.bond_order(), shift, chemFile_->molecule().plane_normal_vector().cast<float>());
            p->painter.setColor(color2);
            p->painter.drawMultiCylinder(vMiddle, bond.end_atom().centre().cast<float>(), radius,
                    bond.bond_order(), shift, chemFile_->molecule().plane_normal_vector().cast<float>());
        }
        break;
    case molekulo::Viewer::ViewBallsAndSticks:
    case molekulo::Viewer::ViewSticks:
        if (fast) {
            p->painter.setColor(color1);
            p->painter.drawCylinder(bond.begin_atom().centre().cast<float>(), vMiddle, radius);
            p->painter.setColor(color2);
            p->painter.drawCylinder(vMiddle, bond.end_atom().centre().cast<float>(), radius);
        } else {
            p->painter.setColor(color1);
            p->painter.drawCylinder(bond.begin_atom().centre().cast<float>(), vMiddle, radius);
            p->painter.setColor(color2);
            p->painter.drawCylinder(vMiddle, bond.end_atom().centre().cast<float>(), radius);
        }
        break;
    case molekulo::Viewer::ViewVdWBalls:
        break;
    }
}

void molekulo::Viewer::drawMolecule(bool fast) const
{
    for (std::size_t i = 0; i < chemFile_->molecule().number_of_atoms(); ++i) {
        drawAtom(chemFile_->molecule().atom(i), fast);
    }

    if (view_ != molekulo::Viewer::ViewVdWBalls) {
        for (std::size_t i = 0; i < chemFile_->molecule().number_of_bonds(); ++i) {
            drawBond(chemFile_->molecule().bond(i), fast);
        }
    }
}

void molekulo::Viewer::drawMoleculeWithNames() const
{
    int n = 0;

    glInitNames();

    for (std::size_t i = 0; i < chemFile_->molecule().number_of_atoms(); ++i)
    {
        glPushName(n);
        {
            drawAtom(chemFile_->molecule().atom(i), false);
        }
        glPopName();
        n++;
    }

    if (view_ != molekulo::Viewer::ViewVdWBalls)
        for (std::size_t i = 0; i < chemFile_->molecule().number_of_bonds(); ++i)
        {
            glPushName(n);
            {
                drawBond(chemFile_->molecule().bond(i),
                         false);
            }
            glPopName();
            n++;
        }
}

Eigen::Vector3f molekulo::Viewer::cameraPosition() const
{
    return Eigen::Vector3f(camera()->position().x,
                           camera()->position().y,
                           camera()->position().z);
}

Eigen::Vector3f molekulo::Viewer::cameraViewDirection() const
{
    return Eigen::Vector3f(camera()->viewDirection().x,
                           camera()->viewDirection().y,
                           camera()->viewDirection().z);
}

Eigen::Vector3f molekulo::Viewer::project(const Eigen::Vector3f& v) const
{
    qglviewer::Vec vec = camera()->projectedCoordinatesOf(qglviewer::Vec(v.x(), v.y(), v.z()));
    return Eigen::Vector3f(vec.x, vec.y, vec.z);
}

void molekulo::Viewer::setProjection(int projection)
{
    if (projection == ProjectionPerspective) {
        camera()->setType(qglviewer::Camera::PERSPECTIVE);
    } else {
        camera()->setType(qglviewer::Camera::ORTHOGRAPHIC);
    }
    update();
}

molekulo::Viewer::Projection molekulo::Viewer::projection() const
{
    if (camera()->type() == qglviewer::Camera::PERSPECTIVE) {
        return ProjectionPerspective;
    } else {
        return ProjectionOrthographic;
    }
}

void molekulo::Viewer::setQuality(int quality)
{
    p->painter.setQuality(quality);
    update();
}

int molekulo::Viewer::quality() const
{
    return p->painter.quality();
}

void molekulo::Viewer::readSettings(QSettings& settings)
{
    setQuality(settings.value("quality", 2).toInt());
}

void molekulo::Viewer::mouseMoveEvent(QMouseEvent* e)
{
    switch (e->buttons())
    {
    case Qt::LeftButton:
        QGLViewer::mouseMoveEvent(e);
        break;
    case Qt::RightButton:
        //    if (e->modifiers() == (Qt::NoModifier | Qt::MetaModifier))
        //    {
        QGLViewer::mouseMoveEvent(e);
        //    }
        break;
    default:
        break;
    }
}

void molekulo::Viewer::mousePressEvent(QMouseEvent* e)
{
    switch (e->button())
    {
    case Qt::LeftButton:
        mouseLeftButtonPressEvent(e);
        break;
    case Qt::RightButton:
        mouseRightButtonPressEvent(e);
        break;
    default:
        break;
    }
}

void molekulo::Viewer::mouseReleaseEvent(QMouseEvent* e)
{
    switch (e->button())
    {
    case (Qt::LeftButton):
        mouseLeftButtonReleaseEvent(e);
        break;
    default:
        break;
    }
    QGLViewer::mouseReleaseEvent(e);
}

void molekulo::Viewer::mouseLeftButtonPressEvent(QMouseEvent* e)
{
    switch (e->modifiers())
    {
    case Qt::NoModifier:
        mouseLeftButtonWithNoModifierPressEvent(e);
        QGLViewer::mousePressEvent(e);
        break;
    case Qt::ShiftModifier:
        mouseLeftButtonWithShiftPressEvent(e);
        break;
    case Qt::ControlModifier:
        mouseLeftButtonWithCtrlPressEvent(e);
        QGLViewer::mousePressEvent(e);
        break;
    default:
        break;
    }
}

void molekulo::Viewer::mouseLeftButtonWithNoModifierPressEvent(QMouseEvent* e)
{
    if (isSomethingUnderPixel(e->pos()) &&
            selectedName() < static_cast<int>(chemFile_->molecule().number_of_atoms()))
    {
        camera()->setRevolveAroundPoint(
            qglviewer::Vec(
                chemFile_->molecule().atom(selectedName()).centre().x(),
                chemFile_->molecule().atom(selectedName()).centre().y(),
                chemFile_->molecule().atom(selectedName()).centre().z()));
    }
    else
    {
        camera()->setRevolveAroundPoint(qglviewer::Vec(0.0f, 0.0f, 0.0f));
    }
}

void molekulo::Viewer::mouseLeftButtonWithShiftPressEvent(QMouseEvent* e)
{
    if (isSomethingUnderPixel(e->pos()))
    {
        if (selectedName() < static_cast<int>(chemFile_->molecule().number_of_atoms()))
            chemFile_->molecule().atom(selectedName()).toggle_selection();
        else
            chemFile_->molecule().bond(
                selectedName() -
                chemFile_->molecule().number_of_atoms()).toggle_selection();
    }
}

void molekulo::Viewer::mouseLeftButtonWithCtrlPressEvent(QMouseEvent* e)
{
    if (isSomethingUnderPixel(e->pos()))
    {
        if (selectedName() < static_cast<int>(chemFile_->molecule().number_of_atoms()))
            atomSelectedBeforeIndex_ = selectedName();
        else
            chemFile_->molecule().bond(
                selectedName() - chemFile_->molecule().number_of_atoms()
            ).cycle_bond_order();
    }
    else
    {
        atomSelectedBeforeIndex_ = -1;
        if (chemFile_->molecule().number_of_atoms() == 0)
            chemFile_->molecule().create_atom(atomicNumber_, Eigen::Vector3d(0.0, 0.0, 0.0));
    }
}

void molekulo::Viewer::mouseRightButtonPressEvent(QMouseEvent* e)
{
    switch (e->modifiers())
    {
    case (Qt::NoModifier):
        mouseRightButtonWithNoModifierPressEvent(e);
        break;
    case (Qt::ControlModifier):
        mouseRightButtonWithCtrlPressEvent(e);
        break;
    default:
        break;
    }
}

void molekulo::Viewer::mouseRightButtonWithNoModifierPressEvent(QMouseEvent* e)
{
    QGLViewer::mousePressEvent(e);
}

void molekulo::Viewer::mouseRightButtonWithCtrlPressEvent(QMouseEvent* e)
{
    if (isSomethingUnderPixel(e->pos())) {
        if (selectedName() < static_cast<int>(chemFile_->molecule().number_of_atoms())) {
            // chemFile_->molecule().remove_atom(selectedName());
        } else {
            // chemFile_->molecule().remove_bond(
            //     selectedName() - chemFile_->molecule().number_of_atoms()
            // );
        }
    }
}

void molekulo::Viewer::mouseLeftButtonReleaseEvent(QMouseEvent* e)
{
    switch (e->modifiers())
    {
    case Qt::NoModifier:
        for (std::size_t i = 0; i < chemFile_->molecule().number_of_bonds(); ++i)
            chemFile_->molecule().set_plane_normal_vector(
                Eigen::Vector3d(
                    camera()->position().x,
                    camera()->position().y,
                    camera()->position().z
                )
            );
        break;
    case Qt::ControlModifier:
        mouseLeftButtonWithCtrlReleaseEvent(e);
        break;
    }
}

void molekulo::Viewer::mouseLeftButtonWithCtrlReleaseEvent(QMouseEvent* e)
{
    if (rect().contains(e->pos()))
    {
        if (atomSelectedBeforeIndex_ != -1)
        {
            if (manipulatedFrame()->position() == qglviewer::Vec(0.0f, 0.0f, 0.0f))
            {
                // chemFile_->molecule().atom(atomSelectedBeforeIndex_).set_atomic_number(atomicNumber_);
            }
            else
            {
                if (!isSomethingUnderPixel(e->pos()))
                {
                    Eigen::Vector3d p(
                        chemFile_->molecule().atom(atomSelectedBeforeIndex_).centre().x() +
                        manipulatedFrame()->position().x,
                        chemFile_->molecule().atom(atomSelectedBeforeIndex_).centre().y() +
                        manipulatedFrame()->position().y,
                        chemFile_->molecule().atom(atomSelectedBeforeIndex_).centre().z() +
                        manipulatedFrame()->position().z);
                    chemFile_->molecule().create_atom(atomicNumber_, p);
                    chemFile_->molecule().create_bond(
                        atomSelectedBeforeIndex_,
                        chemFile_->molecule().number_of_atoms() - 1,
                        1);
                }
                else
                {
                    chemFile_->molecule().create_bond(atomSelectedBeforeIndex_, selectedName(), 1);
                }
            }
        }
    }

    if (atomSelectedBeforeIndex_ != -1) atomSelectedBeforeIndex_ = -1;

    manipulatedFrame()->setPosition(0.0f, 0.0f, 0.0f);
}

Eigen::Vector3f molekulo::Viewer::transformedXAxis() const
{
    qglviewer::Vec vec = camera()->frame()->transformOf(qglviewer::Vec(1.0f, 0.0f, 0.0f));
    return Eigen::Vector3f(vec.x, vec.y, vec.z);
}

Eigen::Vector3f molekulo::Viewer::transformedYAxis() const
{
    qglviewer::Vec vec = camera()->frame()->transformOf(qglviewer::Vec(0.0f, 1.0f, 0.0f));
    return Eigen::Vector3f(vec.x, vec.y, vec.z);
}

Eigen::Vector3f molekulo::Viewer::transformedZAxis() const
{
    qglviewer::Vec vec = camera()->frame()->transformOf(qglviewer::Vec(0.0f, 0.0f, 1.0f));
    return Eigen::Vector3f(vec.x, vec.y, vec.z);
}


Eigen::Vector3f molekulo::Viewer::backTransformedXAxis() const
{
    qglviewer::Vec vec = camera()->frame()->inverseTransformOf(qglviewer::Vec(1.0f, 0.0f, 0.0f));
    return Eigen::Vector3f(vec.x, vec.y, vec.z);
}

Eigen::Vector3f molekulo::Viewer::backTransformedYAxis() const
{
    qglviewer::Vec vec = camera()->frame()->inverseTransformOf(qglviewer::Vec(0.0f, 1.0f, 0.0f));
    return Eigen::Vector3f(vec.x, vec.y, vec.z);
}

Eigen::Vector3f molekulo::Viewer::backTransformedZAxis() const
{
    qglviewer::Vec vec = camera()->frame()->inverseTransformOf(qglviewer::Vec(0.0f, 0.0f, 1.0f));
    return Eigen::Vector3f(vec.x, vec.y, vec.z);  
}
