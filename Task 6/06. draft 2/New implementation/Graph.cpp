/*****************************************************************//**
 * @file   Graph.cpp
 * @brief  Implementation of the Graph class methods.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/
#include "Graph.h"

vector<vector<Move>> Graph::solvePuzzle() {

    // choose any knight
    int movingKnight = Graph::randomKnight();
    cout << "First knight to move: " << movingKnight;
    bool puzzleNotSolved = true;
    bool firstMove = true;

    do {

        vector<Move> trial;

        // First move
        if(firstMove){
            int movingTo = nodes[movingKnight][0]->getPosNo();
            trial.push_back(moveKnight(movingKnight, movingTo));
            firstMove = false;
        }

        while(trial.size() < 16) {
            // get the best move of all possibleMoves


        }

    } while (puzzleNotSolved);
    return trials;
}// solvePuzzle()


Graph::Graph(ChessBoard &board) : board(&board) {
    this->nodes.resize(12);

    // square 0:
    //connect to square 5
    nodes[0].emplace_back(board.getSquare(5));
    //////////////////////////////////////////////

    // square 1:
    //connect to square 6
    nodes[1].emplace_back(board.getSquare(6));
    //connect to square 8
    nodes[1].emplace_back(board.getSquare(8));
    //////////////////////////////////////////////

    // square 2:
    //connect to square 3
    nodes[2].emplace_back(board.getSquare(3));
    //////////////////////////////////////////////

    // square 3:
    //connect to square 2
    nodes[3].emplace_back(board.getSquare(2));
    //connect to square 8
    nodes[3].emplace_back(board.getSquare(8));
    //connect to square 10
    nodes[3].emplace_back(board.getSquare(10));
    //////////////////////////////////////////////

    // square 5:
    //connect to square 0
    nodes[5].emplace_back(board.getSquare(0));
    //connect to square 6
    nodes[5].emplace_back(board.getSquare(6));
    //connect to square 10
    nodes[5].emplace_back(board.getSquare(10));
    //////////////////////////////////////////////

    // square 6:
    //connect to square 1
    nodes[6].emplace_back(board.getSquare(1));
    //connect to square 5
    nodes[6].emplace_back(board.getSquare(5));
    //connect to square 11
    nodes[6].emplace_back(board.getSquare(11));
    //////////////////////////////////////////////	

    // square 8:
    //connect to square 1
    nodes[8].emplace_back(board.getSquare(1));
    //connect to square 3
    nodes[8].emplace_back(board.getSquare(3));
    //connect to square 9
    nodes[8].emplace_back(board.getSquare(9));
    //////////////////////////////////////////////

    // square 9:
    //connect to square 8
    nodes[9].emplace_back(board.getSquare(8));
    //////////////////////////////////////////////

    // square 10:
    //connect to square 3
    nodes[10].emplace_back(board.getSquare(3));
    //connect to square 5
    nodes[10].emplace_back(board.getSquare(5));
    //////////////////////////////////////////////

    // square 11:
    nodes[11].emplace_back(board.getSquare(6));
    //////////////////////////////////////////////
}

int Graph::randomKnight() {
    // Seed the random number generator
    srand(time(nullptr));

    // Define the set of numbers
    int numbers[] = {0, 1, 2, 9, 10, 11};

    // Generate a random index within the range of the array
    int randomIndex = rand() % 6;

    // Choose the number corresponding to the random index
    return numbers[randomIndex];
}

Move Graph::moveKnight(int oldPos, int newPos) {
    board->getSquare(newPos)->placeKnight(board->getSquare(oldPos)->removeKnight());
    return Move(
            oldPos,
            newPos,
            *board->getSquare(newPos)->getKnight(),
            board->getSquare(oldPos)->getHeuristicCost(board->getSquare(oldPos)->getKnight()[0] == "B") -
                board->getSquare(newPos)->getHeuristicCost(board->getSquare(newPos)->getKnight()[0] == "B")
                );
}


