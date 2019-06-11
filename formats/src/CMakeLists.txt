set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(Eigen3 3.0.0)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

find_package(Boost REQUIRED COMPONENTS filesystem system)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

include_directories("../..")

file(GLOB_RECURSE SOURCES *.cpp ../include/formats/*.h)
set(SOURCES ${SOURCES} "../../utility.cpp")
add_library(formats SHARED ${SOURCES})

set_target_properties(formats PROPERTIES DEBUG_POSTFIX "d")
target_link_libraries(formats chem io ${Boost_LIBRARIES})