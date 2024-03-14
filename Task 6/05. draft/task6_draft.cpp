#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// Structure to represent a knight's position
struct Position {
    int row;
    int col;
    char color;

    Position(int r, int c, char col) : row(r), col(c), color(col) {}
};

// Heuristic function to calculate the Manhattan distance
int heuristic(const vector<Position>& knights) {
    int distance = 0;
    for (const auto& knight : knights) {
        if (knight.color == 'B') {
            distance += abs(knight.row - 0);
        } else {
            distance += abs(knight.row - 3);
        }
    }
    return distance;
}

// Function to check if a position is valid on the chessboard
bool isValidPosition(int row, int col) {
    return row >= 0 && row < 4 && col >= 0 && col < 3;
}

// Function to check if a knight can move to a given position
bool canMoveTo(const vector<Position>& knights, int row, int col) {
    for (const auto& knight : knights) {
        if (knight.row == row && knight.col == col) {
            return false;
        }
    }
    return true;
}

// Function to generate successor states by moving one knight
vector<vector<Position>> generateSuccessorStates(const vector<Position>& knights) {
    vector<vector<Position>> successors;
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

    for (const auto& knight : knights) {
        for (int i = 0; i < 8; ++i) {
            int newRow = knight.row + dx[i];
            int newCol = knight.col + dy[i];

            if (isValidPosition(newRow, newCol) && canMoveTo(knights, newRow, newCol)) {
                vector<Position> nextState = knights;
                nextState.push_back(Position(newRow, newCol, knight.color));
                nextState.erase(remove_if(nextState.begin(), nextState.end(),
                                          [knight](const Position& p) {
                                              return p.row == knight.row && p.col == knight.col;
                                          }),
                                nextState.end());

                successors.push_back(nextState);
            }
        }
    }

    return successors;
}

// Structure to represent a state with knights and their priority
struct State {
    vector<Position> knights;
    int priority;

    State(const vector<Position>& k) : knights(k), priority(0) {
        priority = heuristic(knights);
    }

    bool operator<(const State& other) const {
        return priority > other.priority;
    }
};

// Function to check if a state is the goal state
bool isGoalState(const vector<Position>& knights) {
    for (const auto& knight : knights) {
        if ((knight.row == 0 && knight.color == 'W') || (knight.row == 3 && knight.color == 'B')) {
            return false;
        }
    }
    return true;
}

// Iterative improvement algorithm to exchange knights
vector<Position> exchangeKnights() {
    vector<Position> initialKnights = {
        Position(0, 0, 'W'), Position(0, 1, 'W'), Position(0, 2, 'W'),
        Position(3, 0, 'B'), Position(3, 1, 'B'), Position(3, 2, 'B')
    };

    priority_queue<State> pq;
    pq.push(State(initialKnights));

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (isGoalState(current.knights)) {
            return current.knights;
        }

        vector<vector<Position>> successors = generateSuccessorStates(current.knights);

        for (const auto& successor : successors) {
            pq.push(State(successor));
        }
    }

    // If no solution found, return an empty vector
    return {};
}

// Function to print the final position of the knights
void printKnightsPosition(const vector<Position>& knights) {
    char board[4][3];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 'E';
        }
    }

    for (const auto& knight : knights) {
        board[knight.row][knight.col] = knight.color;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<Position> finalKnights = exchangeKnights();

    if (!finalKnights.empty()) {
        cout << "Final position of the knights:" << endl;
        printKnightsPosition(finalKnights);
    } else {
        cout << "No solution found";
}}
