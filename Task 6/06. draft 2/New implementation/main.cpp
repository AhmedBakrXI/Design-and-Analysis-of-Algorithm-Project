// Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ChessBoard.h"
#include "Graph.h"

int main()
{
	ChessBoard b = ChessBoard();
	b.printBoard();

	Graph p(b);
	p.solvePuzzle();
}
