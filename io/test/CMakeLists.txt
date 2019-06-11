find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

file(GLOB SOURCES *.cpp)

add_executable(test_io ${SOURCES})
target_link_libraries(test_io io ${Boost_LIBRARIES})