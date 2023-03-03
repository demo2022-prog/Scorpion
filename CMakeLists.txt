cmake_minimum_required(VERSION 3.5)

if (WIN32)
    project(Scorpion VERSION 0.1 LANGUAGES CXX)
elseif(UNIX)
    project(Scorpion VERSION 0.1)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


#=================== INCLUSION OF Project Files ====================#
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(GUI_DIR "${CMAKE_SOURCE_DIR}/src/gui")
set(LOGIC_DIR "${CMAKE_SOURCE_DIR}/src/logic")

include_directories(${SRC_DIR})
include_directories(${GUI_DIR})
include_directories(${LOGIC_DIR})

file(GLOB_RECURSE SOURCES
    "${SRC_DIR}/*.h"
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.ui"
    "${SRC_DIR}/*.qrc"
)

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32)
    add_executable(Scorpion WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(Scorpion ${SOURCES})
endif()

# Add the target includes for MY_PROJECT
target_include_directories(Scorpion PRIVATE ${SRC_DIR})
target_include_directories(Scorpion PRIVATE ${GUI_DIR})
target_include_directories(Scorpion PRIVATE ${LOGIC_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(Scorpion Qt5::Widgets)
