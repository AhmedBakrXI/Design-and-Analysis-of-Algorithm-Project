#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "ChessBoard.h"
#include "Move.h"
#include <utility>
#include <deque>
#include <iostream>


using namespace std;

class Cost {
	friend class Graph;
private:
	Cost(int whiteCost, int blackCost) : whiteCost(whiteCost), blackCost(blackCost) {}
	int getCost(int color) {
		if (color == 0) return whiteCost;
		return blackCost;
	}
	// inf == no edge, inf = -1.
	int whiteCost;
	int blackCost;
};



class Graph
{
public:
	Graph(ChessBoard& board);
	void printGraph();
	vector<Move*>* solvePuzzle();
private:
	vector<
		vector
		<pair<Cost, Square*>
		>
	> nodes; //pair<int cost, Square*>

	ChessBoard* board;



};



#endif // !GRAPH_H

