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

#include <QtGlobal>
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QDir>

#include <fstream>
#include <boost/filesystem.hpp>

#include "formats/dalton/dalton_dal_file.h"
#include "io/logger.h"

#include "dal_file_window.h"
#include "molecule_window.h"

boost::filesystem::path samplesDir()
{
    boost::filesystem::path samples(boost::filesystem::current_path());
    for (int i = 0; i < 3; ++i) {
        samples = samples.parent_path();
    }
    samples /= "samples";
    return samples;

}

void initLogger()
{
    boost::log::add_common_attributes();
    boost::log::add_file_log(
        boost::log::keywords::file_name = "debug.log",
        boost::log::keywords::format = "[%TimeStamp%]: %Message%"
    );
}

int main(int argc, char* argv[])
{
    initLogger();

    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("Molekulo");
    QCoreApplication::setApplicationVersion(APP_VERSION);

#ifdef Q_OS_MAC
    a.setAttribute(Qt::AA_DontShowIconsInMenus, true);
#endif

    LOG(info) << QCoreApplication::applicationName().toStdString() << " "
        << QCoreApplication::applicationVersion().toStdString() << " is starting...";

    LOG(info) << "Program started successfully.\n";

    QString filePath1 = QString::fromStdString(
        (samplesDir()/"gaussian"/"h2o"/"sp"/"hf_cart_p.out").string()
    );
    std::unique_ptr<ccio::text_file> textFile1 = ccio::text_file::new_instance(filePath1.toStdString());
    textFile1->read();
    ccio::molecule_file* p1 = dynamic_cast<ccio::molecule_file*>(textFile1.get());
    if (p1 != nullptr) {
        textFile1.release();
        std::unique_ptr<ccio::molecule_file> moleculeFile1(p1);
        molekulo::MoleculeWindow* window1 = new molekulo::MoleculeWindow(std::move(moleculeFile1));
        window1->show();
    }

    // QString filePath2 = QString::fromStdString(
    //     // (samplesDir()/"dalton"/"h2o"/"sp"/"hf.out").string()
    //     // (samplesDir()/"dalton"/"h2o"/"sp"/"hf_max_diis.out").string()
    //     (samplesDir()/"dalton"/"h2o"/"sp"/"b3lyp_nodiis_h2o.out").string()
    // );
    // std::unique_ptr<ccio::text_file> textFile2 = ccio::text_file::new_instance(filePath2.toStdString());
    // textFile2->read();
    // ccio::molecule_file* p2 = dynamic_cast<ccio::molecule_file*>(textFile2.get());
    // if (p2 != nullptr) {
    //     textFile2.release();
    //     std::unique_ptr<ccio::molecule_file> moleculeFile2(p2);
    //     molekulo::MoleculeWindow* window2 = new molekulo::MoleculeWindow(std::move(moleculeFile2));
    //     window2->show();
    // }

    return a.exec();
}
