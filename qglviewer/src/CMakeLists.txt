set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Eigen3 3.0.0)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

add_definitions(-DNO_VECTORIAL_RENDER)
# temp
add_definitions(-DQGLVIEWER_STATIC)

# CMAKE_AUTOMOC would not work when headers to be moc'ed are not in the same dir
# set(CMAKE_AUTOMOC ON)
if(HAVE_QT5)
    QT5_WRAP_CPP(camera_moc ${VIEWER_HEADER_DIR}/camera.h)
    QT5_WRAP_CPP(frame_moc ${VIEWER_HEADER_DIR}/frame.h)
    QT5_WRAP_CPP(key_frame_interpolator_moc ${VIEWER_HEADER_DIR}/keyFrameInterpolator.h)
    QT5_WRAP_CPP(manipulated_camera_frame_moc ${VIEWER_HEADER_DIR}/manipulatedCameraFrame.h)
    QT5_WRAP_CPP(manipulated_frame_moc ${VIEWER_HEADER_DIR}/manipulatedFrame.h)
    QT5_WRAP_CPP(qglviewer_moc ${VIEWER_HEADER_DIR}/qglviewer.h)
else()
    QT4_WRAP_CPP(camera_moc ${VIEWER_HEADER_DIR}/camera.h)
    QT4_WRAP_CPP(frame_moc ${VIEWER_HEADER_DIR}/frame.h)
    QT4_WRAP_CPP(key_frame_interpolator_moc ${VIEWER_HEADER_DIR}/keyFrameInterpolator.h)
    QT4_WRAP_CPP(manipulated_camera_frame_moc ${VIEWER_HEADER_DIR}/manipulatedCameraFrame.h)
    QT4_WRAP_CPP(manipulated_frame_moc ${VIEWER_HEADER_DIR}/manipulatedFrame.h)
    QT4_WRAP_CPP(qglviewer_moc ${VIEWER_HEADER_DIR}/qglviewer.h)
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if(HAVE_QT5)
    foreach(dep Core Gui OpenGL Xml)
        add_definitions(${Qt5${dep}_DEFINITIONS})
        include_directories(${Qt5${dep}_INCLUDE_DIRS})
        list(APPEND QT_LIBRARIES ${Qt5${dep}_LIBRARIES})
    endforeach()
else()
    include(${QT_USE_FILE})
    add_definitions(${QT_DEFINITIONS})
    set(QT_LIBRARIES Qt4::QtCore Qt4::QtGui Qt4::QtOpenGL Qt4::QtXml)
endif()

file(GLOB_RECURSE SOURCES *.cpp)
file(GLOB_RECURSE RESOURCES *.qrc)

include_directories("../include/qglviewer")

add_library(qglviewer SHARED ${SOURCES} ${RESOURCES}
	${camera_moc}
	${frame_moc}
	${key_frame_interpolator_moc}
	${manipulated_camera_frame_moc}
	${manipulated_frame_moc}
	${qglviewer_moc}
)

set_target_properties(qglviewer PROPERTIES DEBUG_POSTFIX "d")
target_link_libraries(qglviewer ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
