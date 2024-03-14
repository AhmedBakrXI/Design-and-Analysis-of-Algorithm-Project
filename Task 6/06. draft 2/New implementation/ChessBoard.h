/*****************************************************************//**
 * @file   ChessBoard.h
 * @brief  Declaration of the ChessBoard class.
 * 
 * The ChessBoard class provides functionality to manage the chessboard state, 
 * including placing and moving knights on the board.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/
#pragma once

#ifndef CHESSBOARD_H	
#define CHESSBOARD_H	

#include "Square.h"
#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief Represents a chessboard.
 *
 * This class provides functionalities for creating and manipulating a chessboard,
 * as well as printing its current state.
 */
class ChessBoard
{
public:
	/**
	 * @brief Constructs a chessboard with squares and knights.
	 *
	 * Initializes a 4x3 grid representing the chessboard and populates it with squares.
	 * Initializes the knights vector with black and white knight values.
	 * Places white knights (W1, W2, W3) on the first row and black knights (B1, B2, B3) on the last row of the chessboard.
	 *
	 * The layout of the chessboard is as follows: number(knight name), Em == empty
	 * 0 (W1)   1 (W2)   2 (W3)
	 * 3 (Em)   4 (Em)   5 (Em)
	 * 6 (Em)   7 (Em)   8 (Em)
	 * 9 (B1)   10 (B2)  11 (B3)
	 * 
	 * Note: each square represented by: number (piece name), E.g., W1 is placed on position 0 at beginning.
	 * Note: 'Em' represents an empty square.
	 */
	ChessBoard();

	/**
	 * @brief Prints the current state of the chessboard.
	 */
	void printBoard();

	/**
	 * @brief Gets the square at the specified row and column.
	 * @param row The row index of the square.
	 * @param col The column index of the square.
	 * @return Pointer to the square at the specified position.
	 */
	Square* getSquare(int row, int col);

	/**
	 * @brief Gets the square at the specified position number.
	 * @param posNo The position number of the square.
	 * @return Pointer to the square at the specified position.
	 */
	Square* getSquare(int posNo);

private:
	// 2D matrix to store the chessboard squares.
	vector<vector<Square>> squars;

	// Values of knights.
	vector<string> knights;

};// class ChessBoard

#endif // !CHESSBOARD_H	