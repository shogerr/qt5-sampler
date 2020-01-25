cmake_minimum_required(VERSION 3.12.0)
cmake_policy(SET CMP0074 NEW)

project(qt-sampler)

include("cmake/assign_source_group.cmake")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Quick REQUIRED)
#find_package(Qt5Widgets CONFIG REQUIRED)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:console")

set(SOURCE
    src/main.cpp
    src/button_sampler.cpp
    src/mainwindow.cpp
    src/form.cpp
    src/quickpanel.cpp
    src/barpanel.cpp
)
assign_source_group(${SOURCE})

set(FORMS
    src/form.ui
    src/barpanel.ui
    src/main.qml
    src/quickpanel.ui.qml
)
assign_source_group(${FORMS})


# Removed WIN32
add_executable(qt-sampler ${SOURCE} ${FORMS} "src/qml.qrc")
set_target_properties(qt-sampler PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "-qml")
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(qt-sampler Qt5::Core Qt5::Widgets Qt5::Quick)

