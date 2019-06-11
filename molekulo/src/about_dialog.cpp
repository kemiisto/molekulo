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

#include "about_dialog.h"
#include "ui_about_dialog.h"

#include <boost/version.hpp>
#include <Eigen/Core>
#include <Eigen/src/Core/util/Macros.h>

// From Qt Creator
static QString compilerString()
{
#if defined(Q_CC_CLANG) // must be before GNU, because clang claims to be GNU too
    QString isAppleString;
#if defined(__apple_build_version__) // Apple clang has other version numbers
    isAppleString = QLatin1String(" (Apple)");
#endif
    return QLatin1String("Clang " ) + QString::number(__clang_major__) + QLatin1Char('.')
            + QString::number(__clang_minor__) + isAppleString;
#elif defined(Q_CC_GNU)
    return QLatin1String("GCC " ) + QLatin1String(__VERSION__);
#elif defined(Q_CC_MSVC)
    if (_MSC_VER >= 1800) // 1800: MSVC 2013 (yearly release cycle)
        return QLatin1String("MSVC ") + QString::number(2008 + ((_MSC_VER / 100) - 13));
    if (_MSC_VER >= 1500) // 1500: MSVC 2008, 1600: MSVC 2010, ... (2-year release cycle)
        return QLatin1String("MSVC ") + QString::number(2008 + 2 * ((_MSC_VER / 100) - 15));
#endif
    return QLatin1String("<unknown compiler>");
}

static QString qtString()
{
    return QString("<p>Qt %1<br><a href=\"http://www.qt.io\">http://www.qt.io</a></p>").arg(
        QLatin1String(qVersion())
    );
}

static QString boostString()
{
    int boostMajorVersion = BOOST_VERSION / 100000;
    int boostMinorVersion = BOOST_VERSION / 100 % 1000;
    int boostPatchLevel = BOOST_VERSION % 100;
    return QString("<p>Boost %1.%2.%3<br><a href=\"http://www.boost.org\">http://www.boost.org</a></p>").arg(
        boostMajorVersion
    ).arg(
        boostMinorVersion
    ).arg(
        boostPatchLevel
    );
}

static QString eigenString()
{
    return QString("<p>Eigen %1.%2.%3</p>").arg(
        EIGEN_WORLD_VERSION
    ).arg(
        EIGEN_MAJOR_VERSION
    ).arg(
        EIGEN_MINOR_VERSION
    );
}

struct molekulo::AboutDialog::AboutDialogPrivate
{
    Ui::AboutDialog ui;

    AboutDialogPrivate() : 
        ui()
    {}
};

molekulo::AboutDialog::AboutDialog(QWidget* parent) :
    QDialog(parent),
    p(new AboutDialogPrivate)
{
    p->ui.setupUi(this);

    QString basedOnString = qtString() + boostString() + eigenString();

    // basedOnString += 
    //     "With portions of code from the <a href=\"http://avogadro.cc\">Avogadro</a> project.";

    p->ui.textBrowserBasedOn->setHtml(basedOnString);
    p->ui.compilerLabel->setText(compilerString());
}

molekulo::AboutDialog::~AboutDialog()
{
}

void molekulo::AboutDialog::setHeaderLabelText(const QString& text)
{
    p->ui.labelHeader->setText(text);
}
