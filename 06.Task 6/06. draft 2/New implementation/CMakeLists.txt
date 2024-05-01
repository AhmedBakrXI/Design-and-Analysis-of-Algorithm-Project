cmake_minimum_required(VERSION 3.27)
project(New_implementation)

set(CMAKE_CXX_STANDARD 17)

add_executable(New_implementation main.cpp
        ChessBoard.cpp
        Graph.cpp
        Square.cpp
        Move.cpp
        PossibleMoves.cpp
        PossibleMoves.h)
