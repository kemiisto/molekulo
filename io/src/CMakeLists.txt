find_package(Boost REQUIRED COMPONENTS log system)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

file(GLOB SOURCES *.cpp ../include/io/*.h)
add_library(io SHARED ${SOURCES})

set_target_properties(io PROPERTIES DEBUG_POSTFIX "d")
target_link_libraries(io ${Boost_LIBRARIES})