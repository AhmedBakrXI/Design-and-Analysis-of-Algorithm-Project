/*****************************************************************//**
 * @file   Graph.cpp
 * @brief  Implementation of the Graph class methods.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/
#include "Graph.h"

vector<Move> Graph::solvePuzzle()
{
    // Initialize the queue with starting positions and other necessary variables
    // The algorithm works with starting from positions 9 and 11.
    deque<int> queue;
    queue.push_back(9);
    queue.push_back(11);

    int completedSwaps = 0;
    int totalMoves = 0;


    // Continue until all swaps are completed
    while (completedSwaps != 6) {
        int currentPosition = queue.front();
        queue.pop_front();

        Square* currentSquare = this->board->getSquare(currentPosition);
        vector<pair<Cost, Square*>>* neighborSquares = &this->nodes.at(currentPosition);

        // If the current square is empty, add its neighbors to the queue
        if (currentSquare->getKnight() == nullptr) {
            addNeighborSquaresToQueue(neighborSquares, queue);
            continue;
        }

        // If not empty, check if it can move to another position or not.
        // To move to another position, the cost must not be inf (represented by -1),
        // and the other node we will move to must be empty, also the prevValue of the 
        // other node must be different from the knight we need to move.
        //
        // Then after transferring, we must check if it arrive to its final destination,
        // to check that it must be transferred to a node that has only one edge and it
        // can't be transferred to another node.
        // if that happened, increment the "doneSwapping" counter.
        // Either ways, we will add the new position to the front of the queue.

        // Determine the color of the knight and try moving it
        // The color of knight, 0 for white, 1 for black
        int knightColor = getKnightColor(currentSquare);
        bool hasMoved = tryMovingKnight(currentSquare, neighborSquares, knightColor, completedSwaps, totalMoves, queue);

        // If the knight has moved, print move details
        if (hasMoved) {
            printMoveDetails(totalMoves, currentSquare);
        }
    }


    // Print the total number of moves and return all moves
    printTotalMoves(totalMoves);
    return allMoves;
}// solvePuzzle()

void Graph::addNeighborSquaresToQueue(vector<pair<Cost, Square*>>* neighborSquares, deque<int>& queue)
{
    // Add all neighbor squares to the queue
    for (auto& node : *neighborSquares) {
        queue.push_back(node.second->getPosNo());
    }
}// addNeighborSquaresToQueue()

int Graph::getKnightColor(Square* square)
{
    // Determine the color of the knight: 0 for white, 1 for black
    return square->getKnight()->at(0) == 'B';
} //getKnightColor()

bool Graph::tryMovingKnight(Square* currentSquare, vector<pair<Cost, Square*>>* neighborSquares, int knightColor, int& completedSwaps, int& totalMoves, deque<int>& queue)
{
    // Flag to know if any movement happened.
    bool hasMoved = false;
    // Flag to know if it arrive to its final destination.
    bool isFinalDestination = true;
    // Destination position in the focused list, so it could be added for only 
    // one time to the queue.
    int destinationIndex = -1;

    // Check if it can move to another position or not, and move to the 1st 
    // available position.
    for (int i = 0; i < neighborSquares->size(); i++) {
        pair<Cost, Square*>* neighborPair = &neighborSquares->at(i);
        if (neighborPair->second->getKnight() == nullptr) {
            if (canMoveToSquare(neighborPair, currentSquare, knightColor)) {
                performMove(neighborPair, currentSquare);
                hasMoved = true;
                destinationIndex = i;

                checkForFinalDestination(neighborPair, isFinalDestination, completedSwaps, knightColor);
                storeMoveData( currentSquare, neighborPair);
                break;
            }
        }
    }

    // Add neighbors to the queue after moving the knight
    addNeighborsToQueue(neighborSquares, queue, destinationIndex);
    return hasMoved;
}// tryMovingKnight()

bool Graph::canMoveToSquare(pair<Cost, Square*>* neighborPair, Square* currentSquare, int knightColor)
{
    // Check if the knight can move to a specific square
    return (
        neighborPair->first.getCost(knightColor) != -1 &&
        (
            neighborPair->second->getPrevValue() == nullptr ||
            *neighborPair->second->getPrevValue() != *currentSquare->getKnight()
            )
        );
}// canMoveToSquare()

void Graph::performMove(pair<Cost, Square*>* neighborPair, Square* currentSquare)
{
    // Move the knight to a new square
    neighborPair->second->placeKnight(currentSquare->removeKnight());
}// performMove()

void Graph::checkForFinalDestination(pair<Cost, Square*>* neighborPair, bool& isFinalDestination, int& completedSwaps, int knightColor)
{
    // Check if the knight has reached its final destination
    int newPos = neighborPair->second->getPosNo();
    vector<pair<Cost, Square*>>* destList = &this->nodes.at(newPos);
    for (auto& pairX : *destList) {
        if (pairX.first.getCost(knightColor) != -1) {
            isFinalDestination = false;
            break;
        }
    }
    if (isFinalDestination) {
        completedSwaps++;
    }
}// checkForFinalDestination()

void Graph::storeMoveData(Square* currentSquare, pair<Cost, Square*>* neighborPair)
{
    // Store the move data in the allMoves vector
    int oldPos = currentSquare->getPosNo();
    int newPos = neighborPair->second->getPosNo();
    string knightMoved = *neighborPair->second->getKnight();
    allMoves.push_back( Move(oldPos, newPos, knightMoved));
}// storeMoveData()

void Graph::addNeighborsToQueue(vector<pair<Cost, Square*>>* neighborSquares, deque<int>& queue, int destinationIndex)
{
    // Add neighbors to the queue after moving the knight
    for (int i = 0; i < neighborSquares->size(); i++) {
        if (i == destinationIndex) {
            queue.push_front(i);
            continue;
        }
        queue.push_back(neighborSquares->at(i).second->getPosNo());
    }
}// addNeighborsToQueue()

void Graph::printMoveDetails(int& totalMoves, Square* currentSquare)
{
    // Print move details including step number, board, and move
    totalMoves++;
    cout << "step number: " << totalMoves << endl;
    this->board->printBoard();
    allMoves.back().printMove();
    cout << endl;
}// printMoveDetails()

void Graph::printTotalMoves(int totalMoves)
{
    // Print the total number of moves
    cout << endl << "Total number of moves: " << totalMoves;
}// printMoveDetails()


Graph::Graph(chess_board& board) : board(&board)
{
    this->nodes.resize(12);

    // square 0:
    //connect to square 5
    nodes[0].emplace_back(Cost(0, -1), board.getSquare(5));
    //////////////////////////////////////////////

    // square 1:
    //connect to square 8
    nodes[1].emplace_back(Cost(0, -1), board.getSquare(8));
    //////////////////////////////////////////////

    // square 2:
    //connect to square 3
    nodes[2].emplace_back(Cost(0, -1), board.getSquare(3));
    //////////////////////////////////////////////

    // square 3:
    //connect to square 2
    nodes[3].emplace_back(Cost(-1, 0), board.getSquare(2));
    //connect to square 8
    nodes[3].emplace_back(Cost(-1, 0), board.getSquare(8));
    //connect to square 10
    nodes[3].emplace_back(Cost(0, -1), board.getSquare(10));
    //////////////////////////////////////////////

    // square 5:
    //connect to square 0
    nodes[5].emplace_back(Cost(-1, 0), board.getSquare(0));
    //connect to square 6
    nodes[5].emplace_back(Cost(0, -1), board.getSquare(6));
    //////////////////////////////////////////////

    // square 6:
    //connect to square 1
    nodes[6].emplace_back(Cost(-1, 0), board.getSquare(1));
    //connect to square 11
    nodes[6].emplace_back(Cost(0, -1), board.getSquare(11));
    //////////////////////////////////////////////	

    // square 8:
    //connect to square 3
    nodes[8].emplace_back(Cost(-1, 0), board.getSquare(3));
    //connect to square 9
    nodes[8].emplace_back(Cost(0, -1), board.getSquare(9));
    //////////////////////////////////////////////

    // square 9:
    //connect to square 8
    nodes[9].emplace_back(Cost(-1, 0), board.getSquare(8));
    //////////////////////////////////////////////

    // square 10:
    //connect to square 5
    nodes[10].emplace_back(Cost(-1, 0), board.getSquare(5));
    //////////////////////////////////////////////

    // square 11:
    nodes[11].emplace_back(Cost(-1, 0), board.getSquare(6));
    //////////////////////////////////////////////
}// printMoveDetails()

void Graph::printGraph()
{
    for (size_t i = 0; i < nodes.size(); ++i) {
        cout << "Node " << i << ":" << endl;
        for (size_t j = 0; j < nodes[i].size(); ++j) {
            cout << "  Cost: White - " << nodes[i][j].first.whiteCost;
            cout << ", Black - " << nodes[i][j].first.blackCost << endl;
            cout << "  Square: " << nodes[i][j].second->getPosNo();
            cout << ", Value: ";
            if (nodes[i][j].second->getKnight() == nullptr) {
                cout << "EM";
            }
            else {
                cout << *nodes[i][j].second->getKnight();
            }
            cout << endl << endl;
        }
        cout << endl;
    }
}// printMoveDetails()
