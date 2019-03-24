cmake_minimum_required(VERSION 3.5)
project(Labyrinth_GSoC2019)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")

set(SOURCE_FILES
        main.cpp
        Labyrinth.cpp)

set(HEADER_FILES
        Labyrinth.h)

add_executable(Labyrinth_GSoC2019 ${SOURCE_FILES} ${HEADER_FILES})
