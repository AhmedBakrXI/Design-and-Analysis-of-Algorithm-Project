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
    heuristic = sum / 4;
}


bool State::isGoal() const {
    vector<char> reference = {'B', 'B', 'B', 'E', 'E', 'E', 'E', 'E', 'E', 'W', 'W', 'W'};
    for (int idx = 0; idx < reference.size(); idx++) {
        if (reference[idx] != state[idx])
            return false;
    }
    return true;
}

bool State::isValidMove(int row, int col, int actualCol, int actualRow) {
    // count knight in the middle, max must be 3
    int midKnightsCount = 0;
    if (state[1 * 3 + 0] != 'E') midKnightsCount++;
    if (state[1 * 3 + 2] != 'E') midKnightsCount++;
    if (state[2 * 3 + 0] != 'E') midKnightsCount++;
    if (state[2 * 3 + 2] != 'E') midKnightsCount++;

    if (row == 1 && col == 0 || row == 1 && col == 2 || row == 2 && col == 0 || row == 2 && col == 2) {
        if (midKnightsCount == 3) {
            return false;
        }
    }

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

bool State::equals(State state) {
    for (int i = 0; i < 12; i++) {
        if (this->state[i] != state.state[i]) {
            return false;
        }
    }
    return true;
}

State::State() {
    state = {'W', 'W', 'W', 'E', 'E', 'E', 'E', 'E', 'E', 'B', 'B', 'B'};
    calculateHeuristic();
}

vector<char> State::getState() const {
    return state;
}

int State::getHeuristic() const {
    return heuristic;
}

void State::print() const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << state[i * 3 + j] << " ";
        }
        std::cout << std::endl;
    }
}




