#pragma once

#ifndef CHESSBOARD_H	
#define CHESSBOARD_H	

#include "Square.h"
#include <vector>
#include <iostream>
using namespace std;


class ChessBoard
{
public:
	ChessBoard();
	void printBoard();
	Square* getSquare(int row, int col);
	Square* getSquare(int posNo);

private:
	// 2D matrix to store the chessboard squares.
	vector<vector<Square>> squars;

	//values of knights
	vector<string> knights;
};

#endif // !CHESSBOARD_H	