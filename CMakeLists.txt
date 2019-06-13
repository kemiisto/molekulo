cmake_minimum_required(VERSION 3.0)

project(molekulo_project)

file(COPY chem/data DESTINATION bin)
file(COPY molekulo/fonts DESTINATION bin)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("chem/include")
include_directories("formats/include")
include_directories("io/include")

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(DEBUG_FLAGS -O0)
    set(RELEASE_FLAGS -O2)
    set(STANDARD_FLAGS -std=c++14 -pedantic)
    set(WARNING_FLAGS
        # Turn on all the warnings, then turn few off.
		-Wall -Wextra
        #-Weverything
        -Wno-c++98-compat
        -Wno-c++98-compat-pedantic
        -Wno-padded
        -Wno-weak-vtables
        -Wno-exit-time-destructors
        # Warns when a class member has an identical name as a constructor parameter.
        -Wno-shadow
        # Warns on BOOST_AUTO_TEST_CASE macro.
        -Wno-global-constructors
        # qglviewer/vec.h
        -Wno-gnu-anonymous-struct
        -Wno-nested-anon-types
        -Wfatal-errors
        -Werror)
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    set(DEBUG_FLAGS -Og)
    set(RELEASE_FLAGS -O2)
    #set(STANDARD_FLAGS -std=c++14 -pedantic)
    set(STANDARD_FLAGS -std=c++14)
    # gcc is notorious for reporting incorrect uninitialized variables
    # plus -Werror=attributes warns on qglviewer
    set(WARNING_FLAGS -Wall -Wextra -Wsign-compare -Wfatal-errors -Werror -Wno-error=maybe-uninitialized -Wno-error=attributes)
    set(CMAKE_EXE_LINKER_FLAGS "-s ${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "-s ${CMAKE_SHARED_LINKER_FLAGS}")
endif()

foreach(FLAG ${STANDARD_FLAGS} ${WARNING_FLAGS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG}")
endforeach()

foreach(FLAG ${DEBUG_FLAGS})
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${FLAG}")
endforeach()

foreach(FLAG ${RELEASE_FLAGS})
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${FLAG}")
endforeach()

# VERSION = $$system(hg parents --template '{latesttag}')
add_definitions(-DAPP_VERSION="0.1")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(io)
add_subdirectory(chem)
add_subdirectory(formats)
add_subdirectory(qglviewer)
add_subdirectory(molekulo)
