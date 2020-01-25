cmake_minimum_required(VERSION 3.15)

message(VCPKG\ ROOT:\ ${VCPKG_ROOT})
message("ENV VCPKG ROOT: $ENV{VCPKG_ROOT}")

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE AND VCPKG_ENABLE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

message(Qt5 ROOT:\ ${Qt5_ROOT})
message(Triplet:\ $ENV{VCPKG_TARGET_TRIPLET})

if(NOT DEFINED ENV{VCPKG_TARGET_TRIPLET})
    set(VCPKG_TARGET_TRIPLET x64-windows)
endif()

if(WASM_ENABLE)
    set(CMAKE_CXX_COMPILE em++)
    set(CMAKE_TOOLCHAIN_FILE "C:\\Users\\Ross\\projects\\emsdk\\upstream\\emscripten\\cmake\\Modules\\Platform\\Emscripten.cmake")
    set(Qt5_DIR "C:/Qt/5.14.0/wasm_32/lib/cmake/Qt5")
    set(Qt5Widgets_DIR "C:/Qt/5.14.0/wasm_32/lib/cmake/Qt5Widgets")
    set(Qt5Gui_DIR "C:/Qt/5.14.0/wasm_32/lib/cmake/Qt5Gui")
    set(Qt5Core_DIR "C:/Qt/5.14.0/wasm_32/lib/cmake/Qt5Core")
    set(Qt5Quick_DIR "C:/Qt/5.14.0/wasm_32/lib/cmake/Qt5Quick")
endif()

project(image-editor CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#find_package(OpenCV CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Quick Zlib REQUIRED)
find_package(ZLIB)

set(SOURCE
    src/main.cpp
    src/image_item.cpp
    src/workspace.cpp
    src/renderer.cpp
    )

set(FORMS
    qml/main.qml
    qml/CanvasFrame.qml
    )

add_executable(${PROJECT_NAME}
    ${SOURCE}
    ${FORMS}
    qml/qml.qrc
    test.qrc
    )

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
    )

target_include_directories(${PROJECT_NAME}
    PRIVATE
        C:/Users/Ross/projects/emsdk/upstream/emscripten/system/include
        ${OpenCV_INCLUDE_DIRS}
    )

target_link_libraries(${PROJECT_NAME}
    PRIVATE
#        ${OpenCV_LIBS}
        Qt5::Core
        Qt5::Widgets
        Qt5::Quick
    )
