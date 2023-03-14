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

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED )


configure_file(project/images/logo.png images/logo.png COPYONLY)

#=================== INCLUSION OF Project Files ====================#
set(PROJECT_DIR "${CMAKE_SOURCE_DIR}/project")
set(GUI_DIR "${CMAKE_SOURCE_DIR}/project/gui")
set(LOGIC_DIR "${CMAKE_SOURCE_DIR}/project/logic")
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/project/forms")

file(GLOB_RECURSE SOURCES
    "${PROJECT_DIR}/*.h"
    "${PROJECT_DIR}/*.cpp"
    "${PROJECT_DIR}/*.ui"
    "${PROJECT_DIR}/*.qrc"
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
target_include_directories(Scorpion PRIVATE ${PROJECT_DIR})
target_include_directories(Scorpion PRIVATE ${GUI_DIR})
target_include_directories(Scorpion PRIVATE ${LOGIC_DIR})
target_include_directories(Scorpion PRIVATE ${FORMS_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(Scorpion Qt5::Widgets Qt5::PrintSupport )
