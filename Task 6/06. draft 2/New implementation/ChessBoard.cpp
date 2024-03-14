/*****************************************************************//**
 * @file   ChessBoard.cpp
 * @brief  Implementation of the ChessBoard class methods.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/

#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	
	// construct and add squares
	for (int rowNo = 0; rowNo < 4; rowNo++) {
		vector<Square> row;
		for (int i = 0; i < 3; i++) {
			// Construct a new Square object and add it to the row
			row.emplace_back(Square());
		}
		// Move the constructed row into the 2D matrix representing the chessboard
		this->squars.push_back(move(row));
	}

	// Construct knights
	// Black values
	this->knights = { "B1", "B2", "B3" };

	// White values
	this->knights.insert(knights.end(), { "W1", "W2", "W3" });
	
	// Place knight on the board
	// Place white knights to the first row
	for (size_t  i = 0; i < 3; i++) {
		this->squars[0][i].placeKnight(&this->knights[i + (int)3]);
	}

	// Place black knights to the last row
	for (size_t  i = 0; i < 3; i++) {
		this->squars[3][i].placeKnight(&this->knights[i]);
	}

    // assign a heuristic score to each square, a value for each color.

    // square 0:
    this->getSquare(0)->setHeuristicCost({10, 0});
    // square 1:
    this->getSquare(1)->setHeuristicCost({7, 0});
    // square 2:
    this->getSquare(2)->setHeuristicCost({10, 0});
    // square 3:
    this->getSquare(3)->setHeuristicCost({5, 4});
    // square 5:
    this->getSquare(5)->setHeuristicCost({5, 4});
    // square 6:
    this->getSquare(6)->setHeuristicCost({4, 5});
    // square 8:
    this->getSquare(8)->setHeuristicCost({4, 5});
    // square 9:
    this->getSquare(9)->setHeuristicCost({0, 10});
    // square 10:
    this->getSquare(10)->setHeuristicCost({0, 7});
    // square 11:
    this->getSquare(11)->setHeuristicCost({0, 10});

}// ChessBoard()

void ChessBoard::printBoard()
{
	for (const auto& row : squars) {
		for (const auto& square : row) {
			const string* value = square.getKnight();
			if (value == nullptr) {
				// Print 'Em' for empty squares
				cout << "Em ";
				continue;
			}
			else {
				// Print the knight's name for occupied squares
				cout << *value << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}// printBoard()

Square* ChessBoard::getSquare(int row, int col)
{
	return &this->squars[row][col];
}// getSquare()

Square* ChessBoard::getSquare(int posNo)
{
	int row = posNo / 3;
	int col = posNo % 3;
	return this->getSquare(row, col);
}// getSquare()