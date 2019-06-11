set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(Eigen3 3.0.0)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

include_directories("../..")

file(GLOB SOURCES *.cpp)

add_executable(test_chem ${SOURCES})
target_link_libraries(test_chem chem ${Boost_LIBRARIES})
