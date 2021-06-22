cmake_minimum_required(VERSION 3.0)

project(molekulo_project)

include_directories("../ccio/chem/include")
include_directories("../ccio/formats/include")
include_directories("../ccio/io/include")
include_directories("../qglviewer/include")

include_directories("src")

find_package(Qt5 REQUIRED COMPONENTS Core Concurrent Gui Widgets)

add_subdirectory(src)
# add_subdirectory(test)