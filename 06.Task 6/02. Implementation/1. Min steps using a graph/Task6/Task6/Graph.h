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
#include "Move.h"
#include <utility>
#include <deque>
#include <iostream>


using namespace std;

/**
 * @brief Represents the cost of moving a knight from one square to another.
 * 
 * The cost used to control the movement of knights to the correct squares.
 */
class Cost {
	friend class Graph;
private:
	/**
	 * @brief Constructor for the Cost class.
	 * Note: for value of infinity add cost = -1
	 * @param whiteCost The cost of moving a white knight.
	 * @param blackCost The cost of moving a black knight.
	 */
	Cost(int whiteCost, int blackCost) : whiteCost(whiteCost), blackCost(blackCost) {}

	/**
	 * @brief Gets the cost of moving a knight of a specific color to simplify the using.
	 *
	 * @param color The color of the knight (0 for white, 1 for black).
	 * @return int The cost of moving the knight.
	 */
	int getCost(int color) {
		 return color ? blackCost: whiteCost;
	}

	// The cost of moving a white knight.
	int whiteCost;

	// The cost of moving a black knight.
	int blackCost;
}; // class Cost


/**
 * @brief Represents a graph for solving the knight's puzzle on a chessboard.
 * 
 * The Graph class encapsulates the logic for solving the knight's tour puzzle
 * using graph traversal algorithms.
 */
class Graph
{
public:
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
	Graph(ChessBoard& board);

	/**
	 * @brief Prints the graph (for debugging purposes).
	 */
	void printGraph();

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
	vector<Move*>* solvePuzzle();
private:
	// Represents the nodes (squares) of the graph, each containing a cost and a pointer to a Square object.
	vector<
		vector
		<pair<Cost, Square*>
		>
	> nodes;

	// ChessBoard to solve.
	ChessBoard* board;

	// Helper methods

	/**
	 * @brief Adds neighbor squares to the queue for processing.
	 *
	 * This function iterates over the provided vector of neighbor squares and adds their positions to the 
	 * queue for further processing. 
	 * 
	 * It is used in the knight's puzzle algorithm to enqueue neighboring squares that need to be explored.
	 * @param neighborSquares Pointer to the vector of neighbor squares.
	 * @param queue The deque representing the positions to process.
	 * @param destinationIndex The index of the destination square to prioritize.
	 */
	void addNeighborSquaresToQueue(vector<pair<Cost, Square*>>* neighborSquares, deque<int>& positionsToProcess);
	
	/**
	 * @brief Determines the color of the knight on a given square.
	 *
	 * @param square Pointer to the Square object.
	 * @return int The color of the knight (0 for white, 1 for black).
	 */
	int getKnightColor(Square* square);
	
	/**
	 * @brief Tries to move the knight to an empty neighboring square.
	 *
	 * This function attempts to move the knight currently occupying the provided square to an adjacent
	 * empty square. 
	 * 
	 * It checks each neighboring square to see if it's empty and if the knight can move to it based on the 
	 * cost constraints.
	 * 
	 * If a valid move is found, the knight is transferred, and relevant data such as the move details and 
	 * final destination status are updated.
	 * 
	 * @param currentSquare Pointer to the current Square object.
	 * @param neighborSquares Pointer to the vector of neighbor squares.
	 * @param knightColor The color of the knight (0 for white, 1 for black).
	 * @param completedSwaps Reference to the number of completed swaps.
	 * @param totalMoves Reference to the total number of moves.
	 * @param allMoves Pointer to the vector of Move objects representing all moves.
	 * @param queue The deque representing the positions to process.
	 * @return bool True if the knight moved, false otherwise.
	 */
	bool tryMovingKnight(Square* currentSquare, vector<pair<Cost, Square*>>* neighborSquares, int knightColor, 
		int& completedSwaps, int& totalMoves, vector<Move*>* allMoves, deque<int>& positionsToProcess);

	/**
	 * @brief Checks if the knight can move to a specific square.
	 *
	 * This function determines whether the knight can move to a specific neighboring square based on the cost 
	 * associated with the move and the color of the knight.
	 * 
	 * It verifies that the cost is not infinite (represented by -1) and that the square is either empty or 
	 * occupied by another knight.
	 * 
	 * @param neighborPair Pointer to the pair representing the neighbor square and its cost.
	 * @param currentSquare Pointer to the current Square object.
	 * @param knightColor The color of the knight (0 for white, 1 for black).
	 * @return bool True if the knight can move to the square, false otherwise.
	 */
	bool canMoveToSquare(pair<Cost, Square*>* neighborPair, Square* currentSquare, int knightColor);
	
	/**
	 * @brief Moves the knight to a new square.
	 *
	 * This function moves the knight from the current square to a new square represented by the neighbor pair.
	 * 
	 * It removes the knight from the current square and places it on the neighbor square.
	 * 
	 * @param neighborPair Pointer to the pair representing the neighbor square and its cost.
	 * @param currentSquare Pointer to the current Square object.
	 */
	void performMove(pair<Cost, Square*>* neighborPair, Square* currentSquare);

	/**
	 * @brief Checks if the knight has reached its final destination.
	 *
	 * This function examines whether the knight has reached its final destination after moving to
	 * a neighbor square. 
	 * It iterates over the destination list of the current square to determine if any valid moves 
	 * are available, indicating that the final destination has not been reached.
	 * 
	 * If the final destination is reached, it increments the completedSwaps counter.
	 * 
	 * @param neighborPair Pointer to the pair representing the neighbor square and its cost.
	 * @param isFinalDestination Reference to a flag indicating if the final destination is reached.
	 * @param completedSwaps Reference to the number of completed swaps.
	 * @param knightColor The color of the knight (0 for white, 1 for black).
	 */
	void checkForFinalDestination(pair<Cost, Square*>* neighborPair, bool& isFinalDestination, int& completedSwaps, int knightColor);

	/**
	 * @brief Stores the move data in the vector of Move objects.
	 *
	 * This function records the details of a move, including the old position, new position, 
	 * and the knight moved, into the vector of Move objects representing all moves.
	 * 
	 * @param allMoves Pointer to the vector of Move objects representing all moves.
	 * @param currentSquare Pointer to the current Square object.
	 * @param neighborPair Pointer to the pair representing the neighbor square and its cost.
	 */
	void storeMoveData(vector<Move*>* allMoves, Square* currentSquare, pair<Cost, Square*>* neighborPair);
	
	/**
	 * @brief Adds neighbors to the queue for processing after moving the knight.
	 *
	 * This function adds neighboring squares to the queue for processing after the knight has moved.
	 * It prioritizes adding the destination square first to ensure it's processed next.
	 * Which is an important step in this algorithm.
	 * 
	 * @param neighborSquares Pointer to the vector of neighbor squares.
	 * @param queue The deque representing the positions to process.
	 * @param destinationIndex The index of the destination square to prioritize.
	 */
	void addNeighborsToQueue(vector<pair<Cost, Square*>>* neighborSquares, deque<int>& positionsToProcess, int destinationIndex);
	
	/**
	 * @brief Prints move details including step number, board, and move.
	 *
	 * 
	 * @param totalMoves Reference to the total number of moves.
	 * @param currentSquare Pointer to the current Square object.
	 * @param allMoves Pointer to the vector of Move objects representing all moves.
	 */
	void printMoveDetails(int& totalMoves, Square* currentSquare, vector<Move*>* allMoves);
	
	/**
		 * @brief Prints the total number of moves.
		 *
		 * @param totalMoves The total number of moves.
		 */
	void printTotalMoves(int totalMoves);
};// class Graph

#endif // !GRAPH_H