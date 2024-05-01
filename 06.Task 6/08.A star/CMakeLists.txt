cmake_minimum_required(VERSION 3.27)
project(07__Hill_Climbing)

set(CMAKE_CXX_STANDARD 17)

add_executable(07__Hill_Climbing main.cpp
        State.cpp
        State.h
        Path.cpp
        Path.h)
