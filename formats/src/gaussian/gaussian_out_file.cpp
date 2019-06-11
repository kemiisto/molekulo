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

#include <boost/algorithm/string.hpp>
#include <regex>

#include <iostream>
#include <boost/property_tree/xml_parser.hpp>

#include "formats/gaussian/gaussian_cartesian_orientation_reader.h"
#include "formats/gaussian/gaussian_job_sp_reader.h"
#include "formats/gaussian/gaussian_out_file.h"
#include "io/not_found_exception.h"
#include "io/wrong_format_exception.h"
#include "io/logger.h"

ccio::gaussian_out_file::gaussian_out_file(const std::string& absoluteFilePath) :
    ccio::out_file(absoluteFilePath)
{
    tree().put("Out.<xmlattr>.program", "Gaussian");
}

void ccio::gaussian_out_file::do_read()
{
    LOG(info) << " as Gaussian output..." << "\n";
    find_gaussian_version();
    find_jobs();
    boost::property_tree::xml_writer_settings<std::string> settings(' ', 4);
    boost::property_tree::write_xml(std::cout, tree(), settings);
}

void ccio::gaussian_out_file::load_job(int index)
{
    LOG(info) << "Loading job " << index;

    //    QList<ccio::GaussianJob::Orientation> orientations = jobs_.at(index)->availableOrientations_;
    //    if (orientations.contains(ccio::GaussianJob::OrientationInput)) {
    //        molecule = jobs_.at(index)->getInputOrientation();
    //    } else if (orientations.contains(ccio::GaussianJob::OrientationZMatrix)) {
    //        molecule = jobs_.at(index)->getzMatrixOrientation();
    //    } else if (orientations.contains(ccio::GaussianJob::OrientationStandard)) {
    //        molecule = jobs_.at(index)->getStandardOrientation();
    //    }
}

void ccio::gaussian_out_file::find_gaussian_version()
{
    std::regex regex("Gaussian (\\d{2}), Revision ([A-Z]\\.\\d{1,2})");
    std::smatch smatch;

    std::string line = stream.read_line();
    while (!stream.done() && !std::regex_search(line, smatch, regex)) {
        line = stream.read_line();
    }
    if (!stream.done()) {
        tree().put("Out.<xmlattr>.version", smatch[1].str() + " " + smatch[2].str());
        LOG(info) << "Gaussian version found at line " << stream.line_number();
        LOG(info) << program() << " " << version();
    } else {
        throw kemiisto::io::not_found_exception("Gaussian version");
    }
}

/**
 * Each job starts with the route section.
 * The route section starts with the number sign (#) and continues up to some line with few dashes (-).
 * Each job continues up to "Normal termination" if completed successfully, or up to the very end of the file otherwise.
 *
 * NOTE: here when searching for a job and then reading it, it is assumed that the previous job was read fully,
 * i.e. up to "Normal termination" or the very end of file.
 * This is required since the number sign (#) is also printed at the end of each job before "Normal termination",
 * and the procedure below would wrongly consider it as the start of another job.
 * So it is necessary to read each job fully.
 */
void ccio::gaussian_out_file::find_jobs()
{
    std::string line = stream.read_line();
    while (!stream.done()) {
        line = stream.read_line();
        while (!stream.done() && line.find("#") == std::string::npos) {
            line = stream.read_line();
        }
        if (!stream.done()) {
            LOG(info) << "Route section start found at line " << stream.line_number();
            std::string route;
            while (!stream.done() && line.find("---") == std::string::npos) {
                boost::algorithm::trim(line);
                route.append(line);
                line = stream.read_line();
            }
            if (!stream.done()) {
                LOG(info) << "Route section end found at line " << stream.line_number();
                LOG(info) << route;
                // The route section is found and we can create a specific job on the basis of its contents.
                LOG(info) << "Reading job...\n";
                boost::property_tree::ptree job_tree;
                read_job(this, route, job_tree);
                tree().add_child("Out.Job", job_tree);
            } else {
                LOG(error) << "Route section end not found.";
                throw kemiisto::io::not_found_exception("route section end");
            }
        }
    }
}

void ccio::gaussian_out_file::read_job(ccio::gaussian_out_file* out_file, 
        const std::string& route_section, boost::property_tree::ptree& job_tree)
{
    (void)out_file;

    // http://www.gaussian.com/g_tech/g_ur/m_jobtypes.htm
    std::string s = route_section;
    boost::algorithm::to_lower(s);

    ccio::gaussian_cartesian_orientation_reader coordinates_reader(stream, job_tree, molecule());
    coordinates_reader.read();

    if (s.find("opt") != std::string::npos) {
//        job = std::unique_ptr<ccio::GaussianJob>(new GaussianJobOpt(this, route_section));
    } else if (s.find("freq") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("irc") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("ircmax") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("scan") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("polar") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("admp") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("force") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("stable") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("volume") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("density=checkpoint") != std::string::npos && s.find("guess=only") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("guess=only") != std::string::npos) {
        // addParseError("Unsupported job type!");
    } else if (s.find("bomd") != std::string::npos) {
//        job = std::unique_ptr<ccio::GaussianJob>(new GaussianJobBomd(this, route_section));
    } else {
        ccio::gaussian_job_sp_reader reader(stream, job_tree, molecule(), route_section);
        reader.read();
    }

//    if (job) {
//        addJob(std::move(job));
//    }
}
