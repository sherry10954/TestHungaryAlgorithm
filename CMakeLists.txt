cmake_minimum_required(VERSION 3.19)
project(TestHungaryAlgorithm)

set(CMAKE_CXX_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/inc)
add_executable(TestHungaryAlgorithm
        src/main.cpp
        src/munkres.cpp
        )