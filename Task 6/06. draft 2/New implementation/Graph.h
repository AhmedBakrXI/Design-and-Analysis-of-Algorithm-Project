/*****************************************************************//**
 * @file   Graph.h
 * @brief  Declaration of the Graph class and the Cost class.
 * 
 * The Graph class encapsulates the logic for solving the knight's tour puzzle
 * using graph traversal algorithms.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/
#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "ChessBoard.h"
#include "PossibleMoves.h"
#include "Move.h"
#include <utility>
#include <deque>
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()


using namespace std;


/**
 * @brief Represents a graph for solving the knight's puzzle on a chessboard.
 * 
 * The Graph class encapsulates the logic for solving the knight's tour puzzle
 * using graph traversal algorithms.
 */
class Graph {
public:
    friend class PossibleMoves;
    /**
     * @brief Constructs a Graph object with the given ChessBoard.
     *
     * The constructor initializes a Graph object with the provided ChessBoard by creating
     * nodes and establishing connections between them based on the specified rules.
     * Each square is connected to other squares based on specific knight moves allowed in chess.
     *
     * TODO: add the graph with cost image.
     * @image html image_filename.png
     * @image latex image_filename.png "Caption text" width=5cm
     *
     * @param board The ChessBoard object representing the chessboard.
     */
    Graph(ChessBoard &board);


    /**
     * @brief Solves the knight's  puzzle and returns a vector of Move objects representing the solution.
     *
     * This function implements a breadth-first search algorithm to solve the knight's puzzle.
     *  - It starts from the given starting positions (9 and 11) and explores all possible moves
     *    using a modified queue-based approach.
     *
     *  - The algorithm iteratively explores all reachable squares considering the cost of each move and
     *    ensuring that the knight does not visit any square twice.
     *
     *  - If a square is empty, its neighboring squares are added to the queue for exploration.
     *
     *  - If the knight occupies a square, the algorithm attempts to move it to an empty neighboring square
     *    based on the cost associated with each move.
     *
     *  - After each move, the algorithm checks if the knight has reached its final destination, indicated by
     *    a square with only one edge.
     *
     *  - The algorithm continues until it completes all necessary swaps to solve the puzzle, i.e., until the
     *    knight has visited all squares exactly once.
     *
     *  - It maintains a record of all moves made during the puzzle solution, which are returned as a vector
     *    of Move objects.
     *
     * The returned vector of Move objects represents the solution and is used by the GUI
     * to display the sequence of knight movements on the chessboard.
     *
     * @return vector<Move*>* A pointer to a vector of Move objects representing the solution.
     */
    vector<vector<Move>> solvePuzzle();

private:
    // Represents the nodes (squares) of the graph, each containing a pointer to a Square object.
    vector<vector<Square *>> nodes;

    vector<vector<Move>> trials;

    // ChessBoard to solve.
    ChessBoard *board;

    // Helper methods
    static int randomKnight();
    Move moveKnight(int oldPos, int newPos);

};// class Graph

#endif // !GRAPH_H