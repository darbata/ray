cmake_minimum_required(VERSION 4.3)
project(ray)

set(CMAKE_CXX_STANDARD 23)

add_executable(ray main.cpp
        Tuple.cpp
        Tuple.h
        Colour.cpp
        Colour.h
        Float.cpp
        Float.h)
