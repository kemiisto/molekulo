cmake_minimum_required(VERSION 3.0f)

project(qglviewer_project)

find_package(Qt5Core REQUIRED)
if(Qt5Core_FOUND)
    set(HAVE_QT5 ON)
    find_package(Qt5Gui REQUIRED)
    find_package(Qt5OpenGL REQUIRED)
    find_package(Qt5Xml REQUIRED)
endif()

find_package(OpenGL REQUIRED)

include_directories("include")

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-gnu-anonymous-struct -Wno-nested-anon-types -Wno-deprecated-declarations")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-gnu-anonymous-struct -Wno-nested-anon-types -Wno-deprecated-declarations")
endif()

set(VIEWER_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/qglviewer)
add_subdirectory(src)