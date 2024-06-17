cmake_minimum_required(VERSION 3.10)
project(cube-eater)

set(CMAKE_CXX_STANDARD 20)
set(RAYLIB_DIR "/home/$ENV{USER}/raylib")

include(${RAYLIB_DIR}/cmake/raylib-config.cmake)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.rc)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/button/include    
)

add_executable(
    cube-eater
    src/main.cpp
    src/app.cpp
    src/game_object.cpp
    src/sphere.cpp
    src/cube.cpp
    src/tools_mod.cpp
)

target_link_libraries(cube-eater ${OPENCV_LIBRARIES} ${CURL_LIBRARIES} raylib)
