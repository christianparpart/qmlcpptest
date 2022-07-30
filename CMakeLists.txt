cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(qmlcpptest VERSION "0.0.0" LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"))
    set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
endif()

find_package(Threads)

if(DEFINED MSVC)
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DNOMINMAX)
endif()

find_package(Qt5 COMPONENTS Gui Qml Quick QuickControls2 Network Widgets Multimedia REQUIRED)  # apt install qtbase5-dev libqt5gui5
add_executable(qmlcpptest main.cpp main.h resources.qrc)
set_target_properties(qmlcpptest PROPERTIES AUTOMOC ON)
set_target_properties(qmlcpptest PROPERTIES AUTORCC ON)
target_include_directories(qmlcpptest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
target_compile_definitions(qmlcpptest PRIVATE $<$<CONFIG:Debug>:QT_QML_DEBUG>)
target_compile_definitions(qmlcpptest PRIVATE $<$<CONFIG:Debug>:QMLJSDEBUGGER>)
target_compile_definitions(qmlcpptest PRIVATE $<$<CONFIG:Debug>:QT_DECLARATIVE_DEBUG>)
target_link_libraries(qmlcpptest Qt5::Gui Qt5::Qml Qt5::Quick Qt5::QuickControls2)
