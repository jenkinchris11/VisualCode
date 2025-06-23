cmake_minimum_required(VERSION 3.10)
project(VisualCodePhotoEditor)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
# Prefer the CMake package configuration provided by vcpkg on Windows
find_package(exiv2 CONFIG)
if(NOT exiv2_FOUND)
    find_package(PkgConfig)
    if(PkgConfig_FOUND)
        pkg_check_modules(EXIV2 REQUIRED exiv2)
    else()
        message(FATAL_ERROR "exiv2 not found")
    endif()
else()
    # exiv2 provides an imported target named exiv2lib
    set(EXIV2_LIBRARIES exiv2lib)
    set(EXIV2_INCLUDE_DIRS "")
endif()

add_executable(photo_editor
    src/main.cpp
    src/Catalog.cpp
    src/ImageProcessor.cpp
)

target_include_directories(photo_editor PRIVATE ${OpenCV_INCLUDE_DIRS} ${EXIV2_INCLUDE_DIRS})
target_link_libraries(photo_editor PRIVATE ${OpenCV_LIBS} ${EXIV2_LIBRARIES})
