cmake_minimum_required(VERSION 3.16)

project(MechanicalLoader VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts)

add_subdirectory(stage_control)

set(PROJECT_SOURCES
        main.cpp
        gui/mainwindow/mainwindow.cpp
        gui/mainwindow/mainwindow.h
        gui/mainwindow/mainwindow.ui
        stage_control/src/device.cpp
        stage_control/src/transferqueue.h
        stage_control/src/device.h
        plugins/sinusoidalstimulation/sinusoidalstimulation.h 
        plugins/sinusoidalstimulation/sinusoidalstimulation.cpp 
        plugins/sinusoidalstimulation/sinusoidalstimulation.ui
        luaapi/luaapi.cpp
        luaapi/luaapi.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MechanicalLoader
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(MechanicalLoader SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MechanicalLoader
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MechanicalLoader
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Charts
        stage_control
        luajit-5.1
        lua
)

target_include_directories(MechanicalLoader
    PRIVATE
        gui/mainwindow
        stage_control/src
        luaapi/
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MechanicalLoader)
endif()
set_target_properties(MechanicalLoader PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MechanicalLoader
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MechanicalLoader)
endif()


if(EXISTS "${CMAKE_BINARY_DIR}/compile_commands.json")
    configure_file("${CMAKE_BINARY_DIR}/compile_commands.json" "${CMAKE_SOURCE_DIR}/build" COPYONLY)
endif()
