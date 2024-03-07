/*****************************************************************//**
 * @file   Move.h
 * @brief  Declaration of the Move class.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/
#pragma once

#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Represents a move made on a chessboard.
 * 
 * The Move class provides functionality to record and represent individual
 * moves made by the knight, including the old and new positions of the knight.
 * 
 * Moves will be used by the GUI to display moves at each step of solving the puzzle.
 */
class Move
{
public:
	/**
	 * @brief Constructor for the Move class.
	 * @param oldPos The old position of the piece.
	 * @param newPos The new position of the piece.
	 * @param knight The name of the knight making the move.
	 */
	Move(int oldPos, int newPos, string knight): 
		oldPos(oldPos), newPos(newPos), knight(knight) {}

	/**
	 * @brief Retrieves the name of the knight.
	 * @return The name of the knight.
	 */
	string getknight() {
		return this->knight;
	}

	/**
	 * @brief Retrieves the old position of the piece.
	 * @return The old position of the piece.
	 */
	int getOldPos() {
		return this->oldPos;
	}

	/**
	 * @brief Retrieves the new position of the piece.
	 * @return The new position of the piece.
	 */
	int getNewPos() {
		return this->newPos;
	}

	/**
	 * @brief Prints the details of the move on console.
	 */
	void printMove() {
		cout << "Move: " << knight << " from " << oldPos << " to " << newPos << endl;
	}
private:
	// The old position of the piece.
	int oldPos;
	// The new position of the piece.
	int newPos;
	// The name of the knight making the move.
	string knight;
};// class Move



#endif // !MOVE_H


