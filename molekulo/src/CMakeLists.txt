set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Eigen3 3.0.0)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

message(STATUS "Building with Qt5...")
foreach(dep Core Concurrent Gui Widgets 3DCore 3DExtras 3DRender 3DInput)
    add_definitions(${Qt5${dep}_DEFINITIONS})
    include_directories(${Qt5${dep}_INCLUDE_DIRS})
    list(APPEND QT_LIBRARIES ${Qt5${dep}_LIBRARIES})
endforeach()

add_definitions(-DQT3DEXTRAS_LIBRARY)

file(GLOB_RECURSE SOURCES *.cpp)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/log/logger.cpp)
file(GLOB_RECURSE RESOURCES *.qrc)

find_package(Boost REQUIRED COMPONENTS log log_setup thread filesystem system)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

add_executable(molekulo ${SOURCES} ${RESOURCES})
target_link_libraries(
    molekulo chem io formats
    ${Boost_LIBRARIES}
    ${QT_LIBRARIES}
)

# Currently disabled for debugging, otherwise boost::property_tree::write_xml fails.
#if(WIN32)
#    if(MSVC)
#        set_target_properties(molekulo PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
#    elseif(MINGW)
#        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
#    endif()
#endif()
