//
// Created by eslam on 14/03/2024.
//

#ifndef POSSIBLE_MOVES_H
#define POSSIBLE_MOVES_H
#include "Graph.h"
#include "ChessBoard.h"
#include "Move.h"
#include <algorithm>

using namespace std;

class PossibleMoves{
public:
    PossibleMoves(Graph& g,ChessBoard& b): graph(g), board(b), indexChosen(0), moves(allMoves()) {}
    PossibleMoves(const PossibleMoves& other) :
            board(other.board),
            moves(other.moves),
            indexChosen(other.indexChosen + 1),
            graph(other.graph) {}

    Move* getMove(){
        return &moves[indexChosen];
    }

private:
    ChessBoard& board;
    vector<Move> moves;
    int indexChosen;
    Graph& graph;

    // helper methods
    vector<Move> allMoves();
};


#endif //POSSIBLE_MOVES_H
