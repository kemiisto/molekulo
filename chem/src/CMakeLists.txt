set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(Eigen3 3.0.0)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

find_package(Boost REQUIRED COMPONENTS graph)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

include_directories("../..")

file(GLOB SOURCES *.cpp ../include/chem/*.h)

add_library(chem SHARED ${SOURCES})
set_target_properties(chem PROPERTIES DEBUG_POSTFIX "d")
target_link_libraries(chem io)