cmake_minimum_required(VERSION 3.10)
project(VisualCodePhotoEditor)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(photo_editor
    src/main.cpp
    src/Catalog.cpp
    src/ImageProcessor.cpp
)

target_include_directories(photo_editor PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(photo_editor PRIVATE ${OpenCV_LIBS})
