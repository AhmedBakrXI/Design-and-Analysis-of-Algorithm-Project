//
// Created by eslam on 01/05/2024.
//

#include "State.h"

vector<State> State::moveChess(int position, vector<char> currentState) {
    vector<State> ret;

    vector<pair<int, int>> possibleMoves = {{-1, -2},
                                            {-1, 2},
                                            {-2, -1},
                                            {-2, 1},
                                            {1,  -2},
                                            {1,  2},
                                            {2,  -1},
                                            {2,  1}};
    for (auto val: possibleMoves) {
        vector<char> temp = currentState;

        int rowMove = (position / 3) + val.first;
        int colMove = (position % 3) + val.second;
        if (isValidMove(rowMove, colMove, 3, 4)) {
            if (currentState[colMove + rowMove * 3] == 'E') {
                temp[colMove + rowMove * 3] = temp[position];
                temp[position] = 'E';
                State container = State(temp);
                container.calculateHeuristic();
                ret.push_back(container);

            }
        }
    }
    return ret;
}


void State::calculateHeuristic() {
    int sum = 0;
    for (int idx = 0; idx < (int) state.size(); idx++) {
        if (state[idx] == 'W') {

            sum += (3 - ((idx) / 3));

        } else if (state[idx] == 'B') {
            sum += (idx / 3);

        }
    }
    heuristic = sum;
    //cout << endl;
}

/*void State::calculateHeuristic() {
    // Define weights for different positions on the board
    vector<vector<int>> positionWeights = {
            {2, 3, 2},
            {3, INT_MAX, 3},
            {4, INT_MAX, 4},
            {3, 4, 3}
    };

    int heuristic = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            char piece = this->state[i * 3 + j];
            if (piece == 'W') { // White knight
                heuristic += positionWeights[i][j];
            } else if (piece == 'B') { // Black knight
                heuristic += positionWeights[3 - i][j]; // Reverse row index for black knights
            }
        }
    }
    this->heuristic = heuristic;
}*/


bool State::isGoal() const {
    vector<char> reference = {'B', 'B', 'B', 'E', 'E', 'E', 'E', 'E', 'E', 'W', 'W', 'W'};
    for (int idx = 0; idx < (int) reference.size(); idx++) {
        if (reference[idx] != state[idx])
            return false;
    }
    return true;
}

bool State::isValidMove(int row, int col, int actualCol, int actualRow) {
    // Check if the move is within the bounds of the chessboard
    return (row >= 0 && row < actualRow && col >= 0 && col < actualCol &&
            (row != 1 && col != 1 || row != 2 && col != 1));
}

vector<State> State::generateStates() {
    vector<State> returnVal, whiteKnights, blackKnights;

    for (int idx = 0; idx < (int) getState().size(); idx++) {

        if (state[idx] == 'W') {
            whiteKnights = moveChess(idx, getState());

            for (auto val: whiteKnights)
                returnVal.push_back(val);

        } else if (state[idx] == 'B') {

            blackKnights = moveChess(idx, getState());
            for (auto val: blackKnights)
                returnVal.push_back(val);

        }
    }
    return returnVal;


}