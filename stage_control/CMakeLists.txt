cmake_minimum_required(VERSION 3.16)

qt_add_library(stage_control 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/device.cpp
)

target_compile_options(stage_control PRIVATE -march=native -Wall -Wextra)

target_include_directories(stage_control
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

target_link_libraries(stage_control usb-1.0)
