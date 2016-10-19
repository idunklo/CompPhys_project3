cmake_minimum_required(VERSION 2.8)

set(GCC_COMPILE_FLAGS "-g -O3 --std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

project("CompPhys_project3")

set(SOURCES
    celestialbody.cpp
    solarsystem.cpp
    vec3.cpp
    )

set(HEADERS
    celestialbody.h
    solarsystem.h
    vec3.h
    )

add_executable(main_project main.cpp ${SOURCES} ${HEADERS})


