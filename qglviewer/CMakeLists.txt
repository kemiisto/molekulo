cmake_minimum_required(VERSION 3.0f)

project(qglviewer_project)

set(Qt5_DIR /usr/local/opt/qt@5/lib/cmake/Qt5)
find_package(Qt5 REQUIRED COMPONENTS Core Gui OpenGL Xml)
if(Qt5_FOUND)
    set(HAVE_QT5 ON)
endif()

find_package(OpenGL REQUIRED)

include_directories("include")

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-gnu-anonymous-struct -Wno-nested-anon-types -Wno-deprecated-declarations -Wno-unused-but-set-variable")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-gnu-anonymous-struct -Wno-nested-anon-types -Wno-deprecated-declarations")
endif()

set(VIEWER_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/qglviewer)
add_subdirectory(src)