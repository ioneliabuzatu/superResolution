cmake_minimum_required(VERSION 3.0)
project(superResolution)

set(CMAKE_BUILD_TYPE  Debug)
set(CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(
        superResolution
        src/main.cpp
        src/neuron.cpp
        src/layer.cpp
        src/matrix.cpp
        src/fc.cpp
)